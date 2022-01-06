#include <GL/glut.h>
#include  <iostream>

GLboolean IsSmall = true;
GLboolean IsLarge = true;

void MyDisplay() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
if ((IsSmall) && (IsLarge))
glutWireSphere(0.2, 15, 15); // 작은 원구
else if ((IsSmall) && (!IsLarge))
glutWireSphere(0.5, 15, 15); // 큰 원구
else if ((!IsSmall)&&(IsLarge))
glutWireTorus(0.1, 0.3, 40, 20); // 작은 원환체
else glutWireTorus(0.2, 0.5, 40, 20); // 큰 원환체
glFlush();
}

void MyMainMenu (int entryID) {
if (entryID == 1)
exit(0);
glutPostRedisplay(); // 프로그램 종료
}

void MySubMenu_Sphere (int entryID) {
if (entryID == 1)
IsSmall = true; // 원구 그리기
else if (entryID == 2)
IsSmall = false; // 원환체 그리기
glutPostRedisplay();
}

void MySubMenu_Torus (int entryID) {
if (entryID == 1)
IsLarge = true; // 작은 크기로 그리기
else if (entryID == 2)
IsLarge = false; // 큰 크기로 그리기
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

//Change Shape 서브 메뉴의 콜백 함수 등록
GLint MySubMenuID_Sphere = glutCreateMenu(MySubMenu_Sphere);
glutAddMenuEntry("Small Sphere", 1);
glutAddMenuEntry("Large Sphere", 2);

//Change Size 서브 메뉴의 콜백 함수 등록
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