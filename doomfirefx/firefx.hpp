//
//  firefx.hpp
//  doomfirefx
//
//

#ifndef firefx_hpp
#define firefx_hpp

#include <memory>

class FireFx {
 
public:
    FireFx(int w=640, int h=480) : m_width{w} , m_height{h} {
        pix_colors = std::make_unique<int[]>(w*h);
    }
    void spreadFire(int from);
    void drawFire();
    void putOutFire();
    void lightFire();
    void updateScreenBuffer(std::unique_ptr<int[]>& screen);
    
    std::unique_ptr<int[]>& getPixColors();
    
    
private:
    static constexpr int COLORS[] = {
            0x070707,0x1F0707,0x2F0F07,0x470F07,0x571707,
           0x671F07,0x771F07,0x8F2707,0x9F2F07,0xAF3F07,
           0xBF4707,0xC74707,0xDF4F07,0xDF5707,0xDF5707,
           0xD75F07,0xD75F07,0xD7670F,0xCF6F0F,0xCF770F,
           0xCF7F0F,0xCF8717,0xC78717,0xC78F17,0xC7971F,
           0xBF9F1F,0xBF9F1F,0xBFA727,0xBFA727,0xBFAF2F,
           0xB7AF2F,0xB7B72F,0xB7B737,0xCFCF6F,0xDFDF9F
    };
    
    const int COLORS_SIZE = sizeof(COLORS) / sizeof(COLORS[0]);
    
    std::unique_ptr<int[]> pix_colors;
    
    int m_width;
    int m_height;
};

#endif /* firefx_hpp */


