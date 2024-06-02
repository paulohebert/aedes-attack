#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include <GL/glut.h>

extern bool playerNoChao;
extern GLfloat gravity;
extern GLfloat playerVelocity;
extern GLfloat movePlayerX;
extern GLfloat movePlayerY;
extern GLfloat jumpStrength;
extern bool isJumping;
extern GLfloat jumpVelocity;
extern GLfloat jumpHeight; 


bool verificaColisaoEsquerda();
bool verificaColisaoDireita();
bool verificaColisaoEmbaixo();
bool verificaColisaoCima();
bool applyGravity();
void moveObjetos();
void jump(int value);
void startJump();;
#endif // PHYSICS_H