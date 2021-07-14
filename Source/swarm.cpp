//
//  swarm.cpp
//  SDL Basic
//
//  Created by Tom Wanless on 13/07/2021.
//

#include "swarm.hpp"


namespace wanless {
    
Swarm::Swarm(): lastTime(0) {
    m_pParticles = new Particle[NPARTICLES];
}
    
Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;
    
    for (int i=0; i<Swarm::NPARTICLES; i++) {
        m_pParticles[i].update(interval);
    }
    
    lastTime = elapsed;

}

}
