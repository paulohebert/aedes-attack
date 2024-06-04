#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>

/* Quantidade de Texturas */
#define NUM_TEXTURES 16
/* Texturas */
#define BACKGROUND_MENU 0      /* Índice da Textura da Tela de Início */
#define BACKGROUND_MAIN 1      /* Índice da Textura da Tela do Jogo */
#define BACKGROUND_PAUSE 2     /* Índice da Textura da Tela de Pause */
#define BUTTON_PLAY 3          /* Índice da Textura do Botão de Continuar o Jogo */
#define BUTTON_START 4         /* Índice da Textura do Botão de Iniciar */
#define BUTTON_PAUSE 5         /* Índice da Textura do Botão de Pause */
#define BUTTON_EXIT 6          /* Índice da Textura do Botão de Sair */
#define BUTTON_ABOUT 7         /* Índice da Textura do Botão de Sobre */
#define LOGO 8                 /* Índice da Textura da Logo do Jogo "Aedes Attack" */
#define UNIVASF 9              /* Índice da Textura da Logo da Univasf */
#define MOSQUITO_PROHIBITED 10 /* Índice da Textura da Placa de Proibido Mosquito */
#define PLAYER 11              /* Índice da Textura do Jogador */
#define MOSQUITO_ENEMY 12      /* Índice da Textura do Inimigo */
#define PLATFORM 13            /* Índice da Textura da Plataforma do Jogo */
#define HEART 14               /* Índice da Textura da Vida do Jogador */
#define BANNER_COMBAT_INFO 15  /* Índice da Textura do Banner Educativo sobre o combate ao mosquito */
#define DISPARO_FRAME 16       /* Índice da Textura do Disparo */

/* Frame Atual da Animação a ser exibido na Tela */
extern int currentBackgroundMenuFrame;
extern int currentBackgroundMainFrame;
extern int currentBannerCombatInfoFrame;
extern int currentPlayerFrame;

/* Número Total de Frames em cada Animação */
#define BACKGROUND_MENU_TOTAL_FRAMES 96
#define BACKGROUND_MAIN_TOTAL_FRAMES 16
#define BANNER_COMBAT_INFO_TOTAL_FRAMES 61
#define PLAYER_TOTAL_FRAMES 15

void loadTextures(int);

void freeTextures();

void drawTexture(int textureID, GLfloat xTexture, GLfloat yTexture, GLfloat wTexture, GLfloat hTexture, GLfloat x, GLfloat y, GLfloat width, GLfloat height);

void draw(int textureID, GLfloat x, GLfloat y, GLfloat width, GLfloat height);

void drawFrame(int textureID, int currentFrame, int totalRow, int totalCol, GLfloat x, GLfloat y, GLfloat width, GLfloat height);

#endif
