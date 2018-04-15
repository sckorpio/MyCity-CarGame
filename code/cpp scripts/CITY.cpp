#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "CITY.h"
#include "MYUTILITY.h"
#include "BUILDING.h"
#include "ROAD.h"
#include "CAR.h"
#include "MOTION.h"
#include "CAMERA.h"

using namespace std;



//-------------------objects in city--------------


MOTION m;
CAR car;
CAMERA cam;



int count=0;

int finish=-1;

float omega=0;
float wa=0;

int T;

int state=0;

int s=1;


//---------  palace ------------------------------------------------------------------------------------------


void Palace()
{
  SetC1(0.914,0.588,0.478);               //PALCE
  SetC2(1.0,0.627,0.478);
  SetWin(0.698,0.133,0.133,6,2,3,2);
   
   
   glPushMatrix();
   glTranslatef(0,0,0);
   Building(200,200,70);

   glPopMatrix();


   glPushMatrix();
   glTranslatef(100,0,100);
   Building(50,50,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,0,-100);
   Building(50,50,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,0,100);
   Building(50,50,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,0,-100);
   Building(50,50,100);
   glPopMatrix();

  
//----------------------------------

   SetWin(0.698,0.133,0.133,6,2,3,2);              //domes

    glPushMatrix();
   glTranslatef(0,70,0);
   twistsearsTower(100,100,20,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,100,100);
  twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,100,-100);
   twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,100,100);
   twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,100,-100);
   twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

  //------------------------------------------------------
    
   glPushMatrix();                      //gate
   glTranslatef(0,25,-102);
   glRotatef(90,1,0,0);
   SetC1(0.698,0.133,0.133);
   SetC2(0.698,0.133,0.133);
   CUBOID(50,50,4);
   glPopMatrix();

}





void palacecones()
{
   SetC1(0.914,0.588,0.478);               //PALCE
  SetC2(1.0,0.627,0.478);
  SetWin(0.698,0.133,0.133,3,2,3,2);
   
  
    glPushMatrix();
    glTranslatef(-60,0,-250);
    twistsearsTower(25,25,10,5,2.5,0);
    glPopMatrix();

   glPushMatrix();
   glTranslatef(60,0,-250);
  twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-60,0,-350);
  twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(60,0,-350);
   twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-60,0,-450);
    twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(60,0,-450);
   twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();
   
  
}

//======================================================
//======================================================

void BigBridge()
{
   SetC1(0.69,0.769,0.871);               //CADET BLUE
  SetC2(0.373,0.620,0.627);
 
   glPushMatrix();
  glTranslatef(0,-15,50);
  CUBOID(25,1660,20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-15,-50);
  CUBOID(25,1660,20);
  glPopMatrix();

  //-------------------------------------

  glPushMatrix();                 //LEFT PILLARS
  glTranslatef(-450,-180,50);
  CUBOID(25,25,400);
  glPopMatrix();

 glPushMatrix();
  glTranslatef(-450,-180,-50);
  CUBOID(25,25,400);
  glPopMatrix();

  glPushMatrix();                 //RIGHT PILLARS
  glTranslatef(450,-180,50);
  CUBOID(25,25,400);
  glPopMatrix();

 glPushMatrix();
  glTranslatef(450,-180,-50);
  CUBOID(25,25,400);
  glPopMatrix();

 //-----------------------------------------------

   glPushMatrix();                 //LEFT PILLARS JOINT
  glTranslatef(-450,180,0);
  CUBOID(75,25,25);
  glPopMatrix();

 glPushMatrix();
  glTranslatef(450,180,0);    //RIGHT PILLAR JOINT
  CUBOID(75,25,25);
  glPopMatrix();

//WIRES

  int i;
  
  float k;

  k=800;

  glLineWidth(3);
  glColor3f(0,0,0);

  for(i=0;i<10;i++)
  {
    glBegin(GL_LINES);
    glVertex3f(450,200,-50);
    glVertex3f(k,0,-50);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(450,200,50);
    glVertex3f(k,0,50);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-450,200,-50);
    glVertex3f(-k,0,-50);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-450,200,50);
    glVertex3f(-k,0,50);
    glEnd();


    k=k-100;

  }

  glLineWidth(1);



}


void SmallBridge()
{
   SetC1(0.545,0.271,0.075);               //GOLD -B2            
  SetC2(0.627,0.322,0.176);                 
  SetWin(0.855,0.647,0.125,5,3,2,2);
 
   glPushMatrix();
  glTranslatef(0,-15,50);
  Building(850,25,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-15,-50);
  Building(850,25,25);
  glPopMatrix();

 

  //-------------------------------------

   glPushMatrix();                  //PILLARS
  glTranslatef(250,-150,50);
  Building(40,25,250);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-250,-150,-50);
  Building(40,25,250);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(250,-150,-50);
  Building(40,25,250);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-250,-150,50);
  Building(40,25,250);
  glPopMatrix();

