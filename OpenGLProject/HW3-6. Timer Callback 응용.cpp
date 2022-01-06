/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-6. Timer Callback ����                                                                                                   */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 10�� 8��                                                          */

#include <GL/glut.h>
/*���:
	   ������Ʈ �̵��� ���� ���� (�¿�/���Ʒ�), Polygon �� ����                                                                                                                                   */
double trans_left = 0, trans_up = 0;
GLfloat rc, gc, bc;

void MyDisplay() {
/*���:
		�� ���� ����                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
		�׷����� ������ ���� ȸ��                                                                                                                                                                 */
	glColor3f(0.5, 0.5, 0.5);
/*���:
		�׷����� ������ �� ����                                                                                                                                                                   */
	glColor3f(rc, gc, bc);
/*���:
	   type�� �ٰ���                                                                                                                                                                              */
	glBegin(GL_POLYGON);
/*���:
		���� ��ġ�� �� ���                                                                                                                                                                       */
	glVertex3f(-0.5 + trans_left, -0.5 + trans_up, 0.0);
	glVertex3f(0.5 + trans_left, -0.5 + trans_up, 0.0);
	glVertex3f(0.5 + trans_left, 0.5 + trans_up, 0.0);
	glVertex3f(-0.5 + trans_left, 0.5 + trans_up, 0.0);
	
	glEnd();
/*���:
		��� ����                                                                                                                                                                                 */
	glutSwapBuffers();
}

void MyIdle1() {
/*���:
		�������� 0.1�� �̵�                                                                                                                                                                       */
	trans_left = trans_left - 0.001;
/*���:
		���������� ����                                                                                                                                                                           */
	rc = 1.0; gc = 0.0; bc = 0.0;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}

void MyIdle2() {
/*���:
		���������� 0.1�� �̵�                                                                                                                                                                     */
	trans_left = trans_left + 0.001;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}
/*���� ����:
			���콺 �Լ� ���                                                                                                                                                                      */
void MyMouseClick(GLint Button, GLint state, GLint x, GLint y) {
	switch (Button) {
/*���:
	   ���콺 ���� ��ư ������ ���߱�                                                                                                                                                             */
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
	}
	glutPostRedisplay();
}

/*���� ����:
			Ÿ�̸� ���                                                                                                                                                                           */
void MyTimer(int Value) {
/*���:
		�̺�Ʈ Ÿ�� MyIdle2 callback �Լ�                                                                                                                                                         */
	glutIdleFunc(MyIdle2);
	if (trans_left > 0.5) {
/*���:
		�̺�Ʈ Ÿ�� MyIdle1 callback �Լ�                                                                                                                                                         */
		glutIdleFunc(MyIdle1);
	}
/*���:
			���콺 �Լ� ���                                                                                                                                                                      */
	glutMouseFunc(MyMouseClick);
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
	
}



/*���� ����:
			������ �ʱ�ȭ                                                                                                                                                                         */
int main(int argc, char** argv) {
/*���:
		Window OS�� Session ����                                                                                                                                                                  */
	glutInit(&argc, argv);
/*���:
		Display Mode RGB, Double�� ����                                                                                                                                                           */
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
/*���:
		Window�� ũ�� ����                                                                                                                                                                        */
	glutInitWindowSize(300, 300);
/*���:
		Monitor���� Window�� ������ ��ġ                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
/*���:
		���ο� Window Graphics Timer Callback ���� ����                                                                                                                                           */
	glutCreateWindow("Timer Callback ����");
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
	   ��ĺ�ȯ                                                                                                                                                                                   */
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*���:
		�̺�Ʈ Ÿ�� MyKeyboard callback �Լ�                                                                                                                                                      */
	glutTimerFunc(40, MyTimer, 1);
	
/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/