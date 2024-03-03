#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <stdio.h>                         // Header File For Standard Input/Output ( NEW )
#include <cmath>
#include <math.h>
#include "PolygonQ.h"
//#include "GothicArch.h"
#include "Sphere.h"
#include "Cube.h"
#include "Texture.h"
#include "Cylinder.h"
#include "GateObject.h"
#include "tree.h"
#include "Square.h"
//#include "Minaret.h"
#include "qibliMosque.h"
#include "aqsaMosque.h"
#include "walls.h"
#include "Skybox.h"
#include <glut.h>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <GLAUX.H>		// Header File For The Glaux Library
//#include <Model_3DS.h>
//#include <3DTexture.h>
#include "camera.h"
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib")

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

float moonPosition;

		GLfloat light_pos [] = {0.0, 500.0, 0.0, 1.0};
		GLfloat light_pos2 [] = {0.0, 1000.0, -200.0, 1.0};
		GLfloat light_pos3 [] = {-150.0, 900.0, 0.0, 1.0};
		GLfloat lightAmbient [] = {1.0, 1.0, 1.0, 1.0};
		GLfloat lightDiffuse [] = {1.0, 1.0, 1.0, 0.0};
		
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

int DrawGLScene();

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,50.0f,10000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	//glLoadIdentity();									// Reset The Modelview Matrix
	DrawGLScene();
}

GLuint
	skyUp,
	skyFront,
	skyBack,
	skyRight,
	skyLeft,
	skyBottom,

	skyNightUp,
	skyNightFront, 
	skyNightBack,  
	skyNightRight, 
	skyNightLeft,  
	skyNightBottom,

	beige,
	roofing,
	top1,
	whiteRock,
	whiteWood,
	leftWindow,
	rightWindow,
	grayWood,
	grayMetal,
	grayMetal2,
	flatRoof,
	rockRoof,
	redRug,
	redRug2,
	cat,
	sideCircle,
	sideSide,
	sideLeft,
	leftLeft,
	topOfGate,
	topOfMainGate,
	transparent,
	leftColumn,
	rightColumn,
	sideOfTopOfGate,
	sideOfColumn,
	sideOfTopOfMainGate,
	leftMainColumn,
	rightMainColumn,     
	sideOfMainColumn,
	frontWindow,
	frontGate,
	frontGateRight,
	column,
	whiteFloor,
	whiteColumns,
	minaretSide,
	upperPolygon,
	bottomPolygon,
	bottomPolygonFront,
	qibbaTex,
	treeTrunk,
	treeLeaves,
	treeLeaves1,
	treeLeaves2,
	treeLeaves3,
	treeLeaves4,
	stair,
	brick,
	bottomCylinder,
	aqsaGateSideTop,
	aqsaGateTop,
	columnSide,
	wellRock,
	water
	;
//
//Model_3DS *treeModel;
//GLTexture BARK,Leaf;

bool isDayTime = true;

Camera MyCamera;
bool  isClicked,isRClicked;
double movX, movY, movZ,lX,lY;
float mouseX = 0, mouseY = 0;
float LastX , LastY ;

void mouse(float mouseX, float mouseY, bool isClicked, bool isRClicked)
{
    float dirX = mouseX - LastX;
    if(dirX > 0){
    MyCamera.RotateY(-mouseX * 0.002);
    }
    if(dirX < 0){
    MyCamera.RotateY(mouseX * 0.002);
    }
      float dirY = mouseY - LastY;
    float movey = mouseY * 0.002;
    /*yoffset += dirY * 0.002;
    if(yoffset > 0.5f){yoffset = 0.5f;movey = 0;}
    if(yoffset < -0.5f){yoffset = -0.5f;movey = 0;}*/
    if(dirY > 0){
    MyCamera.RotateX(-movey);
    }
    if(dirY < 0){
    MyCamera.RotateX(movey);
    }
}

