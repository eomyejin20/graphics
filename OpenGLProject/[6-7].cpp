#include <stdlib.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0;

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);	 // Pivot ���� �� ��ü �̵�
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // ������ �������� ȸ��
	glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
	glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0);	// Pivot ���� �� ��ü �̵�
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // ������ �������� ȸ��
	glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
	glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glTranslatef(-1.0, 0.0, 0.0);	 // Pivot ���� �� ��ü �̵�
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // ������ �������� ȸ��
	glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
	glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
		shoulder = (shoulder + 5) % 360;
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot Arm");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}