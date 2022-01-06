/******************************************************************************/
/*                               HW#8 :비행기조종                             */
/* 작성자 : XXX                                 날짜 : 2020년 12월 08일        */
/*                                                                            */
/* 게임 설명 : 지금까지 배운 내용을 토대로 비행기 조종 게임을 만들었습니다.   */
/*             메인 화면에서 우측클릭으로 메뉴를 띄워 모델, 색, 난이도를 선택 */
/*             할 수 있습니다. 게임 진행을 위해 마우스 좌측클릭으로 조종기의  */
/*             전원을 킵니다. 그 후 화면이 전환되고 게임이 시작됩니다.        */
/*                                                                            */
/*             w,a,s,d로 기체를 상하좌우로 움직이며 방향키로 시야를 조정합니다*/
/*             앞에 보이는 장애물을 피해 마지막 WireCube에 도착하면 골인입니다*/
/******************************************************************************/

#include <GL/glut.h>
#include<cstdlib>
#include<ctime>

// 게임 설명 글라이더 비행 경로의 아이템들을 최대한 많이 획득하고 도착지점에 타이밍을 맞춰 도착하기

int Width;			// window의 가로
int Height;			// window의 세로 
int start = 0;

GLfloat eyeupdown = 0, eyeside = 0;     //시야 변수
GLfloat movego = 0, moveup = 0, moveside = 0;    //몸체 이동 변수
GLfloat buttonup = 0, next = 0, noeye = 0, convert = 0;   //화면 전환 변수
GLfloat mode = 1, modelnum = 1, modelcolor = 0;     // 메뉴 변수
GLfloat turnsight = 0, sightcheck = 0, sightstate;   // 몸체의 기울임 변수
GLfloat noticecolor1 = 1, noticecolor2 = 0;   //메인화면 조종기 버튼 색
GLdouble Widthfactor;			// window의 변화에 따른 Width의 변화율
GLdouble Heightfactor;			// window의 변화에 따른 Height의 변화율
GLUquadricObj* qobj = gluNewQuadric();

//비행기 모델 색상 함수
int randomcolor() {                 //비행기 색을 랜덤하게 바꿔주기 위해 0 ~ 9의 랜덤 값을 받아옵니다.
	srand((unsigned int)time(NULL));

	int num = rand();
	return num % 10;
}

//메뉴 난이도 조절 함수
void Difficulty(int entryID) {         //메뉴에서 난이도를 설정합니다.
	if (entryID == 1) {
		mode = 1;
	}
	else if (entryID == 2) {
		mode = 1.5;
	}
	else if (entryID == 3) {
		mode = 2;
	}
	glutPostRedisplay();           // Display함수를 재호출하여 다시 그림을 그립니다.
}

//메뉴 모델 교체 함수
void ChangeModel(int entryID) {         //메뉴에서 받은 entryID로 비행기 모델을 선택합니다.
	if (entryID == 1) {
		modelnum = 1;
		glutPostRedisplay();
	}
	else if (entryID == 2) {
		modelnum = 2;
		glutPostRedisplay();

	}
	else if (entryID == 3) {
		modelnum = 3;
		glutPostRedisplay();
	}
	glutPostRedisplay();           // Display함수를 재호출하여 다시 그림을 그립니다.
}

// 메인 메뉴 함수
void MyMainMenu(int entryID) {          //Mainmenu에서 entryID로 1번을 받으면 비행기 색이 바뀝니다.
	if (entryID == 1)
	{
		modelcolor = randomcolor();
	}
	if (entryID == 2)                   //entryID로 5번을 받으면 게임을 종료합니다.
		exit(0);
	glutPostRedisplay();           // Display함수를 재호출하여 다시 그림을 그립니다.
}

