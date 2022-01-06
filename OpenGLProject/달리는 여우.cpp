#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

// 기본 상수
#define FRAMERATE			60.0	// 프레임레이트 : 초당 60 프레임
#define PI					3.1416	// 원주율


// 카메라 상태 
double yaw = PI / 2 + PI / 4;				// for 좌우 각도
double pitch = PI / 2 - PI / 8;             // for 위아래 각도
bool is_mouselooking = true;		// 마우스 방향 조작 상태

double phase = 0;				// 동물 이동 상태 : 0 ~ 360


// 렌더링 콜백

void leg();

void animal();

void display() {

	// 설정 초기화
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0, 0, 0, 1);

	// 화면 초기화
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 조명 설정
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light0[] = { 0, 5, -2, 1 };	// 천장 조명
	GLfloat light0_dir[] = { 0, -1, 0, 1 };
	GLfloat light0_amb[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, light0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_dir);
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light0_amb);

	// 모델뷰 변환 설정
	double rad = 20;
	double camera_x = rad * sin(pitch) * cos(yaw);
	double camera_z = rad * sin(pitch) * sin(yaw);
	double camera_y = rad * cos(pitch);
	gluLookAt(camera_x, camera_y, camera_z,
		0, 0, 0,

		0.0f, 1.0f, 0.0f);

	// [그리기 시작]
	glColor3ub(255, 128, 0);
	animal();

	// [그리기 끝]

	// 더블버퍼링 실행
	glutSwapBuffers();
}



// 리셰이프 콜백

void reshape(int w, int h) {

	// 뷰포트 변환 재설정
	glMatrixMode(GL_VIEWPORT);
	glLoadIdentity();
	glViewport(0, 0, w, h);

	// 투영 변환 재설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLdouble)w / h, 0.1, 1000);
}


// 키보드 콜백

void keyboard(unsigned char key, int x, int y);


// 타이머 콜백

void input_timer(int value);

void motion_timer(int value);


// 메인 함수

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	// 윈도우 생성
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// 타이틀, 콜백 설정
	glutCreateWindow("Running Fox");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000 / FRAMERATE, input_timer, 0);
	glutTimerFunc(1000 / FRAMERATE, motion_timer, 0);

	// 메인루프 진입
	glutMainLoop();

	return 0;
}



// 그리기 함수

void leg() {

	glPushMatrix();
	glTranslated(0, -1.0, 0);
	glScaled(0.5, 0.7, 0.5);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -1.5, 0);
	glRotated(40 * cos(phase - PI / 4), 0, 0, 1);
	glScaled(0.5, 0.7, 0.5);
	glTranslated(0, -1, 0);
	glutSolidSphere(1, 30, 30);

	glPushMatrix();
	glTranslated(1, -1.0, 0);
	glScaled(1, 0.1, 0.1);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

void animal() {

	// [ 몸통 ]
	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 0, 1, 0);
	glScaled(4, 1, 2);
	glutSolidSphere(1, 30, 30);

	// [ 꼬리 ]
	glPushMatrix();
	glTranslated(-1.5, 0.5, 0);
	glScaled(0.75, 1.0, 0.5);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
	glPopMatrix();

	// [ 목 ]
	glPushMatrix();
	glTranslated(4.2, 0.5, 0);
	glRotated(50, 0, 0, 1);
	glScaled(0.7, 0.4, 0.4);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	// [ 머리 ]
	glPushMatrix();
	glTranslated(5.2, 1.2, 0);
	glRotated(0, 0, 0, 1);
	glScaled(1.0, 0.7, 0.7);
	glutSolidSphere(1, 30, 30);

	// [ 양쪽 귀 ]
	glPushMatrix();
	glTranslated(0, 1.0, 0.5);
	glScaled(0.2, 0.7, 0.2);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.0, -0.5);
	glScaled(0.2, 0.7, 0.2);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	// [ 코 ]
	glPushMatrix();
	glTranslated(1.0, 0.3, 0.0);
	glScaled(0.2, 0.2, 0.3);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
	glPopMatrix();

	// [ 뒷다리 ]

	glPushMatrix();
	glTranslated(-3.5, 0, 0);		// 다리 위치

	// 왼쪽 뒷다리
	glPushMatrix();
	glTranslated(0, 0, -0.7);
	glRotated(sin(phase + PI / 6 + PI / 3) * 35, 0, 0, 1);	// 다리 각도
	leg();
	glPopMatrix();

	// 오른쪽 뒷다리
	glPushMatrix();
	glTranslated(0, 0, 0.7);
	glRotated(sin(phase + PI / 6) * 35, 0, 0, 1);		// 다리 각도
	leg();
	glPopMatrix();

	glPopMatrix();

	// [ 앞다리 ]

	glPushMatrix();
	glTranslated(3.5, 0, 0);		// 다리 위치

	// 왼쪽 앞다리
	glPushMatrix();
	glTranslated(0, 0, -0.7);
	glRotated(-sin(phase) * 60, 0, 0, 1);	// 다리 각도
	leg();
	glPopMatrix();

	// 오른쪽 앞다리
	glPushMatrix();
	glTranslated(0, 0, 0.7);
	glRotated(-sin(phase + PI / 4) * 60, 0, 0, 1);		// 다리 각도
	leg();
	glPopMatrix();

	glPopMatrix();

}

// 타이머 콜백

void input_timer(int value) {

	// 카메라의 위치 (극좌표계 이용) 를 마우스의 이동 정도에 따라 옮긴다.

	static int init = 0;
	if (init == 0 && is_mouselooking) {          // 초기값
		init = 1;
		SetCursorPos(500, 500);
		glutTimerFunc(1000 / FRAMERATE, input_timer, 0);
		return;
	}

	if (is_mouselooking) {

		POINT cursor;
		GetCursorPos(&cursor);

		// 커서 이동 정도 구하기
		int xOffset, yOffset;
		xOffset = (cursor.x - 500);
		yOffset = (cursor.y - 500);

		// 커서 이동 정도로부터 yaw (옆 각도), pitch (위아래 각도) 업데이트
		yaw += xOffset / 100.0f;
		pitch -= yOffset / 100.0f;
		if (pitch > PI - 0.1) {
			pitch = PI - 0.1;
		}
		else if (pitch < 0.1) {
			pitch = 0.1;
		}

		glutPostRedisplay();
		SetCursorPos(500, 500); // 
		ShowCursor(FALSE);
	}
	else {
		init = 0;
		ShowCursor(TRUE);
	}

	glutTimerFunc(1000 / FRAMERATE, input_timer, 0);

}

void motion_timer(int value) {
	phase += 2 * PI / FRAMERATE;
	glutPostRedisplay();
	glutTimerFunc(1000 / FRAMERATE, motion_timer, 0);
}

// 키보드 콜백

void keyboard(unsigned char key, int x, int y)
{
	switch (tolower(key))
	{
	case 'q':
	case 'Q':
		// 마우스 룩킹 상태를 변경한다.
		if (is_mouselooking == false)
			is_mouselooking = true;
		else
			is_mouselooking = false;
		break;
	case 27:
		exit(EXIT_SUCCESS);
		break;
	}
}