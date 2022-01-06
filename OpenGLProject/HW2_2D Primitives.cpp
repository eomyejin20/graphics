/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#2-1. GL Modeling                                                                                                           */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 9월 30일                                                          */

#include <GL/glut.h>



/*문제 정의: 
            2D Primitive Points 구현하기                                                                                                                                                          */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
	/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 점                                                                                                                                                                              */
	glBegin(GL_POINTS);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();

}


/*문제 정의:
			2D Primitive Lines 구현하기                                                                                                                                                           */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
	/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 선                                                                                                                                                                              */
	glBegin(GL_LINES);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive LineStrip 구현하기                                                                                                                                                       */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
	/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 linestrip                                                                                                                                                                       */
	glBegin(GL_LINE_STRIP);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive LineLoop 구현하기                                                                                                                                                        */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 lineloop                                                                                                                                                                        */
	glBegin(GL_LINE_LOOP);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive Polygons 구현하기                                                                                                                                                        */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 다각형                                                                                                                                                                          */
	glBegin(GL_POLYGON);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive Triangles 구현하기                                                                                                                                                       */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 삼각형                                                                                                                                                                          */
	glBegin(GL_TRIANGLES);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(-0.5, 0.25, 0.0); glVertex3f(-0.5, 0.75, 0.0); glVertex3f(0.5, 0.75, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive TriangleStrip 구현하기                                                                                                                                                   */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 삼각형 strip                                                                                                                                                                    */
	glBegin(GL_TRIANGLE_STRIP);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(0.6, -0.1, 0.0); glVertex3f(0.5, 0.2, 0.0); glVertex3f(0.3, 0.0, 0.0); glVertex3f(0.15, 0.25, 0.0); glVertex3f(0.0, -0.05, 0.0); glVertex3f(-0.15, 0.15, 0.0); glVertex3f(-0.25, 0.0, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive TriangleFan 구현하기                                                                                                                                                     */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 삼각형 부채꼴                                                                                                                                                                   */
	glBegin(GL_TRIANGLE_FAN);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.65, 0.0, 0.0); glVertex3f(0.6, 0.2, 0.0); glVertex3f(0.35, 0.4, 0.0); glVertex3f(0.2, 0.45, 0.0); glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive Quads 구현하기                                                                                                                                                           */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 사각형                                                                                                                                                                          */
	glBegin(GL_QUADS);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(0.35, -0.3, 0.0); glVertex3f(0.4, -0.2, 0.0); glVertex3f(0.3, 0.005, 0.0); glVertex3f(0.005, -0.3, 0.0); glVertex3f(-0.2, 0.1, 0.0); glVertex3f(-0.1, 0.3, 0.0); glVertex3f(-0.35, 0.3, 0.0); glVertex3f(-0.4, 0.2, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
			2D Primitive QuadStrip 구현하기                                                                                                                                                       */
void MyDisplay() {
/*기능:
		   색 버퍼 제거                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
			   그려지는 도형의 색은 파란색                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*기능:
		   type은 사각형 strip                                                                                                                                                                    */
	glBegin(GL_QUAD_STRIP);
	/*기능:
			   찍힐 위치에 점 찍기                                                                                                                                                                */
	glVertex3f(0.35, -0.3, 0.0); glVertex3f(0.4, -0.2, 0.0); glVertex3f(0.005, -0.3, 0.0); glVertex3f(0.3, 0.005, 0.0); glVertex3f(-0.2, 0.1, 0.0); glVertex3f(-0.1, 0.3, 0.0); glVertex3f(-0.4, 0.2, 0.0); glVertex3f(-0.35, 0.3, 0.0);
	glEnd();
	/*기능:
		   명령 실행                                                                                                                                                                              */
	glFlush();


}

/*문제 정의:
            윈도우 초기화                                                                                                                                                                         */
int main(int argc, char** argv) { 
	/*기능:
	       Window OS와 Session 연결                                                                                                                                                               */
	glutInit(&argc, argv); 
	/*기능:
	       Display Mode RGB로 설정                                                                                                                                                                */
	glutInitDisplayMode(GLUT_RGB);
	/*기능:
	       Window의 크기 설정                                                                                                                                                                     */
	glutInitWindowSize(500, 500); 
	/*기능:
	         Monitor에서 Window의 시작점 위치                                                                                                                                                     */
	glutInitWindowPosition(-30, 0); 
	/*기능:
	        새로운 Window 3D Tetrahedron Gasket 생성                                                                                                                                              */
	glutCreateWindow("GL Modeling"); 
	/*기능:
		   창 배경 흰색                                                                                                                                                                           */
	glClearColor(1.0, 1.0, 1.0, 1.0);
	/*기능:
	        이벤트 타입 DISPLAY callback 함수                                                                                                                                                     */
	glutDisplayFunc(MyDisplay); 
	/*기능:
	        GLUT Event 처리 Loop 입력                                                                                                                                                             */
	glutMainLoop(); 

	return 0;
}
/**************************************************************************************************************************************************************************************************/