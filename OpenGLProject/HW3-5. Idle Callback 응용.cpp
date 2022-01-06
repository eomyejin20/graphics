/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-5. Idle Callback ����                                                                                                    */
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
	   ��� ����                                                                                                                                                                                  */
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
			Idle1 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle1() {
/*���:
	   ���� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                        */
	trans_left = trans_left - 0.001;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}
/*���� ����:
			Idle2 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle2() {
/*���:
	   ���� Ű �Է� �� ���������� 0.1�� �̵�                                                                                                                                                      */
	trans_left = trans_left + 0.001;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	
}
/*���� ����:
			Idle3 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle3() {
/*���:
	   ���� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                        */
	trans_up= trans_up + 0.001;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}
/*���� ����:
			Idle4 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle4() {
/*���:
	   ���� Ű �Է� �� �������� 0.1�� �̵�                                                                                                                                                        */
	trans_up = trans_up - 0.001;
/*���:
	   ������ �ٽ� �׸����� ��û                                                                                                                                                                  */
	glutPostRedisplay();
}
/*���� ����:
			����� Ű���� �̺�Ʈ ó�� Call Back �Լ�                                                                                                                                              */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
/*���:
		�̺�Ʈ Ÿ�� MyIdle1 callback �Լ�                                                                                                                                                         */
	case GLUT_KEY_LEFT:
		glutIdleFunc(MyIdle1);
/*���:
		������ ������ ����� �ʵ��� ����                                                                                                                                                        */
		if (trans_left < -0.5)  trans_left -= -0.1;
/*���:
	   ������ �ٽ� �׸����� ��û                                                                                                                                                                  */
		glutPostRedisplay();
		break;
/*���:
		�̺�Ʈ Ÿ�� MyIdle2 callback �Լ�                                                                                                                                                         */
	case GLUT_KEY_RIGHT:
		glutIdleFunc(MyIdle2);
/*���:
		������ ������ ����� �ʵ��� ����                                                                                                                                                        */
		if (trans_left > 0.5)  trans_left -= 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		�̺�Ʈ Ÿ�� MyIdle3 callback �Լ�                                                                                                                                                         */
	case GLUT_KEY_UP:
		glutIdleFunc(MyIdle3);
/*���:
		������ ������ ����� �ʵ��� ����                                                                                                                                                        */
		if (trans_up > 0.5)  trans_up -= 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
	   �̺�Ʈ Ÿ�� MyIdle4 callback �Լ�                                                                                                                                                                                                                                                                                                        */
	case GLUT_KEY_DOWN:
		glutIdleFunc(MyIdle4);
/*���:
	   ������ ������ ����� �ʵ��� ����                                                                                                                                                         */
		if (trans_up < -0.5)  trans_up -= -0.5;
/*���:
       ������ �ٽ� �׸����� ��û                                                                                                                                                                  */
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
		���ο� Window Graphics Idle Callback ���� ����                                                                                                                                            */
	glutCreateWindow("Idle Callback ����");
/*���:
	   â ��� ���                                                                                                                                                                               */
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