//------------------PILLAR JOINTS

  glPushMatrix();
  glTranslatef(-250,80,0);
  Building(30,100,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(250,80,0);
  Building(30,100,25);
  glPopMatrix();

//---------------------------

   glPushMatrix();                  
  glTranslatef(250,100,50);
  twistsearsTower(40,25,10,5,2.5,0);
  glPopMatrix();

   glPushMatrix();                  
  glTranslatef(250,100,-50);
  twistsearsTower(40,25,10,5,2.5,0);
  glPopMatrix();

   glPushMatrix();                  
  glTranslatef(-250,100,50);
  twistsearsTower(40,25,10,5,2.5,0);
  glPopMatrix();

   glPushMatrix();                  
  glTranslatef(-250,100,-50);
  twistsearsTower(40,25,10,5,2.5,0);
  glPopMatrix();
  

  //-----------------------------------------

 

   glPushMatrix();
  glTranslatef(170,40,50);
   glRotatef(30,0,0,1);
  Building(200,15,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(170,40,-50);
   glRotatef(30,0,0,1);
  Building(200,15,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(300,40,50);
   glRotatef(-40,0,0,1);
  Building(140,15,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(300,40,-50);
   glRotatef(-40,0,0,1);
  Building(140,15,25);
  glPopMatrix();
  
  //-----------------------------------------

 

   glPushMatrix();
  glTranslatef(-170,40,50);
   glRotatef(-30,0,0,1);
  Building(200,15,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-170,40,-50);
   glRotatef(-30,0,0,1);
  Building(200,15,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-300,40,50);
   glRotatef(40,0,0,1);
  Building(140,15,25);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-300,40,-50);
   glRotatef(40,0,0,1);
  Building(140,15,25);
  glPopMatrix();
 



}


void A()
{
    //---------------------------------------------

   SetC1(0.69,0.769,0.871);               //CADET BLUE
  SetC2(0.373,0.620,0.627);
  SetWin(0.118,0.565,1.0,4,12,3,2);              //A1
   glPushMatrix();
  glTranslatef(-2800,0,1800);
   twistsearsTower(150,150,30,30,5,8);          //TWISTED
   glPopMatrix();


   //-------------------------------------------------------
   

    SetC1(0.69,0.769,0.871);               //WHITE
  SetC2(0.678,0.847,0.902);
  SetWin(0,0,0,10,4,2,10); 
  glPushMatrix();
  glTranslatef(-3275,0,1800);
   Building(100,200,300);
   glPopMatrix();

   //-----------------------------------------

    SetC1(0.275,0.510,0.706);               //CADET+STEEL-   TWIN
  SetC2(0.373,0.620,0.627);
    SetWin(0,0,0.8,5,10,8,3);
   
   glPushMatrix();
   glTranslatef(-3100,0,1850);
   Building(100,100,500);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-2970,0,1850);
   Building(100,100,200);
   glPopMatrix();

   SetC1(0.275,0.510,0.906);               //CADET+STEEL-   TWIN
  SetC2(0.273,0.620,0.927);
  SetWin(0,0,1,6,4,2,2);

   glPushMatrix();
   glTranslatef(-3100,0,1350);
   Building(100,100,150);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-2970,0,1350);

   Building(100,100,150);
   glPopMatrix();

   //---------------------------------------

   SetC1(0.741,0.718,0.420);               //OLIVE -B1               
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.373,0.620,0.627,6,6,2,3);
  float arr[10]={30,30,28,4};

   glPushMatrix();
  glTranslatef(-3250,0,1400);
   searsTower(170,200,4,arr,4);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-2800,0,1350);
   glRotatef(45,0,1,0);
   Building(100,100,80);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-3000,0,1600);
   Building(200,200,100);
   glPopMatrix();

   

}

