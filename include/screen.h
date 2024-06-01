#ifndef SCREEN_H
#define SCREEN_H

extern int larguraJanela, alturaJanela, telaAtual, telaOver, tempoRestante;
extern const GLuint *textureID;
extern float x, y, largura, altura, retX, retY, retX2, retY2;

void telaInicial();

void segundaTela();

void telaPause ();

void telaFim ();

#endif