void Key(bool* keys, float speed)
{
  if (keys['S'])
    MyCamera.RotateX(-1 * speed);
  if (keys['W'])
    MyCamera.RotateX(1 * speed);
  if (keys['D'])
    MyCamera.RotateY(-1 * speed);
  if (keys['Z'])
    MyCamera.RotateZ(1 * speed);
  if (keys['X'])
    MyCamera.RotateZ(-1 * speed);
  if (keys['A'])
    MyCamera.RotateY(1 * speed);
  if (keys[VK_UP])
    MyCamera.MoveForward(1 * speed);
  if (keys[VK_DOWN])
    MyCamera.MoveForward(-1 * speed);
  if (keys[VK_RIGHT])
    MyCamera.MoveRight(1 * speed);
  if (keys[VK_LEFT])
    MyCamera.MoveRight(-1 * speed);
  if (keys['O'])
    MyCamera.MoveUpward(1 * speed);
  if (keys['L'])
    MyCamera.MoveUpward(-1 * speed);
  
}


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping

  MyCamera = Camera();
  MyCamera.Position.x = 0;
  MyCamera.Position.y = 0;
  MyCamera.Position.z = +15;

	//beige = loadGltexture("res/textures/beige.png");
	skyUp	  = loadGltexture("res/textures/upSky.png");
	skyFront  = loadGltexture("res/textures/frontSky.png");
	skyBack   = loadGltexture("res/textures/backSky.png");
	skyRight  = loadGltexture("res/textures/rightSky.png");
	skyLeft   = loadGltexture("res/textures/leftSky.png");
	skyBottom = loadGltexture("res/textures/bottomSky.png");

	skyNightUp	  = loadGltexture("res/textures/upNightSky.png");
	skyNightFront  = loadGltexture("res/textures/frontNightSky.png");
	skyNightBack   = loadGltexture("res/textures/backNightSky.png");
	skyNightRight  = loadGltexture("res/textures/rightNightSky.png");
	skyNightLeft   = loadGltexture("res/textures/leftNightSky.png");
	skyNightBottom = loadGltexture("res/textures/bottomNightSky.png");

	beige	  = loadGltexture("res/textures/beige.png");
	roofing   = loadGltexture("res/textures/roofing.png");
	grayMetal = loadGltexture("res/textures/metal.png");
	grayMetal2 = loadGltexture("res/textures/metal2.png");
	flatRoof  = loadGltexture("res/textures/flatRoof.png");
	grayWood  = loadGltexture("res/textures/grayWood.png");
	rockRoof  = loadGltexture("res/textures/rockRoof.png");
	redRug	  = loadGltexture("res/textures/redRug.png");
	redRug2	  = loadGltexture("res/textures/redRug2.png");
	leftWindow	  = loadGltexture("res/textures/sideWindow.png");
	rightWindow	  = loadGltexture("res/textures/rightWindow.png");
	whiteRock = loadGltexture("res/textures/whiteRock.png");
	whiteWood = loadGltexture("res/textures/whiteWood.png");
	cat		  = loadGltexture("res/textures/cat.png");
	sideCircle = loadGltexture("res/textures/sideCircle.png");
	sideSide = loadGltexture("res/textures/sideSide.png");
	sideLeft = loadGltexture("res/textures/sideLeft.png");
	leftLeft = loadGltexture("res/textures/leftLeft.png");
	topOfGate = loadGltexture("res/textures/topOfGate.png");
	topOfMainGate = loadGltexture("res/textures/topOfMainGate.png");
	transparent = loadGltexture("res/textures/transparent.png");
	sideOfTopOfGate = loadGltexture("res/textures/sideTopOfGate.png");
	leftColumn = loadGltexture("res/textures/leftColumn.png");
	rightColumn = loadGltexture("res/textures/rightColumn.png");
	sideOfColumn = loadGltexture("res/textures/sideOfColumn.png");
	sideOfTopOfMainGate = loadGltexture("res/textures/sideTopOfMainGate.png");
	leftMainColumn      = loadGltexture("res/textures/leftMainColumn.png");
	rightMainColumn     = loadGltexture("res/textures/rightMainColumn.png");
	sideOfMainColumn    = loadGltexture("res/textures/sideOfMainColumn.png");
	frontWindow     = loadGltexture("res/textures/frontWindow.png");
	frontGate    = loadGltexture("res/textures/frontGate.png");
	frontGateRight    = loadGltexture("res/textures/frontGateRight.png");
	whiteFloor    = loadGltexture("res/textures/whiteFloor.png");
	column    = loadGltexture("res/textures/columnGate.png");
	minaretSide = loadGltexture("res/textures/minaretSide.png");
	whiteColumns    = loadGltexture("res/textures/whiteColumns.png");
	upperPolygon    = loadGltexture("res/textures/upperPolygon.png");
	bottomPolygon = loadGltexture("res/textures/bottomPolygon.png");
	bottomCylinder = loadGltexture("res/textures/bottomCylinder.png");
	bottomPolygonFront    = loadGltexture("res/textures/bottomPolygonFront.png");
	qibbaTex    = loadGltexture("res/textures/qibbaTex.png");
	treeTrunk    = loadGltexture("res/textures/treeTrunk.png");
	treeLeaves    = loadGltexture("res/textures/treeLeaves.png");
	treeLeaves1    = loadGltexture("res/textures/treeLeaves1.png");
	treeLeaves2    = loadGltexture("res/textures/treeLeaves2.png");
	treeLeaves3    = loadGltexture("res/textures/treeLeaves3.png");
	treeLeaves4    = loadGltexture("res/textures/treeLeaves4.png");
	stair    = loadGltexture("res/textures/stair.png");
	brick    = loadGltexture("res/textures/brick.png");

	aqsaGateSideTop	= loadGltexture("res/textures/aqsaGateSideTop.png");
	aqsaGateTop	= loadGltexture("res/textures/aqsaGateTop.png");
	columnSide  = loadGltexture("res/textures/columnSide.png");

	wellRock  = loadGltexture("res/textures/wellRock.png");
	water = loadGltexture("res/textures/water.png");

	
	////loading tree model
	//treeModel = new Model_3DS();
	//treeModel->Load("res/models/Tree1.3ds");
	//Leaf.LoadBMP("res/models/leaf2.bmp");
	//BARK.LoadBMP("res/models/BARK.bmp");
	//treeModel->pos.x=0;
	//treeModel->pos.y=0;
	//treeModel->pos.z=0;
	//treeModel->scale=1;
	//treeModel->Materials[0].tex=BARK;
	//treeModel->Materials[1].tex=Leaf;
	//treeModel->Materials[2].tex=Leaf;
	//treeModel->Materials[3].tex=Leaf;
	//treeModel->Materials[4].tex=Leaf;



	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glAlphaFunc ( GL_GREATER, 0.1 ) ;
     glEnable ( GL_ALPHA_TEST ) ;
	glShadeModel(GL_SMOOTH);
     glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);


	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT1);
	return TRUE;										// Initialization Went OK
}
float anglex = 0.0f;
float angley = 0.0f;
float anglez = 0.0f;
float zoom = -40.0f;
float xAxis = 0.0f;
float yAxis = 0.0f;
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
		/*glEnable(GL_BLEND);
		
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		*/glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR,GL_REPLACE);
	//moonPosition+=0.05;
		//glBlendFunc(GL_SRC_COLOR, GL_SRC_ALPHA_SATURATE);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);

	glLightfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos);

	glLightfv(GL_LIGHT1, GL_SHININESS, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos3);

		MyCamera.Render();

		Key(keys, 0.05);
		mouse(mouseX, mouseY, isClicked, isRClicked);
		LastX = mouseX;
		LastY = mouseY;

	glLoadIdentity();
	glTranslatef(xAxis,yAxis,zoom);

	glRotatef(anglex, 1.0f, 0.0f, 0.0f);
	glRotatef(angley, 0.0f, 1.0f, 0.0f);
	glRotatef(anglez, 0.0f, 0.0f, 1.0f);

	GLuint dayTex [6] = {skyFront, skyBack, skyUp, skyBottom, skyRight, skyLeft};
	GLuint nightTex [6] = {skyNightFront, skyNightBack, skyNightUp, skyNightBottom, skyNightRight, skyNightLeft};
	Skybox skybox(dayTex, nightTex, isDayTime);
	skybox.daytimeView();

	
		tree tree1(treeLeaves, treeTrunk);
		tree tree2(treeLeaves1, treeTrunk);
		tree tree3(treeLeaves2, treeTrunk);
		tree tree4(treeLeaves3, treeTrunk);
		tree tree5(treeLeaves4, treeTrunk);

	
	glTranslatef(0.0f, -200.0f, 0.0f);
	//glScalef(2.0, 2.0, 2.0);
	
	

	glTranslatef(0.0f, 0.0f, -150.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -150.0f);
	glPushMatrix();
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		glScalef(15.0f, 15.0f, 15.0f);

		Square square(brick, stair);
			square.draw();

	glPopMatrix();
	
	
	glPushMatrix();
		glScalef(4.0f, 4.0f, 4.0f);
		glTranslatef(0.0f, 3.9f, 0.0f);
		aqsaMosque mosque(bottomPolygonFront, bottomPolygon, upperPolygon, whiteRock, redRug2, grayMetal2, whiteFloor,
		bottomCylinder, qibbaTex, aqsaGateTop, columnSide, aqsaGateSideTop, transparent);
			mosque.drawAqsa();
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glScalef(10.0f, 10.0f, 10.0f);
	glTranslatef(-6.0f, 2.5f, -110.0f);
	qibliMosque qibli(frontGate, sideLeft, rockRoof, redRug, whiteColumns, leftWindow, 
                  frontGateRight, rightWindow, grayMetal, whiteRock, sideSide, sideCircle, 
                  topOfMainGate, leftMainColumn, rightMainColumn, sideOfTopOfMainGate, 
                  sideOfMainColumn, transparent, beige, topOfGate, leftColumn, rightColumn, 
                  sideOfTopOfGate, sideOfColumn, leftLeft, whiteWood, roofing, frontWindow, 
                  whiteFloor, column);
	qibli.drawMainBuilding();

	glPopMatrix();

	glPushMatrix();
	glScalef(8.0f, 8.0f, 8.0f);
	glTranslatef(-5.0f, 1.0f, -100.0f);
	walls wall(sideLeft, roofing, whiteRock, whiteWood, minaretSide, wellRock, transparent, treeTrunk, water);
	wall.drawWalls();

	glPopMatrix();

	glPushMatrix();
	glScalef(8.0f, 8.0f, 8.0f);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glTranslatef(-5.0f, 1.0f, -130.0f);
	wall.drawWalls();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -24.0f, 0.0f);
	GLuint groundTex = isDayTime ? beige : grayWood;
	Cube baseGround(1500.0f, 10.0f, 1500.0f, groundTex, groundTex, groundTex, groundTex, groundTex, groundTex, false);
	baseGround.draw();

	glPopMatrix();


	glPushMatrix();
		glScalef(5.0f, 5.0f, 5.0f);

		glTranslatef(-50.0f, -1.0f, -15.0f);
		
		for(int i = 0; i < 4; i++){


			glTranslatef(0.0f, 0.0f, 10.0f);
			tree5.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree4.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree5.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree4.drawTree4();

		}
		
	glPopMatrix();

	
	glPushMatrix();

		glTranslatef(-420.0f, -1.0f, -950.0f);
		glScalef(6.0f, 6.0f, 6.0f);
		for(int i = 0; i < 2; i++){


			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree3();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree3();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree2();

		}
		
	glPopMatrix();
	glPushMatrix();

		glTranslatef(-700.0f, -1.0f, -1200.0f);
		glScalef(7.0f, 7.0f, 7.0f);
		for(int i = 0; i < 2; i++){


			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree2.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree3();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree3();

		}
		
	glPopMatrix();
	glPushMatrix();

		glTranslatef(-900.0f, -1.0f, -1160.0f);
		glScalef(8.0f, 7.0f, 8.0f);
		for(int i = 0; i < 2; i++){


			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree2.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree3();
			

		}
		
	glPopMatrix();
	glPushMatrix();
	
	
		glScalef(5.0f, 5.0f, 5.0f);

		glTranslatef(50.0f, -1.0f, -15.0f);
			
		for(int i = 0; i < 4; i++){

			glTranslatef(0.0f, 0.0f, 10.0f);
			tree5.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree4.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree5.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree4.drawTree4();

		}

	glPopMatrix();

	glPushMatrix();

		glTranslatef(420.0f, -1.0f, -950.0f);
		glScalef(6.0f, 6.0f, 6.0f);
		for(int i = 0; i < 2; i++){


			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree3();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree3();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree2();

		}
		
	glPopMatrix();
	glPushMatrix();

		glTranslatef(700.0f, -1.0f, -1200.0f);
		glScalef(7.0f, 7.0f, 7.0f);
		for(int i = 0; i < 2; i++){


			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree2.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree3();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree3();

		}
		
	glPopMatrix();
	glPushMatrix();

		glTranslatef(900.0f, -1.0f, -1160.0f);
		glScalef(8.0f, 7.0f, 8.0f);
		for(int i = 0; i < 2; i++){


			glTranslatef(0.0f, 0.0f, 30.0f);
			tree4.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree2.drawTree2();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree1.drawTree1();
			glTranslatef(0.0f, 0.0f, 30.0f);
			tree3.drawTree3();
			

		}
		
	glPopMatrix();
	glPushMatrix();
		
		glTranslatef(1300.0f, -1.0f, -1300.0f);
		glScalef(10.0f, 10.0f, 10.0f);

		for(int i = 0; i < 5; i++){


			glTranslatef(0.0f, 0.0f, 10.0f);
			tree2.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree3.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree2.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree3.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree2.drawTree4();

		}
		
	glPopMatrix();
	glPushMatrix();
		
		glTranslatef(-1300.0f, -1.0f, -1350.0f);
		glScalef(10.0f, 10.0f, 10.0f);

		for(int i = 0; i < 5; i++){


			glTranslatef(0.0f, 0.0f, 10.0f);
			tree2.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree3.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree2.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree3.drawTree4();
			glTranslatef(0.0f, 0.0f, 10.0f);
			tree2.drawTree4();

		}
		
	glPopMatrix();
	glPushMatrix();
		
		glTranslatef(-1300.0f, -1.0f, -1300.0f);
		glScalef(10.0f, 10.0f, 10.0f);

		for(int i = 0; i < 5; i++){


			glTranslatef(10.0f, 0.0f, 0.0f);
			tree2.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree3.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree2.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree3.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree2.drawTree4();

		}
		
	glPopMatrix();
	glPushMatrix();
		
		glTranslatef(-1300.0f, -1.0f, 1300.0f);
		glScalef(10.0f, 10.0f, 10.0f);

		for(int i = 0; i < 5; i++){


			glTranslatef(10.0f, 0.0f, 0.0f);
			tree2.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree3.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree2.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree3.drawTree4();
			glTranslatef(10.0f, 0.0f, 0.0f);
			tree2.drawTree4();

		}
		
	glPopMatrix();

