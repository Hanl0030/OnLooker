#ifndef OL_KEY_DEF_H
#define OL_KEY_DEF_H


namespace OnLooker
{



    namespace MouseCode
    {
        enum EMouseCode
        {
            MOUSE_BUTTON_1 = 0,
            MOUSE_BUTTON_2,
            MOUSE_BUTTON_3,
            MOUSE_BUTTON_4,
            MOUSE_BUTTON_5,
            MOUSE_BUTTON_6,
            MOUSE_BUTTON_7,
            MOUSE_BUTTON_8,

            COUNT,

            MOUSE_BUTTON_LEFT = 0,
            MOUSE_BUTTON_RIGHT,
            MOUSE_BUTTON_MIDDLE
        };
    }

    namespace KeyCode
    {
        enum EKeyCode
        {
            SPACE = 32,
            APOSTROPHE = 39,
            COMMA = 44,
            MINUS = 45,
            PERIOD = 46,
            SLASH = 47,
            ALPHA_0,
            ALPHA_1,
            ALPHA_2,
            ALPHA_3,
            ALPHA_4,
            ALPHA_5,
            ALPHA_6,
            ALPHA_7,
            ALPHA_8,
            ALPHA_9,
            SEMICOLON = 59,
            EQUAL = 61,
            A = 65,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            LEFT_BRACKET,
            BACKSLASH,
            RIGHT_BACKET,
            GRAVE_ACCENT = 96,
            ESCAPE = 256,
            ENTER,
            TAB,
            BACKSPACE,
            INSERT,
            DELETE,
            RIGHT,
            LEFT,
            DOWN,
            UP,
            PAGE_UP,
            PAGE_DOWN,
            HOME,
            END,
            CAPS_LOCK = 280,
            SCROLL_LOCK,
            NUM_LOCK,
            PRINT_SCREEN,
            PAUSE,
            F1 = 290,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            F16,
            F17,
            F18,
            F19,
            F20,
            F21,
            F22,
            F23,
            F24,
            F25,
            COUNT,
        };
    }
}

#endif