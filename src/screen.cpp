#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <screen.h>
#include <utils.h>
#include <texture.h>
#include <keyboard.h>
#include <physics.h>
#include <position.h>

// Variáveis globais para armazenar as dimensões da janela
int larguraJanela, alturaJanela;

int comprimentoTexto;

// Variáveis globais para controlar a tela
int telaAtual = 0; // 0 para tela inicial, 1 para segunda tela
int telaOver;      // Variável que será responsável pela tela de "game over"

float x, y;
float largura, altura, retXinic, retYinic, retXcont, retYcont, retXexit, retYexit;

void loadingScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f); // Cor branca
    const char *message = "Carregando...";

    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)message);
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela / 2;
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, message);

    glutSwapBuffers();
}

void telaInicial()
{
    telaAtual = HOME_SCREEN;
    
    // Resetar o tempo quando a tela inicial for renderizada
    tempoRestante = 90.0;

    // Limpa o buffer de cor e profundidade
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a matriz de modelagem para coordenadas de objeto
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Inicia a aplicação de texturas
    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo
    drawBackgroundMenu();

    // Desenha a logo Aedes Attack
    draw(LOGO, xAedesAttack, yAedesAttack, wAedesAttack, hAedesAttack);

    // Desenha a placa de mosquito
    draw(MOSQUITO_PROHIBITED, xMosquitoProhibited, yMosquitoProhibited, wMosquitoProhibited, hMosquitoProhibited);

    // Desenha o botão de iniciar
    draw(BUTTON_START, xButtonStart, yButtonStart, wButtonStart, hButtonStart);

    // Desativa a aplicação de texturas
    glDisable(GL_TEXTURE_2D);

    // Atualiza a tela
    glutSwapBuffers();
}

void segundaTela()
{
    telaAtual = GAME_SCREEN;
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

    // Desenha informações de combate ao mosquito

    drawInfos(larguraJanela - 10, alturaJanela - 10, larguraJanela * 0.14, alturaJanela * 0.3);

    // Desenha o botão de play
    largura = 100.0f;
    altura = 100.0f;
    retXinic = 0;
    retYinic = alturaJanela - altura;

    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_PAUSE]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retXinic, retYinic);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retXinic + largura, retYinic);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retXinic + largura, retYinic + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retXinic, retYinic + altura);
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

    drawBoyPlayer(100.0, 45.0, 100.0, 150.0);

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
    glClear(GL_COLOR_BUFFER_BIT);

    // Matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textures[BACKGROUND_PAUSE]);
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

    // Desenha as informações de combate ao mosquito
    drawInfos(larguraJanela / 2 + larguraJanela * 0.15, alturaJanela * 0.6, larguraJanela * 0.3, alturaJanela * 0.55);

    // Coordenadas para desenhar o botão de "continue"
    largura = 100.0f;
    altura = 100.0f;
    retXcont = (larguraJanela - largura) * 0.4;
    retYcont = (alturaJanela - altura) * 0.75;
    // Desenha o botão de "continue"
    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_PLAY]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retXcont, retYcont);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retXcont + largura, retYcont);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retXcont + largura, retYcont + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retXcont, retYcont + altura);
    glEnd();

    // Coordenadas para desenhar o botão de "exit"
    largura = 100.0f;
    altura = 100.0f;
    retXexit = (larguraJanela - largura) * 0.6;
    retYexit = (alturaJanela - altura) * 0.75;
    // Desenha o botão de "exit"
    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_EXIT]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retXexit, retYexit);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retXexit + largura, retYexit);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retXexit + largura, retYexit + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retXexit, retYexit + altura);
    glEnd();

    

    glDisable(GL_TEXTURE_2D);

    // Calcula a posição central para o texto
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"JOGO PAUSADO");
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    glColor3f(0.0f, 0.0f, 0.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, "JOGO PAUSADO");

    // Calcula a posição central para o texto 2
    comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char *)"Selecione uma das caixas ou aperte ENTER para retormar o jogo");
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.9f;
    // Desenha o texto centralizado
    escreveTextoBitmap(x, y - 20, GLUT_BITMAP_HELVETICA_12, "Selecione uma das caixas ou aperte ENTER para retomar o jogo");

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

    // Coordenadas para desenhar o botão de "recomeçar"
    largura = 100.0f;
    altura = 100.0f;
    retXcont = (larguraJanela - largura) * 0.4;
    retYcont = (alturaJanela - altura) * 0.75;
    // Desenha o botão de "recomeçar"
    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_PLAY]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retXcont, retYcont);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retXcont + largura, retYcont);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retXcont + largura, retYcont + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retXcont, retYcont + altura);
    glEnd();

    // Coordenadas para desenhar o botão de "exit"
    largura = 100.0f;
    altura = 100.0f;
    retXexit = (larguraJanela - largura) * 0.6;
    retYexit = (alturaJanela - altura) * 0.75;
    // Desenha o botão de "exit"
    glBindTexture(GL_TEXTURE_2D, textures[BUTTON_EXIT]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(retXexit, retYexit);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(retXexit + largura, retYexit);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(retXexit + largura, retYexit + altura);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(retXexit, retYexit + altura);
    glEnd();

    // Atualiza a tela
    glutSwapBuffers();
}