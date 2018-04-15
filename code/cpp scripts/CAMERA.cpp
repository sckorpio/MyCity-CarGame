#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>
#include "CAMERA.h"
using namespace std;

CAMERA::CAMERA()
{
	LX=0; LY=0;  LZ=0;
	EX=0; EY=1000; 
        VIEW=0;
	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,0,1);
}

void CAMERA::SetFreeCamera(float ex,float ey,float ez,float lx,float ly,float lz)
{
	gluLookAt(ex,ey,ez,lx,ly,lz,0,1,0);
}

//---------------------------------------------

void CAMERA::TopView(float cx,float cy,float cz,float ux,float uz)
{

	EX=cx; 
	EY=cy+H;
	EZ=cz;

	LX=cx;
	LY=cy;
	LZ=cz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,1,0,0);
}

void CAMERA::BackView(float cx,float cy,float cz,float ux,float uz)
{
	float d=50;
	float D=1000;

	EX=cx-d*ux; 
	EY=cy+H;
	EZ=cz-d*uz;

	LX=cx+D*ux;
	LY=cy;
	LZ=cz+D*uz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}

void CAMERA::FrontView(float cx,float cy,float cz,float ux,float uz)
{
	float d=50;
	float D=1000;

	EX=cx+d*ux; 
	EY=cy+H;
	EZ=cz+d*uz;

	LX=cx-D*ux;
	LY=cy;
	LZ=cz-D*uz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}


void CAMERA::LeftSideView(float cx,float cy,float cz,float ux,float uz)
{
	float d=50;

	EX=cx+d*uz; 
	EY=cy+H;
	EZ=cz-d*ux;

	LX=cx;
	LY=cy;
	LZ=cz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}


void CAMERA::RightSideView(float cx,float cy,float cz,float ux,float uz)
{
	float d=50;

	EX=cx-d*uz; 
	EY=cy+H;
	EZ=cz+d*ux;

	LX=cx;
	LY=cy;
	LZ=cz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}


void CAMERA::DragonView(float cx,float cy,float cz,float ux,float uz)
{
	float d=100;

	EX=cx-d*ux; 
	EY=cy+H;
	EZ=cz-d*uz;

	LX=cx;
	LY=cy;
	LZ=cz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}

void CAMERA::CornerView(float cx,float cy,float cz,float ux,float uz)
{
	float back=50;
	float side=50;

	EX=cx-back*ux+side*uz; 
	EY=cy+H;
	EZ=cz-back*uz-side*ux;

	LX=cx;
	LY=cy;
	LZ=cz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}

void CAMERA::WindScreen(float cx,float cy,float cz,float ux,float uz)
{
	float d=5;
	float D=1000;
	
	EX=cx+d*ux; 
	EY=cy+7;
	EZ=cz+d*uz;

	LX=cx+D*ux;
	LY=0;
	LZ=cz+D*uz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}

void CAMERA::FixView(float fx,float fy,float fz,float cx,float cy,float cz,float ux,float uz)
{
	float d=5;
	float D=1000;
	
	EX=fx; 
	EY=H;
	EZ=fz;

	LX=cx;
	LY=cy;
	LZ=cz;

	gluLookAt(EX,EY,EZ,LX,LY,LZ,0,1,0);
}

//-----------------

void CAMERA::SetDriveCamera(float cx,float cy,float cz,float ux,float uz)
 {
 	switch(VIEW)
 	{
        
 	case 1: TopView(cx,cy,cz,ux,uz);   break;
        case 2: BackView(cx,cy,cz,ux,uz);  break;
        case 3: FrontView(cx,cy,cz,ux,uz); break;
        case 4: LeftSideView(cx,cy,cz,ux,uz); break;
        case 5: RightSideView(cx,cy,cz,ux,uz); break;
        case 6: DragonView(cx,cy,cz,ux,uz);   break;
        case 7: CornerView(cx,cy,cz,ux,uz);  break;
        case 8: WindScreen(cx,cy,cz,ux,uz);  break;
        case 9: FixView(fx,fy,fz,cx,cy,cz,ux,uz);  break;
 	}
 }   


