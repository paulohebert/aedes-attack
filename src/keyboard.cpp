#include <GL/glut.h>
#include <screen.h>

int pause = 0;
GLfloat translateX = 0, translateY = 0;

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 13: // Tecla ENTER que trata o pause do jogo
        if (telaAtual && !pause)
        {     
            glutDisplayFunc(telaPause); // Efetiva a troca de tela
        }
        else if (telaAtual && pause) {            
            glutDisplayFunc(segundaTela);
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
    case GLUT_KEY_UP:
        translateY += 10;
        break;
    case GLUT_KEY_LEFT:
        translateX -= 10;
        break;
    case GLUT_KEY_RIGHT:
        translateX += 10;
        break;
    case GLUT_KEY_DOWN:
        translateY -= 10;
        break;
    }
    glutPostRedisplay();
}