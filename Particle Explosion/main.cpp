//
//  main.cpp
//  SDL Basic
//
//  I created this program whilst initially learning C++.
//  I have since added more functionality.
//  This was the first time I utilised the SDL2 framework.

#include <SDL.h>
#include <iostream>
#include "screen.hpp"
#include "UI.hpp"
#include "Input.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "swarm.hpp"

using namespace std;
using namespace wanless;

int main() {
    
    //srand(time(NULL));
    
    Screen screen;
    UISystem ui;
    Input input;
    
    if(screen.init() == false) {
        cout << "Error initialising SDL." << endl;
    }
    
    Swarm swarm;
    
    while (true) {

        int elapsed = SDL_GetTicks();
        
        if(ui.checkBlur() == false) {
            screen.clear();
        }
        
        swarm.update(elapsed);
        
        
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + cos(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
        
        const Particle * const pParticles = swarm.getParticles();
        
        for(int i=0;i<Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
        }
        
        if(ui.checkBlur() == true){
            screen.boxBlur();
        }
                
        //Draw Screen
        screen.update();

        
        //IF THERE IS AN EVENT THEN:
        if (input.processEvents() == false) {
            break;
        }
        
        
        
    }
    
    screen.close();
    
    return 0;
}
