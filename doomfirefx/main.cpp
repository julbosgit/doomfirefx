//
//  main.cpp
//  doomfirefx
//

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <cmath>
#include <SDL.h>

#include "display.hpp"
#include "firefx.hpp"


const auto WIDTH = 640;
const auto HEIGHT = 100;


int main(int argc, const char * argv[]) {
    
    Display disp(WIDTH, HEIGHT);
    FireFx fire(WIDTH, HEIGHT);
    
    auto timing_ms = 60;
    
    std::srand(std::time(nullptr));
    
    auto cnt=0;
    
    if(disp.initWindow() == 0) {
        
        SDL_Event e;
        for(;;) {
            SDL_PollEvent(&e);
            if(e.type == SDL_QUIT) break;
            std::this_thread::sleep_for (std::chrono::milliseconds(timing_ms));
            
            if(cnt == 0)
                fire.lightFire();
            else if(cnt > 5000/timing_ms ) {
                fire.putOutFire();
                if(cnt > 9000/timing_ms )
                    cnt = -1;
            }
            cnt++;
            
            fire.drawFire();
            fire.updateScreenBuffer(disp.getScreen());
            
            disp.updateWindow();
        }
    }
    
    
    return 0;
}
