#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <texture.h>

// Variáveis globais para armazenar as dimensões da janela
int larguraJanela, alturaJanela;

int comprimentoTexto;

// Variável global para controlar a tela atual
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela

float x1, y1;
float largura, altura, retX, retY;

void telaInicial()
{
    glClearColor(0.8f, 0.8f, 0.8f, 0.8f);
    glClear(GL_COLOR_BUFFER_BIT);

    loadTexture("../assets/background-city.gif");

    // Habilita o blending para lidar com a transparência alfa
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

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

    glDisable(GL_TEXTURE_2D);

    glDeleteTextures(1, &textureID);

    loadTexture("../assets/aedes-attack.png");

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

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

    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &textureID);

    loadTexture("../assets/mosquito-prohibited-white.png");

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

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
    glDeleteTextures(1, &textureID);

    // Coordenadas para centralizar o retângulo
    largura = 200.0f;
    altura = 120.0f;
    retX = (larguraJanela - largura) / 2;
    retY = (alturaJanela - altura) / 2;


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(retX, retY);
    glVertex2f(retX + largura, retY);
    glVertex2f(retX + largura, retY + altura);
    glVertex2f(retX, retY + altura);
    glEnd();

    // Calcula a posição central para o texto
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"INICIAR");
    float iniciarX = (larguraJanela - comprimentoTexto) / 2;
    float iniciarY = alturaJanela / 2;

    // Desenha o texto centralizado
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(iniciarX, iniciarY, GLUT_BITMAP_HELVETICA_18, "INICIAR");

    glutSwapBuffers();
}

void segundaTela()
{
    glClearColor(0.2f, 0.2f, 0.2f, 0.2f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Calcula a posição central para o texto
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Bem-vindo a segunda tela!");
    x1 = (larguraJanela - comprimentoTexto) / 2;
    y1 = alturaJanela / 2;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x1, y1, GLUT_BITMAP_HELVETICA_18, "Bem-vindo a segunda tela!");


    glutSwapBuffers();
}

void telaPause()
{
    glClearColor(0.2f, 0.2f, 0.6f, 0.2f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Calcula a posição central para o texto
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"JOGO PAUSADO");
    x1 = (larguraJanela - comprimentoTexto) / 2;
    y1 = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x1, y1, GLUT_BITMAP_HELVETICA_18, "JOGO PAUSADO");
    
    // Calcula a posição central para o texto 2
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)"Selecione uma das caixas ou aperte ENTER para sair");
    x1 = (larguraJanela - comprimentoTexto) / 2;
    y1 = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    escreveTextoBitmap(x1, y1-20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas ou aperte ENTER para sair");

    // Coordenadas para centralizar o primeiro retângulo
    largura = 200.0f;
    altura = 100.0f;
    retX = (larguraJanela - largura) / 2;
    retY = ((alturaJanela - altura) / 2) + 60;
    // Desenha o primeiro retângulo
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(retX, retY);
    glVertex2f(retX + largura, retY);
    glVertex2f(retX + largura, retY + altura);
    glVertex2f(retX, retY + altura);
    glEnd();

    // Coordenadas para centralizar o segundo retângulo
    largura = 200.0f;
    altura = 100.0f;
    retX = (larguraJanela - largura) / 2;
    retY = ((alturaJanela - altura) / 2) - 60;
    // Desenha o segundo retângulo
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(retX, retY);
    glVertex2f(retX + largura, retY);
    glVertex2f(retX + largura, retY + altura);
    glVertex2f(retX, retY + altura);
    glEnd();

    glutSwapBuffers();
}

void telaFim ()
{
    glClearColor(0.8f, 0.2f, 0.2f, 0.2f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Calcula a posição central para o texto
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"FIM DE JOGO");
    x1 = (larguraJanela - comprimentoTexto) / 2;
    y1 = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x1, y1, GLUT_BITMAP_HELVETICA_18, "FIM DE JOGO");
    
    // Calcula a posição central para o texto 2
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)"Selecione uma das caixas");
    x1 = (larguraJanela - comprimentoTexto) / 2;
    y1 = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    escreveTextoBitmap(x1, y1-20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas");

    // Coordenadas para centralizar o primeiro retângulo
    largura = 200.0f;
    altura = 100.0f;
    retX = (larguraJanela - largura) / 2;
    retY = ((alturaJanela - altura) / 2) + 60;
    // Desenha o primeiro retângulo
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(retX, retY);
    glVertex2f(retX + largura, retY);
    glVertex2f(retX + largura, retY + altura);
    glVertex2f(retX, retY + altura);
    glEnd();

    // Coordenadas para centralizar o segundo retângulo
    largura = 200.0f;
    altura = 100.0f;
    retX = (larguraJanela - largura) / 2;
    retY = ((alturaJanela - altura) / 2) - 60;
    // Desenha o segundo retângulo
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(retX, retY);
    glVertex2f(retX + largura, retY);
    glVertex2f(retX + largura, retY + altura);
    glVertex2f(retX, retY + altura);
    glEnd();

    glutSwapBuffers();
}