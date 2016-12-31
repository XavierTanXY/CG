#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
#include <OpenGl/glu.h>
#include <OpenGl/gl.h>
#include <GLUT/GLUT.h>
#include "shape.h"


typedef struct
{
    float x;
    float y;
}CIRCLE;

CIRCLE circle;

void createcircle (int k, int r, int h) {
    
    int i;
    glBegin(GL_LINES);
    for ( i = 0; i < 180; i++)
    {
        circle.x = r * cos(i) - h;
        circle.y = r * sin(i) + k;
        glVertex3f(circle.x + k,circle.y - h,0);
        
        circle.x = r * cos(i + 0.1) - h;
        circle.y = r * sin(i + 0.1) + k;
        glVertex3f(circle.x + k,circle.y - h,0);
    }
    glEnd();
}

void drawOval(int x, int y, int width, int height) {
    
    float theta;
    float angle_increment;
    float x1;
    float y1;
    float PI = 3.14;
    
    angle_increment = (float) PI / 500;
    glPushMatrix();
    
    glTranslatef(x+(width/2), y+(height/2), 0);
    
    glColor3f(1.0,1.0,0.6);
    
    glBegin(GL_POLYGON);
    for(theta = 0.0f; theta < 2 * PI; theta += angle_increment) {
        x1 = (float) (width/2 * cos(theta));
        y1 = (float) (height/2 * sin(theta));
        
        
        glVertex2f(x1, y1);
    }
    glEnd();
    
    glPopMatrix();
}

void drawCylinder(float radius, float height) {
    
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    
    gluCylinder(quadratic,0.1f,0.1f,3.0f,32,32);
    
}