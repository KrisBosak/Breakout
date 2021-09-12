#include "SDL.h"
#include "GameSetup.h"
#include "FieldManager.h"

using namespace std;

GameSetup* gameSetup = nullptr;
FieldManager* manageField = nullptr;

int main(int argc, char* argv[]) {
	gameSetup = new GameSetup();
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) gameSetup->init("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	while (gameSetup->running()) {
		frameStart = SDL_GetTicks();

		gameSetup->handleEvents();
		manageField->drawBricks();
		//razmisli jel bi bilo mozda bolje ovo dvoje tu jos stavit
		//render();
		//update();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	gameSetup->clean();

	return 0;
}