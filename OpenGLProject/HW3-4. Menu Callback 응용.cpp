/**************************************************************************************************************************************************************************************************/
/*                                                                 HW#3-4. Menu Callback ����                                                                                                     */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 10�� 8��                                                          */

#include <GL/glut.h>
/*���:
		ture, false ���� ���������� ����                                                                                                                                                          */
GLboolean IsSmall2 = true;
GLboolean IsSmall3 = true;
GLboolean IsSmall1 = true;
GLboolean Red = true;


void MyDisplay() {
/*���:
		�� ���� ����                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
		�׷����� ������ ���� ȸ��                                                                                                                                                                 */
	glColor3f(0.0, 0.5, 0.5);
/*���:
		�۰� �������� �� ������ ���� �� ����                                                                                                                                                                 */
	if ((IsSmall1) && (Red)) 
		glutWireSphere(0.3, 30, 30);
/*���:
		���� �ʰ� �������� �� ������ ū �� ����                                                                                                                                                                */
	else if ((!IsSmall1) && (Red)) 
		glutWireSphere(0.7, 30, 30);
/*���:
		�۰� �������� �� �ʷϻ� ���� �� ����                                                                                                                                                                */
	else if ((IsSmall1) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.3, 30, 30);
	}
/*���:
		���� �ʰ� �������� �ƴ� �� �ʷϻ� ū �� ����                                                                                                                                                                */
	else if ((!IsSmall1) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.7, 30, 30);
	}
/*���:
		�۰� �������� �� ������ ���� ��ȯü ����                                                                                                                                                                 */
	  if ((IsSmall2) && (Red))
		glutWireTorus(0.1, 0.3, 40, 20);
/*���:
		���� �ʰ� �������� �� ������ ū ��ȯü ����                                                                                                                                                                 */
	else if ((!IsSmall2) && (Red))
		glutWireTorus(0.3, 0.7, 40, 20);
/*���:
		�۰� �������� �ƴ� �� �ʷϻ� ���� ��ȯü ����                                                                                                                                                                 */
	else if ((IsSmall2) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTorus(0.1, 0.3, 40, 20);
	}
/*���:
		���� �ʰ� �������� �ƴ� �� �ʷϻ� ū ��ȯü ����                                                                                                                                                                 */
	else if ((!IsSmall2) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTorus(0.3, 0.7, 40, 20);
	}
/*���:
		�۰� �������� �� ������ ���� ������ ����                                                                                                                                                                 */
	 if ((IsSmall3) && (Red))
		glutWireTeapot(0.3);
/*���:
		���� �ʰ� �������� �� ������ ū ������ ����                                                                                                                                                                 */
	else if ((!IsSmall3) && (Red))
		glutWireTeapot(0.7);
/*���:
		�۰� �������� �ƴ� �� �ʷϻ� ���� ������ ����                                                                                                                                                                 */
	else if ((IsSmall3) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTeapot(0.3);
	}
/*���:
		���� �ʰ� �������� �ƴ� �� �ʷϻ� ū ������ ����                                                                                                                                                                 */
	else if ((!IsSmall3) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTeapot(0.7);
	}
/*���:
		�������� �� ������ ���� ���������� ����                                                                                                                                                                */
	else if ((Red))
		 glColor3f(1.0, 0.0, 0.0);
/*���:
		�������� �ƴ� �� ������ ���� �ʷϻ����� ����                                                                                                                                                                 */
	else if ((!Red))
		 glColor3f(0.0, 1.0, 0.0);
/*���:
		����͵� �ƴ� �� ������ ���� �Ķ������� ����                                                                                                                                                                 */
	else 
		 glColor3f(0.0, 0.0, 1.0);
	
		glFlush();
}


/*���� ����:
			���θ޴� �Լ� ���                                                                                                                                                                    */
void MyMainMenu(int entryID) {
/*���:
		���α׷� ����                                                                                                                                                                             */
	if (entryID == 1)
		exit(0);
	glutPostRedisplay(); 
}

