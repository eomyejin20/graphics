/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#6. 뷰폿 변환 응용                                                                                                          */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 11월 11일                                                         */
#include <GL/glut.h>

int Width, Height;


/*기능:
	   세상 좌표계 기준의 시점변환 인수                                                                                                                                                           */
float ex = 0.0;
float ey = 3.5;
float ez = 3.5;
float cx, cy, cz, ux = 0.0;
float uy = 1.0;
float uz = 0.0;

void MyInit() {
	
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
		행렬변환                                                                                                                                                                                  */
		glOrtho(-2.0*(64 / 48.0), 2.0*(64 / 48.0), -2.0, 2.0, 0.1, 100.0);
		glViewport(0, 0, 800, 640);

/*기능:
		표면재료의 속성 결정                                                                                                                                                                      */
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
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
/*기능:
		모델뷰 행렬 선택                                                                                                                                                                          */
    glMatrixMode(GL_MODELVIEW);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                      */
	glLoadIdentity();
}

/*문제 정의:
			장면 그리기                                                                                                                                                                           */
void DrawScene() {
                                                                                                                                                     
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();

/*기능:
		teapot 그리기                                                                                                                                                                             */

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);
	glPopMatrix();

/*기능:
		sphere 그리기                                                                                                                                                                             */
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireSphere(2.0, 50, 50);
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
/*기능:
		좌하단의 뷰폿                                                                                                                                                                            */
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
/*기능:
		평행투영                                                                                                                                                                                 */
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0, 2.0f, 50.0f); 
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

/*기능:
		우하단의 뷰폿                                                                                                                                                                            */
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

/*기능:
		좌상단의 뷰폿                                                                                                                                                                            */
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();
/*기능:
		우상단의 뷰폿                                                                                                                                                                            */
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
/*기능:
		원근투영                                                                                                                                                                                 */
	gluPerspective(30, 1.0, 3.0, 50.0);

/*기능:
			모델뷰 행렬 선택                                                                                                                                                                     */
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
/*기능:
		시점좌표계 정의 함수                                                                                                                                                                     */
	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
	glFlush();
}


/*문제 정의:
			투영변환, 뷰폿변환                                                                                                                                                                   */
void MyReshape(int NewWidth, int NewHeight) {
/*기능:
		전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 (NewWidth)*(NewHeight) 영역에 출력                                                                              */
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
/*기능:
		모델뷰 행렬 선택                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                     */
	glLoadIdentity();
/*기능:
		행렬변환                                                                                                                                                                                 */
	glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor, -1.0, 1.0);
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
			윈도우 초기화                                                                                                                                                                        */
int main(int argc, char** argv) {
/*기능:
		Window OS와 Session 연결                                                                                                                                                                 */
	glutInit(&argc, argv);
/*기능:
		Window의 크기 인수                                                                                                                                                                       */
	Width = 1000;
	Height = 1000;
/*기능:
		Display Mode RGB, Single로 설정                                                                                                                                                          */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
/*기능:
		Window의 크기 설정                                                                                                                                                                       */
	glutInitWindowSize(Width, Height);
/*기능:
		Monitor에서 Window의 시작점 위치                                                                                                                                                         */
	glutInitWindowPosition(0, 0);
/*기능:
		새로운 Window Graphics 뷰폿변환 응용 생성                                                                                                                                                */
	glutCreateWindow("뷰폿 변환 응용");
	MyInit();
/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                        */
	glutDisplayFunc(MyDisplay);
/*기능:
		이벤트 타입 RESHAPE callback 함수                                                                                                                                                        */
	glutReshapeFunc(MyReshape);
/*기능:
		이벤트 타입 MySpecialKey callback 함수                                                                                                                                                   */
	glutSpecialFunc(MySpecialKey);
/*기능:
		GLUT Event 처리 Loop 입력                                                                                                                                                                */
	glutMainLoop();
	return 0;
}
/*************************************************************************************************************************************************************************************************/