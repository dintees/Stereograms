#pragma once
#include <wx/image.h>

class ImageHolder
{
public:
	ImageHolder(wxSize panelSize) : _panelSize(panelSize) {}
	void LoadImg();
	unsigned char* GetImageData();
	wxImage& GetImage();
private:
	wxImage _image;
	wxSize _panelSize;
	unsigned char* _imageData;
};

