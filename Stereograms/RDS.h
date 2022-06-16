#pragma once

#include "ImageHolder.h"
#include <cstdlib>
#include <ctime>

class Stereogram{
public:
    Stereogram(ImageHolder* img, wxSize size, unsigned num_of_strips) 
     : strips_n{num_of_strips}, _width{size.x}, _height{size.y},
    _strip{new unsigned char[size.y*size.x/num_of_strips]}, _strip_w{size.x / static_cast<int>(num_of_strips)},
        _output{ static_cast<unsigned char*>(malloc(size.x * size.y * 3)), size.x }, _image{ *img }
    {
       srand(time(0));
    }

    ~Stereogram(){delete[] _strip;}

    void generateStrips();
    wxImage GetImg() const;

    wxSize GetSize() const { return wxSize(_width, _height); }

private:
    struct {
        unsigned char* img;
        const int x;

        unsigned char* operator()(int i, int j) { return img + (j * x + i)*3; }
    } _output;

    ImageHolder& _image;
    wxImage out_img;

    void generateRandomStrip();
    void fillChannelsGray();

    unsigned strips_n;
    int _width;
    int _height;
    int _strip_w;
    unsigned char* _strip;
};


inline wxImage Stereogram::GetImg() const {
    return out_img;
}