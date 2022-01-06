#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 1.0, 0.0); glVertex3f(-1.0, 0.5, 0.0);
	glVertex3f(-1.0, -0.5, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1.0, -0.5, 0.0); glVertex3f(1.0, 0.5, 0.0);
	glEnd();
	glFlush();


}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(500, 500);
	glutCreateWindow("[4-1]");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}