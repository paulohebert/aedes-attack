#include <GL/glut.h>
#include <keyboard.h>
#include <screen.h>
#include <position.h>

bool playerNoChao;
GLfloat playerVelocity = 5;
GLfloat movePlayerX;
GLfloat movePlayerY;
GLfloat gravity = 8.0;

// Defina uma variável global para controlar o estado do pulo
bool isJumping = false;
GLfloat jumpStrength = 230.0f; // Força do pulo
GLfloat jumpVelocity = 10.0f;   // Velocidade vertical do pulo
GLfloat jumpHeight = 0.0f;     // Altura atual do pulo


// Define variável que verifica se há um botão de movimento horizontal pressionado
bool leftPressed = false;
bool rightPressed = false;

bool verificaColisaoEsquerda(){
    if (!(translateX < xPlatform1 + wPlatform1 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 + hPlatform1)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 + hPlatform2)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 + hPlatform3)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 + hPlatform4)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 + hPlatform5))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoDireita(){
    if (!(translateX < xPlatform1 + wPlatform1 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela + hPlatform1)      // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 150 &&                          // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > -360 &&                          // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&     // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)       // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < -340 &&                        // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 700 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 460 &&                         // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > 100 &&                          // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 770 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > 410 &&                          // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 75 &&     // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 60))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoEmbaixo(){
    if (!(translateX < xPlatform1 + wPlatform1 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela + hPlatform1)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 175 &&    // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 35)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < - 300 &&                       // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 690 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 340 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 500 &&                         // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > 120 &&                          // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 340 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 200)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 800 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > 420 &&                          // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 85 &&     // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 60))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoCima(){
    if (!(translateX < xPlatform1 + wPlatform1 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1  &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela + hPlatform1)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 190 &&                         // Verifica se o lado direito do objeto2 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 350 &&                        // Verifica se o lado esquerdo do objeto2 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 165 &&    // Verifica se a parte superior do objeto2 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 25)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < - 300 &&                       // Verifica se o lado direito do objeto4 em movimento está à esquerda do lado direito do objeto estático
        translateX > - 690 &&                        // Verifica se o lado esquerdo do objeto4 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto4 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 190)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 500 &&                         // Verifica se o lado direito do objeto3 em movimento está à esquerda do lado direito do objeto estático
        translateX > 120 &&                          // Verifica se o lado esquerdo do objeto3 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 330 &&    // Verifica se a parte superior do objeto3 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 + 190)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < 800 &&                         // Verifica se o lado direito do objeto5 em movimento está à esquerda do lado direito do objeto estático
        translateX > 420 &&                          // Verifica se o lado esquerdo do objeto5 em movimento está à direita do lado esquerdo do objeto estático
        translateY < alturaJanela * 0.2 + 75 &&     // Verifica se a parte superior do objeto5 em movimento está abaixo da parte superior do objeto estático
        translateY > alturaJanela * 0.2 - 70))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool applyGravity() {
    // Verifica se há colisão embaixo e se o jogador não está pulando
    if (translateY > alturaJanela * 0.05 - 40 && !isJumping && verificaColisaoEmbaixo()) {
        return true; // Aplicar gravidade apenas se não houver colisão embaixo e o jogador não estiver pulando
    } else {
        return false;
    }
}

void moveObjetos(){
    if(applyGravity()){
        translateY -= gravity;
    }

    // Atualizar a velocidade horizontal com base nas teclas pressionadas
    if (leftPressed && translateX > -150 && verificaColisaoEsquerda()) {
        movePlayerX = -playerVelocity;
    } else if (rightPressed && translateX < larguraJanela - 250 && verificaColisaoDireita()) {
        movePlayerX = playerVelocity;
    } else {
        movePlayerX = 0.0;
    }

    translateX += movePlayerX;
    translateY += movePlayerY;
    movePlayerX = 0;
    movePlayerY = 0;

}

// Função para controlar o pulo do jogador
void jump(int value) {
    if (isJumping) {
        // Atualize a posição vertical do jogador
        jumpHeight += jumpVelocity;
        translateY += jumpVelocity;
        
        // Verifique se o jogador atingiu a altura máxima do pulo
        if (jumpHeight >= jumpStrength || !verificaColisaoCima()) {
            isJumping = false;
            jumpHeight = 0.0f;
        }
        
        // Redesenhe a cena
        //glutPostRedisplay();
        
        // Registre a função de salto novamente para o próximo quadro
        glutTimerFunc(10, jump, 0); // 16 ms para aproximadamente 60 FPS
    }
}

// Função para iniciar o pulo do jogador
void startJump() {
    if (!isJumping) {
        isJumping = true;
        jumpHeight = 0.0f;
        glutTimerFunc(10, jump, 0); // Inicia o temporizador de salto
    }
}
