#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>
#include "MYUTILITY.h"
using namespace std;

float C1[3];
float C2[3];

//--------------------------------utility functions-------------------------------------
 void SetC1(float x,float y,float z)
{
   C1[0]=x;
   C1[1]=y;
   C1[2]=z;
}

 void SetC2(float x,float y,float z)
{
   C2[0]=x;
   C2[1]=y;
   C2[2]=z;
}


 void RECT(float l,float b)
{
  glBegin(GL_POLYGON);
  glVertex3f(-b,0,l);
  glVertex3f(b,0,l);
  glVertex3f(b,0,-l);
  glVertex3f(-b,0,-l);
  glEnd();
}

void CUBOID(float b,float l,float h)
{
   glColor3fv(C1);

   glBegin(GL_POLYGON);            //bottom
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,0,+b/2);
   glEnd();


   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
  
   
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

   glColor3fv(C2);
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();

   glBegin(GL_POLYGON);                  //left
  glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();


   glColor3fv(C2);
   glBegin(GL_POLYGON);         //top
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,h,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glEnd();

  

}

