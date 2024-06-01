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
int telaOver;

// Variável global para controlar a tela atual
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela

float x, y;
float largura, altura, retX, retY;

void loadingScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);

    const char *message = "Carregando...";

    glPushMatrix();

    comprimentoTexto = glutStrokeLength(GLUT_STROKE_ROMAN, (const unsigned char *)message);
    float x = (larguraJanela - comprimentoTexto * 0.5) / 2;
    float y = alturaJanela / 2;

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(x, y, 0);
    glScalef(0.5f, 0.5f, 1.0f);

    for (const char *ch = message; *ch != '\0'; ch++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *ch);
    }

    glPopMatrix();

    glutSwapBuffers();
}

void telaInicial()
{
    // Limpa o buffer de cor e profundidade
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a matriz de modelagem para coordenadas de objeto
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo

    drawBackgroundMenu();

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

    // Coordenadas para centralizar o primeiro retângulo
    largura = 100.0f;
    altura = 100.0f;
    retX = (larguraJanela - largura) / 2;
    retY = ((alturaJanela - altura) / 2);

    // Desenha o botão de play
    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_PLAY]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retX, retY);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retX + largura, retY);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retX + largura, retY + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retX, retY + altura);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Calcula a posição central para o texto
    // comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"INICIAR");
    // float iniciarX = (larguraJanela - comprimentoTexto) / 2;
    // float iniciarY = alturaJanela / 2;

    // Desenha o texto centralizado
    // glColor3f(0.0f, 0.0f, 0.0f);
    // escreveTextoBitmap(iniciarX, iniciarY, GLUT_BITMAP_HELVETICA_18, "INICIAR");

    // Atualiza a tela
    glutSwapBuffers();
}

void segundaTela()
{
    telaAtual = 1;
    pause = 0;
    glClearColor(0.2f, 0.7f, 0.2f, 0.2f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Configura o sistema de coordenadas para o sistema de coordenadas do mundo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, larguraJanela, 0.0, alturaJanela);

    // Volta para a matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Inicia a aplicação de texturas
    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo

    drawBackgroundMain();

    // Desenha o botão de play

    largura = 100.0f;
    altura = 100.0f;
    retX = 0;
    retY = alturaJanela - altura;

    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_PLAY]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retX, retY);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retX + largura, retY);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retX + largura, retY + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retX, retY + altura);
    glEnd();

    // Desenha a plataforma 0
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0, -5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela, -5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela, 50);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0, 50);
    glEnd();

    // Desenha a plataforma 1
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.1, alturaJanela * 0.2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.1 + 300, alturaJanela * 0.2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.1 + 300, alturaJanela * 0.2 + 50);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.1, alturaJanela * 0.2 + 50);
    glEnd();

    // Desenha a plataforma 2
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.3 + 450, alturaJanela * 0.4);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.3 + 450, alturaJanela * 0.4 + 50);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.3, alturaJanela * 0.4 + 50);
    glEnd();

    // Desenha a plataforma 3
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.6, alturaJanela * 0.6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.6 + 300, alturaJanela * 0.6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.6 + 300, alturaJanela * 0.6 + 50);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.6, alturaJanela * 0.6 + 50);
    glEnd();

    // Desenha a plataforma 4
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.08, alturaJanela * 0.6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.08 + 300, alturaJanela * 0.6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.08 + 300, alturaJanela * 0.6 + 50);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.08, alturaJanela * 0.6 + 50);
    glEnd();

    // Desenha a plataforma 5
    glBindTexture(GL_TEXTURE_2D, textures[PLATFORM]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(larguraJanela * 0.8, alturaJanela * 0.3);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(larguraJanela * 0.8 + 300, alturaJanela * 0.3);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(larguraJanela * 0.8 + 300, alturaJanela * 0.3 + 50);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela * 0.8, alturaJanela * 0.3 + 50);
    glEnd();

    glPushMatrix();
    glTranslatef(translateX, translateY, 0.0);

    // Desenha o player
    glBindTexture(GL_TEXTURE_2D, textures[MOSQUITO_ENEMY]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.5f);
    glVertex2f(larguraJanela / 2 - 50, alturaJanela * 0.5 - 380);
    glTexCoord2f(0.5f, 0.5f);
    glVertex2f(larguraJanela / 2 + 50, alturaJanela * 0.5 - 380);
    glTexCoord2f(0.5f, 0.0f);
    glVertex2f(larguraJanela / 2 + 50, alturaJanela * 0.5 - 280);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(larguraJanela / 2 - 50, alturaJanela * 0.5 - 280);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    // Desenha a contagem regressiva
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "Tempo restante: %02d:%02d", tempoRestante / 60, tempoRestante % 60);
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)buffer);
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela - 50;
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, buffer);

    glutSwapBuffers();
}

void telaPause()
{
    pause = 1;
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
    escreveTextoBitmap(x, y - 20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas ou aperte ENTER para sair");

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

void telaFim()
{
    telaOver = 1;
    pause = 0;
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
    escreveTextoBitmap(x, y - 20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas");

    // Coordenadas para centralizar horizontalmente o primeiro retângulo
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

    // Coordenadas para centralizar horizontalmente o segundo retângulo
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

    // Atualiza a tela
    glutSwapBuffers();
}