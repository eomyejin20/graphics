/**************************************************************************************************************************************************************************************************/
/*                                                                 HW#3-4. Menu Callback 응용                                                                                                     */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 10월 8일                                                          */

#include <GL/glut.h>
/*기능:
		ture, false 값을 전역변수로 지정                                                                                                                                                          */
GLboolean IsSmall2 = true;
GLboolean IsSmall3 = true;
GLboolean IsSmall1 = true;
GLboolean Red = true;


void MyDisplay() {
/*기능:
		색 버퍼 제거                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
		그려지는 도형의 색은 회색                                                                                                                                                                 */
	glColor3f(0.0, 0.5, 0.5);
/*기능:
		작고 빨간색일 때 빨갛고 작은 구 구현                                                                                                                                                                 */
	if ((IsSmall1) && (Red)) 
		glutWireSphere(0.3, 30, 30);
/*기능:
		작지 않고 빨간색일 때 빨갛고 큰 구 구현                                                                                                                                                                */
	else if ((!IsSmall1) && (Red)) 
		glutWireSphere(0.7, 30, 30);
/*기능:
		작고 빨간색일 때 초록색 작은 구 구현                                                                                                                                                                */
	else if ((IsSmall1) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.3, 30, 30);
	}
/*기능:
		작지 않고 빨간색이 아닐 때 초록색 큰 구 구현                                                                                                                                                                */
	else if ((!IsSmall1) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.7, 30, 30);
	}
/*기능:
		작고 빨간색일 때 빨갛고 작은 원환체 구현                                                                                                                                                                 */
	  if ((IsSmall2) && (Red))
		glutWireTorus(0.1, 0.3, 40, 20);
/*기능:
		작지 않고 빨간색일 때 빨갛고 큰 원환체 구현                                                                                                                                                                 */
	else if ((!IsSmall2) && (Red))
		glutWireTorus(0.3, 0.7, 40, 20);
/*기능:
		작고 빨간색이 아닐 때 초록색 작은 원환체 구현                                                                                                                                                                 */
	else if ((IsSmall2) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTorus(0.1, 0.3, 40, 20);
	}
/*기능:
		작지 않고 빨간색이 아닐 때 초록색 큰 원환체 구현                                                                                                                                                                 */
	else if ((!IsSmall2) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTorus(0.3, 0.7, 40, 20);
	}
/*기능:
		작고 빨간색일 때 빨갛고 작은 주전자 구현                                                                                                                                                                 */
	 if ((IsSmall3) && (Red))
		glutWireTeapot(0.3);
/*기능:
		작지 않고 빨간색일 때 빨갛고 큰 주전자 구현                                                                                                                                                                 */
	else if ((!IsSmall3) && (Red))
		glutWireTeapot(0.7);
/*기능:
		작고 빨간색이 아닐 때 초록색 작은 주전자 구현                                                                                                                                                                 */
	else if ((IsSmall3) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTeapot(0.3);
	}
/*기능:
		작지 않고 빨간색이 아닐 때 초록색 큰 주전자 구현                                                                                                                                                                 */
	else if ((!IsSmall3) && (!Red)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireTeapot(0.7);
	}
/*기능:
		빨간색일 때 도형의 색을 빨간색으로 지정                                                                                                                                                                */
	else if ((Red))
		 glColor3f(1.0, 0.0, 0.0);
/*기능:
		빨간색이 아닐 때 도형의 색을 초록색으로 지정                                                                                                                                                                 */
	else if ((!Red))
		 glColor3f(0.0, 1.0, 0.0);
/*기능:
		어느것도 아닐 때 도형의 색을 파란색으로 지정                                                                                                                                                                 */
	else 
		 glColor3f(0.0, 0.0, 1.0);
	
		glFlush();
}


/*문제 정의:
			메인메뉴 함수 등록                                                                                                                                                                    */
void MyMainMenu(int entryID) {
/*기능:
		프로그램 종료                                                                                                                                                                             */
	if (entryID == 1)
		exit(0);
	glutPostRedisplay(); 
}

/*문제 정의:
			서브메뉴 Sphere 함수 등록                                                                                                                                                             */
void MySubMenu_Sphere_size(int entryID) {
/*기능:
		작은 크기로 그리기                                                                                                                                                                        */
	if (entryID == 2 )
		IsSmall1 = true; 
/*기능:
		큰 크기로 그리기                                                                                                                                                                          */
	else if (entryID == 3)
		IsSmall1 = false; 
	glutPostRedisplay();
}

