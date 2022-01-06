/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#4-1. �κ� ��-�� �𵨸�                                                                                                     */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 11�� 1��                                                          */

#include<GL/glut.h> 
/*���:
	   �κ� ��-�� �׸��� ���� ����                                                                                                                                                                */
GLUquadricObj* cyl;
int elbow = 70;
int fing1 = 0, fing2 = 0, fing3 = 0, fing4 = 0, fing5 = 0;
int fingnum = 0;
int state = 0;
int Pstate = 0;

void DrawShoulder();
void DrawElbow();
void DrawPalm();
void DrawFing1();
void DrawFing2();
void DrawFing3();
void DrawFing4();
void DrawFing5();

void MyDisplay() {
/*���:
		â ���                                                                                                                                                                                   */
	glClearColor(0.0, 0.0, 0.0, 1.0);
/*���:
		��, ���̹��� ����                                                                                                                                                                         */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*���:
		�𵨺���� ����                                                                                                                                                                           */
	glMatrixMode(GL_MODELVIEW);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                      */
	glLoadIdentity();

	DrawShoulder();

	glutSwapBuffers();
}
/*���� ����:
			Shoulder �׸���                                                                                                                                                                       */
void DrawShoulder() {
	glTranslatef(-1.0, 1.5, -2.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(-7.0, -1.0, -1.0, 0.0);
	cyl = gluNewQuadric(); gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.2, 0.2, 1.5, 4.0, 1.0);
	DrawElbow();
}
/*���� ����:
			Elbow �׸���                                                                                                                                                                           */
void DrawElbow() {
/*���:
		Shoulder ��ǥ push�ϱ�                                                                                                                                                                     */
	glPushMatrix(); 
	glTranslatef(-0.1, 0.0, 1.36);
	glRotatef(20, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 1.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.2, 0.2, 1.5, 4.0, 1.0);
/*���:
		Elbow ��ǥ pop�ϱ�                                                                                                                                                                         */
	DrawPalm(); glPopMatrix(); 

}
/*���� ����:
			Palm �׸���                                                                                                                                                                            */
void DrawPalm() {
/*���:
		Elbow ��ǥ push�ϱ�                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 1.65);
	glScalef(0.5, 0.2, 0.4);
	glutWireCube(1.0);
	glScalef(2.0, 1.0, 2.5);
	DrawFing1();
	DrawFing2();
	DrawFing3();
	DrawFing4();
	DrawFing5();
/*���:
		Falm ��ǥ pop�ϱ�                                                                                                                                                                           */
	glPopMatrix(); 
}
/*���� ����:
			finger1 �׸���                                                                                                                                                                          */
