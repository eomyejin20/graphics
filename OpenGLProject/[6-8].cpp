#include <GL/glut.h>

void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}

	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 3.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// gluLookAt(-1.0, 0.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	DrawGround();

	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0);

	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("VCS (View Coordinate System)");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);

	glutMainLoop();
	return 0;
}