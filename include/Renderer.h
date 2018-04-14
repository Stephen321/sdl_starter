#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include "BasicTypes.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    bool initialize(const char* title, int width, int height, int flags);
    void drawRectOutline(const SDL_Rect& rect, const Colour& colour) const;
    void drawRect(const SDL_Rect& rect, const Colour& colour) const;
    void drawTexture(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest) const;
    void setDrawColor(int r, int g, int b, int a) const;
    void setDrawColor(const Colour& colour) const;
    void clear(const Colour& colour = Colour(0, 0, 0, 0));
    void present();
    SDL_Texture* loadTexture(const char* path);

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};

#endif /* RENDERER_H */
