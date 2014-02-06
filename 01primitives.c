/*
   @@ Author: 
   @@  v2: 
   @@
   @@  v1: Jian Chen (jichen@umbc.edu)
   @@      CMSC 435 / 634 baseline code
   @@      August 2013
*/

#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif
#include <math.h>
#define PI 3.14159265359

void DrawWireTriangle(GLfloat a[], GLfloat b[], GLfloat c[]){
//glColor3f(1,1,1);
glBegin(GL_LINE_LOOP);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}

void DrawWirePlane(GLfloat a[], GLfloat b[], GLfloat c[], GLfloat d[]){
DrawWireTriangle(a,b,c);
DrawWireTriangle(a,c,d);
}

/* 
 */
void DrawWireSphere( GLdouble radius, GLfloat slices, GLfloat stacks)
{
//glColor3f(1,1,0);
float angleT, angleP, nextT, nextP;
float t = 2 * PI /stacks;
float p = 2 * PI / slices;
int i = 0;
for (angleT = 0; angleT < 2* PI; angleT += t){
nextT = angleT + t;
	for(angleP = 0;  angleP < 2 *PI;  angleP += p){
nextP = angleP + p;	
	if(i%2 == 0) {
		glColor3f(1,0,0);
	}
	else{
	glColor3f(1,1,0);}
	i++;	
	GLfloat a[] = {radius*sin(angleT)*cos(angleP), radius * sin(angleT) * sin(angleP), radius * cos(angleT)};	
	GLfloat b[] = {radius*sin(nextT)*cos(angleP), radius * sin(nextT) *sin(angleP), radius *cos(nextT)};
	GLfloat c[] = {radius*sin(nextT)*cos(nextP), radius * sin(nextT) *sin(nextP), radius*cos(nextT)};
	GLfloat d[] = {radius*sin(angleT)*cos(nextP), radius * sin(angleT) *sin(nextP), radius*cos(angleT)};
	//DrawWireTriangle(a,b,c);
	DrawWirePlane(a,b,c,d);	
}
}
}
/* 
 */
void DrawWireCube()
{
glColor3f(0,0,1);
GLfloat a[] = {-0.5,-0.5,0.5};
GLfloat b[] = {0.5,-0.5,0.5};
GLfloat c[] = {0.5,0.5,0.5};
GLfloat d[] = {-0.5,0.5,0.5};
GLfloat e[] = {-0.5,-0.5,-0.5};
GLfloat f[] = {0.5,-0.5,-0.5};
GLfloat g[] = {0.5,0.5,-0.5};
GLfloat h[] = {-0.5,0.5,-0.5};


//front
DrawWirePlane(a,b,c,d);
//left
DrawWirePlane(b,f,g,c);
//top
DrawWirePlane(c,g,h,d);
//right
DrawWirePlane(a,d,h,e);
//bottom
DrawWirePlane(a,e,f,b);
//back
DrawWirePlane(e,h,g,f);
          

}

/* 
 */
void DrawWireCylinder(GLint slices, GLfloat stacks)
{
glColor3f(0,1,0);
float angle = 2 * PI / slices; 
float i, j, myZ;
float r = 0.5;
float unitZ = 1/stacks;

for (i = 0; i < stacks; i++){
float myZ = i * unitZ;
float myZ_2 = (i+1) * unitZ;
	
	GLfloat a[] = {0,0,0};
	GLfloat b[] = {r*sin(angle*i),0,r*cos(angle*i)};
	GLfloat c[] = {r*sin(angle*(i+1)), 0, r*cos(angle * (i+1))};
	DrawWireTriangle(a,b,c);
		
	GLfloat d[] = {0,1,0};
	GLfloat e[] = {r*sin(angle*i),1,r*cos(angle*i)};
	GLfloat f[] = {r*sin(angle*(i+1)), 1, r*cos(angle * (i+1))};
 	DrawWireTriangle(d,e,f);
	
	for(j = 0; j < slices; j++){
	GLfloat a[] = {r*sin(angle*j),myZ,r*cos(angle*j)};
	GLfloat b[] = {r*sin(angle*(j+1)), myZ, r*cos(angle * (j+1))};
	GLfloat c[] = {r*sin(angle*(j+1)), myZ_2, r*cos(angle * (j+1))};	
	GLfloat d[] = {r*sin(angle*j), myZ_2, r*cos(angle * j)};
	DrawWirePlane(a,b,c,d);
}
}

}
/*
 */
void DrawCone(GLint slices, GLfloat stacks)
{
glColor3f(1,0,0);
float angle = 2 * PI / slices; 
float i, j, myZ;
float r = 0.5;
float unitZ = 1/stacks;
//int reverseR = slices;
float unitR = r/slices;


for (i = 0; i < stacks; i++){
float myZ = i * unitZ;
float myZ_2 = (i+1) * unitZ;
float myR = (stacks - i) * unitR;
float myR_2 = (stacks- (i+1)) * unitR;
	GLfloat a[] = {0,0,0};
	GLfloat b[] = {r*sin(angle*i),0,r*cos(angle*i)};
	GLfloat c[] = {r*sin(angle*(i+1)), 0, r*cos(angle * (i+1))};
	DrawWireTriangle(a,b,c);

for(j = 0;  j < slices;  j++){	
	GLfloat l[] = {myR*cos(angle*j),myZ,myR*sin(angle*j)};
	GLfloat n[] = {myR*cos(angle*(j+1)), myZ, myR*sin(angle * (j+1))};
	GLfloat m[] = {myR_2*cos(angle*j), myZ_2, myR_2*sin(j * angle)};
	GLfloat o[] = {myR_2*cos(angle*(j+1)), myZ_2, myR_2*sin((j+1) * angle)};
	DrawWirePlane(l,n,o,m);
	//reverseR--;
}
}
}



