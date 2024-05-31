#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <texture.h>
#include <keyboard.h>

// Variáveis globais para armazenar as dimensões da janela
int larguraJanela, alturaJanela;

GLuint textureID;
int comprimentoTexto;

// Variável global para controlar a tela atual
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela

float x, y;
float largura, altura, retX, retY;

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

    glDeleteTextures(1, &textureID);

    // Coordenadas para centralizar o retângulo
    largura = 200.0f;
    altura = 120.0f;
    retX = (larguraJanela - largura) / 2;
    retY = (alturaJanela - altura) / 2;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.45);
    glVertex2f(larguraJanela * 0.7, alturaJanela * 0.45);
    glVertex2f(larguraJanela * 0.7, alturaJanela * 0.55);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.55);
    glEnd();

    // Calcula a posição central para o texto

    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"INICIAR");
    float iniciarX = (larguraJanela - comprimentoTexto) / 2;
    float iniciarY = alturaJanela / 2;

    // Desenha o texto centralizado
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "INICIAR");

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

    // Calcula a posição central para o texto
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Bem-vindo a segunda tela!");
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela / 2;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "Bem-vindo a segunda tela!");


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
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "JOGO PAUSADO");
    
    // Calcula a posição central para o texto 2
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)"Selecione uma das caixas ou aperte ENTER para sair");
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    escreveTextoBitmap(x, y-20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas ou aperte ENTER para sair");

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
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "FIM DE JOGO");
    
    // Calcula a posição central para o texto 2
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)"Selecione uma das caixas");
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    escreveTextoBitmap(x, y-20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas");

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