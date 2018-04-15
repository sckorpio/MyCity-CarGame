#include <stdio.h> 
#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "BUILDING.h"
#include "MYUTILITY.h"

using namespace std;


//--------------------------------BUILDING FUNCTIONS-----------------------------------------------

//--------------------------------BUILDING FUNCTIONS-----------------------------------------------


  float WC[3];   //window color
  float Wx;  //window breadth
  float Wy;
  float Gx;  //gap between windows
  float Gy;

void Win(float l,float b,float h)
{
   l=l-1;  b=b-1; h=h-1;
    
   glColor3fv(WC);

   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);                  //left
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();
  
  
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

  

   
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();

   

}



void SetWin(float x,float y,float z,float p,float q,float r,float s)
{
   WC[0]=x;
   WC[1]=y;
   WC[2]=z;

   Wx=p;  Wy=q;
   Gx=r;  Gy=s;
}


void Building(float l,float b,float h)
{
   int i=0;
   int X; int rem;  int p=0; int q=0; int r=0;

   while(p==0||q==0||r==0)
   {
       glColor3fv(C1);  
    
       // front back ------------------ STRIPS--------------------------------------------------------------------------------
     if(p==0)
    {
                                          
      X=(-l/2)+i*(Gx+Wx);     

      if((l-i*(Gx+Wx))>Gx)
      { 
          
        glBegin(GL_POLYGON);          
        glVertex3f(X,0,-b/2);
        glVertex3f(X+Gx,0,-b/2);
        glVertex3f(X+Gx,h,-b/2);
        glVertex3f(X,h,-b/2);
        glEnd();

         glBegin(GL_POLYGON);          
        glVertex3f(X,0,b/2);
        glVertex3f(X+Gx,0,b/2);
        glVertex3f(X+Gx,h,b/2);
        glVertex3f(X,h,b/2);
        glEnd();
      }

      else
       {  
        
           rem=(l-i*(Gx+Wx));
         
           glBegin(GL_POLYGON);          
        glVertex3f(X,0,-b/2);
        glVertex3f(X+rem,0,-b/2);
        glVertex3f(X+rem,h,-b/2);
        glVertex3f(X,h,-b/2);
        glEnd();

         glBegin(GL_POLYGON);          
        glVertex3f(X,0,b/2);
        glVertex3f(X+rem,0,b/2);
        glVertex3f(X+rem,h,b/2);
        glVertex3f(X,h,b/2);
        glEnd();

       p=1;

      }

   }


    //----------------------------------left right--------------------------STRIPS----------------------------------------------
     if(q==0)                                  
   {
       glColor3fv(C2);  

      X=(-b/2)+i*(Gx+Wx);     

      if((b-i*(Gx+Wx))>Gx)
      { 
          
         

        glBegin(GL_POLYGON);          
        glVertex3f(-l/2,0,X);
        glVertex3f(-l/2,0,X+Gx);
        glVertex3f(-l/2,h,X+Gx);
        glVertex3f(-l/2,h,X);
        glEnd();

        glBegin(GL_POLYGON);          
        glVertex3f(l/2,0,X);
        glVertex3f(l/2,0,X+Gx);
        glVertex3f(l/2,h,X+Gx);
        glVertex3f(l/2,h,X);
        glEnd();
      }

      else
       {  
        
           rem=(b-i*(Gx+Wx));
         
          glBegin(GL_POLYGON);          
        glVertex3f(-l/2,0,X);
        glVertex3f(-l/2,0,X+rem);
        glVertex3f(-l/2,h,X+rem);
        glVertex3f(-l/2,h,X);
        glEnd();

        glBegin(GL_POLYGON);          
        glVertex3f(l/2,0,X);
        glVertex3f(l/2,0,X+rem);
        glVertex3f(l/2,h,X+rem);
        glVertex3f(l/2,h,X);
        glEnd();

       q=1;

      }


    

   }




     // ---------------------------------------------------horizontals---------------------------------------STRIPS

       if(r==0)                             
   {
       glColor3fv(C2);  

     

      if((h-i*(Gy+Wy))>Gy)
      { 
         glPushMatrix();
          glTranslatef(0,i*(Gy+Wy),0);

       glColor3fv(C1);
   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,Gy,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,Gy,-b/2);
   glEnd();

   
   


   glColor3fv(C2);
   glBegin(GL_POLYGON);                  //left
   glVertex3f(-l/2,Gy,-b/2);
   glVertex3f(-l/2,Gy,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

   
   glColor3fv(C1);
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,Gy,b/2);
   glVertex3f(l/2,Gy,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

  

   glColor3fv(C2);
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,Gy,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,Gy,-b/2);
   glEnd();

   glPopMatrix();

   
      }

      else
       {  
        
           rem=(h-i*(Gy+Wy));
         
           glPushMatrix();
          glTranslatef(0,i*(Gy+Wy),0);

       glColor3fv(C1);
   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,rem,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,rem,-b/2);
   glEnd();

   
   


   glColor3fv(C2);
   glBegin(GL_POLYGON);                  //left
   glVertex3f(-l/2,rem,-b/2);
   glVertex3f(-l/2,rem,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

   
   glColor3fv(C1);
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,rem,b/2);
   glVertex3f(l/2,rem,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

  

   glColor3fv(C2);
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,rem,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,rem,-b/2);
   glEnd();

   glPopMatrix();


       r=1;

   }


    

 }

   i++;


}

 

   
 //------------------------------------------------------------

   glColor3f(0.69,0.769,0.871);
   glBegin(GL_POLYGON);         //top
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,h,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glEnd();

