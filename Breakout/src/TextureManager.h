#ifndef TextureManager_h
#define TextureManager_h

#include "SDL.h"
#include "SDL_image.h"
#include "GameSetup.h"

class TextureManager{
public:
	TextureManager();
	~TextureManager();
	static void DrawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination);
private:
};
#endif // !TextureManager.h