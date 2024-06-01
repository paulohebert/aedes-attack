#include <GL/glut.h>
#include <keyboard.h>
#include <screen.h>

bool playerNoChao;
GLfloat gravity = 0.5;
GLfloat speedJump = 0;

bool verificaColisaoEsquerda(){
    if(translateX > -larguraJanela/2){
        return true;
    }
    else{
        return false;
    }
}

bool verificaColisaoDireita(){
    if(translateX < larguraJanela/2){
        return true;
    }
    else{
        return false;
    }
}

bool verificaColisaoEmbaixo(){

    return true;
}

bool verificaColisoesDireita(){

    return true;
}

void jump(){

}

void applyGravity() {

}