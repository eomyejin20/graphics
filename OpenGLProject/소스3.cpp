/** Sierpinski test 4 - 3D

	All paths method (with recursion)

	2020.08.29 raron
*/
#include <GL/glut.h>

int depth = 6;  // recursion depth

int dWidth = 600;
int dHeight = 600;
int scrollWheel = 0;

PVector eye;
PVector startPoint;

int verts = 4;
PVector[] coord = new PVector[verts];


void settings()
{
	size(dWidth, dHeight, P3D);
}

void setup()
{
	//background(32);  

	eye = new PVector(width / 2.0, height / 2.0, (height / 2.0) / tan(PI*30.0 / 180.0));

	// 3D Sierpinski triangle vertices
	coord[0] = new PVector(0, 0, 0);
	coord[1] = new PVector(300, 0, 0);
	coord[2] = new PVector(150, 0, 260);
	coord[3] = new PVector(150, 245, 130);

	// random start point
	startPoint = new PVector(150, 122, 130);
}


void draw()
{
	background(32);
	stroke(color(255, 70, 70));
	noFill();
	//text(frameRate, 50, 50);

	// Quick'n'dirty viewpoint change
	if (mousePressed)
	{
		eye.x = dWidth - mouseX;
		eye.y = dHeight - mouseY;
	}
	eye.z = eye.z + scrollWheel * 20;
	scrollWheel = 0;

	sierpinski(startPoint, depth);

	camera(eye.x, eye.y, eye.z, width / 2.0, height / 2.0, 0, 0, 1, 0);
}


void sierpinski(PVector currentPoint, int currentDepth)
{
	if (currentDepth == 0) return;
	PVector temp = currentPoint.get();
	for (PVector sVertice : coord)
	{
		currentPoint.set((currentPoint.x + sVertice.x) / 2, (currentPoint.y + sVertice.y) / 2, (currentPoint.z + sVertice.z) / 2);
		pushMatrix();
		translate(width / 4 + currentPoint.x, height * 3 / 4 - currentPoint.y, currentPoint.z);
		box(1);
		popMatrix();
		sierpinski(currentPoint, currentDepth - 1);
		currentPoint = temp.get();
	}
}


void mouseWheel(MouseEvent event)
{
	scrollWheel = event.getCount();
}