// CoalSiloSource.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "CoalSiloSource.h"
#include "ChangeSource.h"
#include "afxdialogex.h"


// CCoalSiloSource dialog

IMPLEMENT_DYNAMIC(CCoalSiloSource, CDialog)

CCoalSiloSource::CCoalSiloSource(CWnd* pParent /*=NULL*/)
	: CDialog(CCoalSiloSource::IDD, pParent)
{

}

CCoalSiloSource::~CCoalSiloSource()
{
}

void CCoalSiloSource::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCoalSiloSource, CDialog)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_COMMAND(ID_CHANGESOURCE, &CCoalSiloSource::OnChangesource)
END_MESSAGE_MAP()


// CCoalSiloSource message handlers


void CCoalSiloSource::OnPaint()
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
	
	dc.SelectObject(m_Font1);
	dc.SetTextColor(RGB(255, 51, 0));
	dc.SetBkColor(RGB(0, 0, 0));
	dc.TextOutW(600, 10, _T("SILO-WISE COAL DISTRIBUTION"));

	// Reading  data from database //
	::CoInitialize(NULL);
	CString m_strConnection, m_strCmdText, m_strConnection1, m_strCmdText1;
	CString m_strCommon1, m_strCommon2;
	_RecordsetPtr m_pRs;
	int y_index = 70;
	int x_index = 0;
	_variant_t var, var1;
	CString str, str1;

	dc.SelectObject(m_Font);
	dc.SetTextColor(RGB(255, 255, 23));
	dc.SetBkColor(RGB(0, 0, 0));

	//m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\BLENDING_SOFTWARE\\SiloDetails.mdb;Mode=Read;");
		//m_strCmdText = _T("Select * from SiloDetails ORDER BY SiNo ASC");
	
	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText = _T("Select * from dbo.Silo_Details ORDER BY Si_No ASC ");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);
	
	x_index = 100;
	y_index =70;
	for (int n = 0; n <= 26; n++)
	{
		var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		var1 = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
		str = var;
		str = str + _T("         ");
		str1 = var1;
		str = str + str1;
		dc.TextOutW(x_index, y_index, str);
		y_index = y_index + 35;
	

		m_pRs->MoveNext();
	}

	x_index = 600;
	y_index = 70;
	for (int n = 27; n <= 53; n++)
	{
		var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		var1 = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
		str = var;
		str = str + _T("         ");
		str1 = var1;
		str = str + str1;
		dc.TextOutW(x_index, y_index, str);
		y_index = y_index + 35;


		m_pRs->MoveNext();
	}


	x_index = 1100;
	y_index = 70;
	for (int n = 54; n <= 80; n++)
	{
		var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		var1 = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
		str = var;
		str = str + _T("         ");
		str1 = var1;
		str = str + str1;
		dc.TextOutW(x_index, y_index, str);
		y_index = y_index + 35;


		m_pRs->MoveNext();
	}
	m_pRs->Close();

}


int CCoalSiloSource::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	ShowWindow(SW_MAXIMIZE);
	return 0;
}


void CCoalSiloSource::OnChangesource()
{
	// TODO: Add your command handler code here
	CChangeSource m_ChangeSource;
	m_ChangeSource.DoModal();

	Invalidate(TRUE);

}
