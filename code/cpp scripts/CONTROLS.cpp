#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "CONTROLS.h"
#include "ALL.h"

using namespace std;

void printLINE(int x,int y,char S[50])
{
   char text[50];
  sprintf(text, S);
    
    glRasterPos3f(x,y,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

}

void controlLIST()
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


    

    glColor3f(0, 0, 0);

  


   printLINE(200,130,"###########################");
   printLINE(200,150,"## ---C O N T R O L S--    ##");
   printLINE(200,170,"###########################");


   printLINE(50,200,"###########################");
   printLINE(50,220,"## DRIVING CONTROLS      ##");
   printLINE(50,240,"###########################");
   printLINE(50,290," Accelerate-  UP arrow    / W");
   printLINE(50,320," Turn left -  LEFT arrow  / A");
   printLINE(50,350," Turn Right-  Right arrow / D");
   printLINE(50,380," Reverse-     DOWN arrow  / S");
   printLINE(50,410," Break -      SpaceBAR");
   printLINE(50,440," VIEWS -      0-9");
   printLINE(50,470," CAMERA ELEVATION T-G");
  
   printLINE(50,500,"###########################");
   printLINE(50,520,"## CAR COLOR MODELS      ##");
   printLINE(50,540,"###########################");
   printLINE(50,580," CAR COLOR RED-  F1");
   printLINE(50,610," CAR COLOR RED-  F2");
   printLINE(50,640," CAR COLOR RED-  F3");
   printLINE(50,670," CAR COLOR RED-  F4");

   printLINE(350,200,"###########################");
   printLINE(350,220,"## XPLORE CONTROLS      ##");
   printLINE(350,240,"###########################");
   printLINE(350,290," Move ahead-  UP arrow   ");
   printLINE(350,320," Move left -  LEFT arrow ");
   printLINE(350,350," Move Right-  Right arrow");
   printLINE(350,380," Move back -  DOWN arrow ");
   printLINE(350,410," Move Up   -  W");
   printLINE(350,440," Move Down -  S");
   printLINE(350,470," Turn left -  A");
   printLINE(350,500," Turn right-  D");
  
  
   


 glFlush(); 
}


void displayCONTROLS(void) 
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

 

   

  controlLIST();
  
   

    glFlush(); 


}






void keyCONTROLS(unsigned char key,int x,int y)
{
   switch(key)
   {
      
      case 27: state=0; break;
     
           
      
   }


   glutPostRedisplay();
}



