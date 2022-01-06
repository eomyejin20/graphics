
#include <GL/glut.h>
#include <Math.h>

const float PI = 3.14159265f;

float upperarmLength = 0.5f;
float forerarmLength = 0.4f;
float upperarmWidth = 0.2f;
float forerarmWidth = 0.1f;
float handRadius = 0.04f;
float upperarmSpeed = 0.01f;
float forerarmSpeed = 0.05f;
float upperarmX = 0.0f;
float upperarmY = 0.0f;
float forearmX, forearmY, handX, handY;
float currentUpperarmAngle;
float currentForearmAngle;
bool upperarmMove = false;
bool forearmMove = false;
bool upperarmMoveInverse = false;
bool forearmMoveInverse = false;
int refreshMillis = 16;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void drawCirle(float circleX, float circleY, float radius, float r, float g, float b, int segmantNumber = 100)
{
	glLoadIdentity();  // very important
	glTranslatef(circleX, circleY, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(r, g, b);
	GLfloat angle;
	for (int i = 0; i <= segmantNumber; i++)
	{
		angle = i * 2.0f * PI / segmantNumber;
		glVertex2f(cos(angle) * radius, sin(angle) * radius);
	}
	glEnd();
}

void drawArm(float node1X, float node1Y, float node2X, float node2Y, float width)
{
	glBegin(GL_LINES);
	glLineWidth(width);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(node1X, node1Y);
	glVertex2f(node2X, node2Y);
	glEnd();
}

void circularMove(float centerX, float centerY, float& targetX, float& targetY, float& currentAngle, float speed, float radius, bool isMoving, bool inverse)
{
	if (isMoving)
	{
		if (inverse)
		{
			currentAngle += speed;
		}
		else
		{
			currentAngle -= speed;
		}
	}
	targetX = centerX + cos(currentAngle) * radius;
	targetY = centerY + sin(currentAngle) * radius;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	circularMove(upperarmX, upperarmY, forearmX, forearmY, currentUpperarmAngle, upperarmSpeed, upperarmLength, upperarmMove, upperarmMoveInverse);
	circularMove(forearmX, forearmY, handX, handY, currentForearmAngle, forerarmSpeed, forerarmLength, forearmMove, forearmMoveInverse);
	drawArm(upperarmX, upperarmY, forearmX, forearmY, upperarmWidth);
	drawArm(forearmX, forearmY, handX, handY, forerarmWidth);
	drawCirle(handX, handY, handRadius, 0.7925, 0.7925, 0.7925);
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
	{
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else
	{
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a':
		upperarmMove = !upperarmMove; break;
	case 's':
		forearmMove = !forearmMove; break;
	case 'q':
		upperarmMoveInverse = !upperarmMoveInverse; break;
	case 'w':
		forearmMoveInverse = !forearmMoveInverse; break;
	default: break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("robot-arm");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 0);
	init();
	glutMainLoop();
	return 0;
}