void DrawFing1()
{
/*���:
		Palm ��ǥ push�ϱ�                                                                                                                                                                          */
	glPushMatrix(); 
	glTranslatef(0.2, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*���:
		finger1 ��ǥ push�ϱ�                                                                                                                                                                       */
	glPushMatrix(); 
	glTranslatef(0.1, 0.0, 0.18);
	glRotatef((GLfloat)fing1, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*���:
		finger1-1 ��ǥ pop�ϱ�                                                                                                                                                                      */
	glPopMatrix();
/*���:
		finger1 ��ǥ pop�ϱ�                                                                                                                                                                        */
	glPopMatrix(); 
}
/*���� ����:
			finger2 �׸���                                                                                                                                                                          */
void DrawFing2() {
/*���:
		Palm ��ǥ push�ϱ�                                                                                                                                                                          */
	glPushMatrix(); 
	glTranslatef(0.1, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*���:
		finger2 ��ǥ push�ϱ�                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing2, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*���:
		finger2-1 ��ǥ pop�ϱ�                                                                                                                                                                       */
	glPopMatrix();
/*���:
		finger2 ��ǥ pop�ϱ�                                                                                                                                                                         */
	glPopMatrix(); 
}
/*���� ����:
			finger3 �׸���                                                                                                                                                                           */
void DrawFing3() {
/*���:
		Palm ��ǥ push�ϱ�                                                                                                                                                                           */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*���:
		finger3 ��ǥ push�ϱ�                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing3, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*���:
		finger3-1 ��ǥ pop�ϱ�                                                                                                                                                                       */
	glPopMatrix(); 
/*���:
		finger3 ��ǥ pop�ϱ�                                                                                                                                                                         */
	glPopMatrix(); 
}
/*���� ����:
			finger4 �׸���                                                                                                                                                                           */
void DrawFing4() {
/*���:
		Palm ��ǥ push�ϱ�                                                                                                                                                                           */
	glPushMatrix();  
	glTranslatef(-0.1, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*���:
		finger4 ��ǥ push�ϱ�                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing4, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*���:
		finger4-1 ��ǥ pop�ϱ�                                                                                                                                                                       */
	glPopMatrix(); 
/*���:
		finger4 ��ǥ pop�ϱ�                                                                                                                                                                         */
	glPopMatrix();
}
/*���� ����:
			finger5 �׸���                                                                                                                                                                           */
void DrawFing5() {
/*���:
		Palm ��ǥ push�ϱ�                                                                                                                                                                           */
	glPushMatrix();  
	glTranslatef(-0.2, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing5, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*���:
		finger5-1 ��ǥ pop�ϱ�                                                                                                                                                                       */
	glPopMatrix(); 
/*���:
		finger5 ��ǥ pop�ϱ�                                                                                                                                                                         */
	glPopMatrix(); 
}
/*���� ����:
			Ÿ�̸� ���                                                                                                                                                                              */
void MyPTimer(int Value) {
/*���:
		elbow 20~130�� �������� ����                                                                                                                                                                 */
	if (elbow == 20 && Pstate == 0) {
		elbow += 10; Pstate = 1;
	}
	if (elbow <= 130 && Pstate == 0) {
		elbow -= 10;
	}
	if (elbow <= 130 && Pstate == 1) {
		elbow += 10;
	}
	if (elbow == 130 && Pstate == 1) {
		Pstate = 2;
	}
	if (Pstate == 2) {
		return;
	}
	glutPostRedisplay();
	glutTimerFunc(100, MyPTimer, 10);
}

/*���� ����:
			���콺 �Լ� ���                                                                                                                                                                        */
void MyMouse(int button, int state, int x, int y) {
/*���:
		���콺 ���� ��ư ������ Ÿ�̸� ����                                                                                                                                                         */
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Pstate = 0; glutTimerFunc(100, MyPTimer, 10);
		glutPostRedisplay();
	}


}
/*���� ����:
			Ÿ�̸� ���                                                                                                                                                                            */
void MyTimer(int Value) {
/*���:
		fing1 0~180�� �������� ����                                                                                                                                                                */
	if (fingnum == 1) {
		if (fing1 == 180) {
			state = 1;
			if (fing1 == 0) {
				return;
			}
			if (fing1 != 0) {
				fing1 -= 20; state = 1; glutPostRedisplay();
			}
		}
		if (fing1 != 180 && state == 0) {
			fing1 += 20; glutPostRedisplay();
		}
		if (fing1 != 0 && state == 1) {
			fing1 -= 20; glutPostRedisplay();
		}
	}
/*���:
		fing2 0~180�� �������� ����                                                                                                                                                                */
	else if (fingnum == 2) {
		if (fing2 == 180) {
			state = 1; if (fing2 == 0) {
				return;
			}
			if (fing2 != 0) {
				fing2 -= 20; state = 1;
				glutPostRedisplay();
			}
		}
		if (fing2 != 180 && state == 0) {
			fing2 += 20; glutPostRedisplay();
		} if (fing2 != 0 && state == 1) {
			fing2 -= 20; glutPostRedisplay();
		}
	}
/*���:
		fing3 0~180�� �������� ����                                                                                                                                                                */
	else if (fingnum == 3) {
		if (fing3 == 180) {
			state = 1;
			if (fing3 == 0) {
				return;
			}
			if (fing3 != 0) {
				fing3 -= 20;
				state = 1;
				glutPostRedisplay();
			}
		}
		if (fing3 != 180 && state == 0) {
			fing3 += 20; glutPostRedisplay();
		}
		if (fing3 != 0 && state == 1) {
			fing3 -= 20; glutPostRedisplay();
		}
	}
/*���:
		fing4 0~180�� �������� ����                                                                                                                                                                */
	else if (fingnum == 4) {
		
		if (fing4 == 180) {
			state = 1;
			if (fing4 == 0) {
				return;
			}
			if (fing4 != 0) {
				fing4 -= 20; state = 1; glutPostRedisplay();
			}
		}
		if (fing4 != 180 && state == 0) {
			fing4 += 20; glutPostRedisplay();
		}
		if (fing4 != 0 && state == 1) {
			fing4 -= 20; glutPostRedisplay();
		}
	}
/*���:
		fing5 0~180�� �������� ����                                                                                                                                                                */
	else {
		if (fing5 == 180) {
			state = 1;
			if (fing5 == 0) {
				return;
			}
			if (fing5 != 0) {
				fing5 -= 20;
				state = 1;
				glutPostRedisplay();
			}
		}
		if (fing5 != 180 && state == 0) {
			fing5 += 20;
			glutPostRedisplay();
		}
		if (fing5 != 0 && state == 1) {
			fing5 -= 20;
			glutPostRedisplay();
		}
	}
	glutTimerFunc(200, MyTimer, 1);
}
/*���� ����:
			Ű���� �Լ� ���                                                                                                                                                                       */
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
/*���:
		1 �Է� �� finger1 ����                                                                                                                                                                     */
	case '1': fingnum = 1;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
/*���:
		2 �Է� �� finger2 ����                                                                                                                                                                     */
	case '2': fingnum = 2;
		glutTimerFunc(100, MyTimer, 1);
		state = 0; break;
/*���:
		3 �Է� �� finger3 ����                                                                                                                                                                     */
	case '3': fingnum = 3;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
/*���:
		4 �Է� �� finger 1,2,3 ����                                                                                                                                                                */
	case '4': fingnum = 1; fingnum = 2; fingnum = 3; fingnum = 4;
		glutTimerFunc(100, MyTimer, 1); 
		state = 0;
		break;
/*���:
		S �Է� �� �������� finger 1,2,3�� ���� ���߱� (��� finger4 �������� ���� ����)                                                                                                            */
	case 'S': 
		fingnum = 4;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
	}


/*���� ����:
			������ȯ, ������ȯ                                                                                                                                                                     */
} void MyReshape(int nw, int nh) {
/*���:
		��ü�� â���� �׸� �� �ֵ��� viewport�� pixel ��ǥ�� ��ġ�ϵ��� �������� (NewWidth)*(NewHeight) ������ ���                                                                                */
	glViewport(0, 0, (GLsizei)nw, (GLsizei)nh);
	GLfloat wf = (GLfloat)nw / (GLfloat)700;
	GLfloat hf = (GLfloat)nh / (GLfloat)700;
/*���:
		�𵨺� ��� ����                                                                                                                                                                           */
	glMatrixMode(GL_PROJECTION);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                       */
	glLoadIdentity();
/*���:
		��ĺ�ȯ                                                                                                                                                                                   */
	glOrtho(-3.0 * wf, 3.0 * wf, -3.0 * hf, 3.0 * hf, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*���� ����:
			������ �ʱ�ȭ                                                                                                                                                                          */
int main(int argc, char** argv) {
/*���:
			Window OS�� Session ����                                                                                                                                                               */
	glutInit(&argc, argv);
/*���:
			Display Mode RGB, Double�� ����                                                                                                                                                        */
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
/*���:
		Window�� ũ�� ����                                                                                                                                                                         */
	glutInitWindowSize(700, 700);
/*���:
		���ο� Window Graphics Robot Arm ����                                                                                                                                                      */
	glutCreateWindow("Robot Arm");
/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                          */
	glutDisplayFunc(MyDisplay);
/*���:
		�̺�Ʈ Ÿ�� Mouse callback �Լ�                                                                                                                                                            */
	glutMouseFunc(MyMouse);
/*���:
		�̺�Ʈ Ÿ�� Keyboard callback �Լ�                                                                                                                                                         */
	glutKeyboardFunc(MyKeyboard);
/*���:
		�̺�Ʈ Ÿ�� Reshape callback �Լ�                                                                                                                                                          */
	glutReshapeFunc(MyReshape);
/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                  */
	glutMainLoop();
	return 0;
}
/**************************************************************************************************************************************************************************************************/