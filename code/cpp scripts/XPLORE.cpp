#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "ALL.h"

using namespace std;

int freerotate=-1;


void initializeXPLORE()
{
        
	m.X=1114;
	m.Y=580;
        m.Z=-3823;
	

        m.theta=112;
    
        car.SelectModel(1);
        
}




void Axes()
{   
    glLineWidth(6);
     
    glColor3f(0,0,1);

    glBegin(GL_LINES);      //Z
    glVertex3f(0,0,5000);
    glVertex3f(0,0,0);
    glEnd();

    glLineWidth(2);
     
    glColor3f(0,0,1);

    glBegin(GL_LINES);      //Z
    glVertex3f(0,0,0);
    glVertex3f(0,0,-5000);
    glEnd();



  glLineWidth(6);
     glColor3f(0,1,1);

    glBegin(GL_LINES);     //Y
    glVertex3f(0,5000,0);
    glVertex3f(0,0,0);
    glEnd();

     glColor3f(1,0,0);

    glBegin(GL_LINES);        //X
    glVertex3f(5000,0,0);
    glVertex3f(0,0,0);
    glEnd();

    glLineWidth(2);

   glColor3f(1,0,0);

    glBegin(GL_LINES);        //X
    glVertex3f(0,0,0);
    glVertex3f(-5000,0,0);
    glEnd();

    glLineWidth(1);


    for(int i=-5000;i<=5000;i+=100)
    {
       glColor3f(0,0,0);
     glBegin(GL_LINES);      //Z
    glVertex3f(i,2,5000);
    glVertex3f(i,2,-5000);
    glEnd();

    }

    for(int i=-5000;i<=5000;i+=100)
    {
      glColor3f(0,0,0);
     glBegin(GL_LINES);        //X
    glVertex3f(5000,2,i);
    glVertex3f(-5000,2,i);
    glEnd();

    }

    
}


void displayXPLORE(void) 
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

   cout<<m.X<<" "<<m.Y<<" "<<m.Z<<endl;

   
   
   cam.SetFreeCamera(m.X,m.Y,m.Z,m.X+m.ux*1000,m.Y,m.Z+m.uz*1000);

   makeRoads();

   makeBuildings();

  
  car.DrawCar(400,2,400,0,0);
   

    glFlush(); 
}



void specialXPLORE(int key,int x,int y)
{
   switch(key)
   {
       case GLUT_KEY_UP:   { m.X=m.X+m.ux*10;  m.Z=m.Z+m.uz*10;  } break;
      case GLUT_KEY_DOWN:  { m.X=m.X-m.ux*10;  m.Z=m.Z-m.uz*10;  }  break; 
      case GLUT_KEY_LEFT:{ m.X=m.X+m.uz*10;  m.Z=m.Z-m.ux*10;  } break;
      case GLUT_KEY_RIGHT:{ m.X=m.X-m.uz*10;  m.Z=m.Z+m.ux*10;  } break;
    
     

      case GLUT_KEY_F1:  car.SelectModel(1);  break;
      case GLUT_KEY_F2:  car.SelectModel(2);  break;
      case GLUT_KEY_F3:  car.SelectModel(3);  break;
      case GLUT_KEY_F4:  car.SelectModel(4);  break;

   }

   m.UpdateVector();


  
   glutPostRedisplay();
}


void keyXPLORE(unsigned char key,int x,int y)
{
   switch(key)
   {
      

     
      //case 'V': vx=-vx;  break;
     case 's':
     case 'S': { m.Y=m.Y-10; }  break;
     case 'w':
     case 'W':  { m.Y=m.Y+10;  } break;
     case 'a':
     case 'A':{ m.theta=m.theta-0.5; } break;
     case 'd':
      case 'D': { m.theta=m.theta+0.5;} break;

    

      //case 9: ax=-ax;break;  

     case 32:freerotate=-freerotate;  break;
     case 27: state=0; break;
           
      
   }

   m.UpdateVector();

   glutPostRedisplay();
}


void timeXPLORE()
{
   if(freerotate==1)
   m.theta=m.theta+2;

   cout<<m.theta<<endl;

  // displayXPLORE();

    m.UpdateVector();
   //glutPostRedisplay();

}


