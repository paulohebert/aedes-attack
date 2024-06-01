#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glut.h>
#include <texture.h>
#include <screen.h>

GLuint *textures;

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
    textures = (GLuint *)malloc(sizeof(GLuint) * NUM_TEXTURES);
    glGenTextures(NUM_TEXTURES, textures);
    loadTexture(textures[BACKGROUND_MENU], "../assets/background-city.png");
    loadTexture(textures[BACKGROUND_MAIN], "../assets/background-rain.png");
    loadTexture(textures[BACKGROUND_PAUSE], "../assets/background-terrain.png");
    loadTexture(textures[LOGO], "../assets/aedes-attack.png");
    loadTexture(textures[MOSQUITO_PROHIBITED], "../assets/mosquito-prohibited-white.png");
    loadTexture(textures[MOSQUITO_ENEMY], "../assets/mosquito.png");
    loadTexture(textures[PLAYER], "../assets/boy-player.png");
    loadTexture(textures[PLATFORM], "../assets/platform.png");
    loadTexture(textures[BUTTON_PLAY], "../assets/play-green.png");
    loadTexture(textures[BUTTON_START], "../assets/btn-start.png");
    loadTexture(textures[BUTTON_PAUSE], "../assets/pause-verde.png");
    loadTexture(textures[BUTTON_EXIT], "../assets/exit-gray.png");
    loadTexture(textures[COMBAT_INFO], "../assets/combat-information.png");
}

void animateTextures(int)
{
    glutPostRedisplay();
    glutTimerFunc(100, animateTextures, 0);
}

void loadTextures(int)
{
    initTextures();
    glutDisplayFunc(telaInicial);

    glutTimerFunc(100, animateTextures, 0);
}

int currentBackgroundMenuFrame = 0;
int backgroundMenuFrames = 96;

void drawBackgroundMenu()
{
    currentBackgroundMenuFrame = (currentBackgroundMenuFrame + 1) % backgroundMenuFrames;

    int row = currentBackgroundMenuFrame / 10;
    int col = currentBackgroundMenuFrame % 10;

    float textureX = (float)col / 10.0f;
    float textureY = (float)row / 10.0f;
    float frameRatio = 1.0f / 10.0f;

    glBindTexture(GL_TEXTURE_2D, textures[BACKGROUND_MENU]);
    glBegin(GL_QUADS);
    glTexCoord2f(textureX, textureY + frameRatio);
    glVertex2f(0.0f, 0.0f);
    glTexCoord2f(textureX + frameRatio, textureY + frameRatio);
    glVertex2f(larguraJanela, 0.0f);
    glTexCoord2f(textureX + frameRatio, textureY);
    glVertex2f(larguraJanela, alturaJanela);
    glTexCoord2f(textureX, textureY);
    glVertex2f(0.0f, alturaJanela);
    glEnd();
}

int currentBackgroundMainFrame = 0;
int backgroundMainFrames = 16;

void drawBackgroundMain()
{
    currentBackgroundMainFrame = (currentBackgroundMainFrame + 1) % backgroundMainFrames;

    int row = currentBackgroundMainFrame / 4;
    int col = currentBackgroundMainFrame % 4;

    float textureX = (float)col / 4.0f;
    float textureY = (float)row / 4.0f;
    float frameRatio = 1.0f / 4.0f;

    glBindTexture(GL_TEXTURE_2D, textures[BACKGROUND_MAIN]);
    glBegin(GL_QUADS);
    glTexCoord2f(textureX, textureY + frameRatio);
    glVertex2f(0.0f, 0.0f);
    glTexCoord2f(textureX + frameRatio, textureY + frameRatio);
    glVertex2f(larguraJanela, 0.0f);
    glTexCoord2f(textureX + frameRatio, textureY);
    glVertex2f(larguraJanela, alturaJanela);
    glTexCoord2f(textureX, textureY);
    glVertex2f(0.0f, alturaJanela);
    glEnd();
}

int currentInfosFrame = 0;
int infosFrames = 61;
int delay = 0;

void drawInfos(float x, float y, float width, float height)
{
    if (delay == 4)
    {
        delay = -1;
        currentInfosFrame = (currentInfosFrame + 1) % infosFrames;
    }
    delay++;
    int row = currentInfosFrame / 8;
    int col = currentInfosFrame % 8;

    float textureX = (float)col / 8.0f;
    float textureY = (float)row / 8.0f;
    float frameRatio = 1.0f / 8.0f;

    glBindTexture(GL_TEXTURE_2D, textures[COMBAT_INFO]);
    glBegin(GL_QUADS);
    glTexCoord2f(textureX, textureY + frameRatio);
    glVertex2f(x - width, y - height);
    glTexCoord2f(textureX + frameRatio, textureY + frameRatio);
    glVertex2f(x, y - height);
    glTexCoord2f(textureX + frameRatio, textureY);
    glVertex2f(x, y);
    glTexCoord2f(textureX, textureY);
    glVertex2f(x - width, y);
    glEnd();
}

int currentBoyPlayerFrame = 0;
int boyPlayerFrames = 15;

void drawBoyPlayer(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    currentBoyPlayerFrame = (currentBoyPlayerFrame + 1) % boyPlayerFrames;

    int row = currentBoyPlayerFrame / 4;
    int col = currentBoyPlayerFrame % 4;

    float textureX = (float)col / 4.0f;
    float textureY = (float)row / 4.0f;
    float frameRatio = 1.0f / 4.0f;

    glBindTexture(GL_TEXTURE_2D, textures[PLAYER]);
    glBegin(GL_QUADS);
    glTexCoord2f(textureX, textureY + frameRatio);
    glVertex2f(x, y);
    glTexCoord2f(textureX + frameRatio, textureY + frameRatio);
    glVertex2f(x + width, y);
    glTexCoord2f(textureX + frameRatio, textureY);
    glVertex2f(x + width, y + height);
    glTexCoord2f(textureX, textureY);
    glVertex2f(x, y + height);
    glEnd();
}

void draw(int textureID, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    glBindTexture(GL_TEXTURE_2D, textures[textureID]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(x, y);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(x + width, y);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(x + width, y + height);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(x, y + height);
    glEnd();
}