#include <GL/glut.h>
#include <screen.h>
#include <keyboard.h>

void mouse(int button, int estado, int x, int y)
{
    int alturaMax = glutGet(GLUT_WINDOW_HEIGHT); // Armazena a altura máxima da tela
    
    // Desenha o primeiro retângulo
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && !telaAtual)
        {            
            if (x >= retX && x <= (retX+largura) && y >= retY  && y <= (retY+altura)) // Verifica se "iniciar" foi selecionado
            glutDisplayFunc(segundaTela); // Troca para a tela de jogo
        }
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && pause)
        {
            if (x >= retX && x <= (retX+largura) && y >= retY  && y <= (retY+altura)) // Verifica se "continuar" foi selecionado
                glutDisplayFunc(segundaTela); // Troca para a tela de jogo
        }
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && (pause || telaOver))
        {
            if (x >= retX2 && x <= (retX2+largura) && y >= retY2  && y <= (retY2+altura)) // Verifica se "sair" foi selecionado tanto na tela de pause, como na tela fim
                exit(0); // Sai do jogo
        }
    
    glutPostRedisplay();
}