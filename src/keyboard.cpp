#include <GL/glut.h>
#include <screen.h>
#include <physics.h>
#include <stdbool.h>

int pause = 0;
GLfloat translateX = 0, translateY = 0; // Define as variáveis responsáveis pela movimentação do personagem

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 13: // Tecla ENTER que trata o pause do jogo
        if (telaAtual && !pause)
            glutDisplayFunc(telaPause); // Troca para a tela de pause

        else if (telaAtual && pause)       
            glutDisplayFunc(segundaTela); // Troca para a tela de jogo
        break;

    case 'z':
    case 'Z':
        
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
        if(translateY < alturaJanela -250 && verificaColisaoCima()){
            translateY += playerVelocity;
        }
            //translateY += playerVelocity;
        break;
    case GLUT_KEY_LEFT:
        if(translateX > -larguraJanela/2 && verificaColisaoEsquerda()){
            translateX -= playerVelocity;
        }
        break;
    case GLUT_KEY_RIGHT:
        if(translateX < larguraJanela/2 && verificaColisaoDireita()){
            translateX += playerVelocity;
        }
        break;
    case GLUT_KEY_DOWN:
        if(translateY > -alturaJanela/2 +430 && verificaColisaoEmbaixo()){
            translateY -= playerVelocity;
        }
        break;
    }
    glutPostRedisplay();
}