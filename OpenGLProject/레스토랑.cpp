#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat angle = 0.0;
float SpinX = 0.0f;
float SpinY = 0.0f;
static POINT LMouse;
static POINT CMouse;
static bool Mousing;
static bool Stop;

const GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
const GLfloat orange[] = { 1.0, 0.5, 0.0, 1.0 };
const GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
const GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
const GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };
const GLfloat purple[] = { 0.25, 0.0, 0.5, 1.0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat brown[] = { 0.5, 0.25, 0.25, 1.0 };
const GLfloat dull[] = { 0.0 };
const GLfloat light_pos[] = { 0.0, 3.0, 0.0, 1.0 };
GLfloat Const = 5.0;

void MyInit(void) {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void MyDisplay(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 0.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glShadeModel(GL_SMOOTH);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, Const);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glPushMatrix();

	glRotatef(-SpinY, 1.0, 0.0, 0.0);
	glRotatef(-SpinX, 0.0, 1.0, 0.0);

	glPushMatrix();
	glTranslatef(-5.0, 1.5, 0.0);
	glScalef(0.5, 1.5, 3.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //의자 등받이
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 0.5, 0.0);
	glScalef(1.5, 0.5, 3.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //의자 바닥
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.15, -0.25, 1.25);
	glScalef(0.2, 1.0, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //의자 다리 1
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.15, -0.25, -1.25);
	glScalef(0.2, 1.0, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //의자 다리 2
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.85, -0.25, 1.25);
	glScalef(0.2, 1.0, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //의자 다리 3
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.85, -0.25, -1.25);
	glScalef(0.2, 1.0, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //의자 다리 4
	glPopMatrix();

	glPushMatrix();
	glScalef(2.0, 1.2, 2.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidCube(1.0); //아랫받침
	glPopMatrix();

	glRotatef(angle, 0.0, 1.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glScalef(1.0, 0.4, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidTorus(1.1, 2.0, 30, 30); //테이블
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, 1.8, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidTeapot(0.5); //주전자
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2, 1.4, -2.0);
	glRotatef(30, 0.0, 1.0, 0.0);
	glScalef(1.0, 0.1, 0.7);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, orange);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidSphere(0.5, 30, 30); //1번 접시
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 1.4, -2.0);
	glRotatef(-30, 0.0, 1.0, 0.0);
	glScalef(1.0, 0.1, 0.7);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidSphere(0.5, 30, 30); //2번 접시
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.2, 1.4, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1.0, 0.1, 0.7);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidSphere(0.5, 30, 30); //3번 접시
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 1.4, 2.0);
	glRotatef(30, 0.0, 1.0, 0.0);
	glScalef(1.0, 0.1, 0.7);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidSphere(0.5, 30, 30); //4번 접시
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2, 1.4, 2.0);
	glRotatef(-30, 0.0, 1.0, 0.0);
	glScalef(1.0, 0.1, 0.7);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, purple);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	glutSolidSphere(0.5, 30, 30); //5번 접시
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	GLfloat WidthFactor = (GLfloat)w / (GLfloat)500;
	GLfloat HeightFactor = (GLfloat)h / (GLfloat)500;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-7 * WidthFactor, 7 * WidthFactor, -4 * HeightFactor, 7 * HeightFactor, -8, 8);
}

void MyTimer(int Value) {
	if (Stop == false) {
		angle += 5;
		glutPostRedisplay();
		glutTimerFunc(100, MyTimer, 1);
	}
	else {
		glutPostRedisplay();
	}
}

void MyMouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			LMouse.x = CMouse.x = x;
			LMouse.y = CMouse.y = y;
			Mousing = true;
		}
		else
			Mousing = false;
		break;
	}
	glutPostRedisplay();
}

void MyMotion(int x, int y) {
	CMouse.x = x;
	CMouse.y = y;
	if (Mousing) {
		SpinX -= (CMouse.x - LMouse.x);
		SpinY -= (CMouse.y - LMouse.y);
	}
	LMouse.x = CMouse.x;
	LMouse.y = CMouse.y;
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
	case 'S':
		if (Stop == false) {
			Stop = true;
		}
		else if (Stop == true) {
			Stop = false;
			glutTimerFunc(100, MyTimer, 1);
		}
		break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		Const -= 0.5;
		if (Const <= 2.0) {
			Const = 2.0;
		}
		break;

	case GLUT_KEY_DOWN:
		Const += 0.5;
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW#8");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);
	glutMotionFunc(MyMotion);
	glutTimerFunc(100, MyTimer, 1);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}