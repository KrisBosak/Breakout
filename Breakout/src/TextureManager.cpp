#include "TextureManager.h"

TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
	SDL_RenderCopy(GameSetup::renderer, texture, &source, &destination);
}