glDisable(GL_BLEND);
    return TRUE; // Keep Going
									// Keep Going
}


GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
		case WM_MOUSEMOVE:
		  {
		    mouseX = (float)LOWORD(lParam);
		    mouseY = (float)HIWORD(lParam);
		    isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		    isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		    break;
		  }
		  case WM_LBUTTONUP:
		    isClicked = false;    break;
		  case WM_RBUTTONUP:
		    isRClicked = false;   break;
		  case WM_LBUTTONDOWN:
		    isClicked = true;   break;
		  case WM_RBUTTONDOWN:
		    isRClicked = true;  break;
		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:
		{
			switch (wParam)
			{
				case SC_SCREENSAVE:
				case SC_MONITORPOWER:
					return 0;
			}
			break;
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}
	
	// Create Our OpenGL Window
	if (!CreateGLWindow("AL AQSA MOSQUE",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	
	
				
	while(!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message==WM_QUIT)				// Have We Received A Quit Message?
			{
				done=TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if ((active && !DrawGLScene()) || keys[VK_ESCAPE])	// Active?  Was There A Quit Received?
			{
				done=TRUE;							// ESC or DrawGLScene Signalled A Quit
			}
			else									// Not Time To Quit, Update Screen
			{
				SwapBuffers(hDC);					// Swap Buffers (Double Buffering)
			}
			if (keys['E'])						// Is R Being Pressed?
			{
				anglex+=0.9f;
			}
			if (keys['C'])						// Is C Being Pressed?
			{
				anglex-=0.9f;
			}
			if (keys['R'])						// Is R Being Pressed?
			{
				angley+=1.2f;
			}
			if (keys[VK_SHIFT]&&keys['R'])						// Is R shift Being Pressed?
			{
				angley+=1.7f;
			}
			if (keys['Q'])						// Is Q Being Pressed?
			{
				angley-=1.2f;
			}
			if (keys[VK_SHIFT]&&keys['Q'])						// Is Q shift Being Pressed?
			{
				angley-=1.7f;
			}
			if (keys['T'])						// Is R Being Pressed?
			{
				anglez+=1.5f;
			}
			if (keys['V'])						// Is Q Being Pressed?
			{
				anglez-=1.5f;
			}
			if (keys['A'])						// Is A Being Pressed?
			{
				xAxis+=1.5f;
			}
			if (keys['D'])						// Is D Being Pressed?
			{
				xAxis-=1.5f;
			}
			if (keys['W'])						// Is W Being Pressed?
			{
				yAxis-=1.5f;
			}
			if (keys['S'])						// Is S Being Pressed?
			{
				yAxis+=1.5f;
			}
			if (keys['Z'])						// Is Z Being Pressed?
			{
				zoom+=1.5f;
			}
			if (keys[VK_SHIFT]&&keys['Z'])						// Is Z Being Pressed?
			{
				zoom+=1.7f;
			}
			if (keys['X'])						// Is X Being Pressed?
			{
				zoom-=1.7f;
			}
			if (keys[VK_SHIFT]&&keys['X'])						// Is X Being Pressed?
			{
				zoom-=2.7f;
			}
			if (keys['F'])						// Is X Being Pressed?
			{
				yAxis = 50;
				anglex = 45;
				zoom = -50;
			}
			if (keys['G'])						// Is X Being Pressed?
			{
				yAxis = 150;
				anglex = 0;
				zoom = -100;
			}
			if (keys['N'])						// Is X Being Pressed?
			{
				isDayTime = false;
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT_MODEL_AMBIENT);
				glEnable(GL_AMBIENT);
				glEnable(GL_DIFFUSE);
				glEnable(GL_LIGHT1);
				glEnable(GL_SHADE_MODEL);
			}
			if (keys['M'])						// Is X Being Pressed?
			{
				isDayTime = true;
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT_MODEL_AMBIENT);
				glDisable(GL_AMBIENT);
				glDisable(GL_DIFFUSE);
				glDisable(GL_LIGHT1);
				glDisable(GL_SHADE_MODEL);
			}
			if (keys['P'])						// Is X Being Pressed?
			{
				if(isDayTime){
				mciSendString("close \"Maghrib.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("open \"daytime.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("play mp3 repeat", NULL, 0, NULL);
				}else{
				mciSendString("close \"daytime.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("open \"Maghrib.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("play mp3 repeat", NULL, 0, NULL);
				}
				
			}
			if (keys['O'])						// Is X Being Pressed?
			{
				mciSendString("pause mp3", NULL, 0, NULL);
			}
			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1]=FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen=!fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("AL AQSA MOSQUE",1920,1080,1024,fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}
	

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

