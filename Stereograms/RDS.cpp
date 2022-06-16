#include "RDS.h"
#include <fstream>

void Stereogram::generateRandomStrip(){
    for(int i=0; i<_height*_strip_w; ++i){
        _strip[i] = 255*(rand()%2);
    }
}

void Stereogram::generateStrips(){
    generateRandomStrip();

    float c=_width/(strips_n + 1.0);
    float b=_width/ strips_n;

    /*std::ofstream o;
    o.open("debug.txt");*/
   for (int i = 0; i < strips_n; ++i) {
        for (int y = 0; y < _height; ++y) {
            for(int x=0; x<_strip_w; ++x){
                float a = c * static_cast<float>(_image(i * _strip_w + b * x / (c - 1), y)) / 255.0*0.1;
                //o << a << "," << int(_image(i * _strip_w + b * x / (c - 1), y))<<std::endl;
                if(i==0){
                    if(x+a <_strip_w)
                        *_output(i*_strip_w+x, y) = _strip[y* _strip_w + (x+static_cast<int>(a))%_strip_w];
                    else
                        *_output(x, y) = *_output(b + x+a, y);
                } else {
                    *_output(i * b+x, y) = *_output((i-1)*b + x + a, y);
                }
            }
        }
    }

   int j = strips_n / 2;
       for (int y = 30; y < 40; ++y) {
           for (int x = 10; x < 20; ++x) {
               *_output(j * b + x, y) = *_output((j-1) * b + x, y) = 0;
           }
       }
 
  /* o.close();*/
       fillChannelsGray();

       out_img = wxImage(_width, _height, _output.img);
}

void Stereogram::fillChannelsGray() {
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            _output(i, j)[1] = _output(i, j)[0];
            _output(i, j)[2] = _output(i, j)[0];
        }
    }
}