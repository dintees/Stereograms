#pragma once
#include <wx/image.h>

class ImageHolder
{
public:
	//ImageHolder(wxSize panelSize) : _panelSize(panelSize) {}
	ImageHolder() = default;
	bool LoadImg();
	unsigned char* GetImageData();
	wxImage& GetImage();
	void SetPanelSize(wxSize);
	wxSize GetSize() const { return _image.GetSize(); }
	unsigned char& operator[](int x);
	unsigned char& operator()(int x, int y);

private:
	wxImage _image;
	wxSize _panelSize{ 800,600 };
	unsigned char* _imageData=nullptr;
	int w, h;
};

