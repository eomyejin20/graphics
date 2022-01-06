#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

// �⺻ ���
#define FRAMERATE			60.0	// �����ӷ���Ʈ : �ʴ� 60 ������
#define PI					3.1416	// ������


// ī�޶� ���� 
double yaw = PI / 2 + PI / 4;				// for �¿� ����
double pitch = PI / 2 - PI / 8;             // for ���Ʒ� ����
bool is_mouselooking = true;		// ���콺 ���� ���� ����

double phase = 0;				// ���� �̵� ���� : 0 ~ 360


// ������ �ݹ�

void leg();

void animal();

void display() {

	// ���� �ʱ�ȭ
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0, 0, 0, 1);

	// ȭ�� �ʱ�ȭ
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ���� ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light0[] = { 0, 5, -2, 1 };	// õ�� ����
	GLfloat light0_dir[] = { 0, -1, 0, 1 };
	GLfloat light0_amb[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, light0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_dir);
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light0_amb);

	// �𵨺� ��ȯ ����
	double rad = 20;
	double camera_x = rad * sin(pitch) * cos(yaw);
	double camera_z = rad * sin(pitch) * sin(yaw);
	double camera_y = rad * cos(pitch);
	gluLookAt(camera_x, camera_y, camera_z,
		0, 0, 0,

		0.0f, 1.0f, 0.0f);

	// [�׸��� ����]
	glColor3ub(255, 128, 0);
	animal();

	// [�׸��� ��]

	// ������۸� ����
	glutSwapBuffers();
}



// �������� �ݹ�

void reshape(int w, int h) {

	// ����Ʈ ��ȯ �缳��
	glMatrixMode(GL_VIEWPORT);
	glLoadIdentity();
	glViewport(0, 0, w, h);

	// ���� ��ȯ �缳��
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLdouble)w / h, 0.1, 1000);
}


// Ű���� �ݹ�

void keyboard(unsigned char key, int x, int y);


// Ÿ�̸� �ݹ�

void input_timer(int value);

void motion_timer(int value);


// ���� �Լ�

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	// ������ ����
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Ÿ��Ʋ, �ݹ� ����
	glutCreateWindow("Running Fox");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000 / FRAMERATE, input_timer, 0);
	glutTimerFunc(1000 / FRAMERATE, motion_timer, 0);

	// ���η��� ����
	glutMainLoop();

	return 0;
}



// �׸��� �Լ�

void leg() {

	glPushMatrix();
	glTranslated(0, -1.0, 0);
	glScaled(0.5, 0.7, 0.5);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -1.5, 0);
	glRotated(40 * cos(phase - PI / 4), 0, 0, 1);
	glScaled(0.5, 0.7, 0.5);
	glTranslated(0, -1, 0);
	glutSolidSphere(1, 30, 30);

	glPushMatrix();
	glTranslated(1, -1.0, 0);
	glScaled(1, 0.1, 0.1);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

void animal() {

	// [ ���� ]
	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 0, 1, 0);
	glScaled(4, 1, 2);
	glutSolidSphere(1, 30, 30);

	// [ ���� ]
	glPushMatrix();
	glTranslated(-1.5, 0.5, 0);
	glScaled(0.75, 1.0, 0.5);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
	glPopMatrix();

	// [ �� ]
	glPushMatrix();
	glTranslated(4.2, 0.5, 0);
	glRotated(50, 0, 0, 1);
	glScaled(0.7, 0.4, 0.4);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	// [ �Ӹ� ]
	glPushMatrix();
	glTranslated(5.2, 1.2, 0);
	glRotated(0, 0, 0, 1);
	glScaled(1.0, 0.7, 0.7);
	glutSolidSphere(1, 30, 30);

	// [ ���� �� ]
	glPushMatrix();
	glTranslated(0, 1.0, 0.5);
	glScaled(0.2, 0.7, 0.2);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.0, -0.5);
	glScaled(0.2, 0.7, 0.2);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	// [ �� ]
	glPushMatrix();
	glTranslated(1.0, 0.3, 0.0);
	glScaled(0.2, 0.2, 0.3);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
	glPopMatrix();

	// [ �޴ٸ� ]

	glPushMatrix();
	glTranslated(-3.5, 0, 0);		// �ٸ� ��ġ

	// ���� �޴ٸ�
	glPushMatrix();
	glTranslated(0, 0, -0.7);
	glRotated(sin(phase + PI / 6 + PI / 3) * 35, 0, 0, 1);	// �ٸ� ����
	leg();
	glPopMatrix();

	// ������ �޴ٸ�
	glPushMatrix();
	glTranslated(0, 0, 0.7);
	glRotated(sin(phase + PI / 6) * 35, 0, 0, 1);		// �ٸ� ����
	leg();
	glPopMatrix();

	glPopMatrix();

	// [ �մٸ� ]

	glPushMatrix();
	glTranslated(3.5, 0, 0);		// �ٸ� ��ġ

	// ���� �մٸ�
	glPushMatrix();
	glTranslated(0, 0, -0.7);
	glRotated(-sin(phase) * 60, 0, 0, 1);	// �ٸ� ����
	leg();
	glPopMatrix();

	// ������ �մٸ�
	glPushMatrix();
	glTranslated(0, 0, 0.7);
	glRotated(-sin(phase + PI / 4) * 60, 0, 0, 1);		// �ٸ� ����
	leg();
	glPopMatrix();

	glPopMatrix();

}

// Ÿ�̸� �ݹ�

void input_timer(int value) {

	// ī�޶��� ��ġ (����ǥ�� �̿�) �� ���콺�� �̵� ������ ���� �ű��.

	static int init = 0;
	if (init == 0 && is_mouselooking) {          // �ʱⰪ
		init = 1;
		SetCursorPos(500, 500);
		glutTimerFunc(1000 / FRAMERATE, input_timer, 0);
		return;
	}

	if (is_mouselooking) {

		POINT cursor;
		GetCursorPos(&cursor);

		// Ŀ�� �̵� ���� ���ϱ�
		int xOffset, yOffset;
		xOffset = (cursor.x - 500);
		yOffset = (cursor.y - 500);

		// Ŀ�� �̵� �����κ��� yaw (�� ����), pitch (���Ʒ� ����) ������Ʈ
		yaw += xOffset / 100.0f;
		pitch -= yOffset / 100.0f;
		if (pitch > PI - 0.1) {
			pitch = PI - 0.1;
		}
		else if (pitch < 0.1) {
			pitch = 0.1;
		}

		glutPostRedisplay();
		SetCursorPos(500, 500); // 
		ShowCursor(FALSE);
	}
	else {
		init = 0;
		ShowCursor(TRUE);
	}

	glutTimerFunc(1000 / FRAMERATE, input_timer, 0);

}

void motion_timer(int value) {
	phase += 2 * PI / FRAMERATE;
	glutPostRedisplay();
	glutTimerFunc(1000 / FRAMERATE, motion_timer, 0);
}

// Ű���� �ݹ�

void keyboard(unsigned char key, int x, int y)
{
	switch (tolower(key))
	{
	case 'q':
	case 'Q':
		// ���콺 ��ŷ ���¸� �����Ѵ�.
		if (is_mouselooking == false)
			is_mouselooking = true;
		else
			is_mouselooking = false;
		break;
	case 27:
		exit(EXIT_SUCCESS);
		break;
	}
}