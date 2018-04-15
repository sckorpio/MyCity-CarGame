#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>
#include "CAR.h"
using namespace std;



void CAR::SetM(float a,float b,float c)
{
    M[0]=a;
    M[1]=b;
    M[2]=c;
}

void CAR::SetG(float a,float b,float c)
{
    G[0]=a;
    G[1]=b;
    G[2]=c;
    G[3]=0.5;
}

void CAR::SetB(float a,float b,float c)
{
    B[0]=a;
    B[1]=b;
    B[2]=c;
}

void CAR::SetL(float a,float b,float c)
{
    L[0]=a;
    L[1]=b;
    L[2]=c;
}



//-----------------------models------------------------

void CAR::Model1()
{
  SetM(1,0,0);
  SetG(0.184, 0.310, 0.310);
  SetB(0.698, 0.133, 0.133);
  SetL(1,1,0);
}


void CAR::Model2()
{
  SetM(0,0,0);
  SetG(0.184, 0.310, 0.310);
  SetB(0,0,0);
}

void CAR::Model3()
{
  SetM(0.753,0.753,0.753);
  SetG(0.690,0.769,0.871);
  SetB(0.663,0.663,0.663);
  SetL(0.878,1,1);
  
}

void CAR::Model4()
{
  SetM(0.098, 0.098, 0.439);
  SetG(0.184, 0.310, 0.310);
  SetB(0.098, 0.098, 0.439);
  SetL(0.69,0.769,0.871);
}

//------------------------------------------------

void CAR::Lights()
{
     //----------------------head light---------------------
   
    glColor3fv(L);

    glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(-13.5,1,5);

     glBegin(GL_POLYGON);  //LEFT
    glVertex3f(-14,0,4);
    glVertex3f(-14,2,4);
    glVertex3f(-10,2,7);
    glVertex3f(-10,0,7);
    glEnd();

    glPopMatrix();

          //--------------

    glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(-13.5,1,-5);

     glBegin(GL_POLYGON);  //RIGHT
    glVertex3f(-14,0,-4);
    glVertex3f(-14,2,-4);
    glVertex3f(-10,2,-7);
    glVertex3f(-10,0,-7);
    glEnd();
  

    glPopMatrix();



    glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(-12,3,5);

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(-14,2,4);
    glVertex3f(-10,2,7);
    glVertex3f(-7,4,5);
    glEnd();


    glPopMatrix();



    glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(-12,3,-5);


     glBegin(GL_POLYGON);  //DOWN
    glVertex3f(-14,2,-4);
    glVertex3f(-10,2,-7);
    glVertex3f(-7,4,-5);
    glEnd();

    glPopMatrix();


    //-------------------------------BACKLIGHT------------------------------------------


     glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(12.5,1,0);

     glBegin(GL_POLYGON);  //CENTRE
     glVertex3f(12,0,3);
    glVertex3f(12,3,3);
    glVertex3f(12,3,-3);
    glVertex3f(12,0,-3);
    glEnd();
  

    glPopMatrix();



    glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(11,1,5);

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(12,0,3);
    glVertex3f(12,3,3);
    glVertex3f(8,3,7);
    glVertex3f(8,0,7);
    glEnd();


    glPopMatrix();



    glPushMatrix();
   
    glScalef(0.5,0.5,0.5);
    glTranslatef(11,1,-5);


     glBegin(GL_POLYGON);  //DOWN
   glVertex3f(12,0,-3);
    glVertex3f(12,3,-3);
    glVertex3f(8,3,-7);
    glVertex3f(8,0,-7);
    glEnd();

    glPopMatrix();

    

}







