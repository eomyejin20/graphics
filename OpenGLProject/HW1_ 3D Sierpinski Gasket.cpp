/***********************************************************************************************************************************************************************************************/
/*                                                                  HW#1 : 3D Sierpinski Gasket                                                                                                */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 9월 23일                                                       */


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

/*문제 정의:
             삼각형 그리기                                                                                                                                                                      */
struct Point {
	/*기능:
	       3D로 구현하는 것이 목표이므로 배열인덱스 대신 x좌표, y좌표뿐만 아니라 z좌표까지 포함하여 3차원 공간의 점으로 기술                                                                    */
	GLfloat x, y, z; 
	/*기능: 
	       3D 좌표: (x,y,z)                                                                                                                                                                     */
	Point(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {} 
	/*기능:
	       임의의 점 p를 선택하여 선택된 점과 현재 점을 기준으로 계산한 중점의 위치 x, y, z의 값                                                                                                */
	Point midpoint(Point p) { return Point((x + p.x) / 2, (y + p.y) / 2, (z + p.z) / 2); }
};

/*문제 정의: 
            투영변환, 뷰폿변환                                                                                                                                                                   */
void reshape(GLint w, GLint h) {
	/*기능:
	       전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 w*h 영역에 출력                                                                                              */
	glViewport(0, 0, w, h); 
	/*기능:
	       투영행렬 선택                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION); 
	/*기능:
	       현재 투영행렬을 항등행렬로 초기화                                                                                                                                                     */
	glLoadIdentity(); 
	/*기능:
	       피라미드가 왜곡되지 않도록 원근 보기 볼륨을 설정하여 피라미드의 수직범위를 볼 수 있도록 설정                                                                                          */
	gluPerspective(100.0, GLfloat(w) / GLfloat(h), 10.0, 1500.0); 
}


void display() { 
	/*기능: 
	       창 배경 흰색                                                                                                                                                                          */
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	/*기능:
	       색 버퍼와 깊이 버퍼 제거해 viewport 지우기                                                                                                                                            */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
}

/*문제 정의:
            함수는 정점 및 현재의 점을 정적 개체로 로컬에 포함하여 호출할 때 해당 값이 유지                                                                                                      */
void generateMorePoints() { 

	/*문제 정의: 
	            4면체에서 4개의 꼭짓점 설정                                                                                                                                                      */
	static Point vertices[4] = { 
	  Point(-250, -225, -200),
	  Point(-250, -555, -700),
	  Point(470, -225, -400),
	  Point(0, 450, -500)
	};
	static Point lastPoint = vertices[0];

	/*기능:
	       type은 점                                                                                                                                                                              */
	glBegin(GL_POINTS); 
	/*기능:
	       1000번 반복                                                                                                                                                                            */
	for (int i = 0; i <= 1000; i++) { 
		/*기능: 
		       4면체 내부에 random하게 임의의 점 선택                                                                                                                                             */
		lastPoint = lastPoint.midpoint(vertices[rand() % 4]);
		/*기능:
		       4면체의 z좌표 범위가 -200에서 -700까지 이어지기 때문에 z값에 700을 더하고 500으로 나누면 0에서 1까지의 범위의 값을 얻음                                                            */
		GLfloat intensity = (700 + lastPoint.z) / 500.0; 
		/*기능:
		       그려지는 도형의 색은 빨간색                                                                                                                                                        */
		glColor3f(1.0, 0.0, 0.0); 
		/*기능:
		       찍힐 위치에 점 찍기                                                                                                                                                                */
		glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z); 
	}
	glEnd();
	/*기능:
	       명령 실행                                                                                                                                                                              */
	glFlush(); 
}

/*문제 정의: 
            초기화                                                                                                                                                                                */
void init() {
	/*기능:
	        Depth 버퍼링 수행                                                                                                                                                                     */
	glEnable(GL_DEPTH_TEST); 
}

/*문제 정의:
            윈도우 초기화                                                                                                                                                                         */
int main(int argc, char** argv) { 
	/*기능:
	       Window OS와 Session 연결                                                                                                                                                               */
	glutInit(&argc, argv); 
	/*기능:
	       Display Mode Single, RGB, Depth로 설정                                                                                                                                                 */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	/*기능:
	       Window의 크기 설정                                                                                                                                                                     */
	glutInitWindowSize(500, 500); 
	/*기능:
	         Monitor에서 Window의 시작점 위치                                                                                                                                                     */
	glutInitWindowPosition(150, 50); 
	/*기능:
	        새로운 Window 3D Tetrahedron Gasket 생성                                                                                                                                              */
	glutCreateWindow("3D Sierpinski Gasket"); 
	/*기능:
	        이벤트 타입 DISPLAY callback 함수                                                                                                                                                     */
	glutDisplayFunc(display); 
	/*기능:
	       이벤트 타입 RESHAPE callback 함수                                                                                                                                                      */
	glutReshapeFunc(reshape); 
	/*기능:
	        이벤트 타입 IDLE callback 함수                                                                                                                                                        */
	glutIdleFunc(generateMorePoints); 
	init();
	/*기능:
	        GLUT Event 처리 Loop 입력                                                                                                                                                             */
	glutMainLoop(); 
}
/**************************************************************************************************************************************************************************************************/