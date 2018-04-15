#ifndef CAR_H
#define CAR_H

#include <GL/glut.h>

class CAR
{
	//--------------------------------------------------------------------
   public:

    int model;
   
    void SelectModel(int i);                                  //to select Model
    
    //-----------------------------------------------------------------

    

    	float M[3];
    	float B[3];
    	float G[4];
    	float L[3];

    void SetM(float a,float b,float c);	
    void SetB(float a,float b,float c);	
    void SetL(float a,float b,float c);	
    void SetG(float a,float b,float c);	

    void Model1();
    void Model2();
    void Model3();
    void Model4();

    void WireFrame();
    void Paint();
    void Lights();
    void Wheels(float aw);
    void Tyre();

   void DrawCar(float a,float b,float c,float A,float Aw);   //to draw CAR

};

#endif

