#ifndef SCREEN_H
#define SCREEN_H

extern int larguraJanela;
extern int alturaJanela;
extern int telaAtual;
extern int telaOver;
extern int tempoRestante;
extern const GLuint *textureID;

void telaInicial();

void segundaTela();

void telaPause ();

void telaFim ();

#endif
