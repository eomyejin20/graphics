#include <gl/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, -30.0);
	glVertex3f(10.0, 0.0, -30.0);
	glVertex3f(10.0, 10.0, -30.0);
	glVertex3f(10.0, 10.0, -30.0);
	glEnd();
	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
	

	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0*WidthFactor, 20.0*WidthFactor, 0.0*HeightFactor, 20.0*HeightFactor, 10.0, 50.0);

}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);

}

int main(int argc, const char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Reshape");
	MyInit();
	glutReshapeFunc(MyDisplay);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}