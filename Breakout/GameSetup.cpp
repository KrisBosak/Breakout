#include "GameSetup.h"
#include <iostream>

using namespace std;

GameSetup::GameSetup(){}
GameSetup::~GameSetup(){}

SDL_Texture* background;
SDL_Texture* paddle;
SDL_Texture* ball;
SDL_Rect dstRPaddle, dstRBall;

void GameSetup::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	SDL_Init(SDL_INIT_EVERYTHING);
	isRunning = true;

	window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
	if (window) {
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		}
		cout << "window created" << endl;
	}

	background = IMG_LoadTexture(renderer, "assets/andromeda.jpg"); 
	paddle = IMG_LoadTexture(renderer, "assets/paddle.png");
	ball = IMG_LoadTexture(renderer, "assets/ball.png");

	//paddle look and starting position
	dstRPaddle.w = (WINDOW_WIDTH / 10);
	dstRPaddle.h = 10;
	dstRPaddle.x = (WINDOW_WIDTH - dstRPaddle.w) / 2;
	dstRPaddle.y = (WINDOW_HEIGHT - dstRPaddle.h);
	sprite_xPos = dstRPaddle.x;

	//ball look and starting position
	dstRBall.w = 18;
	dstRBall.h = 18;
	dstRBall.x = (WINDOW_WIDTH - dstRBall.w) / 2;
	dstRBall.y = (WINDOW_HEIGHT - (dstRPaddle.h + dstRBall.h));
	//sprite_xPos = dstRBall.x;
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
			default:
				break;
			}
			break;
		}
	}

	update(left, right);
}

void GameSetup::update(bool left, bool right) {
	sprite_xVel = 0;

	if (left && !right) sprite_xVel = -SPEED;
	if (right && !left) sprite_xVel = SPEED;

	//update positions
	sprite_xPos += sprite_xVel / 60;

	//collision detection
	if (sprite_xPos <= 0) sprite_xPos = 0;
	if (sprite_xPos >= (WINDOW_WIDTH - dstRPaddle.w)) sprite_xPos = WINDOW_WIDTH - dstRPaddle.w;

	dstRPaddle.x = (int) sprite_xPos;
	//SDL_RenderClear(renderer); //I want to keep my background
	SDL_RenderCopy(renderer, paddle, NULL, &dstRPaddle);
	SDL_RenderPresent(renderer);
}

void GameSetup::render() {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		SDL_RenderCopy(renderer, paddle, NULL, &dstRPaddle);
		SDL_RenderCopy(renderer, ball, NULL, &dstRBall);
		SDL_RenderPresent(renderer);
}

void GameSetup::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	//SDL_Quit();
	cout << "Game Cleaned" << endl;
}