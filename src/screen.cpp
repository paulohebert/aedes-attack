#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

// Variáveis globais para armazenar as dimensões da janela
int larguraJanela = 800;
int alturaJanela = 600;

// Variável global para controlar a tela atual
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela

void telaInicial()
{
    glClearColor(0.8f, 0.8f, 0.8f, 0.8f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Configura o sistema de coordenadas para o sistema de coordenadas do mundo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, larguraJanela, 0.0, alturaJanela);

    // Volta para a matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Calcula a posição central para o texto
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Pressione ENTER para iniciar o jogo...");
    float x = (larguraJanela - comprimentoTexto) / 2;
    float y = alturaJanela / 2;

    // Desenha o texto centralizado
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "Pressione ENTER para iniciar o jogo...");
    glFlush();
}

void segundaTela()
{
    glClearColor(0.2f, 0.2f, 0.2f, 0.2f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Configura o sistema de coordenadas para o sistema de coordenadas do mundo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, larguraJanela, 0.0, alturaJanela);

    // Volta para a matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Calcula a posição central para o texto
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Bem-vindo a segunda tela!");
    float x = (larguraJanela - comprimentoTexto) / 2;
    float y = alturaJanela / 2;

    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "Bem-vindo a segunda tela!");
    glFlush();
}