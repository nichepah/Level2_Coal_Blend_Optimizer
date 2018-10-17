// SetSiloStock.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "SetSiloStock.h"
#include "afxdialogex.h"


// CSetSiloStock dialog

IMPLEMENT_DYNAMIC(CSetSiloStock, CDialog)

CSetSiloStock::CSetSiloStock(CWnd* pParent /*=NULL*/)
	: CDialog(CSetSiloStock::IDD, pParent)
	, m_Silo_1(0)
	, m_Silo_3(0)
	, m_Silo_5(0)
	, m_Silo_7(0)
	, m_Silo_9(0)
	, m_Silo_11(0)
	, m_Silo_13(0)
	, m_Silo_15(0)
	, m_Silo_17(0)
	, m_Silo_19(0)
	, m_Silo_21(0)
	, m_Silo_23(0)
	, m_Silo_25(0)
	, m_Silo_27(0)
	, m_Silo_29(0)
	, m_Silo_31(0)
	, m_Silo_33(0)
	, m_Silo_35(0)
	, m_Silo_37(0)
	, m_Silo_39(0)
	, m_Silo_41(0)
	, m_Silo_43(0)
	, m_Silo_45(0)
	, m_Silo_47(0)
	, m_Silo_49(0)
	, m_Silo_51(0)
	, m_Silo_53(0)
	, m_Silo_1_Db(0)
	, m_Silo_3_Db(0)
	, m_Silo_5_Db(0)
	, m_Silo_7_Db(0)
	, m_Silo_9_Db(0)
	, m_Silo_11_Db(0)
	, m_Silo_13_Db(0)
	, m_Silo_15_Db(0)
	, m_Silo_17_Db(0)
	, m_Silo_19_Db(0)
	, m_Silo_21_Db(0)
	, m_Silo_23_Db(0)
	, m_Silo_25_Db(0)
	, m_Silo_27_Db(0)
	, m_Silo_29_Db(0)
	, m_Silo_31_Db(0)
	, m_Silo_33_Db(0)
	, m_Silo_35_Db(0)
	, m_Silo_37_Db(0)
	, m_Silo_39_Db(0)
	, m_Silo_41_Db(0)
	, m_Silo_43_Db(0)
	, m_Silo_45_Db(0)
	, m_Silo_47_Db(0)
	, m_Silo_49_Db(0)
	, m_Silo_51_Db(0)
	, m_Silo_53_Db(0)
{
	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText= _T("Select * from dbo.Silo_Details ORDER BY Si_No ASC ");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);

}

CSetSiloStock::~CSetSiloStock()
{
	m_pRs->Close();
}

