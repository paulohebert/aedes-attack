#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include <GL/glut.h>

extern bool playerNoChao;
extern GLfloat gravity;
extern GLfloat jump;

bool verificaColisoes();
void applyGravity();

#endif // PHYSICS_H
