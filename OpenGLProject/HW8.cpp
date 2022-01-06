/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#8. 종합                                                                                                      */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 12월 16일                                                          */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
/*기능:
	   세상 좌표계 기준의 시점변환 인수                                                                                                                                                           */
float ex = 0.0;
float ey = 3.5;
float ez = 3.5;
float cx, cy, cz, ux = 0.0;
float uy = 1.0;
float uz = 0.0;

/*기능:
		시야각                                                                                                                                                                                    */
double horizAngle = 0.0;
double vertAngle = 0.0;

/*기능:
		달리기 시야각과 변수                                                                                                                                                                      */
double limbAngle = 0.0;
bool run = false;

/*문제 정의:
			사람 그리기                                                                                                                                                                      */
void drawRobot() {
	/*기능:
				머리 그리기                                                                                                                                                                                      */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 1.0, 0.0);
	glutSolidSphere(.25, 20, 20);
	glPopMatrix();

	/*기능:
			머리카락 그리기                                                                                                                                                                                 */
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 1.05, -0.10);
	glScaled(1.2, 0.5, 0.9);
	glutSolidSphere(0.3, 20, 20);
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
	 
	/*기능:
			입 그리기                                                                                                                                                                                 */

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

	/*기능:
			몸매 그리기                                                                                                                                                                                */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 0.40, 0.0);
	glScaled(1.0, 1.5, 0.30);
	glutSolidCube(.50);
	glPopMatrix();


}
/*기능:
		왼팔 그리기                                                                                                                                                                                */
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

	/*기능:
			왼손 그리기                                                                                                                                                                               */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();

}
/*기능:
		오른팔 그리기                                                                                                                                                                             */
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

	/*기능:
			오른손 그리기                                                                                                                                                                              */
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();
}
/*기능:
		왼다리 그리기                                                                                                                                                                              */
void leftLeg() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	/*기능:
				왼신발 그리기                                                                                                                                                                              */
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
/*기능:
		오른다리 그리기                                                                                                                                                                            */
void rightLeg() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	/*기능:
			오른신발 그리기                                                                                                                                                                            */
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

/*문제 정의:
			달리기                                                                                                                                                                           */
void Run(void)
{
	/*기능:
			팔, 다리 운동 인자                                                                                                                                                                             */
	static float mf = 0.05;

	limbAngle += mf;
	/*기능:
			달리기 각도에 따른 운동                                                                                                                                                                            */
	if (limbAngle > 30.0) {
		mf = -0.70;
	}
	if (limbAngle < -30.0) {
		mf = 0.70;
	}
	glutPostRedisplay();
}

/*문제 정의:
			사람 그리기                                                                                                                                                                           */
void myDisplay(void) {
	/*기능:
			모델뷰행렬 선택                                                                                                                                                                             */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*기능:
			색, 깊이 버퍼 삭제                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*기능:
		시점좌표계 정의 함수                                                                                                                                                                     */
	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
	glFlush();

	if (run == true) {
		/*기능:
				달릴 때 사람 주위 회전                                                                                                                                                                           */
		glPushMatrix();
		drawRobot();
		glPopMatrix();
		/*기능:
				왼팔 걷기 운동                                                                                                                                                                           */
		glPushMatrix();
		glTranslated(-0.30, 1.0, 0.0);
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(0.30, -1.0, 0.0);
		leftArm();
		glPopMatrix();
		/*기능:
				오른팔 걷기 운동                                                                                                                                                                           */
		glPushMatrix();
		glTranslated(0.30, 1.0, 0.0);
		glRotated(-limbAngle, 1.0, 0.0, 0.0f);
		glTranslated(-0.30, -1.0, 0.0);
		rightArm();
		glPopMatrix();
		/*기능:
				왼다리 걷기 운동                                                                                                                                                                           */
		glPushMatrix();
		glRotated(-limbAngle, 1.0, 0.0, 0.0f);
		leftLeg();
		glPopMatrix();
		/*기능:
				오른다리 걷기 운동                                                                                                                                                                           */
		glPushMatrix();
		glRotated(limbAngle, 1.0, 0.0, 0.0f);
		rightLeg();
		glPopMatrix();
	}

	else if (run == false) {
		/*기능:
				안달릴 때 사람 그리기                                                                                                                                                                        */
		glPushMatrix();
		drawRobot();
		leftArm();
		rightArm();
		leftLeg();
		rightLeg();
		glPopMatrix();
	}

	/*기능:
				버퍼 2개 사용                                                                                                                                                                         */
	glutSwapBuffers();
}


