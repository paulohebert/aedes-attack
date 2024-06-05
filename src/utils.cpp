#include <GL/glut.h>
#include <stdlib.h>
#include <screen.h>
#include <texture.h>
#include <keyboard.h>
#include <physics.h>

int tempoRestante = 90;

// Função para desenhar texto na tela
void escreveTextoBitmap(float x, float y, void *fonte, const char *string)
{
    int comprimentoTexto = glutBitmapLength(fonte, (const unsigned char *)string);
    const char *c;
    glRasterPos2f(x - comprimentoTexto / 2, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(fonte, *c);
}

// Callback para a contagem regressiva
void atualizaTempo(int value)
{
    if (pause)
    {
        glutTimerFunc(1000, atualizaTempo, 0); // Reagenda o timer mesmo quando pausado
        return;
    }
    if (tempoRestante > 0)
    {
        tempoRestante--;
        glutPostRedisplay();
        glutTimerFunc(1000, atualizaTempo, 0);
    }
}

void atualizaMovimento(int)
{
    moveObjetos();
    glutTimerFunc(10, atualizaMovimento, 0);
}

void atualizaMosquitos(int){
    adicionaMosquito();
    glutTimerFunc(5000, atualizaMosquitos, 0);
}

/* Atualiza os frames das texturas da tela inicial */
void animateHomeScreenTextures(int)
{
    /* Evita que a animação continue quando trocar de tela */
    if (telaAtual == HOME_SCREEN)
    {
        // Altera para o próximo frame do plano de fundo da tela inicial
        currentBackgroundMenuFrame = (currentBackgroundMenuFrame + 1) % BACKGROUND_MENU_TOTAL_FRAMES;

        glutPostRedisplay();                             // Redesenha a tela
        glutTimerFunc(70, animateHomeScreenTextures, 0); // Loop
    }
}

/* Atualiza os frames das texturas da tela do jogo */
void animateGameScreenTextures(int)
{
    /* Evita que a animação continue quando trocar de tela */
    if (telaAtual == GAME_SCREEN)
    {
        // Altera para o próximo frame do plano de fundo da tela do jogo
        currentBackgroundMainFrame = (currentBackgroundMainFrame + 1) % BACKGROUND_MAIN_TOTAL_FRAMES;

        // Altera para o próximo frame do personagem do jogador
        currentPlayerFrame = (currentPlayerFrame + 1) % PLAYER_TOTAL_FRAMES;

        // Adiciona um delay na animação do banner para não ficar passando muito rápido
        static int delay = 4;
        if (delay-- == 0)
        {
            // Altera para o próximo frame do banner de combate à dengue
            currentBannerCombatInfoFrame = (currentBannerCombatInfoFrame + 1) % BANNER_COMBAT_INFO_TOTAL_FRAMES;
            delay = 4;
        }

        glutPostRedisplay();                              // Redesenha a tela
        glutTimerFunc(100, animateGameScreenTextures, 0); // Loop
    }
}

/* Atualiza os frames das texturas da tela de pause do jogo */
void animateGamePauseScreenTextures(int)
{
    /* Evita que a animação continue quando trocar de tela */
    if (telaAtual == GAME_PAUSE_SCREEN)
    {
        // Altera para o próximo frame do banner de combate à dengue
        currentBannerCombatInfoFrame = (currentBannerCombatInfoFrame + 1) % BANNER_COMBAT_INFO_TOTAL_FRAMES;

        glutPostRedisplay();                                   // Redesenha a tela
        glutTimerFunc(400, animateGamePauseScreenTextures, 0); // Loop
    }
}

/* Atualiza os frames das texturas da tela de fim de jogo */
void animateEndGameScreenTextures(int)
{
    /* Evita que a animação continue quando trocar de tela */
    if (telaAtual == END_GAME_SCREEN)
    {
        // Altera para o próximo frame do mosquito na tela de fim de jogo
        currentMosquitoGameOverFrame = (currentMosquitoGameOverFrame + 1) % MOSQUITO_GAME_OVER_TOTAL_FRAMES;

        glutPostRedisplay();                                   // Redesenha a tela
        glutTimerFunc(50, animateEndGameScreenTextures, 0); // Loop
    }
}