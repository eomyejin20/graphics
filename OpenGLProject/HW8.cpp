/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#8. ����                                                                                                      */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 12�� 16��                                                          */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
/*���:
	   ���� ��ǥ�� ������ ������ȯ �μ�                                                                                                                                                           */
float ex = 0.0;
float ey = 3.5;
float ez = 3.5;
float cx, cy, cz, ux = 0.0;
float uy = 1.0;
float uz = 0.0;

/*���:
		�þ߰�                                                                                                                                                                                    */
double horizAngle = 0.0;
double vertAngle = 0.0;

/*���:
		�޸��� �þ߰��� ����                                                                                                                                                                      */
double limbAngle = 0.0;
bool run = false;

/*���� ����:
			��� �׸���                                                                                                                                                                      */
void drawRobot() {
	/*���:
				�Ӹ� �׸���                                                                                                                                                                                      */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 1.0, 0.0);
	glutSolidSphere(.25, 20, 20);
	glPopMatrix();

	/*���:
			�Ӹ�ī�� �׸���                                                                                                                                                                                 */
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 1.05, -0.10);
	glScaled(1.2, 0.5, 0.9);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	/*���:
			�� �׸���                                                                                                                                                                                 */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.11, 1.1, 0.15);
	glutWireSphere(.07, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.11, 1.1, 0.15);
	glutWireSphere(.07, 20, 20);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.12, 1.12, 0.2);
	glutWireSphere(.03, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.12, 1.12, 0.2);
	glutWireSphere(.03, 20, 20);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.121, 1.125, 0.222);
	glutWireSphere(.01, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.121, 1.125, 0.222);
	glutWireSphere(.01, 20, 20);
	glPopMatrix();
	 
	/*���:
			�� �׸���                                                                                                                                                                                 */

	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.92, 0.180);
	glScaled(2.0, 0.60, 1.0);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.92, 0.190);
	glRotated(20, 1.0, 0.0, 0.0);
	glScaled(2.04, 0.65, 0.6);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();

	/*���:
			���� �׸���                                                                                                                                                                                */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 0.40, 0.0);
	glScaled(1.0, 1.5, 0.30);
	glutSolidCube(.50);
	glPopMatrix();


}
/*���:
		���� �׸���                                                                                                                                                                                */
