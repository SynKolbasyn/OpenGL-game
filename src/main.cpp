#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    if (!glfwInit()) {
        cout << "glfwInit() - failed" << endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL-game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        cout << "glfwCreateWindow() - failed" << endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    if (!gladLoadGL()) {
        cout << "gladLoadGL() - failed" << endl;
        return -1;
    }
    
    glClearColor(0, 1, 0, 1);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

