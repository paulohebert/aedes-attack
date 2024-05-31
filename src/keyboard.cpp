#include <GL/glut.h>
#include <screen.h>
#include <keyboard.h>

int pause = 0;
void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 13: // Tecla ENTER que trata o pause do jogo
        if (telaAtual && !pause)
        {
            pause = 1;
            glutDisplayFunc(telaPause);
        }
        else if (telaAtual && pause)
        {
            pause = 0;
            glutDisplayFunc(segundaTela);
        }
        break;

    case 'w':
    case 'W':
        break;

    case 'a':
    case 'A':
        break;

    case 'd':
    case 'D':
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