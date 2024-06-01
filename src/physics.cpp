#include <GL/glut.h>
#include <keyboard.h>
#include <screen.h>

bool playerNoChao;
GLfloat playerVelocity = 10;
GLfloat gravity = 0.5;
GLfloat speedJump = 0;

bool verificaColisaoEsquerda(){
    if (!(translateX < -larguraJanela * 0.5 + 500 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 150 &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 200 &&                         // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 300 &&                        // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < -290 &&                        // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 640 &&                        // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 200 &&                         // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 300 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)      // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 200 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 300 &&                        // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoDireita(){
    if (!(translateX < -larguraJanela * 0.5 + 450 &&   // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 100 &&    // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&      // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)      // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 150 &&                          // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > -360 &&                          // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&     // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)       // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < -340 &&                        // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 700 &&                        // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 150 &&                         // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 360 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)      // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 150 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 360 &&                        // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoEmbaixo(){
    if (!(translateX < -larguraJanela * 0.5 + 490 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 110 &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 &&          // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 150)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 175 &&    // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < - 300 &&                       // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 690 &&                        // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 340 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 175 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)      // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 175 &&    // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoCima(){
    if (!(translateX < -larguraJanela * 0.5 + 490 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > -larguraJanela * 0.5 + 110 &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 - 10 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 160)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 25)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < - 300 &&                       // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 690 &&                        // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 190)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 25)      // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 25))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

void jump(){

}

void applyGravity() {

}