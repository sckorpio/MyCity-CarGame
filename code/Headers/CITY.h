#ifndef CITY_H
#define CITY_H

#include <GL/glut.h>

#include "CAR.h"
#include "MOTION.h"
#include "CAMERA.h"

//-----------------------
 
 extern MOTION m;
 extern CAR car;
 extern CAMERA cam;

 extern int count;
 extern int finish;
 extern float omega;
 extern float wa;
 extern int state;
 extern int T;
 extern int s;

 //------------------------

 void makeBuildings();
 void makeRoads();

 //--------------------

 #endif
