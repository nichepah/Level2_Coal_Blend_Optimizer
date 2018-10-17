#pragma once


// CSetSiloStock_02_54 dialog

class CSetSiloStock_02_54 : public CDialog
{
	DECLARE_DYNAMIC(CSetSiloStock_02_54)

public:
	CSetSiloStock_02_54(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSetSiloStock_02_54();

// Dialog Data
	enum { IDD = IDD_SET_COAL_STOCK_2_54_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float m_Silo_2;
	float m_Silo_4;
	float m_Silo_6;
	float m_Silo_8;
	float m_Silo_10;
	float m_Silo_12;
	float m_Silo_14;
	float m_Silo_16;
	float m_Silo_18;
	float m_Silo_20;
	float m_Silo_22;
	float m_Silo_24;
	float m_Silo_26;
	float m_Silo_28;
	float m_Silo_30;
	float m_Silo_32;
	float m_Silo_34;
	float m_Silo_36;
	float m_Silo_38;
	float m_Silo_40;
	float m_Silo_42;
	float m_Silo_44;
	float m_Silo_46;
	float m_Silo_48;
	float m_Silo_50;
	float m_Silo_52;
	float m_Silo_54;
	float m_Silo_2_Db;
	float m_Silo_4_Db;
	float m_Silo_6_Db;
	float m_Silo_8_Db;
	float m_Silo_10_Db;
	float m_Silo_12_Db;
	float m_Silo_14_Db;
	float m_Silo_16_Db;
	float m_Silo_18_Db;
	float m_Silo_20_Db;
	float m_Silo_22_Db;
	float m_Silo_24_Db;
	float m_Silo_26_Db;
	float m_Silo_28_Db;
	float m_Silo_30_Db;
	float m_Silo_32_Db;
	float m_Silo_34_Db;
	float m_Silo_36_Db;
	float m_Silo_38_Db;
	float m_Silo_40_Db;
	float m_Silo_42_Db;
	float m_Silo_44_Db;
	float m_Silo_46_Db;
	float m_Silo_48_Db;
	float m_Silo_50_Db;
	float m_Silo_52_Db;
	float m_Silo_54_Db;
	afx_msg void OnPaint();
};
