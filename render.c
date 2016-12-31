#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
#include <OpenGl/glu.h>
#include <OpenGl/gl.h>
#include <GLUT/GLUT.h>
#include "render.h"
#include "shape.h"



//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0, alpha, beta, a, inc2;
float Autorun = 15;
int   inc;

int animationState;
int ANIMATION_RUNNING = 1;
int ANIMATION_STOPPED = 0;

void initVariable() {
    
    alpha = -(float) 20.0;
    beta  =  (float) 20.0;
    a = -(float) 5.0;
    
    inc = 1;
    inc2 = 0.1;
    
    animationState = ANIMATION_RUNNING;
}

void camera (void) {
    
    glRotatef(xrot,0.5,0.0,0.0);  //rotate our camera on the x-axis (left and right)
    glRotatef(yrot,0.0,0.5,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
    
}

void bubble1() {
    
    glPushMatrix();
    
    a = a + (float) inc2;
    if(a  >  (float) 20.0)
        a = -(float) 5.0;
    
    
    glTranslatef(-5, a, 5);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
}

void bubble2() {
    
    glPushMatrix();
    
    if(a  >  (float) 20.0)
        a = -(float) 5.0;
    
    
    glTranslatef(-3, a, -5);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
}
void bubble3() {
    
    glPushMatrix();
    
    if(a  >  (float) 20.0)
        a = -(float) 5.0;
    
    glTranslatef(0, a, 0);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
}

void bubble4() {
    
    glPushMatrix();
    
    if(a  >  (float) 20.0)
        a = -(float) 5.0;
    
    glTranslatef(3, a, -5);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
}

void drawBubbles() {
    
    bubble1();
    bubble2();
    bubble3();
    bubble4();
}


void drawGround() {

    glPushMatrix();
    glColor3f( 0.137255, 0.556863, 0.419608);
    glTranslatef(0,-5,0);
    glBegin(GL_QUADS);
 
    glVertex3f(-8.0,0,8.0);
    glVertex3f(8,0,8.0);
    glVertex3f(8.0,0,-8.0);
    glVertex3f(-8.0,0,-8.0);
    
    
    glEnd();
    glPopMatrix();
}

void drawPyramid () {
    
    glPushMatrix();
    
    glTranslatef(-4, -2, 0);
    glScaled(3, 3, 3);
    
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    
    // Front
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    // Right
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    // Back
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    // Left
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glColor3f(0.81, 0.71, 0.23);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();
    
    glPopMatrix();
    
}

void drawChest() {
    
    glPushMatrix();
    
    glColor3f(0.55, 0.47, 0.14);
    glTranslatef(3, -4.4, 0);
    glutSolidCube(1.0f);
    
    glPopMatrix();
}

void drawHuman() {
    
    glPushMatrix();
    
    Autorun = Autorun + (float) inc2;
    
    if(Autorun  >  (float) 20.0)
        Autorun -= (float) 30.0;
    
    glTranslated(-Autorun, 0, 0);
    
    glPushMatrix();
    glScaled(0.5, 0.5, 0.5); //Scaling human
    
    glPushMatrix(); //Bubble
    glTranslatef(-1.5, a + 6 , 1.7);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix(); //Bubble
    glTranslatef(-1, a + 8 , 1.7);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix(); //Bubble
    glTranslatef(-0.5, a + 10 , 1.7);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix(); //Draw head
    glScaled(0.5, 0.5, 0.5);
    glTranslatef(-2, 2, 1.7);
    glColor3f(1,1, 1);
    createcircle(0.25,1,0.25);
    glPopMatrix();
    
    glBegin(GL_LINES); //Draw pipe
    glVertex3f(-1, 1, 1);
    glVertex3f( -0.5, 2, 1);
    glEnd();
    
    glBegin(GL_LINES); //Draw body
    glVertex3f(1, 1, 1);
    glVertex3f( -0.5, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f( 2.5, 1.2, 1);
    glVertex3f(1, 1, 1);
    glVertex3f( 2.5, 0, 1);
    glEnd();
    
    glPushMatrix();
    glTranslatef(2,2.5,1);
    glScaled(-0.5, -0.5, -0.5);
    drawOval( 0, 1, 4, 2);
    drawOval( 1, 1, 4, 2);
    glPopMatrix();
    
    glPopMatrix(); //Pop scaling
    glPopMatrix();
}


void drawFlower() {
    
    glPushMatrix();
    glTranslatef( 6, -2, 5);
    
    glPushMatrix(); //Animation start
    
    glPushMatrix(); //Bubble
    glTranslatef(-0.5, a + 6 , 1.7);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix(); //Bubble
    glTranslatef(1, a + 8 , 1.7);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix(); //Bubble
    glTranslatef(1.5, a + 10 , 1.7);
    glColor3f(0,0, 1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    alpha = alpha + (float) inc;
    
    if(alpha  >  (float) 360.0)
        alpha -= (float) 360.0;
    
    glRotatef(alpha, (float) 0.0, (float) 0.0, (float) 1.0);
    
    glPushMatrix(); //Paddle 1
    glScaled(-0.5, -0.5, -0.5);
    glTranslatef( -1, -2, -0.25);
    drawOval( 1, 1, 4, 2);
    glPopMatrix();
    
    glPushMatrix(); //Paddle 2
    glScaled(-0.5, -0.5, -0.5);
    glRotatef(90, 0, 0,1 );
    glTranslatef( -1, -2, -0.25);
    drawOval( 1, 1, 4, 2);
    glPopMatrix();
    
    glPushMatrix(); //Paddle 3
    glScaled(-0.5, -0.5, -0.5);
    glRotatef(180, 0, 0,1 );
    glTranslatef( -1, -2, -0.25);
    drawOval( 1, 1, 4, 2);
    glPopMatrix();
    
    glPushMatrix(); //Paddle 4
    glScaled(-0.5, -0.5, -0.5);
    glRotatef(270, 0, 0,1 );
    glTranslatef( -1, -2, -0.25);
    drawOval( 1, 1, 4, 2);
    glPopMatrix();
    
    glPushMatrix(); //Draw middle
    glColor3f(0,1,1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPopMatrix();//Animation pop
    
    glPushMatrix(); //Draw stick
    glColor3f(0.91, 0.76, 0.65);
    glRotatef(90, 1, 0, 0 );
    drawCylinder( 2, 5 );
    glPopMatrix();
    
    glPopMatrix();
    
}

void drawTurtle() {
    
    glPushMatrix();
    glTranslatef(0,-5,-4);
    beta = beta + (float) inc2;
    
    if(beta  >  (float) 20.0)
        beta -= (float) 30.0;
    
    glTranslated(0, 0, beta);
    
    glPushMatrix(); //Shell
    glScaled(-0.5, -0.5, -0.5);
    glRotatef(89, 1, 0, 0 );
    glTranslatef(-6,0,1);
    drawOval( 1, 1, 5, 7);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.71, 0.65, 0.26);
    glBegin(GL_LINES); //Draw Lines on shell
    glVertex3f(0.8, 0.5, -1);
    glVertex3f( 2.3, 0.5, -1);
    glVertex3f(0.5, 0.5, -1.5);
    glVertex3f( 2.5, 0.5, -1.5);
    glVertex3f(0.5, 0.5, -2);
    glVertex3f( 2.5, 0.5, -2);
    glVertex3f(0.5, 0.5, -2.5);
    glVertex3f( 2.5, 0.5, -2.5);
    glVertex3f(0.8, 0.5, -3);
    glVertex3f( 2.3, 0.5, -3);
    glVertex3f(2, 0.5, -0.8);
    glVertex3f( 2, 0.5, -3.3);
    glVertex3f(1.5, 0.5, -0.5);
    glVertex3f( 1.5, 0.5, -3.5);
    glVertex3f(1, 0.5, -0.8);
    glVertex3f( 1, 0.5, -3.3);
    glEnd();
    glPopMatrix();
    
    glPushMatrix(); //Head
    glColor3f(0,1,0);
    glTranslatef(1.5,0.75,-0.5);
    glutSolidSphere(0.4,20,20);
    glPopMatrix();
    
    
    //Four legs
    glPushMatrix();
    glColor3f(0.71, 0.65, 0.26);
    glTranslatef(2,0.25,-1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.71, 0.65, 0.26);
    glTranslatef(2,0.25,-3);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.71, 0.65, 0.26);
    glTranslatef(1,0.25,-3);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.71, 0.65, 0.26);
    glTranslatef(1,0.25,-1);
    glutSolidSphere(0.25,20,20);
    glPopMatrix();
    
    glPopMatrix();
}

void fastenAnimation() {
    
    inc += 1;
    inc2 += 0.03;
}

void slowAnimation() {
    
    inc -= 1;
    inc2 -= 0.03;
    
}

void stopAnimation() {
    
    inc = 0;
    inc2 = 0;
}

void resumeAnimation() {
    inc = 1;
    inc2 = 0.1;
}

void input(unsigned char key, int x, int y) {
   
    switch (key) {
        case '`':
            exit(0);
            break;
        case 't':
            if( animationState == ANIMATION_RUNNING ) {
                stopAnimation();
                animationState = ANIMATION_STOPPED;
            }
            break;
        case 'c':
            if( animationState == ANIMATION_STOPPED ) {
                resumeAnimation();
                animationState = ANIMATION_RUNNING;
            }
            break;
        case 'f':
            fastenAnimation();
            break;
        case 's':
            slowAnimation();
            break;
        case 'x':
            xrot -= 0.1; //Rotate x
            break;
        case 'z':
            gluLookAt(0, 0, 0.1, 0, 0, -1, 0, 1, 0);
            break;
        case 'Z':
            gluLookAt(0, 0, -0.1, 0, 0, -1, 0, 1, 0);
            break;
        case 'y':
            yrot -= 0.1; //Rotate y
            break;
        case 'p':
            glShadeModel(GL_FLAT);
            break;
        case 'P':
            glShadeModel(GL_SMOOTH);
            break;
        case 'a':
            if( animationState == ANIMATION_RUNNING ) {
                stopAnimation();
                animationState = ANIMATION_STOPPED;
            } else if( animationState == ANIMATION_STOPPED ) {
                resumeAnimation();
                animationState = ANIMATION_RUNNING;
            }
            break;
        default:
            break;
    }
    
}

void output( char *array, float yAxis ) {
    
    int i, len;
    float xAxis = 5.0;
    
    glColor3f( 1, 1, 1 );
    glRasterPos2f( xAxis, yAxis );
    len = strlen(array);
    
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, array[i]);
    }
    
}

