#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <math.h>
using namespace std;

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600,600,"Cool Game",NULL,NULL);
    if(window == NULL)
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0,0,600,600);
    
    glClearColor(0.941,0.404,0.404,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    float prev_time=glfwGetTime();
    float angle = 0.0;    

    while(!glfwWindowShouldClose(window))
    {
        float time= glfwGetTime();
        if(time-prev_time >= 0.1)
        {
            angle += 0.1;
            prev_time = time;
        }
        glClearColor(float(sin(angle/0.2)),float(cos(angle/0.2)),float(tan(angle/0.2)), 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents(); 
        glfwSwapBuffers(window); 
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

