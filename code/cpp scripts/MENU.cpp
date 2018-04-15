#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "ALL.h"
#include "GAME.h"
#include "DRIVE.h"
#include "XPLORE.h"

using namespace std;

int ptr=150;
int temp=1;


void arrow()
{
    glColor3f(1,0,0);

    glBegin(GL_POLYGON);
    glVertex3f(-200,ptr,0.5);
    glVertex3f(-260,ptr+20,0.5);
    glVertex3f(-230,ptr,0.5);
    glVertex3f(-260,ptr-20,0.5);
    glEnd();


}

void LIST()
{
  
           // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();
 glViewport(0,0,600,600);                           // start with identity matrix 
 glOrtho(-300.0, 300.0, -300.0, 300.0, -1.0, 1.0);   // setup a 10x10x2 viewing world

 
  glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   
   glColor3f(0.482,0.408,0.933);

    glBegin(GL_POLYGON);
    glVertex3f(-230,-180,0.3);
    glVertex3f(30,-180,0.3);
    glVertex3f(30,330,0.3);
    glVertex3f(-230,330,0.3);
    glEnd();



   glColor3f(0.690,0.769,0.871);

    glBegin(GL_POLYGON);
    glVertex3f(-200,-150,0.5);
    glVertex3f(0,-150,0.5);
    glVertex3f(0,300,0.5);
    glVertex3f(-200,300,0.5);
    glEnd();

    char text[32];

    glColor3f(0, 0, 0);

    sprintf(text, "##############");
    
    glRasterPos3f( -200 , 270 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    sprintf(text, "##  MyCITY    ##");
    
    glRasterPos3f( -200 , 250 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

   sprintf(text, "#############");
    
    glRasterPos3f( -200 , 220 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

      sprintf(text, "---PLAY");
    
    glRasterPos3f( -200 , 150 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

      sprintf(text, "--FREE DRIVE");
    
    glRasterPos3f( -200 , 100 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

      sprintf(text, "--XPLORE CITY");
    
    glRasterPos3f( -200 , 50 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
   
  sprintf(text, "--CONTROLS");
  glRasterPos3f( -200 , 0 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

  sprintf(text, "--CREDITS");
  glRasterPos3f( -200 , -50 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

   sprintf(text, "--QUIT");
  glRasterPos3f( -200 , -100 ,1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);



    arrow();



 glFlush(); 
}


void displayMENU(void) 
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

 

   cout<<temp<<" "<<state<<endl;

  car.SelectModel(1);
  cam.SetFreeCamera(30,10,-940,0,2,-900);

  makeRoads();

   makeBuildings();

  glPushMatrix();
   glTranslatef(0,2,-900);
  glRotatef(90,0,1,0);
  car.DrawCar(0,0,0,0,0);
  glPopMatrix();

  LIST();
  
   

    glFlush(); 


}



void specialMENU(int key,int x,int y)
{
   switch(key)
   {
       case GLUT_KEY_UP:   { if(temp!=1){ ptr=ptr+50; temp--; } } break;
      case GLUT_KEY_DOWN:  { if(temp!=6) { ptr=ptr-50; temp++; } }  break; 
   }

   glutPostRedisplay();
}


void keyMENU(unsigned char key,int x,int y)
{
   switch(key)
   {
      
      case 13: {  
                    state=temp;

                    if(state==1)
                    initializeGAME();

                   else if(state==2)
                    initializeDRIVE();
                   
                    else if(state==3)
                    initializeXPLORE();

                    else if(state==6)
                     exit(0);
                      

               } break;
     
           
      
   }


   glutPostRedisplay();
}



