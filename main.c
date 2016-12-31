#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
#include <OpenGl/glu.h>
#include <OpenGl/gl.h>
#include <GLUT/GLUT.h>
#include "main.h"
#include "shape.h"
#include "render.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 800

void init() {
    // Create light components
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
    GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    
    glEnable (GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
 
  
    // Assign created components to GL_LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    initVariable();
    gluLookAt(0, 0, 20, 0, 0, -1, 0, 1, 0);
    
    
}

void display(void) {
    /* clear the buffer of all data  */
    glClearColor (0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera();
    
    prepareOutput();
    drawHuman();
    drawFlower();
    drawTurtle();
    drawBubbles();
    drawGround();
    drawPyramid();
    drawChest();
    
    glFlush();
    glutSwapBuffers();
    
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
}

void idle(void) {
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(400, 400);
    
    glutCreateWindow("CG252 Under The Sea");
    init();
    
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutKeyboardFunc(input);
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}