void CAR::Paint()
{

    glColor3f(0,0,0);

    glBegin(GL_POLYGON);  //CENTRE
    glVertex3f(-10,0,6);
    glVertex3f(-10,0,-6);
    glVertex3f(8,0,-6);
    glVertex3f(8,0,6);
    glEnd();

    glBegin(GL_POLYGON);  //FRONT BASE
    glVertex3f(-10,0,7);
    glVertex3f(-10,0,-7);
    glVertex3f(-14,0,-4);
    glVertex3f(-14,0,4);
    glEnd();

    glBegin(GL_POLYGON);  //REAR BASE
    glVertex3f(8,0,7);
    glVertex3f(8,0,-7);
    glVertex3f(12,0,-3);
    glVertex3f(12,0,3);
    glEnd();

    //-------------------------- FRONT BUMPER--------------

    glColor3fv(B);

    glBegin(GL_POLYGON);  //CENTRE
    glVertex3f(-14,0,4);
    glVertex3f(-14,2,4);
    glVertex3f(-14,2,-4);
    glVertex3f(-14,0,-4);
    glEnd();

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(-14,0,4);
    glVertex3f(-14,2,4);
    glVertex3f(-10,2,7);
    glVertex3f(-10,0,7);
    glEnd();

    glBegin(GL_POLYGON);  //DOWN
    glVertex3f(-14,0,-4);
    glVertex3f(-14,2,-4);
    glVertex3f(-10,2,-7);
    glVertex3f(-10,0,-7);
    glEnd();

    //----------------------BACK BUMPPER-----------
     glColor3fv(B);

    glBegin(GL_POLYGON);  //CENTRE
    glVertex3f(12,0,3);
    glVertex3f(12,3,3);
    glVertex3f(12,3,-3);
    glVertex3f(12,0,-3);
    glEnd();

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(12,0,3);
    glVertex3f(12,3,3);
    glVertex3f(8,3,7);
    glVertex3f(8,0,7);
    glEnd();

    glBegin(GL_POLYGON);  //DOWN
    glVertex3f(12,0,-3);
    glVertex3f(12,3,-3);
    glVertex3f(8,3,-7);
    glVertex3f(8,0,-7);
    glEnd();
    
    //----------------------BONET-----------

    glColor3fv(M);

    glBegin(GL_POLYGON);  //CENTRE
    glVertex3f(-14,2,4);
    glVertex3f(-14,2,-4);
    glVertex3f(-7,4,-5);
    glVertex3f(-7,4,5);
    glEnd();

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(-14,2,4);
    glVertex3f(-10,2,7);
    glVertex3f(-7,4,5);
    glEnd();

    glBegin(GL_POLYGON);  //DOWN
    glVertex3f(-14,2,-4);
    glVertex3f(-10,2,-7);
    glVertex3f(-7,4,-5);
    glEnd();

    //-------------------------WINDSCREEN-------------
   
   glColor4fv(G);
    
    glBegin(GL_POLYGON);
     glVertex3f(-3,5,2);
    glVertex3f(-3,5,-2);
    glVertex3f(-7,4,-5);  //CENTRE
    glVertex3f(-7,4,5);
   
    
    glEnd();


     glBegin(GL_POLYGON);
     glVertex3f(-3,5,2);
    glVertex3f(0,6,3);
    glVertex3f(-7,4,5);  //C U
   
    
    glEnd();

     glBegin(GL_POLYGON);
     glVertex3f(-3,5,-2);
    glVertex3f(0,6,-3);
    glVertex3f(-7,4,-5);  //C D
   
    
    glEnd();


     glBegin(GL_POLYGON);  //TOP
    glVertex3f(-7,4,5);
    glVertex3f(0,6,3);
    glVertex3f(12,3,3);
    glEnd();

    glBegin(GL_POLYGON);  //DOWN
    glVertex3f(-7,4,-5);
    glVertex3f(0,6,-3);
    glVertex3f(12,3,-3);
    glEnd();
   
   //-----------------------ROOF-------------------
    glColor3fv(M);

    glBegin(GL_POLYGON);  //CENTRE
    glVertex3f(-3,5,2);
    glVertex3f(12,3,3);
    glVertex3f(12,3,-3);
    glVertex3f(-3,5,-2);
    glEnd();

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(-3,5,2);
    glVertex3f(12,3,3);
    glVertex3f(0,6,3);
    glEnd();

    glBegin(GL_POLYGON);  //DOWN
    glVertex3f(-3,5,-2);
    glVertex3f(12,3,-3);
    glVertex3f(0,6,-3);
    glEnd();


    //-----------------------SIDE BODY-------------------
   glColor3fv(M);

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(-10,2,7);
    glVertex3f(-7,4,5);
    glVertex3f(12,3,3);
    glEnd();

     glBegin(GL_POLYGON);  
    glVertex3f(8,3,7);
    glVertex3f(12,3,3);
    glVertex3f(-7,4,5);
    glEnd();

    //-------------

    glBegin(GL_POLYGON);  
    glVertex3f(-10,2,-7);
    glVertex3f(-7,4,-5);
    glVertex3f(12,3,-3);
    glEnd();

    glBegin(GL_POLYGON);  //DOWN
    glVertex3f(8,3,-7);
    glVertex3f(12,3,-3);
    glVertex3f(-7,4,-5);
    glEnd();


    //-----------------------SIDE BUMPPER------------------
   glColor3fv(M);

    glBegin(GL_POLYGON);  //TOP
    glVertex3f(-10,0,6);
    glVertex3f(-7,4,5);
    glVertex3f(8,3,6);
    glVertex3f(8,0,6);
    glEnd();

     glBegin(GL_POLYGON);  
   glVertex3f(-10,0,-6);
    glVertex3f(-7,4,-5);
    glVertex3f(8,3,-6);
    glVertex3f(8,0,-6);
    glEnd();




   


}


