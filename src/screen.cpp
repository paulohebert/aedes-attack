#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <texture.h>
#include <keyboard.h>

// Variáveis globais para armazenar as dimensões da janela
int larguraJanela;
int alturaJanela;

// Variável global para controlar a tela atual
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela

void telaInicial()
{
    // Limpa o buffer de cor e profundidade
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a matriz de modelagem para coordenadas de objeto
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo
    glBindTexture(GL_TEXTURE_2D, textures[BACKGROUND_MENU]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela, alturaJanela);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, alturaJanela);
    glEnd();

    // Desenha a logo Aedes Attack
    glBindTexture(GL_TEXTURE_2D, textures[LOGO]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.7);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.7, alturaJanela * 0.7);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.7, alturaJanela * 0.7 + 200);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.7 + 200);
    glEnd();

    // Desenha a placa de mosquito
    glBindTexture(GL_TEXTURE_2D, textures[MOSQUITO_PROHIBITED]);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.45, alturaJanela * 0.62);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.55, alturaJanela * 0.62);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.55, alturaJanela * 0.62 + 200);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.45, alturaJanela * 0.62 + 200);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.45);
    glVertex2f(larguraJanela * 0.7, alturaJanela * 0.45);
    glVertex2f(larguraJanela * 0.7, alturaJanela * 0.55);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.55);
    glEnd();

    // Calcula a posição central para o texto
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Pressione ENTER para iniciar o jogo...");
    float x = (larguraJanela - comprimentoTexto) / 2;
    float y = alturaJanela / 2;

    // Desenha o texto centralizado
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "Pressione ENTER para iniciar o jogo...");

    // Atualiza a tela
    glutSwapBuffers();
}

void segundaTela()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Configura o sistema de coordenadas para o sistema de coordenadas do mundo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, larguraJanela, 0.0, alturaJanela);

    // Volta para a matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo
    glBindTexture(GL_TEXTURE_2D, textures[BACKGROUND_MAIN]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela, alturaJanela);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, alturaJanela);
    glEnd();

    // Desenha a plataforma
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.5, alturaJanela * 0.7);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.5 + 300, alturaJanela * 0.7);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.5 + 300, alturaJanela * 0.7 + 100);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.5, alturaJanela * 0.7 + 100);
    glEnd();

    // Desenha a plataforma
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.1, alturaJanela * 0.4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.1 + 300, alturaJanela * 0.4);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.1 + 300, alturaJanela * 0.4 + 100);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.1, alturaJanela * 0.4 + 100);
    glEnd();

    glPushMatrix();
    glTranslatef(translateX, translateY, 0.0);

    // Desenha a Mosquito
    glBindTexture(GL_TEXTURE_2D, textures[MOSQUITO_ENEMY]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.5f);
    glVertex2f(larguraJanela * 0.2, alturaJanela * 0.5);
    glTexCoord2f(0.5f, 0.5f);
    glVertex2f(larguraJanela * 0.2 + 100, alturaJanela * 0.5);
    glTexCoord2f(0.5f, 0.0f);
    glVertex2f(larguraJanela * 0.2 + 100, alturaJanela * 0.5 + 100);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.2, alturaJanela * 0.5 + 100);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    // Calcula a posi��o central para o texto
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Bem-vindo a segunda tela!");
    float x = (larguraJanela - comprimentoTexto) / 2;
    float y = alturaJanela / 2;

    // Desenha o texto centralizado
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "Bem-vindo a segunda tela!");

    // Atualiza a tela
    glutSwapBuffers();
}