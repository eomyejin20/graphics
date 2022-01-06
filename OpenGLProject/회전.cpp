void MySubMenu_Change_Color(int entryID) {
	if (entryID == 1)
		Red = true; // 작은 크기로 그리기
	else if (entryID == 2)
		Green = false; // 큰 크기로 그리기
	else if (entryID == 2)
		Blue =

		glutAddSubMenu("Change Color", MySubMenuID_Change_Color);
		GLint MySubMenuID_Change_Color = glutCreateMenu(MySubMenu_Change_Color);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 2);


		glutPostRedisplay();


		void MySubMenu_Change_Color(int entryID) {
			if (entryID == 1)
				glColor3f(1.0f, 0.0f, 0.0f);
			else if (entryID == 2)
				glColor3f(0.0f, 1.0f, 0.0f);
			else if (entryID == 3)
				glColor3f(0.0f, 0.0f, 1.0f);
			else
				glColor3f(0.5f, 0.5f, 0.5f);

			glutPostRedisplay();
		}
		GLint MySubMenuID_Change_Color = glutCreateMenu(MySubMenu_Change_Color);
		glutAddMenuEntry("Red", 8);
		glutAddMenuEntry("Green", 9);
		glutAddMenuEntry("Blue", 10);
		glutAddMenuEntry("Change Color", MySubMenuID_Change_Color);
}
#include <gl/glut.h>
#include <stdio.h>

static GLfloat spin = 0.0; // 회전 값 초기화
static GLclampf red = 1.0; // Red값 초기화
static GLclampf green = 1.0; // Green값 초기화
static GLclampf blue = 1.0; // Blue값 초기화
static GLbyte turn = 0; // turn값 초기화

void init(void) // 초기화 함수
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Clear명령시 초기화할 색 지정
	glShadeModel(GL_FLAT); //
}

void display(void) // Display 함수
{
	glClear(GL_COLOR_BUFFER_BIT); // 윈도우 화면 클리어
	glPushMatrix(); //
	glRotatef(spin, 0.0, 0.0, 1.0); //
	glColor3f(red, green, blue); // 색지정
	glRectf(-25.0, -25.0, 25.0, 25.0); // 사각형 그리기
	glPopMatrix();
	glutSwapBuffers(); // 버퍼 교체
}


void MoveMouse(void)
{
	spin = spin + 2.0; // 회전값(spin) 증가

	if (spin > 360.0)
	{
		spin = spin - 360; // 1회전시 회전값 초기화
	}
	


	glutPostRedisplay(); //이건 glutMainLoop()한티 등록된 디스플레이 콜백을 담에 하라고 지시하는겨

}

void reshape(int w, int h) //윈도우 변화시에 쓰는 Call Back 함수
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); // 좌표값 설정
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void mouse(int button, int state, int x, int y) // 마우스 이벤트 처리 Call Back 함수
{
	switch (button) {

	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) // 왼쪽 눌렸어?
			glutIdleFunc(spinDisplay); // 그라면 spinDisplay 실행혀
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) // 오른쪽 눌렸구마?
			glutIdleFunc(NULL); // 그라면 좀 쉬그래이..(일시정지)
		break;
	}
}

int main(int argc, char** argv) // 이거시 메인이여..
{
	glutInit(&argc, argv); // Glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // glut 디스플레이 모드 설정(더블프레임, RGB모드 bitmap)
	glutInitWindowSize(250, 250); // 윈도우 사이즈 초기화
	glutInitWindowPosition(100, 100); // 윈도우 초기 위치 초기화
	glutCreateWindow(argv[0]); // 윈도우 생성시키자.
	init(); // init함수 실행 내나름대로의 초기화
	glutDisplayFunc(display); // 콜백함수 등록
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop(); // MainLoop()실행


	return 0;
}



void MyIdle2() {
	trans_left = trans_left + 0.001;

	glutPostRedisplay();
}

void MyIdle3() {
	trans_up = trans_up + 0.001;

	glutPostRedisplay();
}

void MyIdle4() {
	trans_up = trans_up - 0.001;

	glutPostRedisplay();
}

case GLUT_KEY_RIGHT:     //오른쪽 키
	glutIdleFunc(MyIdle2);
	if (trans_left > 0.5)  trans_left -= 0.1;
	glutPostRedisplay();
	break;
case GLUT_KEY_UP:      //위 키
	glutIdleFunc(MyIdle3);
	if (trans_up > 0.5)  trans_up -= 0.1;
	glutPostRedisplay();
	break;
case GLUT_KEY_DOWN:      //아래 키
	glutIdleFunc(MyIdle4);
	if (trans_up < -0.5)  trans_up -= -0.1;
	glutPostRedisplay();
	break;
