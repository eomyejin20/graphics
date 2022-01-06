/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#4-1. 로봇 손-팔 모델링                                                                                                     */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 11월 1일                                                          */

#include<GL/glut.h> 
/*기능:
	   로봇 손-팔 그리기 위한 변수                                                                                                                                                                */
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
/*기능:
		창 배경                                                                                                                                                                                   */
	glClearColor(0.0, 0.0, 0.0, 1.0);
/*기능:
		색, 깊이버퍼 제거                                                                                                                                                                         */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*기능:
		모델뷰행렬 선택                                                                                                                                                                           */
	glMatrixMode(GL_MODELVIEW);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                      */
	glLoadIdentity();

	DrawShoulder();

	glutSwapBuffers();
}
/*문제 정의:
			Shoulder 그리기                                                                                                                                                                       */
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
/*문제 정의:
			Elbow 그리기                                                                                                                                                                           */
void DrawElbow() {
/*기능:
		Shoulder 좌표 push하기                                                                                                                                                                     */
	glPushMatrix(); 
	glTranslatef(-0.1, 0.0, 1.36);
	glRotatef(20, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 1.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.2, 0.2, 1.5, 4.0, 1.0);
/*기능:
		Elbow 좌표 pop하기                                                                                                                                                                         */
	DrawPalm(); glPopMatrix(); 

}
/*문제 정의:
			Palm 그리기                                                                                                                                                                            */
void DrawPalm() {
/*기능:
		Elbow 좌표 push하기                                                                                                                                                                        */
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
/*기능:
		Falm 좌표 pop하기                                                                                                                                                                           */
	glPopMatrix(); 
}
/*문제 정의:
			finger1 그리기                                                                                                                                                                          */
