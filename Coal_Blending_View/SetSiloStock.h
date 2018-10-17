#pragma once


// CSetSiloStock dialog

class CSetSiloStock : public CDialog
{
	DECLARE_DYNAMIC(CSetSiloStock)

public:
	CSetSiloStock(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSetSiloStock();

// Dialog Data
	enum { IDD = IDD_SET_COAL_STOCK_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	float m_Silo_1;
	float m_Silo_3;
	float m_Silo_5;
	float m_Silo_7;
	float m_Silo_9;
	float m_Silo_11;
	float m_Silo_13;
	float m_Silo_15;
	float m_Silo_17;
	float m_Silo_19;
	float m_Silo_21;
	float m_Silo_23;
	float m_Silo_25;
	float m_Silo_27;
	float m_Silo_29;
	float m_Silo_31;
	float m_Silo_33;
	float m_Silo_35;
	float m_Silo_37;
	float m_Silo_39;
	float m_Silo_41;
	float m_Silo_43;
	float m_Silo_45;
	float m_Silo_47;
	float m_Silo_49;
	float m_Silo_51;
	float m_Silo_53;
	float m_Silo_1_Db;
	float m_Silo_3_Db;
	float m_Silo_5_Db;
	float m_Silo_7_Db;
	float m_Silo_9_Db;
	float m_Silo_11_Db;
	float m_Silo_13_Db;
	float m_Silo_15_Db;
	float m_Silo_17_Db;
	float m_Silo_19_Db;
	float m_Silo_21_Db;
	float m_Silo_23_Db;
	float m_Silo_25_Db;
	float m_Silo_27_Db;
	float m_Silo_29_Db;
	float m_Silo_31_Db;
	float m_Silo_33_Db;
	float m_Silo_35_Db;
	float m_Silo_37_Db;
	float m_Silo_39_Db;
	float m_Silo_41_Db;
	float m_Silo_43_Db;
	float m_Silo_45_Db;
	float m_Silo_47_Db;
	float m_Silo_49_Db;
	float m_Silo_51_Db;
	float m_Silo_53_Db;

	CString m_strConnection, m_strCmdText;
	_RecordsetPtr  m_pRs;
	

	afx_msg void OnBnClickedS1Button();
};
