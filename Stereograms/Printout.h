#pragma once
#include <wx/wx.h>
#include <wx/printdlg.h>
#include <wx/print.h>
#include <wx/printdlg.h>

/**
* @brief a class for handling printing jobs which inherits from wxPrintout
* @tparam std::shared_ptr<wxPageSetupDialogData> keeps informations about page settings
* @tparam wxBitmap image which will be printed
*/

class Printout : public wxPrintout
{
private:
	std::shared_ptr<wxPageSetupDialogData> _pageSetupData;
	wxBitmap _picture;

public:
	// constructor
	Printout(std::shared_ptr<wxPageSetupDialogData> data, wxImage image, const wxChar* title = (const wxChar*)"Stereogram") : _pageSetupData{ data }, _picture{wxBitmap(image)}, wxPrintout(title) {};
	bool OnPrintPage(int page);
	bool OnBeginDocument(int startPage, int endPage);
	void GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo);
};
