/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-6. Timer Callback 응용                                                                                                   */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 10월 8일                                                          */

#include <GL/glut.h>
/*기능:
	   오브젝트 이동을 위한 변수 (좌우/위아래), Polygon 색 변수                                                                                                                                   */
double trans_left = 0, trans_up = 0;
GLfloat rc, gc, bc;

void MyDisplay() {
/*기능:
		색 버퍼 제거                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
		그려지는 도형의 색은 회색                                                                                                                                                                 */
	glColor3f(0.5, 0.5, 0.5);
/*기능:
		그려지는 도형의 색 변수                                                                                                                                                                   */
	glColor3f(rc, gc, bc);
/*기능:
	   type은 다각형                                                                                                                                                                              */
	glBegin(GL_POLYGON);
/*기능:
		찍힐 위치에 점 찍기                                                                                                                                                                       */
	glVertex3f(-0.5 + trans_left, -0.5 + trans_up, 0.0);
	glVertex3f(0.5 + trans_left, -0.5 + trans_up, 0.0);
	glVertex3f(0.5 + trans_left, 0.5 + trans_up, 0.0);
	glVertex3f(-0.5 + trans_left, 0.5 + trans_up, 0.0);
	
	glEnd();
/*기능:
		명령 실행                                                                                                                                                                                 */
	glutSwapBuffers();
}

void MyIdle1() {
/*기능:
		왼쪽으로 0.1씩 이동                                                                                                                                                                       */
	trans_left = trans_left - 0.001;
/*기능:
		빨간색으로 변경                                                                                                                                                                           */
	rc = 1.0; gc = 0.0; bc = 0.0;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}

void MyIdle2() {
/*기능:
		오른쪽으로 0.1씩 이동                                                                                                                                                                     */
	trans_left = trans_left + 0.001;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}
/*문제 정의:
			마우스 함수 등록                                                                                                                                                                      */
void MyMouseClick(GLint Button, GLint state, GLint x, GLint y) {
	switch (Button) {
/*기능:
	   마우스 왼쪽 버튼 누르면 멈추기                                                                                                                                                             */
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
	}
	glutPostRedisplay();
}

/*문제 정의:
			타이머 등록                                                                                                                                                                           */
void MyTimer(int Value) {
/*기능:
		이벤트 타입 MyIdle2 callback 함수                                                                                                                                                         */
	glutIdleFunc(MyIdle2);
	if (trans_left > 0.5) {
/*기능:
		이벤트 타입 MyIdle1 callback 함수                                                                                                                                                         */
		glutIdleFunc(MyIdle1);
	}
/*기능:
			마우스 함수 등록                                                                                                                                                                      */
	glutMouseFunc(MyMouseClick);
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
	
}



/*문제 정의:
			윈도우 초기화                                                                                                                                                                         */
int main(int argc, char** argv) {
/*기능:
		Window OS와 Session 연결                                                                                                                                                                  */
	glutInit(&argc, argv);
/*기능:
		Display Mode RGB, Double로 설정                                                                                                                                                           */
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
/*기능:
		Window의 크기 설정                                                                                                                                                                        */
	glutInitWindowSize(300, 300);
/*기능:
		Monitor에서 Window의 시작점 위치                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
/*기능:
		새로운 Window Graphics Timer Callback 응용 생성                                                                                                                                           */
	glutCreateWindow("Timer Callback 응용");
/*기능:
		창 배경 흰색                                                                                                                                                                              */
	glClearColor(1.0, 1.0, 1.0, 1.0);
/*기능:
		투영행렬 선택                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                      */
	glLoadIdentity();
/*기능:
	   행렬변환                                                                                                                                                                                   */
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*기능:
		이벤트 타입 MyKeyboard callback 함수                                                                                                                                                      */
	glutTimerFunc(40, MyTimer, 1);
	
/*기능:
		GLUT Event 처리 Loop 입력                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/