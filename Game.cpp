//
// Created by matti on 22/04/18.
//
#include <ctime>
#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {
    player = nullptr;
    enemy = nullptr;
    enemiescount=1;
    gameTimerStart = 0;
    running = false;
    window = nullptr;
}
Game::~Game() {
    delete player;
    /*
     * for(auto en: enemies)
        delete en;
    */
    delete enemy;
    clean();
}

void Game::init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!!"<<std::endl;
        int flags= fullscreen?SDL_WINDOW_FULLSCREEN:0;
        window=SDL_CreateWindow(title, xpos, ypos, width, height, static_cast<Uint32>(flags));
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout << "Renderer created!" << std::endl;
        }
        running = true;
    }
    else {
        running = false;

    }
    srand((unsigned)time(NULL));
    int randnumber = rand() % 3 +1;
    Map::Istance(randnumber);
    player = new GameObject(const_cast<char *>("../images/sprite1.png"), 19, 0, 1);
    enemy = new Enemy(const_cast<char *>("../images/demon.png"), 0, 0, 1);
    //enemies.push_back(enemy);
    gameTimerStart = SDL_GetTicks();
    std::cout << "Game started after" << gameTimerStart << "milliseconds" << std::endl;
}

void Game::update() {
    player->Update();
    std::cout << "Time: " << SDL_GetTicks() << std::endl;
    if((SDL_GetTicks() - gameTimerStart) >= 60000) {
        std::cout << "WIN!!!!" << std::endl;
        running = false;
    }
    /*else if(((SDL_GetTicks() - gameTimerStart) / 8000) >= enemiescount) {
        enemiescount++;
        auto enemy = new Enemy(const_cast<char *>("../images/demon.png"), 0, 0, 1);
        enemies.push_back(enemy);
        registerObserver(enemy);
    }*/

    //for(auto enemy : enemies) {
    enemy->Update();
    if (enemy->directions.empty()) {
        //do A*
        // Create an instance of the search class...

        AStarSearch<MapSearchNode> astarsearch;

        unsigned int SearchCount = 0;

        const unsigned int NumSearches = 1;

        while (SearchCount < NumSearches) {
            // Create a start state
            MapSearchNode nodeStart;
            nodeStart.x = enemy->getXpos();
            nodeStart.y = enemy->getYpos();
            // Define the goal state
            MapSearchNode nodeEnd;
            nodeEnd.x = player->getXpos();
            nodeEnd.y = player->getYpos();
            // Set Start and goal states
            astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);
            unsigned int SearchState;
            unsigned int SearchSteps = 0;
            do {
                SearchState = astarsearch.SearchStep();
                SearchSteps++;
            } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

            if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
                cout << "Search found goal state\n";

                MapSearchNode *node = astarsearch.GetSolutionStart();
                int steps = 0;
                enemy->directions.push_back(node);
                node->PrintNodeInfo();
                for (;;) {
                    node = astarsearch.GetSolutionNext();
                    if (!node) {
                        break;
                    }
                    node->PrintNodeInfo();
                    enemy->directions.push_back(node);
                    steps++;
                };
                cout << "Solution steps " << steps << endl;
                // Once you're done with the solution you can free the nodes up
                astarsearch.FreeSolutionNodes();
            } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
                cout << "Search terminated. Did not find goal state\n";
            }

            // Display the number of loops the search went through
            cout << "SearchSteps : " << SearchSteps << "\n";
            SearchCount++;
            astarsearch.EnsureMemoryFreed();
        }
    }
    else {
        if (enemy->checkCollision(player, 0)) {
            //end game, LOSE.
            std::cout << "You lost...";
            running = false;
        } else {
            auto currentPos = enemy->directions.front();
            enemy->setPosition(currentPos->x, currentPos->y);
            enemy->directions.pop_front();
            enemy->Update();
        }
    }
    //}
}

void Game::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0 ) {
        switch(event.type) {
            case SDL_QUIT:
                running=false;
                break;
                //press arrows->move and notify
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym) {
                            //press arrows->move and notify
                            case SDLK_UP:
                                std::cout << "Pressed UP" << std::endl;
                                if(Map::Istance()->getMap(player->getXpos(),player->getYpos()-1) < 9)
                                    player->setPosition(player->getXpos(),player->getYpos()-1);
                                break;
                            case SDLK_DOWN:
                                std::cout << "Pressed DOWN" << std::endl;
                                if(Map::Istance()->getMap(player->getXpos(),player->getYpos()+1) < 9)
                                    player->setPosition(player->getXpos(),player->getYpos()+1);
                                break;
                            case SDLK_LEFT:
                                std::cout << "Pressed LEFT" << std::endl;
                                if(Map::Istance()->getMap(player->getXpos()-1,player->getYpos()) < 9)
                                    player->setPosition(player->getXpos()-1,player->getYpos());
                                break;
                            case SDLK_RIGHT:
                                std::cout << "Pressed RIGHT" << std::endl;
                                if(Map::Istance()->getMap(player->getXpos()+1,player->getYpos()) < 9)
                                    player->setPosition(player->getXpos()+1,player->getYpos());
                                break;
                            default:
                                break;
                        }
                        SDL_FlushEvent(SDL_KEYDOWN);
                        break;
            default:
                break;
        }
    }

}

void Game::render() {
    SDL_RenderClear(renderer);
    Map::Istance()->drawMap();
    player->Render();
    //for(auto enemy : enemies)
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

bool Game::isRunning() {return running;}


