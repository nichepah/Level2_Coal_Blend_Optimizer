
// Coal_Blending_ViewView.cpp : implementation of the CCoal_Blending_ViewView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Coal_Blending_View.h"
#include "CoalSiloSource.h"
#endif

#include "Coal_Blending_ViewDoc.h"
#include "Coal_Blending_ViewView.h"
#include "CurrentY18Value.h"
#include "BlendPercent.h"
#include "SetSiloStock.h"
#include "SetSiloStock_02_54.h"
#include "Setsilostock_2A_54a.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UINT nIDTimer = 200;
// CCoal_Blending_ViewView

IMPLEMENT_DYNCREATE(CCoal_Blending_ViewView, CScrollView)

BEGIN_MESSAGE_MAP(CCoal_Blending_ViewView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCoal_Blending_ViewView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	
	ON_COMMAND(ID_Y18_CURRENTVALUE, &CCoal_Blending_ViewView::OnY18Currentvalue)
	
	ON_COMMAND(ID_Y18_BLEND, &CCoal_Blending_ViewView::OnY18Blend)
	
	ON_COMMAND(ID_SILO_1_53, &CCoal_Blending_ViewView::OnSilo153)
	ON_COMMAND(ID_SILO_COALMINES, &CCoal_Blending_ViewView::OnSiloCoalmines)
	ON_COMMAND(ID_SILO_2, &CCoal_Blending_ViewView::OnSilo2)
	ON_COMMAND(ID_SILO_2A, &CCoal_Blending_ViewView::OnSilo2a)
END_MESSAGE_MAP()

// CCoal_Blending_ViewView construction/destruction

CCoal_Blending_ViewView::CCoal_Blending_ViewView()
{
	// TODO: add construction code here

}

CCoal_Blending_ViewView::~CCoal_Blending_ViewView()
{
}

BOOL CCoal_Blending_ViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW, NULL, (HBRUSH)(::CreateSolidBrush(RGB(0, 0, 0))), NULL);
	
	return CScrollView::PreCreateWindow(cs);
}


// CCoal_Blending_ViewView drawing

