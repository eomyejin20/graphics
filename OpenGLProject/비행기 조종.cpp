/******************************************************************************/
/*                               HW#8 :���������                             */
/* �ۼ��� : XXX                                 ��¥ : 2020�� 12�� 08��        */
/*                                                                            */
/* ���� ���� : ���ݱ��� ��� ������ ���� ����� ���� ������ ��������ϴ�.   */
/*             ���� ȭ�鿡�� ����Ŭ������ �޴��� ��� ��, ��, ���̵��� ���� */
/*             �� �� �ֽ��ϴ�. ���� ������ ���� ���콺 ����Ŭ������ ��������  */
/*             ������ ŵ�ϴ�. �� �� ȭ���� ��ȯ�ǰ� ������ ���۵˴ϴ�.        */
/*                                                                            */
/*             w,a,s,d�� ��ü�� �����¿�� �����̸� ����Ű�� �þ߸� �����մϴ�*/
/*             �տ� ���̴� ��ֹ��� ���� ������ WireCube�� �����ϸ� �����Դϴ�*/
/******************************************************************************/

#include <GL/glut.h>
#include<cstdlib>
#include<ctime>

// ���� ���� �۶��̴� ���� ����� �����۵��� �ִ��� ���� ȹ���ϰ� ���������� Ÿ�̹��� ���� �����ϱ�

int Width;			// window�� ����
int Height;			// window�� ���� 
int start = 0;

GLfloat eyeupdown = 0, eyeside = 0;     //�þ� ����
GLfloat movego = 0, moveup = 0, moveside = 0;    //��ü �̵� ����
GLfloat buttonup = 0, next = 0, noeye = 0, convert = 0;   //ȭ�� ��ȯ ����
GLfloat mode = 1, modelnum = 1, modelcolor = 0;     // �޴� ����
GLfloat turnsight = 0, sightcheck = 0, sightstate;   // ��ü�� ����� ����
GLfloat noticecolor1 = 1, noticecolor2 = 0;   //����ȭ�� ������ ��ư ��
GLdouble Widthfactor;			// window�� ��ȭ�� ���� Width�� ��ȭ��
GLdouble Heightfactor;			// window�� ��ȭ�� ���� Height�� ��ȭ��
GLUquadricObj* qobj = gluNewQuadric();

//����� �� ���� �Լ�
int randomcolor() {                 //����� ���� �����ϰ� �ٲ��ֱ� ���� 0 ~ 9�� ���� ���� �޾ƿɴϴ�.
	srand((unsigned int)time(NULL));

	int num = rand();
	return num % 10;
}

//�޴� ���̵� ���� �Լ�
void Difficulty(int entryID) {         //�޴����� ���̵��� �����մϴ�.
	if (entryID == 1) {
		mode = 1;
	}
	else if (entryID == 2) {
		mode = 1.5;
	}
	else if (entryID == 3) {
		mode = 2;
	}
	glutPostRedisplay();           // Display�Լ��� ��ȣ���Ͽ� �ٽ� �׸��� �׸��ϴ�.
}

//�޴� �� ��ü �Լ�
void ChangeModel(int entryID) {         //�޴����� ���� entryID�� ����� ���� �����մϴ�.
	if (entryID == 1) {
		modelnum = 1;
		glutPostRedisplay();
	}
	else if (entryID == 2) {
		modelnum = 2;
		glutPostRedisplay();

	}
	else if (entryID == 3) {
		modelnum = 3;
		glutPostRedisplay();
	}
	glutPostRedisplay();           // Display�Լ��� ��ȣ���Ͽ� �ٽ� �׸��� �׸��ϴ�.
}

// ���� �޴� �Լ�
void MyMainMenu(int entryID) {          //Mainmenu���� entryID�� 1���� ������ ����� ���� �ٲ�ϴ�.
	if (entryID == 1)
	{
		modelcolor = randomcolor();
	}
	if (entryID == 2)                   //entryID�� 5���� ������ ������ �����մϴ�.
		exit(0);
	glutPostRedisplay();           // Display�Լ��� ��ȣ���Ͽ� �ٽ� �׸��� �׸��ϴ�.
}

