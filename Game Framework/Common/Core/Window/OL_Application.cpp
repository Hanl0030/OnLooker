#include "OL_Application.h"
#include "../../Game/OL_Game.h"
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
            m_Game = 0;
            
        }

        Application::~Application()
        {
            if(m_Game != 0)
            {
                delete m_Game;
                m_Game = 0;
            }
        }

        bool Application::init()
        {
            if(m_Init == true)
            {
                return m_Init;
            }
            //TODO: Initialize Application
            m_Game = new Game();

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
            if(m_Game != 0)
            {
                m_Game->update();
                m_Game->render();
            }
        }

        

}