//----------------------------------------------------------------

  
 
  Win(l,b,h);

}



//-----------------------------BUILDING TYPES SKYSCRAPERS---------------------------------



void twistsearsTower(float l,float b,int blocks,float h,float d,float dangle)
{

  int i=1;

  
  float th;

  th=0;  float ax=0;

  for(i=0;i<blocks;i++)
  {   
    glPushMatrix();
    glTranslatef(0,th,0);
    glRotatef(ax,0,1,0);
      Building(l,b,h);
      glPopMatrix();
      th=th+h;
      l=l-d;  b=b-d;

      ax=ax+dangle;
  }
}

void searsTower(float l,float b,int blocks,float BH[20],float d)
{

  int i=1;

  
  float th;

  th=0;  
  for(i=0;i<blocks;i++)
  {   
    glPushMatrix();
    glTranslatef(0,th,0);
      Building(l,b,BH[i]);
     // cout<<l<<" "<<b<<" "<<BH[i]<<endl;
      glPopMatrix();
      th=th+BH[i];
      l=l-d;  b=b-d;

  }
}


void petronas()
{  
   float arr[20]={60,55,50,40,30,25,24,23,22,21,20,38,24,10,10,14,18,22,26,30};

   glPushMatrix();
   glTranslatef(-110,0,0);
   glRotatef(45,0,1,0);
    searsTower(75,75,20,arr,3.6);
    glPopMatrix();

    glPushMatrix();
   glTranslatef(110,0,0);
   glRotatef(45,0,1,0);
    searsTower(75,75,20,arr,3.6);
    glPopMatrix();

    glPushMatrix();
   glTranslatef(0,250,0);
    Building(150,20,20);
    glPopMatrix();




}

//-------------------------------------------------------hut--------------------------------------------------------------

void Hut(float l,float b,float h)
{
	 glColor3f(1,0,0);
   glBegin(GL_POLYGON);            //bottom
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,0,+b/2);
   glEnd();


   glColor3fv(C1);
   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
   glColor3f(0,0,0);
   glBegin(GL_POLYGON);                 //front gate
   glVertex3f(l/4,h/3,-b/2-1);
   glVertex3f(l/4,0,-b/2-1);
   glVertex3f(-l/4,0,-b/2-1);
   glVertex3f(-l/4,h/3,-b/2-1);
   glEnd();


   glColor3fv(C2);
   glBegin(GL_POLYGON);                  //left
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

    glColor3f(0,0,0);
   glBegin(GL_POLYGON);                 //LEFT gate
   glVertex3f(-l/2-1,h/2,-b/4);
   glVertex3f(-l/2-1,h/2,b/4);
   glVertex3f(-l/2-1,0,b/4);
   glVertex3f(-l/2-1,0,-b/4);
   glEnd();


   

   glColor3fv(C1);
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);                 //BACK gate
   glVertex3f(-l/4,h/3,b/2+1);
   glVertex3f(l/4,h/3,b/2+1);
   glVertex3f(l/4,0,b/2+1);
   glVertex3f(-l/4,0,b/2+1);
   glEnd();

   

   glColor3fv(C2);
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);                 //RIGHT gate
   glVertex3f(l/2+1,h/3,b/4);
   glVertex3f(l/2+1,0,b/4);
   glVertex3f(l/2+1,0,-b/4);
   glVertex3f(l/2+1,h/3,-b/4);
   glEnd();

   glColor3fv(WC);
   
   
   glBegin(GL_TRIANGLE_FAN);         //top roof
   glVertex3f(0,2*h,0);
   glVertex3f(l/2+5,h,-b/2-5);
   glVertex3f(-l/2-5,h,-b/2-5);
   glVertex3f(-l/2-5,h,b/2+5);
   glVertex3f(l/2+5,h,b/2+5);
   glVertex3f(l/2+5,h,-b/2-5);
   glEnd();

}




		
