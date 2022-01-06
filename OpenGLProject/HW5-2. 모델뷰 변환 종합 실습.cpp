/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#5-2. 모델뷰 변환 종합 실습                                                                                                      */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 11월 4일                                                          */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
/*기능:
		시야각                                                                                                                                                                                    */
double horizAngle = 0.0;
double vertAngle = 0.0;

/*문제 정의:
			전신 로봇 그리기                                                                                                                                                                      */
void drawRobot() {
/*기능:
			머리 그리기                                                                                                                                                                                      */
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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
/*기능:
		투영행렬 선택                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 투영행렬을 항등행렬로 초기화                                                                                                                                                         */
	glLoadIdentity();
/*기능:
		행렬변환                                                                                                                                                                                   */
	glOrtho(-2.0*(64 / 48.0), 2.0*(64 / 48.0), -2.0, 2.0, 0.1, 100.0); 
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
	   로봇 다시 그리기                                                                                                                                                                           */
		glPushMatrix();
		glRotated(vertAngle, 1.0, 0.0, 0.0f);
		glRotated(horizAngle, 0.0, 1.0, 0.0f);
		drawRobot();
		leftArm();
		rightArm();
		leftLeg();
		rightLeg();
		glPopMatrix();
	
/*기능:
		버퍼 2개 사용                                                                                                                                                                         */
	glutSwapBuffers();
}


/*문제 정의:
			키보드 함수 등록                                                                                                                                                     */
void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*기능:
		줌 인, 아웃                                                                                                                                                                         */
	static double zoomFactor = 1.0;	
	static double zoomFactor2 = 1.0;

	switch (key)
	{
/*기능:
		z 입력 시 줌 아웃, Z 입력 시 줌 인                                                                                                                                                                        */
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

/*문제 정의:
			arrowKeyPress 함수 등록                                                                                                                                                     */
void arrowKeyPress(int key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*기능:
		오른쪽 키 입력 시 오른쪽 시점으로 실행                                                                                                                                                                       */
	switch (key) {
	case GLUT_KEY_RIGHT:
		horizAngle += 2;
		break;
/*기능:
		왼쪽 키 입력 시 왼쪽 시점으로 실행                                                                                                                                                                       */
	case GLUT_KEY_LEFT:
		horizAngle -= 2;
		break;
/*기능:
		윗쪽 키 입력 시 위 시점으로 실행                                                                                                                                                                       */
	case GLUT_KEY_UP:
		vertAngle -= 2;
		break;
/*기능:
		아래쪽 키 입력 시 아래쪽 시점으로 실행                                                                                                                                                                       */
	case GLUT_KEY_DOWN:
		vertAngle += 2;
		break;
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
		새로운 Window Graphics 모델뷰 변환 종합 생성                                                                                                                                           */
	glutCreateWindow("모델뷰 변환 종합");
/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(myDisplay);
	

/*기능:
		이벤트 타입 Keyboard callback 함수                                                                                                                                                         */
	glutKeyboardFunc(myKeyboard);
/*기능:
		이벤트 타입 MySpecialKey callback 함수                                                                                                                                                    */
    glutSpecialFunc(arrowKeyPress);

/*기능:
		조명 모드를 활성화                                                                                                                                                                     */
	glEnable(GL_LIGHTING);
/*기능:
		0번의 광원 활성화                                                                                                                                                                      */
	glEnable(GL_LIGHT0);
	/*기능:
		   정점색을 보간해가면서 채운다                                                                                                                                                          */
	glShadeModel(GL_SMOOTH);
/*기능:
		깊이 버퍼 활성화                                                                                                                                                                       */
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
/*기능:
		glColor에서 설정한 값이 적용될 재질 인자를 지정                                                                                                                                                                       */
	glEnable(GL_COLOR_MATERIAL);	

	myInit();
	glutMainLoop();
}
/**************************************************************************************************************************************************************************************************/