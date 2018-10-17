#pragma once


// Setsilostock_2A_54a dialog

class Setsilostock_2A_54a : public CDialog
{
	DECLARE_DYNAMIC(Setsilostock_2A_54a)

public:
	Setsilostock_2A_54a(CWnd* pParent = NULL);   // standard constructor
	virtual ~Setsilostock_2A_54a();

// Dialog Data
	enum { IDD = IDD_SET_COAL_STOCK_2A_54A_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float m_Silo_2A;
	float m_Silo_4A;
	float m_Silo_6A;
	float m_Silo_8A;
	float m_Silo_10A;
	float m_Silo_12A;
	float m_Silo_14A;
	float m_Silo_16A;
	float m_Silo_18A;
	float m_Silo_20A;
	float m_Silo_22A;
	float m_Silo_24A;
	float m_Silo_26A;
	float m_Silo_28A;
	float m_Silo_30A;
	float m_Silo_32A;
	float m_Silo_34A;
	float m_Silo_36A;
	float m_Silo_38A;
	float m_Silo_40A;
	float m_Silo_42A;
	float m_Silo_44A;
	float m_Silo_46A;
	float m_Silo_48A;
	float m_Silo_50A;
	float m_Silo_52A;
	float m_Silo_54A;
	float m_Silo_2A_Db;
	float m_Silo_4A_Db;
	float m_Silo_6A_Db;
	float m_Silo_8A_Db;
	float m_Silo_10A_Db;
	float m_Silo_12A_Db;
	float m_Silo_14A_Db;
	float m_Silo_16A_Db;
	float m_Silo_18A_Db;
	float m_Silo_20A_Db;
	float m_Silo_22A_Db;
	float m_Silo_24A_Db;
	float m_Silo_26A_Db;
	float m_Silo_28A_Db;
	float m_Silo_30A_Db;
	float m_Silo_32A_Db;
	float m_Silo_34A_Db;
	float m_Silo_36A_Db;
	float m_Silo_38A_Db;
	float m_Silo_40A_Db;
	float m_Silo_42A_Db;
	float m_Silo_44A_Db;
	float m_Silo_46A_Db;
	float m_Silo_48A_Db;
	float m_Silo_50A_Db;
	float m_Silo_52A_Db;
	float m_Silo_54A_Db;	
	afx_msg void OnPaint();
};
