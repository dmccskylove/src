// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "pci7230\Include\Dask.h"
#include "gvVisionIO_PCI7230.h"

#pragma comment(lib,"PCI-Dask.lib")

gvVisionIO_pci7230::gvVisionIO_pci7230(gvVisionManager* pgvVisionManager)
{
	wxASSERT(pgvVisionManager);
	c_pgvVisionManager = pgvVisionManager;

	m_isInit = false;
	m_sCardNo = -1;
	m_ulOutputs = 0;
}


gvVisionIO_pci7230::~gvVisionIO_pci7230(void)
{
	if ( isInit() )
	{
		Release_Card(m_sCardNo);
		m_isInit = false;
	}//if ( isInit() )
}

bool gvVisionIO_pci7230::isInit()
{
	return m_isInit;
}

bool gvVisionIO_pci7230::get_InputBit( unsigned int idxPort )
{
	if ( isInit() )
	{
		wxCriticalSectionLocker csLock(m_CriticalSection);
		U32 input = 0;
		DI_ReadPort( m_sCardNo, 0, &input );
		bool bRet = ( input >> idxPort ) & 0x01;
		return bRet;
	}//if ( isInit() )

	return false;
}

bool gvVisionIO_pci7230::get_OutputBit( unsigned int idxPort )
{
	return ( m_ulOutputs >> idxPort ) & 0x01;
}

bool gvVisionIO_pci7230::set_OutputBit( unsigned int idxPort, bool isSet/* = true*/ )
{
	if( !isInit() )
	{
		//wxMessageBox(wxT("I/O未初始化，设置I/O输出口失败！"));
		return false;
	}
	wxCriticalSectionLocker csLock(m_CriticalSection);
	if(isSet)
	{
		if( !( (m_ulOutputs >> idxPort) & 0x01 ) )
		{
			m_ulOutputs += ( (U16)1L ) << idxPort;
			DO_WritePort( m_sCardNo, 0, m_ulOutputs );
		}
	}
	else
	{
		if( (m_ulOutputs >> idxPort) & 0x01 )
		{
			m_ulOutputs -= ( (U16)1L ) << idxPort;
			DO_WritePort( m_sCardNo, 0, m_ulOutputs );
		}
	}

	return true;
}

bool gvVisionIO_pci7230::gvIO_Init()
{
	/************************************************************************/
	/* 初始化I/O卡                                                          */
	/************************************************************************/
	m_sCardNo = Register_Card( PCI_7230, 0 );
	if ( m_sCardNo > -1 )
	{
		m_isInit = true;
	}//if ( m_sCardNo > -1 )

	return m_isInit;
}
