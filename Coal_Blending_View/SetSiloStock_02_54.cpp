// SetSiloStock_02_54.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "SetSiloStock_02_54.h"
#include "afxdialogex.h"


// CSetSiloStock_02_54 dialog

IMPLEMENT_DYNAMIC(CSetSiloStock_02_54, CDialog)

CSetSiloStock_02_54::CSetSiloStock_02_54(CWnd* pParent /*=NULL*/)
	: CDialog(CSetSiloStock_02_54::IDD, pParent)
	, m_Silo_2(0)
	, m_Silo_4(0)
	, m_Silo_6(0)
	, m_Silo_8(0)
	, m_Silo_10(0)
	, m_Silo_12(0)
	, m_Silo_14(0)
	, m_Silo_16(0)
	, m_Silo_18(0)
	, m_Silo_20(0)
	, m_Silo_22(0)
	, m_Silo_24(0)
	, m_Silo_26(0)
	, m_Silo_28(0)
	, m_Silo_30(0)
	, m_Silo_32(0)
	, m_Silo_34(0)
	, m_Silo_36(0)
	, m_Silo_38(0)
	, m_Silo_40(0)
	, m_Silo_42(0)
	, m_Silo_44(0)
	, m_Silo_46(0)
	, m_Silo_48(0)
	, m_Silo_50(0)
	, m_Silo_52(0)
	, m_Silo_54(0)
	, m_Silo_2_Db(0)
	, m_Silo_4_Db(0)
	, m_Silo_6_Db(0)
	, m_Silo_8_Db(0)
	, m_Silo_10_Db(0)
	, m_Silo_12_Db(0)
	, m_Silo_14_Db(0)
	, m_Silo_16_Db(0)
	, m_Silo_18_Db(0)
	, m_Silo_20_Db(0)
	, m_Silo_22_Db(0)
	, m_Silo_24_Db(0)
	, m_Silo_26_Db(0)
	, m_Silo_28_Db(0)
	, m_Silo_30_Db(0)
	, m_Silo_32_Db(0)
	, m_Silo_34_Db(0)
	, m_Silo_36_Db(0)
	, m_Silo_38_Db(0)
	, m_Silo_40_Db(0)
	, m_Silo_42_Db(0)
	, m_Silo_44_Db(0)
	, m_Silo_46_Db(0)
	, m_Silo_48_Db(0)
	, m_Silo_50_Db(0)
	, m_Silo_52_Db(0)
	, m_Silo_54_Db(0)
{

}

CSetSiloStock_02_54::~CSetSiloStock_02_54()
{
}

