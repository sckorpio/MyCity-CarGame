#ifndef MOTION_H
#define MOTION_H

#include <GL/glut.h>

class MOTION
{
	//--------------------------------------------------------------------
   
   public:

    GLfloat X;      //coordinates
    GLfloat Y;
    GLfloat Z;

    GLfloat theta;     //direction angle
    
    GLfloat ux;  GLfloat uz;  //unit vector

    GLfloat Speed;
    GLfloat Friction;
    GLfloat Acc;

    GLfloat t;  //timer

    //----------

    MOTION();
    
    void UpdateAcc();
    void UpdateVector();
    void FreeMotion();
    void DrawVector();

   
};

#endif
