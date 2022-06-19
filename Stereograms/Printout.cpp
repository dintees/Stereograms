#include "Printout.h"

bool Printout::OnBeginDocument(int startPage, int endPage)
{
	if (wxPrintout::OnBeginDocument(startPage, endPage)) return true;
	return false;
}

bool Printout::OnPrintPage(int pageNum)
{
	wxDC* dc = GetDC();
	FitThisSizeToPageMargins(wxSize(800, 600), *_pageSetupData);
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

bool DefaultPrinterAvailable() {
	DWORD size = 0;
	DWORD numprinters;
	DWORD dwSizeNeeded = 0;

	// Get the size of the default printer name.
	GetDefaultPrinter(NULL, &size);
	// Get the name of default printer
	TCHAR* buffer = new TCHAR[size];
	EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 2, NULL, 0, &dwSizeNeeded, &numprinters);

	// Get the printer name.
	GetDefaultPrinter(buffer, &size);

	HANDLE hPrinter = NULL;
	// Get a pointer to the default printer
	OpenPrinter(buffer, &hPrinter, NULL);
	LPSTR pPrinterInfo = (LPSTR)malloc(dwSizeNeeded);
	DWORD cByteUsed;

	wxProgressDialog a(_("Printer check"), _("Looking for default printer. Please wait."));
	a.Pulse();
	if (!GetPrinter(hPrinter, 2, (LPBYTE)pPrinterInfo, dwSizeNeeded, &cByteUsed))
	{
		/* Failure to access the printer. */

		free(pPrinterInfo);
		pPrinterInfo = NULL;
		// return FALSE;
		//a.Pulse();
		return false;
	}
	else {
		free(pPrinterInfo);
		pPrinterInfo = NULL;
		//a.Pulse();
		return true;
	}
}