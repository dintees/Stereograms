#pragma once
#include <wx/image.h>

class ImageHolder
{
public:
	ImageHolder(wxSize panelSize) : _panelSize(panelSize) {}
	ImageHolder() = default;
	void LoadImg();
	unsigned char* GetImageData();
	wxImage& GetImage();
	void SetPanelSize(wxSize);
	unsigned char& operator[](int x);
private:
	wxImage _image;
	wxSize _panelSize;
	unsigned char* _imageData;
};

