// Setsilostock_2A_54a.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "Setsilostock_2A_54a.h"
#include "afxdialogex.h"


// Setsilostock_2A_54a dialog

IMPLEMENT_DYNAMIC(Setsilostock_2A_54a, CDialog)

Setsilostock_2A_54a::Setsilostock_2A_54a(CWnd* pParent /*=NULL*/)
	: CDialog(Setsilostock_2A_54a::IDD, pParent)
	, m_Silo_2A(0)
	, m_Silo_4A(0)
	, m_Silo_6A(0)
	, m_Silo_8A(0)
	, m_Silo_10A(0)
	, m_Silo_12A(0)
	, m_Silo_14A(0)
	, m_Silo_16A(0)
	, m_Silo_18A(0)
	, m_Silo_20A(0)
	, m_Silo_22A(0)
	, m_Silo_24A(0)
	, m_Silo_26A(0)
	, m_Silo_28A(0)
	, m_Silo_30A(0)
	, m_Silo_32A(0)
	, m_Silo_34A(0)
	, m_Silo_36A(0)
	, m_Silo_38A(0)
	, m_Silo_40A(0)
	, m_Silo_42A(0)
	, m_Silo_44A(0)
	, m_Silo_46A(0)
	, m_Silo_48A(0)
	, m_Silo_50A(0)
	, m_Silo_52A(0)
	, m_Silo_54A(0)
	, m_Silo_2A_Db(0)
	, m_Silo_4A_Db(0)
	, m_Silo_6A_Db(0)
	, m_Silo_8A_Db(0)
	, m_Silo_10A_Db(0)
	, m_Silo_12A_Db(0)
	, m_Silo_14A_Db(0)
	, m_Silo_16A_Db(0)
	, m_Silo_18A_Db(0)
	, m_Silo_20A_Db(0)
	, m_Silo_22A_Db(0)
	, m_Silo_24A_Db(0)
	, m_Silo_26A_Db(0)
	, m_Silo_28A_Db(0)
	, m_Silo_30A_Db(0)
	, m_Silo_32A_Db(0)
	, m_Silo_34A_Db(0)
	, m_Silo_36A_Db(0)
	, m_Silo_38A_Db(0)
	, m_Silo_40A_Db(0)
	, m_Silo_42A_Db(0)
	, m_Silo_44A_Db(0)
	, m_Silo_46A_Db(0)
	, m_Silo_48A_Db(0)
	, m_Silo_50A_Db(0)
	, m_Silo_52A_Db(0)
	, m_Silo_54A_Db(0)
{

}

Setsilostock_2A_54a::~Setsilostock_2A_54a()
{
}

