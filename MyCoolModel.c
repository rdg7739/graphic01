/*
  @@ v1: Jian Chen (jichen@umbc.edu)
  @@     CMSC 435 / 634 project 1:  main function
  @@     display my cool models
  @@     August 2013
*/

#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "trackball.h"

#include "model.h"
#include "MyCoolModel.h"
#include "01primitives.h"
#include "01primitivesUtil.h"



/*-------------------------------------------------------------
 *  * Public  variables
 *   */
extern int draw_coord;
extern GLuint  coordList;
extern int draw_ground;
extern GLuint  groundList;

// object rotation along the three axes
extern GLfloat zoom; 
extern GLfloat tbx;
extern GLfloat tby;
GLint  mouseButton = -1;

/*---------------------------------------------------------------
 *   @ init routine 
 *     init some OpenGL states
 */
void init()
{
  /* background color: black */
  glClearColor(0, 0, 0, 0);
  glShadeModel(GL_FLAT);

  tbInit(GLUT_LEFT_BUTTON);

  /* generate coordList  */
  coordList = glGenLists(1);
  uMakeCoordList(coordList);

  /* generate groundList - not implemented */
  groundList = glGenLists(1);
  uMakeGroundList(groundList);

  /* extra credit */
  //initLittleMario();
}

/*---------------------------------------------------------------
 *   @ Display callback
 *     put all drawing routines here
 */
void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  tbMatrix();
  
  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);

  /* --> test drawing: draw a triangle*/
  glColor3f(0, 0, 0);  // white color
  // solid
  /*glBegin(GL_POLYGON);
    glVertex3f(0, 1, 0); 
    glVertex3f(-1, -1, 0); 
    glVertex3f(1, -1, 1);
  glEnd();

  glColor3f(1, 1, 1);  // white color
  glBegin(GL_LINE_LOOP);
    glVertex3f(0, 1, 0); 
    glVertex3f(-1, -1, 0); 
    glVertex3f(1, -1, 1);
  glEnd();
*/  
/* --> end of test drawing*/
  //DrawWireCube(4, 5);
  
/* here are the functions to be implemented */
  ModelHead();
  ModelTorso();
  ModelUpperBody();
  ModelLegsAndFeet();

  /* draw the coordinate system for debugging purpose */
  if(draw_coord)  glCallList(coordList);
  glPopMatrix();

  /* ground in the world coordinates */
  if(draw_ground) glCallList(groundList);

  /* extra credi:t play with 2D drawing */
  //ModelLittleMario();

  glutSwapBuffers();
}

/*---------------------------------------------------------------
 *   Reshape function 
 *     defines how to redraw the view when the window is resized
 */
void Reshape(int width, int height)
{
  tbReshape(width, height);

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLdouble)width/height, 0.01, 100);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -10+zoom);
}

void Mouse(int button, int state, int x, int y)
{
   //mouse_state = state;
   mouseButton=button;

   tbMouse(button, state, x, y);
   glutPostRedisplay();
}

void Motion(int x, int y)
{
  tbMotion(x, y, mouseButton);
  glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 27:   // esc
	  exit(0);
	  break;
	case 'c':  // toggle coordinates on/off (for debugging)
	  draw_coord= !draw_coord;
	  break;
	case 'g':  // toggle ground plane on/off (for debugging)
	  draw_ground= !draw_ground;
	  break;
    default:
	  break;
  }
  glutPostRedisplay();
}

/*---------------------------------------------------------------
 *   main 
 */
int main(int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("My cool model\n");

  init();

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutMouseFunc(Mouse);
  glutMotionFunc(Motion);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();
  return 0;
}
