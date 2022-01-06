#include <GL/glut.h>
#include  <iostream>

GLboolean IsSmall = true;
GLboolean IsLarge = true;

void MyDisplay() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
if ((IsSmall) && (IsLarge))
glutWireSphere(0.2, 15, 15); // ���� ����
else if ((IsSmall) && (!IsLarge))
glutWireSphere(0.5, 15, 15); // ū ����
else if ((!IsSmall)&&(IsLarge))
glutWireTorus(0.1, 0.3, 40, 20); // ���� ��ȯü
else glutWireTorus(0.2, 0.5, 40, 20); // ū ��ȯü
glFlush();
}

void MyMainMenu (int entryID) {
if (entryID == 1)
exit(0);
glutPostRedisplay(); // ���α׷� ����
}

void MySubMenu_Sphere (int entryID) {
if (entryID == 1)
IsSmall = true; // ���� �׸���
else if (entryID == 2)
IsSmall = false; // ��ȯü �׸���
glutPostRedisplay();
}

void MySubMenu_Torus (int entryID) {
if (entryID == 1)
IsLarge = true; // ���� ũ��� �׸���
else if (entryID == 2)
IsLarge = false; // ū ũ��� �׸���
glutPostRedisplay();
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowSize(300, 300);
glutInitWindowPosition(0, 0);
glutCreateWindow("Menu Callback");

glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

//Change Shape ���� �޴��� �ݹ� �Լ� ���
GLint MySubMenuID_Sphere = glutCreateMenu(MySubMenu_Sphere);
glutAddMenuEntry("Small Sphere", 1);
glutAddMenuEntry("Large Sphere", 2);

//Change Size ���� �޴��� �ݹ� �Լ� ���
GLint MySubMenuID_Torus = glutCreateMenu(MySubMenu_Torus);
glutAddMenuEntry("Small Torus", 1);
glutAddMenuEntry("Large Torus", 2);

GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
glutAddSubMenu("Sphere", MySubMenuID_Sphere);
glutAddSubMenu("Torus", MySubMenuID_Torus);
glutAddMenuEntry("Teapot", 1);

glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(MyDisplay);
glutMainLoop();

return 0;
}