#define GameSetup_h
#ifndef GameSetup_h
#endif // !GameSetup.h

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)
#define SPEED (300)

class GameSetup {
public:
	GameSetup();
	~GameSetup();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update(bool left, bool right);
	void render();
	void clean();
	void movement();

	bool running() {
		return isRunning;
	}
private:
	bool isRunning = true;
	//bool up = 0;
	//bool down = 0;
	bool right = 0;
	bool left = 0;
	float sprite_xPos = 0;
	float sprite_yPos = 0;
	float sprite_xVel = 0;
	float sprite_yVel = 0;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};


