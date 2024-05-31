#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <texture.h>

// Variáveis globais para armazenar as dimensões da janela
int larguraJanela;
int alturaJanela;

// Variável global para controlar a tela atual
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela

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
    float largura = 200.0f;
    float altura = 120.0f;
    float retX = (larguraJanela - largura) / 2;
    float retY = (alturaJanela - altura) / 2;


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(retX, retY);
    glVertex2f(retX + largura, retY);
    glVertex2f(retX + largura, retY + altura);
    glVertex2f(retX, retY + altura);
    glEnd();


    // Calcula a posição central para o texto
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"INICIAR");
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
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Bem-vindo a segunda tela!");
    float x = (larguraJanela - comprimentoTexto) / 2;
    float y = alturaJanela / 2;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "Bem-vindo a segunda tela!");

    
    glutSwapBuffers();
}