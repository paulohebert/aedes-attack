#ifndef POSITION_H
#define POSITION_H

#include <GL/glut.h>

// Posição da Logo do Jogo Aedes Attack
extern GLfloat xAedesAttack, yAedesAttack, wAedesAttack, hAedesAttack;

// Posição da Placa de Proibido Mosquito
extern GLfloat xMosquitoProhibited, yMosquitoProhibited, wMosquitoProhibited, hMosquitoProhibited;

// Posição do Botão de Iniciar do Jogo
extern GLfloat xButtonStart, yButtonStart, wButtonStart, hButtonStart;

void updatePosition();

#endif