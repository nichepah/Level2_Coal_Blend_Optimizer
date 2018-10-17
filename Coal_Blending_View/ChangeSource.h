#pragma once
#include "afxwin.h"
#include "opccomn.h"
#include "opcda.h"

// CChangeSource dialog

class CChangeSource : public CDialog
{
	DECLARE_DYNAMIC(CChangeSource)

public:
	CChangeSource(CWnd* pParent = NULL);   // standard constructor
	virtual ~CChangeSource();

// Dialog Data
	enum { IDD = IDD_CHANGE_SOURCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	CComboBox m_SiloNumber;
	CComboBox m_CoalSource;
	afx_msg void OnCbnDropdownCombo1();

	CString m_strConnection, m_strCmdText;
	_RecordsetPtr m_pRs;
	HRESULT CreateOPCLink(void);
	HRESULT Create_PLC_OPC_Server(void);
	HRESULT AddOPCGroup(void);
	HRESULT AddOPCItems(void);
	HRESULT Read_FS_PLC_Data(void);
	HRESULT Write_FS_PLC_Data(int, CString);

	CString GetSourceString(OPCITEMSTATE);
	SAFEARRAY* PutSourceString(CString);

	afx_msg void OnCbnDropdownCombo2();
	afx_msg void OnBnClickedButton1();
};
