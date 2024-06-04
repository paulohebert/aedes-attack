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
    if (!(translateX < xPlatform1 + wPlatform1/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlatform1/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1/2 - gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlatform2/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2/2 - gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlatform3/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3/2 - gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlatform4/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4/2 - gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlatform5/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5/2 - gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoDireita(){
    if (!(translateX < xPlatform1 + wPlatform1/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlatform1/2 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlatform2/2 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlatform3/2 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlatform4/2 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlatform5/2 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoEmbaixo(){
    if (!(translateX < xPlatform1 + wPlatform1/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlatform1/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlatform2/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlatform3/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlatform4/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlatform5/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoCima(){
    if (!(translateX < xPlatform1 + wPlatform1/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlatform1/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlatform2/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer - playerVelocity)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlatform3/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlatform4/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlatform5/2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5/2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer - playerVelocity))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
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
        //translateY -= gravity;
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
