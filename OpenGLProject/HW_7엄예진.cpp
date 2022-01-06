/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#7. ���� Can Robot�� ���� ȿ�� ����                                                                                         */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 11�� 27��                                                         */


#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

/*���:
        �޸��� �þ߰��� ����                                                                                                                                                                      */
double limbAngle = 0.0; 
bool run = false;

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
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.11, 1.1, 0.15);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.12, 1.12, 0.2);
	glutSolidSphere(.03, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.12, 1.12, 0.2);
	glutSolidSphere(.03, 20, 20);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.121, 1.125, 0.222);
	glutSolidSphere(.01, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.121, 1.125, 0.222);
	glutSolidSphere(.01, 20, 20);
	glPopMatrix();
	

/*���:
	   �� �׸���                                                                                                                                                                                */
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
		�� �׸���                                                                                                                                                                                */
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 1.02, 0.29);
	glScaled(0.80, 0.80, 1.0);
	glutSolidSphere(.06, 20, 20);
	glPopMatrix();

/*���:
		���� �׸���                                                                                                                                                                                */
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.40, 0.0);
	glScaled(1.0, 1.5, 0.30);
	glutSolidCube(.50);
	glPopMatrix();

	
}

/*���:
		���� �׸���                                                                                                                                                                                */
void leftArm() {
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);
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
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);
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
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
/*���:
		�޽Ź� �׸���                                                                                                                                                                              */
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(-0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
}

/*���:
		�����ٸ� �׸���                                                                                                                                                                            */
void rightLeg() {
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
/*���:
		�����Ź� �׸���                                                                                                                                                                            */
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutSolidSphere(.1, 20, 20);
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
	        �κ� �׸���                                                                                                                                                                           */
void myDisplay(void) {
/*���:
		�𵨺���� ����                                                                                                                                                                             */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
/*���:
		��, ���� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (run == true) {
/*���:
		�޸� �� �κ� ���� ȸ��                                                                                                                                                                           */
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
		�ȴ޸� �� �κ� �׸���                                                                                                                                                                        */
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
/*���:
		��, ���� ���� ����                                                                                                                                                                        */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	switch (key)
	{
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
		���ο� Window Graphics ���� ���� Can Robot ����                                                                                                                                           */
	glutCreateWindow("���� ���� Can Robot");
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
		���� Ȱ��ȭ                                                                                                                                                         */
	glEnable(GL_LIGHTING);
/*���:
		ù ��° ���� ���                                                                                                                                                         */
	glEnable(GL_LIGHT0);
/*���:
		���� �� �ε巴�� ����                                                                                                                                                         */
	glShadeModel(GL_SMOOTH);
/*���:
		���� ���� Ȱ��ȭ                                                                                                                                                       */
	glEnable(GL_DEPTH_TEST);
/*���:
		�ڵ����� ������������ ���ϱ�                                                                                                                                                         */
	glEnable(GL_NORMALIZE);
/*���:
		���� ���߾ ���� ����                                                                                                                                                         */
	glEnable(GL_COLOR_MATERIAL);
/*���:
		�κ��� �ݽð������ �������� ����                                                                                                                                                         */
	glFrontFace(GL_CCW);
/*���:
			�κ��� �ĸ��� ����                                                                                                                                                         */
	glCullFace(GL_BACK);
/*���:
			�κ��� �ĸ����� Ȱ��ȭ                                                                                                                                                         */
	glEnable(GL_CULL_FACE);
/*���:
		���̴� �κ��� �ո�� �޸鿡 LINE ����                                                                                                                                                         */
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	

	myInit();
	glutMainLoop();
}
/**************************************************************************************************************************************************************************************************/