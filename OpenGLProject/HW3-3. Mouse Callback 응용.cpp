/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-3. Mouse Callback ����                                                                                                   */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 10�� 8��                                                          */

#include <gl/glut.h>
#include <stdio.h>

/*���:
	   ������Ʈ �̵��� ���� ���� (�¿�/���Ʒ�)                                                                                                                                                    */
double trans_left = 0, trans_up = 0;

void MyDisplay() {
/*���:
		�� ���� ����                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
		�׷����� ������ ���� ȸ��                                                                                                                                                                 */
	glColor3f(0.5, 0.5, 0.5);
/*���:
		type�� �ٰ���                                                                                                                                                                             */
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
	glFlush();
}



/*���� ����:
			������ȯ, ������ȯ                                                                                                                                                                    */
void MyReshape(int NewWidth, int NewHeight) {
/*���:
		��ü�� â���� �׸� �� �ֵ��� viewport�� pixel ��ǥ�� ��ġ�ϵ��� �������� (NewWidth)*(NewHeight) ������ ���                                                                               */
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
/*���:
		�𵨺� ��� ����                                                                                                                                                                          */
	glMatrixMode(GL_PROJECTION);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                      */
	glLoadIdentity();
/*���:
		��ĺ�ȯ                                                                                                                                                                                  */
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 *HeightFactor, 1.0 * HeightFactor, -1.0, -1.0);
}

/*���� ����:
			Idle �̺�Ʈ ���                                                                                                                                                                      */
void MyIdle() {
	trans_left = trans_left + 0.00001;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}

/*���� ����:
			���콺 �Լ� ���                                                                                                                                                                      */
void MyMouseClick(GLint Button, GLint state, GLint x, GLint y) {
	switch (Button) {
/*���:
		���콺 ���� ��ư ������ Idle �̺�Ʈ ó�� Call Back                                                                                                                                        */
	case GLUT_LEFT_BUTTON:
			if (state==GLUT_DOWN)
				glutIdleFunc(MyIdle);
/*���:
	   ������ ������ ����� �ʵ��� ����                                                                                                                                                         */
			else if (trans_left < -0.5)  trans_left -= -0.1;
	}
/*���:
	   ���콺 ������ ��ư ������ ���߱�                                                                                                                                                           */
	switch (Button) {
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
	}
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}


/*���� ����:
			������ �ʱ�ȭ                                                                                                                                                                         */
int main(int argc, char** argv) {
/*���:
		Window OS�� Session ����                                                                                                                                                                  */
	glutInit(&argc, argv);
/*���:
		Display Mode RGB�� ����                                                                                                                                                                   */
	glutInitDisplayMode(GLUT_RGB);
/*���:
		Window�� ũ�� ����                                                                                                                                                                        */
	glutInitWindowSize(300, 300);
/*���:
		Monitor���� Window�� ������ ��ġ                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
/*���:
		���ο� Window Graphics Mouse Callback ���� ����                                                                                                                                           */
	glutCreateWindow("Mouse Callback ����");
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
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*���:
		�̺�Ʈ Ÿ�� MyMouseClick callback �Լ�                                                                                                                                                    */
	glutMouseFunc(MyMouseClick);

/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/