void CSetSiloStock::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SET_S1_EDIT, m_Silo_1);
	DDV_MinMaxFloat(pDX, m_Silo_1, 0, 2500);
	DDX_Text(pDX, IDC_SET_S3_EDIT, m_Silo_3);
	DDV_MinMaxFloat(pDX, m_Silo_3, 0, 2500);
	DDX_Text(pDX, IDC_SET_S5_EDIT, m_Silo_5);
	DDV_MinMaxFloat(pDX, m_Silo_5, 0, 2500);
	DDX_Text(pDX, IDC_SET_S7_EDIT, m_Silo_7);
	DDV_MinMaxFloat(pDX, m_Silo_7, 0, 2500);
	DDX_Text(pDX, IDC_SET_S9_EDIT, m_Silo_9);
	DDV_MinMaxFloat(pDX, m_Silo_9, 0, 2500);
	DDX_Text(pDX, IDC_SET_S11_EDIT, m_Silo_11);
	DDV_MinMaxFloat(pDX, m_Silo_11, 0, 2500);
	DDX_Text(pDX, IDC_SET_S13_EDIT, m_Silo_13);
	DDV_MinMaxFloat(pDX, m_Silo_13, 0, 2500);
	DDX_Text(pDX, IDC_SET_S15_EDIT, m_Silo_15);
	DDV_MinMaxFloat(pDX, m_Silo_15, 0, 2500);
	DDX_Text(pDX, IDC_SET_S17_EDIT, m_Silo_17);
	DDV_MinMaxFloat(pDX, m_Silo_17, 0, 2500);
	DDX_Text(pDX, IDC_SET_S19_EDIT, m_Silo_19);
	DDV_MinMaxFloat(pDX, m_Silo_19, 0, 2500);
	DDX_Text(pDX, IDC_SET_S21_EDIT, m_Silo_21);
	DDV_MinMaxFloat(pDX, m_Silo_21, 0, 2500);
	DDX_Text(pDX, IDC_SET_S23_EDIT, m_Silo_23);
	DDV_MinMaxFloat(pDX, m_Silo_23, 0, 2500);
	DDX_Text(pDX, IDC_SET_S25_EDIT, m_Silo_25);
	DDV_MinMaxFloat(pDX, m_Silo_25, 0, 2500);
	DDX_Text(pDX, IDC_SET_S27_EDIT, m_Silo_27);
	DDV_MinMaxFloat(pDX, m_Silo_27, 0, 2500);
	DDX_Text(pDX, IDC_SET_S29_EDIT, m_Silo_29);
	DDV_MinMaxFloat(pDX, m_Silo_29, 0, 2500);
	DDX_Text(pDX, IDC_SET_S31_EDIT, m_Silo_31);
	DDV_MinMaxFloat(pDX, m_Silo_31, 0, 2500);
	DDX_Text(pDX, IDC_SET_S33_EDIT, m_Silo_33);
	DDV_MinMaxFloat(pDX, m_Silo_33, 0, 2500);
	DDX_Text(pDX, IDC_SET_S35_EDIT, m_Silo_35);
	DDV_MinMaxFloat(pDX, m_Silo_35, 0, 2500);
	DDX_Text(pDX, IDC_SET_S37_EDIT, m_Silo_37);
	DDV_MinMaxFloat(pDX, m_Silo_37, 0, 2500);
	DDX_Text(pDX, IDC_SET_S39_EDIT, m_Silo_39);
	DDV_MinMaxFloat(pDX, m_Silo_39, 0, 2500);
	DDX_Text(pDX, IDC_SET_S41_EDIT, m_Silo_41);
	DDV_MinMaxFloat(pDX, m_Silo_41, 0, 2500);
	DDX_Text(pDX, IDC_SET_S43_EDIT, m_Silo_43);
	DDV_MinMaxFloat(pDX, m_Silo_43, 0, 2500);
	DDX_Text(pDX, IDC_SET_S45_EDIT, m_Silo_45);
	DDV_MinMaxFloat(pDX, m_Silo_45, 0, 2500);
	DDX_Text(pDX, IDC_SET_S47_EDIT, m_Silo_47);
	DDV_MinMaxFloat(pDX, m_Silo_47, 0, 2500);
	DDX_Text(pDX, IDC_SET_S49_EDIT, m_Silo_49);
	DDV_MinMaxFloat(pDX, m_Silo_49, 0, 2500);
	DDX_Text(pDX, IDC_SET_S51_EDIT, m_Silo_51);
	DDV_MinMaxFloat(pDX, m_Silo_51, 0, 2500);
	DDX_Text(pDX, IDC_SET_S53_EDIT, m_Silo_53);
	DDV_MinMaxFloat(pDX, m_Silo_53, 0, 2500);
	DDX_Text(pDX, IDC_ST_S1_EDIT, m_Silo_1_Db);
	DDV_MinMaxFloat(pDX, m_Silo_1_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S3_EDIT, m_Silo_3_Db);
	DDV_MinMaxFloat(pDX, m_Silo_3_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S5_EDIT, m_Silo_5_Db);
	DDV_MinMaxFloat(pDX, m_Silo_5_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S7_EDIT, m_Silo_7_Db);
	DDV_MinMaxFloat(pDX, m_Silo_7_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S9_EDIT, m_Silo_9_Db);
	DDV_MinMaxFloat(pDX, m_Silo_9_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S11_EDIT, m_Silo_11_Db);
	DDV_MinMaxFloat(pDX, m_Silo_11_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S13_EDIT, m_Silo_13_Db);
	DDV_MinMaxFloat(pDX, m_Silo_13_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S15_EDIT, m_Silo_15_Db);
	DDV_MinMaxFloat(pDX, m_Silo_15_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S17_EDIT, m_Silo_17_Db);
	DDV_MinMaxFloat(pDX, m_Silo_17_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S19_EDIT, m_Silo_19_Db);
	DDV_MinMaxFloat(pDX, m_Silo_19_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S21_EDIT, m_Silo_21_Db);
	DDV_MinMaxFloat(pDX, m_Silo_21_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S23_EDIT, m_Silo_23_Db);
	DDV_MinMaxFloat(pDX, m_Silo_23_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S25_EDIT, m_Silo_25_Db);
	DDV_MinMaxFloat(pDX, m_Silo_25_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S27_EDIT, m_Silo_27_Db);
	DDV_MinMaxFloat(pDX, m_Silo_27_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S29_EDIT, m_Silo_29_Db);
	DDV_MinMaxFloat(pDX, m_Silo_29_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S31_EDIT, m_Silo_31_Db);
	DDV_MinMaxFloat(pDX, m_Silo_31_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S33_EDIT, m_Silo_33_Db);
	DDV_MinMaxFloat(pDX, m_Silo_33_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S35_EDIT, m_Silo_35_Db);
	DDV_MinMaxFloat(pDX, m_Silo_35_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S37_EDIT, m_Silo_37_Db);
	DDV_MinMaxFloat(pDX, m_Silo_37_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S39_EDIT, m_Silo_39_Db);
	DDV_MinMaxFloat(pDX, m_Silo_39_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S41_EDIT, m_Silo_41_Db);
	DDV_MinMaxFloat(pDX, m_Silo_41_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S43_EDIT, m_Silo_43_Db);
	DDV_MinMaxFloat(pDX, m_Silo_43_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S45_EDIT, m_Silo_45_Db);
	DDV_MinMaxFloat(pDX, m_Silo_45_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S47_EDIT, m_Silo_47_Db);
	DDV_MinMaxFloat(pDX, m_Silo_47_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S49_EDIT, m_Silo_49_Db);
	DDV_MinMaxFloat(pDX, m_Silo_49_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S51_EDIT, m_Silo_51_Db);
	DDV_MinMaxFloat(pDX, m_Silo_51_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S53_EDIT, m_Silo_53_Db);
	DDV_MinMaxFloat(pDX, m_Silo_53_Db, 0, 2500);
}