/*문제 정의:
			서브메뉴 Torus함수 등록                                                                                                                                                               */
void MySubMenu_Torus_size(int entryID) {
/*기능:
		작은 크기로 그리기                                                                                                                                                                        */
	if (entryID == 4)
		IsSmall2 = true; 
/*기능:
		큰 크기로 그리기                                                                                                                                                                          */
	else if (entryID == 5)
		IsSmall2 = false; 
	glutPostRedisplay();
}

/*문제 정의:
			서브메뉴 Teapot 함수 등록                                                                                                                                                             */
void MySubMenu_Teapot_size(int entryID) {
/*기능:
		작은 크기로 그리기                                                                                                                                                                        */
	if (entryID == 6)
		IsSmall3 = true;
/*기능:
		큰 크기로 그리기                                                                                                                                                                          */
	else if (entryID ==7)
		IsSmall3 = false; 
	glutPostRedisplay();
}

/*문제 정의:
			서브메뉴 색 바꾸는 함수 등록                                                                                                                                                          */
void MySubMenu_Change_Color(int entryID) {
/*기능:
		빨간색으로 그리기                                                                                                                                                                         */
	if (entryID == 8)
		Red = true; 
/*기능:
		초록색으로 그리기                                                                                                                                                                         */
	else if (entryID == 9)
		Red = false; 
	glutPostRedisplay();
}

	

/*문제 정의:
			윈도우 초기화                                                                                                                                                                         */
int main(int argc, char** argv) {
/*기능:
		Window OS와 Session 연결                                                                                                                                                                  */
	glutInit(&argc, argv);
/*기능:
		Display Mode RGB로 설정                                                                                                                                                                   */
	glutInitDisplayMode(GLUT_RGB);
/*기능:
		Window의 크기 설정                                                                                                                                                                        */
	glutInitWindowSize(300, 300);
/*기능:
		Monitor에서 Window의 시작점 위치                                                                                                                                                          */
	glutInitWindowPosition(0, 0);
/*기능:
		새로운 Window Graphics Menu Callback 응용 생성                                                                                                                                            */
	glutCreateWindow("Menu Callback 응용");
/*기능:
		창 배경 흰색                                                                                                                                                                              */
	glClearColor(1.0, 1.0, 1.0, 1.0);
/*기능:
		투영행렬 선택                                                                                                                                                                             */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                      */
	glLoadIdentity();
/*기능:
		행렬변환                                                                                                                                                                                  */
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

/*기능:
		Sphere_size 서브 메뉴의 콜백 함수 등록                                                                                                                                                    */
	GLint MySubMenuID_Sphere_size = glutCreateMenu(MySubMenu_Sphere_size);
	glutAddMenuEntry("Small Sphere", 2);
	glutAddMenuEntry("Large Sphere", 3);

/*기능:
		Torus_size 서브 메뉴의 콜백 함수 등록                                                                                                                                                     */
	GLint MySubMenuID_Torus_size = glutCreateMenu(MySubMenu_Torus_size);
	glutAddMenuEntry("Small Torus", 4);
	glutAddMenuEntry("Large Torus", 5);

/*기능:
		Teapot_size 서브 메뉴의 콜백 함수 등록                                                                                                                                                    */
    GLint MySubMenuID_Teapot_size = glutCreateMenu(MySubMenu_Teapot_size);
	glutAddMenuEntry("Small Teapot", 6);
	glutAddMenuEntry("Large Teapot", 7);

/*기능:
		Change_Color 서브 메뉴의 콜백 함수 등록                                                                                                                                                   */
	GLint MySubMenuID_Change_Color = glutCreateMenu(MySubMenu_Change_Color);
	glutAddMenuEntry("Red", 8);
	glutAddMenuEntry("Green", 9);
	glutAddMenuEntry("Blue", 10);
/*기능:
	    메인 메뉴에 메뉴 항목 첨가                                                                                                                                                                */
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySubMenuID_Sphere_size);
	glutAddSubMenu("Draw Torus", MySubMenuID_Torus_size);
	glutAddSubMenu("Draw Teapot", MySubMenuID_Teapot_size);
	glutAddSubMenu("Change Color", MySubMenuID_Change_Color);
/*기능:
		마우스 오른쪽 버튼을 누르면 현 메뉴 팝업                                                                                                                                                               */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
/*기능:
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*기능:
		GLUT Event 처리 Loop 입력                                                                                                                                                                 */
	glutMainLoop();
	return 0;
}
/**************************************************************************************************************************************************************************************************/