/*문제 정의:
			키보드 함수 등록                                                                                                                                                     */
void myKeyboard(unsigned char key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*기능:
			확대, 축소                                                                                                                                                                         */
	static double zoomFactor = 1.0;
	static double zoomFactor2 = 1.0;

	switch (key)
	{
		/*기능:
				z 입력 시 축소, Z 입력 시 확대                                                                                                                                                                       */
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
	/*기능:
		r,R 입력 시 달리기                                                                                                                                                                        */
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

/*문제 정의:
			스페셜 키보드 이벤트 등록                                                                                                                                                            */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
		/*기능:
				왼쪽 키 입력 시 왼쪽으로 0.1씩 이동                                                                                                                                                      */
	case GLUT_KEY_LEFT:
		/*기능:
				왼쪽 키 입력 시 camera X축 좌표 연속적으로 0.1씩 감소                                                                                                                                    */
		ex = ex - 0.01;
		/*기능:
				윈도우 다시 그리도록 요청                                                                                                                                                                */
		glutPostRedisplay();
		break;
		/*기능:
				오른쪽 키 입력 시 오른쪽으로 0.1씩 이동                                                                                                                                                  */
	case GLUT_KEY_RIGHT:
		/*기능:
				오른쪽 키 입력 시 camera X축 좌표 연속적으로 0.1씩 증가                                                                                                                                  */
		ex = ex + 0.01;
		/*기능:
				윈도우 다시 그리도록 요청                                                                                                                                                                */
		glutPostRedisplay();
		break;
		/*기능:
				위 키 입력 시 위쪽으로 0.1씩 이동                                                                                                                                                        */
	case GLUT_KEY_UP:
		/*기능:
				윗쪽 키 입력 시 camera Y축 좌표 연속적으로 0.1씩 증가                                                                                                                                    */
		ey = ey + 0.01;
		/*기능:
				윈도우 다시 그리도록 요청                                                                                                                                                                */
		glutPostRedisplay();
		break;
		/*기능:
				아래 키 입력 시 아래쪽으로 0.1씩 이동                                                                                                                                                    */
	case GLUT_KEY_DOWN:
		/*기능:
				아래쪽 키 입력 시 camera Y축 좌표 연속적으로 0.1씩 감소                                                                                                                                  */
		ey = ey - 0.01;
		/*기능:
				윈도우 다시 그리도록 요청                                                                                                                                                                */
		glutPostRedisplay();
		break;
	}

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
			새로운 Window Graphics 종합 생성                                                                                                                                           */
	glutCreateWindow("종합");
	/*기능:
			이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(myDisplay);

	/*기능:
		이벤트 타입 MyIdle callback 함수로 지속적인 달리기 구현                                                                                                                                                          */
	glutIdleFunc(Run);

	/*기능:
			이벤트 타입 Keyboard callback 함수                                                                                                                                                         */
	glutKeyboardFunc(myKeyboard);
	/*기능:
	       이벤트 타입 MySpecialKey callback 함수                                                                                                                                                              */                                                                                                                                              
	glutSpecialFunc(MySpecialKey);

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
	/*기능:
		자동으로 단위법선벡터 구하기                                                                                                                                                         */

	glEnable(GL_NORMALIZE);
	/*기능:
			glColor에서 설정한 값이 적용될 재질 인자를 지정                                                                                                                                                                       */
	glEnable(GL_COLOR_MATERIAL);
	/*기능:
		사람의 반시계방향을 정면으로 설정                                                                                                                                                         */
	glFrontFace(GL_CCW);
	/*기능:
				사람의 후면을 제거                                                                                                                                                         */
	glCullFace(GL_BACK);
	/*기능:
				사람의 후면제거 활성화                                                                                                                                                         */
	glEnable(GL_CULL_FACE);
	/*기능:
			보이는 사람의 앞면과 뒷면에 FILL 적용                                                                                                                                                         */
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	myInit();
	glutMainLoop();
}
/**************************************************************************************************************************************************************************************************/