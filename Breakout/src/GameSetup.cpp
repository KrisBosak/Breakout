#include "GameSetup.h"
#include <iostream>

using namespace std;

GameSetup::GameSetup(){}
GameSetup::~GameSetup(){}

SDL_Renderer* GameSetup::renderer = nullptr;
SDL_Texture* background = nullptr;
SDL_Texture* paddle = nullptr;
SDL_Texture* ball = nullptr;
FieldManager* manageParsing = nullptr;
SDL_Rect dstRPaddle{ 0, 0, 0, 0 }, dstRBall{ 0, 0, 0, 0 };

void GameSetup::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
	if (window) {
		isRunning = true;
		GameSetup::renderer = SDL_CreateRenderer(window, -1, 0);
		if (GameSetup::renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		}
	}

	background = IMG_LoadTexture(GameSetup::renderer, "assets/Backgrounds/andromeda.jpg");
	paddle = IMG_LoadTexture(GameSetup::renderer, "assets/paddle.png");
	ball = IMG_LoadTexture(GameSetup::renderer, "assets/ball.png");
	//paddle look and starting position
	dstRPaddle.w = (WINDOW_WIDTH / 10);
	dstRPaddle.h = 10;
	dstRPaddle.x = (WINDOW_WIDTH - dstRPaddle.w) / 2;
	dstRPaddle.y = (WINDOW_HEIGHT - dstRPaddle.h);
	paddleSprite_xPos = (float)dstRPaddle.x;

	//ball look and starting position
	dstRBall.w = 18;
	dstRBall.h = 18;
	dstRBall.x = (WINDOW_WIDTH - dstRBall.w) / 2;
	dstRBall.y = (WINDOW_HEIGHT - (dstRPaddle.h + dstRBall.h));
	ballSprite_xPos = (float) dstRBall.x;
	ballSprite_yPos = (float) dstRBall.y;
	cout << ballSprite_yPos << endl;

	render();
}

void GameSetup::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			cout << "Game closed" << endl;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_LEFT:
				left = 1;
				break;
			case SDL_SCANCODE_D:
			case SDL_SCANCODE_RIGHT:
				right = 1;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_LEFT:
				left = 0;
				break;
			case SDL_SCANCODE_D:
			case SDL_SCANCODE_RIGHT:
				right = 0;
				break;
			case SDL_SCANCODE_SPACE:
				GameSetup::ballAlive = 1;
				break;
			default:
				break;
			}
			break;
		}
	}

	//I don't want the player to be able to move until the ball is dropped
	if (ballAlive) {
		ballMotion();
		paddleMotion(left, right);
	}
}

void GameSetup::paddleMotion(bool left, bool right) {
	paddleSprite_xVel = 0;

	if (left && !right) paddleSprite_xVel = -PADDLE_SPEED;
	if (right && !left) paddleSprite_xVel = -PADDLE_SPEED;

	//update positions
	paddleSprite_xPos += paddleSprite_xVel / FPS;

	//collision detection
	if (paddleSprite_xPos <= 0) paddleSprite_xPos = 0;
	if (paddleSprite_xPos >= WINDOW_WIDTH - dstRPaddle.w) paddleSprite_xPos = (float) WINDOW_WIDTH - dstRPaddle.w;

	dstRPaddle.x = (int)paddleSprite_xPos;

	render();
}

void GameSetup::ballMotion() { 
	if (ballSprite_xPos <= 0) {
		ballSprite_xVel = -ballSprite_xVel;
	}
	if (ballSprite_yPos <= 0) {
		ballSprite_yVel = -ballSprite_yVel;
	}
	if (ballSprite_xPos >= WINDOW_WIDTH - dstRBall.w) {
		ballSprite_xVel = -ballSprite_xVel;
	}
	if (ballSprite_yPos >= (WINDOW_HEIGHT - (dstRPaddle.h + dstRBall.h)) && (ballSprite_xPos > dstRPaddle.x && ballSprite_xPos < (dstRPaddle.x + dstRPaddle.w))) {
		//ballSprite_yPos = WINDOW_HEIGHT - (dstRBall.h + dstRPaddle.h);
		ballSprite_yVel = -ballSprite_yVel;
	}
	else if (ballSprite_yPos > WINDOW_HEIGHT + dstRBall.h) {
		isRunning = false;
	}

	ballSprite_xPos += ballSprite_xVel / FPS;
	ballSprite_yPos += ballSprite_yVel / FPS;

	dstRBall.x = (int)ballSprite_xPos;
	dstRBall.y = (int)ballSprite_yPos;

	render();
}

void GameSetup::render() {
		SDL_RenderClear(GameSetup::renderer);
		SDL_RenderCopy(GameSetup::renderer, background, NULL, NULL);
		SDL_RenderCopy(GameSetup::renderer, paddle, NULL, &dstRPaddle);
		SDL_RenderCopy(GameSetup::renderer, ball, NULL, &dstRBall);
		SDL_RenderPresent(GameSetup::renderer);
}

void GameSetup::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(GameSetup::renderer);
	//SDL_Quit();
	cout << "Game Cleaned" << endl;
}