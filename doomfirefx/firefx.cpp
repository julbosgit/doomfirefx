//
//  firefx.cpp
//  doomfirefx
//

#include <cmath>
#include <algorithm>
#include "firefx.hpp"


void FireFx::drawFire() {
    for(auto i=m_width-1 ; i>0 ; i--)
        for(auto j=m_height-1; j>1 ; j--)
            spreadFire(j * m_width + i);
}


void FireFx::spreadFire(int from) {
    int r = static_cast<int>(round(((1.0*std::rand() / RAND_MAX))*2));
    auto to = from - m_width - r + 1;
    if(to < 0)
        to = 0;
    if(pix_colors[from] != 0)
        pix_colors[to] = pix_colors[from] - (r & 1);
    else
        pix_colors[to] = 0;
}

void FireFx::putOutFire() {
    int r = static_cast<int>(round(((1.0*std::rand() / RAND_MAX))*2));
    for(auto i=0; i<m_width ; i++) {
        pix_colors[(m_height-1)*m_width + i] -= r;
        if(pix_colors[(m_height-1)*m_width + i] < 0)
            pix_colors[(m_height-1)*m_width + i] = 0;
    }
}

void FireFx::lightFire() {
    std::fill_n(static_cast<int*>(pix_colors.get()) + m_width * (m_height-1), m_width, COLORS_SIZE-1);
    std::fill_n(static_cast<int*>(pix_colors.get()), m_width * (m_height-1), 0);
}


std::unique_ptr<int[]>& FireFx::getPixColors() {
    return (pix_colors);
}

void FireFx::updateScreenBuffer(std::unique_ptr<int[]>& screen) {
    for(auto i=0 ; i<m_width ; i++)
        for(auto j=0; j<m_height ; j++)
            screen[j * m_width + i] = COLORS[pix_colors[j * m_width + i]];
}
