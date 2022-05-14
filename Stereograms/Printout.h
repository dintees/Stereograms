#pragma once

class Printout : public wxPrintout
{
private:
	std::shared_ptr<wxPageSetupDialogData> _pageSetupData;
	wxBitmap _picture;

public:
	Printout(std::shared_ptr<wxPageSetupDialogData> data, wxImage image, const wxChar* title = (const wxChar*)"Stereogram") : _pageSetupData{ data }, _picture{wxBitmap(image)}, wxPrintout(title) {};
	bool OnPrintPage(int page);
	bool OnBeginDocument(int startPage, int endPage);
	void GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo);

};

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