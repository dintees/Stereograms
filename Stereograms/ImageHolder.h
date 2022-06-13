#pragma once
#include <wx/image.h>

class ImageHolder
{
public:
	ImageHolder(wxSize panelSize) : _panelSize(panelSize) {}
	ImageHolder() = default;
	bool LoadImg();
	unsigned char* GetImageData();
	wxImage& GetImage();
	void SetPanelSize(wxSize);
	void convertToImg();
	unsigned char& operator[](int x);
	unsigned char& operator()(int x, int y);
	void init();
private:
	wxImage _image;
	wxSize _panelSize;
	unsigned char* _imageData=nullptr;
	int w, h;
};

