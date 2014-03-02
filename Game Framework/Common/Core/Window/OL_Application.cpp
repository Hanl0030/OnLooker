#include "OL_Application.h"
#include <iostream>


namespace OnLooker
{
        Application * Application::s_Instance = 0;
        Application * Application::getInstance()
        {
            if(s_Instance == 0)
            {
                s_Instance = new Application();
            }
            return s_Instance;
        }
        
        void Application::destroy()
        {
            if(s_Instance != 0)
            {
                delete s_Instance;
                s_Instance = 0;
            }
        }

        Application::Application()
        {
            m_Init = false;

            
        }

        Application::~Application()
        {

        }

        bool Application::init()
        {
            if(m_Init == true)
            {
                return m_Init;
            }
            //TODO: Initialize Application

            //Temp Code ***REMOVE***
            m_Init = true;

            return m_Init;
        }


        void Application::onIdle()
        {
            //If initialization has not occured return.
            if(m_Init == false)
            {
                return;
            }

            //TODO: Write game update / render methods

        }

        

}