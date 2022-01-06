/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-3. Mouse Callback 응용                                                                                                   */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 10월 8일                                                          */

#include <gl/glut.h>
#include <stdio.h>

/*기능:
	   오브젝트 이동을 위한 변수 (좌우/위아래)                                                                                                                                                    */
double trans_left = 0, trans_up = 0;

void MyDisplay() {
/*기능:
		색 버퍼 제거                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
		그려지는 도형의 색은 회색                                                                                                                                                                 */
	glColor3f(0.5, 0.5, 0.5);
/*기능:
		type은 다각형                                                                                                                                                                             */
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
	glFlush();
}



/*문제 정의:
			투영변환, 뷰폿변환                                                                                                                                                                    */
void MyReshape(int NewWidth, int NewHeight) {
/*기능:
		전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 (NewWidth)*(NewHeight) 영역에 출력                                                                               */
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
/*기능:
		모델뷰 행렬 선택                                                                                                                                                                          */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                      */
	glLoadIdentity();
/*기능:
		행렬변환                                                                                                                                                                                  */
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 *HeightFactor, 1.0 * HeightFactor, -1.0, -1.0);
}

/*문제 정의:
			Idle 이벤트 등록                                                                                                                                                                      */
void MyIdle() {
	trans_left = trans_left + 0.00001;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}

/*문제 정의:
			마우스 함수 등록                                                                                                                                                                      */
void MyMouseClick(GLint Button, GLint state, GLint x, GLint y) {
	switch (Button) {
/*기능:
		마우스 왼쪽 버튼 누르면 Idle 이벤트 처리 Call Back                                                                                                                                        */
	case GLUT_LEFT_BUTTON:
			if (state==GLUT_DOWN)
				glutIdleFunc(MyIdle);
/*기능:
	   윈도우 영역을 벗어나지 않도록 설정                                                                                                                                                         */
			else if (trans_left < -0.5)  trans_left -= -0.1;
	}
/*기능:
	   마우스 오른쪽 버튼 누르면 멈추기                                                                                                                                                           */
	switch (Button) {
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
	}
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}


/*문제 정의:
			윈도우 초기화                                                                                                                                                                         */
int main(int argc, char** argv) {
/*기능:
		Window OS와 Session 연결                                                                                                                                                                  */
	glutInit(&argc, argv);
/*기능:
		Display Mode RGB로 설정                                                                                                                                                                   */
	glutInitDisplayMode(GLUT_RGB);
/*기능:
		Window의 크기 설정                                                                                                                                                                        */
	glutInitWindowSize(300, 300);
/*기능:
		Monitor에서 Window의 시작점 위치                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
/*기능:
		새로운 Window Graphics Mouse Callback 응용 생성                                                                                                                                           */
	glutCreateWindow("Mouse Callback 응용");
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
		행렬변환                                                                                                                                                                                  */
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*기능:
		이벤트 타입 MyMouseClick callback 함수                                                                                                                                                    */
	glutMouseFunc(MyMouseClick);

/*기능:
		GLUT Event 처리 Loop 입력                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/