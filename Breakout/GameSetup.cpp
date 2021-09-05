#include "GameSetup.h"
#include <iostream>

using namespace std;

GameSetup::GameSetup(){}
GameSetup::~GameSetup(){}

SDL_Texture* background;

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

	/*SDL_Surface* tmpSurface = IMG_Load("assets/andromeda.jpg");
	background = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);*/
	background = IMG_LoadTexture(renderer, "assets/andromeda.jpg");
	//background = SDL_GetWindowSurface(window);
	//background = SDL_LoadFile("assets/andromeda.png", NULL);
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
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		SDL_RenderPresent(renderer);
		cout << "renderer created" << endl;
}

void GameSetup::update() {

}

void GameSetup::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" << endl;
}