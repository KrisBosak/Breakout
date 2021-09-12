#ifndef FieldManager_h
#define FieldManager_h

#include "tinyxml2.h"
#include "vector"
#include "GameSetup.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <iostream>

class FieldManager{
public:
	FieldManager();
	~FieldManager();

	//void loadDocument(string xmlPath);
	//void readDocument();
	void drawBricks();

private:
	SDL_Texture* hardBrick = nullptr;
	SDL_Texture* mediumBrick = nullptr;
	SDL_Texture* softBrick = nullptr; 
	SDL_Texture* invinsibruuuu = nullptr;
}; 
#endif // !FieldManager.h