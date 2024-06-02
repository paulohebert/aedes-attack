#ifndef POSITION_H
#define POSITION_H

#include <GL/glut.h>

// --------------------------------------------------------------- //
// Tela de Início

// Posição da Logo do Jogo Aedes Attack
extern GLfloat xAedesAttack, yAedesAttack, wAedesAttack, hAedesAttack;

// Posição da Placa de Proibido Mosquito
extern GLfloat xMosquitoProhibited, yMosquitoProhibited, wMosquitoProhibited, hMosquitoProhibited;

// Posição do Botão de Iniciar do Jogo
extern GLfloat xButtonStart, yButtonStart, wButtonStart, hButtonStart;

// --------------------------------------------------------------- //
// Tela do Jogo

// Posição do Botão de Pause do Jogo
extern GLfloat xButtonPause, yButtonPause, wButtonPause, hButtonPause;

// Posição do Banner de Combate à Dengue
extern GLfloat xBannerDengue, yBannerDengue, wBannerDengue, hBannerDengue;

// Posição do Jogador
extern GLfloat xPlayer, yPlayer, wPlayer, hPlayer;

// Posição do Mosquito
extern GLfloat xMosquito, yMosquito, wMosquito, hMosquito;

// Posição da Plataforma de Piso do Chão
extern GLfloat xPlatformFloor, yPlatformFloor, wPlatformFloor, hPlatformFloor;

// Posição da Plataforma Suspensa 1
extern GLfloat xPlatform1, yPlatform1, wPlatform1, hPlatform1;

// Posição da Plataforma Suspensa 2
extern GLfloat xPlatform2, yPlatform2, wPlatform2, hPlatform2;

// Posição da Plataforma Suspensa 3
extern GLfloat xPlatform3, yPlatform3, wPlatform3, hPlatform3;

// Posição da Plataforma Suspensa 4
extern GLfloat xPlatform4, yPlatform4, wPlatform4, hPlatform4;

// Posição da Plataforma Suspensa 5
extern GLfloat xPlatform5, yPlatform5, wPlatform5, hPlatform5;

void updatePosition();

#endif