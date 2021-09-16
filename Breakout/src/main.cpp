#include "SDL.h"
#include "GameSetup.h"
#include "FieldManager.h"

using namespace std;

GameSetup* gameSetup = new GameSetup();
FieldManager* brickDrawing = new FieldManager();
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime = 0;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		gameSetup->init("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
	}

	while (gameSetup->running()) {
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;

		gameSetup->handleEvents();
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	gameSetup->clean();

	return 0;
}