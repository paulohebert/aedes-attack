#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>

/* Quantidade de Texturas */
#define NUM_TEXTURES 13
/* Texturas */
#define BACKGROUND_MENU 0
#define BACKGROUND_MAIN 1
#define BACKGROUND_PAUSE 2
#define LOGO 3
#define MOSQUITO_PROHIBITED 4
#define MOSQUITO_ENEMY 5
#define PLATFORM 6
#define BUTTON_PLAY 7
#define BUTTON_START 8
#define BUTTON_PAUSE 9
#define BUTTON_EXIT 10
#define COMBAT_INFO 11
#define PLAYER 12

extern GLuint *textures;

void loadTextures(int);

void drawBackgroundMenu();

void drawBackgroundMain();

void drawInfos(float, float, float, float);

void drawBoyPlayer(GLfloat x, GLfloat y, GLfloat width, GLfloat height);

void draw(int textureID, GLfloat x, GLfloat y, GLfloat width, GLfloat height);

#endif
