#ifndef AQSAMOSQUE_H  //SALMA AL FAWAL
#define AQSAMOSQUE_H

#include "Minaret.h"
#include "GateObject.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cube.h"
#include "PolygonQ.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library

class aqsaMosque {
public:
    GLuint bottomPolygonFront;
    GLuint bottomPolygon;
    GLuint upperPolygon;
    GLuint whiteRock;
    GLuint redRug2;
    GLuint grayMetal2;
    GLuint beige;
    GLuint bottomCylinder;
    GLuint qibbaTex;
    GLuint aqsaGateTop;
    GLuint columnSide;
    GLuint aqsaGateSideTop;
	GLuint transparent;

    aqsaMosque::aqsaMosque(GLuint bottomPolygonFront, GLuint bottomPolygon, GLuint upperPolygon, GLuint whiteRock, GLuint redRug2,
        GLuint grayMetal2, GLuint beige, GLuint bottomCylinder, GLuint qibbaTex, GLuint aqsaGateTop, GLuint columnSide,
		GLuint aqsaGateSideTop, GLuint transparent) :
        bottomPolygonFront(bottomPolygonFront), bottomPolygon(bottomPolygon), upperPolygon(upperPolygon), whiteRock(whiteRock),
        redRug2(redRug2), grayMetal2(grayMetal2), beige(beige), bottomCylinder(bottomCylinder), qibbaTex(qibbaTex),
		aqsaGateTop(aqsaGateTop), columnSide(columnSide), aqsaGateSideTop(aqsaGateSideTop), transparent(transparent){}

    void aqsaMosque::drawAqsa() {
        glPushMatrix();
        glScalef(2.0f, 2.0f, 2.0f);
        glRotatef(20, 0.0f, 1.0f, 0.0f);
        GLuint textures2[8] = { bottomPolygonFront, bottomPolygon, bottomPolygonFront, bottomPolygon, bottomPolygonFront, bottomPolygon, bottomPolygonFront, bottomPolygon };
        PolygonQ bottomAqsaPolygon(10.5f, 8, 4.0f, 4.0f, textures2, whiteRock, redRug2);
        bottomAqsaPolygon.draw();
		
		Sphere rock(2.0f, 5, true, whiteRock);
		rock.draw();

        glTranslatef(0.0f, 4.0f, 0.0f);
        GLuint textures1[8] = { upperPolygon, upperPolygon, upperPolygon, upperPolygon, upperPolygon, upperPolygon, upperPolygon, upperPolygon };
        PolygonQ upperAqsaPolygon(11.0f, 8, 2.0f, 2.0f, textures1, grayMetal2, beige);
        upperAqsaPolygon.draw();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, 14.7f, 0.0f);
        Cylinder cylinder(6.9f, 4.7f, 10, bottomCylinder, qibbaTex, whiteRock);
        cylinder.draw();

        glTranslatef(0.0f, 2.2f, 0.0f);
        Cylinder cylinder2(7.3f, 0.3f, 10, qibbaTex, qibbaTex, qibbaTex);
        cylinder2.draw();

        glTranslatef(0.0f, 0.3f, 0.0f);
        Sphere sphere(7.0f, 20, true, qibbaTex);
        sphere.draw();

        glPopMatrix();

		glPushMatrix();
        glTranslatef(-0.7f, 0.2f, 20.0f);
		GateObject aqsaGate(aqsaGateTop, columnSide, columnSide, aqsaGateSideTop, 0, beige, transparent);
        aqsaGate.drawAqsaGate();
		 glTranslatef(0.0f, 0.0f, 2.0f);
		 aqsaGate.drawAqsaGate();
		 glTranslatef(0.0f, 0.0f, 2.0f);
		 aqsaGate.drawAqsaGate();
		glPopMatrix();
    }
};

#endif
