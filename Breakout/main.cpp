#include <iostream>
#include "SDL.h"
#include "GameSetup.h"

using namespace std;

GameSetup* gameSetup = nullptr;

int main(int argc, char* argv[]) {
	gameSetup = new GameSetup();
	/*bool isFullscreen = false;
	char fullscrn[] = "";

	cout << "Do you want your game to be fullscreen? Y/N" << endl;
	do {
		cin >> fullscrn;
	} while (fullscrn != "Y" && fullscrn != "N");
	
	if(fullscrn == "Y"){
		isFullscreen = true;
	}*/

	gameSetup->init("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (gameSetup->running()) {
		gameSetup->handleEvents();
		gameSetup->render();
		gameSetup->update();
	}

	gameSetup->clean();

	return 0;
}