#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>
#include "METER.h"


void meter()
{
           // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();
 glViewport(0,0,200,200);                           // start with identity matrix 
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);   // setup a 10x10x2 viewing world

 
  glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

glTranslatef(0,-50,0);

 glColor3f(0.663, 0.663, 0.663); 
 
  GLUquadricObj *p = gluNewQuadric();
        
  gluDisk(p,0,100,100,100);
 
 

  //MARKINGS

  glTranslatef(0,0,0.5);
  
  glColor3f(0,0,0);
  gluDisk(p,92,100,100,100);



  glColor3f(0,0.980,0.604);
  gluPartialDisk(p,70,90,100,100,-120,40);
  glColor3f(0.196,0.804,0.196);
  gluPartialDisk(p,70,90,100,100,-80,40);
  glColor3f(0.604,0.804,0.196);
  gluPartialDisk(p,70,90,100,100,-40,40);
  glColor3f(1,0.843,0);
  gluPartialDisk(p,70,90,100,100,0,40);
  glColor3f(1,0.549,0);
  gluPartialDisk(p,70,90,100,100,40,40);
  glColor3f(1,0.271,0);
  gluPartialDisk(p,70,90,100,100,80,40);
  

  float NT=220;
  float nangle=(200/1000.0)*(abs(m.Speed));
  
  if(nangle<220)
  NT=220-nangle;

  else
    NT=340;
  

 // cout<<NT<<endl;

 glColor3f(0,0,1);

 glLineWidth(5);

  glBegin(GL_LINES);
  glVertex3f(1,0,0);
  glVertex3f(80*cos(NT*3.14/180),80*sin(NT*3.14/180),0.5);
  glEnd();

   char text[32];
    sprintf(text, "%.0f", m.Speed/3.0);
    glColor3f(0, 0, 0);
    glRasterPos3f( -20 , 20 ,0);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);


 glFlush(); 
}

