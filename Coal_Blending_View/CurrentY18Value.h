#pragma once


// CCurrentY18Value dialog

class CCurrentY18Value : public CDialog
{
	DECLARE_DYNAMIC(CCurrentY18Value)

public:
	CCurrentY18Value(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCurrentY18Value();

// Dialog Data
	enum { IDD = IDD_Y18_CURRENT_VALUE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
