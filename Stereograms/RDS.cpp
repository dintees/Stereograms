#include "RDS.h"


void Stereogram::generateRandomStrip(){
    for(int i=0; i<_height*_strip_w; ++i){
        _strip[i] = 255*(rand()%2);
    }
}

void Stereogram::generateStrips(){
    generateRandomStrip();

    float c=1.0/(_strip_w + 1.0);
    float b=1.0/_strip_w;

    for (int i = 0; i < strips_n; ++i) {
        for (int y = 0; y < _height; ++y) {
            for(int x=0; x<_strip_w; ++x){
                float a = _width*c*static_cast<float>(_image(b * x / (c - 1), y)) / 255.0;
                if(i==0){
                    if(x+a <_strip_w)
                        _output(x, y) = _strip[y*_strip_w+x+static_cast<int>(a)];
                    else
                        _output(x, y) = _output(x+a-_strip_w, y);
                } else {
                     _output(i*_strip_w+x, y) = _output((i-1)*_strip_w + x+a, y);
                }
            }
        }
    }
}