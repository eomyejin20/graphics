#include <GL/glut.h>

void MyLightInit() {
	GLfloat global_ambient[] = { 0.5, 0.5, 0.5, 1.0 };	//���� �ֺ��ݻ�

	GLfloat Light0_Ambient[] = { 1.0, 1.0, 1.0, 1.0 };	//0�� ���� Ư��
	GLfloat Light0_Diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat Light0_Specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat Light1_Ambient[] = { 0.3, 0.3, 0.3, 1.0 };	//1�� ���� Ư��
	GLfloat Light1_Diffuse[] = { 0.3, 0.3, 0.3, 0.3 };
	GLfloat Light1_Specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat Light0_Position[] = { 0.0, 0.0, 1.0, 1.0 };	//0�� ������ġ
	GLfloat Light0_Direction[] = { 0.0, 0.0, -1.0 };		//0�� ���� ����
	GLfloat Light0_Cutoff[] = { 5.0 };					//0�� ���� ����

	GLfloat Light1_Position[] = { 0.0, 0.0, 1.0, 1.0 };	//1�� ������ġ

	glLightfv(GL_LIGHT0, GL_AMBIENT, Light0_Ambient);	//0�� ���� Ư���Ҵ�
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light0_Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light0_Specular);

	glLightfv(GL_LIGHT1, GL_AMBIENT, Light1_Ambient);	//1�� ���� Ư���Ҵ�
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light1_Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Light1_Specular);

	glLightfv(GL_LIGHT0, GL_POSITION, Light0_Position);	//����Ʈ����Ʈ
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Light0_Direction);	//����
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, Light0_Cutoff);	//����
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1.0);			//�ڻ��� �¼�

	GLfloat material_ambient[] = { 0.0, 0.0, 0.0, 1.0 };	//��ü Ư��
	GLfloat material_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat material_shininess[] = { 127.0 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);//��ü Ư���Ҵ�
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//�����ֺ��ݻ� 
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); //��������

	glShadeModel(GL_SMOOTH);	//���� ���̵�
	glEnable(GL_DEPTH_TEST);	//���� ���� Ȱ��ȭ
	glEnable(GL_LIGHTING);		//���� Ȱ��ȭ
	glEnable(GL_LIGHT0);		//0�� ���� Ȱ��ȭ
	glEnable(GL_LIGHT1);		//1�� ���� Ȱ��ȭ
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);							//�𵨺� ���
	glLoadIdentity();									//�׵���� �ε�
	gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	//������ȯ

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			glPushMatrix();
			glTranslatef(-0.5 + i * 0.3, -0.5 + j * 0.3, 0.0);
			glutSolidSphere(0.2, 500, 500);
			glPopMatrix();
		}
	}

	glDisable(GL_LIGHTING);
	glTranslatef(0.0, 0.0, 1.0);
	glutWireCone(0.05, 0.1, 50, 50);
	glEnable(GL_LIGHTING);

	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);				//�������
	glLoadIdentity();							//�׵���� �ε�
	gluPerspective(60.0, (GLsizei)w / (GLsizei)h, 0.1, 100);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Spotlight");
	glClearColor(0.5, 0.5, 0.5, 0.5);
	MyLightInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}