void B()
{
   SetC1(0.275,0.510,0.706);               //CADET+STEEL-B4
  SetC2(0.373,0.620,0.627);
  SetWin(0.0,0.808,0.820,5,15,5,5);
   glPushMatrix();                       //B1
  glTranslatef(-3750,0,1050);
   Building(150,150,550);
   glPopMatrix();

   SetC1(0.741,0.718,0.420);               //OLIVE -B1               
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.373,0.620,0.627,10,4,4,5);

  glPushMatrix();
   glTranslatef(-3700,0,700);
   Building(200,300,100);
   glPopMatrix();


   SetC1(0.69,0.769,0.871);               //CADET BLUE         PETRONAS
  SetC2(0.373,0.620,0.627);
  SetWin(0,0,1,8,3,2,3);
   glPushMatrix();
  glTranslatef(-3400,0,600);
   petronas();
   glPopMatrix();


   SetC1(0.69,0.769,0.871);               //WHITE
  SetC2(0.678,0.847,0.902);
  SetWin(0,0,0,10,6,3,3); 
  glPushMatrix();
  glTranslatef(-2800,0,800);   //BIG OFFICE
   Building(100,600,60);
   glPopMatrix();

   glPushMatrix();
  glTranslatef(-3000,0,1075);
   Building(300,100,60);
   glPopMatrix();

   glPushMatrix();
  glTranslatef(-3000,0,500);
   Building(300,100,60);
   glPopMatrix();

   glPushMatrix();
  glTranslatef(-3070,2,800);
   glColor3f(0,0.392,0);
   RECT(200,200);
   glPopMatrix();


   SetC1(0.69,0.769,0.871);               //WHITE
  SetC2(0.678,0.847,0.902);
  SetWin(0,0,0,6,3,2,3); 
  glPushMatrix();
  glTranslatef(-3250,0,900);
   Building(50,50,200);
   glPopMatrix();

   glPushMatrix();
  glTranslatef(-3250,0,1000);
   Building(50,50,200);
   glPopMatrix();

   glPushMatrix();
  glTranslatef(-3250,0,800);
   Building(50,50,200);
   glPopMatrix();

  float arr1[10]={70,50,40,30,20,10,15,25,15,10};
   
SetWin(0,0,0,8,4,2,7); 
   glPushMatrix();
  glTranslatef(-3600,0,2200);
   searsTower(200,100,10,arr1,10);
   glPopMatrix();

  
  SetC1(0.275,0.510,0.706);               //CADET+STEEL-B4
  SetC2(0.373,0.620,0.627);
  SetWin(0.0,0.808,0.820,4,8,2,2);
  float arr[10]={100,90,80,70,60,50,40,30,40,50};
  
   glPushMatrix();                       //B1
  glTranslatef(650,0,1200);
   glRotatef(45,0,1,0);
   searsTower(150,100,10,arr,9);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(650,0,1200);
   glRotatef(-45,0,1,0);
   searsTower(150,100,10,arr,9);
   glPopMatrix();


}

void dualcolorbuilding(float l,float b,float h)
{
	for(int i=0;i<10;i++)
   {  

   	  if(i%2==0)
   	  {
   	  	SetC1(0.69,0.769,0.871);               //WHITE
        SetC2(0.678,0.847,0.902);
       
   	  }

   	  else
   	  {
   	  	  SetC1(0.69,0.769,0.871);               //CADET BLUE         PETRONAS
          SetC2(0.373,0.620,0.627);
          

   	  }

   	  glPushMatrix();
   	  glTranslatef(0,i*h,0);
   	  Building(l,b,h);
   	  glPopMatrix();

   }


}

void C()
{  
     SetC1(0.69,0.769,0.871);               //CADET BLUE         PETRONAS
  SetC2(0.373,0.620,0.627);
  SetWin(0,0,1,5,5,5,5);

   SetC1(0.69,0.769,0.871);               //WHITE
  SetC2(0.678,0.847,0.902);
  SetWin(0,0,0,4,6,2,2); 

  glPushMatrix();
  glTranslatef(-2300,0,-100);

  SetWin(0.3,0.3,0.3,15,4,2,2);

   for(int i=0;i<10;i++)
   {  

   	  if(i%2==0)
   	  {
   	  	SetC1(0.69,0.769,0.871);               //WHITE
        SetC2(0.678,0.847,0.902);
        
   	  }

   	  else
   	  {
   	  	  SetC1(0.69,0.769,0.871);               //CADET BLUE         PETRONAS
          SetC2(0.373,0.620,0.627);
          
   	  }

   	  glPushMatrix();
   	  glTranslatef(0,i*15,0-i*15);
   	  Building(100-i*10,300-i*30,15);
   	  glPopMatrix();

      
   	  glPushMatrix();
   	  glTranslatef(120,0,-230);
   	  glRotatef(120,0,1,0);
   	  glTranslatef(0,i*15,0-i*15);
   	  Building(100-i*10,300-i*30,15);
   	  glPopMatrix();

   	 glPushMatrix();
   	  glTranslatef(-120,0,-230);
   	  glRotatef(-120,0,1,0);
   	  glTranslatef(0,i*15,0-i*15);
   	  Building(100-i*10,300-i*30,15);
   	  glPopMatrix();
   }

   glPopMatrix();

   SetWin(0,0,1,10,3,2,4);
   glPushMatrix();
   glTranslatef(750,0,700);
   dualcolorbuilding(100,200,40);
   glPopMatrix();


   SetWin(0.0,0.808,0.820,100,10,2,4);
   glPushMatrix();
   glTranslatef(-450,0,1500);
   dualcolorbuilding(200,100,40);
   glPopMatrix();




}

