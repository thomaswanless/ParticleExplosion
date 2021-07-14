//
//  swarm.hpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#ifndef swarm_hpp
#define swarm_hpp
#include "particle.hpp"
#include <stdio.h>


namespace wanless {
    
class Swarm {
public:
    const static int NPARTICLES = 5000;
private:
    Particle* m_pParticles;
    
public:
    Swarm();
    ~Swarm();
    void update(int elapsed);
    int lastTime;
    const Particle * const getParticles() {return m_pParticles; };
};
    
}

#endif /* swarm_hpp */
