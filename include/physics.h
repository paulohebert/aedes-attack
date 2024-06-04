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
    bool disparou;
    GLfloat velocity;
};
extern std::vector<disparo> disparos;

bool verificaColisaoEsquerda();
bool verificaColisaoDireita();
bool verificaColisaoEmbaixo();
bool verificaColisaoCima();
bool applyGravity();
void moveObjetos();
void jump(int value);
void startJump();;
void disparar();

#endif // PHYSICS_H