void CAR::WireFrame()
{  
    glColor3f(0,0,0);    

    glBegin(GL_LINE_LOOP);  //CENTRE
    glVertex3f(-10,0,6);
    glVertex3f(-10,0,-6);
    glVertex3f(8,0,-6);
    glVertex3f(8,0,6);
    glEnd();

    glBegin(GL_LINE_LOOP);  //FRONT BASE
    glVertex3f(-10,0,7);
    glVertex3f(-10,0,-7);
    glVertex3f(-14,0,-4);
    glVertex3f(-14,0,4);
    glEnd();

    glBegin(GL_LINE_LOOP);  //REAR BASE
    glVertex3f(8,0,7);
    glVertex3f(8,0,-7);
    glVertex3f(12,0,-3);
    glVertex3f(12,0,3);
    glEnd();

    //-------------------------- FRONT BUMPER--------------

    glBegin(GL_LINE_LOOP);  //CENTRE
    glVertex3f(-14,0,4);
    glVertex3f(-14,2,4);
    glVertex3f(-14,2,-4);
    glVertex3f(-14,0,-4);
    glEnd();

    glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(-14,0,4);
    glVertex3f(-14,2,4);
    glVertex3f(-10,2,7);
    glVertex3f(-10,0,7);
    glEnd();

    glBegin(GL_LINE_LOOP);  //DOWN
    glVertex3f(-14,0,-4);
    glVertex3f(-14,2,-4);
    glVertex3f(-10,2,-7);
    glVertex3f(-10,0,-7);
    glEnd();

    //----------------------BACK BUMPPER-----------

    glBegin(GL_LINE_LOOP);  //CENTRE
    glVertex3f(12,0,3);
    glVertex3f(12,3,3);
    glVertex3f(12,3,-3);
    glVertex3f(12,0,-3);
    glEnd();

    glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(12,0,3);
    glVertex3f(12,3,3);
    glVertex3f(8,3,7);
    glVertex3f(8,0,7);
    glEnd();

    glBegin(GL_LINE_LOOP);  //DOWN
    glVertex3f(12,0,-3);
    glVertex3f(12,3,-3);
    glVertex3f(8,3,-7);
    glVertex3f(8,0,-7);
    glEnd();
    
    //----------------------BONET-----------

    glBegin(GL_LINE_LOOP);  //CENTRE
    glVertex3f(-14,2,4);
    glVertex3f(-14,2,-4);
    glVertex3f(-7,4,-5);
    glVertex3f(-7,4,5);
    glEnd();

    glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(-14,2,4);
    glVertex3f(-10,2,7);
    glVertex3f(-7,4,5);
    glEnd();

    glBegin(GL_LINE_LOOP);  //DOWN
    glVertex3f(-14,2,-4);
    glVertex3f(-10,2,-7);
    glVertex3f(-7,4,-5);
    glEnd();

    //-------------------------WINDSCREEN-------------

    
    glBegin(GL_LINE_LOOP);
     glVertex3f(-3,5,2);
    glVertex3f(-3,5,-2);
    glVertex3f(-7,4,-5);  //CENTRE
    glVertex3f(-7,4,5);
   
    
    glEnd();


     glBegin(GL_LINE_LOOP);
     glVertex3f(-3,5,2);
    glVertex3f(0,6,3);
    glVertex3f(-7,4,5);  //C U
   
    
    glEnd();

     glBegin(GL_LINE_LOOP);
     glVertex3f(-3,5,-2);
    glVertex3f(0,6,-3);
    glVertex3f(-7,4,-5);  //C D
   
    
    glEnd();


     glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(-7,4,5);
    glVertex3f(0,6,3);
    glVertex3f(12,3,3);
    glEnd();

    glBegin(GL_LINE_LOOP);  //DOWN
    glVertex3f(-7,4,-5);
    glVertex3f(0,6,-3);
    glVertex3f(12,3,-3);
    glEnd();
   
   //-----------------------ROOF-------------------


    glBegin(GL_LINE_LOOP);  //CENTRE
    glVertex3f(-3,5,2);
    glVertex3f(12,3,3);
    glVertex3f(12,3,-3);
    glVertex3f(-3,5,-2);
    glEnd();

    glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(-3,5,2);
    glVertex3f(12,3,3);
    glVertex3f(0,6,3);
    glEnd();

    glBegin(GL_LINE_LOOP);  //DOWN
    glVertex3f(-3,5,-2);
    glVertex3f(12,3,-3);
    glVertex3f(0,6,-3);
    glEnd();


    //-----------------------SIDE BODY-------------------


    glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(-10,2,7);
    glVertex3f(-7,4,5);
    glVertex3f(12,3,3);
    glEnd();

     glBegin(GL_LINE_LOOP);  
    glVertex3f(8,3,7);
    glVertex3f(12,3,3);
    glVertex3f(-7,4,5);
    glEnd();

    //-------------

    glBegin(GL_LINE_LOOP);  
    glVertex3f(-10,2,-7);
    glVertex3f(-7,4,-5);
    glVertex3f(12,3,-3);
    glEnd();

    glBegin(GL_LINE_LOOP);  //DOWN
    glVertex3f(8,3,-7);
    glVertex3f(12,3,-3);
    glVertex3f(-7,4,-5);
    glEnd();


    //-----------------------SIDE BUMPPER------------------


    glBegin(GL_LINE_LOOP);  //TOP
    glVertex3f(-10,0,6);
    glVertex3f(-7,4,5);
    glVertex3f(8,3,6);
    glVertex3f(8,0,6);
    glEnd();

     glBegin(GL_LINE_LOOP);  
   glVertex3f(-10,0,-6);
    glVertex3f(-7,4,-5);
    glVertex3f(8,3,-6);
    glVertex3f(8,0,-6);
    glEnd();



}



