/**************************************************************************************************************************************************************************************************/
/*                                                                  HW#2-1. GL Modeling                                                                                                           */
/* �ۼ���: ������                                                                                                 ��¥ : 2021�� 9�� 30��                                                          */

#include <GL/glut.h>



/*���� ����: 
            2D Primitive Points �����ϱ�                                                                                                                                                          */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
	/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� ��                                                                                                                                                                              */
	glBegin(GL_POINTS);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();

}


/*���� ����:
			2D Primitive Lines �����ϱ�                                                                                                                                                           */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
	/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� ��                                                                                                                                                                              */
	glBegin(GL_LINES);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive LineStrip �����ϱ�                                                                                                                                                       */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
	/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� linestrip                                                                                                                                                                       */
	glBegin(GL_LINE_STRIP);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive LineLoop �����ϱ�                                                                                                                                                        */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� lineloop                                                                                                                                                                        */
	glBegin(GL_LINE_LOOP);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive Polygons �����ϱ�                                                                                                                                                        */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� �ٰ���                                                                                                                                                                          */
	glBegin(GL_POLYGON);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, -0.25, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0);  glVertex3f(-0.5, 0.25, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive Triangles �����ϱ�                                                                                                                                                       */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� �ﰢ��                                                                                                                                                                          */
	glBegin(GL_TRIANGLES);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(-0.5, -0.25, 0.0); glVertex3f(0.0, -0.5, 0.0); glVertex3f(0.5, 0.25, 0.0); glVertex3f(-0.5, 0.25, 0.0); glVertex3f(-0.5, 0.75, 0.0); glVertex3f(0.5, 0.75, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive TriangleStrip �����ϱ�                                                                                                                                                   */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� �ﰢ�� strip                                                                                                                                                                    */
	glBegin(GL_TRIANGLE_STRIP);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(0.6, -0.1, 0.0); glVertex3f(0.5, 0.2, 0.0); glVertex3f(0.3, 0.0, 0.0); glVertex3f(0.15, 0.25, 0.0); glVertex3f(0.0, -0.05, 0.0); glVertex3f(-0.15, 0.15, 0.0); glVertex3f(-0.25, 0.0, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive TriangleFan �����ϱ�                                                                                                                                                     */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� �ﰢ�� ��ä��                                                                                                                                                                   */
	glBegin(GL_TRIANGLE_FAN);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.65, 0.0, 0.0); glVertex3f(0.6, 0.2, 0.0); glVertex3f(0.35, 0.4, 0.0); glVertex3f(0.2, 0.45, 0.0); glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive Quads �����ϱ�                                                                                                                                                           */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� �簢��                                                                                                                                                                          */
	glBegin(GL_QUADS);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(0.35, -0.3, 0.0); glVertex3f(0.4, -0.2, 0.0); glVertex3f(0.3, 0.005, 0.0); glVertex3f(0.005, -0.3, 0.0); glVertex3f(-0.2, 0.1, 0.0); glVertex3f(-0.1, 0.3, 0.0); glVertex3f(-0.35, 0.3, 0.0); glVertex3f(-0.4, 0.2, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
			2D Primitive QuadStrip �����ϱ�                                                                                                                                                       */
void MyDisplay() {
/*���:
		   �� ���� ����                                                                                                                                                                           */
	glClear(GL_COLOR_BUFFER_BIT);
/*���:
			   �׷����� ������ ���� �Ķ���                                                                                                                                                        */
	glColor3f(0.0, 0.0, 1.0);
	/*���:
		   type�� �簢�� strip                                                                                                                                                                    */
	glBegin(GL_QUAD_STRIP);
	/*���:
			   ���� ��ġ�� �� ���                                                                                                                                                                */
	glVertex3f(0.35, -0.3, 0.0); glVertex3f(0.4, -0.2, 0.0); glVertex3f(0.005, -0.3, 0.0); glVertex3f(0.3, 0.005, 0.0); glVertex3f(-0.2, 0.1, 0.0); glVertex3f(-0.1, 0.3, 0.0); glVertex3f(-0.4, 0.2, 0.0); glVertex3f(-0.35, 0.3, 0.0);
	glEnd();
	/*���:
		   ��� ����                                                                                                                                                                              */
	glFlush();


}

/*���� ����:
            ������ �ʱ�ȭ                                                                                                                                                                         */
int main(int argc, char** argv) { 
	/*���:
	       Window OS�� Session ����                                                                                                                                                               */
	glutInit(&argc, argv); 
	/*���:
	       Display Mode RGB�� ����                                                                                                                                                                */
	glutInitDisplayMode(GLUT_RGB);
	/*���:
	       Window�� ũ�� ����                                                                                                                                                                     */
	glutInitWindowSize(500, 500); 
	/*���:
	         Monitor���� Window�� ������ ��ġ                                                                                                                                                     */
	glutInitWindowPosition(-30, 0); 
	/*���:
	        ���ο� Window 3D Tetrahedron Gasket ����                                                                                                                                              */
	glutCreateWindow("GL Modeling"); 
	/*���:
		   â ��� ���                                                                                                                                                                           */
	glClearColor(1.0, 1.0, 1.0, 1.0);
	/*���:
	        �̺�Ʈ Ÿ�� DISPLAY callback �Լ�                                                                                                                                                     */
	glutDisplayFunc(MyDisplay); 
	/*���:
	        GLUT Event ó�� Loop �Է�                                                                                                                                                             */
	glutMainLoop(); 

	return 0;
}
/**************************************************************************************************************************************************************************************************/