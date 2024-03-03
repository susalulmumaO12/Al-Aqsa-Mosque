#ifndef QIBLIMOSQUE_H   //SALMA AL FAWAL
#define QIBLIMOSQUE_H

#include "Minaret.h"
#include "GateObject.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cube.h"

#include <glut.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

class qibliMosque {

public:
	GLuint frontGate, sideLeft, rockRoof, redRug, whiteColumns, leftWindow, frontGateRight, 
		rightWindow, grayMetal, whiteRock, sideSide, sideCircle, topOfMainGate, leftMainColumn,
		rightMainColumn, sideOfTopOfMainGate, sideOfMainColumn, transparent,  beige, topOfGate, 
		leftColumn, rightColumn, sideOfTopOfGate, sideOfColumn, leftLeft, whiteWood, roofing, 
		frontWindow, whiteFloor, column;

	  qibliMosque(GLuint frontGate, GLuint sideLeft, GLuint rocRoof, GLuint redRug, GLuint whiteColumns,
				  GLuint leftWindow, GLuint frontGateRight, GLuint rightWindow, GLuint grayMetal, 
				  GLuint whiteRock, GLuint sideSide, GLuint sideCircle, GLuint topOfMainGate, 
				  GLuint leftMainColumn, GLuint rightMainColumn, GLuint sideOfTopOfMainGate, 
				  GLuint sideOfMainColumn, GLuint transparent, GLuint beige, GLuint topOfGate, 
				  GLuint leftColumn, GLuint rightColumn, GLuint sideOfTopOfGate, GLuint sideOfColumn, 
				  GLuint leftLeft, GLuint whiteWood, GLuint roofing, GLuint frontWindow, GLuint whiteFloor, 
				  GLuint column) {
						this->frontGate = frontGate;
						this->sideLeft = sideLeft;
						this->rockRoof = rocRoof;
						this->redRug = redRug;
						this->whiteColumns = whiteColumns;
						this->leftWindow = leftWindow;
						this->frontGateRight = frontGateRight;
						this->rightWindow = rightWindow;
						this->grayMetal = grayMetal;
						this->whiteRock = whiteRock;
						this->sideSide = sideSide;
						this->sideCircle = sideCircle;
						this->topOfMainGate = topOfMainGate;
						this->leftMainColumn = leftMainColumn;
						this->rightMainColumn = rightMainColumn;
						this->sideOfTopOfMainGate = sideOfTopOfMainGate;
						this->sideOfMainColumn = sideOfMainColumn;
						this->transparent = transparent;
						this->beige = beige;
						this->topOfGate = topOfGate;
						this->leftColumn = leftColumn;
						this->rightColumn = rightColumn;
						this->sideOfTopOfGate = sideOfTopOfGate;
						this->sideOfColumn = sideOfColumn;
						this->leftLeft = leftLeft;
						this->whiteWood = whiteWood;
						this->roofing = roofing;
						this->frontWindow = frontWindow;
						this->whiteFloor = whiteFloor;
						this->column = column;
  };

	qibliMosque(){}

