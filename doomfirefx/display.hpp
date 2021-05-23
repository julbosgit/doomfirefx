//
//  display.hpp
//  doomfirefx
//

#ifndef display_hpp
#define display_hpp

#include <vector>
#include <memory>
#include <SDL.h>



class Display {
    
    
public:
    Display(int w=640, int h=480) : m_width{w}, m_height{h} {

        screen = std::make_unique<int[]>(w*h);
    }
    
    int initWindow();
    void updateWindow();
    
    std::unique_ptr<int[]>& getScreen();
    
    
    
private:
    int m_width;
    int m_height;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    
    std::unique_ptr<int[]> screen;
    
};

#endif /* display_hpp */
