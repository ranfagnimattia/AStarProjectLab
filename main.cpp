#include "Game.h"


int main(int argc,const char* args[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    float frameTime = 0;
    auto game = new Game();
    game->init("Hello!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480 , false);
    auto gameTimerStart = SDL_GetTicks();

    while (game->isRunning()) {

        frameStart = SDL_GetTicks(); //Tempo in ms dall'esecuzione del programma in cui il frame inizia a essere renderizzato

        game->update();
        game->handleEvents();
        game->render();
        SDL_Delay(750);

        frameTime = SDL_GetTicks() - frameStart; //Calcolo quanti millisecondi impiego a renderizzare un frame

        if (frameDelay > frameTime) //Se ci metto meno del tempo prestabilito a renderizzare un frame...
        {
            SDL_Delay(static_cast<Uint32>(frameDelay - frameTime)); //... aggiungo un ritardo in modo che combaci con frameDelay.
        }
    }

    game->clean();
    return 0;
}