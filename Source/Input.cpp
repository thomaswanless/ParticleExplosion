//
//  Input.cpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#include <SDL.h>
#include "Input.hpp"
#include "UI.hpp"


namespace wanless {

bool Input::processEvents(){
    //Checks for any SDL Event
    // If event is SDL quit event, breaks game loop.
    
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN) {
            UISystem::setBlur();
        }
    }
    return true;
}

}
