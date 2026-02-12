#include <iostream>
using namespace std;
// 1. ַבÊײדםה:
// ÊÚׁםÝ GLEW_STATIC ם־ָׁ ַבדÚַבּ ַבד׃ָÞ ֳההַ ה׃Ê־ֿד דßÊָֹ ׃ַßהֹ (Êֿדּ Ýם ַבÜ exe)
// םָּ ֶַֿדַנ Êײדםה GLEW Þָב GLFW בֳהוַ ÊֽÊזם Úבל ÊÚׁםÝַÊ OpenGL ַבײׁזׁםֹ
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
const GLint WIDTH = 800, HEIGHT = 600;
int main() {
    if (!glfwInit()) {
        cout << "fatal error";
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

    if (nullptr == window)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate(); // ÊהÙםÝ ַבדזַֿׁ Þָב ַב־ׁזּ
        return EXIT_FAILURE;
    }

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Êֽֿםֿ דהÝ׀ ַבÚׁײ (Viewport):
    // ה־ָׁ OpenGL ֳה ד׃ַֹֽ ַבׁ׃ד Êֳָֿ דה (0,0) זÊדÊֿ בÚׁײ זַׁÊÝַÚ ַבװַװֹ ַבÝÚבםםה
    glViewport(0, 0, screenWidth, screenHeight);

    // 6. ֽבÞֹ ַבÚׁײ (Game Loop):
    // ו׀ו ַבֽבÞֹ Ê׃Êדׁ ַָבֿזַׁה ״ַבדַ בד ם״בָ ַבד׃Ê־ֿד ֵÛבַÞ ַבהַÝ׀ֹ
    while (!glfwWindowShouldClose(window))
    {
        // ַבÊֽÞÞ דה ַבֳַֻֽֿ (Events):
        // וב ײÛ״ ַבד׃Ê־ֿד ׁׂ¿ וב ֽׁß ַבדַז׃¿ GLFW ÊבÊÞ״ ו׀ו ַבֳַֻֽֿ והַ.
        glfwPollEvents();

        // --- דֽׁבֹ ַבׁ׃ד ---

        // Êֽֿםֿ בזה ַבד׃ֽ: ַֿבֹ "ַֽבֹ" Êֽֿֿ ַבבזה ַב׀ם ׃ה׃Ê־ֿדו בד׃ֽ ַבװַװֹ (בזה Êׁßזַׂם)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // ÊהÝם׀ ַבד׃ֽ: ַֿבֹ "ֳדׁ" Ê׃Ê־ֿד ַבבזה ַבדֽֿֿ ֳÚבַו בד׃ֽ ד־ׂה ַבֳבזַה (Color Buffer)
        glClear(GL_COLOR_BUFFER_BIT);

        // ַבÊָֿםב (Swap Buffers):
        // ָדַ ֳההַ ׁ׃דהַ Ýם ַבד־ׂה ַב־בÝם¡ הÞזד ַבֲה ָÊָֿםבו בםÙוׁ בבד׃Ê־ֿד

        glfwSwapBuffers(window);
    }

    // 7. ַבֵהוֱַ:
    // ÊהÙםÝ ּדםÚ דזַֿׁ GLFW זֽ׀Ý ַבהַÝ׀ֹ דה ַב׀ַßֹׁ
    glfwTerminate();

    return EXIT_SUCCESS;
}