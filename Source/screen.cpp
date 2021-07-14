//
//  screen.cpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#include "screen.hpp"
#include <SDL.h>
#include "UI.hpp"

namespace wanless {

//Initialises Screen object with NULL variables.
//This allow init to set variable values.
Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {
    
}

bool Screen::init(){
    
    // Creates Window|Renderer|Texture|Buffer
    // Sets Buffer to Colour.
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return false;
    }
    
    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if(m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    if(m_texture == NULL) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

    return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    
    if(x<0||x>= SCREEN_WIDTH|| y<0 || y >= SCREEN_HEIGHT) {
        return;
    }
    
    Uint32 color = 0;
    
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    m_buffer1[(y * SCREEN_WIDTH) + x] = color;
    //y * SCREEN_WIDTH = Row selection.
    //x = Column selection.
}

void Screen::boxBlur(){
    //Swap buffers so we can draw to buffer 1
    Uint32 *temp = m_buffer1;
    m_buffer1 = m_buffer2;
    m_buffer2 = temp;
    
    for(int y=0; y<SCREEN_HEIGHT; y++) {
        for(int x = 0; x<SCREEN_WIDTH; x++) {
            
            int redTotal=0;
            int greenTotal=0;
            int blueTotal=0;
            
            for(int row = -1; row <=1; row++) {
                for(int col=-1;col<=1; col++){
                    int currentX = x + col;
                    int currentY = y + row;
                    
                    if(currentX >=0 && currentX<SCREEN_WIDTH && currentY>=0 && currentY < SCREEN_HEIGHT) {
                        Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];
                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;
                        
                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                        
                    }
                }
            }
            
            Uint8 red = redTotal/9;
            Uint8 green = greenTotal/9;
            Uint8 blue = blueTotal/9;
            
            setPixel(x, y, red, green, blue);

        }
    }
}

void Screen::clear() {
    memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32)); //Copying Pixels from Buffer to Texture.
    SDL_RenderClear(m_renderer); // Remove current render.
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL); // Texture -> Renderer
    SDL_RenderPresent(m_renderer); //Outputs render to image.
    //Runs game loop when false.
}

void Screen::close(){
    //Deletes SDL and buffer objects from memory.
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
};


} //Namespace END
