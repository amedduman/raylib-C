#include "rendering_helper.h"

int main()
{
    GLFWwindow* window = init_window(800, 600);

    unsigned int vertexShader = create_shader(GL_VERTEX_SHADER, "src/my_first.vert");
    unsigned int fragmentShader = create_shader(GL_FRAGMENT_SHADER, "src/my_first.frag");
    unsigned int shaderProgram = create_shader_program({vertexShader, fragmentShader});

    float vertices[] = {
        // positions         // colors
        0.5f,  -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
        0.0f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f  // top
    };
    unsigned int indices[] = { 0, 1, 2 };

    unsigned int VAO = create_model(vertices, sizeof(vertices), indices, sizeof(indices));

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