void leftArm() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(1.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(-0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();

	/*���:
			�޼� �׸���                                                                                                                                                                               */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();

}
/*���:
		������ �׸���                                                                                                                                                                             */
void rightArm() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(1.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();

	/*���:
			������ �׸���                                                                                                                                                                              */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();
}
/*���:
		�޴ٸ� �׸���                                                                                                                                                                              */
void leftLeg() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	/*���:
				�޽Ź� �׸���                                                                                                                                                                              */
	glColor3f(1.0, 0.6,10.0);
	glPushMatrix();
	glTranslated(-0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
}
/*���:
		�����ٸ� �׸���                                                                                                                                                                            */
void rightLeg() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	/*���:
			�����Ź� �׸���                                                                                                                                                                            */
	glColor3f(1.0, 0.6, 10.0);
	glPushMatrix();
	glTranslated(0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
}


void myInit() {
	/*���:
			â ���                                                                                                                                                                                   */
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	/*���:
			������� ����                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
	/*���:
			���� ��������� �׵���ķ� �ʱ�ȭ                                                                                                                                                         */
	glLoadIdentity();
	/*���:
			��ĺ�ȯ                                                                                                                                                                                   */
	glOrtho(-2.0*(64 / 48.0), 2.0*(64 / 48.0), -2.0, 2.0, 0.1, 100.0);
	glViewport(0, 0, 800, 640);

	/*���:
			ǥ������� �Ӽ� ����                                                                                                                                                                       */
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 50.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat lightIntensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_position[] = { 2.0f, 2.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

}

/*���� ����:
			�޸���                                                                                                                                                                           */
void Run(void)
{
	/*���:
			��, �ٸ� � ����                                                                                                                                                                             */
	static float mf = 0.05;

	limbAngle += mf;
	/*���:
			�޸��� ������ ���� �                                                                                                                                                                            */
	if (limbAngle > 30.0) {
		mf = -0.70;
	}
	if (limbAngle < -30.0) {
		mf = 0.70;
	}
	glutPostRedisplay();
}

/*���� ����:
			��� �׸���                                                                                                                                                                           */
void myDisplay(void) {
	/*���:
			�𵨺���� ����                                                                                                                                                                             */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*���:
			��, ���� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*���:
		������ǥ�� ���� �Լ�                                                                                                                                                                     */
	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
	glFlush();

	if (run == true) {
		/*���:
				�޸� �� ��� ���� ȸ��                                                                                                                                                                           */
		glPushMatrix();
		drawRobot();
		glPopMatrix();
		/*���:
				���� �ȱ� �                                                                                                                                                                           */
		glPushMatrix();
		glTranslated(-0.30, 1.0, 0.0);
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(0.30, -1.0, 0.0);
		leftArm();
		glPopMatrix();
		/*���:
				������ �ȱ� �                                                                                                                                                                           */
		glPushMatrix();
		glTranslated(0.30, 1.0, 0.0);
		glRotated(-limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(-0.30, -1.0, 0.0);
		rightArm();
		glPopMatrix();
		/*���:
				�޴ٸ� �ȱ� �                                                                                                                                                                           */
		glPushMatrix();
		glRotated(-limbAngle, 1.0, 0.0, 0.0f);
		leftLeg();
		glPopMatrix();
		/*���:
				�����ٸ� �ȱ� �                                                                                                                                                                           */
		glPushMatrix();
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		rightLeg();
		glPopMatrix();
	}

	else if (run == false) {
		/*���:
				�ȴ޸� �� ��� �׸���                                                                                                                                                                        */
		glPushMatrix();
		drawRobot();
		leftArm();
		rightArm();
		leftLeg();
		rightLeg();
		glPopMatrix();
	}

	/*���:
				���� 2�� ���                                                                                                                                                                         */
	glutSwapBuffers();
}


/*���� ����:
			Ű���� �Լ� ���                                                                                                                                                     */
void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*���:
			Ȯ��, ���                                                                                                                                                                         */
	static double zoomFactor = 1.0;
	static double zoomFactor2 = 1.0;

	switch (key)
	{
		/*���:
				z �Է� �� ���, Z �Է� �� Ȯ��                                                                                                                                                                       */
	case 'z':
		zoomFactor -= 0.02;
		zoomFactor2 += 7.7;
		glViewport(1.0 * zoomFactor2, 1.0 * zoomFactor2, 800 * zoomFactor, 640 * zoomFactor);
		break;
	case 'Z':
		zoomFactor += 0.02;
		zoomFactor2 -= 7.7;
		glViewport(1.0 * zoomFactor2, 1.0 * zoomFactor2, 800 * zoomFactor, 640 * zoomFactor);
		break;
	/*���:
		r,R �Է� �� �޸���                                                                                                                                                                        */
	case 'r':
		if (run == false) {
			run = true;
		}
		else if (run == true) {
			run = false;
		}
		break;
	case 'R':
		if (run == false) {
			run = true;
		}
		else if (run == true) {
			run = false;
		}
		break;
	case 'e':
		exit(0);
	}


	glutPostRedisplay();
}

/*���� ����:
			����� Ű���� �̺�Ʈ ���                                                                                                                                                            */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
		/*���:
				���� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                      */
	case GLUT_KEY_LEFT:
		/*���:
				���� Ű �Է� �� camera X�� ��ǥ ���������� 0.1�� ����                                                                                                                                    */
		ex = ex - 0.01;
		/*���:
				������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
		/*���:
				������ Ű �Է� �� ���������� 0.1�� �̵�                                                                                                                                                  */
	case GLUT_KEY_RIGHT:
		/*���:
				������ Ű �Է� �� camera X�� ��ǥ ���������� 0.1�� ����                                                                                                                                  */
		ex = ex + 0.01;
		/*���:
				������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
		/*���:
				�� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                        */
	case GLUT_KEY_UP:
		/*���:
				���� Ű �Է� �� camera Y�� ��ǥ ���������� 0.1�� ����                                                                                                                                    */
		ey = ey + 0.01;
		/*���:
				������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
		/*���:
				�Ʒ� Ű �Է� �� �Ʒ������� 0.1�� �̵�                                                                                                                                                    */
	case GLUT_KEY_DOWN:
		/*���:
				�Ʒ��� Ű �Է� �� camera Y�� ��ǥ ���������� 0.1�� ����                                                                                                                                  */
		ey = ey - 0.01;
		/*���:
				������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
	}

}


/*���� ����:
			������ �ʱ�ȭ                                                                                                                                                                         */
void main(int argc, char **argv) {
	/*���:
			Window OS�� Session ����                                                                                                                                                                  */
	glutInit(&argc, argv);
	/*���:
			Display Mode RGB, Double, Depth�� ����                                                                                                                                                           */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/*���:
			Window�� ũ�� ����                                                                                                                                                                        */
	glutInitWindowSize(800, 640);
	/*���:
			Monitor���� Window�� ������ ��ġ                                                                                                                                                          */
	glutInitWindowPosition(100, 100);
	/*���:
			���ο� Window Graphics ���� ����                                                                                                                                           */
	glutCreateWindow("����");
	/*���:
			�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(myDisplay);

	/*���:
		�̺�Ʈ Ÿ�� MyIdle callback �Լ��� �������� �޸��� ����                                                                                                                                                          */
	glutIdleFunc(Run);

	/*���:
			�̺�Ʈ Ÿ�� Keyboard callback �Լ�                                                                                                                                                         */
	glutKeyboardFunc(myKeyboard);
	/*���:
	       �̺�Ʈ Ÿ�� MySpecialKey callback �Լ�                                                                                                                                                              */                                                                                                                                              
	glutSpecialFunc(MySpecialKey);

	/*���:
			���� ��带 Ȱ��ȭ                                                                                                                                                                     */
	glEnable(GL_LIGHTING);
	/*���:
			0���� ���� Ȱ��ȭ                                                                                                                                                                      */
	glEnable(GL_LIGHT0);
	/*���:
		   �������� �����ذ��鼭 ä���                                                                                                                                                          */
	glShadeModel(GL_SMOOTH);
	/*���:
			���� ���� Ȱ��ȭ                                                                                                                                                                       */
	glEnable(GL_DEPTH_TEST);
	/*���:
		�ڵ����� ������������ ���ϱ�                                                                                                                                                         */

	glEnable(GL_NORMALIZE);
	/*���:
			glColor���� ������ ���� ����� ���� ���ڸ� ����                                                                                                                                                                       */
	glEnable(GL_COLOR_MATERIAL);
	/*���:
		����� �ݽð������ �������� ����                                                                                                                                                         */
	glFrontFace(GL_CCW);
	/*���:
				����� �ĸ��� ����                                                                                                                                                         */
	glCullFace(GL_BACK);
	/*���:
				����� �ĸ����� Ȱ��ȭ                                                                                                                                                         */
	glEnable(GL_CULL_FACE);
	/*���:
			���̴� ����� �ո�� �޸鿡 FILL ����                                                                                                                                                         */
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	myInit();
	glutMainLoop();
}
/**************************************************************************************************************************************************************************************************/