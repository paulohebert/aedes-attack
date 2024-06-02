#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <texture.h>
#include <keyboard.h>
#include <physics.h>

int tempoRestante=90;

// Função para desenhar texto na tela

void escreveTextoBitmap(float x, float y, void *fonte, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(fonte, *c);
}

    // Callback para a contagem regressiva
void atualizaTempo(int value)
{
    if (pause)
    {
        glutTimerFunc(1000, atualizaTempo, 0); // Reagenda o timer mesmo quando pausado
        return;
    }
    if (tempoRestante > 0)
    {
        tempoRestante--;
        glutPostRedisplay();
        glutTimerFunc(1000, atualizaTempo, 0);
    }
}

void atualizaMovimento(int)
{
    moveObjetos();
    glutTimerFunc(16, atualizaMovimento, 0);
}