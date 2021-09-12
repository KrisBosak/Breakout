#ifndef GameSetup_h
#define GameSetup_h

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "FieldManager.h"
#include "TextureManager.h"

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (600)
#define PADDLE_SPEED (400)
#define BALL_SPEED (500)
#define FPS (60)

class GameSetup {
public:
	GameSetup();
	~GameSetup();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void paddleMotion(bool left, bool right);
	void render();
	void clean();
	void ballMotion();

	bool running() {
		return isRunning;
	}
	bool isBallAlive() {
		return ballAlive;
	}

	static SDL_Renderer* renderer;
private:
	int rowCount = 0;
	int columnCount = 0;
	int rowSpacing = 0;
	int columnSpacing = 0;
	bool isRunning = false;
	bool ballAlive = false;
	bool right = 0;
	bool left = 0;
	float paddleSprite_xPos = 0;
	float paddleSprite_xVel = 0;
	float ballSprite_xPos = 0;
	float ballSprite_yPos = 0;
	float ballSprite_xVel = -BALL_SPEED;
	float ballSprite_yVel = -BALL_SPEED;
	SDL_Window* window = nullptr;
};
#endif // !GameSetup.h
