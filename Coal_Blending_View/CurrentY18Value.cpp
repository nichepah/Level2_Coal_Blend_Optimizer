// CurrentY18Value.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "CurrentY18Value.h"
#include "afxdialogex.h"


// CCurrentY18Value dialog

IMPLEMENT_DYNAMIC(CCurrentY18Value, CDialog)

CCurrentY18Value::CCurrentY18Value(CWnd* pParent /*=NULL*/)
	: CDialog(CCurrentY18Value::IDD, pParent)
{

}

CCurrentY18Value::~CCurrentY18Value()
{
}

void CCurrentY18Value::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCurrentY18Value, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCurrentY18Value message handlers


void CCurrentY18Value::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages

	CBrush backBruch(RGB(0, 0, 02));
	//CBrush backBruch(RGB(255,189,222));
	CBrush* pOldBrush = dc.SelectObject(&backBruch);
	dc.PatBlt(0, 0, GetSystemMetrics(SM_CXFULLSCREEN), ::GetSystemMetrics(SM_CYFULLSCREEN), PATCOPY);
	dc.SelectObject(pOldBrush);

	CFont m_Font, m_Font1, m_Font2, m_Font5;

	m_Font.CreateFont(24, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
	m_Font1.CreateFont(40, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));


	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	int nLineHeight = tm.tmHeight + tm.tmExternalLeading;
	CPoint pText(0, 0);
	int y = 0;
	UpdateData(TRUE);

	dc.SelectObject(m_Font1);
	dc.SetTextColor(RGB(0, 255, 255));
	dc.SetBkColor(RGB(0, 0, 0));
	dc.TextOut(pText.x + 650, pText.y, _T("Y18 CURRENT DATA"));

		// Reading  data from database //
	::CoInitialize(NULL);
	CString m_strConnection, m_strCmdText, m_strConnection1, m_strCmdText1;
	CString m_strCommon1, m_strCommon2;
	_RecordsetPtr m_pRs;
	_variant_t var, var1;
	CString str, str1;
	double m_val = 0;

	dc.SelectObject(m_Font);
	dc.SetTextColor(RGB(255, 255, 23));
	dc.SetBkColor(RGB(0, 0, 0));

	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	

	int start_line = pText.y;
	dc.SetTextColor(RGB(255, 255, 0));
	dc.TextOut(pText.x + 10, pText.y, _T("Time"));
	dc.TextOut(pText.x + 200, pText.y, _T("TPH"));
	dc.TextOut(pText.x + 300, pText.y, _T("ASH AR"));
	dc.TextOut(pText.x + 400, pText.y, _T("ASH DB"));
	dc.TextOut(pText.x + 500, pText.y, _T("MOIST"));
	dc.TextOut(pText.x + 600, pText.y, _T("CV"));
	dc.TextOut(pText.x + 700, pText.y, _T("SIO2"));
	dc.TextOut(pText.x + 800, pText.y, _T("AL2O3"));
	dc.TextOut(pText.x + 900, pText.y, _T("FE2O3"));
	dc.TextOut(pText.x + 1000, pText.y, _T("CAO"));
	dc.TextOut(pText.x + 1100, pText.y, _T("NA2O"));
	dc.TextOut(pText.x + 1200, pText.y, _T("K2O"));
	dc.TextOut(pText.x + 1300, pText.y, _T("TiO2"));
	dc.TextOut(pText.x + 1400, pText.y, _T("N"));
	dc.TextOut(pText.x + 1500, pText.y, _T("Cl"));
	dc.TextOut(pText.x + 1600, pText.y, _T("S"));

	pText.y += nLineHeight;
	pText.y += nLineHeight;

	COleDateTime m_Time;
	
	dc.SetTextColor(RGB(0, 255, 255));
	::CoInitialize(NULL);
	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Analyzer_Db;Trusted=True;");
	m_strCmdText = _T("Select * from dbo.Y18_Analyzer_1_MIN");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);
	

	m_pRs->MoveLast();

	for (int n = 0; n <= 25; ++n)
	{
		var = m_pRs->Fields->GetItem(_T("Time_Stamp"))->Value;
		if (var.vt != VT_NULL)
		{
			m_Time = var;
			str = m_Time.Format(_T("%I:%M :%S %p"));
			dc.TextOut(pText.x + 15, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("TPH_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 200, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("ASH_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 315, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("ASH_DB_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 400, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("MOIST_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 500, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("CV_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 590, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("SIO2_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 700, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("AL2O3_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 800, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("FE2O3_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 900, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("CAO_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1000, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("NA2O_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1100, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("NA2O_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1100, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("K2O_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1200, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("TIO2_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1300, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("N_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1400, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("CL_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1500, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("S_AR_1_MIN"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1600, pText.y, str);

		}

		m_pRs->MovePrevious();
		pText.y += nLineHeight;
		pText.y += nLineHeight;
		
	}

	m_pRs->Close();


		

}