void CCoal_Blending_ViewView::OnDraw(CDC* pDC)
{
	CCoal_Blending_ViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	
	
	CFont m_Font, m_Font1, m_Font2, m_Font5;

	m_Font.CreateFont(10, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
	m_Font1.CreateFont(30, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
	m_Font2.CreateFont(40, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
	m_Font5.CreateFont(22, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));


	COleDateTime curtime;
	curtime = COleDateTime::GetCurrentTime();

	//dc.DrawIcon(925, 10, sail_icon);
	//dc.SetTextColor(RGB(255, 255, 23));
	//dc.SetBkColor(RGB(0, 0, 0));
	//dc.TextOut(900, 38, _T("DSP - RDCIS"));

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int nLineHeight = tm.tmHeight + tm.tmExternalLeading;
	CPoint pText(0, 0);
	int y = 0;
	UpdateData(TRUE);

	pDC->SelectObject(m_Font2);
	pDC->SetTextColor(RGB(0, 255, 255));
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->TextOut(pText.x + 650, pText.y, _T("Overview of Coal Handling Plant Silos"));

	
	pDC->SelectObject(m_Font5);
	pDC->SetTextColor(RGB(255, 255, 0));
	pDC->SetBkColor(RGB(0, 0, 0));
	
	// Reading  data from database //
	::CoInitialize(NULL);
	CString m_strConnection, m_strCmdText, m_strConnection1, m_strCmdText1;
	CString m_strCommon1, m_strCommon2;
	_RecordsetPtr m_pRs, m_pRs1;
	
	_variant_t var, var1;
	CString str, str1;
		
	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText = _T("Select * from dbo.Silo_Details ORDER BY Si_No ASC ");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);


	m_strCmdText1 = _T("Select * from dbo.Common_FS");
	m_pRs1.CreateInstance(_uuidof(Recordset));
	m_pRs1->CursorLocation = adUseServer;
	m_pRs1->Open((LPCTSTR)m_strCmdText1, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);



	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	////////////////////////////// FOR SILO NO. 1, 3, 5 ...........53 ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int start_line = pText.y;
	pDC->SetTextColor(RGB(0, 255, 255));
	pDC->TextOut(pText.x + 10, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 75, pText.y, _T("Coal"));
	pDC->TextOut(pText.x + 160, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 270, pText.y, _T("Ash"));
	pDC->TextOut(pText.x + 340, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 420, pText.y, _T("WF"));
	pDC->TextOut(pText.x + 500, pText.y, _T("TPH"));

	pText.y += nLineHeight;
	pText.y = pText.y + nLineHeight/2;
	pDC->TextOut(pText.x + 12, pText.y, _T("No."));
	pDC->TextOut(pText.x + 75, pText.y, _T("Mine"));
	pDC->TextOut(pText.x + 150, pText.y, _T("Selected"));
	pDC->TextOut(pText.x + 280, pText.y, _T("%"));
	pDC->TextOut(pText.x + 330, pText.y, _T("Stock"));
	pDC->TextOut(pText.x + 415, pText.y, _T("Selected"));
	pDC->SetTextColor(RGB(255, 255, 0));

	pText.y += nLineHeight;
	pText.y += nLineHeight;

	int n_index = 0;
	float m_val = 0;
	CString m_Path = _T("");

	for (n_index = 0; n_index <= 26; n_index++)
	{
		var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		str = var;
		pDC->TextOut(pText.x + 30, pText.y,str);

		var = m_pRs->Fields->GetItem(_T("Feed_Status"))->Value;
		if (var.boolVal)
		{
			m_Path = ValidatePath(str);  //Validating Cottect Path for Silo Selection
			if (m_Path != _T(""))
			{
				pDC->SetTextColor(RGB(0, 255, 0));
				//pDC->TextOut(pText.x + 165, pText.y, _T("Yes"));
				pDC->TextOut(pText.x + 165, pText.y, m_Path);
			}
		}
		//else
			//pDC->TextOut(pText.x + 165, pText.y, _T("No"));
		
		var = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
		str = var;
		pDC->TextOut(pText.x + 80, pText.y, str);
		//pDC->SetTextColor(RGB(255, 255, 0));

		////////Displaying Silo Stock
		var = m_pRs->Fields->GetItem(_T("Silo_Stock"))->Value;
		m_val = var.dblVal;
		str.Format(_T("%0.2f"), m_val);
		pDC->TextOut(pText.x + 325, pText.y, str);
		pDC->SetTextColor(RGB(255, 255, 0));


		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			pDC->SetTextColor(RGB(255, 0, 0));
			pDC->TextOut(pText.x + 415, pText.y, _T("Yes"));

			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_val = var.dblVal;

			if (m_val >= 20)  //For valid signal only
			{
				str.Format(_T("%0.2f"), m_val);
				pDC->TextOut(pText.x + 500, pText.y, str);
			}
			else
			{
				if (m_pRs1->Fields->GetItem(_T("Y9_RUN"))->Value.boolVal)
				{
					pDC->SetTextColor(RGB(255, 183, 185));
					pDC->TextOut(pText.x + 500, pText.y, _T("Hanging"));
					pDC->SetTextColor(RGB(255, 0, 0));
				}
				else
				{
					pDC->SetTextColor(RGB(255, 183, 185));
					pDC->TextOut(pText.x + 500, pText.y, _T("Y9 STOP"));
					pDC->SetTextColor(RGB(255, 0, 0));
				}
			}

		}
		//else
			//pDC->TextOut(pText.x + 415, pText.y, _T("No"));

		pText.y += nLineHeight;
		pText.y += nLineHeight;
		
		m_pRs->MoveNext();	
		pDC->SetTextColor(RGB(255, 255, 0));
	}


	////////////////////////////// FOR SILO NO. 2, 4, 6 ........................54  ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

	pText.y = start_line;
	pDC->SetTextColor(RGB(0, 255, 255));
	pDC->TextOut(pText.x + 645, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 710, pText.y, _T("Coal"));
	pDC->TextOut(pText.x + 795, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 905, pText.y, _T("Ash"));
	pDC->TextOut(pText.x + 975, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 1055, pText.y, _T("WF"));
	pDC->TextOut(pText.x + 1135, pText.y, _T("TPH"));

	pText.y += nLineHeight;
	pText.y = pText.y + nLineHeight / 2;
	pDC->TextOut(pText.x + 647, pText.y, _T("No."));
	pDC->TextOut(pText.x + 710, pText.y, _T("Mine"));
	pDC->TextOut(pText.x + 785, pText.y, _T("Selected"));
	pDC->TextOut(pText.x + 915, pText.y, _T("%"));
	pDC->TextOut(pText.x + 965, pText.y, _T("Stock"));
	pDC->TextOut(pText.x + 1050, pText.y, _T("Selected"));
	pDC->SetTextColor(RGB(255, 255, 0));
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	m_Path = _T("");
	for (n_index = 0; n_index <= 26; n_index++)
	{
		var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		str = var;
		pDC->TextOut(pText.x + 660, pText.y, str);

		var = m_pRs->Fields->GetItem(_T("Feed_Status"))->Value;
		if (var.boolVal)
		{
			m_Path = ValidatePath(str);  //Validating Cottect Path for Silo Selection

			if (m_Path != _T(""))
			{
				pDC->SetTextColor(RGB(0, 255, 0));
				pDC->TextOut(pText.x + 805, pText.y, m_Path);
				//pDC->TextOut(pText.x + 805, pText.y, _T("Yes"));
			}
		}
		//else
			//pDC->TextOut(pText.x + 805, pText.y, _T("No"));


		var = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
		str = var;
		pDC->TextOut(pText.x + 720, pText.y, str);
		//pDC->SetTextColor(RGB(255, 255, 0));

		////////Displaying Silo Stock
		var = m_pRs->Fields->GetItem(_T("Silo_Stock"))->Value;
		m_val = var.dblVal;
		str.Format(_T("%0.2f"), m_val);
		pDC->TextOut(pText.x + 960, pText.y, str);
		pDC->SetTextColor(RGB(255, 255, 0));

		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			pDC->SetTextColor(RGB(255, 0, 0));
			pDC->TextOut(pText.x + 1045, pText.y, _T("Yes"));

			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_val = var.dblVal;
			if (m_val >= 20)  //For valid signal only
			{
				str.Format(_T("%0.2f"), m_val);
				pDC->TextOut(pText.x + 1135, pText.y, str);
			}
			else
			{
				if (m_pRs1->Fields->GetItem(_T("Y10_RUN"))->Value.boolVal)
				{
					pDC->SetTextColor(RGB(255, 183, 185));
					pDC->TextOut(pText.x + 1135, pText.y, _T("Hanging"));
					pDC->SetTextColor(RGB(255, 0, 0));
				}
				else
				{
					pDC->SetTextColor(RGB(255, 183, 185));
					pDC->TextOut(pText.x + 1135, pText.y, _T("Y10 STOP"));
					pDC->SetTextColor(RGB(255, 0, 0));
				}
			}

		}
		//else
			//pDC->TextOut(pText.x + 1045, pText.y, _T("No"));


		pText.y += nLineHeight;
		pText.y += nLineHeight;

		m_pRs->MoveNext();
		pDC->SetTextColor(RGB(255, 255, 0));
	}


	////////////////////////////// FOR SILO NO. 2A, 4A, 6A ........................54A  ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////


	pText.y = start_line;
	pDC->SetTextColor(RGB(0, 255, 255));
	pDC->TextOut(pText.x + 1310, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 1370, pText.y, _T("Coal"));
	pDC->TextOut(pText.x + 1450, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 1560, pText.y, _T("Ash"));
	pDC->TextOut(pText.x + 1630, pText.y, _T("Silo"));
	pDC->TextOut(pText.x + 1710, pText.y, _T("WF"));
	pDC->TextOut(pText.x + 1790, pText.y, _T("TPH"));

	pText.y += nLineHeight;
	pText.y = pText.y + nLineHeight / 2;
	pDC->TextOut(pText.x + 1312, pText.y, _T("No."));
	pDC->TextOut(pText.x + 1370, pText.y, _T("Mine"));
	pDC->TextOut(pText.x + 1440, pText.y, _T("Selected"));
	pDC->TextOut(pText.x + 1570, pText.y, _T("%"));
	pDC->TextOut(pText.x + 1620, pText.y, _T("Stock"));
	pDC->TextOut(pText.x + 1705, pText.y, _T("Selected"));
	pDC->SetTextColor(RGB(255, 255, 0));
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	m_Path = _T("");
	for (n_index = 0; n_index <= 26; n_index++)
	{
		var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		str = var;
		pDC->TextOut(pText.x + 1310, pText.y, str);

		var = m_pRs->Fields->GetItem(_T("Feed_Status"))->Value;

		m_Path = ValidatePath(str);  //Validating Cottect Path for Silo Selection
		if (var.boolVal)
		{
			if (m_Path != _T(""))
			{
				pDC->SetTextColor(RGB(0, 255, 0));
				pDC->TextOut(pText.x + 1455, pText.y, m_Path);
				//pDC->TextOut(pText.x + 1455, pText.y, _T("Yes"));
			}
		}
		//else
			//pDC->TextOut(pText.x + 1455, pText.y, _T("No"));

		var = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
		str = var;
		pDC->TextOut(pText.x + 1370, pText.y, str);
		//pDC->SetTextColor(RGB(255, 255, 0));

		////////Displaying Silo Stock
		var = m_pRs->Fields->GetItem(_T("Silo_Stock"))->Value;
		m_val = var.dblVal;
		str.Format(_T("%0.2f"), m_val);
		pDC->TextOut(pText.x + 1625, pText.y, str);
		pDC->SetTextColor(RGB(255, 255, 0));


		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			pDC->SetTextColor(RGB(255, 0, 0));
			pDC->TextOut(pText.x + 1700, pText.y, _T("Yes"));

			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_val = var.dblVal;

			if (m_val >= 20)  //For valid signal only
			{
				str.Format(_T("%0.2f"), m_val);
				pDC->TextOut(pText.x + 1790, pText.y, str);
			}
			else
			{
				if (m_pRs1->Fields->GetItem(_T("Y10A_RUN"))->Value.boolVal)
				{
					pDC->SetTextColor(RGB(255, 183, 185));
					pDC->TextOut(pText.x + 1790, pText.y, _T("Hanging"));
					pDC->SetTextColor(RGB(255, 0, 0));
				}
				else
				{
					pDC->SetTextColor(RGB(255, 183, 185));
					pDC->TextOut(pText.x + 1790, pText.y, _T("Y10A STOP"));
					pDC->SetTextColor(RGB(255, 0, 0));
				}
			}


		}
		//else
			//pDC->TextOut(pText.x + 1700, pText.y, _T("No"));



		pText.y += nLineHeight;
		pText.y += nLineHeight;

		m_pRs->MoveNext();
		pDC->SetTextColor(RGB(255, 255, 0));
	}

	m_pRs->Close();
	m_pRs1->Close();

	UINT TimerVal;
	TimerVal = SetTimer(nIDTimer, 20000, NULL);
}

