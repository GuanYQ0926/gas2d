#include <iostream>
#include <sstream>
#include <string>

#include "glinclude.h"
#include "scene.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int main(int argc, char const *argv[])
{
    int frames = 0;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//necessary
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(gridWidth, gridHeight,
                                        "Gas2D", NULL, NULL);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    Scene* scene = new Scene();
    scene->initScene();

    GLfloat lastFrame = glfwGetTime();

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //render scene
        scene->renderScene();
        glfwSwapBuffers(window);
        frames++;

        GLfloat currentFrame = glfwGetTime();
        if(currentFrame - lastFrame >= 1.0f)
        {
            string title;
            std::stringstream sfps;
            sfps << double(frames);
            sfps >> title;
            lastFrame = currentFrame;
            glfwSetWindowTitle(window, title.c_str());
            frames = 0;
        }
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