void prepareOutput() {
    
    float yAxis = 7;
    char zoomIn[12]  = {'<', 'Z', '>', '-', 'Z', 'o', 'o', 'm' , ' ', 'i', 'n', '\0'};
    output( zoomIn, yAxis );
    yAxis-= 0.5;
    
    char zoomOut[13]  = {'<', 'z', '>', '-', 'Z', 'o', 'o', 'm' , ' ', 'o', 'u', 't', '\0'};
    output( zoomOut,  yAxis);
    yAxis-= 0.5;
    
    char rotateX[13]  = {'<', 'x', '>', '-', 'R', 'o', 't', 'a' , 't', 'e', ' ', 'X', '\0'};
    output( rotateX, yAxis );
    yAxis-= 0.5;
    
    char rotateY[13]  = {'<', 'y', '>', '-', 'R', 'o', 't', 'a' , 't', 'e', ' ', 'Y', '\0'};
    output( rotateY, yAxis );
    yAxis-= 0.5;
    
    char predefinedAnimation[26]  = {'<', 'a', '>', '-', 'P', 'r', 'e', '-' , 'd', 'e', 'f', 'i', 'n', 'e', 'd', ' ', 'A', 'n', 'i', 'm', 'a', 't', 'i' , 'o', 'n', '\0'};
    output( predefinedAnimation, yAxis );
    yAxis-= 0.5;
    
    char fasterAnimation[21]  = {'<', 'f', '>', '-', 'F', 'a', 's', 't', 'e', 'r', ' ', 'A', 'n', 'i', 'm', 'a', 't', 'i' , 'o', 'n', '\0'};
    output( fasterAnimation, yAxis );
    yAxis-= 0.5;
    
    char slowerAnimation[21]  = {'<', 'f', '>', '-', 'S', 'l', 'o', 'w', 'e', 'r', ' ', 'A', 'n', 'i', 'm', 'a', 't', 'i' , 'o', 'n', '\0'};
    output( slowerAnimation, yAxis);
    yAxis-= 0.5;
    
    char pauseAnimation[20]  = {'<', 't', '>', '-', 'P', 'a', 'u', 's', 'e', ' ', 'A', 'n', 'i', 'm', 'a', 't', 'i' , 'o', 'n', '\0'};
    output( pauseAnimation, yAxis );
    yAxis-= 0.5;
    
    char resumeAnimation[21]  = {'<', 'c', '>', '-', 'R', 'e', 's', 'u', 'm', 'e', ' ', 'A', 'n', 'i', 'm', 'a', 't', 'i' , 'o', 'n', '\0'};
    output( resumeAnimation, yAxis );
    yAxis-= 0.5;
    
    char renderFlat[30]  = {'<', 'p', '>', '-', 'R', 'e', 'n', 'd', 'e', 'r', ' ', 'F', 'l', 'a', 't', ' ', 'S', 'h' , 'a', 'd', 'e', 'd', '\0'};
    output( renderFlat, yAxis );
    yAxis-= 0.5;
    
    char renderSmooth[30]  = {'<', 'P', '>', '-', 'R', 'e', 'n', 'd', 'e', 'r', ' ', 'F', 'l', 'a', 't', ' ', 'S', 'm' , 'o', 'o', 't', 'h', '\0'};
    output( renderSmooth, yAxis );
    yAxis-= 0.5;
    
}
