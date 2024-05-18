#include <GLFW/glfw3.h>
#include <cmath>

void gridDraw() {
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    for (float i = -10; i < 10; i++) {
        glVertex2f(i, -10);
        glVertex2f(i, 10);
        glVertex2f(-10, i);
        glVertex2f(10, i);
    }

    glEnd();
}
void drawAxis() {
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(238, 0, 0);
    glVertex2f(-10, 0);
    glVertex2f(10, 0);
    glVertex2f(0, 10);
    glVertex2f(0, -10);

    glEnd();
}