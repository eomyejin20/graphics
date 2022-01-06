/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#4-2. ���� �κ� �𵨸�                                                                                                      */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 11�� 1��                                                          */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
/*���:
		�þ߰�                                                                                                                                                                                    */
double horizAngle = 0.0;	
double vertAngle = 0.0;	
/*���:
		�ȴ� ����                                                                                                                                                                                 */
double limbAngle = 0.0; 
bool walk = false;
GLboolean arm = true;
GLboolean leg = true;
/*���� ����:
			���� �κ� �׸���                                                                                                                                                                      */
void drawRobot() {
/*���:
		�Ӹ� �׸���                                                                                                                                                                               */
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
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
/*���:
		������� ����                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
/*���:
		���� ��������� �׵���ķ� �ʱ�ȭ                                                                                                                                                         */
	glLoadIdentity();
/*���:
	   ��ĺ�ȯ                                                                                                                                                                                   */
	glOrtho(-2.0*(64 / 48.0), 2.0*(64 / 48.0), -2.0, 2.0, 0.1, 100.0); //left, right, bottom, top, near, far Parallel Projection
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
			�ȱ� ���� ����                                                                                                                                                                         */
void Walk(void)
{
/*���:
	   ���� � ����                                                                                                                                                                              */
	static float mf = 0.05;

	limbAngle += mf;

	if (limbAngle > 30.0) {
		mf = -0.70;
	}
	if (limbAngle < -30.0) {
		mf = 0.70;
	}
	glutPostRedisplay();
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
		arm�̸� ���� ������                                                                                                                                                                         */
	if (arm == true) {
/*���:
		�κ� ���� ȸ��                                                                                                                                                                              */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		glPopMatrix();
/*���:
	   ���� �׸��� ����                                                                                                                                                                             */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		glTranslated(-0.30, 1.0, 0.0);
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(0.30, -1.0, 0.0);
		leftArm();
		glPopMatrix();
/*���:
		������ �׸���                                                                                                                                                                               */
		rightArm();
		glPopMatrix();
/*���:
		�޴ٸ� �׸���                                                                                                                                                                                */
		leftLeg();
		glPopMatrix();
/*���:
		�����ٸ� �׸���                                                                                                                                                                              */
		rightLeg();
		glPopMatrix();
	}


/*���:
		arm�� �ƴϸ� ������ ������                                                                                                                                                                   */
		else if (arm == false) {
/*���:
		�κ� ���� ȸ��                                                                                                                                                                               */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
/*���:
		���� �׸���                                                                                                                                                                                  */
			leftArm();
			glPopMatrix();

/*���:
		������ �׸��� ����                                                                                                                                                                           */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			glTranslated(0.30, 1.0, 0.0);
			glRotated(-limbAngle, 1.0, 0.0, 0.0f);
			glTranslated(-0.30, -1.0, 0.0);
			rightArm();
			glPopMatrix();
/*���:
		�޴ٸ� �׸���                                                                                                                                                                                */
			leftLeg();
			glPopMatrix();
			//Right leg walking movement
			glPushMatrix();
/*���:
		�����ٸ� �׸���                                                                                                                                                                              */
			rightLeg();
			glPopMatrix();

		}
/*���:
		leg��  �޴ٸ� ������                                                                                                                                                                         */
		else if (leg == true) {
/*���:
		�κ� ���� ȸ��                                                                                                                                                                               */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
/*���:
		���� �׸���                                                                                                                                                                                  */
			leftArm();
			glPopMatrix();
/*���:
		������ �׸���                                                                                                                                                                                */
			rightArm();
			glPopMatrix();
/*���:
		�޴ٸ� �׸��� ����                                                                                                                                                                           */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			glRotated(-limbAngle, 1.0, 0.0, 0.0f);
			leftLeg();
			glPopMatrix();
/*���:
		�����ٸ� �׸���                                                                                                                                                                              */
			rightLeg();
			glPopMatrix();
		}
/*���:
		leg �ƴϸ� �����ٸ� ������                                                                                                                                                                   */
		else if (leg == false) {
/*���:
		�κ� ���� ȸ��                                                                                                                                                                               */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
/*���:
		���� �׸���                                                                                                                                                                                  */
			leftArm();
			glPopMatrix();
/*���:
		������ �׸���                                                                                                                                                                                */
			rightArm();
			glPopMatrix();
/*���:
		�޴ٸ� �׸���                                                                                                                                                                                */
			leftLeg();
			glPopMatrix();
/*���:
		�����ٸ� �׸��� ����                                                                                                                                                                         */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			glRotated(limbAngle, 1.0, 0.0, 0.0f);
			rightLeg();
			glPopMatrix();
		}
/*���:
		���߱�                                                                                                                                                                                       */
		else {
/*���:
		�κ� ���� ȸ��                                                                                                                                                                               */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		glPopMatrix();
/*���:
		���� �׸���                                                                                                                                                                                  */
		leftArm();
		glPopMatrix();
/*���:
		������ �׸���                                                                                                                                                                                */
		rightArm();
		glPopMatrix();
/*���:
	   �޴ٸ� �׸���                                                                                                                                                                                 */
		leftLeg();
		glPopMatrix();
/*���:
		�����ٸ� �׸���                                                                                                                                                                              */
		rightLeg();
		glPopMatrix();
		}
		glFlush();
/*���:
       ������ ���ο� �׸��� ������ �ʴ� ���ۿ� �׷����� �׸��Ⱑ �Ϸ�Ǹ� ���÷��̰� �׸����� ��ȯ�˴ϴ�.                                                                                          */
		glutSwapBuffers();
	
}
/*���� ����:
			���θ޴� �Լ� ���                                                                                                                                                                       */
void MyMainMenu(int entryID) {
/*���:
		���� ����                                                                                                                                                                                    */
	if (entryID == 1)
		arm = true;
/*���:
		������ ����                                                                                                                                                                                  */
	else if (entryID == 2)
		arm = false;
/*���:
		�޴ٸ� ����                                                                                                                                                                                  */
	else if (entryID == 3)
		leg = true;
/*���:
		�����ٸ� ����                                                                                                                                                                                */
	else if (entryID == 4)
		leg = false;
	glutPostRedisplay;
}
/*���� ����:
			Ű���� �Լ� ���                                                                                                                                                                         */
void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static double zoomFactor = 1.0;	//Zooming in/out 
	static double zoomFactor2 = 1.0;

	switch (key)
	{
/*���:
		S �Է� �� ���� ���߱�                                                                                                                                                                        */
	case 'S':
		if (arm == true) {

			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
			
			leftArm();
			glPopMatrix();

			rightArm();
			glPopMatrix();

			leftLeg();
			glPopMatrix();

			rightLeg();
			glPopMatrix();
		
		glFlush();
		glutSwapBuffers();
		break;

		}
	case 'e':
		exit(0);			
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
		���ο� Window Graphics Timer Callback ���� ����                                                                                                                                           */
	glutCreateWindow("Give me your candy Kid!!!");
/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(myDisplay);
	glutIdleFunc(Walk);	
/*���:
		�̺�Ʈ Ÿ�� Keyboard callback �Լ�                                                                                                                                                         */
	glutKeyboardFunc(myKeyboard);	//myKeyboard will handle normal keys
/*���:
		���� �޴��� �޴� �׸� ÷��                                                                                                                                                                */
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Head", 0);
	glutAddMenuEntry("left arm", 1);
	glutAddMenuEntry("right arm", 2);
	glutAddMenuEntry("right leg", 3);
	glutAddMenuEntry("left leg", 4);
/*���:
		���콺 ������ ��ư�� ������ �� �޴� �˾�                                                                                                                                                               */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
/*���:
		���� ���� ��ġ ���� ���� ����                                                                                                                                                             */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	myInit();
	glutMainLoop();
}
/**************************************************************************************************************************************************************************************************/