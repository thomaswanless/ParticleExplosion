//
//  UI.cpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#include "UI.hpp"

namespace wanless {

bool UISystem::toggleBlur = true;

UISystem::UISystem() {
    
}

bool UISystem::checkBlur() {
    return toggleBlur;
}

void UISystem::setBlur() {
    toggleBlur = !toggleBlur;
}

}
