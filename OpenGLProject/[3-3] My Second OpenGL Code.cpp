#include <GL/glut.h>

void MyDisplay() {
	float vertices[3][2] = { {0.0, 0.0}, {250.0, 500.0}, {500.0, 0.0} };
	float p[2] = { 75.0, 50.0 };
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT);

	for (j = 0; j < 5000; j++) {
		i = rand() % 3;
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;

		glBegin(GL_POINTS);
		glVertex2fv(p);
		glEnd();
	}
	glFlush();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.5, 0.5, 0.5);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, 1, -1);
}

void main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinski Gasket");
	glutDisplayFunc(MyDisplay);
	MyInit();
	glutMainLoop();
}