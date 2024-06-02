#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include <GL/glut.h>

extern bool playerNoChao;
extern GLfloat gravity;
extern GLfloat playerVelocity;
extern GLfloat speedJump;
extern GLfloat movePlayerX;
extern GLfloat movePlayerY;

bool verificaColisaoEsquerda();
bool verificaColisaoDireita();
bool verificaColisaoEmbaixo();
bool verificaColisaoCima();
void applyGravity();
void moveObjetos();

#endif // PHYSICS_H