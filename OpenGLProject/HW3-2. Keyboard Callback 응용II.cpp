/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#3-2. Keyboard Callback 응용II                                                                                              */
/* 작성자: 엄예진                                                                                                 날짜 : 2021년 10월 8일                                                          */

#include <gl/glut.h>
#include <stdio.h>
/*기능:
	   오브젝트 이동을 위한 변수 (좌우/위아래)                                                                                                                                                    */
double trans_left = 0, trans_up = 0;


void MyDisplay() {
/*기능:
		색 버퍼 제거                                                                                                                                                                              */
	glClear(GL_COLOR_BUFFER_BIT);
/*기능:
		그려지는 도형의 색은 회색                                                                                                                                                                 */
	glColor3f(0.5, 0.5, 0.5);
/*기능:
		type은 다각형                                                                                                                                                                             */
	glBegin(GL_POLYGON);
/*기능:
		찍힐 위치에 점 찍기                                                                                                                                                                       */
	glVertex3f(-0.5 + trans_left, -0.5 + trans_up, 0.0);
	glVertex3f(0.5 + trans_left, -0.5 + trans_up, 0.0);
	glVertex3f(0.5 + trans_left, 0.5 + trans_up, 0.0);
	glVertex3f(-0.5 + trans_left, 0.5 + trans_up, 0.0);
	glEnd();
/*기능:
		명령 실행                                                                                                                                                                                 */
	glFlush();
}


/*문제 정의:
			투영변환, 뷰폿변환                                                                                                                                                                    */
void MyReshape(int NewWidth, int NewHeight) {
/*기능:
		전체의 창에서 그릴 수 있도록 viewport를 pixel 좌표와 일치하도록 원점에서 (NewWidth)*(NewHeight) 영역에 출력                                                                               */
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
/*기능:
		모델뷰 행렬 선택                                                                                                                                                                          */
	glMatrixMode(GL_PROJECTION);
/*기능:
		현재 모델뷰 행렬을 항등행렬로 초기화                                                                                                                                                      */
	glLoadIdentity();
/*기능:
		행렬변환                                                                                                                                                                                  */
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 *HeightFactor, 1.0 * HeightFactor, -1.0, -1.0);
}

/*문제 정의:
			스페셜 키보드 이벤트 등록                                                                                                                                                             */
void MySpecialKey(int Key, int x, int y)
{
	switch (Key) {
/*기능:
	   왼쪽 키 입력 시 왼쪽으로 0.1씩 이동                                                                                                                                                        */
	case GLUT_KEY_LEFT:     
		trans_left = trans_left - 0.1;
/*기능:
	   윈도우 영역을 벗어나지 않도록 설정                                                                                                                                                         */
		if (trans_left < -0.5)  trans_left -= -0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
		오른쪽 키 입력 시 오른쪽으로 0.1씩 이동                                                                                                                                                   */
	case GLUT_KEY_RIGHT: 
		trans_left = trans_left + 0.1;
/*기능:
		윈도우 영역을 벗어나지 않도록 설정                                                                                                                                                        */
		if (trans_left > 0.5)  trans_left -= 0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
		위 키 입력 시 위쪽으로 0.1씩 이동                                                                                                                                                         */
	case GLUT_KEY_UP:      
		trans_up = trans_up + 0.1;
/*기능:
		윈도우 영역을 벗어나지 않도록 설정                                                                                                                                                        */
		if (trans_up > 0.5)  trans_up -= 0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
		아래 키 입력 시 아래쪽으로 0.1씩 이동                                                                                                                                                     */
	case GLUT_KEY_DOWN:      
		trans_up = trans_up - 0.1;
/*기능:
		윈도우 영역을 벗어나지 않도록 설정                                                                                                                                                        */
		if (trans_up < -0.5)  trans_up -= -0.1;
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
		Page Up 키 입력 시 0.1씩 확대                                                                                                                                                             */
	case GLUT_KEY_PAGE_UP:
		
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
/*기능:
	   Page Down 키 입력 시 0.1씩 축소                                                                                                                                                            */
	case GLUT_KEY_PAGE_DOWN:
		
/*기능:
		윈도우 다시 그리도록 요청                                                                                                                                                                 */
		glutPostRedisplay();
		break;
	}

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
		새로운 Window Graphics Keyboard Callback 응용 2 생성                                                                                                                                      */
	glutCreateWindow("Keyboard Callback 응용 2");
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
		이벤트 타입 DISPLAY callback 함수                                                                                                                                                         */
	glutDisplayFunc(MyDisplay);
/*기능:
		이벤트 타입 MySpecialKey callback 함수                                                                                                                                                    */
	glutSpecialFunc(MySpecialKey);

/*기능:
		GLUT Event 처리 Loop 입력                                                                                                                                                                 */
	glutMainLoop();

	return 0;
}
/**************************************************************************************************************************************************************************************************/
