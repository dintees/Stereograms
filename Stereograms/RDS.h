#pragma once

#include "ImageHolder.h"
#include <cstdlib>
#include <ctime>

class Stereogram{
public:
    Stereogram(wxSize panel_s, wxSize size, unsigned num_of_strips) 
    : strips_n{num_of_strips}, _width{size.x}, _height{size.y},
    _stip{new unsigned char[size.y*size.x/num_of_strips]}, _strip_w{size.x/num_of_strips},
    _output(panel_s)
    {
        srand(time(0));
    }

    ~Stereogram(){delete[] _strip;}


    ImageHolder _output;

private:
    void generateRandomStrip();

    unsigned strips_n;
    int _width;
    int _height;
    int _strip_w;
    unsigned char* _strip;
};