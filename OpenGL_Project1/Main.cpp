#include <GLFW/glfw3.h>
#include <cmath> 
#include "funcs.h" // own functions 

void gridDraw();
void drawAxis();

float a = 0; // global a to use it independet of loop while
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(680, 680, "OpenGlTester", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // background color
        glClear(GL_COLOR_BUFFER_BIT);

        glLoadIdentity();      // const matrix 
        glScalef(0.1, 0.1, 1); // Scale of everthing 0.1x
        

        gridDraw();
        drawAxis();

       glPointSize(3);
        glBegin(GL_POINTS); // change to GL_POINTS if necesarry or GL_LINE_STRIP

            glColor3f(0,0,0); // color black
            
            
            for (float i = -10; i <= 10; i+=0.01) { // change i to 

                float y = sin(a*i) +  i*cos(a); // your formula is here (a or other arguments must be declared out of loop
              glVertex2f(i, y); // draw point or point of line where i is x and y is y
            
            }
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        a += 0.1; // Change global argument
        if (a == 5.0) {
            a = -5.0;
        }
    }

    glfwTerminate(); // end
    return 0;
}