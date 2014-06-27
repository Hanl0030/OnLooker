#include "OL_Main.h"
#include "../../../../Common/Libraries/OL_OpenGL.h"
#include <iostream>

//#include "../../../../Common/Core/OL_Core.h"


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
    OnLooker::MemoryManager::instance();
    int mainRunCode = OnLooker::Main::getInstance()->run();
    OnLooker::Main::destroy();
    OnLooker::MemoryManager::destroy();

    return mainRunCode;
}

namespace OnLooker
{
        
        Main * Main::s_Instance = 0;
        Main * Main::getInstance()
        {
            if(s_Instance == 0)
            {
                s_Instance = Memory::instantiate<Main>();//new Main();
            }
            return s_Instance;
        }

        void Main::destroy()
        {
            if(s_Instance != 0)
            {
                //delete s_Instance;
                //s_Instance = 0;
                s_Instance = Memory::destroy<Main>(s_Instance);
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

            //m_Window = Memory::instantiate<Window>(); 
            

            if(m_Window->createWindow() == false)
            {
                //TODO: Debug Error
                Debug::console->outputFormat("Failure to create window \n");
                onExit();
                return -1;
            }
			//Renderer setup
            Renderer::getInstance()->initialize(m_Window->getWindowWidth(),m_Window->getWindowHeight());

            if(Application::getInstance()->init() != true)
            {
                //Something went wrong
                Debug::console->outputFormat("Failure to initialize Application \n");
                onExit();
                return -1;
            }
            //Setup Time Variables pre loop
			
            Time::m_CurrentTime = Window::getTime();
            Time::m_LastTime = Time::m_CurrentTime;
            Time::m_Delta = Time::m_CurrentTime - Time::m_LastTime;

            
            if(Renderer::getInstance()->isReadyInitalized() != true)
            {
                Debug::console->outputFormat("Failure to initialize Renderer \n");
                onExit();
                return -1;
            }

            onLookerInit();

            //Game Loop Here
            //TODO: Implement game update and render calls
            while(!m_Window->shouldWindowClose())
            {

                //Calculate delta
				Time::m_LastTime = Time::m_CurrentTime;
                Time::m_CurrentTime = Window::getTime();
                Time::m_Delta = Time::m_CurrentTime - Time::m_LastTime;
                //Clear 
                Renderer::getInstance()->clear();
                //Game Update/Render
                Application::getInstance()->onIdle(); 

                //Check for Errors
                Renderer::getInstance()->checkForErrors();
                //Update window
                Input::getInstance()->handleStates();
                m_Window->swapBuffers();
                m_Window->pollEvents();
            }

            onExit();
            return 0;
        }

        const char * Main::getType()
        {
            return OL_INDESTRUCTIBLE_OBJECT;
        }

        //This function gets called before run is left
        void Main::onExit()
        {
            Application::getInstance()->destroy();

            
            if(m_Window != 0)
            {
                m_Window->destroy();
                delete m_Window;
                m_Window = 0;
            }


            Debug::destroy();
            FilePath::destroy();
        }

        

        

}