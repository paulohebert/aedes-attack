#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glut.h>
#include <texture.h>
#include <screen.h>
#include <utils.h>

/* Armazena as todas texturas */
GLuint *textures;

/* Guarda o estado atual do frame da animação  */
int currentBackgroundMenuFrame = 0;   // Background da Tela Inicial
int currentBackgroundMainFrame = 0;   // Background da Tela do Jogo
int currentBannerCombatInfoFrame = 0; // Banner de Combate à dengue
int currentPlayerFrame = 0;           // Personagem do Jogador

void loadTexture(GLuint texture, const char *filename)
{
    int imgWidth, imgHeight, imgChannels;
    unsigned char *imgData;
    // Carrega a imagem usando stb_image
    imgData = stbi_load(filename, &imgWidth, &imgHeight, &imgChannels, STBI_default);
    if (imgData == nullptr)
    {
        fprintf(stderr, "Erro ao carregar a imagem %s\n", filename);
        exit(1);
    }

    glBindTexture(GL_TEXTURE_2D, texture);

    // Define os parâmetros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Carrega a textura para a memória da GPU
    if (imgChannels == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);
    }
    else if (imgChannels == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
    }

    // Libera a imagem carregada da memória RAM
    stbi_image_free(imgData);
}

void initTextures()
{
    // Armazenar o espaço para todas as texturas
    textures = (GLuint *)malloc(sizeof(GLuint) * NUM_TEXTURES);
    glGenTextures(NUM_TEXTURES, textures);

    // Carrega todas as texturas usadas no Jogo
    loadTexture(textures[BACKGROUND_MENU], "../assets/background-city.png");
    loadTexture(textures[BACKGROUND_MAIN], "../assets/background-rain.png");
    loadTexture(textures[BACKGROUND_PAUSE], "../assets/background-terrain.png");
    loadTexture(textures[LOGO], "../assets/aedes-attack.png");
    loadTexture(textures[UNIVASF], "../assets/univasf.png");
    loadTexture(textures[MOSQUITO_PROHIBITED], "../assets/mosquito-prohibited-white.png");
    loadTexture(textures[MOSQUITO_ENEMY], "../assets/mosquito.png");
    loadTexture(textures[PLAYER], "../assets/boy-player.png");
    loadTexture(textures[PLATFORM], "../assets/platform.png");
    loadTexture(textures[BUTTON_PLAY], "../assets/play-green.png");
    loadTexture(textures[BUTTON_START], "../assets/btn-start.png");
    loadTexture(textures[BUTTON_PAUSE], "../assets/pause-verde.png");
    loadTexture(textures[BUTTON_EXIT], "../assets/exit-gray.png");
    loadTexture(textures[BUTTON_ABOUT], "../assets/btn-about.png");
    loadTexture(textures[HEART], "../assets/vida.png");
    loadTexture(textures[BANNER_COMBAT_INFO], "../assets/combat-information.png");
}

/* Função que espera carregar todas as texturas para só depois ir para tela inicial */
void loadTextures(int)
{
    initTextures(); // Carrega as texturas

    // Depois muda a tela de carregando para a tela de início
    glutDisplayFunc(telaInicial);
    glutTimerFunc(70, animateHomeScreenTextures, 0); // Começa a animação da tela inicial
}

/* Libera as texturas da memória */
void freeTextures()
{
    glDeleteTextures(NUM_TEXTURES, textures);
    free(textures);
}

void drawFrame(int textureID, int currentFrame, int totalRow, int totalCol, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    int row = currentFrame / totalRow;
    int col = currentFrame % totalRow;

    float textureX = (float)col / totalRow;
    float textureY = (float)row / totalCol;
    float frameRatioX = 1.0f / totalRow;
    float frameRatioY = 1.0f / totalCol;

    drawTexture(textureID, textureX, textureY, frameRatioX, frameRatioY, x, y, width, height);
}

// Função que Desenha uma imagem que tem o controle do recorte sobre a textura
void drawTexture(int textureID, GLfloat xTexture, GLfloat yTexture, GLfloat wTexture, GLfloat hTexture, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    glBindTexture(GL_TEXTURE_2D, textures[textureID]); // Aplica a textura
    glBegin(GL_QUADS);
    glTexCoord2f(xTexture, yTexture + hTexture);
    glVertex2f(x, y);
    glTexCoord2f(xTexture + wTexture, yTexture + hTexture);
    glVertex2f(x + width, y);
    glTexCoord2f(xTexture + wTexture, yTexture);
    glVertex2f(x + width, y + height);
    glTexCoord2f(xTexture, yTexture);
    glVertex2f(x, y + height);
    glEnd();
}

// Função que Desenha uma imagem usando a textura completa
void draw(int textureID, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    drawTexture(textureID, 0.0f, 0.0f, 1.0f, 1.0f, x, y, width, height);
}
