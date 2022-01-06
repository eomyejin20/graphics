#include<GL/glut.h> 

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
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawShoulder();

	glutSwapBuffers();
}
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
void DrawElbow() {
	glPushMatrix(); // Shoulder ��ǥ push 
	glTranslatef(-0.1, 0.0, 1.36);
	glRotatef(20, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 1.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.2, 0.2, 1.5, 4.0, 1.0);
	DrawPalm(); glPopMatrix(); // Elbow ��ǥ pop 

}
void DrawPalm() {
	glPushMatrix(); // �� ��ǥ push 
	glTranslatef(0.0, 0.0, 1.65);
	glScalef(0.5, 0.2, 0.4);
	glutWireCube(1.0);
	glScalef(2.0, 1.0, 2.5);
	DrawFing1();
	DrawFing2();
	DrawFing3();
	DrawFing4();
	DrawFing5();
	glPopMatrix(); // �չٴ� ��ǥ pop 
}
void DrawFing1()
{
	glPushMatrix(); // �չٴ� ��ǥ push 
	glTranslatef(0.2, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
	glPushMatrix(); // �հ���1 ��ǥ push 
	glTranslatef(0.1, 0.0, 0.18);
	glRotatef((GLfloat)fing1, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
	glPopMatrix(); // �հ���1-1 ��ǥ pop 
	glPopMatrix(); // �հ���1 ��ǥ pop 
}

void DrawFing2() {
	glPushMatrix(); // �չٴ� ��ǥ push 
	glTranslatef(0.1, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
	glPushMatrix(); // �հ���2 ��ǥ push 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing2, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
	glPopMatrix(); // �հ���2-1 ��ǥ pop 
	glPopMatrix(); // �հ���2 ��ǥ pop
}

void DrawFing3() {
	glPushMatrix(); // �չٴ� ��ǥ push 
	glTranslatef(0.0, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
	glPushMatrix(); // �հ���3 ��ǥ push 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing3, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
	glPopMatrix(); // �հ���3-1 ��ǥ pop 
	glPopMatrix(); // �հ���3 ��ǥ pop 
}

void DrawFing4() {
	glPushMatrix(); // �չٴ� ��ǥ push 
	glTranslatef(-0.1, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
	glPushMatrix(); // �հ���4 ��ǥ push 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing4, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
	glPopMatrix(); // �հ���4-1 ��ǥ pop 
	glPopMatrix(); // �հ���4 ��ǥ pop 
}
void DrawFing5() {
	glPushMatrix(); // �չٴ� ��ǥ push 
	glTranslatef(-0.2, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
	glPushMatrix(); // �հ���5 ��ǥ push 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing5, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
	glPopMatrix(); // �հ���5-1 ��ǥ pop 
	glPopMatrix(); // �հ���5 ��ǥ pop 
}

void MyPTimer(int Value) {
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
void MyMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Pstate = 0; glutTimerFunc(100, MyPTimer, 10);
		glutPostRedisplay();
	}


}
void MyTimer(int Value) {
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

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1': fingnum = 1;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
	case '2': fingnum = 2;
		glutTimerFunc(100, MyTimer, 1);
		state = 0; break;
	case '3': fingnum = 3;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
	case '4': fingnum = 1; fingnum = 2; fingnum = 3;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
	case '5': fingnum = 5;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
	}



} void MyReshape(int nw, int nh) {
	glViewport(0, 0, (GLsizei)nw, (GLsizei)nh);
	GLfloat wf = (GLfloat)nw / (GLfloat)700;
	GLfloat hf = (GLfloat)nh / (GLfloat)700;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0 * wf, 3.0 * wf, -3.0 * hf, 3.0 * hf, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Robot Arm");
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouse);
	glutKeyboardFunc(MyKeyboard);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}
