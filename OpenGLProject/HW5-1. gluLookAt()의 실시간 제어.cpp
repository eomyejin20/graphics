/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#5-2. 모델뷰 변환 종합 실습                                                                                                      */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 11월 4일                                                          */


#include <GL/glut.h>

/*기능:
	   세상 좌표계 기준의 시점변환 인수                                                                                                                                                  */
float ex = 0.0;
float ey = 3.5;
float ez = 3.5;
float cx, cy, cz, ux = 0.0;
float uy = 1.0;
float uz = 0.0;

/*문제 정의:
			땅 그리기                                                                                                                                                                   */
void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}

	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}

void MyDisplay() {
/*기능:
		색 버퍼와 깊이 버퍼 제거                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*기능:
		모델뷰 행렬 선택                                                                                                                                                                      */
	glMatrixMode(GL_MODELVIEW);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                  */
	glLoadIdentity();

	DrawGround();
/*기능:
		시점좌표계 정의 함수                                                                                                                                                  */
	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
/*기능:
		티팟의 색 지정                                                                                                                                                  */
	glColor3f(1.0, 1.0, 0.0);
/*기능:
		티팟 그리기                                                                                                                                                  */
	glutWireTeapot(1.0);
	glFlush();
}

/*문제 정의:
			투영변환, 뷰폿변환                                                                                                                                                                   */
void MyReshape(int w, int h) {
/*기능:
		전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 (GLsizei)w*(GLsizei)h 영역에 출력                                                                            */
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
/*기능:
		투영행렬 선택                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 투영행렬을 항등행렬로 초기화                                                                                                                                                     */
	glLoadIdentity();
/*기능:
		큐브 뷰 프로젝션 매트릭스를 설정                                                                                                                                                     */
	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}

/*문제 정의:
			Idle1 이벤트 등록                                                                                                                                                                     */
void MyIdle1() {
/*기능:
		왼쪽 키 입력 시 camera X축 좌표 연속적으로 0.1씩 감소                                                                                                                                                        */
	ex = ex -0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}
/*문제 정의:
			Idle2 이벤트 등록                                                                                                                                                                     */
void MyIdle2() {
/*기능:
		오른쪽 키 입력 시 camera X축 좌표 연속적으로 0.1씩 증가                                                                                                                                                        */
	ex = ex + 0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}
/*문제 정의:
			Idle3 이벤트 등록                                                                                                                                                                     */
void MyIdle3() {
/*기능:
		윗쪽 키 입력 시 camera Y축 좌표 연속적으로 0.1씩 증가                                                                                                                                                          */
	ey = ey + 0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}
/*문제 정의:
			Idle4 이벤트 등록                                                                                                                                                                     */
void MyIdle4() {
/*기능:
		아래쪽 키 입력 시 camera Y축 좌표 연속적으로 0.1씩 감소                                                                                                                                                           */
	ey = ey - 0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
	glutPostRedisplay();
}


/*문제 정의:
			스페셜 키보드 이벤트 처리 Call Back 함수                                                                                                                                              */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
/*기능:
		이벤트 타입 MyIdle1 callback 함수                                                                                                                                                         */
	case GLUT_KEY_LEFT:
		glutIdleFunc(MyIdle1);
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                  */
		glutPostRedisplay();
		break;
/*기능:
		이벤트 타입 MyIdle2 callback 함수                                                                                                                                                         */
	case GLUT_KEY_RIGHT:
		glutIdleFunc(MyIdle2);
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
		이벤트 타입 MyIdle3 callback 함수                                                                                                                                                         */
	case GLUT_KEY_UP:
		glutIdleFunc(MyIdle3);
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
		이벤트 타입 MyIdle4 callback 함수                                                                                                                                                                                                                                                                                                        */
	case GLUT_KEY_DOWN:
		glutIdleFunc(MyIdle4);
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                  */
		glutPostRedisplay();
		break;

	}
}
/*문제 정의:
			키보드 함수 등록                                                                                                                                                     */
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
/*기능:
		27 입력 시 종료                                                                                                                                                            */
	switch (KeyPressed)
		if (KeyPressed == '27') {
			exit(0);
			break;
	}
/*기능:
		a 입력 시 초점 X축 좌표 0.1씩 증가                                                                                                                                                             */
	if (KeyPressed == 'a') {
			cx = cx + 0.1;
		}
/*기능:
		f 입력 시 초점 X축 좌표 0.1씩 감소                                                                                                                                                           */
	if (KeyPressed == 'f') {
		cx = cx - 0.1;
	}
/*기능:
		v 입력 시 초점 Y축 좌표 0.1씩 감소                                                                                                                                                             */
	if (KeyPressed == 'v') {
		cy = cy - 0.1;
	}
/*기능:
		r 입력 시 초점 Y축 좌표 0.1씩 증가                                                                                                                                                           */
	if (KeyPressed == 'r') {
		cy = cy + 0.1;
		
	}
/*기능:
		z 입력 시 초점 Z축 좌표 0.1씩 증가                                                                                                                                                                     */
	if (KeyPressed == 'z') {
		cz = cz + 0.1;
	}
/*기능:
		t 입력 시 초점 Z축 좌표 0.1씩 감소                                                                                                                                                                   */
	if (KeyPressed == 't') {
		cz = cz - 0.1;
	}
/*기능:
		A 입력 시 초점 X축 좌표 0.1씩 증가                                                                                                                                                              */
	if (KeyPressed == 'A') {
		cx = cx + 0.1;
	}
/*기능:
		F 입력 시 초점 X축 좌표 0.1씩 감소                                                                                                                                                           */
	if (KeyPressed == 'F') {
		cx = cx - 0.1;
	}
/*기능:
		V 입력 시 초점 Y축 좌표 0.1씩 감소                                                                                                                                                             */
	if (KeyPressed == 'V') {
		cy = cy - 0.1;
	}
/*기능:
		R 입력 시 초점 Y축 좌표 0.1씩 증가                                                                                                                                                            */
	if (KeyPressed == 'R') {
		cy = cy + 0.1;
	}
/*기능:
		Z 입력 시 초점 Z축 좌표 0.1씩 증가                                                                                                                                                                 */
	if (KeyPressed == 'Z') {
		cz = cz + 0.1;
	}
/*기능:
		T 입력 시 초점 Z축 좌표 0.1씩 감소                                                                                                                                                                 */
	if (KeyPressed == 'T') {
		cz = cz - 0.1;
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
			Display Mode RGBA, SINGLE로 설정                                                                                                                                                                   */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	/*기능:
			Window의 크기 설정                                                                                                                                                                        */
	glutInitWindowSize(500, 500);
	/*기능:
			Monitor에서 Window의 시작점 위치                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
	/*기능:
			새로운 Window Graphics gluLookAt()의 실시간 제어 생성                                                                                                                                      */
	glutCreateWindow("VCS (View Coordinate System) 변형");
	/*기능:
			창 배경 검은색                                                                                                                                                                              */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*기능:
			이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
	/*기능:
			이벤트 타입 RESHAPE callback 함수                                                                                                                                                      */
	glutReshapeFunc(MyReshape);
	/*기능:
			이벤트 타입 MySpecialKey callback 함수                                                                                                                                                    */
	glutSpecialFunc(MySpecialKey);
	/*기능:
			이벤트 타입 MyKeyboard callback 함수                                                                                                                                                      */
	glutKeyboardFunc(MyKeyboard);
	/*기능:
			GLUT Event 처리 Loop 입력                                                                                                                                                                 */
	glutMainLoop();
	return 0;
}
/**************************************************************************************************************************************************************************************************/