void makeHuts()
{
	//-----------------------------------

   SetC1(0.741,0.718,0.420);               //OLIVE -B1               
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.545,0.271,0.075,1.5,0,0,5);

 
   glPushMatrix();
   glTranslatef(100,0,-1200);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(200,0,-1200);
   Hut(45,30,30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,0,-1300);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(200,0,-1300);
   Hut(45,30,10);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,0,-1200);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-200,0,-1200);
   Hut(45,30,30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-300,0,-1300);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-200,0,-1300);
   Hut(45,30,10);
   glPopMatrix();


    glPushMatrix();
    glTranslatef(100,0,-1300);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(930,0,-500);
   Hut(45,30,10);
   glPopMatrix();

   glPushMatrix();
    glTranslatef(940,0,-600);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
    glTranslatef(750,0,-700);
   Hut(45,30,30);
   glPopMatrix();

   glPushMatrix();
    glTranslatef(750,0,-800);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(750,0,-900);
   Hut(45,30,10);
   glPopMatrix();

   //-------------------------DOUBLE

  glPushMatrix();
   glTranslatef(650,0,-200);
   
   Hut(200,200,30);
   
   glPushMatrix();
   glTranslatef(0,40,0);
   Hut(120,120,20);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0,70,0);
   Hut(60,60,20);
   glPopMatrix();

  glPopMatrix(); 

   //--------------------------------------

   SetC1(0.69,0.769,0.871);               //WHITE
  SetC2(0.678,0.847,0.902);
  SetWin(0.373,0.620,0.627,1,0,0,5); 

  glPushMatrix();
   glTranslatef(600,0,-1200);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(700,0,-1200);
   Hut(45,30,30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(700,0,-1300);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(600,0,-1300);
   Hut(45,30,10);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(650,0,-1100);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(750,0,-1100);
   Hut(45,30,30);
   glPopMatrix();

   //---------------

   glPushMatrix();
   glTranslatef(-600,0,-1200);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-700,0,-1200);
   Hut(45,30,30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-700,0,-1300);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-600,0,-1300);
   Hut(45,30,10);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-650,0,-1100);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-750,0,-1100);
   Hut(45,30,30);
   glPopMatrix();

   //------

    SetC1(0.871,0.722,0.529);               //SAND
  SetC2(0.824,0.706,0.549);
  SetWin(0.627,0.322,0.176,1,0,0,5); 


   glPushMatrix();
   glTranslatef(-600,0,-800);
   Hut(35,50,20);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-700,0,-800);
   Hut(15,70,30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-700,0,-700);
   Hut(35,70,50);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-600,0,-700);
   Hut(45,60,40);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-650,0,-600);
   Hut(70,50,30);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-750,0,-600);
   Hut(70,50,50);
   glPopMatrix();


}

