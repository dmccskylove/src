#include "gvVisionTask_logo.h"
gvVisionTask_logo::gvVisionTask_logo( E_ROI_TYPE type )
:gvVisionTask(type)
{
	m_typeTask = TASKTYPE_LOGO;
}

gvVisionTask_logo::~gvVisionTask_logo()
{
    //dtor
}

bool gvVisionTask_logo::gvTask_inspect( Hobject image_src, Hobject *outRegion_defects )
{
	// Local iconic variables
	Hobject  ModelContours, TransContours;


	// Local control variables
	HTuple  ModelRow, ModelColumn, ModelAngle;
	HTuple  ModelScore, MatchingObjIdx, HomMat;


	set_system("border_shape_models", "false");

//	read_shape_model("D:/Matching 07.shm", &ModelId);

//	get_shape_model_contours(&ModelContours, m_ModelId, 1);

	find_shape_model(image_src, m_ModelId, HTuple(0).Rad(), HTuple(360).Rad(), (double)m_minscore/100, 1,
	0.5, "least_squares", 4, 0.75, &ModelRow, &ModelColumn, &ModelAngle, &ModelScore);

	for (MatchingObjIdx=0; MatchingObjIdx<=(ModelScore.Num())-1; MatchingObjIdx+=1)
	{
		hom_mat2d_identity(&HomMat);
		hom_mat2d_rotate(HomMat, HTuple(ModelAngle[MatchingObjIdx]), 0, 0, &HomMat);
		hom_mat2d_translate(HomMat, HTuple(ModelRow[MatchingObjIdx]), HTuple(ModelColumn[MatchingObjIdx]),
		&HomMat);
		affine_trans_contour_xld(m_ModelContours, outRegion_defects, HomMat);
	}
    return TRUE;
}

void gvVisionTask_logo::gvTask_ReadParam( wxXmlNode* pNode_parent )
{
    gvVisionTask::gvTask_ReadParam(pNode_parent);
	m_minscore=ISHCAP_API::xml_GetNodeValueF(pNode_parent,wxT("minscore"),0.5);
	m_modelname=ISHCAP_API::xml_GetNodeValueS(pNode_parent,wxT("modelname"),"");
	wxString modelname= wxGetCwd()
			+ wxT("\\articles\\Model\\")
			+ m_modelname
			+ wxT(".shm");
	read_shape_model(modelname, &m_ModelId);
	get_shape_model_contours(&m_ModelContours, m_ModelId, 1);
}

void gvVisionTask_logo::gvTask_SaveParam( wxXmlNode* pNode_parent )
{
    gvVisionTask::gvTask_SaveParam(pNode_parent);
	ISHCAP_API::xml_SetNodeValueF(pNode_parent,wxT("minscore"),m_minscore);
	ISHCAP_API::xml_SetNodeValueS(pNode_parent,wxT("modelname"),m_modelname);
	wxString modelname1= wxGetCwd()
		+ wxT("\\articles\\Model\\")
		+ m_modelname
		+ wxT(".shm");
	HTuple modelname2 = modelname1;
	write_shape_model(m_ModelId,modelname2);

}

