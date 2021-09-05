#define GameSetup_h
#ifndef GameSetup_h
#endif // !GameSetup.h

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class GameSetup {
public:
	GameSetup();
	~GameSetup();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() {
		return isRunning;
	}
private:
	bool isRunning = true;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};