//초기화 함수
void MyInit() {

	glMatrixMode(GL_PROJECTION);                // 직교투영을 통해 화면 왜곡문제를 해결합니다.
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLint HardID = glutCreateMenu(Difficulty);    //Difficulty (난이도)에 대한 submenu를 생성합니다.
	glutAddMenuEntry("Easy", 1);
	glutAddMenuEntry("Normal", 2);
	glutAddMenuEntry("Hard", 3);

	GLint ChangeID = glutCreateMenu(ChangeModel);    //Change Model에 대한 submenu를 생성합니다.
	glutAddMenuEntry("Model A", 1);
	glutAddMenuEntry("Model B", 2);
	glutAddMenuEntry("Model C", 3);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);    //MainMenu를 생성합니다.
	glutAddSubMenu("Difficulty", HardID);
	glutAddSubMenu("Change Model", ChangeID);
	glutAddMenuEntry("Change color", 1);
	glutAddMenuEntry("Exit", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

//게임 시작을 알림 (화살표 색상 변경)
void notice() {
	glColor3f(noticecolor1, noticecolor2, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.08, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.02, 0.0);
	glVertex3f(0.02, 0.0, 0.0);
	glVertex3f(0.01, 0.0, 0.0);
	glVertex3f(0.01, 0.03, 0.0);
	glVertex3f(-0.01, 0.03, 0.0);
	glVertex3f(-0.01, 0, 0.0);
	glVertex3f(-0.02, 0, 0.0);
	glEnd();
}

//게임 맵을 그립니다
void Drawmap()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(turnsight, 1.0, 0.0, 0.0);

	glColor3f(0.7, 0.7, 0.7);  // 바닥을 그립니다.
	glPushMatrix();
	glRotatef(30, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(50, 0.0, 50);
	glVertex3f(50, 0.0, -50);
	glVertex3f(-50, 0.0, -50);
	glVertex3f(-50, 0.0, 50);
	glEnd();
	glPopMatrix();

	//골인
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.1);
	glTranslatef(8, 1.3, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutWireCube(1);
	glPopMatrix();

	// 마지막 단계
	glPushMatrix();
	glColor3f(0.2, 0.0, 0.2);
	glTranslatef(6, 1.5, 0.0);
	glScalef(1, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.4, 0.3);
	glTranslatef(3, 3.0, 0.0);
	glScalef(0.5, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.8, 0.2);
	glTranslatef(3, 8.0, 0.0);
	glScalef(3, 8, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.0, 0.2);
	glTranslatef(0, 1.0, 0.0);
	glScalef(1, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();


	//3단계
	glPushMatrix();
	glColor3f(0.6, 1.0, 0.6);
	glTranslatef(-5, 3.0, -2.0);
	glScalef(1, 6, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6, 1.0, 0.6);
	glTranslatef(-5, 3.0, 2.0);
	glScalef(1, 6, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.0);
	glTranslatef(-5, 2.0, 0.0);
	glScalef(1, 4, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(-5, 8, 0.0);
	glScalef(1, 2, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	//2단계
	glPushMatrix();
	glColor3f(1.0, 0.2, 0.2);
	glTranslatef(-10, 1.0, 0.0);
	glScalef(1, 2, 6.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.4, 0.4);
	glTranslatef(-10, 6.0, 0.0);
	glScalef(1, 6, 6.0);
	glutSolidCube(1);
	glPopMatrix();


	//1단계
	glPushMatrix();
	glColor3f(0.2, 0.2, 1.0);
	glTranslatef(-15, 5.0, 5.0);
	glScalef(1, 10, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.2, 1.0);
	glTranslatef(-15, 5.0, -5.0);
	glScalef(1, 10, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 1.0);
	glTranslatef(-15, 5.0, 0.0);
	glScalef(1, 10, 4.0);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

//화면 전환 함수
void Converting(int value) {
	if (convert < 2.9999) {
		convert += 0.1;
		glutPostRedisplay();
		glutTimerFunc(30, Converting, 1);
	}
	else {
		next = 1;
		return;
	}
}

//게임 실행 화면
void Mygame(int value) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1 * Widthfactor, 1 * Widthfactor, -1 * Heightfactor, 1 * Heightfactor, -1.0, 5);	// 직교투영함수로 가시부피를 상황에 맞게 변화시켜 왜곡문제 해결
	gluPerspective(100, 1.0, 0.0, 100.0);		// 원근 투영을 통해 현실적인 시야 확보

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	gluLookAt(-25.0 + movego, 3 + moveup, 0.0 + moveside, 5.0, 1.3 + eyeupdown, 0.0 + eyeside, 0.0, 1.0, 0.0);	// 시점 좌표게 설정
	Drawmap();

	if (modelnum == 1) {            // 메뉴에서 모델 A를 선택하면 비행기의 모양이 바뀝니다.
		glScalef(0.8, 0.8, 0.8);
		glPushMatrix();
		glColor3f(modelcolor, modelcolor / 2, modelcolor / 3);
		glBegin(GL_POLYGON);
		glVertex3f(-24.0 + movego, 2.0 + moveup, 0.0 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, 0.4 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, -0.4 + moveside);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(-22.3 + movego, 2.0 + moveup, 0.0 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, 0.2 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, -0.2 + moveside);
		glEnd();

		glPopMatrix();
	}
	else if (modelnum == 2) {       // 메뉴에서 모델 A를 선택하면 비행기의 모양이 바뀝니다.
		glScalef(0.8, 0.8, 0.8);
		glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_POLYGON);
		glVertex3f(-23.0 + movego, 2.0 + moveup, 0.2 + moveside);
		glVertex3f(-23.0 + movego, 2.0 + moveup, -0.2 + moveside);
		glVertex3f(-24.0 + movego, 2.0 + moveup, -0.2 + moveside);
		glVertex3f(-24.0 + movego, 2.0 + moveup, 0.2 + moveside);
		glEnd();

		glColor3f(modelcolor, modelcolor / 2, modelcolor / 3);
		glBegin(GL_POLYGON);
		glVertex3f(-23.2 + movego, 2.0 + moveup, 0.1 + moveside);
		glVertex3f(-23.2 + movego, 2.0 + moveup, -0.1 + moveside);
		glVertex3f(-23.8 + movego, 2.0 + moveup, -0.1 + moveside);
		glVertex3f(-23.8 + movego, 2.0 + moveup, 0.1 + moveside);
		glEnd();

		glPopMatrix();
	}
	else if (modelnum == 3) {       // 메뉴에서 모델 A를 선택하면 비행기의 모양이 바뀝니다.
		glScalef(0.8, 0.8, 0.8);
		glPushMatrix();
		glTranslatef(-5 + movego, 2.0 + moveup, 0.0 + moveside);
		glColor3f(modelcolor, modelcolor / 2, modelcolor / 3);
		gluSphere(qobj, 1.0, 20, 20);
		glPopMatrix();
	}
	glPopMatrix();

	glFlush();

}

//처음 메인 화면 (조종기 모양 출력)
void Mymain() {

	if (next == 0) {
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		notice();   //조종기 버튼 출력

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1 * Widthfactor, 1 * Widthfactor, -1 * Heightfactor, 1 * Heightfactor, -1.0, 5);	// 직교투영함수로 가시부피를 상황에 맞게 변화시켜 왜곡문제 해결

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.3, 0);
		glVertex3f(0.5, -0.3, 0);
		glVertex3f(0.5, 0.3, 0);
		glVertex3f(0.3, 0.5, 0);
		glVertex3f(-0.3, 0.5, 0);
		glVertex3f(-0.5, 0.3, 0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.4, 0.3, 0);
		glVertex3f(0.25, 0.45, 0);
		glVertex3f(-0.25, 0.45, 0);
		glVertex3f(-0.4, 0.3, 0);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.05, 0.3, 0);
		glVertex3f(0.03, 0.8, 0);
		glVertex3f(-0.03, 0.8, 0);
		glVertex3f(-0.05, 0.3, 0);
		glEnd();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(-1.3, 0.0, 0.0);
		gluDisk(qobj, 0.7, 0.8, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(1.3, 0.0, 0.0);
		gluDisk(qobj, 0.7, 0.8, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(-1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.7, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.7, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(-1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.15, 20, 2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);
		glTranslated(1.3, 0.0, 0.0);
		gluDisk(qobj, 0, 0.15, 20, 2);
		glPopMatrix();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.02, 0.05, 0);
		glVertex3f(-0.02, 0.05, 0);
		glVertex3f(-0.02, -0.05, 0);
		glVertex3f(0.02, -0.05, 0);
		glEnd();

		glColor3f(0.8, 0.8, 0.8);
		glBegin(GL_POLYGON);
		glVertex3f(0.02, 0.00 + buttonup, 0);
		glVertex3f(-0.02, 0.00 + buttonup, 0);
		glVertex3f(-0.02, -0.04 + buttonup, 0);
		glVertex3f(0.02, -0.04 + buttonup, 0);
		glEnd();

		glPushMatrix();
		notice();
		glPopMatrix();

		glColor3f(1.0, 1.0, 1.0);
		gluDisk(qobj, 3 - convert, 5, 30, 3);

		glFlush();
	}
	else glutTimerFunc(2000, Mygame, 1);
}

// 글라이더의 고도, 좌우방향을 조절하기 위해 키보드 입력을 받습니다.
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'W':
	case 'w':                       //W 또는 w를 누르면 앞과 위로 이동합니다.          
		movego += 0.01;
		moveup += 0.05;
		sightcheck = 0;
		break;
	case 'S':
	case 's':                       //S 또는 s를 누르면 밑으로 이동합니다.
		moveup -= 0.01;
		break;
	case 'A':
	case 'a':                       //A 또는 a를 누르면 좌측으로 이동합니다.
		moveside -= 0.02;
		sightcheck = 1;
		break;
	case 'D':
	case 'd':                       //D 또는 d를 누르면 우측으로 이동합니다.
		moveside += 0.02;
		sightcheck = -1;
		break;
	case 'Q':                   // q 또는 Q를 입력받으면 프로그램을 종료합니다.
	case 'q':
		exit(0);
		break;
	case 27:                    // ESC를 입력받으면 프로그램을 종료합니다.
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();           // Display함수를 재호출하여 다시 그림을 그립니다.
}

