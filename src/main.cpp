#include <GL/glut.h>
#include <keyboard.h>
#include <mouse.h>
#include <screen.h>
#include <texture.h>
#include <utils.h>
#include <position.h>

// Inicializa o que precisa ser usado no jogo
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Habilita o blending para lidar com a transparência alfa
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

// Função de limpeza
void Cleanup()
{
    freeTextures();
}

void alteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Atualiza as variáveis globais com as novas dimensões
    larguraJanela = w;
    alturaJanela = h;

    // Evita a divisão por zero
    if (h == 0)
        h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, larguraJanela, alturaJanela);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, larguraJanela, 0.0, alturaJanela);
    updatePosition();
}

int main(int argc, char **argv)
{
    // Inicializa o GLUT
    glutInit(&argc, argv);

    // Define o modo de operação da GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Aedes Attack");

    // Faz a janela entrar em modo de tela cheia
    glutFullScreen();

    // Inicia na tela de Carregamento
    changeScreen(LOADING_SCREEN);

    // Registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(alteraTamanhoJanela);

    // Registra a função callback para tratamento das teclas ASCII
    glutKeyboardFunc(teclado);

    // Registra a função callback para tratamento das teclas especiais
    glutSpecialFunc(teclasEspeciais);

    // Registra a função callback para tratamento das teclas especiais com duas teclas pressionadas
    glutSpecialUpFunc(specialKeysUp);

    // Registra a função callback para tratamento dos botões do mouse
    glutMouseFunc(mouse);

    // Registra a função callback para alterar o cursor do mouse quando estiver sobre um objeto
    glutPassiveMotionFunc(passiveMouse);

    // Registra a função callback que será chamada para trocar a tela de carregando após carregar as texturas
    glutTimerFunc(100, loadTextures, 0);

    // Inicia o que precisa no jogo
    init();

    // Limpa as texturas ao dar exit no jogo
    atexit(Cleanup);

    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();

    return 0;
}
