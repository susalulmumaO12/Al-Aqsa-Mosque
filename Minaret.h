#ifndef MINARET_H   //SALMA AL FAWAL
#define MINARET_H

#include "Cylinder.h"
#include "Cube.h"

#include <glut.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

class Minaret {

public:
	GLuint sideTex, topTex, bottomTex, cubeSideTex;

	Minaret(GLuint side, GLuint top, GLuint bottom, GLuint cubeSide){
		this->sideTex = side;
		this->topTex = top;
		this->bottomTex = bottom;
		this->cubeSideTex = cubeSide;
	};

	Minaret(void){}

	void Minaret::drawMinaret(){

		glPushMatrix();

		Cylinder column(1.5f, 15.0f, 5, sideTex, topTex, bottomTex);
		column.draw();

		glTranslatef(0.0f, 8.0f, 0.0f);

		Cube cube(1.5f, 1.5f, 1.5f, cubeSideTex, cubeSideTex, topTex, bottomTex, cubeSideTex, cubeSideTex, false);
		cube.draw();

		glTranslatef(0.0f, 2.0f, 0.0f);
		Cylinder coneColumn(1.5, 1.5, 5, sideTex, topTex, bottomTex);
		coneColumn.drawWithCone();

		glPopMatrix();
	}
};

#endif