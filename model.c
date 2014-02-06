/*  
 * Implementation functions that will draw the robot 
 * 
 */

#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include "01primitives.h"
#include "model.h"

void ModelHead()
{  //hat
  glPushMatrix();
  glTranslatef(0,4,0);
  glScalef(1,0.5,1);
  DrawCone(5,5);
  glTranslatef(0, -1, 0);  // put the translation along the x, y, z here
  // draw the head here
  DrawWireCylinder(10,5);
  glTranslatef(0,-0.25, 0);
  glScalef(0.25,0.5,0.5); //neck
  DrawWireCube();
  glPopMatrix();
}

void ModelUpperBody()
{
  //chest
  glPushMatrix();
  glTranslatef(0, 3,0);
  glScalef(2,0.5,1);
  DrawWireCube();
  //right shoulder
  glTranslatef(0.65,0.10,0);
  glScalef(0.3,0.75,0.65);
  DrawWireSphere(0.5,10,10);
  //left shoulder 
  glTranslatef(-4.3,0,0);
  DrawWireSphere(0.5, 10,10);
  //right arm 
  glTranslatef(4.3,-2.80, 0);
  glScalef(0.5, 5, 0.5);
  DrawWireCube();
  //left arm
  glTranslatef(-8.6,0,0);
  DrawWireCube();
  //right hand
  glTranslatef(8.6,-0.60,0);
  glScalef(2,0.25,2);
  DrawWireSphere(0.5,10,10);
  //left hand 

  glTranslatef(0,0,0);
  glTranslatef(-4.3,0,0);
  DrawWireSphere(0.5,10,10);
  glPopMatrix();
}

void ModelTorso()
{
  glPushMatrix();
  glTranslatef(0, 0.75, 0);
  glScalef(1.75,2,2);
  DrawWireCylinder(10,10);
  glPopMatrix();
}

void ModelLegsAndFeet()
{
  glPushMatrix();
  //right leg
  glTranslatef(0.5, -0.5, 0);
  glScalef(0.5,2.5,0.75);
  DrawWireCube();
  //left leg
  glTranslatef(-2, 0, 0);
  DrawWireCube();
  //right feet
  glTranslatef(2.1, -0.6, 0.2);
  glScalef(1.3,0.2,1.5);
  DrawWireCube();
  //left feet
  glTranslatef(-1.7, 0, 0);
  DrawWireCube();
  glTranslatef(1,-0.5,0);
  glScalef(3,3,3);
  GLfloat a[] = {-1,0,1};
  GLfloat b[] = {1,0,1};
  GLfloat c[] = {1,0,-1};
  GLfloat d[] = {-1,0,-1};
  DrawWirePlane(a,b,c,d);
  glPopMatrix();
}
/*

void ModelHead(){}
void ModelTorso(){}
void ModelLegsAndFeet(){}
*/
/*----------------------------------------------------------------------------
 */
/*  extra credit ONLY */
#define SizeX 4 
#define SizeY 4
GLubyte  myLittleMario[SizeX * SizeY * 3];

void initLittleMario()
{
/* --> testing routine  */
  int i, j;

  for(i=0; i<SizeY; i++)
    for(j=0; j<SizeX; j++)
    {
      myLittleMario[(i*SizeX + j) * 3 + 0] = 0x00;
      myLittleMario[(i*SizeX + j) * 3 + 1] = 0xff;
      myLittleMario[(i*SizeX + j) * 3 + 2] = 0x00;
    }
/* --> end of testing routine  */
}

void ModelLittleMario()
{
  glRasterPos2f(20, 20);
  glDrawPixels(20, 20, GL_RGB, GL_UNSIGNED_BYTE, myLittleMario);
}
