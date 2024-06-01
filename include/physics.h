#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include <GL/glut.h>

extern bool playerNoChao;
extern GLfloat gravity;
//extern GLfloat jump;
extern GLfloat speedJump;

bool verificaColisaoEsquerda();
bool verificaColisaoDireita();
bool verificaColisaoEmbaixo();
bool verificaColisaoCima();
void applyGravity();
void jump();

#endif // PHYSICS_H