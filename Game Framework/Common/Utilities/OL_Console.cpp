#include "OL_Console.h"
#include <stdio.h>
#include <stdarg.h>

#if WIN32
    #include <Windows.h>
    #include <io.h>
#endif

namespace OnLooker
{
    Console * Console::s_Instance = 0;
    Console * Console::getInstance()
    {
        if(s_Instance == 0)
        {
            s_Instance = new Console();
        }
        return s_Instance;
    }
    void Console::destroy()
    {
        if(s_Instance != 0)
        {
            delete s_Instance;
            s_Instance = 0;
        }
    }
	//void outputString(std::string aMessage)
	//{
	
	//}

    void Console::output(const char * aMessage, ...)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }

        va_list arguments;
        va_start(arguments, aMessage);
        vprintf(aMessage, arguments);

        va_end(arguments);

    }
    void Console::output(int aValue)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
        printf("%f \n",aValue);
    }
    void Console::output(float aValue)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
        printf("%f \n",aValue);
    }
    void Console::output(double aValue)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
        printf("%f \n",aValue);
    }

    Console::Console()
    {
        m_IsConsoleAllocated = false;
    }
    Console::~Console()
    {

    }

    void Console::createConsole()
    {
#if WIN32
        m_IsConsoleAllocated = true;
        AllocConsole();
#if UNICODE
	SetConsoleTitle(L"Debug Console");
#else
	SetConsoleTitle("Debug Console");
#endif

    int hConHandle = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE),0x4000);
    FILE * filePointer = _fdopen(hConHandle, "w");
    *stdout = *filePointer;
    setvbuf(stdout,NULL,_IONBF,0);
#endif
    }
    
}