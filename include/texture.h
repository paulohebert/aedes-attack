#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>

/* Quantidade de Texturas */
#define NUM_TEXTURES 7
/* Texturas */
#define BACKGROUND_MENU 0
#define BACKGROUND_MAIN 1
#define LOGO 2
#define MOSQUITO_PROHIBITED 3
#define MOSQUITO_ENEMY 4
#define PLATFORM 5
#define BUTTON_PLAY 6

extern GLuint *textures;

void loadTextures(int);

void drawBackgroundMenu();

void drawBackgroundMain();

#endif
