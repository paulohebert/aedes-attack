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
    drawFrame(BACKGROUND_MENU, currentBackgroundMenuFrame, 10, 10, 0, 0, larguraJanela, alturaJanela);

    // Desenha a logo Aedes Attack
    draw(LOGO, xAedesAttack, yAedesAttack, wAedesAttack, hAedesAttack);

    // Desenha a logo da Univasf
    draw(UNIVASF, xUnivasf, yUnivasf, wUnivasf, hUnivasf);

    // Desenha a placa de mosquito
    draw(MOSQUITO_PROHIBITED, xMosquitoProhibited, yMosquitoProhibited, wMosquitoProhibited, hMosquitoProhibited);

    // Desenha o botão de iniciar
    draw(BUTTON_START, xButtonStart, yButtonStart, wButtonStart, hButtonStart);

    // Desenha o botão de Sobre
    draw(BUTTON_ABOUT, xButtonAbout, yButtonAbout, wButtonAbout, hButtonAbout);

    // Desativa a aplicação de texturas
    glDisable(GL_TEXTURE_2D);

    // Atualiza a tela
    glutSwapBuffers();
}

void segundaTela()
{
    telaAtual = GAME_SCREEN;
    pause = 0;

    // Limpa o buffer de cor e profundidade
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a matriz de modelagem para coordenadas de objeto
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Inicia a aplicação de texturas
    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo
    drawFrame(BACKGROUND_MAIN, currentBackgroundMainFrame, 4, 4, 0, 0, larguraJanela, alturaJanela);

    // Desenha informações de combate ao mosquito
    drawFrame(BANNER_COMBAT_INFO, currentBannerCombatInfoFrame, 8, 8, xBannerDengue, yBannerDengue, wBannerDengue, hBannerDengue);

    // Desenha o botão de Pause
    draw(BUTTON_PAUSE, xButtonPause, yButtonPause, wButtonPause, hButtonPause);

    // Desenha a quantidade de Vida que o jogador tem
    for (int totalHeart = 5; totalHeart; totalHeart--)
    {
        draw(HEART, xHeart + (wHeart * totalHeart) + (totalHeart * offsetHeart), yHeart, wHeart, hHeart);
    }

    // Desenha a plataforma de piso
    draw(PLATFORM, xPlatformFloor, yPlatformFloor, wPlatformFloor, hPlatformFloor);

    // Desenha a plataforma 1
    draw(PLATFORM, xPlatform1, yPlatform1, wPlatform1, hPlatform1);

    // Desenha a plataforma 2
    draw(PLATFORM, xPlatform2, yPlatform2, wPlatform2, hPlatform2);

    // Desenha a plataforma 3
    draw(PLATFORM, xPlatform3, yPlatform3, wPlatform3, hPlatform3);

    // Desenha a plataforma 4
    draw(PLATFORM, xPlatform4, yPlatform4, wPlatform4, hPlatform4);

    // Desenha a plataforma 5
    draw(PLATFORM, xPlatform5, yPlatform5, wPlatform5, hPlatform5);

    // Move o Jogador
    glPushMatrix();
    glTranslatef(translateX, translateY, 0.0);

    // Desenha o player
    drawFrame(PLAYER, currentPlayerFrame, 4, 4, xPlayer, yPlayer, wPlayer, hPlayer);

    glPopMatrix();

    // Desenha o Mosquito
    drawTexture(MOSQUITO_ENEMY, 0.0f, 0.0f, 0.5f, 0.5f, xMosquito, yMosquito, wMosquito, hMosquito);

    glDisable(GL_TEXTURE_2D);

    // Desenha a contagem regressiva
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "Tempo restante: %02d:%02d", tempoRestante / 60, tempoRestante % 60);
    int comprimentoTexto = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)buffer);
    x = (larguraJanela - comprimentoTexto) / 2;
    y = alturaJanela * 0.95;
    glColor3f(1.0f, 1.0f, 1.0f);
    escreveTextoBitmap(x, y, GLUT_BITMAP_HELVETICA_18, buffer);

    glutSwapBuffers();
}

void telaPause()
{
    telaAtual = GAME_PAUSE_SCREEN;
    pause = 1;
    glClear(GL_COLOR_BUFFER_BIT);

    // Matriz de modelagem
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Inicia a aplicação de texturas
    glEnable(GL_TEXTURE_2D);

    // Desenha o plano de fundo
    draw(BACKGROUND_PAUSE, 0, 0, larguraJanela, alturaJanela);

    // Desenha as informações de combate ao mosquito
    drawFrame(BANNER_COMBAT_INFO, currentBannerCombatInfoFrame, 8, 8, xBannerDengueCenter, yBannerDengueCenter, wBannerDengueCenter, hBannerDengueCenter);

    // Desenha o botão de "continue"
    draw(BUTTON_PLAY, xButtonContinue, yButtonContinue, wButtonContinue, hButtonContinue);

    // Desenha o botão de "exit"
    draw(BUTTON_EXIT, xButtonExit, yButtonExit, wButtonExit, hButtonExit);

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
    telaAtual = END_GAME_SCREEN;
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
    /*  largura = 100.0f;
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
     glEnd(); */

    // Atualiza a tela
    glutSwapBuffers();
}