/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#6. ���� ��ȯ ����                                                                                                          */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 11�� 11��                                                         */
#include <GL/glut.h>

int Width, Height;


/*���:
	   ���� ��ǥ�� ������ ������ȯ �μ�                                                                                                                                                           */
float ex = 0.0;
float ey = 3.5;
float ez = 3.5;
float cx, cy, cz, ux = 0.0;
float uy = 1.0;
float uz = 0.0;

void MyInit() {
	
/*���:
		â ���                                                                                                                                                                                   */
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
/*���:
		������� ����                                                                                                                                                                             */
		glMatrixMode(GL_PROJECTION);
/*���:
		���� ��������� �׵���ķ� �ʱ�ȭ                                                                                                                                                         */
		glLoadIdentity();
/*���:
		��ĺ�ȯ                                                                                                                                                                                  */
		glOrtho(-2.0*(64 / 48.0), 2.0*(64 / 48.0), -2.0, 2.0, 0.1, 100.0);
		glViewport(0, 0, 800, 640);

/*���:
		ǥ������� �Ӽ� ����                                                                                                                                                                      */
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

/*���:
		â ��� ���                                                                                                                                                                              */
	glClearColor(1.0, 1.0, 1.0, 1.0);
/*���:
		������� ����                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                      */
    glLoadIdentity();
/*���:
		��ĺ�ȯ                                                                                                                                                                                  */
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
/*���:
		�𵨺� ��� ����                                                                                                                                                                          */
    glMatrixMode(GL_MODELVIEW);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                      */
	glLoadIdentity();
}

/*���� ����:
			��� �׸���                                                                                                                                                                           */
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

/*���:
		teapot �׸���                                                                                                                                                                             */

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);
	glPopMatrix();

/*���:
		sphere �׸���                                                                                                                                                                             */
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireSphere(2.0, 50, 50);
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
/*���:
		���ϴ��� ����                                                                                                                                                                            */
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
/*���:
		��������                                                                                                                                                                                 */
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0, 2.0f, 50.0f); 
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

/*���:
		���ϴ��� ����                                                                                                                                                                            */
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

/*���:
		�»���� ����                                                                                                                                                                            */
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();
/*���:
		������ ����                                                                                                                                                                            */
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
/*���:
		��������                                                                                                                                                                                 */
	gluPerspective(30, 1.0, 3.0, 50.0);

/*���:
			�𵨺� ��� ����                                                                                                                                                                     */
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
/*���:
		������ǥ�� ���� �Լ�                                                                                                                                                                     */
	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
	glFlush();
}


/*���� ����:
			������ȯ, ������ȯ                                                                                                                                                                   */
void MyReshape(int NewWidth, int NewHeight) {
/*���:
		��ü�� â���� �׸� �� �ֵ��� viewport�� pixel ��ǥ�� ��ġ�ϵ��� �������� (NewWidth)*(NewHeight) ������ ���                                                                              */
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
/*���:
		�𵨺� ��� ����                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                     */
	glLoadIdentity();
/*���:
		��ĺ�ȯ                                                                                                                                                                                 */
	glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor, -1.0, 1.0);
}


/*���� ����:
			����� Ű���� �̺�Ʈ ���                                                                                                                                                            */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
/*���:
		���� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                      */
	case GLUT_KEY_LEFT:
/*���:
		���� Ű �Է� �� camera X�� ��ǥ ���������� 0.1�� ����                                                                                                                                    */
		ex = ex - 0.01;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
/*���:
		������ Ű �Է� �� ���������� 0.1�� �̵�                                                                                                                                                  */
	case GLUT_KEY_RIGHT:
/*���:
		������ Ű �Է� �� camera X�� ��ǥ ���������� 0.1�� ����                                                                                                                                  */
		ex = ex + 0.01;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
/*���:
		�� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                        */
	case GLUT_KEY_UP:
/*���:
		���� Ű �Է� �� camera Y�� ��ǥ ���������� 0.1�� ����                                                                                                                                    */
		ey = ey + 0.01;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
/*���:
		�Ʒ� Ű �Է� �� �Ʒ������� 0.1�� �̵�                                                                                                                                                    */
	case GLUT_KEY_DOWN:
/*���:
		�Ʒ��� Ű �Է� �� camera Y�� ��ǥ ���������� 0.1�� ����                                                                                                                                  */
		ey = ey - 0.01;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                */
		glutPostRedisplay();
		break;
	}

}

/*���� ����:
			������ �ʱ�ȭ                                                                                                                                                                        */
int main(int argc, char** argv) {
/*���:
		Window OS�� Session ����                                                                                                                                                                 */
	glutInit(&argc, argv);
/*���:
		Window�� ũ�� �μ�                                                                                                                                                                       */
	Width = 1000;
	Height = 1000;
/*���:
		Display Mode RGB, Single�� ����                                                                                                                                                          */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
/*���:
		Window�� ũ�� ����                                                                                                                                                                       */
	glutInitWindowSize(Width, Height);
/*���:
		Monitor���� Window�� ������ ��ġ                                                                                                                                                         */
	glutInitWindowPosition(0, 0);
/*���:
		���ο� Window Graphics ������ȯ ���� ����                                                                                                                                                */
	glutCreateWindow("���� ��ȯ ����");
	MyInit();
/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                        */
	glutDisplayFunc(MyDisplay);
/*���:
		�̺�Ʈ Ÿ�� RESHAPE callback �Լ�                                                                                                                                                        */
	glutReshapeFunc(MyReshape);
/*���:
		�̺�Ʈ Ÿ�� MySpecialKey callback �Լ�                                                                                                                                                   */
	glutSpecialFunc(MySpecialKey);
/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                */
	glutMainLoop();
	return 0;
}
/*************************************************************************************************************************************************************************************************/