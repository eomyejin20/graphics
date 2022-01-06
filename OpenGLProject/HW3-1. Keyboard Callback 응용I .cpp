/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-1. Keyboard Callback ����I                                                                                               */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 10�� 8��                                                          */

#include <gl/glut.h>
#include <stdio.h>

/*���:
	   ������Ʈ �̵��� ���� ���� (�¿�/���Ʒ�), Polygon �� ����                                                                                                                                   */
double trans_left = 0, trans_up = 0;
GLfloat rc, gc, bc;

void MyDisplay() {
/*���:
	   �� ���� ����                                                                                                                                                                               */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
		�׷����� ������ ���� ȸ��                                                                                                                                                                 */
	glColor3f(0.5, 0.5, 0.5);
/*���:
		�׷����� ������ �� ����                                                                                                                                                                   */
	glColor3f(rc, gc, bc);
/*���:
		   type�� �ٰ���                                                                                                                                                                          */
	glBegin(GL_POLYGON);
/*���:
	   ���� ��ġ�� �� ���                                                                                                                                                                        */
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
            Ű���� �Լ� ���                                                                                                                                                     */
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed)
/*���:
		a �Է� �� �������� 0.1�� �̵�                                                                                                                                                             */
	if (KeyPressed == 'a') {
		trans_left = trans_left - 0.1;
	}
/*���:
		f �Է� �� ���������� 0.1�� �̵�                                                                                                                                                           */
	if (KeyPressed == 'f') {
		trans_left = trans_left + 0.1;
	}
/*���:
		v �Է� �� �������� 0.1�� �̵�                                                                                                                                                             */
	if (KeyPressed == 'v') {
		trans_up = trans_up + 0.1;
	}
/*���:
		r �Է� �� �Ʒ������� 0.1�� �̵�                                                                                                                                                           */
	if (KeyPressed == 'r') {
		trans_up = trans_up - 0.1;
		rc = 1.0; gc = 0.0; bc = 0.0;
	}
/*���:
		b �Է� �� �Ķ������� ����                                                                                                                                                                 */
	if (KeyPressed == 'b') {
		rc = 0.0; gc = 0.0; bc = 1.0;
	}
/*���:
		A �Է� �� �������� 0.1�� �̵�                                                                                                                                                             */
	if (KeyPressed == 'A') {
		trans_left = trans_left - 0.1;
	}
/*���:
		F �Է� �� ���������� 0.1�� �̵�                                                                                                                                                           */
	if (KeyPressed == 'F') {
		trans_left = trans_left + 0.1;
	}
/*���:
		V �Է� �� �������� 0.1�� �̵�                                                                                                                                                             */
	if (KeyPressed == 'V') {
		trans_up = trans_up + 0.1;
	}
/*���:
	   R �Է� �� �Ʒ������� 0.1�� �̵�                                                                                                                                                            */
	if (KeyPressed == 'R') {
		trans_up = trans_up - 0.1;
		rc = 1.0; gc = 0.0; bc = 0.0;
	}
/*���:
		B �Է� �� �Ķ������� ����                                                                                                                                                                 */
	if (KeyPressed == 'B') {
		rc = 0.0; gc = 0.0; bc = 1.0;
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
		���ο� Window Graphics Keyboard Callback ���� 1 ����                                                                                                                                      */
	glutCreateWindow("Keyboard Callback ���� 1");
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
		�̺�Ʈ Ÿ�� MyKeyboard callback �Լ�                                                                                                                                                      */
	glutKeyboardFunc(MyKeyboard);
	
/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/
