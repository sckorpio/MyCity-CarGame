#include <stdio.h> 
#include <math.h>
#include <iomanip>
#include <GL/glut.h>
#include <iostream>
#include "MOTION.h"
using namespace std;


MOTION::MOTION()
{
	X=850;  Z=-1900;  Y=0;
	theta=180;
	ux=-1; uz=0;
    Speed=0;
	Acc=0;  Friction=200;  
	t=20;
}

void MOTION::UpdateVector()
{
   ux=cos(theta*(3.14/180));
   uz=sin(theta*(3.14/180));
}

void MOTION::FreeMotion()
{
    X=X+(ux*Speed)*(t/1000);
    Z=Z+(uz*Speed)*(t/1000);

    
    if(Speed>0)
    {  
       if(Speed<Friction*(t/1000))
         Speed=0; 
       
       else
       Speed=Speed-Friction*(t/1000);
    }

    if(Speed<0)
    {  
       if(Speed>-Friction*(t/1000))
         Speed=0; 
       
       else
       Speed=Speed+Friction*(t/1000);
   }
}

void MOTION::UpdateAcc()
{
   if(abs(Speed)<200)
    Acc=90;
   
   else if(abs(Speed)>200&&abs(Speed)<400)
   Acc=70;

  else if(abs(Speed)>400&&abs(Speed)<600)
   Acc=50;

   else if(abs(Speed)>600&&abs(Speed)<800)
   Acc=30;

  else if(abs(Speed)>800&&abs(Speed)<1000)
   Acc=10;
  
  else
  Acc=0;

}

  

void MOTION::DrawVector()
{
    glColor3f(0,1,0);
    glLineWidth(10);

    glBegin(GL_LINES);
    glVertex3f(X,Y+7,Z);
    glVertex3f(X+30*ux,Y+7,Z+30*uz);
    glEnd();

    glLineWidth(1);

}




  


