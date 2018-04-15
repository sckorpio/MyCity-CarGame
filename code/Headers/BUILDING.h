#ifndef BUILDING_H
#define BUILDING_H

#include <GL/glut.h>
#include "MYUTILITY.h"

//---------------------------------

  extern float WC[3];   //window color
  extern float Wx;  //window breadth
  extern float Wy;
  extern float Gx;  //gap between windows
  extern float Gy;
 //---------------------------------

 void Win(float l,float b,float h);    //window on walls
 

 void SetWin(float x,float y,float z,float p,float q,float r,float s);  // personalize window
  
 void Building(float l,float b,float h);  //make a building 

 //----------------------------------

        //BUILDING types

 void twistsearsTower(float l,float b,int blocks,float h,float d,float dangle);

 void searsTower(float l,float b,int blocks,float BH[20],float d);

 void petronas();

 //-----------------------------------

 void Hut(float l,float b,float h);


 
#endif
