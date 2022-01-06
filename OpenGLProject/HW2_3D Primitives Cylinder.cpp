/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#2-2. GLU Modeling                                                                                                          */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 9월 30일                                                          */

#include <stdlib.h>
#include <GL/glut.h>

/*기능:
	   새로운 Quadric 생성                                                                                                                                                                        */
GLUquadricObj *qobj = gluNewQuadric();
/*기능:
	   DisplayList는 정수 ID에 의해 식별                                                                                                                                                          */
int MyListID[4];

void MyInit(void) {

	/*기능:
		   주변광                                                                                                                                                                                 */
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	/*기능:
		   반사광                                                                                                                                                                                 */
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	/*기능:
		   선명도                                                                                                                                                                                 */
	GLfloat mat_shininess[] = { 50.0 };
	/*기능:
		   조명 위치                                                                                                                                                                              */
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	/*기능:
		   그려지는 그림의 색                                                                                                                                                                     */
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	/*기능:
		   창 배경 검은색                                                                                                                                                                         */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*기능:
		   질감의 설정                                                                                                                                                                            */
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	/*기능:
		   광원의 설정                                                                                                                                                                            */
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	/*기능:
		   조명 모델의 설정                                                                                                                                                                       */
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

	/*기능:
		   조명 모드를 활성화                                                                                                                                                                     */
	glEnable(GL_LIGHTING);
	/*기능:
		   0번의 광원 활성화                                                                                                                                                                      */
	glEnable(GL_LIGHT0);
	/*기능:
		   깊이 버퍼 활성화                                                                                                                                                                       */
	glEnable(GL_DEPTH_TEST);
}

/*문제 정의:
			Display List 생성                                                                                                                                                                          */
void MyCreateList() {
	/*기능:
		   새로운 List 생성                                                                                                                                                                       */
	MyListID[0] = glGenLists(4);
	/*기능:
		   Display List를 생성하기 위한 함수로 ID를  컴파일이 완료된 버전으로 새로 만듦                                                                                                           */
	glNewList(MyListID[0], GL_COMPILE);

	/*기능:
		   Quadric을 위해 원하는 Draw Style 지정                                                                                                                                                  */
	gluQuadricDrawStyle(qobj, GLU_FILL);
	/*기능:
		   법선벡터 제어                                                                                                                                                                          */
	gluQuadricNormals(qobj, GLU_SMOOTH);
	/*기능:
		   법선벡터 외부로 방향 지정                                                                                                                                                              */
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	/*기능:
		   Texture 좌표 사용 안함                                                                                                                                                                 */
	gluQuadricTexture(qobj, GL_FALSE);

	/*기능:
		   Cylinder 생성                                                                                                                                                                         */
	gluCylinder(qobj, 1.0, 0.5, 2.0, 20, 20);

	/*기능:
		   Display List의 끝을 표시하는 함수                                                                                                                                                     */
	glEndList();

}



void MyDisplay() {
	/*기능:
		   색 버퍼와 깊이 버퍼 제거                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*기능:
		   모델뷰 행렬 선택                                                                                                                                                                      */
	glMatrixMode(GL_MODELVIEW);
	/*기능:
		   현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                  */
	glLoadIdentity();

	/*기능:
		   조명모드를 활성화                                                                                                                                                                     */
	glEnable(GL_LIGHTING);
	/*기능:
		   정점색을 보간해가면서 채운다                                                                                                                                                          */
	glShadeModel(GL_SMOOTH);

	/*기능:
		   Display List를 실행하기 위한 함수                                                                                                                                                     */
	glCallList(MyListID[0]);
	/*기능:
		   버퍼 2개 사용                                                                                                                                                                         */
	glutSwapBuffers();
}

/*문제 정의:
			투영변환, 뷰폿변환                                                                                                                                                                   */
void Reshape(int w, int h) {
	/*기능:
		   전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 (GLsizei)w*(GLsizei)h 영역에 출력                                                                            */
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	/*기능:
		   투영행렬 선택                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION);
	/*기능:
		   현재 투영행렬을 항등행렬로 초기화                                                                                                                                                     */
	glLoadIdentity();

	/*기능:
		   행렬변환                                                                                                                                                                              */
	glOrtho(-2.5, 2.5, -2.5*(GLfloat)h / (GLfloat)w, 2.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	/*기능:
		   모델뷰 행렬 선택                                                                                                                                                                      */
	glMatrixMode(GL_MODELVIEW);
	/*기능:
		   현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                   */
	glLoadIdentity();
}

/*문제 정의:
			윈도우 초기화                                                                                                                                                                         */
int main(int argc, char** argv) {
	/*기능:
		   Window OS와 Session 연결                                                                                                                                                               */
	glutInit(&argc, argv);
	/*기능:
		   Display Mode Double, RGB, Depth로 설정                                                                                                                                                 */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/*기능:
		   Window의 크기 설정                                                                                                                                                                     */
	glutInitWindowSize(800, 600);
	/*기능:
			 Monitor에서 Window의 시작점 위치                                                                                                                                                     */
	glutInitWindowPosition(0, 0);
	/*기능:
			새로운 Window Graphics Primitives Cylinder 생성                                                                                                                                         */
	glutCreateWindow("Graphics Primitives Cylinder");
	/*기능:
		   재질과 빛과 관련된 값 초기화                                                                                                                                                           */
	MyInit();
	/*기능:
			이벤트 타입 DISPLAY callback 함수                                                                                                                                                     */
	glutDisplayFunc(MyDisplay);
	/*기능:
		   이벤트 타입 RESHAPE callback 함수                                                                                                                                                      */
	glutReshapeFunc(Reshape);
	/*기능:
		   Display List 생성                                                                                                                                                                      */
	MyCreateList();
	/*기능:
			GLUT Event 처리 Loop 입력                                                                                                                                                             */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/