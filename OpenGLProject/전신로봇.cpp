/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#4-2. 전신 로봇 모델링                                                                                                      */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 11월 1일                                                          */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
/*기능:
		시야각                                                                                                                                                                                    */
double horizAngle = 0.0;	
double vertAngle = 0.0;	
/*기능:
		걷는 각도                                                                                                                                                                                 */
double limbAngle = 0.0; 
bool walk = false;
GLboolean arm = true;
GLboolean leg = true;
/*문제 정의:
			전신 로봇 그리기                                                                                                                                                                      */
void drawRobot() {
/*기능:
		머리 그리기                                                                                                                                                                               */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 1.0, 0.0);
	glutWireSphere(.25, 20, 20);
	glPopMatrix();


/*기능:
		눈 그리기                                                                                                                                                                                 */
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
	
/*기능:
		몸매 그리기                                                                                                                                                                                */
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.40, 0.0);
	glScaled(1.0, 1.5, 0.30);
	glutWireCube(.50);
	glPopMatrix();

	
}
/*기능:
		왼팔 그리기                                                                                                                                                                                */
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
	
/*기능:
		왼손 그리기                                                                                                                                                                               */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutWireSphere(.08, 20, 20);
	glPopMatrix();

}
/*기능:
		오른팔 그리기                                                                                                                                                                             */
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
	
/*기능:
		오른손 그리기                                                                                                                                                                              */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutWireSphere(.08, 20, 20);
	glPopMatrix();
}
/*기능:
		왼다리 그리기                                                                                                                                                                              */
