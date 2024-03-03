#ifndef WALLS_H    //SALMA AL FAWAL
#define WALLS_H


#include "Minaret.h"
#include "GateObject.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cube.h"
#include "PolygonQ.h"

#include <glut.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library


class walls {

public:
	GLuint sideLeft, roofing, whiteRock, whiteWood, minaretSide, wellRock, transparent, treeTrunk, water;
	walls(GLuint sideLeft, GLuint roofing, GLuint whiteRock, GLuint whiteWood, GLuint minaretSide, GLuint wellRock, GLuint transparent, GLuint treeTrunk, GLuint water){
	
		this->sideLeft = sideLeft;
		this->roofing = roofing;
		this->whiteRock = whiteRock;
		this->whiteWood = whiteWood;
		this->minaretSide = minaretSide;
		this->transparent =transparent;
		this->wellRock = wellRock;
		this->treeTrunk = treeTrunk;
		this->water = water;

	};

	void walls::drawWalls(){


	//the angle wall
		glPushMatrix();
	glTranslatef(51.5f, -1.6f, -20.0f);
	Cube outsideWall2(30.0f, 2.0f, 5.0f, sideLeft, sideLeft, roofing, sideLeft, sideLeft, sideLeft, false);
		outsideWall2.draw(); //left wall

	glTranslatef(25.5f, 0.0f, 26.0f);
	Cube outsideWall3(4.0f, 2.0f, 22.0f, sideLeft, sideLeft, roofing, sideLeft, sideLeft, sideLeft, true);
		outsideWall3.draw(); //right wall

	glPushMatrix();
	glTranslatef(0.0f, 3.0f, 0.0f);
	Sphere roofSphere(2.0f, 15, true, whiteRock);
		roofSphere.draw(); //qibba of the wall
	glPopMatrix();

	glTranslatef(2.0f, 0.0f, 42.0f);
	Cube outsideWall4(1.5f, 2.0f, 20.0f, sideLeft, sideLeft, roofing, sideLeft, sideLeft, sideLeft, false);
		outsideWall4.draw(); //right right wall
	glPopMatrix();

	glPushMatrix();
	glTranslatef(76.0f, 6.0f, -22.0f);
	Minaret minaret(sideLeft, whiteRock, whiteWood, minaretSide);
	minaret.drawMinaret(); //minaret of the wall
	glPopMatrix();


	glPushMatrix();
	glScalef(1.0, 1.7, 1.0);
	glTranslatef(79.0f, 5.0f, 70.5f);
	minaret.drawMinaret(); //minaret of the wall
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	Cylinder well(5.0f, 7.0f, 13, wellRock, transparent, wellRock);
	Cylinder well2(4.7f, 3.0f, 13, wellRock, water, wellRock);

	Cylinder stick(0.5f, 6.0f, 6, treeTrunk, treeTrunk, treeTrunk);
	
	
	glTranslatef(-100.0f, -3.0f, 70.5f);

	well.draw();
	well2.draw();

	glPushMatrix();
	glTranslatef(4.7f, 6.0f, 0.0f);
	stick.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.7f, 6.0f, 0.0f);
	stick.draw();
	glPopMatrix();

	/*glPushMatrix();
	glScalef(2.0, 1.0, 1.0);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	glTranslatef(-4.0f, 20.0f, 0.0f);
	stick.draw();
	glPopMatrix();*/

	glPopMatrix();

	}
};

#endif