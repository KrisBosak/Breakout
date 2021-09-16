#include "TextureManager.h"

TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
	SDL_RenderCopy(GameSetup::renderer, texture, &source, &destination);
}
void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect destination) {
	SDL_RenderCopy(GameSetup::renderer, texture, NULL, &destination);
}
void TextureManager::DrawTexture(SDL_Texture* texture) {
	SDL_RenderCopy(GameSetup::renderer, texture, NULL, NULL);
}