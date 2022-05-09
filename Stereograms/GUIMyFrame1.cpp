#include "GUIMyFrame1.h"

#include <wx/dcclient.h>

#include "ImageHolder.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::b_LoadFromFile_Click( wxCommandEvent& event )
{
p_OriginalImage->ClearBackground(); // remove old photo from panel
wxClientDC dc(p_OriginalImage);
auto imageHolder = new ImageHolder(dc.GetSize());
imageHolder->LoadImg();
wxImage& image = imageHolder->GetImage();
wxBitmap bitmap(image);
dc.DrawBitmap(bitmap, 0, 0, true);
}


