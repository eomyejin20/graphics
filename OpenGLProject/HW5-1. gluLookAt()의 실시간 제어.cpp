/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#5-2. �𵨺� ��ȯ ���� �ǽ�                                                                                                      */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 11�� 4��                                                          */


#include <GL/glut.h>

/*���:
	   ���� ��ǥ�� ������ ������ȯ �μ�                                                                                                                                                  */
float ex = 0.0;
float ey = 3.5;
float ez = 3.5;
float cx, cy, cz, ux = 0.0;
float uy = 1.0;
float uz = 0.0;

/*���� ����:
			�� �׸���                                                                                                                                                                   */
void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}

	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}

void MyDisplay() {
/*���:
		�� ���ۿ� ���� ���� ����                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*���:
		�𵨺� ��� ����                                                                                                                                                                      */
	glMatrixMode(GL_MODELVIEW);
/*���:
		���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                  */
	glLoadIdentity();

	DrawGround();
/*���:
		������ǥ�� ���� �Լ�                                                                                                                                                  */
	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
/*���:
		Ƽ���� �� ����                                                                                                                                                  */
	glColor3f(1.0, 1.0, 0.0);
/*���:
		Ƽ�� �׸���                                                                                                                                                  */
	glutWireTeapot(1.0);
	glFlush();
}

/*���� ����:
			������ȯ, ������ȯ                                                                                                                                                                   */
void MyReshape(int w, int h) {
/*���:
		��ü�� â���� �׸� �� �ֵ��� viewport�� pixel ��ǥ�� ��ġ�ϵ��� �������� (GLsizei)w*(GLsizei)h ������ ���                                                                            */
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
/*���:
		������� ����                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION);
/*���:
		���� ��������� �׵���ķ� �ʱ�ȭ                                                                                                                                                     */
	glLoadIdentity();
/*���:
		ť�� �� �������� ��Ʈ������ ����                                                                                                                                                     */
	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}

/*���� ����:
			Idle1 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle1() {
/*���:
		���� Ű �Է� �� camera X�� ��ǥ ���������� 0.1�� ����                                                                                                                                                        */
	ex = ex -0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}
/*���� ����:
			Idle2 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle2() {
/*���:
		������ Ű �Է� �� camera X�� ��ǥ ���������� 0.1�� ����                                                                                                                                                        */
	ex = ex + 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}
/*���� ����:
			Idle3 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle3() {
/*���:
		���� Ű �Է� �� camera Y�� ��ǥ ���������� 0.1�� ����                                                                                                                                                          */
	ey = ey + 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
	glutPostRedisplay();
}
/*���� ����:
			Idle4 �̺�Ʈ ���                                                                                                                                                                     */
void MyIdle4() {
/*���:
		�Ʒ��� Ű �Է� �� camera Y�� ��ǥ ���������� 0.1�� ����                                                                                                                                                           */
	ey = ey - 0.1;
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
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
		������ �ٽ� �׸����� ��û                                                                                                                                                                  */
		glutPostRedisplay();
		break;
/*���:
		�̺�Ʈ Ÿ�� MyIdle2 callback �Լ�                                                                                                                                                         */
	case GLUT_KEY_RIGHT:
		glutIdleFunc(MyIdle2);
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		�̺�Ʈ Ÿ�� MyIdle3 callback �Լ�                                                                                                                                                         */
	case GLUT_KEY_UP:
		glutIdleFunc(MyIdle3);
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*���:
		�̺�Ʈ Ÿ�� MyIdle4 callback �Լ�                                                                                                                                                                                                                                                                                                        */
	case GLUT_KEY_DOWN:
		glutIdleFunc(MyIdle4);
/*���:
		������ �ٽ� �׸����� ��û                                                                                                                                                                  */
		glutPostRedisplay();
		break;

	}
}
/*���� ����:
			Ű���� �Լ� ���                                                                                                                                                     */
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
/*���:
		27 �Է� �� ����                                                                                                                                                            */
	switch (KeyPressed)
		if (KeyPressed == '27') {
			exit(0);
			break;
	}
/*���:
		a �Է� �� ���� X�� ��ǥ 0.1�� ����                                                                                                                                                             */
	if (KeyPressed == 'a') {
			cx = cx + 0.1;
		}
/*���:
		f �Է� �� ���� X�� ��ǥ 0.1�� ����                                                                                                                                                           */
	if (KeyPressed == 'f') {
		cx = cx - 0.1;
	}
/*���:
		v �Է� �� ���� Y�� ��ǥ 0.1�� ����                                                                                                                                                             */
	if (KeyPressed == 'v') {
		cy = cy - 0.1;
	}
/*���:
		r �Է� �� ���� Y�� ��ǥ 0.1�� ����                                                                                                                                                           */
	if (KeyPressed == 'r') {
		cy = cy + 0.1;
		
	}
/*���:
		z �Է� �� ���� Z�� ��ǥ 0.1�� ����                                                                                                                                                                     */
	if (KeyPressed == 'z') {
		cz = cz + 0.1;
	}
/*���:
		t �Է� �� ���� Z�� ��ǥ 0.1�� ����                                                                                                                                                                   */
	if (KeyPressed == 't') {
		cz = cz - 0.1;
	}
/*���:
		A �Է� �� ���� X�� ��ǥ 0.1�� ����                                                                                                                                                              */
	if (KeyPressed == 'A') {
		cx = cx + 0.1;
	}
/*���:
		F �Է� �� ���� X�� ��ǥ 0.1�� ����                                                                                                                                                           */
	if (KeyPressed == 'F') {
		cx = cx - 0.1;
	}
/*���:
		V �Է� �� ���� Y�� ��ǥ 0.1�� ����                                                                                                                                                             */
	if (KeyPressed == 'V') {
		cy = cy - 0.1;
	}
/*���:
		R �Է� �� ���� Y�� ��ǥ 0.1�� ����                                                                                                                                                            */
	if (KeyPressed == 'R') {
		cy = cy + 0.1;
	}
/*���:
		Z �Է� �� ���� Z�� ��ǥ 0.1�� ����                                                                                                                                                                 */
	if (KeyPressed == 'Z') {
		cz = cz + 0.1;
	}
/*���:
		T �Է� �� ���� Z�� ��ǥ 0.1�� ����                                                                                                                                                                 */
	if (KeyPressed == 'T') {
		cz = cz - 0.1;
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
			Display Mode RGBA, SINGLE�� ����                                                                                                                                                                   */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	/*���:
			Window�� ũ�� ����                                                                                                                                                                        */
	glutInitWindowSize(500, 500);
	/*���:
			Monitor���� Window�� ������ ��ġ                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
	/*���:
			���ο� Window Graphics gluLookAt()�� �ǽð� ���� ����                                                                                                                                      */
	glutCreateWindow("VCS (View Coordinate System) ����");
	/*���:
			â ��� ������                                                                                                                                                                              */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*���:
			�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
	/*���:
			�̺�Ʈ Ÿ�� RESHAPE callback �Լ�                                                                                                                                                      */
	glutReshapeFunc(MyReshape);
	/*���:
			�̺�Ʈ Ÿ�� MySpecialKey callback �Լ�                                                                                                                                                    */
	glutSpecialFunc(MySpecialKey);
	/*���:
			�̺�Ʈ Ÿ�� MyKeyboard callback �Լ�                                                                                                                                                      */
	glutKeyboardFunc(MyKeyboard);
	/*���:
			GLUT Event ó�� Loop �Է�                                                                                                                                                                 */
	glutMainLoop();
	return 0;
}
/**************************************************************************************************************************************************************************************************/