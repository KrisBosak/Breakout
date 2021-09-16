#ifndef FieldManager_h
#define FieldManager_h

#include <iostream>
#include <string>
#include <map>
#include "tinyxml2.h"
#include "SDL.h"
#include "SDL_image.h"
#include "GameSetup.h"
#include "TextureManager.h"

class FieldManager{
public:
	FieldManager();
	~FieldManager();

	static void getGameDetails();
	void drawBricks();

private:
	int breakScore = 0;
	int charSize = 0;
	int counter = 0;
	int rowCount = 0;
	int columnCount = 0;
	int rowSpacing = 0;
	int columnSpacing = 0;
	int hitPoints = 0;
	char fieldMap[3][20] = {};
	const char* path = " ";
	const char* brickCharArray = " ";
	SDL_Texture* hardBrick = nullptr;
	SDL_Texture* mediumBrick = nullptr;
	SDL_Texture* softBrick = nullptr;
	SDL_Texture* invinsibruuuu = nullptr;
}; 
#endif // !FieldManager.h