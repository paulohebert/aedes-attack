#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glut.h>
#include <texture.h>

GLuint textureID;

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
    loadTexture(textures[BACKGROUND_MENU], "../assets/background-city.gif");
    loadTexture(textures[BACKGROUND_MAIN], "../assets/background-desert.png");
    loadTexture(textures[LOGO], "../assets/aedes-attack.png");
    loadTexture(textures[MOSQUITO_PROHIBITED], "../assets/mosquito-prohibited-white.png");
    loadTexture(textures[MOSQUITO_ENEMY], "../assets/mosquito.png");
    loadTexture(textures[PLATFORM], "../assets/plataforma2.png");
}