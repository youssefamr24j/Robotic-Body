#include <GL/glut.h>
#include <stdlib.h>

static int Arm = 0, Elbow = 0 , RotatingArm=0, LeftLeg = 0, RightLeg =0, LeftKnee = 0 , RightKnee = 0 , RotatingRightLeg=0 , RotatingLeftLeg = 0 ;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef(0,1,0);
   //Head
   glPushMatrix();
   glTranslatef(0,1.65,0);
   glutSolidSphere(0.4,20,20);
   glPopMatrix();
   //Body
   glPushMatrix();
   glScalef(1.25,2.5,0.5);
   glutWireCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.0,1.075,0);
   glRotatef((GLfloat) RotatingArm,1.0,0.0,0.0);
   glTranslatef(0.0,-1.075,0);
   //Right Arm
   //Upper Shoulder
   glPushMatrix();
   glTranslatef(0.7,1.075,0);
   glRotatef((GLfloat) Arm,0.0,0.0,1.0);
   glTranslatef(-0.7,-1.075,0);
   glPushMatrix();
   glTranslatef(0.8,0.7,0);
   glScalef(0.2,0.75,0.3);
   glutWireCube(1);
   glPopMatrix();
   //Lower Shoulder
   glPushMatrix();
   glTranslatef(0.7,0.325,0);
   glRotatef((GLfloat) Elbow,0.0,0.0,1.0);
   glTranslatef(-0.7,-0.325,0);
   glTranslatef(0.8,0,0);
   glScalef(0.2,0.75,0.3);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();
   
   
   //Left Arm
   //Upper Shoulder
   glPushMatrix();
   glTranslatef(-0.7,1.075,0);
   glRotatef(-(GLfloat) Arm,0.0,0.0,1.0);
   glTranslatef(0.7,-1.075,0);
   glPushMatrix();
   glTranslatef(-0.8,0.7,0);
   glScalef(0.2,0.75,0.3);
   glutWireCube(1);
   glPopMatrix();
   //Lower Shoulder
   glPushMatrix();
   glTranslatef(-0.7,0.325,0);
   glRotatef(-(GLfloat) Elbow,0.0,0.0,1.0);
   glTranslatef(0.7,-0.325,0);
   glTranslatef(-0.8,0,0);
   glScalef(0.2,0.75,0.3);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   //Right Leg
   //Upper Leg
   glPushMatrix();
   glTranslatef(0.625,-1.3,0);
   glRotatef((GLfloat) RotatingRightLeg,0.0,0.0,1.0);
   glTranslatef(-0.625,1.3,0);
   glTranslatef(0.0,-1.3,0);
   glRotatef((GLfloat) RightLeg,1.0,0.0,0.0);
   glTranslatef(0.0,1.3,0);
   glPushMatrix();
   glTranslatef(0.425,-1.8,0);
   glScalef(0.4,1,0.5);
   glutWireCube(1);
   glPopMatrix();
   //Lower Leg
   glPushMatrix();
   glTranslatef(0.0,-2.3,0);
   glRotatef((GLfloat) RightKnee,1.0,0.0,0.0);
   glTranslatef(0.0,2.3,0);
   glPushMatrix();
   glTranslatef(0.425,-2.8,0);
   glScalef(0.4,1,0.5);
   glutWireCube(1);
   glPopMatrix();
   //Feet
   glPushMatrix();
   glTranslatef(0.425,-3.37,0.15);
   glScalef(0.4,0.15,0.8);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   //Left Leg
   //Upper Leg
   glPushMatrix();
   glTranslatef(-0.625,-1.3,0);
   glRotatef(-(GLfloat) RotatingLeftLeg,0.0,0.0,1.0);
   glTranslatef(0.625,1.3,0);
   glTranslatef(0.0,-1.3,0);
   glRotatef((GLfloat) LeftLeg,1.0,0.0,0.0);
   glTranslatef(0.0,1.3,0);
   glPushMatrix();
   glTranslatef(-0.425,-1.8,0);
   glScalef(0.4,1,0.5);
   glutWireCube(1);
   glPopMatrix();
   //Lower Leg
   glPushMatrix();
   glTranslatef(0.0,-2.3,0);
   glRotatef((GLfloat) LeftKnee,1.0,0.0,0.0);
   glTranslatef(0.0,2.3,0);
   glPushMatrix();
   glTranslatef(-0.425,-2.8,0);
   glScalef(0.4,1,0.5);
   glutWireCube(1);
   glPopMatrix();
   //Feet
   glPushMatrix();
   glTranslatef(-0.425,-3.37,0.15);
   glScalef(0.4,0.15,0.8);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();

 
   glPopMatrix();
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'a':
      if(Arm < 180)
         Arm = (Arm + 5) % 360;
      glutPostRedisplay();
      break;
   case 'A':
      if(Arm > 0)
         Arm = (Arm - 5) % 360;
      glutPostRedisplay();
      break;
   case 'e':
      if(Elbow < 145)
         Elbow = (Elbow + 5) % 360;
      glutPostRedisplay();
      break;
   case 'E':
      if(Elbow > 0)
         Elbow = (Elbow - 5) % 360;
      glutPostRedisplay();
      break;
   case 'w':
      RotatingArm = (RotatingArm + 5) % 360;
      glutPostRedisplay();
      break;
   case 'W':
      RotatingArm = (RotatingArm - 5) % 360;
      glutPostRedisplay();
      break;      
   case 'l' :
      if( LeftLeg < 45)
         LeftLeg = (LeftLeg + 5) % 360;
      glutPostRedisplay();
      break;
   case 'L':
      if( LeftLeg > -180)
         LeftLeg = (LeftLeg - 5) % 360;
      glutPostRedisplay();
      break;
   case 'r' :
      if( RightLeg < 45)
         RightLeg = (RightLeg + 5) % 360;
      glutPostRedisplay();
      break;
   case 'R':
      if( RightLeg > -180)
         RightLeg = (RightLeg - 5) % 360;
      glutPostRedisplay();
      break;   
   case 'k':
      if(LeftKnee < 90)
         LeftKnee = (LeftKnee + 5) % 360;
      glutPostRedisplay();
      break;
   case 'K':
      if(LeftKnee > 0)
         LeftKnee = (LeftKnee - 5) % 360;
      glutPostRedisplay();
      break;
   case 'n':
      if(RightKnee < 90)
         RightKnee = (RightKnee + 5) % 360;
      glutPostRedisplay();
      break;
   case 'N':
      if(RightKnee > 0)
         RightKnee = (RightKnee - 5) % 360;
      glutPostRedisplay();
      break;
   case 'x':
      RotatingRightLeg = (RotatingRightLeg + 5) % 360;
      glutPostRedisplay();
      break;
   case 'X':
      RotatingRightLeg = (RotatingRightLeg - 5) % 360;
      glutPostRedisplay();
      break;            
   case 'z':
      RotatingLeftLeg = (RotatingLeftLeg + 5) % 360;
      glutPostRedisplay();
      break;
   case 'Z':
      RotatingLeftLeg = (RotatingLeftLeg - 5) % 360;
      glutPostRedisplay();
      break;            
   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
    angle = angle + (x - startx);
    angle2 = angle2 + (y - starty);
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(1000, 750);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
