#include "main.h"
#include <unistd.h>
#include <iostream.h>
using namespace std;

int WIDTH = 1200;		// screen resolution
int HEIGHT = 900;
float center_x = 0.0;
float center_y = 0.0;
float center_z = 0.0;

void Display()
{
	scene1();
};

void keyboard (unsigned char key, int x, int y){
	switch (key)
	{
		case 27:			/* ESC */	
			glutDestroyWindow(winIdMain);
			glutLeaveGameMode();
			printf ("Exit gracefully\n");
			exit (0);
	}
}

/* Callback function for reshaping the main window */
void mainReshape (int w, int h) {
  	glViewport (0, 0, w, h);
  	glMatrixMode (GL_PROJECTION);
  	gluPerspective (
					40.0,		/* Field of view in degree */
					1.25,		/* aspect ratio e.g. 1280 divided by 1024 */
					1.0,		/* Z near */
					300.0 /* Z far */ );
  	gluLookAt (
			   0.0, 0.0, 10.0,	/* Eye is at */
			   center_x, center_y, center_z,	/* Center is at */
			   0.0, 1.0, 0.0 /* Up is in positive Y direction */ );
};


void idle () {
	glutSetWindow (winIdMain);
	glutPostRedisplay ();
};

void *glutmain(void *arg) {
	glutMainLoop ();				// keep on looping in this main fucntion
	return 0;
}

int main (int argc, char **argv) {
	/* Global end signal of demo */
	/* Glut initializations */
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutGameModeString("1440x900");
	glutEnterGameMode();
	glutSetCursor(GLUT_CURSOR_NONE);		// no mouse pointer
	glutAddMenuEntry("Quit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(Display);			// Let's draw something
	glutReshapeFunc(mainReshape);		// if windows is resized
	glutKeyboardFunc(keyboard);			// some keybindings
	glutIdleFunc(idle);				// idle loop for timer increment
	glutmain(NULL);	
	return 0;					// die clean
};