void CAR::Tyre()
{

  GLUquadricObj *p = gluNewQuadric();
  
   glColor3f(0.04, 0.04, 0.04);
  gluCylinder(p,10,10,5,100,100);

  
   glColor3f(0.02,0.02,0.02);       
  gluDisk(p,7,10,100,100);

 glTranslatef(0,0,-0.2);  

 glColor3f(0.439, 0.502, 0.565); 
  gluDisk(p,0,3,100,100);

                            //WHEEL SPOILERS
  glColor3f(0.439, 0.502, 0.565);
  gluPartialDisk(p,0,7,100,100,0,40);
  gluPartialDisk(p,0,7,100,100,72,40);
  gluPartialDisk(p,0,7,100,100,144,40);
  gluPartialDisk(p,0,7,100,100,216,40);
  gluPartialDisk(p,0,7,100,100,288,40);

  glTranslatef(0,0,-0.2);     //TUBE PATTERN
  glColor3f(0.439, 0.502, 0.565);
  gluPartialDisk(p,8,9,100,100,0,60);
  gluPartialDisk(p,8,9,100,100,120,60);
  gluPartialDisk(p,8,9,100,100,240,60);
 
}


void CAR::Wheels(float Aw)
{
	glPushMatrix();
  glTranslatef(-7.5,1,-7);
  glScalef(0.2,0.2,0.2);
  glRotatef(Aw,0,0,1);
  Tyre();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.5,1,-7.5);
  glScalef(0.2,0.2,0.2);
  glRotatef(Aw,0,0,1);
  Tyre();
  glPopMatrix();


  glPushMatrix();
  glTranslatef(-7.5,1,7);
  glScalef(0.2,0.2,0.2);
  glRotatef(180,0,1,0);
  glRotatef(-Aw,0,0,1);
  Tyre();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.5,1,7.5);
  glScalef(0.2,0.2,0.2);
  glRotatef(180,0,1,0);
  glRotatef(-Aw,0,0,1);
  Tyre();
  glPopMatrix();


}

//------------------------------------------------------

void CAR::SelectModel(int i)
{
	switch(i)
	{
		case 1:  Model1();  break;
		case 2:  Model2();  break;
		case 3:  Model3();  break;
		case 4:  Model4();  break;
	}
}


void CAR::DrawCar(float X,float Y,float Z,float A,float Aw)
{
   
   glPushMatrix();  //--------------------

   glTranslatef(X,Y,Z);
   glRotatef(-A,0,1,0);
   glRotatef(180,0,1,0);

     WireFrame();
     Lights();
     Paint();
     Wheels(Aw);

   glPopMatrix(); //----------------------
   
   glFlush();  


}


//==========================================================================
