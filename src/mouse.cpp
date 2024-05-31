#include <GL/glut.h>
#include <screen.h>
#include <keyboard.h>

void mouse(int button, int estado, int x, int y)
{
    int alturaMax = glutGet(GLUT_WINDOW_HEIGHT); // Armazena a altura máxima da tela
    // Desenha o primeiro retângulo

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && !telaAtual)
        {            
            glutDisplayFunc(segundaTela); // Efetiva a troca de tela
        }
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && pause)
        {
            if (x >= 860 && x <= 1060 && y >= 430  && y <= 530 ) // verifica se "continuar" foi selecionado
                glutDisplayFunc(segundaTela);
        }
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && (pause || telaOver))
        {
            if (x >= 860 && x <= 1060 && y <= 650 && y >= 550) // verifica se "sair" foi selecionado tanto na tela de pause, como na tela fim
                exit(0);
        }
    
    glutPostRedisplay();
}