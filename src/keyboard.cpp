#include <GL/glut.h>
#include <screen.h>

int pause = 0;
void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 13: // Tecla ENTER que trata o pause do jogo
        if (telaAtual && !pause)
        {
            telaAtual = 1;                // Muda para a segunda tela
            glutDisplayFunc(segundaTela); // Registra a função da segunda tela
        }
        break;

    case 'w':
    case 'W':
        translateY += 10;
        break;
    case 's':
    case 'S':
        translateY -= 10;
        break;
    case 'a':
    case 'A':
        translateX -= 10;
        break;

    case 'd':
    case 'D':
        translateX += 10;
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
    case GLUT_KEY_F1:
        break;
    case GLUT_KEY_F2:
        break;
    case GLUT_KEY_F3:
        break;
    }
    glutPostRedisplay();
}