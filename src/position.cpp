#include <GL/glut.h>
#include <screen.h>

// --------------------------------------------------------------- //
// Tela de Início

// Posição da Logo do Jogo Aedes Attack
GLfloat xAedesAttack; // Posição X
GLfloat yAedesAttack; // Posição Y
GLfloat wAedesAttack; // Largura
GLfloat hAedesAttack; // Altura

// Posição da Placa de Proibido Mosquito
GLfloat xMosquitoProhibited; // Posição X
GLfloat yMosquitoProhibited; // Posição Y
GLfloat wMosquitoProhibited; // Largura
GLfloat hMosquitoProhibited; // Altura

// Posição do Botão de Iniciar do Jogo
GLfloat xButtonStart; // Posição X
GLfloat yButtonStart; // Posição Y
GLfloat wButtonStart; // Largura
GLfloat hButtonStart; // Altura

// --------------------------------------------------------------- //
// Tela do Jogo

// Posição do Botão de Pause do Jogo
GLfloat xButtonPause; // Posição X
GLfloat yButtonPause; // Posição Y
GLfloat wButtonPause; // Largura
GLfloat hButtonPause; // Altura

// Posição do Banner de Combate à Dengue
GLfloat xBannerDengue; // Posição X
GLfloat yBannerDengue; // Posição Y
GLfloat wBannerDengue; // Largura
GLfloat hBannerDengue; // Altura

// Posição do Jogador
GLfloat xPlayer; // Posição X
GLfloat yPlayer; // Posição Y
GLfloat wPlayer; // Largura
GLfloat hPlayer; // Altura

// Posição do Mosquito
GLfloat xMosquito; // Posição X
GLfloat yMosquito; // Posição Y
GLfloat wMosquito; // Largura
GLfloat hMosquito; // Altura

// Posição da Plataforma de Piso do Chão
GLfloat xPlatformFloor; // Posição X
GLfloat yPlatformFloor; // Posição Y
GLfloat wPlatformFloor; // Largura
GLfloat hPlatformFloor; // Altura

// Posição da Plataforma Suspensa 1
GLfloat xPlatform1; // Posição X
GLfloat yPlatform1; // Posição Y
GLfloat wPlatform1; // Largura
GLfloat hPlatform1; // Altura

// Posição da Plataforma Suspensa 2
GLfloat xPlatform2; // Posição X
GLfloat yPlatform2; // Posição Y
GLfloat wPlatform2; // Largura
GLfloat hPlatform2; // Altura

// Posição da Plataforma Suspensa 3
GLfloat xPlatform3; // Posição X
GLfloat yPlatform3; // Posição Y
GLfloat wPlatform3; // Largura
GLfloat hPlatform3; // Altura

// Posição da Plataforma Suspensa 4
GLfloat xPlatform4; // Posição X
GLfloat yPlatform4; // Posição Y
GLfloat wPlatform4; // Largura
GLfloat hPlatform4; // Altura

// Posição da Plataforma Suspensa 5
GLfloat xPlatform5; // Posição X
GLfloat yPlatform5; // Posição Y
GLfloat wPlatform5; // Largura
GLfloat hPlatform5; // Altura

// --------------------------------------------------------------- //
// Tela de Pause

// --------------------------------------------------------------- //
// Tela de Fim de Jogo

// --------------------------------------------------------------- //

// Centralizar o objeto em X ou Y
GLfloat centerPosition(GLfloat objSize, GLfloat windowSize)
{
    return (windowSize - objSize) / 2;
}

