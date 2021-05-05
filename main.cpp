#include <iostream>
#include <GLFW/glfw3.h>
#include <OLASConfig.h>

#ifdef USE_ADDER
    #include <adder.h>
#endif

int main(int argc, char* argv[])
{
#ifdef USE_ADDER
    std::cout <<"adder lib defind"<<  add(45, 45)<< '\n';
#else
    std::cout <<"adder lib not defind"<< 45 + 45 << '\n';
#endif


    std::cout << argv[0] << " Version " << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << "\n";

GLFWwindow *window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
     window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
