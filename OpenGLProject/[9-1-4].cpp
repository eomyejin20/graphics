#include <GL/glut.h>


static int SpinAngle = 0;

void InitLight() {
	GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 };     //???? Ư??
	GLfloat light0_diffuse[] = { 0.8, 0.7, 0.6, 1.0 };
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glEnable(GL_DEPTH_TEST);    //???? ???? Ȱ??ȭ
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);      //???? Ȱ??ȭ
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
}

void MyDisplay() {  // ?????? ???? ??ǥ?迡 ??ġ
	GLfloat LightPosition[] = { 0.0, 0.0, 1.5, 1.0 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(SpinAngle, 1.0, 0.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition); // ?????? ??ġ
	glPopMatrix();
	glutSolidTeapot(1);

	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, 5.0, 0, 0, -100, 0, 1, 0);
}

void MyMouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			SpinAngle = (SpinAngle + 15) % 360;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Light Animation");
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);
	glutMainLoop();
	return 0;
}