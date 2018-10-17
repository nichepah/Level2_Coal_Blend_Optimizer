// ChangeSource.cpp : implementation file
//

#include "stdafx.h"
#include "Coal_Blending_View.h"
#include "ChangeSource.h"
#include"CoalSiloSource.h"
#include "TagDefinition.h"
#include <comdef.h>
#include "afxdialogex.h"
#include <atlsafe.h>


extern "C"
{
	const IID IID_IOPCServer = { 0x39c13a4d, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCServerPublicGroups = { 0x39c13a4e, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCBrowseServerAddressSpace = { 0x39c13a4f, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCGroupStateMgt = { 0x39c13a50, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCPublicGroupStateMgt = { 0x39c13a51, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCSyncIO = { 0x39c13a52, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCAsyncIO2 = { 0x39c13a71, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCItemMgt = { 0x39c13a54, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IEnumOPCItemAttributes = { 0x39c13a55, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
	const IID IID_IOPCDataCallback = { 0x39c13a70, 0x011e, 0x11d0, { 0x96, 0x75, 0x00, 0x20, 0xaf, 0xd8, 0xad, 0xb3 } };
}

int dwCount_Read = no_of_tags_coal_mine_read_FS;

IUnknown* lpUnknown = NULL;
IOPCServer* m_opcserver = NULL;
IUnknown* pUnkGrp = NULL;

IOPCAsyncIO2* pOPCAsyncIO2 = NULL;
IOPCItemMgt* pOPCItemMgt = NULL;
OPCITEMDEF		*ItemArray = NULL;
OPCHANDLE *ItemHandles = (OPCHANDLE*)CoTaskMemAlloc(dwCount_Read*sizeof(OPCHANDLE));
OPCITEMRESULT	*AddResults;
IOPCSyncIO	 *pOPCSyncIO_PLC = NULL;

// CChangeSource dialog

IMPLEMENT_DYNAMIC(CChangeSource, CDialog)

CChangeSource::CChangeSource(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeSource::IDD, pParent)
{

}

CChangeSource::~CChangeSource()
{
}

void CChangeSource::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_SiloNumber);
	DDX_Control(pDX, IDC_COMBO2, m_CoalSource);
}


BEGIN_MESSAGE_MAP(CChangeSource, CDialog)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CChangeSource::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CChangeSource::OnCbnDropdownCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CChangeSource::OnBnClickedButton1)
END_MESSAGE_MAP()


// CChangeSource message handlers
BOOL CChangeSource::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_SiloNumber.ResetContent();
	m_CoalSource.ResetContent();
	
	HRESULT hr;
	hr = CreateOPCLink();
	
	return TRUE;

}


void CChangeSource::OnCbnDropdownCombo1()
{
	// TODO: Add your control notification handler code here
	CString str;
	int m_index = 0;


	::CoInitialize(NULL);
	_variant_t var;

	//m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\BLENDING_SOFTWARE\\SiloDetails.mdb;Mode=Read;");
	//m_strCmdText = _T("Select * from SiloDetails ORDER BY SiloDetails.SiNo ASC");

	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText = _T("Select * from dbo.Silo_Details ORDER BY Si_No ASC ");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);

	while (!m_pRs->EndOfFile)
	{
		str = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
		m_SiloNumber.InsertString(m_index, str);
		m_index++;
		m_pRs->MoveNext();
	};
	m_pRs->Close();
}


void CChangeSource::OnCbnDropdownCombo2()
{
	// TODO: Add your control notification handler code here
	CString str;
	int m_index = 0;


	::CoInitialize(NULL);
	_variant_t var;

	//m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\BLENDING_SOFTWARE\\SiloDetails.mdb;Mode=Read;");
	//m_strCmdText = _T("Select * from CoalTypes");

	m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
	m_strCmdText = _T("Select * from dbo.CoalTypes");
	m_pRs.CreateInstance(_uuidof(Recordset));
	m_pRs->CursorLocation = adUseServer;
	m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);

	while (!m_pRs->EndOfFile)
	{
		str = m_pRs->Fields->GetItem(_T("CoalType"))->Value;
		m_CoalSource.InsertString(m_index, str);
		m_index++;
		m_pRs->MoveNext();
	};
	m_pRs->Close();
}


void CChangeSource::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	::CoInitialize(NULL);

	CString str1 = _T("");
	CString str2 = _T("");

	if (m_SiloNumber.GetCurSel() != CB_ERR)
		m_SiloNumber.GetLBText(m_SiloNumber.GetCurSel(), str1);

	if (m_CoalSource.GetCurSel() != CB_ERR)
		m_CoalSource.GetLBText(m_CoalSource.GetCurSel(), str2);

	if ((str1 != _T("")) && ((str2 != _T(""))))
	{
		int i = MessageBox(_T("Are you sure to save the data"), _T("Warning 1"), MB_YESNO + MB_ICONWARNING);

		if (i == IDYES)
		{

			int m_index;
			CString str;
			int index = 0;
			HRESULT hr;

			_variant_t var;
			m_index = 0;
			//m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\BLENDING_SOFTWARE\\SiloDetails.mdb;Mode=Write|ReadWrite|Read;");
			//m_strCmdText = _T("Select * from SiloDetails");

			m_strConnection = _T("DRIVER={SQL Server};Server=BLENDINGPC-2;Database=Coal_Blending_Db;Trusted=True");
			m_strCmdText = _T("Select * from dbo.Silo_Details");
			m_pRs.CreateInstance(_uuidof(Recordset));
			m_pRs->CursorLocation = adUseServer;
			m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenDynamic, adLockOptimistic, adCmdText);

			while (!m_pRs->EndOfFile)
			{
				str = m_pRs->Fields->GetItem(_T("Silo_No"))->Value;
				index = m_pRs->Fields->GetItem(_T("Si_No"))->Value.iVal;
				if ((str == str1) && (index > 0))
				{
					m_pRs->Update(("Coal_Type"), (_variant_t)str2); //Saving Coal Mine in L2 database
					hr = Write_FS_PLC_Data(index, str2); //Writing Coal Mine to PLC
				}

				m_pRs->MoveNext();
			};

			MessageBox(_T("Data Successfully Saved\nData Successfully written in PLC"), _T("Data Saved"), MB_OK);
			Invalidate();
		}

		m_pRs->Close();
	}
	else
		MessageBox(_T("You have not selected either Silo No. or Coal Source"), _T("Error"), MB_OK);


	CoUninitialize();

	
	

}

HRESULT CChangeSource::CreateOPCLink()
{
	HRESULT hr;

	//Creating Schneider OFC OPC SERVER Instance

	hr = Create_PLC_OPC_Server();

	//Adding  OPC GROUP

	hr = AddOPCGroup();

	// Adding All OPC Items
	hr = AddOPCItems();

	return hr;
}

HRESULT CChangeSource::Create_PLC_OPC_Server(void)
{
	CLSID			clsidSimaticNETOPC;
	HRESULT			hr;

	hr = ::CoInitialize(NULL);

	///Retriving Schneider OFC OPC Server CLSID
	if (CLSIDFromProgID(OLESTR("Schneider-Aut.OFS"), &clsidSimaticNETOPC) != NOERROR)
	{
		MessageBox(_T("Unable to Get Schneider OPC Server CLSID"), _T("Error"), MB_OK);
		return FALSE;
	}

	/*if (CLSIDFromProgID(OLESTR("ThermoScientific.Datapool"), &clsidSimaticNETOPC) != NOERROR)
	{
		MessageBox(_T("Unable to Get Schneider OPC Server CLSID"), _T("Error"), MB_OK);
		return FALSE;
	}*/

	
	hr = CoCreateInstance(clsidSimaticNETOPC, NULL, CLSCTX_LOCAL_SERVER, IID_IUnknown, (LPVOID*)&lpUnknown);
	if (hr != S_OK)
	{
		MessageBox(_T("CoCreateInstance Failed"), _T("Error"), MB_OK);
		return FALSE;
	}


	hr = lpUnknown->QueryInterface(IID_IOPCServer, (LPVOID*)&m_opcserver);
	if (hr != S_OK)
	{
		MessageBox(_T("IUnknown - QueryInterface Failed"), _T("Error"), MB_OK);
		lpUnknown->Release();
		return FALSE;
	}

	return hr;
}

HRESULT CChangeSource::AddOPCGroup()
{
	HRESULT hr;
	DWORD dwRequestedUpdateRate;
	DWORD dwRevisedUpdateRate;
	OPCHANDLE hServerGroup;
	OPCHANDLE hClientGroup;
	LONG	lTimeBias = 240L;
	BOOL	GroupActiveState = TRUE;
	wchar_t	szwGroupName[80];
	wcscpy_s(szwGroupName, L"Coal_Source"); ///OPC Group name definition
	hClientGroup = 0x100;
	dwRequestedUpdateRate = 1000;

	// Add a group to the server
	hr = m_opcserver->AddGroup(szwGroupName, GroupActiveState, dwRequestedUpdateRate,
		hClientGroup, &lTimeBias, NULL, 0,
		&hServerGroup, &dwRevisedUpdateRate,
		IID_IUnknown, (LPUNKNOWN*)&pUnkGrp);
	if (hr != S_OK)
	{
		MessageBox(_T("IOPcServer - AddGroup Failed"), _T("Error"), MB_OK);
		m_opcserver->Release();
		return FALSE;
	}

	return hr;
}
HRESULT CChangeSource::AddOPCItems()
{
	HRESULT hr;


	hr = pUnkGrp->QueryInterface(IID_IOPCItemMgt, (LPVOID*)&pOPCItemMgt);
	if (hr != S_OK)
	{
		MessageBox(_T("IUnknown - Failed to get IOPCItemMgt_read pointer from QueryInterface"), _T("Error"), MB_OK);
		CoUninitialize();
		exit(1);
		return FALSE;
	}

	ItemArray = (OPCITEMDEF*)CoTaskMemAlloc(dwCount_Read * sizeof(OPCITEMDEF));
	HRESULT			*AddErrors;

	for (int n = 0; n < dwCount_Read; n++)
	{
		ItemArray[n].szItemID = (LPWSTR)CoTaskMemAlloc(sizeof(TagList_Read_COAL_MINE[n]));
		ItemArray[n].szAccessPath = L"CHP_FS"; // Name of the Topic szwAccessPath
		//ItemArray[n].szAccessPath = L""; // Name of the Topic szwAccessPath
		ItemArray[n].szItemID = (LPWSTR)TagList_Read_COAL_MINE[n];
		ItemArray[n].bActive = TRUE;
		ItemArray[n].hClient = 0x1000 + n;
		ItemArray[n].dwBlobSize = 0;
		ItemArray[n].pBlob = NULL;
		ItemArray[n].vtRequestedDataType = VT_EMPTY;
	}


	// Add the item to the group for read

	hr = pOPCItemMgt->AddItems(dwCount_Read, ItemArray, &AddResults, &AddErrors);
	if (hr != S_OK)
	{
		MessageBox(_T("AddItem Failed - OPCItemMgt"), _T("Error"), MB_OK);
		CoTaskMemFree(AddErrors);
		CoTaskMemFree(AddResults);
		pOPCItemMgt->Release();
		exit(1);
	}

	CoTaskMemFree(AddErrors);
	if (hr == S_OK)
	{
		for (int n = 0; n < dwCount_Read; n++)
			ItemHandles[n] = AddResults[n].hServer;
	}
	
	return hr;
}

HRESULT CChangeSource::Read_FS_PLC_Data()
{
	HRESULT hr;
	DWORD dwCount_read = dwCount_Read;
	HRESULT			*ReadErrors = NULL;
	//OPCHANDLE *ItemHandles = (OPCHANDLE*)CoTaskMemAlloc(dwCount_read*sizeof(OPCHANDLE));
	DWORD			dwTransactionId = 0;
	OPCITEMSTATE* ItemState = (OPCITEMSTATE*)CoTaskMemAlloc(dwCount_read*sizeof(OPCITEMSTATE));

	//for(int n = 0; n < dwCount_read; n++)
	//ItemHandles[n] = AddResults_PLC3[n].hServer;

	// Get a pointer to the IOPCAsyncIO2 interface
	hr = pOPCItemMgt->QueryInterface(IID_IOPCSyncIO, (void**)&pOPCSyncIO_PLC);
	if (hr != S_OK)
	{
		MessageBox(_T("Unable to get IOPCSyncIO_read"), _T("Error"), MB_OK);
		CoUninitialize();
		exit(1);
	}

	hr = pOPCSyncIO_PLC->Read(OPC_DS_DEVICE, dwCount_read, ItemHandles, &ItemState, &ReadErrors);
	if (hr != S_OK)
	{
		//MessageBox(_T("Unable to read data_winch "), _T("Error"), MB_OK);
		return(0);
	}
	
	hr = pOPCSyncIO_PLC->Read(OPC_DS_DEVICE, dwCount_read, ItemHandles, &ItemState, &ReadErrors);
	
	CString m_Coal_Mine = _T("");
	_variant_t var5;
	VARTYPE vt1;
	if (hr == S_OK)
	{
		for (int n = 0; n < dwCount_Read; n++)
		{
			//var5 = ItemState[n].vDataValue;
			vt1 = ItemState[n].vDataValue.vt;
			m_Coal_Mine = GetSourceString(ItemState[n]);
		}
	}
	
	return hr;
}

HRESULT CChangeSource::Write_FS_PLC_Data(int index, CString str)
{
	HRESULT hr;
	hr = S_OK;
	DWORD dwCount_write = 1;
	HRESULT			*WriteErrors = NULL;
	//OPCHANDLE *ItemHandles = (OPCHANDLE*)CoTaskMemAlloc(dwCount_write*sizeof(OPCHANDLE));
	DWORD			dwTransactionId = 0;
	
	OPCHANDLE *ItemHandles_Write = (OPCHANDLE*)CoTaskMemAlloc(dwCount_write*sizeof(OPCHANDLE));
	
	ItemHandles_Write[0] = ItemHandles[index - 1]; // Transfering Handle of Silo Number

	
	SAFEARRAY* write_array = PutSourceString(str);
	_variant_t write_data[1];
	
	write_data[0].vt = VT_ARRAY | VT_UI1;
	write_data[0].parray = write_array;
	
	hr = pOPCItemMgt->QueryInterface(IID_IOPCSyncIO, (void**)&pOPCSyncIO_PLC);
	if (hr != S_OK)
	{
		MessageBox(_T("Unable to get IOPCSyncIO_read"), _T("Error"), MB_OK);
		CoUninitialize();
		exit(1);
	}
	hr = pOPCSyncIO_PLC->Write(dwCount_write, ItemHandles_Write, write_data, &WriteErrors);
	if (hr != S_OK)
	{
		MessageBox(_T("Unable to write Coal Mine Name to PLC"), _T("Error"), MB_OK);
		CoUninitialize();		
	}
	
	VariantClear(write_data);

	return hr;

}
CString CChangeSource::GetSourceString(OPCITEMSTATE pItemState)
{
	SAFEARRAY* var1 = NULL;
	
	
	SAFEARRAYBOUND saBound;
	saBound.lLbound = 0;
	saBound.cElements = 1;
	//SAFEARRAY* var1 = SafeArrayCreate(VT_UI1, 1, &saBound);

	int item = 0;

	CString str, str1, str2;
	str = _T("");
	str1 = _T("");
	
	var1 = pItemState.vDataValue.parray;
	
	long lower, upper;
	SafeArrayGetUBound(var1, 1, &upper);
	SafeArrayGetLBound(var1, 1, &lower);

	for (long j = lower; j <= upper; j++)
	{
		SafeArrayGetElement(var1, &j, (void*)&item);
		str1.Format(_T("%s"), &item);
		str = str + str1;
	}

	return str;
}

SAFEARRAY* CChangeSource::PutSourceString(CString m_Coal_Mine)
{
	
	SAFEARRAYBOUND saBound;
	saBound.lLbound = 0;
	saBound.cElements = 4;
	SAFEARRAY FAR* psa = SafeArrayCreate(VT_UI1, 1, &saBound);
	
	HRESULT hr;
	
	long m_asc = 0;
	unsigned char c = ' ';
	int len1 = m_Coal_Mine.GetLength();
	long len = 0;
	len = len1;
		
	for (long j = 0; j <= len; j++)
	{
		c = m_Coal_Mine.GetAt(j);
		m_asc = c;
		hr = SafeArrayPutElement(psa, &j, &m_asc);
	}
	
	return psa;
}