//�ʱ�ȭ �Լ�
void MyInit() {

	glMatrixMode(GL_PROJECTION);                // ���������� ���� ȭ�� �ְ���� �ذ��մϴ�.
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLint HardID = glutCreateMenu(Difficulty);    //Difficulty (���̵�)�� ���� submenu�� �����մϴ�.
	glutAddMenuEntry("Easy", 1);
	glutAddMenuEntry("Normal", 2);
	glutAddMenuEntry("Hard", 3);

	GLint ChangeID = glutCreateMenu(ChangeModel);    //Change Model�� ���� submenu�� �����մϴ�.
	glutAddMenuEntry("Model A", 1);
	glutAddMenuEntry("Model B", 2);
	glutAddMenuEntry("Model C", 3);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);    //MainMenu�� �����մϴ�.
	glutAddSubMenu("Difficulty", HardID);
	glutAddSubMenu("Change Model", ChangeID);
	glutAddMenuEntry("Change color", 1);
	glutAddMenuEntry("Exit", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

//���� ������ �˸� (ȭ��ǥ ���� ����)
void notice() {
	glColor3f(noticecolor1, noticecolor2, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.08, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.02, 0.0);
	glVertex3f(0.02, 0.0, 0.0);
	glVertex3f(0.01, 0.0, 0.0);
	glVertex3f(0.01, 0.03, 0.0);
	glVertex3f(-0.01, 0.03, 0.0);
	glVertex3f(-0.01, 0, 0.0);
	glVertex3f(-0.02, 0, 0.0);
	glEnd();
}

//���� ���� �׸��ϴ�
void Drawmap()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(turnsight, 1.0, 0.0, 0.0);

	glColor3f(0.7, 0.7, 0.7);  // �ٴ��� �׸��ϴ�.
	glPushMatrix();
	glRotatef(30, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(50, 0.0, 50);
	glVertex3f(50, 0.0, -50);
	glVertex3f(-50, 0.0, -50);
	glVertex3f(-50, 0.0, 50);
	glEnd();
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.1);
	glTranslatef(8, 1.3, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutWireCube(1);
	glPopMatrix();

	// ������ �ܰ�
	glPushMatrix();
	glColor3f(0.2, 0.0, 0.2);
	glTranslatef(6, 1.5, 0.0);
	glScalef(1, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.4, 0.3);
	glTranslatef(3, 3.0, 0.0);
	glScalef(0.5, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.8, 0.2);
	glTranslatef(3, 8.0, 0.0);
	glScalef(3, 8, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.0, 0.2);
	glTranslatef(0, 1.0, 0.0);
	glScalef(1, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();


	//3�ܰ�
	glPushMatrix();
	glColor3f(0.6, 1.0, 0.6);
	glTranslatef(-5, 3.0, -2.0);
	glScalef(1, 6, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6, 1.0, 0.6);
	glTranslatef(-5, 3.0, 2.0);
	glScalef(1, 6, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.0);
	glTranslatef(-5, 2.0, 0.0);
	glScalef(1, 4, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(-5, 8, 0.0);
	glScalef(1, 2, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	//2�ܰ�
	glPushMatrix();
	glColor3f(1.0, 0.2, 0.2);
	glTranslatef(-10, 1.0, 0.0);
	glScalef(1, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.4, 0.4);
	glTranslatef(-10, 6.0, 0.0);
	glScalef(1, 6, 6.0);
	glutSolidCube(1);
	glPopMatrix();


	//1�ܰ�
	glPushMatrix();
	glColor3f(0.2, 0.2, 1.0);
	glTranslatef(-15, 5.0, 5.0);
	glScalef(1, 10, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.2, 1.0);
	glTranslatef(-15, 5.0, -5.0);
	glScalef(1, 10, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 1.0);
	glTranslatef(-15, 5.0, 0.0);
	glScalef(1, 10, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

//ȭ�� ��ȯ �Լ�
void Converting(int value) {
	if (convert < 2.9999) {
		convert += 0.1;
		glutPostRedisplay();
		glutTimerFunc(30, Converting, 1);
	}
	else {
		next = 1;
		return;
	}
}

//���� ���� ȭ��
void Mygame(int value) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1 * Widthfactor, 1 * Widthfactor, -1 * Heightfactor, 1 * Heightfactor, -1.0, 5);	// ���������Լ��� ���ú��Ǹ� ��Ȳ�� �°� ��ȭ���� �ְ�� �ذ�
	gluPerspective(100, 1.0, 0.0, 100.0);		// ���� ������ ���� �������� �þ� Ȯ��

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	gluLookAt(-25.0 + movego, 3 + moveup, 0.0 + moveside, 5.0, 1.3 + eyeupdown, 0.0 + eyeside, 0.0, 1.0, 0.0);	// ���� ��ǥ�� ����
	Drawmap();

	if (modelnum == 1) {            // �޴����� �� A�� �����ϸ� ������� ����� �ٲ�ϴ�.
		glScalef(0.8, 0.8, 0.8);
		glPushMatrix();
		glColor3f(modelcolor, modelcolor / 2, modelcolor / 3);
		glBegin(GL_POLYGON);
		glVertex3f(-24.0 + movego, 2.0 + moveup, 0.0 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, 0.4 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, -0.4 + moveside);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(-22.3 + movego, 2.0 + moveup, 0.0 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, 0.2 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, -0.2 + moveside);
		glEnd();

		glPopMatrix();
	}
	else if (modelnum == 2) {       // �޴����� �� A�� �����ϸ� ������� ����� �ٲ�ϴ�.
		glScalef(0.8, 0.8, 0.8);
		glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_POLYGON);
		glVertex3f(-23.0 + movego, 2.0 + moveup, 0.2 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, -0.2 + moveside);
		glVertex3f(-24.0 + movego, 2.0 + moveup, -0.2 + moveside);
		glVertex3f(-24.0 + movego, 2.0 + moveup, 0.2 + moveside);
		glEnd();

		glColor3f(modelcolor, modelcolor / 2, modelcolor / 3);
		glBegin(GL_POLYGON);
		glVertex3f(-23.2 + movego, 2.0 + moveup, 0.1 + moveside);
		glVertex3f(-23.2 + movego, 2.0 + moveup, -0.1 + moveside);
		glVertex3f(-23.8 + movego, 2.0 + moveup, -0.1 + moveside);
		glVertex3f(-23.8 + movego, 2.0 + moveup, 0.1 + moveside);
		glEnd();

		glPopMatrix();
	}
	else if (modelnum == 3) {       // �޴����� �� A�� �����ϸ� ������� ����� �ٲ�ϴ�.
		glScalef(0.8, 0.8, 0.8);
		glPushMatrix();
		glTranslatef(-5 + movego, 2.0 + moveup, 0.0 + moveside);
		glColor3f(modelcolor, modelcolor / 2, modelcolor / 3);
		gluSphere(qobj, 1.0, 20, 20);
		glPopMatrix();
	}
	glPopMatrix();

	glFlush();

}

//ó�� ���� ȭ�� (������ ��� ���)
void Mymain() {

	if (next == 0) {
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		notice();   //������ ��ư ���

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1 * Widthfactor, 1 * Widthfactor, -1 * Heightfactor, 1 * Heightfactor, -1.0, 5);	// ���������Լ��� ���ú��Ǹ� ��Ȳ�� �°� ��ȭ���� �ְ�� �ذ�

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.3, 0);
		glVertex3f(0.5, -0.3, 0);
		glVertex3f(0.5, 0.3, 0);
		glVertex3f(0.3, 0.5, 0);
		glVertex3f(-0.3, 0.5, 0);
		glVertex3f(-0.5, 0.3, 0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.4, 0.3, 0);
		glVertex3f(0.25, 0.45, 0);
		glVertex3f(-0.25, 0.45, 0);
		glVertex3f(-0.4, 0.3, 0);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.05, 0.3, 0);
		glVertex3f(0.03, 0.8, 0);
		glVertex3f(-0.03, 0.8, 0);
		glVertex3f(-0.05, 0.3, 0);
		glEnd();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(-1.3, 0.0, 0.0);
		gluDisk(qobj, 0.7, 0.8, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(1.3, 0.0, 0.0);
		gluDisk(qobj, 0.7, 0.8, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(-1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.7, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.7, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(-1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.15, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.15, 20, 2);
		glPopMatrix();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.02, 0.05, 0);
		glVertex3f(-0.02, 0.05, 0);
		glVertex3f(-0.02, -0.05, 0);
		glVertex3f(0.02, -0.05, 0);
		glEnd();

		glColor3f(0.8, 0.8, 0.8);
		glBegin(GL_POLYGON);
		glVertex3f(0.02, 0.00 + buttonup, 0);
		glVertex3f(-0.02, 0.00 + buttonup, 0);
		glVertex3f(-0.02, -0.04 + buttonup, 0);
		glVertex3f(0.02, -0.04 + buttonup, 0);
		glEnd();

		glPushMatrix();
		notice();
		glPopMatrix();

		glColor3f(1.0, 1.0, 1.0);
		gluDisk(qobj, 3 - convert, 5, 30, 3);

		glFlush();
	}
	else glutTimerFunc(2000, Mygame, 1);
}

// �۶��̴��� ��, �¿������ �����ϱ� ���� Ű���� �Է��� �޽��ϴ�.
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'W':
	case 'w':                       //W �Ǵ� w�� ������ �հ� ���� �̵��մϴ�.          
		movego += 0.01;
		moveup += 0.05;
		sightcheck = 0;
		break;
	case 'S':
	case 's':                       //S �Ǵ� s�� ������ ������ �̵��մϴ�.
		moveup -= 0.01;
		break;
	case 'A':
	case 'a':                       //A �Ǵ� a�� ������ �������� �̵��մϴ�.
		moveside -= 0.02;
		sightcheck = 1;
		break;
	case 'D':
	case 'd':                       //D �Ǵ� d�� ������ �������� �̵��մϴ�.
		moveside += 0.02;
		sightcheck = -1;
		break;
	case 'Q':                   // q �Ǵ� Q�� �Է¹����� ���α׷��� �����մϴ�.
	case 'q':
		exit(0);
		break;
	case 27:                    // ESC�� �Է¹����� ���α׷��� �����մϴ�.
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();           // Display�Լ��� ��ȣ���Ͽ� �ٽ� �׸��� �׸��ϴ�.
}

// �۶��̴��� ������ �����ϱ� ���� Ű���� �Է��� �޽��ϴ�.
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:        // ��������Ű�� ������ �������� �ٶ󺾴ϴ�.
		eyeside += 0.1;
		break;
	case GLUT_KEY_LEFT:          // ��������Ű�� ������ ������ �ٶ󺾴ϴ�.
		eyeside -= 0.1;
		break;
	case GLUT_KEY_UP:           // ������Ű�� ������ ������ �ٶ󺾴ϴ�.
		eyeupdown += 0.2;

		break;
	case GLUT_KEY_DOWN:        // �Ʒ�����Ű�� ������ �Ʒ����� �ٶ󺾴ϴ�.
		eyeupdown -= 0.2;
		break;
	default:
		break;
	}
	glutPostRedisplay();                //Display�Լ��� ��ȣ���Ͽ� �׸��� �ٽ� �׸��ϴ�.
}

