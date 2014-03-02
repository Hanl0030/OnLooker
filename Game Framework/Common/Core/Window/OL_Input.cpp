#include "OL_Input.h"
#include "../../Libraries/OL_OpenGL.h"



namespace OnLooker
{
#define NUMBER_OF_KEYS 350
#define NUMBER_OF_MOUSE_BUTTONS 8

    Input * Input::s_Instance = 0;
    Input * Input::getInstance()
    {
        if(s_Instance == 0)
        {
            s_Instance = new Input();
        }
        return s_Instance;
    }
    void Input::destroy()
    {
        if(s_Instance != 0)
        {
            delete s_Instance;
            s_Instance = 0;
        }
    }

    Input::Input()
    {
        m_Keys = new Key[NUMBER_OF_KEYS];

        for(int i = 0; i < NUMBER_OF_MOUSE_BUTTONS; i++)
        {
            m_Keys[i].m_State = KeyState::Up;
        }

        m_MouseButtons = new Key[NUMBER_OF_MOUSE_BUTTONS];
        for(int i = 0; i < NUMBER_OF_MOUSE_BUTTONS; i++)
        {
            m_MouseButtons[i].m_State = KeyState::Up;
        }

        m_MouseX = 0.0f;
        m_MouseY = 0.0f;
        m_MouseScroll = 0.0f;
        

    }
    Input::~Input()
    {
        if(m_Keys != 0)
        {
            delete[] m_Keys;
            m_Keys = 0;
        }
        if(m_MouseButtons != 0)
        {
            delete[] m_MouseButtons;
            m_MouseButtons = 0;
        }
    }
    bool Input::getKey(KeyCode aCode)
    {
        if(aCode < 0 || aCode >= KeyCode::KeyCode_Count)
        {
            return false;
        }
        if(m_Keys[aCode].m_State == KeyState::Down || m_Keys[aCode].m_State == KeyState::Pressed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Input::getKeyPressed(KeyCode aCode)
    {
        if(aCode < 0 || aCode >= KeyCode::KeyCode_Count)
        {
            return false;
        }
        if(m_Keys[aCode].m_State == KeyState::Pressed)
        {
            return true;
        }
        return false;
    }
    bool Input::getKeyReleased(KeyCode aCode)
    {
        if(aCode < 0 || aCode >= KeyCode::KeyCode_Count)
        {
            return false;
        }
        if(m_Keys[aCode].m_State == KeyState::Released)
        {
            return true;
        }
        return false;
    }
    bool Input::getMouse(MouseCode aCode)
    {
        if(aCode < 0 || aCode >= MouseCode::MouseCode_Count)
        {
            return false;
        }
        if(m_MouseButtons[aCode].m_State == KeyState::Pressed || m_MouseButtons[aCode].m_State == KeyState::Down)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Input::getMousePressed(MouseCode aCode)
    {
        if(aCode < 0 || aCode >= MouseCode::MouseCode_Count)
        {
            return false;
        }
        if(m_MouseButtons[aCode].m_State == KeyState::Pressed)
        {
            return true;
        }
        return false;
    }
    bool Input::getMouseReleased(MouseCode aCode)
    {
        if(aCode < 0 || aCode >= MouseCode::MouseCode_Count)
        {
            return false;
        }
        if(m_MouseButtons[aCode].m_State == KeyState::Released)
        {
            return true;
        }
        return false;
    }
    float Input::getMouseX()
    {
        return m_MouseX;
    }
    float Input::getMouseY()
    {
        return m_MouseY;
    }
    
    void Input::handleStates()
    {
        for(int i = 0; i < NUMBER_OF_KEYS; i++)
        {
            if(m_Keys[i].m_State == KeyState::Pressed)
            {
                m_Keys[i].m_State = KeyState::Down;
            }
            else if(m_Keys[i].m_State == KeyState::Released)
            {
                m_Keys[i].m_State = KeyState::Up;
            }
        }
        for(int i = 0; i < NUMBER_OF_MOUSE_BUTTONS; i++)
        {
            if(m_MouseButtons[i].m_State == KeyState::Pressed)
            {
                m_MouseButtons[i].m_State = KeyState::Down;
            }
            else if(m_MouseButtons[i].m_State == KeyState::Released)
            {
                m_MouseButtons[i].m_State = KeyState::Up;
            }
        }

        m_MouseScroll = 0.0f;

    }

    void Input::handleKeyEvent(int aKey, int aAction)
    {
        if(aAction == GLFW_RELEASE)
        {
            m_Keys[aKey].m_State = KeyState::Released;
        }
        else if(aAction == GLFW_PRESS)
        {
            m_Keys[aKey].m_State = KeyState::Pressed;
        }
    }
    void Input::handleMouseButtonEvent(int aButton, int aAction)
    {
        if(aAction == GLFW_RELEASE)
        {
            m_MouseButtons[aButton].m_State = KeyState::Released;
        }
        else if(aAction == GLFW_PRESS)
        {
            m_MouseButtons[aButton].m_State = KeyState::Pressed;
        }
    }
    void Input::handleMouseMove(double aXPosition, double aYPosition)
    {
        m_MouseX = aXPosition;
        m_MouseY = aYPosition;
    }
    void Input::handleMouseScroll(double aXAxis, double aYAxis)
    {
        m_MouseScroll = aYAxis;
    }
    
}

