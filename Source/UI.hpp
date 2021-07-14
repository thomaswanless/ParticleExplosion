//
//  UI.hpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#ifndef UI_hpp
#define UI_hpp

#include <SDL.h>

namespace wanless {

class UISystem {
private:
    static bool toggleBlur;

public:
    UISystem();
    bool checkBlur();
    static void setBlur();
    void drawMenu();
    void initMenu();
};

}
#endif /* UI_hpp */
