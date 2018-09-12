#include "Game.h"
#include "Player.h"
#include "Enemy.h"

const int MAX_DISTANCE_RANGE = 5;
Game *game=nullptr;

int main(int argc,const char* args[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    float frameTime = 0;
    game= new Game();
    game->init("Hello!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640,false);
    auto gameTimerStart = SDL_GetTicks();

    auto player = new Player(const_cast<char *>("../images/sprite1.png"), 0, 0,1);
    game->registerObserver(player);
    std::list<Enemy*> enemies;

    int enemiescount = 0;

    while (game->isRunning()) {

        //frameStart = SDL_GetTicks();

        if((SDL_GetTicks() - gameTimerStart) >= 30000) {
            //end game, WIN!
            break;
        }
        else if(((SDL_GetTicks() - gameTimerStart) / 8) >= enemiescount) {
            enemiescount++;
            //edit and add factory
            auto enemy = new Enemy(const_cast<char *>("../images/Sprite-0001.bmp"), 0, 0,1);
            enemies.push_back(enemy);
            game->registerObserver(enemy);

        }
        game->handleEvents();
        for(auto enemy : enemies) {
            if(enemy->directions.empty()) {
                //do A*
                // Our sample problem defines the world as a 2d array representing a terrain
                // Each element contains an integer from 0 to 5 which indicates the cost
                // of travel across the terrain. Zero means the least possible difficulty
                // in travelling (think ice rink if you can skate) whilst 5 represents the
                // most difficult. 9 indicates that we cannot pass.

                // Create an instance of the search class...

                AStarSearch<MapSearchNode> astarsearch;

                unsigned int SearchCount = 0;

                const unsigned int NumSearches = 1;

                while(SearchCount < NumSearches)
                {
                    // Create a start state
                    MapSearchNode nodeStart;
                    nodeStart.x = rand()%(Map::width);
                    nodeStart.y = rand()%(Map::height);
                    // Define the goal state
                    MapSearchNode nodeEnd;
                    nodeEnd.x = player->getXpos();
                    nodeEnd.y = player->getYpos();
                    // Set Start and goal states
                    astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );
                    unsigned int SearchState;
                    unsigned int SearchSteps = 0;
                    do
                    {
                        SearchState = astarsearch.SearchStep();
                        SearchSteps++;
                    }
                    while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

                    if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
                    {
                        cout << "Search found goal state\n";

                        MapSearchNode *node = astarsearch.GetSolutionStart();
                        int steps = 0;
                        enemy->directions.push_back(node);
                        node->PrintNodeInfo();
                        for( ;; )
                        {
                            node = astarsearch.GetSolutionNext();
                            if( !node )
                            {
                                break;
                            }
                            node->PrintNodeInfo();
                            steps ++;
                        };
                        cout << "Solution steps " << steps << endl;
                        // Once you're done with the solution you can free the nodes up
                        astarsearch.FreeSolutionNodes();
                    }
                    else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
                    {
                        cout << "Search terminated. Did not find goal state\n";
                    }

                    // Display the number of loops the search went through
                    cout << "SearchSteps : " << SearchSteps << "\n";
                    SearchCount ++;
                    astarsearch.EnsureMemoryFreed();
                }
            }
            else {
                if(enemy->checkCollision(player,MAX_DISTANCE_RANGE)) {
                    //end game, LOSE.
                    game->setRunning(false);
                }
                else {
                    auto currentPos= enemy->directions.front();
                    enemy->setPosition(currentPos->x,currentPos->y);
                    enemy->directions.pop_front();
                    //move -> edit position and notify(?)
                }
            }
        }
        game->render();
        SDL_Delay(1500);

        /*frameTime = SDL_GetTicks() - frameStart;//per vedere tempo trascorso a fare render e tutto
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }*/



    }
    game->clean();
    return 0;
}