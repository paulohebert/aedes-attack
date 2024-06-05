#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include <GL/glut.h>
#include <vector> 

extern bool playerNoChao;
extern GLfloat gravity;
extern GLfloat playerVelocity;
extern GLfloat movePlayerX;
extern GLfloat movePlayerY;
extern GLfloat jumpStrength;
extern bool isJumping;
extern GLfloat jumpVelocity;
extern GLfloat jumpHeight; 
extern bool leftPressed;
extern bool rightPressed;
struct disparo {
    float x, y;
    float largura = 20, altura = 10;
    GLfloat velocity;
    bool direita;
};
extern std::vector<disparo> disparos;
extern bool direcaoDisparo;

bool verificaColisaoEsquerda();
bool verificaColisaoDireita();
bool verificaColisaoEmbaixo();
bool verificaColisaoCima();
bool applyGravity();
void moveObjetos();
void jump(int value);
void startJump();;
void disparar();
void moveDisparos();


#endif // PHYSICS_H