// ���콺�� ����Ŭ���ϸ� ����ȭ�鿡�� ����ȭ������ �̵��մϴ�.
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP)
	{
		buttonup = 0.04;
		noticecolor1 = 0;
		noticecolor2 = 1;
		glutTimerFunc(500, Converting, 1);
	}
	glutPostRedisplay();
}

//����� �̵� �Լ�
void MoveToFront(int value) {
	if (movego <= 29) {               // ���������� �����̵� �մϴ�.
		movego += 0.02*mode;         // ���̵��� ���� ���� �ӵ��� �ٲ�ϴ�.
		glutPostRedisplay();
		glutTimerFunc(50, MoveToFront, 1);
	}
	else {                      //�������� �����ϸ� ������ ����ϴ�.
		noeye = movego;
		return;
	}
}

//����� �ϰ� �Լ�
void Moveupdown(int value) {
	if (moveup > -1.0) {        // �ϴÿ��� �������� �ֱ⿡ �������� �ϰ��� ��Ÿ���ϴ�.
		moveup -= 0.01;
		glutPostRedisplay();
		glutTimerFunc(100, Moveupdown, 1);
	}
	else return;
}

//�þ� �̵� �Լ�
void EyeDown(int value) {
	if (noeye == 0) {               //�������� ������, ������ ���̻� ������ �ʽ��ϴ�.
		if (eyeupdown > -5.0) {      //������ �ٴ��� �� �� ���� ���������� ������ �����ϴ�.
			eyeupdown -= 0.3;
			glutPostRedisplay();
			glutTimerFunc(50, EyeDown, 1);
		}
	}
	else return;
}

