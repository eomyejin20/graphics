/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-2. Keyboard Callback ����II                                                                                              */
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
			����� Ű���� �̺�Ʈ ���                                                                                                                                                             */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
/*���:
	   ���� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                        */
	case GLUT_KEY_LEFT:     
		trans_left = trans_left - 0.1;
/*���:
	   ������ ������ ����� �ʵ��� ����                                                                                                                                                         */
		if (trans_left < -0.5)  trans_left -= -0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		������ Ű �Է� �� ���������� 0.1�� �̵�                                                                                                                                                   */
	case GLUT_KEY_RIGHT: 
		trans_left = trans_left + 0.1;
/*���:
		������ ������ ����� �ʵ��� ����                                                                                                                                                        */
		if (trans_left > 0.5)  trans_left -= 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		�� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                         */
	case GLUT_KEY_UP:      
		trans_up = trans_up + 0.1;
/*���:
		������ ������ ����� �ʵ��� ����                                                                                                                                                        */
		if (trans_up > 0.5)  trans_up -= 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		�Ʒ� Ű �Է� �� �Ʒ������� 0.1�� �̵�                                                                                                                                                     */
	case GLUT_KEY_DOWN:      
		trans_up = trans_up - 0.1;
/*���:
		������ ������ ����� �ʵ��� ����                                                                                                                                                        */
		if (trans_up < -0.5)  trans_up -= -0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		Page Up Ű �Է� �� 0.1�� Ȯ��                                                                                                                                                             */
	case GLUT_KEY_PAGE_UP:
		
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
	   Page Down Ű �Է� �� 0.1�� ���                                                                                                                                                            */
	case GLUT_KEY_PAGE_DOWN:
		
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
	}

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
		���ο� Window Graphics Keyboard Callback ���� 2 ����                                                                                                                                      */
	glutCreateWindow("Keyboard Callback ���� 2");
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
		�̺�Ʈ Ÿ�� MySpecialKey callback �Լ�                                                                                                                                                    */
	glutSpecialFunc(MySpecialKey);

/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/