	void qibliMosque::drawMainBuilding(){

		//main building block
	glPushMatrix();
	glTranslatef(3.0f, 0.0f, 0.0f);
	Cube mainBuilding(11.0f, 3.5f, 20.0f, frontGate, sideLeft, rockRoof, redRug, whiteColumns, leftWindow, false); // Create a cube with edge size 1.0
    mainBuilding.draw();

	glTranslatef(15.0f, -0.5f, 0.0f);
	Cube mainBuildingTwo(4.0f, 3.0f, 20.0f, frontGateRight, sideLeft, rockRoof, redRug, rightWindow, whiteColumns, false); // Create a cube with edge size 1.0
    mainBuildingTwo.draw();

	glPopMatrix();
	
	
	//front gates roof and side walls
	glPushMatrix();

	glTranslatef(6.5f, 1.5f, 22.0f);
	Cube roof(14.5f, 0.2f, 2.0f, frontGateRight, frontGateRight, grayMetal, grayMetal, grayMetal, frontGateRight, false);
	roof.draw();

	glTranslated(0.0f, -0.2f, 0.0f);
	Sphere roofSphere(1.5f, 15, true, whiteRock);
	roofSphere.draw();

	glPopMatrix();


	glPushMatrix();

	glTranslatef(6.5f, -3.5f, 24.0f);
	Cube ground(14.5f, 0.2f, 4.0f, whiteRock, whiteRock, whiteRock, whiteRock, whiteRock, whiteRock, false);
	ground.draw();

	glPopMatrix();
	
	glPushMatrix();
	
	glTranslatef(-7.8f, -0.4f, 22.0f);
	Cube sideWall(0.3f, 2.8f, 2.0f, whiteRock, sideLeft, grayMetal, sideLeft, sideLeft, sideLeft, false);
	sideWall.draw();
	
	glPopMatrix();

		
	glPushMatrix();
	
	glTranslatef(20.8f, -0.4f, 22.0f);
	sideWall.draw();
	
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(6.5f, 2.0f, 24.0f);
	//GateObject gate(topOfGate, leftColumn, rightColumn, sideOfTopOfGate, sideOfColumn, beige, transparent);
	//gate.drawGate();
	GateObject mainGate(topOfMainGate, leftMainColumn, rightMainColumn, sideOfTopOfMainGate, sideOfMainColumn, beige, transparent);
	mainGate.drawMainGate();

	glPopMatrix();


	glPushMatrix();

	glTranslatef(11.0f, 0.6f, 24.0f);
	GateObject gate(topOfGate, leftColumn, rightColumn, sideOfTopOfGate, sideOfColumn, beige, transparent);
	gate.drawGate();
	glTranslatef(4.0f, 0.0f, 0.0f);
	gate.drawGate();
	glTranslatef(4.0f, 0.0f, 0.0f);
	gate.drawGate();

	glPopMatrix();


	glPushMatrix();

	glTranslatef(2.0f, 0.6f, 24.0f);
	gate.drawGate();
	glTranslatef(-4.0f, 0.0f, 0.0f);
	gate.drawGate();
	glTranslatef(-4.0f, 0.0f, 0.0f);
	gate.drawGate();

	glPopMatrix();


	//side blocks
	
	glPushMatrix();

		glTranslatef(-9.5f, 0.0f, -7.5f);
		//sideCircle block
		Cube leftSideDoor(2.0f, 3.5f, 2.0f, sideSide, sideSide, grayMetal, redRug, sideSide, sideCircle, false);
		leftSideDoor.draw();

		//the block on its left
		glTranslatef(-0.4f, -1.0f, -5.0f);
		Cube leftBlock(2.0f, 2.5f, 3.0f, sideLeft, sideLeft, grayMetal, redRug, leftLeft, leftLeft, false);
		leftBlock.draw();

		//the block on its right its right
		glTranslatef(-4.0f, -0.8f, -5.0f);
		Cube leftLeftBlock(6.5f, 1.7f, 2.0f, sideLeft, sideLeft, grayMetal, redRug, sideLeft, sideLeft, false);
		leftLeftBlock.draw();

		//the block on its right its right its right
		glTranslatef(-30.5f, 0.0f, -1.0f);
		Cube outsideWall(24.0f, 1.7f, 1.0f, sideLeft, sideLeft, rockRoof, sideLeft, sideLeft, sideLeft, false);
		outsideWall.draw();

	glPopMatrix();

	glPushMatrix();

		glTranslatef(-11.0f, -2.5f, 12.0f);
		Cube wall(0.3f, 0.7f, 12.5f, whiteRock, whiteRock, whiteWood, whiteWood, whiteWood, whiteWood, false); // Create a cube with edge size 1.0
		wall.draw();	

	glPopMatrix();

	//roofed block and Qibba
	
	glPushMatrix();

	glTranslatef(6.5f, 3.0f, 5.0f);
	//roofed building
	Cube roofed(3.0f, 1.5f, 15.0f, frontWindow, frontWindow, grayMetal, whiteFloor, rightWindow, rightWindow, true);
		roofed.draw();

	glPopMatrix();


	glPushMatrix();

		glTranslatef(6.5f, 3.5f, -14.0f);

		Cylinder cylinder(3.9f, 1.7f, 10, sideLeft, roofing, roofing);
		cylinder.draw();
		
		glTranslatef(0.0f, 1.0f, 0.0f);
		Cylinder cylinder2(4.3f, 0.3f, 10, grayMetal, grayMetal, grayMetal);
		cylinder2.draw();

		glTranslatef(0.0f, 1.0f, 0.0f);
		Sphere sphere(4.0f, 10, true, grayMetal);
		sphere.draw();

	glPopMatrix();

	//inside details
	
	glPushMatrix();

	glTranslatef(-5.5f, 0.4f, 0.0f);

	GateObject columns(column, whiteFloor, whiteFloor, whiteFloor, whiteFloor, whiteFloor, transparent);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-5.5f, 0.4f, -7.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();

	glPopMatrix();

	
	glPushMatrix();

	glTranslatef(-5.5f, 0.4f, 7.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();
	glTranslatef(3.5f, 0.0f, 0.0f);
	columns.drawGate();

	glPopMatrix();

	
	glPushMatrix();

	glTranslatef(6.5f, 1.0f, 0.0f);
		roofSphere.draw();
		glTranslatef(3.5f, 0.0f, 0.0f);
		roofSphere.draw();
		glTranslatef(3.5f, 0.0f, 0.0f);
		roofSphere.draw();
		glTranslatef(3.5f, 0.0f, 0.0f);
		roofSphere.draw();

	glPopMatrix();

	}

};

#endif