void DrawFing1()
{
/*기능:
		Palm 좌표 push하기                                                                                                                                                                          */
	glPushMatrix(); 
	glTranslatef(0.2, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*기능:
		finger1 좌표 push하기                                                                                                                                                                       */
	glPushMatrix(); 
	glTranslatef(0.1, 0.0, 0.18);
	glRotatef((GLfloat)fing1, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*기능:
		finger1-1 좌표 pop하기                                                                                                                                                                      */
	glPopMatrix();
/*기능:
		finger1 좌표 pop하기                                                                                                                                                                        */
	glPopMatrix(); 
}
/*문제 정의:
			finger2 그리기                                                                                                                                                                          */
void DrawFing2() {
/*기능:
		Palm 좌표 push하기                                                                                                                                                                          */
	glPushMatrix(); 
	glTranslatef(0.1, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*기능:
		finger2 좌표 push하기                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing2, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*기능:
		finger2-1 좌표 pop하기                                                                                                                                                                       */
	glPopMatrix();
/*기능:
		finger2 좌표 pop하기                                                                                                                                                                         */
	glPopMatrix(); 
}
/*문제 정의:
			finger3 그리기                                                                                                                                                                           */
void DrawFing3() {
/*기능:
		Palm 좌표 push하기                                                                                                                                                                           */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*기능:
		finger3 좌표 push하기                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing3, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*기능:
		finger3-1 좌표 pop하기                                                                                                                                                                       */
	glPopMatrix(); 
/*기능:
		finger3 좌표 pop하기                                                                                                                                                                         */
	glPopMatrix(); 
}
/*문제 정의:
			finger4 그리기                                                                                                                                                                           */
void DrawFing4() {
/*기능:
		Palm 좌표 push하기                                                                                                                                                                           */
	glPushMatrix();  
	glTranslatef(-0.1, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 4.0, 1.0);
/*기능:
		finger4 좌표 push하기                                                                                                                                                                        */
	glPushMatrix(); 
	glTranslatef(0.0, 0.0, 0.18);
	glRotatef((GLfloat)fing4, 1.0, 0.0, 0.0);
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);
	gluQuadricNormals(cyl, GLU_SMOOTH);
	glColor3f(1.0, 1.0, 1.0);
	gluCylinder(cyl, 0.05, 0.05, 0.23, 4.0, 1.0);
/*기능:
		finger4-1 좌표 pop하기                                                                                                                                                                       */
	glPopMatrix(); 
/*기능:
		finger4 좌표 pop하기                                                                                                                                                                         */
	glPopMatrix();
}
/*문제 정의:
			finger5 그리기                                                                                                                                                                           */
void DrawFing5() {
/*기능:
		Palm 좌표 push하기                                                                                                                                                                           */
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
/*기능:
		finger5-1 좌표 pop하기                                                                                                                                                                       */
	glPopMatrix(); 
/*기능:
		finger5 좌표 pop하기                                                                                                                                                                         */
	glPopMatrix(); 
}
/*문제 정의:
			타이머 등록                                                                                                                                                                              */
void MyPTimer(int Value) {
/*기능:
		elbow 20~130의 범위에서 동작                                                                                                                                                                 */
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

/*문제 정의:
			마우스 함수 등록                                                                                                                                                                        */
void MyMouse(int button, int state, int x, int y) {
/*기능:
		마우스 왼쪽 버튼 누르면 타이머 실행                                                                                                                                                         */
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Pstate = 0; glutTimerFunc(100, MyPTimer, 10);
		glutPostRedisplay();
	}


}
/*문제 정의:
			타이머 등록                                                                                                                                                                            */
void MyTimer(int Value) {
/*기능:
		fing1 0~180의 범위에서 동작                                                                                                                                                                */
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
/*기능:
		fing2 0~180의 범위에서 동작                                                                                                                                                                */
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
/*기능:
		fing3 0~180의 범위에서 동작                                                                                                                                                                */
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
/*기능:
		fing4 0~180의 범위에서 동작                                                                                                                                                                */
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
/*기능:
		fing5 0~180의 범위에서 동작                                                                                                                                                                */
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
/*문제 정의:
			키보드 함수 등록                                                                                                                                                                       */
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
/*기능:
		1 입력 시 finger1 동작                                                                                                                                                                     */
	case '1': fingnum = 1;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
/*기능:
		2 입력 시 finger2 동작                                                                                                                                                                     */
	case '2': fingnum = 2;
		glutTimerFunc(100, MyTimer, 1);
		state = 0; break;
/*기능:
		3 입력 시 finger3 동작                                                                                                                                                                     */
	case '3': fingnum = 3;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
/*기능:
		4 입력 시 finger 1,2,3 동작                                                                                                                                                                */
	case '4': fingnum = 1; fingnum = 2; fingnum = 3; fingnum = 4;
		glutTimerFunc(100, MyTimer, 1); 
		state = 0;
		break;
/*기능:
		S 입력 시 동작중인 finger 1,2,3의 동작 멈추기 (대신 finger4 동작으로 인해 멈춤)                                                                                                            */
	case 'S': 
		fingnum = 4;
		glutTimerFunc(100, MyTimer, 1);
		state = 0;
		break;
	}


/*문제 정의:
			투영변환, 뷰폿변환                                                                                                                                                                     */
} void MyReshape(int nw, int nh) {
/*기능:
		전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 (NewWidth)*(NewHeight) 영역에 출력                                                                                */
	glViewport(0, 0, (GLsizei)nw, (GLsizei)nh);
	GLfloat wf = (GLfloat)nw / (GLfloat)700;
	GLfloat hf = (GLfloat)nh / (GLfloat)700;
/*기능:
		모델뷰 행렬 선택                                                                                                                                                                           */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                       */
	glLoadIdentity();
/*기능:
		행렬변환                                                                                                                                                                                   */
	glOrtho(-3.0 * wf, 3.0 * wf, -3.0 * hf, 3.0 * hf, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*문제 정의:
			윈도우 초기화                                                                                                                                                                          */
int main(int argc, char** argv) {
/*기능:
			Window OS와 Session 연결                                                                                                                                                               */
	glutInit(&argc, argv);
/*기능:
			Display Mode RGB, Double로 설정                                                                                                                                                        */
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
/*기능:
		Window의 크기 설정                                                                                                                                                                         */
	glutInitWindowSize(700, 700);
/*기능:
		새로운 Window Graphics Robot Arm 생성                                                                                                                                                      */
	glutCreateWindow("Robot Arm");
/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                          */
	glutDisplayFunc(MyDisplay);
/*기능:
		이벤트 타입 Mouse callback 함수                                                                                                                                                            */
	glutMouseFunc(MyMouse);
/*기능:
		이벤트 타입 Keyboard callback 함수                                                                                                                                                         */
	glutKeyboardFunc(MyKeyboard);
/*기능:
		이벤트 타입 Reshape callback 함수                                                                                                                                                          */
	glutReshapeFunc(MyReshape);
/*기능:
		GLUT Event 처리 Loop 입력                                                                                                                                                                  */
	glutMainLoop();
	return 0;
}
/**************************************************************************************************************************************************************************************************/