#include <GL/glut.h>
#include <screen.h>
#include <keyboard.h>

void mouse(int button, int estado, int x, int y)
{
    int uraMax = glutGet(GLUT_WINDOW_HEIGHT); // Armazena a altura máxima da tela
    // Desenha o primeiro retângulo

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && !telaAtual)
        {
            telaAtual = 1;                // Altera a variável que controla a tela
            glutDisplayFunc(segundaTela); // Efetiva a troca de tela
        }
        if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
        {
            if (x >= 860 && x <= 1060 && y >= 430  && y <= 530 ) // verifica se "continuar" foi selecionado
                glutDisplayFunc(segundaTela);
        }
        if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
        {
            if (x >= 860 && x <= 1060 && y <= 650 && y >= 550) // verifica se "sair" foi selecionado
                exit(0);
        }


    if (button == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
        {
            
        }
    glutPostRedisplay();
}