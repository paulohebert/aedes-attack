#include <GL/glut.h>
#include <keyboard.h>
#include <screen.h>

bool playerNoChao;
GLfloat gravity = 0.5;
GLfloat speedJump = 0;

bool verificaColisaoEsquerda(){
    if (!(translateX < -larguraJanela * 0.5 + 500 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 150 &&  // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&  // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)
        &&
        !(translateX < -larguraJanela * 0.5 + 500 &&  // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 150 &&  // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&  // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)) {  // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        return true;
    }
    return false;
}

bool verificaColisaoDireita(){
    if (!(translateX < -larguraJanela * 0.5 + 450 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 100 &&  // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&  // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)) {  // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        return true;
    }
    return false;
}

bool verificaColisaoEmbaixo(){
    if (!(translateX < -larguraJanela * 0.5 + 490 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 110 &&  // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 &&  // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)) {  // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        return true;
    }
    return false;
}

bool verificaColisaoCima(){
    if (!(translateX < -larguraJanela * 0.5 + 490 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 110 &&  // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&  // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 160)) {  // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        return true;
    }
    return false;
}

void jump(){

}

void applyGravity() {

}