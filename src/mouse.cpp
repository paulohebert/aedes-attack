#include <GL/glut.h>

void mouse(int button, int estado, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (estado == GLUT_DOWN)
        {
        }

    if (button == GLUT_RIGHT_BUTTON)
        if (estado == GLUT_DOWN)
        {
        }
    glutPostRedisplay();
}