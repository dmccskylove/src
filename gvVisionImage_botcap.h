#ifndef GVVISIONIMAGE_BOTCAP_H
#define GVVISIONIMAGE_BOTCAP_H

#include "core/gvVisionImage.h"

#include"gvVisionTask_black.h"
#include"gvVisionTask_logo.h"
#include"gvVisionTask_color.h"


class gvVisionTask;
class gvVisionCCD;
class gvVisionImage_botcap : public gvVisionImage
{
    public:
        gvVisionImage_botcap(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight);
        virtual ~gvVisionImage_botcap();

        void gvIMG_TriggerInspection( bool isTest = false );
        virtual void gvIMG_ShowConfig( wxWindow *parent ) = 0;
		void gvIMG_ReadParam( wxXmlNode* pNode_parent ) ;
		void gvIMG_SaveParam( wxXmlNode* pNode_parent ) ;
		virtual bool _insp_loc( Hobject image_src, Hobject *outRegion_loc)=0;
        void gvIMG_LoadImage( wxString filename );
        void gvIMG_SaveImage( wxString filename );
        void gvIMG_DrawImage( bool isDrawRoi = false );
        bool gvIMG_ConvertImage();

		 int gvIMG_GetTaskCnt(){ return vec_pTask.size();}
		gvVisionTask* gvIMG_GetTask(unsigned int idxTask){ return vec_pTask.at(idxTask);}
        void gvIMG_AddTask(gvVisionTask* pgvTask);
		void gvIMG_DeletTask(unsigned int idxTask);
		gvVisionCCD* gvIMG_GetVisionCCD()
		{
			return c_pgvVisionCCD;
		}

		BOOL  gvIMG_OpenWindow(HWND hParentWnd, unsigned int left  = 0 , unsigned int top  = 0 , unsigned int width  = 640 , unsigned int height  = 480 );

		void gvIMG_SetMinarea(int minarea)
		{
			m_minarea = minarea;
		}
		int gvIMG_GetMinarea()
		{
			return m_minarea;
		}



		bool gvIMG_GetisLoadImage(){return m_bloadimage;}

		void gvIMG_ShowAllROI();
		void gvIMG_FitSize( int left,  int top, int width,  int height);
		Hobject gvIMG_GetRoi(int idxRoi){return ho_ROI[idxRoi];}
		Hobject gvIMG_GetImage(){return ho_Image;}
	/**<  ROI*/
		bool gvIMG_ROISelect();
		void gvIMG_ROIStop();
		void gvIMG_ROIMove();
		void gvIMG_SetROImshape(int x,int y);

    protected:
        Hobject         ho_Image;
        Hobject			ho_ROI[30];
        Hlong           hl_WindowID;
        wxRect			hl_WindowID_rect;
        std::vector<gvVisionTask*>  vec_pTask;
        std::vector<gvVisionTask*>::iterator itr_pTask;
		gvVisionCCD* c_pgvVisionCCD;
		int m_minarea;
		int m_idxActiveROI;
		E_ROI_TYPE 	m_roitype[30];

		long     m_rowMoving;
		long     m_colMoving;
		bool		m_bROIMoving;
		bool 		m_bROISizOut;
		bool 		m_bloadimage;




    private:


};

#endif // GVVISIONIMAGE_BOTCAP_H
