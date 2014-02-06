/*
   @@ Author: Jian Chen (jichen@umbc.edu)
   @@ CMSC 435 / 634 project 1: interface for primitives drawing
   @@ August 2013
*/

#ifndef __01_PRIMITIVES_H__
#define __01_PRIMITIVES_H__

#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

void DrawWireTriangle(GLfloat a[], GLfloat b[], GLfloat c[]);
void DrawWirePlane(GLfloat a[], GLfloat b[], GLfloat c[], GLfloat d[]);
/* 
 * this function implements glutSolidSphere 
 * Input:  radius: the radius of the sphere
 *         slices: number of subdivisions around the longitude
 *         stacks: number of subdivisions around the latitude
 */
void DrawWireSphere(GLdouble radius, GLfloat slices, GLfloat stacks);

/* 
 * this function implements  glutWireCube
 */
void DrawWireCube();

/* 
 * this function implements gluCylinder 
 * put your input for tessellation here..
 */
void DrawWireCylinder(GLint slices, GLfloat stacks);

/* 
*/
void DrawCone(GLint slices, GLfloat stacks);

#endif
