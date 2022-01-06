/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#5-2. �𵨺� ��ȯ ���� �ǽ�                                                                                                      */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 11�� 4��                                                          */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
/*���:
		�þ߰�                                                                                                                                                                                    */
double horizAngle = 0.0;
double vertAngle = 0.0;

/*���� ����:
			���� �κ� �׸���                                                                                                                                                                      */
void drawRobot() {
/*���:
			�Ӹ� �׸���                                                                                                                                                                                      */
glColor3f(1.0, 1.0, 1.0);
glPushMatrix();
glTranslated(0.0, 1.0, 0.0);
glutWireSphere(.25, 20, 20);
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
glColor3f(1.0, 0.0, 0.0);
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
		���� �׸���                                                                                                                                                                                */
glColor3f(1.0, 1.0, 0.0);
glPushMatrix();
glTranslated(0.0, 0.40, 0.0);
glScaled(1.0, 1.5, 0.30);
glutWireCube(.50);
glPopMatrix();


}
/*���:
		���� �׸���                                                                                                                                                                                */
void leftArm() {
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(-0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();

/*���:
		�޼� �׸���                                                                                                                                                                               */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutWireSphere(.08, 20, 20);
	glPopMatrix();

}
/*���:
		������ �׸���                                                                                                                                                                             */
void rightArm() {
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);
	glPushMatrix();
	glTranslated(0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();

/*���:
		������ �׸���                                                                                                                                                                              */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutWireSphere(.08, 20, 20);
	glPopMatrix();
}
/*���:
		�޴ٸ� �׸���                                                                                                                                                                              */
void leftLeg() {
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
/*���:
			�޽Ź� �׸���                                                                                                                                                                              */
	glColor3f(1.0, 0.0, 0.0);
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
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
/*���:
		�����Ź� �׸���                                                                                                                                                                            */
	glColor3f(1.0, 0.0, 0.0);
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



void myDisplay(void) {
/*���:
		�𵨺���� ����                                                                                                                                                                             */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
/*���:
		��, ���̹��� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*���:
	   �κ� �ٽ� �׸���                                                                                                                                                                           */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		leftArm();
		rightArm();
		leftLeg();
		rightLeg();
		glPopMatrix();
	
/*���:
		���� 2�� ���                                                                                                                                                                         */
	glutSwapBuffers();
}


/*���� ����:
			Ű���� �Լ� ���                                                                                                                                                     */
void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*���:
		�� ��, �ƿ�                                                                                                                                                                         */
	static double zoomFactor = 1.0;	
	static double zoomFactor2 = 1.0;

	switch (key)
	{
/*���:
		z �Է� �� �� �ƿ�, Z �Է� �� �� ��                                                                                                                                                                        */
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
	case 'e':
		exit(0);			
	}

	
	glutPostRedisplay();		
}

/*���� ����:
			arrowKeyPress �Լ� ���                                                                                                                                                     */
void arrowKeyPress(int key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*���:
		������ Ű �Է� �� ������ �������� ����                                                                                                                                                                       */
	switch (key) {
	case GLUT_KEY_RIGHT:
		horizAngle += 2;
		break;
/*���:
		���� Ű �Է� �� ���� �������� ����                                                                                                                                                                       */
	case GLUT_KEY_LEFT:
		horizAngle -= 2;
		break;
/*���:
		���� Ű �Է� �� �� �������� ����                                                                                                                                                                       */
	case GLUT_KEY_UP:
		vertAngle -= 2;
		break;
/*���:
		�Ʒ��� Ű �Է� �� �Ʒ��� �������� ����                                                                                                                                                                       */
	case GLUT_KEY_DOWN:
		vertAngle += 2;
		break;
	}

	glutPostRedisplay();
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
		���ο� Window Graphics �𵨺� ��ȯ ���� ����                                                                                                                                           */
	glutCreateWindow("�𵨺� ��ȯ ����");
/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(myDisplay);
	

/*���:
		�̺�Ʈ Ÿ�� Keyboard callback �Լ�                                                                                                                                                         */
	glutKeyboardFunc(myKeyboard);
/*���:
		�̺�Ʈ Ÿ�� MySpecialKey callback �Լ�                                                                                                                                                    */
    glutSpecialFunc(arrowKeyPress);

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
	glEnable(GL_NORMALIZE);
/*���:
		glColor���� ������ ���� ����� ���� ���ڸ� ����                                                                                                                                                                       */
	glEnable(GL_COLOR_MATERIAL);	

	myInit();
	glutMainLoop();
}
/**************************************************************************************************************************************************************************************************/