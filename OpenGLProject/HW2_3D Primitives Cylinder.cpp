/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#2-2. GLU Modeling                                                                                                          */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 9�� 30��                                                          */

#include <stdlib.h>
#include <GL/glut.h>

/*���:
	   ���ο� Quadric ����                                                                                                                                                                        */
GLUquadricObj *qobj = gluNewQuadric();
/*���:
	   DisplayList�� ���� ID�� ���� �ĺ�                                                                                                                                                          */
int MyListID[4];

void MyInit(void) {

	/*���:
		   �ֺ���                                                                                                                                                                                 */
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	/*���:
		   �ݻ籤                                                                                                                                                                                 */
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	/*���:
		   ����                                                                                                                                                                                 */
	GLfloat mat_shininess[] = { 50.0 };
	/*���:
		   ���� ��ġ                                                                                                                                                                              */
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	/*���:
		   �׷����� �׸��� ��                                                                                                                                                                     */
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	/*���:
		   â ��� ������                                                                                                                                                                         */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*���:
		   ������ ����                                                                                                                                                                            */
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	/*���:
		   ������ ����                                                                                                                                                                            */
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	/*���:
		   ���� ���� ����                                                                                                                                                                       */
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

	/*���:
		   ���� ��带 Ȱ��ȭ                                                                                                                                                                     */
	glEnable(GL_LIGHTING);
	/*���:
		   0���� ���� Ȱ��ȭ                                                                                                                                                                      */
	glEnable(GL_LIGHT0);
	/*���:
		   ���� ���� Ȱ��ȭ                                                                                                                                                                       */
	glEnable(GL_DEPTH_TEST);
}

/*���� ����:
			Display List ����                                                                                                                                                                          */
void MyCreateList() {
	/*���:
		   ���ο� List ����                                                                                                                                                                       */
	MyListID[0] = glGenLists(4);
	/*���:
		   Display List�� �����ϱ� ���� �Լ��� ID��  �������� �Ϸ�� �������� ���� ����                                                                                                           */
	glNewList(MyListID[0], GL_COMPILE);

	/*���:
		   Quadric�� ���� ���ϴ� Draw Style ����                                                                                                                                                  */
	gluQuadricDrawStyle(qobj, GLU_FILL);
	/*���:
		   �������� ����                                                                                                                                                                          */
	gluQuadricNormals(qobj, GLU_SMOOTH);
	/*���:
		   �������� �ܺη� ���� ����                                                                                                                                                              */
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	/*���:
		   Texture ��ǥ ��� ����                                                                                                                                                                 */
	gluQuadricTexture(qobj, GL_FALSE);

	/*���:
		   Cylinder ����                                                                                                                                                                         */
	gluCylinder(qobj, 1.0, 0.5, 2.0, 20, 20);

	/*���:
		   Display List�� ���� ǥ���ϴ� �Լ�                                                                                                                                                     */
	glEndList();

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

	/*���:
		   �����带 Ȱ��ȭ                                                                                                                                                                     */
	glEnable(GL_LIGHTING);
	/*���:
		   �������� �����ذ��鼭 ä���                                                                                                                                                          */
	glShadeModel(GL_SMOOTH);

	/*���:
		   Display List�� �����ϱ� ���� �Լ�                                                                                                                                                     */
	glCallList(MyListID[0]);
	/*���:
		   ���� 2�� ���                                                                                                                                                                         */
	glutSwapBuffers();
}

/*���� ����:
			������ȯ, ������ȯ                                                                                                                                                                   */
void Reshape(int w, int h) {
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
		   ��ĺ�ȯ                                                                                                                                                                              */
	glOrtho(-2.5, 2.5, -2.5*(GLfloat)h / (GLfloat)w, 2.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	/*���:
		   �𵨺� ��� ����                                                                                                                                                                      */
	glMatrixMode(GL_MODELVIEW);
	/*���:
		   ���� �𵨺� ����� �׵���ķ� �ʱ�ȭ                                                                                                                                                   */
	glLoadIdentity();
}

/*���� ����:
			������ �ʱ�ȭ                                                                                                                                                                         */
int main(int argc, char** argv) {
	/*���:
		   Window OS�� Session ����                                                                                                                                                               */
	glutInit(&argc, argv);
	/*���:
		   Display Mode Double, RGB, Depth�� ����                                                                                                                                                 */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/*���:
		   Window�� ũ�� ����                                                                                                                                                                     */
	glutInitWindowSize(800, 600);
	/*���:
			 Monitor���� Window�� ������ ��ġ                                                                                                                                                     */
	glutInitWindowPosition(0, 0);
	/*���:
			���ο� Window Graphics Primitives Cylinder ����                                                                                                                                         */
	glutCreateWindow("Graphics Primitives Cylinder");
	/*���:
		   ������ ���� ���õ� �� �ʱ�ȭ                                                                                                                                                           */
	MyInit();
	/*���:
			�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                     */
	glutDisplayFunc(MyDisplay);
	/*���:
		   �̺�Ʈ Ÿ�� RESHAPE callback �Լ�                                                                                                                                                      */
	glutReshapeFunc(Reshape);
	/*���:
		   Display List ����                                                                                                                                                                      */
	MyCreateList();
	/*���:
			GLUT Event ó�� Loop �Է�                                                                                                                                                             */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/