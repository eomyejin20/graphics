void MySubMenu_Change_Color(int entryID) {
	if (entryID == 1)
		Red = true; // ���� ũ��� �׸���
	else if (entryID == 2)
		Green = false; // ū ũ��� �׸���
	else if (entryID == 2)
		Blue =

		glutAddSubMenu("Change Color", MySubMenuID_Change_Color);
		GLint MySubMenuID_Change_Color = glutCreateMenu(MySubMenu_Change_Color);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 2);


		glutPostRedisplay();


		void MySubMenu_Change_Color(int entryID) {
			if (entryID == 1)
				glColor3f(1.0f, 0.0f, 0.0f);
			else if (entryID == 2)
				glColor3f(0.0f, 1.0f, 0.0f);
			else if (entryID == 3)
				glColor3f(0.0f, 0.0f, 1.0f);
			else
				glColor3f(0.5f, 0.5f, 0.5f);

			glutPostRedisplay();
		}
		GLint MySubMenuID_Change_Color = glutCreateMenu(MySubMenu_Change_Color);
		glutAddMenuEntry("Red", 8);
		glutAddMenuEntry("Green", 9);
		glutAddMenuEntry("Blue", 10);
		glutAddMenuEntry("Change Color", MySubMenuID_Change_Color);
}
#include <gl/glut.h>
#include <stdio.h>

static GLfloat spin = 0.0; // ȸ�� �� �ʱ�ȭ
static GLclampf red = 1.0; // Red�� �ʱ�ȭ
static GLclampf green = 1.0; // Green�� �ʱ�ȭ
static GLclampf blue = 1.0; // Blue�� �ʱ�ȭ
static GLbyte turn = 0; // turn�� �ʱ�ȭ

void init(void) // �ʱ�ȭ �Լ�
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Clear��ɽ� �ʱ�ȭ�� �� ����
	glShadeModel(GL_FLAT); //
}

void display(void) // Display �Լ�
{
	glClear(GL_COLOR_BUFFER_BIT); // ������ ȭ�� Ŭ����
	glPushMatrix(); //
	glRotatef(spin, 0.0, 0.0, 1.0); //
	glColor3f(red, green, blue); // ������
	glRectf(-25.0, -25.0, 25.0, 25.0); // �簢�� �׸���
	glPopMatrix();
	glutSwapBuffers(); // ���� ��ü
}


void MoveMouse(void)
{
	spin = spin + 2.0; // ȸ����(spin) ����

	if (spin > 360.0)
	{
		spin = spin - 360; // 1ȸ���� ȸ���� �ʱ�ȭ
	}
	


	glutPostRedisplay(); //�̰� glutMainLoop()��Ƽ ��ϵ� ���÷��� �ݹ��� �㿡 �϶�� �����ϴ°�

}

void reshape(int w, int h) //������ ��ȭ�ÿ� ���� Call Back �Լ�
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); // ��ǥ�� ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void mouse(int button, int state, int x, int y) // ���콺 �̺�Ʈ ó�� Call Back �Լ�
{
	switch (button) {

	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) // ���� ���Ⱦ�?
			glutIdleFunc(spinDisplay); // �׶�� spinDisplay ������
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) // ������ ���ȱ���?
			glutIdleFunc(NULL); // �׶�� �� ���׷���..(�Ͻ�����)
		break;
	}
}

int main(int argc, char** argv) // �̰Ž� �����̿�..
{
	glutInit(&argc, argv); // Glut �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // glut ���÷��� ��� ����(����������, RGB��� bitmap)
	glutInitWindowSize(250, 250); // ������ ������ �ʱ�ȭ
	glutInitWindowPosition(100, 100); // ������ �ʱ� ��ġ �ʱ�ȭ
	glutCreateWindow(argv[0]); // ������ ������Ű��.
	init(); // init�Լ� ���� ����������� �ʱ�ȭ
	glutDisplayFunc(display); // �ݹ��Լ� ���
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop(); // MainLoop()����


	return 0;
}



void MyIdle2() {
	trans_left = trans_left + 0.001;

	glutPostRedisplay();
}

void MyIdle3() {
	trans_up = trans_up + 0.001;

	glutPostRedisplay();
}

void MyIdle4() {
	trans_up = trans_up - 0.001;

	glutPostRedisplay();
}

case GLUT_KEY_RIGHT:     //������ Ű
	glutIdleFunc(MyIdle2);
	if (trans_left > 0.5)  trans_left -= 0.1;
	glutPostRedisplay();
	break;
case GLUT_KEY_UP:      //�� Ű
	glutIdleFunc(MyIdle3);
	if (trans_up > 0.5)  trans_up -= 0.1;
	glutPostRedisplay();
	break;
case GLUT_KEY_DOWN:      //�Ʒ� Ű
	glutIdleFunc(MyIdle4);
	if (trans_up < -0.5)  trans_up -= -0.1;
	glutPostRedisplay();
	break;
