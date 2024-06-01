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
    wButtonStart = 400.0f; // Largura
    hButtonStart = 125.0f; // Altura
    xButtonStart = centerPosition(wButtonStart, larguraJanela); // Posição X
    yButtonStart = centerPosition(hButtonStart, alturaJanela);; // Posição Y

}