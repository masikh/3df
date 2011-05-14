// main.h header file

/* standard C libs */
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* OpenGL and SDL libs */
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

/* My own libs */
#define TITLE "<- There is no Space -> [esc]: quits"
bool stop = false;
int winIdMain;
void scene1();
