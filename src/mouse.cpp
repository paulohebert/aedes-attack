#include <GL/glut.h>
#include <screen.h>
#include <keyboard.h>
#include <position.h>
#include <utils.h>

int isHover(GLfloat xMouse, GLfloat yMouse, GLfloat xObj, GLfloat yObj, GLfloat wObj, GLfloat hObj)
{
    return (xMouse > xObj && xMouse < xObj + wObj && yMouse > yObj && yMouse < yObj + hObj);
}

void mouse(int button, int estado, int x, int y)
{
    int alturaMax = glutGet(GLUT_WINDOW_HEIGHT); // Armazena a altura máxima da tela

    // Converte a coordenada y do mouse para o sistema de coordenadas do OpenGL
    int yInvertido = alturaMax - y;

    // Desenha o primeiro retângulo
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && !telaAtual)
    {
        if (isHover(x, yInvertido, xButtonStart, yButtonStart, wButtonStart, hButtonStart)) // Verifica se "iniciar" foi selecionado
        {
            glutSetCursor(GLUT_CURSOR_INHERIT); // Muda para cursor padrão após o click
            changeScreen(GAME_SCREEN);          // Muda para a tela do jogo
        }
    }

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && pause)
    {
        if (isHover(x, yInvertido, xButtonContinue, yButtonContinue, wButtonContinue, hButtonContinue)) // Verifica se "continuar" foi selecionado
        {
            glutSetCursor(GLUT_CURSOR_INHERIT); // Muda para cursor padrão após o click
            changeScreen(GAME_SCREEN);          // Muda para a tela do jogo
        }
    }

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && telaOver)
    {
        if (isHover(x, yInvertido, xButtonContinue, yButtonContinue, wButtonContinue, hButtonContinue)) // Verifica se "recomeçar" foi selecionado
        {
            glutSetCursor(GLUT_CURSOR_INHERIT); // Muda para cursor padrão após o click
            changeScreen(HOME_SCREEN);          // Muda para a tela inicial
        }
    }

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && (pause || telaOver))
    {
        if (isHover(x, yInvertido, xButtonExit, yButtonExit, wButtonExit, hButtonExit)) // Verifica se "sair" foi selecionado tanto na tela de pause, como na tela fim
        {
            exit(0); // Sai do jogo
        }
    }

    // Verifica se o botão "pause" foi clicado
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && !pause && (telaAtual != HOME_SCREEN))
    {
        if (isHover(x, yInvertido, xButtonPause, yButtonPause, wButtonPause, hButtonPause)) // Verifica se "pause" foi selecionado
        {
            pause = 1;                          // Pausa o jogo
            glutSetCursor(GLUT_CURSOR_INHERIT); // Muda para cursor padrão após o click
            changeScreen(GAME_PAUSE_SCREEN);    // Muda para a tela de pause
        }
    }

    glutPostRedisplay();
}

// Verifica a cada movimento do mouse se ele está sobre algum botão para poder mudar o cursor
void passiveMouse(int x, int y)
{
    // Converte a coordenada Y para corresponder ao sistema de coordenadas do GLUT
    y = glutGet(GLUT_WINDOW_HEIGHT) - y;

    // Verifica se o mouse está sobre o botão "iniciar"
    if (isHover(x, y, xButtonStart, yButtonStart, wButtonStart, hButtonStart) && (telaAtual == HOME_SCREEN))
    {
        // Muda o cursor para quando estiver sobre o botão "iniciar"
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    // Verifica se o mouse está sobre o botão "continuar"
    else if (isHover(x, y, xButtonContinue, yButtonContinue, wButtonContinue, hButtonContinue) && pause)
    {
        // Muda o cursor para quando estiver sobre o botão "continuar"
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    // Verifica se o mouse está sobre o botão "recomeçar"
    else if (isHover(x, y, xButtonContinue, yButtonContinue, wButtonContinue, hButtonContinue) && telaOver)
    {
        // Muda o cursor para quando estiver sobre o botão "recomeçar"
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    // Verifica se o mouse está sobre o botão "sair"
    else if (isHover(x, y, xButtonExit, yButtonExit, wButtonExit, hButtonExit) && (pause || telaOver))
    {
        // Muda o cursor para quando estiver sobre o botão "sair"
        glutSetCursor(GLUT_CURSOR_DESTROY);
    }
    // Verifica se o mouse está sobre o botão "pause"
    else if (isHover(x, y, xButtonPause, yButtonPause, wButtonPause, hButtonPause) && !pause && (telaAtual != HOME_SCREEN))
    {
        // Muda o cursor para quando estiver sobre o botão "pause"
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    else
    {
        // Caso contrário, volta para o cursor padrão
        glutSetCursor(GLUT_CURSOR_INHERIT);
    }
}