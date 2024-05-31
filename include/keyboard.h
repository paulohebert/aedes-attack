#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <GL/glut.h>

extern GLfloat translateX, translateY;

extern int pause;

void teclado(unsigned char, int, int);

void teclasEspeciais(int, int, int);

#endif
