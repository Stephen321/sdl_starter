#include "Renderer.h"
#include <SDL_image.h>

Renderer::Renderer() {

}

Renderer::~Renderer() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}

bool Renderer::initialize(const char* title, int width, int height, int flags) {
    bool running = false;

    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (m_window != 0) {
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        if (m_renderer != 0) {
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); //linear filtering scaling
            SDL_RenderSetLogicalSize(m_renderer, width, height); //letterboxing
            SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
            running = true;
        }
    }
    return running;
}

void Renderer::drawRectOutline(const SDL_Rect& rect, const Colour& colour) const {
    setDrawColor(colour);
    SDL_RenderDrawRect(m_renderer, &rect);
}

void Renderer::drawRect(const SDL_Rect& rect, const Colour& colour) const {
    setDrawColor(colour);
    SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::drawTexture(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest) const {
    SDL_RenderCopy(m_renderer, texture, &src, &dest);
}

void Renderer::drawTextureEx(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest, double angle, SDL_Point* centre, SDL_RendererFlip flip) const {
	SDL_RenderCopyEx(m_renderer, texture, src, dest, angle, centre, flip);
}

void Renderer::setDrawColor(int r, int g, int b, int a) const {
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Renderer::setDrawColor(const Colour& colour) const {
    setDrawColor(colour.r, colour.g, colour.b, colour.a);
}

void Renderer::clear(const Colour& colour) {
    setDrawColor(colour);
    SDL_RenderClear(m_renderer);
}

void Renderer::present() {
    SDL_RenderPresent(m_renderer);
}

SDL_Texture* Renderer::loadTexture(const char* path) {
    SDL_Texture* texture = IMG_LoadTexture(m_renderer, path);
    if (texture == nullptr) {
        printf("Couldn't load texture: %s. Error: %s\n", path, SDL_GetError());
    }

    return texture;
}