// 글라이더의 시점을 조절하기 위해 키보드 입력을 받습니다.
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:        // 우측방향키를 누르면 오른쪽을 바라봅니다.
		eyeside += 0.1;
		break;
	case GLUT_KEY_LEFT:          // 좌측방향키를 누르면 왼쪽을 바라봅니다.
		eyeside -= 0.1;
		break;
	case GLUT_KEY_UP:           // 위방향키를 누르면 위쪽을 바라봅니다.
		eyeupdown += 0.2;

		break;
	case GLUT_KEY_DOWN:        // 아래방향키를 누르면 아래쪽을 바라봅니다.
		eyeupdown -= 0.2;
		break;
	default:
		break;
	}
	glutPostRedisplay();                //Display함수를 재호출하여 그림을 다시 그립니다.
}

// 마우스를 좌측클릭하면 메인화면에서 게임화면으로 이동합니다.
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP)
	{
		buttonup = 0.04;
		noticecolor1 = 0;
		noticecolor2 = 1;
		glutTimerFunc(500, Converting, 1);
	}
	glutPostRedisplay();
}

//비행기 이동 함수
void MoveToFront(int value) {
	if (movego <= 29) {               // 목적지까지 전진이동 합니다.
		movego += 0.02*mode;         // 난이도에 따라 전진 속도가 바뀝니다.
		glutPostRedisplay();
		glutTimerFunc(50, MoveToFront, 1);
	}
	else {                      //목적지에 도착하면 전진을 멈춥니다.
		noeye = movego;
		return;
	}
}