BEGIN_MESSAGE_MAP(CSetSiloStock, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_S1_BUTTON, &CSetSiloStock::OnBnClickedS1Button)
END_MESSAGE_MAP()


// CSetSiloStock message handlers


void CSetSiloStock::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	CString m_strConnection_WF, m_strCmdText_WF;
	_RecordsetPtr m_pRs_WF;
	_variant_t var;
	double m_siloStock;
	
	m_strConnection_WF = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText_WF = _T("Select * from dbo.Silo_Details ORDER BY Si_No ASC ");
	m_pRs_WF.CreateInstance(_uuidof(Recordset));
	m_pRs_WF->CursorLocation = adUseServer;
	m_pRs_WF->Open((LPCTSTR)m_strCmdText_WF, (LPCTSTR)m_strConnection_WF, adOpenDynamic, adLockOptimistic, adCmdText);

	m_Silo_1_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_3_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_5_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_7_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_9_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_11_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_13_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_15_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_17_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_19_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_21_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_23_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_25_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_27_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_29_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_31_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_33_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_35_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_37_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_39_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_41_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_43_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_45_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_47_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_49_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_51_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_53_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	UpdateData(false);
	m_pRs_WF->Close();

}


BOOL CSetSiloStock::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	//cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW, NULL, (HBRUSH)(::CreateSolidBrush(RGB(255, 255, 255))), NULL);
	return CDialog::PreCreateWindow(cs);
}


void CSetSiloStock::OnBnClickedS1Button()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_pRs->MoveFirst();

	int i = MessageBox(_T("Are you sure to save the data"), _T("Warning 1"), MB_YESNO + MB_ICONWARNING);

	if (i == IDYES)
	{
		if ((m_Silo_1 >= 0) && (m_Silo_1 <= 2500))
			m_pRs->Update(("Silo_Stock"), (_variant_t)m_Silo_1);
		else
		{
			m_Silo_1 = 0;
			MessageBox(_T("Please enter a value between 0 and 2500 Ton"), _T("Warning 1"), MB_OK);
		}
	}
	

	UpdateData(FALSE);
	Invalidate(FALSE);
}
