//
//  screen.hpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#ifndef screen_hpp
#define screen_hpp

#include <SDL.h>

namespace wanless {

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;
    bool toggleBlur;

public:
    Screen();
    bool init();
    bool processEvents();
    void close();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void clear();
    void boxBlur();
    bool checkBlur();
};



//Namespace END
}

#endif /* screen_hpp */