void CSetSiloStock_02_54::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SET_S2_EDIT, m_Silo_2);
	DDV_MinMaxFloat(pDX, m_Silo_2, 0, 2500);
	DDX_Text(pDX, IDC_SET_S4_EDIT, m_Silo_4);
	DDV_MinMaxFloat(pDX, m_Silo_4, 0, 2500);
	DDX_Text(pDX, IDC_SET_S6_EDIT, m_Silo_6);
	DDV_MinMaxFloat(pDX, m_Silo_6, 0, 2500);
	DDX_Text(pDX, IDC_SET_S8_EDIT, m_Silo_8);
	DDV_MinMaxFloat(pDX, m_Silo_8, 0, 2500);
	DDX_Text(pDX, IDC_SET_S10_EDIT, m_Silo_10);
	DDV_MinMaxFloat(pDX, m_Silo_10, 0, 2500);
	DDX_Text(pDX, IDC_SET_S12_EDIT, m_Silo_12);
	DDV_MinMaxFloat(pDX, m_Silo_12, 0, 2500);
	DDX_Text(pDX, IDC_SET_S14_EDIT, m_Silo_14);
	DDV_MinMaxFloat(pDX, m_Silo_14, 0, 2500);
	DDX_Text(pDX, IDC_SET_S16_EDIT, m_Silo_16);
	DDV_MinMaxFloat(pDX, m_Silo_16, 0, 2500);
	DDX_Text(pDX, IDC_SET_S18_EDIT, m_Silo_18);
	DDV_MinMaxFloat(pDX, m_Silo_18, 0, 2500);
	DDX_Text(pDX, IDC_SET_S20_EDIT, m_Silo_20);
	DDV_MinMaxFloat(pDX, m_Silo_20, 0, 2500);
	DDX_Text(pDX, IDC_SET_S22_EDIT, m_Silo_22);
	DDV_MinMaxFloat(pDX, m_Silo_22, 0, 2500);
	DDX_Text(pDX, IDC_SET_S24_EDIT, m_Silo_24);
	DDV_MinMaxFloat(pDX, m_Silo_24, 0, 2500);
	DDX_Text(pDX, IDC_SET_S26_EDIT, m_Silo_26);
	DDV_MinMaxFloat(pDX, m_Silo_26, 0, 2500);
	DDX_Text(pDX, IDC_SET_S28_EDIT, m_Silo_28);
	DDV_MinMaxFloat(pDX, m_Silo_28, 0, 2500);
	DDX_Text(pDX, IDC_SET_S30_EDIT, m_Silo_30);
	DDV_MinMaxFloat(pDX, m_Silo_30, 0, 2500);
	DDX_Text(pDX, IDC_SET_S32_EDIT, m_Silo_32);
	DDV_MinMaxFloat(pDX, m_Silo_32, 0, 2500);
	DDX_Text(pDX, IDC_SET_S34_EDIT, m_Silo_34);
	DDV_MinMaxFloat(pDX, m_Silo_34, 0, 2500);
	DDX_Text(pDX, IDC_SET_S36_EDIT, m_Silo_36);
	DDV_MinMaxFloat(pDX, m_Silo_36, 0, 2500);
	DDX_Text(pDX, IDC_SET_S38_EDIT, m_Silo_38);
	DDV_MinMaxFloat(pDX, m_Silo_38, 0, 2500);
	DDX_Text(pDX, IDC_SET_S40_EDIT, m_Silo_40);
	DDV_MinMaxFloat(pDX, m_Silo_40, 0, 2500);
	DDX_Text(pDX, IDC_SET_S42_EDIT, m_Silo_42);
	DDV_MinMaxFloat(pDX, m_Silo_42, 0, 2500);
	DDX_Text(pDX, IDC_SET_S44_EDIT, m_Silo_44);
	DDV_MinMaxFloat(pDX, m_Silo_44, 0, 2500);
	DDX_Text(pDX, IDC_SET_S46_EDIT, m_Silo_46);
	DDV_MinMaxFloat(pDX, m_Silo_46, 0, 2500);
	DDX_Text(pDX, IDC_SET_S48_EDIT, m_Silo_48);
	DDV_MinMaxFloat(pDX, m_Silo_48, 0, 2500);
	DDX_Text(pDX, IDC_SET_S50_EDIT, m_Silo_50);
	DDV_MinMaxFloat(pDX, m_Silo_50, 0, 2500);
	DDX_Text(pDX, IDC_SET_S52_EDIT, m_Silo_52);
	DDV_MinMaxFloat(pDX, m_Silo_52, 0, 2500);
	DDX_Text(pDX, IDC_SET_S54_EDIT, m_Silo_54);
	DDV_MinMaxFloat(pDX, m_Silo_54, 0, 2500);
	DDX_Text(pDX, IDC_ST_S2_EDIT, m_Silo_2_Db);
	DDV_MinMaxFloat(pDX, m_Silo_2_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S4_EDIT, m_Silo_4_Db);
	DDV_MinMaxFloat(pDX, m_Silo_4_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S6_EDIT, m_Silo_6_Db);
	DDV_MinMaxFloat(pDX, m_Silo_6_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S8_EDIT, m_Silo_8_Db);
	DDV_MinMaxFloat(pDX, m_Silo_8_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S10_EDIT, m_Silo_10_Db);
	DDV_MinMaxFloat(pDX, m_Silo_10_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S12_EDIT, m_Silo_12_Db);
	DDV_MinMaxFloat(pDX, m_Silo_12_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S14_EDIT, m_Silo_14_Db);
	DDV_MinMaxFloat(pDX, m_Silo_14_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S16_EDIT, m_Silo_16_Db);
	DDV_MinMaxFloat(pDX, m_Silo_16_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S18_EDIT, m_Silo_18_Db);
	DDV_MinMaxFloat(pDX, m_Silo_18_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S20_EDIT, m_Silo_20_Db);
	DDV_MinMaxFloat(pDX, m_Silo_20_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S22_EDIT, m_Silo_22_Db);
	DDV_MinMaxFloat(pDX, m_Silo_22_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S24_EDIT, m_Silo_24_Db);
	DDV_MinMaxFloat(pDX, m_Silo_24_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S26_EDIT, m_Silo_26_Db);
	DDV_MinMaxFloat(pDX, m_Silo_26_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S28_EDIT, m_Silo_28_Db);
	DDV_MinMaxFloat(pDX, m_Silo_28_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S30_EDIT, m_Silo_30_Db);
	DDV_MinMaxFloat(pDX, m_Silo_30_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S32_EDIT, m_Silo_32_Db);
	DDV_MinMaxFloat(pDX, m_Silo_32_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S34_EDIT, m_Silo_34_Db);
	DDV_MinMaxFloat(pDX, m_Silo_34_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S36_EDIT, m_Silo_36_Db);
	DDV_MinMaxFloat(pDX, m_Silo_36_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S38_EDIT, m_Silo_38_Db);
	DDV_MinMaxFloat(pDX, m_Silo_38_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S40_EDIT, m_Silo_40_Db);
	DDV_MinMaxFloat(pDX, m_Silo_40_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S42_EDIT, m_Silo_42_Db);
	DDV_MinMaxFloat(pDX, m_Silo_42_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S44_EDIT, m_Silo_44_Db);
	DDV_MinMaxFloat(pDX, m_Silo_44_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S46_EDIT, m_Silo_46_Db);
	DDV_MinMaxFloat(pDX, m_Silo_46_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S48_EDIT, m_Silo_48_Db);
	DDV_MinMaxFloat(pDX, m_Silo_48_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S50_EDIT, m_Silo_50_Db);
	DDV_MinMaxFloat(pDX, m_Silo_50_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S52_EDIT, m_Silo_52_Db);
	DDV_MinMaxFloat(pDX, m_Silo_52_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S54_EDIT, m_Silo_54_Db);
	DDV_MinMaxFloat(pDX, m_Silo_54_Db, 0, 2500);
}


BEGIN_MESSAGE_MAP(CSetSiloStock_02_54, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSetSiloStock_02_54 message handlers


void CSetSiloStock_02_54::OnPaint()
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

	m_pRs_WF->Move(27);		// move to the corresponding records

	m_Silo_2_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_4_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_6_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_8_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_10_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_12_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_14_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_16_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_18_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_20_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_22_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_24_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_26_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_28_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_30_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_32_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_34_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_36_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_38_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_40_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_42_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_44_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_46_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_48_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_50_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_52_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_54_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	UpdateData(false);
}