void makeBuildings()
{
     //---------------------------------------------
     A();
   //-------------------------------------------------------
     B();

     C();

     makeHuts();



   Palace();
   palacecones();

float g=-2;


  glColor3f(0.133,0.545,0.133);          //ground

  glBegin(GL_POLYGON);       //A
  glVertex3f(-1050,g,-2050);
  glVertex3f(1050,g,-2050);
  glVertex3f(1050,g,1600);
  glVertex3f(-1050,g,1600); 
  glEnd();

  glBegin(GL_POLYGON);      //B
  glVertex3f(-2550,g,550);
  glVertex3f(-2550,g,-750);
  glVertex3f(-1850,g,-750);
  glVertex3f(-1850,g,550);
  glEnd();

  glBegin(GL_POLYGON);      //C
  glVertex3f(-2550,g,-750);
  glVertex3f(-2550,g,2550);
  glVertex3f(-4050,g,2550);
  glVertex3f(-4050,g,-750);
  glEnd();

              
  

//color change-------------------
  glColor3f(0.957,0.643,0.376);

   glBegin(GL_POLYGON);       //1 BEACH
  glVertex3f(-1050,g,-2050);
  glVertex3f(1050,g,-2050);
  glVertex3f(1050+400,g-200,-2050-400);
  glVertex3f(-1050-50,g-200,-2050-50); 
  glEnd();

  glBegin(GL_POLYGON);       //3
   glVertex3f(-1050-50,g-200,1600+50); 
 glVertex3f(-1050,g,1600); 
 glVertex3f(1050,g,1600);
  glVertex3f(1050+400,g-200,1600+400); 
  glEnd();



   glBegin(GL_POLYGON);       //8
  glVertex3f(-2550,g,2550);
  glVertex3f(-2550+200,g-200,2550+200);
  glVertex3f(-4050-200,g-200,2550+200); 
  glVertex3f(-4050,g,2550);
  glEnd();

   glBegin(GL_POLYGON);       //6
  glVertex3f(-1850,g,-750);
  glVertex3f(-1850+50,g-200,-750-50);
  glVertex3f(-4050-200,g-200,-750-50); 
  glVertex3f(-4050,g,-750);
  glEnd();

   glBegin(GL_POLYGON);       //10
  glVertex3f(-1850,g,550);
  glVertex3f(-1850+50,g-200,550+50);
  glVertex3f(-2550-100,g-200,550+50); 
  glVertex3f(-2550,g,550);
  glEnd();

  

//-----------------------------------

   glColor3f(0.804,0.522,0.247);


   glBegin(GL_POLYGON);       //2
  glVertex3f(1050,g,-2050);
  glVertex3f(1050+400,g-200,-2050-400);
  glVertex3f(1050+400,g-200,1600+400); 
  glVertex3f(1050,g,1600);
  glEnd();

  glBegin(GL_POLYGON);       //7
  glVertex3f(-4050,g,2550);
  glVertex3f(-4050-200,g-200,2550+200);
  glVertex3f(-4050-200,g-200,-750-50); 
  glVertex3f(-4050,g,-750); 
  glEnd();

  glBegin(GL_POLYGON);       //9
  glVertex3f(-2550,g,2550);
  glVertex3f(-2550+50,g-200,2550+200);
  glVertex3f(-2550+50,g-200,550-50); 
  glVertex3f(-2550,g,550);
  glEnd();

//--------------------------------


 

//color change-------------------

 glColor3f(0.561,0.737,0.561);

 
glBegin(GL_POLYGON);       //5
  glVertex3f(-1850,g,-750);
  glVertex3f(-1850,g,550);
  glVertex3f(-1850+50,g-200,550+50);
  glVertex3f(-1850+50,g-200,-750-50); 
  glEnd();

  
glBegin(GL_POLYGON);       //4
   glVertex3f(-1050,g,-2050);
  glVertex3f(-1050-50,g-200,-2050-50); 
   glVertex3f(-1050-50,g-200,1600+50); 
 glVertex3f(-1050,g,1600); 
  glEnd();



//color change-------------------

 glColor3f(0,0.808,0.820);

 glBegin(GL_POLYGON);       //OCEAN
   glVertex3f(-5000,g-100,-5000);
  glVertex3f(-5000,g-100,5000); 
   glVertex3f(5000,g-100,5000); 
 glVertex3f(5000,g-100,-5000); 
  glEnd();


  


  glPushMatrix();
  glTranslatef(-1762,0,1370);
  BigBridge();
  glPopMatrix();

   glPushMatrix();
  glTranslatef(-1450,0,-600);
  SmallBridge();
  glPopMatrix();
}

//----------------------------------ROADS-----------------------------------------


void makeRoads()
{
  RoadXc(200,-200,200);
        RoadXc(-200,-200,200);
        RoadZc(200,-200,200);
        RoadZc(-200,-200,200);

//---------------XC ONES------

       RoadXc(850,-1900,1400);  //IN A
        RoadXc(0,-1900,1400);
       RoadXc(-900,-1900,1400);

       RoadXc(-1950,-600,450);   //IN B
        RoadXc(-2625,-600,2440);
       RoadXc(-3400,-600,2440);
        RoadXc(-3900,-600,2440);

//-----------Z C ONES-----------

       RoadZc(-1900,-900,900);      //IN A
        RoadZc(-1000,-900,900);
        RoadZc(0,-900,900);
        RoadZc(1370,-2650,900);   // BIG BRIDGE ROAD
         RoadZc(1000,-900,900);

      RoadZc(400,-3900,-1950);      //IN B
        RoadZc(1200,-3900,-2600);
        RoadZc(2000,-3900,-2600);
        RoadZc(-600,-3900,-825);   // SMALL BRIDGE ROAD
         RoadZc(2400,-3900,-2600);
            
       
}

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------


