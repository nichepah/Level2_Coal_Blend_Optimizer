#pragma once


// CCoalSiloSource dialog

class CCoalSiloSource : public CDialog
{
	DECLARE_DYNAMIC(CCoalSiloSource)

public:
	CCoalSiloSource(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCoalSiloSource();

// Dialog Data
	enum { IDD = IDD_COAL_SILO_SOURCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChangesource();
	
};
