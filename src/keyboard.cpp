#include <GL/glut.h>
#include <screen.h>

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 13: // Tecla ENTER
        if (telaAtual == 0)
        {
            telaAtual = 1;                // Muda para a segunda tela
            glutDisplayFunc(segundaTela); // Registra a função da segunda tela
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