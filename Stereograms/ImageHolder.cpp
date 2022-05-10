#include "ImageHolder.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

void ImageHolder::LoadImg()
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxBMPHandler);
	wxString filename = wxFileSelector(_T("Select file"), _T(""), _T(""), _T("*.bmp"), _T("All files (*.bmp)|*.bmp"));
	if(!_image.LoadFile(filename))
	{
		wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowa\u0107 obrazka"));
	}

	int panelHeight = _panelSize.GetHeight();
	int panelWidth = _panelSize.GetWidth();

	// modyfikacja rozmiaru zdjecia jesli jest wieksze niz dlugosc/szerokosc panelu
	if (panelWidth <= _image.GetWidth() && panelHeight <= _image.GetHeight()) _image = _image.Rescale(panelWidth, panelHeight);
	else if (panelWidth <= _image.GetWidth() && panelHeight >= _image.GetHeight()) _image = _image.Rescale(panelWidth, _image.GetHeight());
	else if (panelWidth >= _image.GetWidth() && panelHeight <= _image.GetHeight()) _image = _image.Rescale(_image.GetWidth(), panelHeight);

	int imageHeight = _image.GetHeight();
	int imageWidth = _image.GetWidth();

	// wersja kolorowa
	/*_imageData = new unsigned char[imageHeight * imageWidth * 3];
	_imageData = _image.GetData();*/
	
	// wersja szara
	auto imgDataTemp = new unsigned char[imageHeight * imageWidth * 3];
	imgDataTemp = _image.GetData();
	_imageData = new unsigned char[imageHeight * imageWidth];
	for (int i = 0; i < imageHeight * imageWidth; i++)
	{
		_imageData[i] = 0.299 * imgDataTemp[i] + 0.587 * imgDataTemp[i + 1] + 0.114 * imgDataTemp[i + 2];
	}
}
unsigned char& ImageHolder::operator()(int x, int y)
{
	return _imageData[x * y];
}

unsigned char* ImageHolder::GetImageData()
{
	return _imageData;
}
wxImage& ImageHolder::GetImage()
{
	return _image;
}
void ImageHolder::SetPanelSize(wxSize size)
{
	_panelSize = size;
}