//ȸ���� ���� �þ� ���� �Լ�
void Sight(int value) {     // Ű���� �Է¿� ���� ��ȸ��, ��ȸ��, ���� 3������ ��츦 �ľ��Ͽ� Timer�Լ� ��� ����
	value = sightcheck;
	if (value == -1)        //��ȸ���ϴ� ���
	{
		turnsight -= 0.2;       // ��ü�� �������� ����Դϴ�.
		sightstate = sightcheck;    //�������� �̵��ϰ� ������ �����մϴ�.
		glutPostRedisplay();
		glutTimerFunc(100, Sight, sightstate);
	}
	else if (value == 1)     //��ȸ���ϴ� ���
	{
		turnsight += 0.2;       // ��ü�� �������� ����Դϴ�.
		sightstate = sightcheck;    //�������� �̵��ϰ� ������ �����մϴ�.
		glutPostRedisplay();
		glutTimerFunc(100, Sight, sightstate);
	}
	else                  // ���� �ϴ� ���
	{
		sightstate = sightcheck;
		glutPostRedisplay();
		glutTimerFunc(100, Sight, sightstate);
	}
}

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	Width = w;	// viewport�� ũ�⵵ ���� ������ ���ؾ� �ϱ� ������ Width, Height�� ��� ����
	Height = h;
	Widthfactor = (GLfloat)Width / (GLfloat)700;	// Widht�� Height ��ȭ��
	Heightfactor = (GLfloat)Height / (GLfloat)700;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //�����츦 �����ϰ� GLUT ���̺귯���� �ʱ�ȭ�մϴ�.
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);      //RGB���� ����ϵ��� ȭ���带 �����մϴ�.
	glutInitWindowSize(1200, 1200);       //ȭ���� ũ�⸦ �����մϴ�.
	glutInitWindowPosition(300, 0);       //ȭ���� ��ġ�� �����մϴ�.
	glutCreateWindow("Glider simulator");  //"Menu Callback" �̶�� �̸��� ȭ���� �����մϴ�.
	MyInit();                           //MyInit�Լ��� ȣ���մϴ�. (�������� �ʱ�ȭ �� ������ �մϴ�.)
	glutMouseFunc(MyMouseClick);        // ó�� ���콺 Ŭ���� ������ �����մϴ�.
	glutKeyboardFunc(MyKeyboard);       // �۶��̴��� ��, �¿������ �����ϱ� ���� Ű���� �Է��� �޽��ϴ�.
	glutSpecialFunc(MySpecial);         // �۶��̴��� ������ �����ϱ� ���� Ű���� �Է��� �޽��ϴ�.
	glutReshapeFunc(MyReshape);         // ������ �׸��� �ٽ� �׸��ϴ�.
	glutDisplayFunc(Mymain);            // ������ ����ȭ���� ����մϴ�.
	glutTimerFunc(100, MoveToFront, 20);    //�۶��̴� ���� ���� Timer �ݹ��Լ� ���
	glutTimerFunc(100, Moveupdown, 1);      //�۶��̴� ���� �϶�Timer �ݹ��Լ� ���
	glutTimerFunc(100, EyeDown, 1);         //�۶��̴� ���� �Ʒ����� ���� ��ȭ Timer �ݹ��Լ� ���
	glutTimerFunc(50, Sight, 1);            // Ű���� �Է¿� ���� �۶��̴� ���� Timer �ݹ��Լ� ���
	glutMainLoop();                     //Main�Լ��� �����մϴ�.
	return 0;
}