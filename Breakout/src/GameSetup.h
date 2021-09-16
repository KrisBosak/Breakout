#ifndef GameSetup_h
#define GameSetup_h

#include <iostream>
#include <string>
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
	void loadTextures(const char* bckgrnd);
	void handleEvents();
	void paddleMotion(bool left, bool right);
	void ballMotion();
	void render();
	void clean();

	bool running() {
		return isRunning;
	}
	bool isBallAlive() {
		return ballAlive;
	}

	static SDL_Renderer* renderer;
private:
	bool isRunning = false;
	bool ballAlive = false;
	bool right = 0;
	bool left = 0;
	float paddleSprite_xPos = 0;
	float paddleSprite_xVel = 0;
	float ballSprite_xPos = 0;
	float ballSprite_yPos = 0;
	float ballSprite_xVel = BALL_SPEED;
	float ballSprite_yVel = BALL_SPEED;
	SDL_Window* window = nullptr;
	SDL_Rect dstRPaddle, dstRBall;
	SDL_Texture* paddle = nullptr;
	SDL_Texture* ball = nullptr;
};
#endif // !GameSetup.h