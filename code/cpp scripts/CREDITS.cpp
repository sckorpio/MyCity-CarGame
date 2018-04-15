#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "CREDITS.h"
#include "ALL.h"

using namespace std;

void printLINEc(int x,int y,char S[50])
{
   char text[50];
  sprintf(text, S);
    
    glRasterPos3f(x,y,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

}

void creditLIST()
{
  
           // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();
 glViewport(0,0,800,800);                           // start with identity matrix 
 glOrtho(0.0, 800.0, 800.0, 0.0, -1.0, 1.0);   // setup a 10x10x2 viewing world

 
  glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glColor3f(0.482,0.408,0.933);

    glBegin(GL_POLYGON);
    glVertex3f(0,0,0.5);
    glVertex3f(0,800,0.5);
    glVertex3f(800,800,0.5);
    glVertex3f(800,0,0.5);
    glEnd();

   glColor3f(0.690,0.769,0.871);
    glBegin(GL_POLYGON);
    glVertex3f(50,50,0.6);
    glVertex3f(50,750,0.6);
    glVertex3f(750,750,0.6);
    glVertex3f(750,50,0.6);
    glEnd();


    

    glColor3f(0, 0, 1);

  


   printLINEc(240,130,"##############################");
   printLINEc(240,150,"##           ---C R E D I T S--       ##");
   printLINEc(240,170,"##############################");
   glColor3f(1, 0, 0);

   printLINEc(200,200,"-----NATIONAL INSTITUTE OF TECHNOLOGY----");
   printLINEc(200,220,"----- COMPUTER SCIENCE & ENGINEERING--");
   glColor3f(0, 0, 0);

   printLINEc(200,280,"---KARTIK KUMAR--------- (16568)");
   printLINEc(200,320,"---VIKAS KUMAR SAHU----- (16569)");
   printLINEc(200,340,"---SHIVOM CHAUHAN-------(16562)");
   printLINEc(200,360,"---AYUSH DHIMAN---------(16542)");
   printLINEc(200,380,"---ANKIT KUMAR----------(16574)");

   printLINEc(360,500,"Special Thanks to--  Dr. NAVEEN CHAUHAN ");

   printLINEc(50,680,"Total lines CODED-- 4944");
   printLINEc(50,700,"Completed- 12/DEC/2017");

   
   


 glFlush(); 
}


void displayCREDITS(void) 
{ 


  glClearColor(1,1,1,0);

   glClearDepth(1);
   glClear(GL_COLOR_BUFFER_BIT);
   glClear(GL_DEPTH_BUFFER_BIT);

   glEnable(GL_DEPTH_TEST);
  
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glViewport(0,0,800,800);        
   gluPerspective(45,1,1,10000);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

 

   

  creditLIST();
  
   

    glFlush(); 


}






void keyCREDITS(unsigned char key,int x,int y)
{
   switch(key)
   {
      
      case 27: state=0; break;
     
           
      
   }


   glutPostRedisplay();
}



