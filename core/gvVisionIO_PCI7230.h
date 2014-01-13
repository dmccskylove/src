#pragma once
#include "core\ISHCAPDef.h"

class gvVisionManager;
class gvVisionIO_pci7230
{
public:
	gvVisionIO_pci7230(gvVisionManager* pgvVisionManager);
	~gvVisionIO_pci7230(void);

	bool gvIO_Init();
	bool isInit();

	bool get_InputBit( unsigned int idxPort );
	bool get_OutputBit( unsigned int idxPort );
	bool set_OutputBit( unsigned int idxPort, bool isSet = true );
private:
	bool				m_isInit;
	short				m_sCardNo;
	unsigned long		m_ulOutputs;
	wxCriticalSection	m_CriticalSection;
	gvVisionManager		*c_pgvVisionManager;
};

