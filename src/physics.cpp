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
    if((translateX < larguraJanela/2) && (true)){
        return true;
    }
    else{
        return false;
    }
}

bool verificaColisaoEmbaixo(){
    if(translateY > -alturaJanela/2 +430){
        return true;
    }
    else{
        return false;
    }
}

bool verificaColisaoCima(){
    if(translateY < alturaJanela -250){
        return true;
    }
    else{
        return false;
    }
}

void jump(){

}

void applyGravity() {

}