void Setsilostock_2A_54a::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SET_S2A_EDIT, m_Silo_2A);
	DDV_MinMaxFloat(pDX, m_Silo_2A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S4A_EDIT, m_Silo_4A);
	DDV_MinMaxFloat(pDX, m_Silo_4A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S6A_EDIT, m_Silo_6A);
	DDV_MinMaxFloat(pDX, m_Silo_6A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S8A_EDIT, m_Silo_8A);
	DDV_MinMaxFloat(pDX, m_Silo_8A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S10A_EDIT, m_Silo_10A);
	DDV_MinMaxFloat(pDX, m_Silo_10A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S12A_EDIT, m_Silo_12A);
	DDV_MinMaxFloat(pDX, m_Silo_12A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S14A_EDIT, m_Silo_14A);
	DDV_MinMaxFloat(pDX, m_Silo_14A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S16A_EDIT, m_Silo_16A);
	DDV_MinMaxFloat(pDX, m_Silo_16A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S18A_EDIT, m_Silo_18A);
	DDV_MinMaxFloat(pDX, m_Silo_18A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S20A_EDIT, m_Silo_20A);
	DDV_MinMaxFloat(pDX, m_Silo_20A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S22A_EDIT, m_Silo_22A);
	DDV_MinMaxFloat(pDX, m_Silo_22A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S24A_EDIT, m_Silo_24A);
	DDV_MinMaxFloat(pDX, m_Silo_24A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S26A_EDIT, m_Silo_26A);
	DDV_MinMaxFloat(pDX, m_Silo_26A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S28A_EDIT, m_Silo_28A);
	DDV_MinMaxFloat(pDX, m_Silo_28A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S30A_EDIT, m_Silo_30A);
	DDV_MinMaxFloat(pDX, m_Silo_30A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S32A_EDIT, m_Silo_32A);
	DDV_MinMaxFloat(pDX, m_Silo_32A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S34A_EDIT, m_Silo_34A);
	DDV_MinMaxFloat(pDX, m_Silo_34A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S36A_EDIT, m_Silo_36A);
	DDV_MinMaxFloat(pDX, m_Silo_36A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S38A_EDIT, m_Silo_38A);
	DDV_MinMaxFloat(pDX, m_Silo_38A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S40A_EDIT, m_Silo_40A);
	DDV_MinMaxFloat(pDX, m_Silo_40A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S42A_EDIT, m_Silo_42A);
	DDV_MinMaxFloat(pDX, m_Silo_42A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S44A_EDIT, m_Silo_44A);
	DDV_MinMaxFloat(pDX, m_Silo_44A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S46A_EDIT, m_Silo_46A);
	DDV_MinMaxFloat(pDX, m_Silo_46A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S48A_EDIT, m_Silo_48A);
	DDV_MinMaxFloat(pDX, m_Silo_48A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S50A_EDIT, m_Silo_50A);
	DDV_MinMaxFloat(pDX, m_Silo_50A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S52A_EDIT, m_Silo_52A);
	DDV_MinMaxFloat(pDX, m_Silo_52A, 0, 2500);
	DDX_Text(pDX, IDC_SET_S54A_EDIT, m_Silo_54A);
	DDV_MinMaxFloat(pDX, m_Silo_54A, 0, 2500);	
	DDX_Text(pDX, IDC_ST_S2A_EDIT, m_Silo_2A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_2A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S4A_EDIT, m_Silo_4A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_4A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S6A_EDIT, m_Silo_6A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_6A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S8A_EDIT, m_Silo_8A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_8A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S10A_EDIT, m_Silo_10A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_10A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S12A_EDIT, m_Silo_12A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_12A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S14A_EDIT, m_Silo_14A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_14A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S16A_EDIT, m_Silo_16A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_16A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S18A_EDIT, m_Silo_18A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_18A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S20A_EDIT, m_Silo_20A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_20A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S22A_EDIT, m_Silo_22A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_22A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S24A_EDIT, m_Silo_24A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_24A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S26A_EDIT, m_Silo_26A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_26A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S28A_EDIT, m_Silo_28A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_28A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S30A_EDIT, m_Silo_30A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_30A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S32A_EDIT, m_Silo_32A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_32A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S34A_EDIT, m_Silo_34A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_34A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S36A_EDIT, m_Silo_36A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_36A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S38A_EDIT, m_Silo_38A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_38A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S40A_EDIT, m_Silo_40A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_40A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S42A_EDIT, m_Silo_42A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_42A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S44A_EDIT, m_Silo_44A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_44A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S46A_EDIT, m_Silo_46A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_46A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S48A_EDIT, m_Silo_48A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_48A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S50A_EDIT, m_Silo_50A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_50A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S52A_EDIT, m_Silo_52A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_52A_Db, 0, 2500);
	DDX_Text(pDX, IDC_ST_S54A_EDIT, m_Silo_54A_Db);
	DDV_MinMaxFloat(pDX, m_Silo_54A_Db, 0, 2500);	
}


BEGIN_MESSAGE_MAP(Setsilostock_2A_54a, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Setsilostock_2A_54a message handlers


void Setsilostock_2A_54a::OnPaint()
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

	m_pRs_WF->Move(54);		// move to the corresponding records

	m_Silo_2A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_4A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_6A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_8A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_10A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_12A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_14A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_16A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_18A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_20A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_22A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_24A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_26A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_28A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_30A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_32A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_34A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_36A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_38A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_40A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_42A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_44A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_46A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_48A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_50A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_52A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	m_Silo_54A_Db = m_pRs_WF->Fields->GetItem(_T("Silo_Stock"))->Value.dblVal;
	m_pRs_WF->MoveNext();

	UpdateData(false);

}
