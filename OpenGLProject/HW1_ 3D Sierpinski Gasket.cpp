/***********************************************************************************************************************************************************************************************/
/*                                                                  HW#1 : 3D Sierpinski Gasket                                                                                                */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 9�� 23��                                                       */


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

/*���� ����:
             �ﰢ�� �׸���                                                                                                                                                                      */
struct Point {
	/*���:
	       3D�� �����ϴ� ���� ��ǥ�̹Ƿ� �迭�ε��� ��� x��ǥ, y��ǥ�Ӹ� �ƴ϶� z��ǥ���� �����Ͽ� 3���� ������ ������ ���                                                                    */
	GLfloat x, y, z; 
	/*���: 
	       3D ��ǥ: (x,y,z)                                                                                                                                                                     */
	Point(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {} 
	/*���:
	       ������ �� p�� �����Ͽ� ���õ� ���� ���� ���� �������� ����� ������ ��ġ x, y, z�� ��                                                                                                */
	Point midpoint(Point p) { return Point((x + p.x) / 2, (y + p.y) / 2, (z + p.z) / 2); }
};

/*���� ����: 
            ������ȯ, ������ȯ                                                                                                                                                                   */
void reshape(GLint w, GLint h) {
	/*���:
	       ��ü�� â���� �׸� �� �ֵ��� viewport�� pixel ��ǥ�� ��ġ�ϵ��� �������� w*h ������ ���                                                                                              */
	glViewport(0, 0, w, h); 
	/*���:
	       ������� ����                                                                                                                                                                         */
	glMatrixMode(GL_PROJECTION); 
	/*���:
	       ���� ��������� �׵���ķ� �ʱ�ȭ                                                                                                                                                     */
	glLoadIdentity(); 
	/*���:
	       �Ƕ�̵尡 �ְ���� �ʵ��� ���� ���� ������ �����Ͽ� �Ƕ�̵��� ���������� �� �� �ֵ��� ����                                                                                          */
	gluPerspective(100.0, GLfloat(w) / GLfloat(h), 10.0, 1500.0); 
}


void display() { 
	/*���: 
	       â ��� ���                                                                                                                                                                          */
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	/*���:
	       �� ���ۿ� ���� ���� ������ viewport �����                                                                                                                                            */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
}

/*���� ����:
            �Լ��� ���� �� ������ ���� ���� ��ü�� ���ÿ� �����Ͽ� ȣ���� �� �ش� ���� ����                                                                                                      */
void generateMorePoints() { 

	/*���� ����: 
	            4��ü���� 4���� ������ ����                                                                                                                                                      */
	static Point vertices[4] = { 
	  Point(-250, -225, -200),
	  Point(-250, -555, -700),
	  Point(470, -225, -400),
	  Point(0, 450, -500)
	};
	static Point lastPoint = vertices[0];

	/*���:
	       type�� ��                                                                                                                                                                              */
	glBegin(GL_POINTS); 
	/*���:
	       1000�� �ݺ�                                                                                                                                                                            */
	for (int i = 0; i <= 1000; i++) { 
		/*���: 
		       4��ü ���ο� random�ϰ� ������ �� ����                                                                                                                                             */
		lastPoint = lastPoint.midpoint(vertices[rand() % 4]);
		/*���:
		       4��ü�� z��ǥ ������ -200���� -700���� �̾����� ������ z���� 700�� ���ϰ� 500���� ������ 0���� 1������ ������ ���� ����                                                            */
		GLfloat intensity = (700 + lastPoint.z) / 500.0; 
		/*���:
		       �׷����� ������ ���� ������                                                                                                                                                        */
		glColor3f(1.0, 0.0, 0.0); 
		/*���:
		       ���� ��ġ�� �� ���                                                                                                                                                                */
		glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z); 
	}
	glEnd();
	/*���:
	       ��� ����                                                                                                                                                                              */
	glFlush(); 
}

/*���� ����: 
            �ʱ�ȭ                                                                                                                                                                                */
void init() {
	/*���:
	        Depth ���۸� ����                                                                                                                                                                     */
	glEnable(GL_DEPTH_TEST); 
}

/*���� ����:
            ������ �ʱ�ȭ                                                                                                                                                                         */
int main(int argc, char** argv) { 
	/*���:
	       Window OS�� Session ����                                                                                                                                                               */
	glutInit(&argc, argv); 
	/*���:
	       Display Mode Single, RGB, Depth�� ����                                                                                                                                                 */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	/*���:
	       Window�� ũ�� ����                                                                                                                                                                     */
	glutInitWindowSize(500, 500); 
	/*���:
	         Monitor���� Window�� ������ ��ġ                                                                                                                                                     */
	glutInitWindowPosition(150, 50); 
	/*���:
	        ���ο� Window 3D Tetrahedron Gasket ����                                                                                                                                              */
	glutCreateWindow("3D Sierpinski Gasket"); 
	/*���:
	        �̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                     */
	glutDisplayFunc(display); 
	/*���:
	       �̺�Ʈ Ÿ�� RESHAPE callback �Լ�                                                                                                                                                      */
	glutReshapeFunc(reshape); 
	/*���:
	        �̺�Ʈ Ÿ�� IDLE callback �Լ�                                                                                                                                                        */
	glutIdleFunc(generateMorePoints); 
	init();
	/*���:
	        GLUT Event ó�� Loop �Է�                                                                                                                                                             */
	glutMainLoop(); 
}
/**************************************************************************************************************************************************************************************************/