//비행기 하강 함수
void Moveupdown(int value) {
	if (moveup > -1.0) {        // 하늘에서 떨어지고 있기에 연속적인 하강을 나타냅니다.
		moveup -= 0.01;
		glutPostRedisplay();
		glutTimerFunc(100, Moveupdown, 1);
	}
	else return;
}

//시야 이동 함수
void EyeDown(int value) {
	if (noeye == 0) {               //목적지에 도착시, 시점을 더이상 내리지 않습니다.
		if (eyeupdown > -5.0) {      //시점이 바닥을 볼 때 까지 연속적으로 시점을 내립니다.
			eyeupdown -= 0.3;
			glutPostRedisplay();
			glutTimerFunc(50, EyeDown, 1);
		}
	}
	else return;
}

//회전에 따른 시야 조종 함수
void Sight(int value) {     // 키보드 입력에 따라 좌회전, 우회전, 직진 3가지의 경우를 파악하여 Timer함수 재귀 실행
	value = sightcheck;
	if (value == -1)        //좌회전하는 경우
	{
		turnsight -= 0.2;       // 몸체를 좌측으로 기울입니다.
		sightstate = sightcheck;    //좌측으로 이동하고 있음을 저장합니다.
		glutPostRedisplay();
		glutTimerFunc(100, Sight, sightstate);
	}
	else if (value == 1)     //우회전하는 경우
	{
		turnsight += 0.2;       // 몸체를 우측으로 기울입니다.
		sightstate = sightcheck;    //우측으로 이동하고 있음을 저장합니다.
		glutPostRedisplay();
		glutTimerFunc(100, Sight, sightstate);
	}
	else                  // 직진 하는 경우
	{
		sightstate = sightcheck;
		glutPostRedisplay();
		glutTimerFunc(100, Sight, sightstate);
	}
}

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	Width = w;	// viewport의 크기도 같은 비율로 변해야 하기 때문에 Width, Height도 계속 변동
	Height = h;
	Widthfactor = (GLfloat)Width / (GLfloat)700;	// Widht와 Height 변화율
	Heightfactor = (GLfloat)Height / (GLfloat)700;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //윈도우를 연결하고 GLUT 라이브러리를 초기화합니다.
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);      //RGB색을 사용하도록 화면모드를 설정합니다.
	glutInitWindowSize(1200, 1200);       //화면의 크기를 설정합니다.
	glutInitWindowPosition(300, 0);       //화면의 위치를 설정합니다.
	glutCreateWindow("Glider simulator");  //"Menu Callback" 이라는 이름의 화면을 생성합니다.
	MyInit();                           //MyInit함수를 호출합니다. (여러가지 초기화 및 설정을 합니다.)
	glutMouseFunc(MyMouseClick);        // 처음 마우스 클릭을 게임을 시작합니다.
	glutKeyboardFunc(MyKeyboard);       // 글라이더의 고도, 좌우방향을 조절하기 위해 키보드 입력을 받습니다.
	glutSpecialFunc(MySpecial);         // 글라이더의 시점을 조절하기 위해 키보드 입력을 받습니다.
	glutReshapeFunc(MyReshape);         // 수정된 그림을 다시 그립니다.
	glutDisplayFunc(Mymain);            // 게임의 시작화면을 출력합니다.
	glutTimerFunc(100, MoveToFront, 20);    //글라이더 연속 전진 Timer 콜백함수 등록
	glutTimerFunc(100, Moveupdown, 1);      //글라이더 연속 하락Timer 콜백함수 등록
	glutTimerFunc(100, EyeDown, 1);         //글라이더 연속 아래방향 시점 변화 Timer 콜백함수 등록
	glutTimerFunc(50, Sight, 1);            // 키보드 입력에 의한 글라이더 조종 Timer 콜백함수 등록
	glutMainLoop();                     //Main함수를 루프합니다.
	return 0;
}