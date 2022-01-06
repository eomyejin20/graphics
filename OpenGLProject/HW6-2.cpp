#include <GL/glut.h>

int Width, Height;
/*기능:
		시야각                                                                                                                                                                                    */
double horizAngle = 0.0;
double vertAngle = 0.0;

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

	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

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

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);
	glPopMatrix();

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireSphere(2.0, 50, 50);
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0, 2.0f, 50.0f); //
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(30, 1.0, 3.0, 50.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}


void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)400;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)400;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor, -1.0, 1.0);
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


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 1000;
	Height = 1000;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Viewpory Partition");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	/*기능:
		이벤트 타입 MySpecialKey callback 함수                                                                                                                                                    */
	glutSpecialFunc(arrowKeyPress);
	glutMainLoop();
	return 0;
}