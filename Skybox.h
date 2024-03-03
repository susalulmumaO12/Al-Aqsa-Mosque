// Skybox.h  //SALMA AL FAWAL
#ifndef SKYBOX_H
#define SKYBOX_H

#include "Cube.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library

//#include "Sun.h"
//#include "Moon.h"

class Skybox {
private:
    //Sun sun;
    //Moon moon;
    int dayTexture[6];  // Texture for the "daytime" skybox
    int nightTexture[6];  // Texture for the "nighttime" skybox
    //GLfloat ambientDay[4] = {0.4, 0.4, 0.4, 1.0};  // Daytime ambient lighting
    //GLfloat ambientNight[4] = {0.2, 0.2, 0.2, 1.0};  // Nighttime ambient lighting
    bool isDaytime;

public:
    Skybox(GLuint dayTex[], GLuint nightTex[], bool isDayTime){
		this->isDaytime = isDayTime;  // Initially set to daytime

		for (int i = 0; i < 6; i++) {
			dayTexture[i] = dayTex[i];
			nightTexture[i] = nightTex[i];
    }
    }

    // Function to change the daytime/nighttime view
    void daytimeView() {

        if (isDaytime) {
    glPushMatrix();
		glTranslatef(0.0f, 200.0f, 0.0f);
		
		Cube skyBox(1500, 1500, 1500, dayTexture[0], dayTexture[1], dayTexture[2], dayTexture[3], dayTexture[4], dayTexture[5], false);
			skyBox.drawSkyBox();

	glPopMatrix();
            // Change the light properties for daytime
            //sun.setBrightness(1.0f);  // Brighter light for the sun
            //sun.setPosition(/*new position for the sun*/);
            //moon.setBrightness(0.0f);  // No light from the moon
        } else {
            
    glPushMatrix();
		glTranslatef(0.0f, 200.0f, 0.0f);
		
		Cube skyBox(1500, 1500, 1500, nightTexture[0], nightTexture[1], nightTexture[2], nightTexture[3], nightTexture[4], nightTexture[5], false);
			skyBox.drawSkyBox();

	glPopMatrix();
            // Change the light properties for nighttime
            //moon.setBrightness(1.0f);  // Brighter light for the moon
            //moon.setPosition(/*new position for the moon*/);
            //sun.setBrightness(0.0f);  // No light from the sun
        }

        // Change the ambient lighting based on daytime/nighttime

        //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, isDaytime ? ambientDay : ambientNight);
    }
};

#endif // SKYBOX_H
