#ifndef GATEOBJECT_H   //SALMA AL FAWAL
#define GATEOBJECT_H

#include "Cube.h"
#include "Cylinder.h"
#include <glut.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library


class GateObject {

public:

	GLuint topOfGateTex, mainGateTex, transparentTex, leftColumnTex, rightColumnTex, sideOfTopOfGateTex, sideOfColumnTex, beigeTex;
	GateObject(GLuint frontUpper, GLuint frontLeft, GLuint frontRight, GLuint sideUpper, GLuint sideDown, GLuint bottom ,GLuint transparent){
		this->topOfGateTex = frontUpper;
		this->leftColumnTex = frontLeft;
		this->rightColumnTex = frontRight;
		this->sideOfTopOfGateTex = sideUpper;
		this->sideOfColumnTex = sideDown;
		this->beigeTex = bottom;
		this->transparentTex = transparent;
	};
    GateObject(void) {}

    void GateObject::drawGate() {
		
		glPushMatrix();

		glTranslatef(0.0f, 0.7f, 0.0f);
		Cube shortRoof(1.9f, 0.2f, 0.4f, beigeTex, beigeTex, beigeTex, beigeTex, sideOfTopOfGateTex, sideOfTopOfGateTex, true);
        shortRoof.draw();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(0.0f, 0.5f, 0.0f);
        // Draw the gate using the Cube class and the specified textures
		Cube topOfThreeGate(2.0f, 1.5f, 0.5f, topOfGateTex, topOfGateTex, transparentTex, transparentTex, sideOfTopOfGateTex, sideOfTopOfGateTex, false);
        topOfThreeGate.draw();

		glPopMatrix();

        glPushMatrix();
        glTranslatef(1.6f, -2.0f, 0.0f);
        Cube rightColumnOfThreeGate(0.4f, 1.8f, 0.5f, rightColumnTex, sideOfColumnTex, beigeTex, beigeTex, sideOfColumnTex, sideOfColumnTex, false);
        rightColumnOfThreeGate.draw();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6f, -2.0f, 0.0f);
        Cube leftColumnOfThreeGate(0.4f, 1.8f, 0.5f, leftColumnTex, sideOfColumnTex, beigeTex, beigeTex, sideOfColumnTex, sideOfColumnTex, false);
        leftColumnOfThreeGate.draw();
        glPopMatrix();
    }

	void GateObject::drawMainGate() {
		
		glPushMatrix();

		glTranslatef(0.0f, 0.3f, 0.0f);
		Cube shortRoof(2.4f, 0.2f, 0.4f, beigeTex, beigeTex, beigeTex, beigeTex, sideOfTopOfGateTex, sideOfTopOfGateTex, true);
        shortRoof.draw();

		glPopMatrix();

        // Draw the gate using the Cube class and the specified textures
		Cube topOfMainGate(2.5f, 1.5f, 0.5f, topOfGateTex, topOfGateTex, transparentTex, transparentTex, sideOfTopOfGateTex, sideOfTopOfGateTex, false);
        topOfMainGate.draw();

        glPushMatrix();
        glTranslatef(1.8f, -3.2f, 0.0f);
        Cube rightColumn(0.7f, 2.0f, 0.5f, rightColumnTex, sideOfColumnTex, beigeTex, beigeTex, sideOfColumnTex, sideOfColumnTex, false);
        rightColumn.draw();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.8f, -3.2f, 0.0f);
        Cube leftColumn(0.7f, 2.0f, 0.5f, leftColumnTex, sideOfColumnTex, beigeTex, beigeTex, sideOfColumnTex, sideOfColumnTex, false);
        leftColumn.draw();
        glPopMatrix();
    }

	void GateObject::drawAqsaGate(){
		Cylinder column(0.3f, 3.5, 20, leftColumnTex, rightColumnTex, rightColumnTex);
		Cube cube(0.5f, 0.5f, 0.5f, beigeTex, beigeTex, beigeTex, beigeTex, beigeTex, beigeTex, false);
			


        glPushMatrix();
		glTranslatef(1.9f, 0.0f, 0.0f);
			cube.draw();
        glTranslatef(0.0f, 2.0f, 0.0f);
			column.draw();
		glTranslatef(0.0f, 2.0f, 0.0f);
			cube.draw();
        glPopMatrix();



        glPushMatrix();
		glTranslatef(-1.9f, 0.0f, 0.0f);
			cube.draw();
        glTranslatef(0.0f, 2.0f, 0.0f);
			column.draw();
		glTranslatef(0.0f, 2.0f, 0.0f);
			cube.draw();
        glPopMatrix();



		glPushMatrix();

		glTranslatef(0.0f, 6.0f, 0.0f);
        // Draw the gate using the Cube class and the specified textures
		Cube topAqsaGate(2.5f, 1.5f, 0.5f, topOfGateTex, topOfGateTex, transparentTex, transparentTex, sideOfTopOfGateTex, sideOfTopOfGateTex, false);
        topAqsaGate.draw();

		glPopMatrix();

	}

};
  #endif /* GATEOBJECT_H */