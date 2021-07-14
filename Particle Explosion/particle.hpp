//
//  particle.hpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>


namespace wanless {


struct Particle {
    double m_x;
    double m_y;
private:
    double m_speed;
    double m_direction;
    
private:
    void init();
    
public:
    Particle();
    ~Particle();
    void update(int interval);
};

}


#endif /* particle_hpp */
