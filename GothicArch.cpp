#include <glut.h>
#include <cmath>
#include "GothicArch.h"
GothicArch::GothicArch(float x, float y, float z) : x(x), y(y), z(z) {}
GothicArch::~GothicArch(){}

    void GothicArch::draw() {
		double M_PI = 3.14285714;
        const int numSegments = 100;
        const float angleIncrement = 2 * M_PI / numSegments;

        glBegin(GL_TRIANGLES);
		for(float i = -x; i <= x; i += 0.01f) {
		for(float j = -z; j <= z; j += 0.01f) {
        float y1 = sin(sqrt(i*i + j*j));
        float y2 = sin(sqrt((i+0.01f)*(i+0.01f) + j*j));
        float y3 = sin(sqrt(i*i + (j+0.01f)*(j+0.01f)));
        float y4 = sin(sqrt((i+0.01f)*(i+0.01f) + (j+0.01f)*(j+0.01f)));

        // First triangle
        glVertex3f(i, y1, j);
        glVertex3f(i+0.01f, y2, j);
        glVertex3f(i, y3, j+0.01f);

        // Second triangle
		
        glVertex3f(i+0.01f, y2, j);
        glVertex3f(i, y3, j+0.01f);
        glVertex3f(i+0.01f, y4, j+0.01f);
			}
		}
		glEnd();

    }
