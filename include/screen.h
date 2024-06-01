#ifndef SCREEN_H
#define SCREEN_H

extern int larguraJanela, alturaJanela, telaAtual, telaOver;
extern const GLuint *textureID;
extern float largura, altura, retXinic, retYinic, retXcont, retYcont, retXexit, retYexit;

void loadingScreen();

void telaInicial();

void segundaTela();

void telaPause();

void telaFim();

#endif
