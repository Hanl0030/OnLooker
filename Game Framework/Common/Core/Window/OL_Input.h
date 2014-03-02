#ifndef OL_INPUT_H
#define OL_INPUT_H

#include "OL_KeyDef.h"

namespace OnLooker
{
    class Window;
    class Main;


    class Input
    {
    public:
        static Input * getInstance();
        static void destroy();

        bool getKey(KeyCode aCode);
        bool getKeyPressed(KeyCode aCode);
        bool getKeyReleased(KeyCode aCode);
        bool getMouse(MouseCode aCode);
        bool getMousePressed(MouseCode aCode);
        bool getMouseReleased(MouseCode aCode);
        float getMouseX();
        float getMouseY();
        //mouse scroll coming soon
        //float getMouseScroll();

    private:
        Input();
        ~Input();
        static Input * s_Instance;

        //
        void handleStates();
        //Functions for window to use
        void handleKeyEvent(int aKey, int aAction);
        void handleMouseButtonEvent(int aButton, int aAction);
        void handleMouseMove(double aXPosition, double aYPosition);
        void handleMouseScroll(double aXAxis, double aYAxis);

        Key * m_Keys;
        Key * m_MouseButtons;

        float m_MouseX;
        float m_MouseY;
        float m_MouseScroll;

        friend Window;
        friend Main;
    };
}

#endif