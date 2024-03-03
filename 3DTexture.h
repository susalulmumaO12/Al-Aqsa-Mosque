#pragma once
#include <windows.h>

#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glut.h>			// Header File For The GLu32 Library
#include "texture.h"
class GLTexture {
public:
    GLTexture();
    ~GLTexture();

    void Load(char* name);
    void LoadFromResource(char* name);
    void Use();
    void BuildColorTexture(unsigned char r, unsigned char g, unsigned char b);

    void LoadBMP(char* name);
    void LoadTGA(char* name);
    void LoadBMPResource(char* name);
    void LoadTGAResource(char* name);

private:
    char* texturename;
    GLuint texture[1];
    GLsizei width;
    GLsizei height;
};