#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>


#include "ROAD.h"
#include "MYUTILITY.h"

using namespace std;




//--------------------------ROAD--------------------------------------------------




void RoadSlab()
{
    float L=40;
    float B=40;
    float b=0.5;
    float l=4;
    float fh=0.7;

    glColor3f(0.184, 0.310, 0.310);             //Concrete
    RECT(L,B+6);

    glPushMatrix();
    glTranslatef(0,0.5,0);
    glColor3f(1,1,0);          //Middle Yellow Strip
    RECT(L,b);
    glPopMatrix();

    glColor3f(1,1,1);       //WhiteStrips

    glPushMatrix();
    glTranslatef(-B/2,0.5,0);
    RECT(l,b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(B/2,0.5,0);
    RECT(l,b);
    glPopMatrix();

    SetC2(0.871,0.722,0.529);
     SetC1(0.804,0.522,0.247);     //Footpath1
   
    glPushMatrix();
    glTranslatef(-(5*B/4),0,L/2);
    CUBOID(L,B/3,fh);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((5*B/4),0,L/2);
    CUBOID(L,B/3,fh);
    glPopMatrix();
    
    SetC2(0.957,0.643,0.376); 
    SetC1(0.804,0.522,0.247);         //Footpath2

    glPushMatrix();
    glTranslatef(-(5*B/4),0,-L/2);
    CUBOID(L,B/3,fh);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((5*B/4),0,-L/2);
    CUBOID(L,B/3,fh);
    glPopMatrix();

   







}



void RoadXc(float Xc,float Z1,float Z2)
{
   float i;

   for(i=Z1;i<=Z2;i=i+80)
   {
       glPushMatrix();
       glTranslatef(Xc,0.5,i);
       RoadSlab();
       glPopMatrix();

     
   }

   


   
}


void RoadZc(float Zc,float X1,float X2)
{
   float i;

   for(i=X1;i<=X2;i=i+80)
   {
       glPushMatrix();
       glTranslatef(i,0.5,Zc);
       glRotatef(90,0,1,0);
       RoadSlab();
       glPopMatrix();

      
   }
}


void FixJunction(float a,float b)
{
    SetC1(0,0,0);
   SetC2(0,0,0);
   glPushMatrix();
   glTranslatef(a,1,b);
   glRotatef(45,0,1,0);
   CUBOID(70,70,1);
   glPopMatrix();
   
}




