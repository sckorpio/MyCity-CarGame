#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "CITY.h"


char text[15];


//----------------------------------------------------------------------------


void Stopwatch(int it)
{
	int t=glutGet(GLUT_ELAPSED_TIME);
	int dt=t-it;


    glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();
 glViewport(600,500,200,100);                           // start with identity matrix 
 glOrtho(-100.0, 100.0, -50.0, 50.0, -1.0, 1.0);   // setup a 10x10x2 viewing world

 
  glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
  
  glColor3f(0.482,0.408,0.933);
   glBegin(GL_POLYGON);
   glVertex3f(-100,50,0);
   glVertex3f(100,50,0);
   glVertex3f(100,-50,0);
   glVertex3f(-100,-50,0);
   glEnd();

   glColor3f(0.690,0.769,0.871);
   glBegin(GL_POLYGON);
   glVertex3f(-80,40,0.5);
   glVertex3f(80,40,0.5);
   glVertex3f(80,-40,0.5);
   glVertex3f(-80,-40,0.5);
   glEnd();

   

   int milli=dt%100;



  dt=dt/1000.0;
  

  int sec=dt%60;
  int min=dt/60;

  //cout<<dt<<endl;

  char text2[15];
  
    sprintf(text, "%.0d :: %.0d :: %.0d",min,sec,milli);
    sprintf(text2,"left=%.0d",(99-count));
    glColor3f(1, 0, 0);
    glRasterPos3f( -40, 10 ,0.6);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

     glColor3f(0, 0, 0);
    glRasterPos3f( -50, -10 ,0.6);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text2[i]);


  if(count==100)
    {
       finish=1;
   }
 

 glFlush(); 

}

void printScore()
{
	
   //cout<<score<<endl;

    glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();
 glViewport(100,100,600,200);                           // start with identity matrix 
 glOrtho(-300.0, 300.0, -100.0, 100.0, -1.0, 1.0);   // setup a 10x10x2 viewing world

 
  glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
  
  glColor3f(1,1,0);
   glBegin(GL_POLYGON);
   glVertex3f(-300,100,0);
   glVertex3f(300,100,0);
   glVertex3f(300,-100,0);
   glVertex3f(-300,-100,0);
   glEnd();

   glColor3f(1,0,0);
   glBegin(GL_POLYGON);
   glVertex3f(-280,80,0.5);
   glVertex3f(280,80,0.5);
   glVertex3f(280,-80,0.5);
   glVertex3f(-280,-80,0.5);
   glEnd();

  

   glColor3f(0, 0, 0);

   char text2[15];
   sprintf(text2,"-------TIME------ ");

   glRasterPos3f( -100, 10 ,0.6);
    for(int i = 0; text2[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text2[i]);

    glRasterPos3f( -50, -10 ,0.6);
  for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
 

 glFlush(); 


}

