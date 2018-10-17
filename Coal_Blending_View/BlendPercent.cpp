// BlendPercent.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "BlendPercent.h"
#include "afxdialogex.h"


// CBlendPercent dialog

IMPLEMENT_DYNAMIC(CBlendPercent, CDialog)

CBlendPercent::CBlendPercent(CWnd* pParent /*=NULL*/)
	: CDialog(CBlendPercent::IDD, pParent)
{

}

CBlendPercent::~CBlendPercent()
{
}

void CBlendPercent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBlendPercent, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDREFRESH1, &CBlendPercent::OnBnClickedRefresh1)
END_MESSAGE_MAP()


// CBlendPercent message handlers


void CBlendPercent::OnPaint()
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

	m_Font.CreateFont(22, 0, 0, 0, FW_HEAVY, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
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
	dc.TextOut(pText.x + 650, pText.y, _T("CURRENT BLEND PERCENTAGE"));

	// Reading  data from database //
	::CoInitialize(NULL);
	CString m_strConnection, m_strCmdText, m_strConnection1, m_strCmdText1;
	CString m_strCommon1, m_strCommon2;
	_RecordsetPtr m_pRs, m_pRs1;

	_variant_t var, var1;
	CString str, str1;
	double m_val, m_silo_discharge_rate;
	m_val = m_silo_discharge_rate = 0;

	CString Silo_Coal_Type[10], Silo_String[10];
	double CoalTypeWise_discharge[10];
	for (int n = 0; n < 10; n++)
	{
		Silo_Coal_Type[n] = _T("");
		Silo_String[n] = _T("");
		CoalTypeWise_discharge[n] = 0;
	}

	int start_line = pText.y;
	dc.SelectObject(m_Font);
	dc.SetTextColor(RGB(255, 255, 0));

	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;


	////////////////////////////// FOR SILO NO. 1, 3, 5 ...........53 ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

	dc.TextOut(pText.x + 10, pText.y, _T("Silo"));
	dc.TextOut(pText.x + 100, pText.y, _T("Coal"));
	dc.TextOut(pText.x + 200, pText.y, _T("Set"));
	dc.TextOut(pText.x + 300, pText.y, _T("Actual"));

	pText.y += nLineHeight;
	pText.y = pText.y + nLineHeight / 2;
	dc.TextOut(pText.x + 12, pText.y, _T("No."));
	dc.TextOut(pText.x + 100, pText.y, _T("Mine"));
	dc.TextOut(pText.x + 200, pText.y, _T("Point"));
	dc.TextOut(pText.x + 300, pText.y, _T("TPH"));
	
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	
	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText = _T("Select * from dbo.Silo_Details ORDER BY Si_No ASC ");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);

	m_strCmdText1 = _T("Select * from dbo.Common_FS");
	m_pRs1.CreateInstance(_uuidof(Recordset));
	m_pRs1->CursorLocation = adUseServer;
	m_pRs1->Open((LPCTSTR)m_strCmdText1, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);

	int n_type_count = 0; //Count for type of Coal being discharged
	bool type_check = 0; //Status of coal type repeating

	for (int n_index = 0; n_index <= 26; n_index++)
	{
		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_silo_discharge_rate = var.dblVal;

			var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
			str = var;
			dc.TextOut(pText.x + 10, pText.y, str);

			str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
			dc.TextOut(pText.x + 100, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("TPH_SP_HMI"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 200, pText.y, str);

			if (m_silo_discharge_rate >= 20)  //For valid signal only
			{
				var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
				m_val = var.dblVal;
				str.Format(_T("%0.2f"), m_val);
				dc.TextOut(pText.x + 300, pText.y, str);

				str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
				
				for (int check = 0; check < 10; check++) //Checking Coal Type is already available in Coal type array or not
				{
					if (Silo_Coal_Type[check] == str)
						type_check = 1;
				}

				if (!type_check) //New Coal Type
				{
					Silo_Coal_Type[n_type_count] = str;
					n_type_count++;
				}
				
				type_check = 0;

				pText.y += nLineHeight;
				pText.y += nLineHeight;				
				
			}
			else
			{
				if (m_pRs1->Fields->GetItem(_T("Y9_RUN"))->Value.boolVal)
				{
					dc.SetTextColor(RGB(255, 183, 185));
					dc.TextOut(pText.x + 300, pText.y, _T("Hanging"));
					dc.SetTextColor(RGB(255, 255, 0));
				}
				else
				{
					dc.SetTextColor(RGB(255, 183, 185));
					dc.TextOut(pText.x + 300, pText.y, _T("Y9 STOP"));
					dc.SetTextColor(RGB(255, 255, 0));
				}
				pText.y += nLineHeight;
				pText.y += nLineHeight;
			}
		}
		m_pRs->MoveNext();
	}

	////////////////////////////// FOR SILO NO. 2, 4, 6 ........................54  ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

	pText.y = start_line;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	dc.TextOut(pText.x + 500, pText.y, _T("Silo"));
	dc.TextOut(pText.x + 600, pText.y, _T("Coal"));
	dc.TextOut(pText.x + 700, pText.y, _T("Set"));
	dc.TextOut(pText.x + 800, pText.y, _T("Actual"));

	pText.y += nLineHeight;
	pText.y = pText.y + nLineHeight / 2;
	dc.TextOut(pText.x + 500, pText.y, _T("No."));
	dc.TextOut(pText.x + 600, pText.y, _T("Mine"));
	dc.TextOut(pText.x + 700, pText.y, _T("Point"));
	dc.TextOut(pText.x + 800, pText.y, _T("TPH"));

	pText.y += nLineHeight;
	pText.y += nLineHeight;
	for (int n_index = 0; n_index <= 26; n_index++)
	{
		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_silo_discharge_rate = var.dblVal;

			var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
			str = var;
			dc.TextOut(pText.x + 500, pText.y, str);

			str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
			dc.TextOut(pText.x + 600, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("TPH_SP_HMI"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 700, pText.y, str);

			if (m_silo_discharge_rate >= 20)  //For valid signal only
			{
				var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
				m_val = var.dblVal;
				str.Format(_T("%0.2f"), m_val);
				dc.TextOut(pText.x + 800, pText.y, str);

				str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;

				for (int check = 0; check < 10; check++) //Checking Coal Type is already available in Coal type array or not
				{
					if (Silo_Coal_Type[check] == str)
						type_check = 1;
				}

				if (!type_check) //New Coal Type
				{
					Silo_Coal_Type[n_type_count] = str;
					n_type_count++;
				}

				type_check = 0;

				pText.y += nLineHeight;
				pText.y += nLineHeight;

			}
			else
			{
				if (m_pRs1->Fields->GetItem(_T("Y10_RUN"))->Value.boolVal)
				{
					dc.SetTextColor(RGB(255, 183, 185));
					dc.TextOut(pText.x + 800, pText.y, _T("Hanging"));
					dc.SetTextColor(RGB(255, 255, 0));
				}
				else
				{
					dc.SetTextColor(RGB(255, 183, 185));
					dc.TextOut(pText.x + 800, pText.y, _T("Y10 STOP"));
					dc.SetTextColor(RGB(255, 255, 0));
				}
				pText.y += nLineHeight;
				pText.y += nLineHeight;
			}
		}
		m_pRs->MoveNext();
	}

	////////////////////////////// FOR SILO NO. 2A, 4A, 6A ........................54A  ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	pText.y = start_line;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	dc.TextOut(pText.x + 1000, pText.y, _T("Silo"));
	dc.TextOut(pText.x + 1100, pText.y, _T("Coal"));
	dc.TextOut(pText.x + 1200, pText.y, _T("Set"));
	dc.TextOut(pText.x + 1300, pText.y, _T("Actual"));

	pText.y += nLineHeight;
	pText.y = pText.y + nLineHeight / 2;
	dc.TextOut(pText.x + 1000, pText.y, _T("No."));
	dc.TextOut(pText.x + 1100, pText.y, _T("Mine"));
	dc.TextOut(pText.x + 1200, pText.y, _T("Point"));
	dc.TextOut(pText.x + 1300, pText.y, _T("TPH"));

	pText.y += nLineHeight;
	pText.y += nLineHeight;
	for (int n_index = 0; n_index <= 26; n_index++)
	{
		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_silo_discharge_rate = var.dblVal;

			var = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
			str = var;
			dc.TextOut(pText.x + 1000, pText.y, str);

			str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
			dc.TextOut(pText.x + 1100, pText.y, str);

			var = m_pRs->Fields->GetItem(_T("TPH_SP_HMI"))->Value;
			m_val = var.dblVal;
			str.Format(_T("%0.2f"), m_val);
			dc.TextOut(pText.x + 1200, pText.y, str);

			if (m_silo_discharge_rate >= 20)  //For valid signal only
			{
				var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
				m_val = var.dblVal;
				str.Format(_T("%0.2f"), m_val);
				dc.TextOut(pText.x + 1300, pText.y, str);

				str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;

				for (int check = 0; check < 10; check++) //Checking Coal Type is already available in Coal type array or not
				{
					if (Silo_Coal_Type[check] == str)
						type_check = 1;
				}

				if (!type_check) //New Coal Type
				{
					Silo_Coal_Type[n_type_count] = str;
					n_type_count++;
				}

				type_check = 0;

				pText.y += nLineHeight;
				pText.y += nLineHeight;

			}
			else
			{
				if (m_pRs1->Fields->GetItem(_T("Y10A_RUN"))->Value.boolVal)
				{
					dc.SetTextColor(RGB(255, 183, 185));
					dc.TextOut(pText.x + 1300, pText.y, _T("Hanging"));
					dc.SetTextColor(RGB(255, 255, 0));
				}
				else
				{
					dc.SetTextColor(RGB(255, 183, 185));
					dc.TextOut(pText.x + 1300, pText.y, _T("Y10A STOP"));
					dc.SetTextColor(RGB(255, 255, 0));
				}
				pText.y += nLineHeight;
				pText.y += nLineHeight;
			}
		}
		m_pRs->MoveNext();
	}

	///// Display of Type of Coals ///////////
	m_pRs->MoveFirst();

	while (!m_pRs->EndOfFile)
	{
		var = m_pRs->Fields->GetItem(_T("WF_START"))->Value;
		if (var.boolVal)
		{
			var = m_pRs->Fields->GetItem(_T("TPH_PV"))->Value;
			m_silo_discharge_rate = var.dblVal;


			if (m_silo_discharge_rate >= 20)  //For valid signal only
			{
				str = m_pRs->Fields->GetItem(_T("Coal_Type"))->Value;
				for (int check = 0; check < 10; check++) //Checking Coal Type is already available in Coal type array or not
				{
					if (Silo_Coal_Type[check] == str)
					{
						CoalTypeWise_discharge[check] = CoalTypeWise_discharge[check] + m_silo_discharge_rate;
					}						
				}

			}
		}

		m_pRs->MoveNext();
	}

	m_pRs->Close();


	///////////////Display of Blend % /////////////////////

	double total_discharge = 0;
	double blend_perct = 0;

	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	for (int check = 0; check < 10; check++) //Checking Coal Type is already available in Coal type array or not
		if (Silo_Coal_Type[check] != _T(""))
			if (CoalTypeWise_discharge[check] > 0)
				total_discharge = total_discharge + CoalTypeWise_discharge[check];

	
	dc.TextOut(pText.x + 15, pText.y, _T("Total Discharge  :"));
	str.Format(_T("%0.2f"), total_discharge);
	str = str + _T("  Ton / Hr.");
	dc.TextOut(pText.x + 300, pText.y, str);

	///////////////// Displaying Value of Y18 - Belt Weigher ///////////////////
	m_strConnection1 = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Analyzer_Db;Trusted=True;");
	m_strCmdText1 = _T("Select * from dbo.Y18_COMMON");
	m_pRs1.CreateInstance(_uuidof(Recordset));
	m_pRs1->CursorLocation = adUseServer;
	m_pRs1->Open((LPCTSTR)m_strCmdText1, (LPCTSTR)m_strConnection1, adOpenDynamic, adLockOptimistic, adCmdText);
	
	
	var = m_pRs1->Fields->GetItem(_T("Y18_TPH"))->Value;
	if (var.vt != VT_NULL)
	{
		dc.TextOut(pText.x + 600, pText.y, _T("Y18 Belt Weigher :"));
		
		m_val = var.dblVal;
		str.Format(_T("%0.2f"), m_val);
		str = str + _T("  Ton / Hr.");
		dc.TextOut(pText.x + 800, pText.y, str);
	}
	m_pRs1->Close();

	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;
	pText.y += nLineHeight;

	for (int check = 0; check < 10; check++) //Checking Coal Type is already available in Coal type array or not
	{
		if (Silo_Coal_Type[check] != _T(""))
		{
			str = Silo_Coal_Type[check];
			str = str + _T("   :");
			dc.TextOut(pText.x + 50, pText.y, str);

			if (CoalTypeWise_discharge[check] > 0)
			{
				str.Format(_T("%0.2f"), CoalTypeWise_discharge[check]);
				dc.TextOut(pText.x + 150, pText.y, str);

				blend_perct = CoalTypeWise_discharge[check] * 100 / total_discharge;
				str.Format(_T("%0.2f"), blend_perct);
				str = str + _T("  %");
				dc.TextOut(pText.x + 150, pText.y, str);
			}


			pText.y += nLineHeight;
			pText.y += nLineHeight;

		}

	}

}



void CBlendPercent::OnBnClickedRefresh1()
{
	// TODO: Add your control notification handler code here
	Invalidate(TRUE);
}
