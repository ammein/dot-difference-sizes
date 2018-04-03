#include <stdlib.h>
#include <glut.h>
#include <iostream>

using namespace std;

GLsizei windowWidth = 800, windowHeight = 640;

void initGL()
{
	glClearColor(0.431, 0.462, 0.866, 1.0f); // RGBA Window Color
}

/***************************************************

	1			GRAPH DISPLAY
	y											1
	^ 
	|
	|
	|
	|0
	|
	|
	|
	|__________________________________________> x
	-1					0						1


***************************************************/

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
	// Time to draw
	glPointSize(20.0); // Point Size Color
	glBegin(GL_POINTS);
		glColor3f(0.584f, 0.607f, 0.921f); // RGB Point Color
		glVertex2d(-0.4, windowHeight / 1000); // Value 0 - 1 positioning x
	glEnd();
	glPointSize(30.0); // Point Size Color
	glBegin(GL_POINTS);
		glColor3f(0.305f, 0.341f, 0.796f); // RGB Point Color
		glVertex2d(-0.25, windowHeight / 1000); // Value 0 - 1
	glEnd();
	glPointSize(40.0); // Point Size Color
	glBegin(GL_POINTS);
		glColor3f(0.772f, 0.784f, 0.972f); // RGB Point Color
		glVertex2d(-0.1, windowHeight / 1000); // Value 0 - 1 
	glEnd();
	glPointSize(50.0); // Point Size Color
	glBegin(GL_POINTS);
		glColor3f(0.584f, 0.607f, 0.921f); // RGB Point Color
		glVertex2d(0.1, windowHeight / 1000); // Value 0 - 1 positioning x
	glEnd();
	glPointSize(60.0); // Point Size Color
	glBegin(GL_POINTS);
		glColor3f(0.992f, 0.992f, 0.992f); // RGB Point Color
		glVertex2d(0.35, windowHeight / 1000); // Value 0 - 1
	glEnd();
	glFlush(); // Render Now
}
/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitWindowSize(windowWidth, windowHeight); // Set the window's initial width & height
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
	glutCreateWindow("Dot Dot Designs"); // Create a window with the given title
	glutDisplayFunc(displayFunc); // Register display callback handler for window re-paint
	glutReshapeFunc(reshape); 
	initGL();
	cout << "Window Width : " << windowWidth << " , Window Height : " << windowHeight << endl;
	glutMainLoop(); // Enter the event-processing loop
	return 0;
}
