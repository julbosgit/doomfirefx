//
//  display.cpp
//  doomfirefx
//

#include <iostream>
#include <SDL.h>
#include "display.hpp"





int Display::initWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "error initializing SDL: %s\n" << SDL_GetError();
        return 1;
    }
    
   m_window = SDL_CreateWindow("DoomFireFx",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       m_width, m_height, SDL_WINDOW_RESIZABLE);
    if(m_window == nullptr) {
        std::cout << "Could not create window! SDL_Error: " << SDL_GetError();
        return 1;
    }
    
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    
    if(m_renderer == nullptr) {
        std::cout << "Could not create renderer! SDL_Error: " << SDL_GetError();
        return 1;
    }
    
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, m_width, m_height);
    
    if(m_texture == nullptr) {
        std::cout << "Could not create texture! SDL_Error: " << SDL_GetError();
        return 1;
    }
    
    SDL_SetRenderTarget(m_renderer, m_texture);
    
    return 0;
}


void Display::updateWindow() {
    
    SDL_UpdateTexture(m_texture, nullptr, static_cast<int*>(screen.get()), m_width*sizeof(int));
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
    
}

std::unique_ptr<int[]>& Display::getScreen() {
    return (screen);
}
