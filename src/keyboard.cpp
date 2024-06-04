#include <GL/glut.h>
#include <screen.h>
#include <physics.h>
#include <utils.h>
#include <stdbool.h>
#include <position.h>

int pause = 0;
GLfloat translateX = 0, translateY = 0; // Define as variáveis responsáveis pela movimentação do personagem

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 13: // Tecla ENTER que trata o pause do jogo
        if (telaAtual == GAME_SCREEN)
        {
            glutDisplayFunc(telaPause);                            // Troca para a tela de pause
            glutTimerFunc(400, animateGamePauseScreenTextures, 0); // Começa a animação da tela de pause do jogo
        }
        else if (telaAtual == GAME_PAUSE_SCREEN)
        {
            glutDisplayFunc(telaJogo);                     // Troca para a tela de jogo
            glutTimerFunc(200, animateGameScreenTextures, 0); // Começa a animação da tela do jogo
        }
        break;

    case 'z':
    case 'Z':
        disparos.push_back({translateX + wPlayer, translateY + hPlayer / 2, 30, 10, true, 15.0f});
        break;
    case 'x':
    case 'X':

        break;
    case 'c':
    case 'C':

        break;

    case 32: // Tecla espaço

        break;

    case 27: // Tecla ESC
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void teclasEspeciais(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_UP:
        if (translateY < alturaJanela - 200 && verificaColisaoCima())
        {
            startJump();
            //translateY += playerVelocity;
        }
        break;
    case GLUT_KEY_LEFT:
        if (translateX > -150 && verificaColisaoEsquerda())
        {
            movePlayerX = -playerVelocity;
            leftPressed = true;
            //translateX -= playerVelocity;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (translateX < larguraJanela - 250 && verificaColisaoDireita())
        {
            movePlayerX = playerVelocity;
            rightPressed = true;
            //translateX += playerVelocity;            
        }
        break;
    case GLUT_KEY_DOWN:
        if (translateY > alturaJanela * 0.05 - 40 && verificaColisaoEmbaixo())
        {
            //translateY -= playerVelocity;
        }
        break;
    }
    glutPostRedisplay();
}

void specialKeysUp(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_LEFT:
        leftPressed = false;
        break;
    case GLUT_KEY_RIGHT:
        rightPressed = false;
        break;
    }
}