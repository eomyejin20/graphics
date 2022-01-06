#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>


GLfloat v[4][3] = { {0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
	  {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333} };

GLfloat colors[4][3] = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0},
						{0.0, 0.0, 1.0}, {0.0, 0.0, 0.0} };
GLfloat eye[3], at[3];
GLfloat eye_start[3] = { 1.0, 1.0, 1.0 };
GLfloat eye_end[3] = { 0.0, 0.0, 0.0 };
GLfloat alpha = 0.0, delta = 0.003;

int n;
static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;


void triangle(GLfloat *va, GLfloat *vb, GLfloat *vc)
{
	glVertex3fv(va);
	glVertex3fv(vb);
	glVertex3fv(vc);
}

void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
	glColor3fv(colors[0]);
	triangle(a, b, c);
	glColor3fv(colors[1]);
	triangle(a, c, d);
	glColor3fv(colors[2]);
	triangle(a, d, b);
	glColor3fv(colors[3]);
	triangle(b, d, c);
}

void divide_tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{

	GLfloat mid[6][3];
	int j;

	glBegin(GL_TRIANGLES);
	if (m > 0)
	{
		/* compute six midpoints */

		for (j = 0; j < 3; j++) mid[0][j] = (a[j] + b[j]) / 2;
		for (j = 0; j < 3; j++) mid[1][j] = (a[j] + c[j]) / 2;
		for (j = 0; j < 3; j++) mid[2][j] = (a[j] + d[j]) / 2;
		for (j = 0; j < 3; j++) mid[3][j] = (b[j] + c[j]) / 2;
		for (j = 0; j < 3; j++) mid[4][j] = (c[j] + d[j]) / 2;
		for (j = 0; j < 3; j++) mid[5][j] = (b[j] + d[j]) / 2;

		/* create 4 tetrahedrons by subdivision */

		divide_tetra(a, mid[0], mid[1], mid[2], m - 1);
		divide_tetra(mid[0], b, mid[3], mid[5], m - 1);
		divide_tetra(mid[1], mid[3], c, mid[4], m - 1);
		divide_tetra(mid[2], mid[4], d, mid[5], m - 1);

	}
	else(tetra(a, b, c, d)); /* draw tetrahedron at end of recursion */
	glEnd();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(1.0, 1.0, 1.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);




	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	divide_tetra(v[0], v[1], v[2], v[3], n);

	glFlush();
	glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{

	/* 회전 중심축을 선택 */

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / h, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}


void spinCube(void)
{

	/* 선택된 축을 중심으로 회전 */
	theta[axis] += 2.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;

	for (int i = 0; i <= 300000; i++)
		//delay();
		glutPostRedisplay();


}

void approach(int value)
{
	int i;
	alpha = alpha + delta;
	for (i = 0; i < 3; i++)eye[i] = (1.0 - alpha)*eye_start[i] + alpha * eye_end[i];
	glutTimerFunc(50, approach, 1);
}



int main(int argc, char **argv)
{

	n = 2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D Gasket");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(mouse);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutMainLoop();
}



