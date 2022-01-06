#include <GL/glut.h>

//삼각형그리기
void MyDisplay() {
	float verticies[3][2] = { {0.0,0.0}, {250.0,300.0}, {500.0,0.0} };//초기의 삼각형
	float p[2] = { 75.0, 50.0 }; //삼각형 내부의 임의의 초기점
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT);//윈도우 지우기

	for (j = 0; j < 5000; j++); {//5000번반복
		i = rand%3;//삼각형 내부에 random하게 임의의 점p[i] 선택
		p[0] = (p[0] + vertices[i][0]) / 2.0;//선택된 점과 현재 점을 기준으로 계산한 중점의 위치 x값
		p[1] = (p[1] + vertices[i][1]) / 2.0;//선택된 점과 현재 점을 기준으로 계산한 중점의 위치 y값

		glBegin(GL_POINTS);//타입은 점
		glVertex3fv(p);//찍힐 위치에 점 찍기
		glEnd();
	}

glFlush();//명령 실행
}


void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //창 배경 흰색
	glColor3f(0.5, 0.5, 0.5); //회색으로 바꿈

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 300.0, 1, -1); //원점을 좌하단으로 하는 500
}

//윈도우 초기화
int main(int argc, char**argv)
{
	glutInit(&argc, argv); //Window OS와 Session 연결
	glutInitDisplayMode(GLUT_RGB); //Display Mode RGB로 설정
	glutInitWindowSize(500, 500); //Window의 크기 설정
	glutInitWindowPosition(0, 0); //Monitor에서 Window의 시작점 위치는 원점
	glutCreateWindow("3D Tetrahedron Gasket"); //새로운 Window 3D Tetrahedron Gasket 생성
	glutDisplayFunc(MyDisplay); //callback 함수
	MyInit();
	glutMainLoop(); //GLUT Event 처리 Loop 입력
}
