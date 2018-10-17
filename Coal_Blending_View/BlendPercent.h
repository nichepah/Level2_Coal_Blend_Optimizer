#pragma once


// CBlendPercent dialog

class CBlendPercent : public CDialog
{
	DECLARE_DYNAMIC(CBlendPercent)

public:
	CBlendPercent(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBlendPercent();
	

// Dialog Data
	enum { IDD = IDD_BLEND_PERCT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	
	afx_msg void OnBnClickedRefresh1();
};
