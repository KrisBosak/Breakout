#include "GameSetup.h"
#include <iostream>

using namespace std;

GameSetup::GameSetup(){}
GameSetup::~GameSetup(){}

void GameSetup::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	SDL_Init(SDL_INIT_EVERYTHING);
	isRunning = true;

	window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
	if (window) {
		cout << "window created" << endl;
	}
}

void GameSetup::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type)	{
		case SDL_QUIT:
			isRunning = false;
			cout << "Game closed" << endl;
			//break;
		default:
			break;
		}
	}
}

void GameSetup::render() {
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		cout << "renderer created" << endl;
	}
}

void GameSetup::update() {

}

void GameSetup::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" << endl;
}