void CCoal_Blending_ViewView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	/*CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);*/


	CSize sizeTotal(15000, 30000);
	// TODO: calculate the total size of this view
	//sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CCoal_Blending_ViewView printing


void CCoal_Blending_ViewView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCoal_Blending_ViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCoal_Blending_ViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCoal_Blending_ViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCoal_Blending_ViewView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCoal_Blending_ViewView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

CString CCoal_Blending_ViewView::ValidatePath(CString m_Silo_No)
{
	CString m_Path = _T("");

	bool Y1_P1, Y1_P2, Y1_P3, Y1_P4, Y1_P5, Y1_P6, Y2_P1, Y2_P2, Y2_P3, Y2_P4, Y2_P5, Y2_P6, Y1, Y2;
	Y1_P1 = Y1_P2 = Y1_P3 = Y1_P4 = Y1_P5 = Y1_P6 = Y2_P1 = Y2_P2 = Y2_P3 = Y2_P4 = Y2_P5 = Y2_P6 = Y1 = Y2 = 0;

	
	///////////OPENING ULS COMMON DATABASE ///////////////////
	CString  m_strConnection_uls, m_strCmdText_uls;
	_RecordsetPtr m_pRs_uls;

	m_strConnection_uls = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText_uls = _T("Select * from Common_ULS");
	m_pRs_uls.CreateInstance(_uuidof(Recordset));
	m_pRs_uls->CursorLocation = adUseServer;
	m_pRs_uls->Open((LPCTSTR)m_strCmdText_uls, (LPCTSTR)m_strConnection_uls, adOpenDynamic, adLockOptimistic, adCmdText);

	/////////READING SELECTED PATHS ///////////////
	Y1_P1 = m_pRs_uls->Fields->GetItem("Y1_P1")->Value.boolVal;
	Y1_P2 = m_pRs_uls->Fields->GetItem("Y1_P2")->Value.boolVal;
	Y1_P3 = m_pRs_uls->Fields->GetItem("Y1_P3")->Value.boolVal;
	Y1_P4 = m_pRs_uls->Fields->GetItem("Y1_P4")->Value.boolVal;
	Y1_P5 = m_pRs_uls->Fields->GetItem("Y1_P5")->Value.boolVal;
	Y1_P6 = m_pRs_uls->Fields->GetItem("Y1_P6")->Value.boolVal;

	Y2_P1 = m_pRs_uls->Fields->GetItem("Y2_P1")->Value.boolVal;
	Y2_P2 = m_pRs_uls->Fields->GetItem("Y2_P2")->Value.boolVal;
	Y2_P3 = m_pRs_uls->Fields->GetItem("Y2_P3")->Value.boolVal;
	Y2_P4 = m_pRs_uls->Fields->GetItem("Y2_P4")->Value.boolVal;
	Y2_P5 = m_pRs_uls->Fields->GetItem("Y2_P5")->Value.boolVal;
	Y2_P6 = m_pRs_uls->Fields->GetItem("Y2_P6")->Value.boolVal;

	Y1 = m_pRs_uls->Fields->GetItem("Y1_RUN")->Value.boolVal;
	Y2 = m_pRs_uls->Fields->GetItem("Y2_RUN")->Value.boolVal;

	m_pRs_uls->Close();
	////////////////////////////////////////////////////////////

	if ((Y1_P1 && Y1) || (Y2_P1 && Y2))
	{
		if (m_Silo_No == _T("1"))
		{
			if (Y1_P1 && Y1)
				m_Path = _T("Y1_P1");
			if (Y2_P1 && Y2)
				m_Path = _T("Y2_P1");			
		}
	}
	// added for y1 / y2 stop with path selection
	if ((Y1_P1 && !Y1) || (Y2_P1 && !Y2))
	{
		if (m_Silo_No == _T("1"))
		{
			if (Y1_P1 && !Y1)
				m_Path = _T("Y1 Stopped");
			if (Y2_P1 && !Y2)
				m_Path = _T("Y2 Stopped");
		}
	}

	if ((Y1_P2 && Y1) || (Y2_P2  && Y2))
	{
		if ((m_Silo_No == _T("3")) || (m_Silo_No == _T("5")) || (m_Silo_No == _T("7")) || (m_Silo_No == _T("9")) || (m_Silo_No == _T("11")) || (m_Silo_No == _T("13")) || (m_Silo_No == _T("15")) || (m_Silo_No == _T("17")) || (m_Silo_No == _T("19")) || (m_Silo_No == _T("21")) || (m_Silo_No == _T("23")) || (m_Silo_No == _T("25")) || (m_Silo_No == _T("27")) || (m_Silo_No == _T("29")) || (m_Silo_No == _T("31")) || (m_Silo_No == _T("33")) || (m_Silo_No == _T("35")) || (m_Silo_No == _T("37")) || (m_Silo_No == _T("39")) || (m_Silo_No == _T("41")) || (m_Silo_No == _T("43")) || (m_Silo_No == _T("45")) || (m_Silo_No == _T("47")) || (m_Silo_No == _T("49")) || (m_Silo_No == _T("51")) || (m_Silo_No == _T("53")))
		{
			if (Y1_P2 && Y1)
				m_Path = _T("Y1_P2");
			if (Y2_P2 && Y2)
				m_Path = _T("Y2_P2");
		}			
	}
	// added for y1 / y2 stop with path selection
	if ((Y1_P2 && !Y1) || (Y2_P2  && !Y2))
	{
		if ((m_Silo_No == _T("3")) || (m_Silo_No == _T("5")) || (m_Silo_No == _T("7")) || (m_Silo_No == _T("9")) || (m_Silo_No == _T("11")) || (m_Silo_No == _T("13")) || (m_Silo_No == _T("15")) || (m_Silo_No == _T("17")) || (m_Silo_No == _T("19")) || (m_Silo_No == _T("21")) || (m_Silo_No == _T("23")) || (m_Silo_No == _T("25")) || (m_Silo_No == _T("27")) || (m_Silo_No == _T("29")) || (m_Silo_No == _T("31")) || (m_Silo_No == _T("33")) || (m_Silo_No == _T("35")) || (m_Silo_No == _T("37")) || (m_Silo_No == _T("39")) || (m_Silo_No == _T("41")) || (m_Silo_No == _T("43")) || (m_Silo_No == _T("45")) || (m_Silo_No == _T("47")) || (m_Silo_No == _T("49")) || (m_Silo_No == _T("51")) || (m_Silo_No == _T("53")))
		{
			if (Y1_P2 && !Y1)
				m_Path = _T("Y1 Stopped");
			if (Y2_P2 && !Y2)
				m_Path = _T("Y2 Stopped");
		}
	}



	if ((Y1_P3 && Y1) || (Y2_P3  && Y2))
	{
		if (m_Silo_No == _T("2"))
		{
			if (Y1_P3 && Y1)
				m_Path = _T("Y1_P3");
			if (Y2_P3  && Y2)
				m_Path = _T("Y2_P3");
		}
	}
	// added for y1 / y2 stop with path selection
	if ((Y1_P3 && !Y1) || (Y2_P3  && !Y2))
	{
		if (m_Silo_No == _T("2"))
		{
			if (Y1_P3 && !Y1)
				m_Path = _T("Y1 Stopped");
			if (Y2_P3  && !Y2)
				m_Path = _T("Y2 Stopped");
		}
	}



	if ((Y1_P4  && Y1) || (Y2_P4  && Y2))
	{
		if ((m_Silo_No == _T("4")) || (m_Silo_No == _T("6")) || (m_Silo_No == _T("8")) || (m_Silo_No == _T("10")) || (m_Silo_No == _T("12")) || (m_Silo_No == _T("14")) || (m_Silo_No == _T("16")) || (m_Silo_No == _T("18")) || (m_Silo_No == _T("20")) || (m_Silo_No == _T("22")) || (m_Silo_No == _T("24")) || (m_Silo_No == _T("26")) || (m_Silo_No == _T("28")) || (m_Silo_No == _T("30")) || (m_Silo_No == _T("32")) || (m_Silo_No == _T("34")) || (m_Silo_No == _T("36")) || (m_Silo_No == _T("38")) || (m_Silo_No == _T("40")) || (m_Silo_No == _T("42")) || (m_Silo_No == _T("44")) || (m_Silo_No == _T("46")) || (m_Silo_No == _T("48")) || (m_Silo_No == _T("50")) || (m_Silo_No == _T("52")) || (m_Silo_No == _T("54")))
		{
			if (Y1_P4 && Y1)
				m_Path = _T("Y1_P4");
			if (Y2_P4  && Y2)
				m_Path = _T("Y2_P4");
		}
	}
	// added for y1 / y2 stop with path selection
	if ((Y1_P4  && !Y1) || (Y2_P4  && !Y2))
	{
		if ((m_Silo_No == _T("4")) || (m_Silo_No == _T("6")) || (m_Silo_No == _T("8")) || (m_Silo_No == _T("10")) || (m_Silo_No == _T("12")) || (m_Silo_No == _T("14")) || (m_Silo_No == _T("16")) || (m_Silo_No == _T("18")) || (m_Silo_No == _T("20")) || (m_Silo_No == _T("22")) || (m_Silo_No == _T("24")) || (m_Silo_No == _T("26")) || (m_Silo_No == _T("28")) || (m_Silo_No == _T("30")) || (m_Silo_No == _T("32")) || (m_Silo_No == _T("34")) || (m_Silo_No == _T("36")) || (m_Silo_No == _T("38")) || (m_Silo_No == _T("40")) || (m_Silo_No == _T("42")) || (m_Silo_No == _T("44")) || (m_Silo_No == _T("46")) || (m_Silo_No == _T("48")) || (m_Silo_No == _T("50")) || (m_Silo_No == _T("52")) || (m_Silo_No == _T("54")))
		{
			if (Y1_P4 && !Y1)
				m_Path = _T("Y1 Stopped");
			if (Y2_P4  && !Y2)
				m_Path = _T("Y2 Stopped");
		}
	}



	if ((Y1_P5  && Y1) || (Y2_P5  && Y2))
	{
		if (m_Silo_No == _T("2A"))
		{
			if (Y1_P5  && Y1)
				m_Path = _T("Y1_P5");
			if (Y2_P5  && Y2)
				m_Path = _T("Y2_P5");
		}
	}
	// added for y1 / y2 stop with path selection
	if ((Y1_P5  && !Y1) || (Y2_P5  && !Y2))
	{
		if (m_Silo_No == _T("2A"))
		{
			if (Y1_P5  && !Y1)
				m_Path = _T("Y1 Stopped");
			if (Y2_P5  && !Y2)
				m_Path = _T("Y2 Stopped");
		}
	}


	if ((Y1_P6  && Y1) || (Y2_P6  && Y2))
	{
		if ((m_Silo_No == _T("4A")) || (m_Silo_No == _T("6A")) || (m_Silo_No == _T("8A")) || (m_Silo_No == _T("10A")) || (m_Silo_No == _T("12A")) || (m_Silo_No == _T("14A")) || (m_Silo_No == _T("16A")) || (m_Silo_No == _T("18A")) || (m_Silo_No == _T("20A")) || (m_Silo_No == _T("22A")) || (m_Silo_No == _T("24A")) || (m_Silo_No == _T("26A")) || (m_Silo_No == _T("28A")) || (m_Silo_No == _T("30A")) || (m_Silo_No == _T("32A")) || (m_Silo_No == _T("34A")) || (m_Silo_No == _T("36A")) || (m_Silo_No == _T("38A")) || (m_Silo_No == _T("40A")) || (m_Silo_No == _T("42A")) || (m_Silo_No == _T("44A")) || (m_Silo_No == _T("46A")) || (m_Silo_No == _T("48A")) || (m_Silo_No == _T("50A")) || (m_Silo_No == _T("52A")) || (m_Silo_No == _T("54A")))
		{
			if (Y1_P6 && Y1)
				m_Path = _T("Y1_P6");
			
			if (Y2_P6  && Y2)
				m_Path = _T("Y2_P6");

		}
	}

	// added for y1 / y2 stop with path selection
	if ((Y1_P6  && !Y1) || (Y2_P6  && !Y2))
	{
		if ((m_Silo_No == _T("4A")) || (m_Silo_No == _T("6A")) || (m_Silo_No == _T("8A")) || (m_Silo_No == _T("10A")) || (m_Silo_No == _T("12A")) || (m_Silo_No == _T("14A")) || (m_Silo_No == _T("16A")) || (m_Silo_No == _T("18A")) || (m_Silo_No == _T("20A")) || (m_Silo_No == _T("22A")) || (m_Silo_No == _T("24A")) || (m_Silo_No == _T("26A")) || (m_Silo_No == _T("28A")) || (m_Silo_No == _T("30A")) || (m_Silo_No == _T("32A")) || (m_Silo_No == _T("34A")) || (m_Silo_No == _T("36A")) || (m_Silo_No == _T("38A")) || (m_Silo_No == _T("40A")) || (m_Silo_No == _T("42A")) || (m_Silo_No == _T("44A")) || (m_Silo_No == _T("46A")) || (m_Silo_No == _T("48A")) || (m_Silo_No == _T("50A")) || (m_Silo_No == _T("52A")) || (m_Silo_No == _T("54A")))
		{
			if (Y1_P6 && !Y1)
				m_Path = _T("Y1 Stopped");

			if (Y2_P6  && !Y2)
				m_Path = _T("Y2 Stopped");

		}
	}

	return(m_Path);
}