/*���� ����:
			����޴� Sphere �Լ� ���                                                                                                                                                             */
void MySubMenu_Sphere_size(int entryID) {
/*���:
		���� ũ��� �׸���                                                                                                                                                                        */
	if (entryID == 2 )
		IsSmall1 = true; 
/*���:
		ū ũ��� �׸���                                                                                                                                                                          */
	else if (entryID == 3)
		IsSmall1 = false; 
	glutPostRedisplay();
}

/*���� ����:
			����޴� Torus�Լ� ���                                                                                                                                                               */
void MySubMenu_Torus_size(int entryID) {
/*���:
		���� ũ��� �׸���                                                                                                                                                                        */
	if (entryID == 4)
		IsSmall2 = true; 
/*���:
		ū ũ��� �׸���                                                                                                                                                                          */
	else if (entryID == 5)
		IsSmall2 = false; 
	glutPostRedisplay();
}

/*���� ����:
			����޴� Teapot �Լ� ���                                                                                                                                                             */
void MySubMenu_Teapot_size(int entryID) {
/*���:
		���� ũ��� �׸���                                                                                                                                                                        */
	if (entryID == 6)
		IsSmall3 = true;
/*���:
		ū ũ��� �׸���                                                                                                                                                                          */
	else if (entryID ==7)
		IsSmall3 = false; 
	glutPostRedisplay();
}

/*���� ����:
			����޴� �� �ٲٴ� �Լ� ���                                                                                                                                                          */
void MySubMenu_Change_Color(int entryID) {
/*���:
		���������� �׸���                                                                                                                                                                         */
	if (entryID == 8)
		Red = true; 
/*���:
		�ʷϻ����� �׸���                                                                                                                                                                         */
	else if (entryID == 9)
		Red = false; 
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
		���ο� Window Graphics Menu Callback ���� ����                                                                                                                                            */
	glutCreateWindow("Menu Callback ����");
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
		Sphere_size ���� �޴��� �ݹ� �Լ� ���                                                                                                                                                    */
	GLint MySubMenuID_Sphere_size = glutCreateMenu(MySubMenu_Sphere_size);
	glutAddMenuEntry("Small Sphere", 2);
	glutAddMenuEntry("Large Sphere", 3);

/*���:
		Torus_size ���� �޴��� �ݹ� �Լ� ���                                                                                                                                                     */
	GLint MySubMenuID_Torus_size = glutCreateMenu(MySubMenu_Torus_size);
	glutAddMenuEntry("Small Torus", 4);
	glutAddMenuEntry("Large Torus", 5);

/*���:
		Teapot_size ���� �޴��� �ݹ� �Լ� ���                                                                                                                                                    */
    GLint MySubMenuID_Teapot_size = glutCreateMenu(MySubMenu_Teapot_size);
	glutAddMenuEntry("Small Teapot", 6);
	glutAddMenuEntry("Large Teapot", 7);

/*���:
		Change_Color ���� �޴��� �ݹ� �Լ� ���                                                                                                                                                   */
	GLint MySubMenuID_Change_Color = glutCreateMenu(MySubMenu_Change_Color);
	glutAddMenuEntry("Red", 8);
	glutAddMenuEntry("Green", 9);
	glutAddMenuEntry("Blue", 10);
/*���:
	    ���� �޴��� �޴� �׸� ÷��                                                                                                                                                                */
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySubMenuID_Sphere_size);
	glutAddSubMenu("Draw Torus", MySubMenuID_Torus_size);
	glutAddSubMenu("Draw Teapot", MySubMenuID_Teapot_size);
	glutAddSubMenu("Change Color", MySubMenuID_Change_Color);
/*���:
		���콺 ������ ��ư�� ������ �� �޴� �˾�                                                                                                                                                               */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
/*���:
		�̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*���:
		GLUT Event ó�� Loop �Է�                                                                                                                                                                 */
	glutMainLoop();
	return 0;
}
/**************************************************************************************************************************************************************************************************/