// Atualizar a Posição quando redimensionar a tela (Assim, não há a necessidade de ficar recalculando a cada atualização dos frames)
void updatePosition()
{

    // --------------------------------------------------------------- //
    // Tela de Início

    // Posição da Logo do Jogo Aedes Attack
    xAedesAttack = larguraJanela * 0.3; // Posição X
    yAedesAttack = alturaJanela * 0.7;  // Posição Y
    wAedesAttack = larguraJanela * 0.4; // Largura
    hAedesAttack = alturaJanela * 0.2;  // Altura

    // Posição da Placa de Proibido Mosquito
    xMosquitoProhibited = larguraJanela * 0.45; // Posição X
    yMosquitoProhibited = alturaJanela * 0.62;  // Posição Y
    wMosquitoProhibited = larguraJanela * 0.1;  // Largura
    hMosquitoProhibited = larguraJanela * 0.1;  // Altura

    // Posição do Botão de Iniciar do Jogo
    wButtonStart = 400.0f;                                      // Largura
    hButtonStart = 125.0f;                                      // Altura
    xButtonStart = centerPosition(wButtonStart, larguraJanela); // Posição X
    yButtonStart = centerPosition(hButtonStart, alturaJanela);  // Posição Y

    // --------------------------------------------------------------- //
    // Tela do Jogo

    // Posição do Botão de Pause do Jogo
    wButtonPause = alturaJanela * 0.1;          // Largura
    hButtonPause = alturaJanela * 0.1;          // Altura
    xButtonPause = 0;                           // Posição X
    yButtonPause = alturaJanela - hButtonPause; // Posição Y

    // Posição do Banner de Combate à Dengue
    wBannerDengue = larguraJanela * 0.14;               // Largura
    hBannerDengue = alturaJanela * 0.3;                 // Altura
    xBannerDengue = larguraJanela - wBannerDengue - 10; // Posição X
    yBannerDengue = alturaJanela - hBannerDengue - 10;  // Posição Y

    // Posição da Plataforma de Piso do Chão
    xPlatformFloor = 0;                    // Posição X
    yPlatformFloor = alturaJanela * -0.01; // Posição Y
    wPlatformFloor = larguraJanela;        // Largura
    hPlatformFloor = alturaJanela * 0.05;  // Altura

    // Posição da Plataforma Suspensa 1
    xPlatform1 = larguraJanela * 0.1; // Posição X
    yPlatform1 = alturaJanela * 0.2;  // Posição Y
    wPlatform1 = larguraJanela * 0.2; // Largura
    hPlatform1 = alturaJanela * 0.05; // Altura

    // Posição da Plataforma Suspensa 2
    xPlatform2 = larguraJanela * 0.35; // Posição X
    yPlatform2 = alturaJanela * 0.4;   // Posição Y
    wPlatform2 = larguraJanela * 0.2;  // Largura
    hPlatform2 = alturaJanela * 0.05;  // Altura

    // Posição da Plataforma Suspensa 3
    xPlatform3 = larguraJanela * 0.6;  // Posição X
    yPlatform3 = alturaJanela * 0.6;   // Posição Y
    wPlatform3 = larguraJanela * 0.17; // Largura
    hPlatform3 = alturaJanela * 0.05;  // Altura

    // Posição da Plataforma Suspensa 4
    xPlatform4 = larguraJanela * 0.05; // Posição X
    yPlatform4 = alturaJanela * 0.6;   // Posição Y
    wPlatform4 = larguraJanela * 0.17; // Largura
    hPlatform4 = alturaJanela * 0.05;  // Altura

    // Posição da Plataforma Suspensa 5
    xPlatform5 = larguraJanela * 0.7;  // Posição X
    yPlatform5 = alturaJanela * 0.3;   // Posição Y
    wPlatform5 = larguraJanela * 0.22; // Largura
    hPlatform5 = alturaJanela * 0.05;  // Altura

    // Posição do Jogador
    xPlayer = larguraJanela * 0.1;                   // Posição X
    yPlayer = yPlatformFloor + hPlatformFloor * 0.8; // Posição Y
    wPlayer = alturaJanela * 0.1;                    // Largura
    hPlayer = alturaJanela * 0.16;                   // Altura

    // Posição do Mosquito
    xMosquito = larguraJanela * 0.45; // Posição X
    yMosquito = alturaJanela * 0.17;  // Posição Y
    wMosquito = alturaJanela * 0.1;   // Largura
    hMosquito = alturaJanela * 0.1;   // Altura

    // --------------------------------------------------------------- //
    // Tela de Pause

    // --------------------------------------------------------------- //
    // Tela de Fim de Jogo

    // --------------------------------------------------------------- //
}