void leftLeg() {
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
/*기능:
		왼신발 그리기                                                                                                                                                                              */
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
/*기능:
		오른다리 그리기                                                                                                                                                                            */
void rightLeg() {
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutWireCube(.50);
	glPopMatrix();
/*기능:
		오른신발 그리기                                                                                                                                                                            */
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
/*기능:
		창 배경                                                                                                                                                                                   */
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
/*기능:
		투영행렬 선택                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 투영행렬을 항등행렬로 초기화                                                                                                                                                         */
	glLoadIdentity();
/*기능:
	   행렬변환                                                                                                                                                                                   */
	glOrtho(-2.0*(64 / 48.0), 2.0*(64 / 48.0), -2.0, 2.0, 0.1, 100.0); //left, right, bottom, top, near, far Parallel Projection
	glViewport(0, 0, 800, 640);

/*기능:
	   표면재료의 속성 결정                                                                                                                                                                       */
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
/*문제 정의:
			걷기 동작 수행                                                                                                                                                                         */
void Walk(void)
{
/*기능:
	   사지 운동 인자                                                                                                                                                                              */
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
/*기능:
		모델뷰행렬 선택                                                                                                                                                                             */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*기능:
		색, 깊이버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


/*기능:
		arm이면 왼팔 움직임                                                                                                                                                                         */
	if (arm == true) {
/*기능:
		로봇 주위 회전                                                                                                                                                                              */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		glPopMatrix();
/*기능:
	   왼팔 그리고 동작                                                                                                                                                                             */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		glTranslated(-0.30, 1.0, 0.0);
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(0.30, -1.0, 0.0);
		leftArm();
		glPopMatrix();
/*기능:
		오른팔 그리기                                                                                                                                                                               */
		rightArm();
		glPopMatrix();
/*기능:
		왼다리 그리기                                                                                                                                                                                */
		leftLeg();
		glPopMatrix();
/*기능:
		오른다리 그리기                                                                                                                                                                              */
		rightLeg();
		glPopMatrix();
	}


/*기능:
		arm이 아니면 오른팔 움직임                                                                                                                                                                   */
		else if (arm == false) {
/*기능:
		로봇 주위 회전                                                                                                                                                                               */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
/*기능:
		왼팔 그리기                                                                                                                                                                                  */
			leftArm();
			glPopMatrix();

/*기능:
		오른팔 그리고 동작                                                                                                                                                                           */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			glTranslated(0.30, 1.0, 0.0);
			glRotated(-limbAngle, 1.0, 0.0, 0.0f);
			glTranslated(-0.30, -1.0, 0.0);
			rightArm();
			glPopMatrix();
/*기능:
		왼다리 그리기                                                                                                                                                                                */
			leftLeg();
			glPopMatrix();
			//Right leg walking movement
			glPushMatrix();
/*기능:
		오른다리 그리기                                                                                                                                                                              */
			rightLeg();
			glPopMatrix();

		}
/*기능:
		leg면  왼다리 움직임                                                                                                                                                                         */
		else if (leg == true) {
/*기능:
		로봇 주위 회전                                                                                                                                                                               */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
/*기능:
		왼팔 그리기                                                                                                                                                                                  */
			leftArm();
			glPopMatrix();
/*기능:
		오른팔 그리기                                                                                                                                                                                */
			rightArm();
			glPopMatrix();
/*기능:
		왼다리 그리고 동작                                                                                                                                                                           */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			glRotated(-limbAngle, 1.0, 0.0, 0.0f);
			leftLeg();
			glPopMatrix();
/*기능:
		오른다리 그리기                                                                                                                                                                              */
			rightLeg();
			glPopMatrix();
		}
/*기능:
		leg 아니면 오른다리 움직임                                                                                                                                                                   */
		else if (leg == false) {
/*기능:
		로봇 주위 회전                                                                                                                                                                               */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			drawRobot();
			glPopMatrix();
/*기능:
		왼팔 그리기                                                                                                                                                                                  */
			leftArm();
			glPopMatrix();
/*기능:
		오른팔 그리기                                                                                                                                                                                */
			rightArm();
			glPopMatrix();
/*기능:
		왼다리 그리기                                                                                                                                                                                */
			leftLeg();
			glPopMatrix();
/*기능:
		오른다리 그리고 동작                                                                                                                                                                         */
			glPushMatrix();
			glRotated(vertAngle, 1.0, 0.0, 0.0f);
			glRotated(horizAngle, 0.0, 1.0, 0.0f);
			glRotated(limbAngle, 1.0, 0.0, 0.0f);
			rightLeg();
			glPopMatrix();
		}
/*기능:
		멈추기                                                                                                                                                                                       */
		else {
/*기능:
		로봇 주위 회전                                                                                                                                                                               */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		glPopMatrix();
/*기능:
		왼팔 그리기                                                                                                                                                                                  */
		leftArm();
		glPopMatrix();
/*기능:
		오른팔 그리기                                                                                                                                                                                */
		rightArm();
		glPopMatrix();
/*기능:
	   왼다리 그리기                                                                                                                                                                                 */
		leftLeg();
		glPopMatrix();
/*기능:
		오른다리 그리기                                                                                                                                                                              */
		rightLeg();
		glPopMatrix();
		}
		glFlush();
/*기능:
       각각의 새로운 그림은 보이지 않는 버퍼에 그려지고 그리기가 완료되면 디스플레이가 그림으로 전환됩니다.                                                                                          */
		glutSwapBuffers();
	
}
/*문제 정의:
			메인메뉴 함수 등록                                                                                                                                                                       */
void MyMainMenu(int entryID) {
/*기능:
		왼팔 동작                                                                                                                                                                                    */
	if (entryID == 1)
		arm = true;
/*기능:
		오른팔 동작                                                                                                                                                                                  */
	else if (entryID == 2)
		arm = false;
/*기능:
		왼다리 동작                                                                                                                                                                                  */
	else if (entryID == 3)
		leg = true;
/*기능:
		오른다리 동작                                                                                                                                                                                */
	else if (entryID == 4)
		leg = false;
	glutPostRedisplay;
}
/*문제 정의:
			키보드 함수 등록                                                                                                                                                                         */
void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static double zoomFactor = 1.0;	//Zooming in/out 
	static double zoomFactor2 = 1.0;

	switch (key)
	{
/*기능:
		S 입력 시 동작 멈추기                                                                                                                                                                        */
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

/*문제 정의:
			윈도우 초기화                                                                                                                                                                         */
void main(int argc, char **argv) {
/*기능:
		Window OS와 Session 연결                                                                                                                                                                  */
	glutInit(&argc, argv); 
/*기능:
		Display Mode RGB, Double, Depth로 설정                                                                                                                                                           */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
/*기능:
		Window의 크기 설정                                                                                                                                                                        */
	glutInitWindowSize(800, 640);
/*기능:
		Monitor에서 Window의 시작점 위치                                                                                                                                                          */
	glutInitWindowPosition(100, 100);
/*기능:
		새로운 Window Graphics Timer Callback 응용 생성                                                                                                                                           */
	glutCreateWindow("Give me your candy Kid!!!");
/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(myDisplay);
	glutIdleFunc(Walk);	
/*기능:
		이벤트 타입 Keyboard callback 함수                                                                                                                                                         */
	glutKeyboardFunc(myKeyboard);	//myKeyboard will handle normal keys
/*기능:
		메인 메뉴에 메뉴 항목 첨가                                                                                                                                                                */
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Head", 0);
	glutAddMenuEntry("left arm", 1);
	glutAddMenuEntry("right arm", 2);
	glutAddMenuEntry("right leg", 3);
	glutAddMenuEntry("left leg", 4);
/*기능:
		마우스 오른쪽 버튼을 누르면 현 메뉴 팝업                                                                                                                                                               */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
/*기능:
		재질 색상 일치 정점 색상 지정                                                                                                                                                             */
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