// CCoal_Blending_ViewView diagnostics

#ifdef _DEBUG
void CCoal_Blending_ViewView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCoal_Blending_ViewView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCoal_Blending_ViewDoc* CCoal_Blending_ViewView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoal_Blending_ViewDoc)));
	return (CCoal_Blending_ViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CCoal_Blending_ViewView message handlers

void CCoal_Blending_ViewView::OnSiloCoalmines()
{
	// TODO: Add your command handler code here
	CCoalSiloSource m_CoalSource;
	m_CoalSource.DoModal();
}




void CCoal_Blending_ViewView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent)
		KillTimer(nIDEvent);

	Invalidate();

	CScrollView::OnTimer(nIDEvent);
}

void CCoal_Blending_ViewView::OnY18Currentvalue()
{
	// TODO: Add your command handler code here
	CCurrentY18Value m_Y18_Value;
	m_Y18_Value.DoModal();
}





void CCoal_Blending_ViewView::OnY18Blend()
{
	// TODO: Add your command handler code here
	CBlendPercent m_Blend;
	m_Blend.DoModal();
}





void CCoal_Blending_ViewView::OnSilo153()
{
	// TODO: Add your command handler code here
	//sILO sTOCK 1-53
	CSetSiloStock m_1_53_SiloStock;
	m_1_53_SiloStock.DoModal();
}

void CCoal_Blending_ViewView::OnSilo2()
{
	// TODO: Add your command handler code here
	CSetSiloStock_02_54 m_2_54_SiloStock;
	m_2_54_SiloStock.DoModal();
}


void CCoal_Blending_ViewView::OnSilo2a()
{
	// TODO: Add your command handler code here
	Setsilostock_2A_54a m_2A_54A_SiloStock;
	m_2A_54A_SiloStock.DoModal();
}
