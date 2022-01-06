#include <GL/glut.h>

//�ﰢ���׸���
void MyDisplay() {
	float verticies[3][2] = { {0.0,0.0}, {250.0,300.0}, {500.0,0.0} };//�ʱ��� �ﰢ��
	float p[2] = { 75.0, 50.0 }; //�ﰢ�� ������ ������ �ʱ���
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT);//������ �����

	for (j = 0; j < 5000; j++); {//5000���ݺ�
		i = rand%3;//�ﰢ�� ���ο� random�ϰ� ������ ��p[i] ����
		p[0] = (p[0] + vertices[i][0]) / 2.0;//���õ� ���� ���� ���� �������� ����� ������ ��ġ x��
		p[1] = (p[1] + vertices[i][1]) / 2.0;//���õ� ���� ���� ���� �������� ����� ������ ��ġ y��

		glBegin(GL_POINTS);//Ÿ���� ��
		glVertex3fv(p);//���� ��ġ�� �� ���
		glEnd();
	}

glFlush();//��� ����
}


void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //â ��� ���
	glColor3f(0.5, 0.5, 0.5); //ȸ������ �ٲ�

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 300.0, 1, -1); //������ ���ϴ����� �ϴ� 500
}

//������ �ʱ�ȭ
int main(int argc, char**argv)
{
	glutInit(&argc, argv); //Window OS�� Session ����
	glutInitDisplayMode(GLUT_RGB); //Display Mode RGB�� ����
	glutInitWindowSize(500, 500); //Window�� ũ�� ����
	glutInitWindowPosition(0, 0); //Monitor���� Window�� ������ ��ġ�� ����
	glutCreateWindow("3D Tetrahedron Gasket"); //���ο� Window 3D Tetrahedron Gasket ����
	glutDisplayFunc(MyDisplay); //callback �Լ�
	MyInit();
	glutMainLoop(); //GLUT Event ó�� Loop �Է�
}
