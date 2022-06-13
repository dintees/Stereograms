#include "Printout.h"

bool Printout::OnBeginDocument(int startPage, int endPage)
{
	if (wxPrintout::OnBeginDocument(startPage, endPage)) return true;
	return false;
}

bool Printout::OnPrintPage(int pageNum)
{
	wxDC* dc = GetDC();
	FitThisSizeToPageMargins(wxSize(300, 600), *_pageSetupData);
	dc->Clear();
	dc->DrawBitmap(wxBitmap(_picture), 0, 0);
	return true;
}

void Printout::GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo)
{
	*minPage = 1;
	*maxPage = 1;
	*selPageFrom = 1;
	*selPageTo = 1;
}