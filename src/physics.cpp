#include <GL/glut.h>
#include <keyboard.h>
#include <screen.h>

bool playerNoChao;
GLfloat gravity = 0.5;
GLfloat jump = 10.0;

bool verificaColisoes(){
    bool podeMover;
    
    // Verifica colisao com a plataforma 0
    if(translateX > -larguraJanela/2  && translateX < larguraJanela/2)
    {
        podeMover = true;
    }
    else{
        podeMover = false;
    }


    return true;
}

void applyGravity() 
{
    if (!playerNoChao)
    {
        translateY -= gravity;
    }
}