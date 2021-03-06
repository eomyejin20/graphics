#include <GL/glut.h>

GLfloat Delta = 0.0;
GLfloat rc, gc, bc;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glColor3f(rc, gc, bc);
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MyIdle1() { 
	rc = 1.0; gc = 0.0; bc = 0.0;
	if (Delta < 1.0f) {
		Delta = Delta - 0.1;
		rc = 1.0; gc = 0.0; bc = 0.0;
	}
	glutPostRedisplay();
}
void MyTimer(int Value) {
	Delta = Delta + 0.1;
	if (Delta < 1.0) {
		Delta = Delta - 0.01;
		rc = 1.0; gc = 0.0; bc = 0.0;
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Timer Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1);

	glutMainLoop();
	return 0;
}
