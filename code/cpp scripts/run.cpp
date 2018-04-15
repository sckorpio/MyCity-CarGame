#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>


#include "MENU.h"
#include "GAME.h"
#include "DRIVE.h"
#include "XPLORE.h"
#include "CONTROLS.h"
#include "CREDITS.h"

using namespace std;


void display()
{
	switch(state)
	{
		case 0: displayMENU();  break; 
		case 1: displayGAME();  break; 
		case 2: displayDRIVE(); break;
		case 3: displayXPLORE(); break;
                case 4: displayCONTROLS(); break;
                case 5: displayCREDITS(); break;
	}
}


void key(unsigned char key,int x,int y)
{
	switch(state)
	{
		case 0:keyMENU(key,x,y); break;
		case 1:keyGAME(key,x,y); break;
		case 2:keyDRIVE(key,x,y); break;
		case 3:keyXPLORE(key,x,y); break;
                case 4:keyCONTROLS(key,x,y); break;
                case 5:keyCREDITS(key,x,y); break;
	}
}



void special(int key,int x,int y)
{
	switch(state)
	{
		case 0:specialMENU(key,x,y); break;
		case 1:specialGAME(key,x,y); break;
		case 2:specialDRIVE(key,x,y); break;
		case 3:specialXPLORE(key,x,y); break;
	}
}


void time(int value)
{
	switch(state)
	{
	case 1:   timeGAME();  break;
        case 2:   timeDRIVE(); break;
        case 3:   timeXPLORE(); break;
             
		
	}

	glutPostRedisplay();

	glutTimerFunc(20,time,0);
	
	
}



void reshape(int w,int h)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);         // black background 
 
   glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

  
}



int main(int argc, char **argv) 
{ 
 printf("hello world\n"); 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
 

 glutInitWindowPosition(0,0); 
 glutInitWindowSize(800,800); 
 glutCreateWindow ("car");
  
 glutReshapeFunc(reshape);

  glutDisplayFunc(display); 

  glutKeyboardFunc(key);

   glutSpecialFunc(special);

 
  glutTimerFunc(20,time,0);
  
 glutMainLoop();

 return 0; 
}
