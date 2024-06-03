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
        translateX > xPlatform1 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer - playerVelocity)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer - playerVelocity))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoDireita(){
    if (!(translateX < xPlatform1 + wPlatform1/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 - wPlayer &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlayer - playerVelocity &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoEmbaixo(){
    if (!(translateX < xPlatform1 + wPlatform1/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1 + gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer + gravity)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2 + gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer + gravity)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3 + gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer + gravity)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4 + gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer + gravity)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5 + gravity &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer + gravity))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}

bool verificaColisaoCima(){
    if (!(translateX < xPlatform1 + wPlatform1/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform1 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform1 + hPlatform1 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform1 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto1 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform2 + wPlatform2/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform2 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform2 + hPlatform2 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform2 - hPlayer - playerVelocity)      // Verifica se a parte inferior do objeto2 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform3 + wPlatform3/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform3 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform3 + hPlatform3 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform3 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto4 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform4 + wPlatform4/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform4 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform4 + hPlatform4 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform4 - hPlayer - playerVelocity)     // Verifica se a parte inferior do objeto3 em movimento está acima da parte inferior do objeto estático
        &&
        !(translateX < xPlatform5 + wPlatform5/2 &&  // Verifica se o lado direito do objeto1 em movimento está à esquerda do lado direito do objeto estático
        translateX > xPlatform5 - wPlayer &&   // Verifica se o lado esquerdo do objeto1 em movimento está à direita do lado esquerdo do objeto estático
        translateY < yPlatform5 + hPlatform5 &&     // Verifica se a parte superior do objeto1 em movimento está abaixo da parte superior do objeto estático
        translateY > yPlatform5 - hPlayer - playerVelocity))     // Verifica se a parte inferior do objeto5 em movimento está acima da parte inferior do objeto estático
        {  
        return true;
    }
    return false;
}


/*
// Função que verifica se o objeto está colidindo à esquerda de qualquer plataforma
bool verificaColisaoEsquerda() {
    if (!(translateX + wPlayer >= xPlatform1 && // O lado direito do objeto está à esquerda do lado esquerdo da plataforma
            translateX + wPlayer <= xPlatform1 && // O lado direito do objeto está à direita do lado esquerdo da plataforma (ajustado pela velocidade)
            translateY < yPlatform1 + hPlatform1 && // A parte inferior do objeto está abaixo do topo da plataforma
            translateY + hPlayer > yPlatform1)
            &&
            !(translateX + wPlayer >= xPlatform2 && // O lado direito do objeto está à esquerda do lado esquerdo da plataforma
            translateX + wPlayer <= xPlatform2 && // O lado direito do objeto está à direita do lado esquerdo da plataforma (ajustado pela velocidade)
            translateY < yPlatform2 + hPlatform2 && // A parte inferior do objeto está abaixo do topo da plataforma
            translateY + hPlayer > yPlatform2)
            &&
            !(translateX + wPlayer >= xPlatform3 && // O lado direito do objeto está à esquerda do lado esquerdo da plataforma
            translateX + wPlayer <= xPlatform3 && // O lado direito do objeto está à direita do lado esquerdo da plataforma (ajustado pela velocidade)
            translateY < yPlatform3 + hPlatform3 && // A parte inferior do objeto está abaixo do topo da plataforma
            translateY + hPlayer > yPlatform3)
            &&
            !(translateX + wPlayer >= xPlatform4 && // O lado direito do objeto está à esquerda do lado esquerdo da plataforma
            translateX + wPlayer <= xPlatform4 && // O lado direito do objeto está à direita do lado esquerdo da plataforma (ajustado pela velocidade)
            translateY < yPlatform4 + hPlatform4 && // A parte inferior do objeto está abaixo do topo da plataforma
            translateY + hPlayer > yPlatform4)
            &&
            !(translateX + wPlayer >= xPlatform5 && // O lado direito do objeto está à esquerda do lado esquerdo da plataforma
            translateX + wPlayer <= xPlatform5 && // O lado direito do objeto está à direita do lado esquerdo da plataforma (ajustado pela velocidade)
            translateY < yPlatform5 + hPlatform5 && // A parte inferior do objeto está abaixo do topo da plataforma
            translateY + hPlayer > yPlatform5)) { // A parte superior do objeto está acima da base da plataforma
            return true;    
    }
    return false;
}

// Função que verifica se o objeto está colidindo à direita de qualquer plataforma
bool verificaColisaoDireita() {
    if (!(translateX <= xPlatform1 + wPlatform1 && // O lado esquerdo do objeto está à direita do lado direito da plataforma
            translateX >= xPlatform1 + wPlatform1 && // O lado esquerdo do objeto está à esquerda do lado direito da plataforma (ajustado pela velocidade)
            translateY < yPlatform1 + hPlatform1 && // A parte inferior do objeto está abaixo do topo da plataforma
            translateY + hPlayer > yPlatform1)) { // A parte superior do objeto está acima da base da plataforma
            return true;
    }
    return false;
}

// Função que verifica se o objeto está colidindo na parte de cima de qualquer plataforma
bool verificaColisaoCima() {
    if (!(translateY <= yPlatform1 + hPlatform1 && // A parte inferior do objeto está acima da parte superior da plataforma
            translateY >= yPlatform1 + hPlatform1 && // A parte inferior do objeto está abaixo da parte superior da plataforma (ajustado pela velocidade)
            translateX < xPlatform1 + wPlatform1 && // O lado esquerdo do objeto está à direita do lado esquerdo da plataforma
            translateX + wPlayer > xPlatform1)) { // O lado direito do objeto está à esquerda do lado direito da plataforma
            return true;
    }    
    return false;
}

// Função que verifica se o objeto está colidindo na parte de baixo de qualquer plataforma
bool verificaColisaoEmbaixo() {
    if (!(translateY + hPlayer >= yPlatform1 && // A parte superior do objeto está abaixo da parte inferior da plataforma
            translateY + hPlayer <= yPlatform1 && // A parte superior do objeto está acima da parte inferior da plataforma (ajustado pela velocidade)
            translateX < xPlatform1 + wPlatform1 && // O lado esquerdo do objeto está à direita do lado esquerdo da plataforma
            translateX + wPlayer > xPlatform1)) { // O lado direito do objeto está à esquerda do lado direito da plataforma
            return true;
    }
    return false;
}
*/





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
