#include "OL_Main.h"
#include "../../../../Common/Libraries/OL_OpenGL.h"
#include <iostream>


/*
*   Filename: OL_Main.cpp
*   Date Modified: 25/02/2014 by Nathan Hanlan
*   Comments: v1.0.0 Initial Creation
*             - Implemented Main Class
*             - Wrote entry point.
*             - Implemented game loop and delta time calculation
*/

int main()
{
    
    int mainRunCode = OnLooker::Main::getInstance()->run();
    OnLooker::Main::destroy();

    return mainRunCode;
}

namespace OnLooker
{
        Main * Main::s_Instance = 0;
        Main * Main::getInstance()
        {
            if(s_Instance == 0)
            {
                s_Instance = new Main();
            }

            return s_Instance;
        }

        void Main::destroy()
        {
            if(s_Instance != 0)
            {
                delete s_Instance;
                s_Instance = 0;
            }
        }

        Main::Main()
        {
            m_Window = 0;
            
        }
        Main::~Main()
        {

        }

        int Main::run()
        {
            //Create Window
            m_Window = new Window(1024,768,"OnLooker v3.0");
            if(m_Window->createWindow() == false)
            {
                //TODO: Debug Error
                Debug::console->output("Failure to create window");
                return -1;
            }
            if(Application::getInstance()->init() != true)
            {
                //Something went wrong
                Debug::console->output("Failure to initialize Application");
                return -1;
            }
            //Setup Time Variables pre loop
            Time::m_CurrentTime = Window::getTime();
            Time::m_LastTime = Time::m_CurrentTime;
            Time::m_Delta = Time::m_CurrentTime - Time::m_LastTime;


            //Game Loop Here
            //TODO: Implement game update and render calls
            while(!m_Window->shouldWindowClose())
            {

                //Calculate delta
                Time::m_CurrentTime = Window::getTime();
                Time::m_LastTime = Time::m_CurrentTime;
                Time::m_Delta = Time::m_CurrentTime - Time::m_LastTime;

                
                
                //Update window
                m_Window->swapBuffers();
                m_Window->pollEvents();
            }

            
            



            Application::getInstance()->onIdle();


            Application::getInstance()->destroy();

            
            if(m_Window != 0)
            {
                m_Window->destroy();
                delete m_Window;
                m_Window = 0;
            }


            Debug::destroy();
            FilePath::destroy();

            return 0;
        }



        

        

}