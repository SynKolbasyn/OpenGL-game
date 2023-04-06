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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL-game", nullptr, nullptr);

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

    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "OpenGL version: " << glGetString(GL_VERSION) << endl;
    
    glClearColor(0, 1, 0, 1);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

