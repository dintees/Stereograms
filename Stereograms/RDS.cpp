#include "RDS.h"
//#include <cassert>

void Stereogram::generateRandomStrip_G() {
    for (int i = 0; i < _height * _strip_w; ++i) {
        _strip[i] = 255 * (rand() % 2);
    }
}

void Stereogram::generateRandomStrip_C() {
    for (int i = 0; i < _height * _strip_w; ++i) {
        _strip[i] = rand() % 7;
    }
}

void Stereogram::generateStrips(bool color) {
    if (!_output.img)
        free(_output.img);

    _output.img = static_cast<unsigned char*>(malloc(_width * _height * 3));

    if(color)
        generateRandomStrip_C();
    else
        generateRandomStrip_G();

    float c = _width / (strips_n + 1.0);
    float b = _width / strips_n;



    for (int i = 0; i < strips_n; ++i) {
        for (int y = 0; y < _height; ++y) {
            for (int x = 0; x < _strip_w; ++x) {
                float a = c * static_cast<float>(_image(i * _strip_w + b * x / (c - 1), y)) / 255.0 * 0.1;


                if (i == 0) {
                    *_output(i * _strip_w + x, y) = _strip[y * _strip_w + (x + static_cast<int>(a)) % _strip_w];
                    //assert(("Going left from strip", (x + static_cast<int>(a)) % _strip_w >= 0));
                }
                else {
                    *_output(i * b + x, y) = *_output((i - 1) * b + x + a, y);
                    //assert(("Again goint left", a + x >= 0));
                }

            }
        }
    }

    int j = strips_n / 2;
    for (int y = 30; y < 40; ++y) {
        for (int x = 10; x < 20; ++x) {
            *_output(j * b + x, y) = *_output((j - 1) * b + x, y) = 0;
        }
    }

    
    if(color)
        fillChannelsColor();
    else
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

void Stereogram::fillChannelsColor() {
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {

            if (_output(i, j)[0] == 0) {
                for (int k = 0; k < 3; ++k) {
                    _output(i, j)[k] = 0;
                }

                continue;
            }
            unsigned char col = _output(i, j)[0] % 3;
            unsigned char def = _output(i, j)[0] % 2;

            for (int k = 0; k < 3; ++k) {
                _output(i, j)[k] = def * 255;
            }

            _output(i, j)[col] = (1 - def) * 255;

        }
    }
}