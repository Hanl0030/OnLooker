#include "OL_Window.h"
#include "../../Windows/OnLooker/OnLooker/Source/OL_Main.h"

namespace OnLooker
{
	Window::Window()
	{
		m_X = 0;
		m_Y = 0;
		m_Width = 1024;
		m_Height = 768;

		m_Title = "OnLooker Engine";
		m_Style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
		m_IsFullScreen = false;

		m_ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		m_ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

		DEVMODE curdmode;

		ZeroMemory(&curdmode, sizeof(curdmode));
		curdmode.dmSize = sizeof(curdmode);
		curdmode.dmDriverExtra = 0;
		EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS, &curdmode);
		m_ScreenRefreshRate = curdmode.dmDisplayFrequency;


	}
    Window::~Window()
	{
	}

	void Window::Create()
	{
		//Create the window class
		if(m_WindowClass)
		{
			//return true;
		}
		else
		{
			WNDCLASS wc;
			wc.style				= CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
			wc.lpfnWndProc			= WindowProc;
			wc.cbClsExtra			= 0;
			wc.cbWndExtra			= 0;
			wc.hInstance			= Main::getInstance()->getInstanceHandle();
			wc.hIcon				= LoadIcon(NULL,IDI_APPLICATION);
			wc.hCursor				= LoadCursor(NULL, IDC_ARROW);
			wc.hbrBackground		= (HBRUSH)(COLOR_WINDOW + 1);
			wc.lpszMenuName			= NULL;
			wc.lpszClassName		= "OnLooker Engine";

			//register the window class
			m_WindowClass = RegisterClass(&wc);

		}
		

		//Create the window
		m_WindowHandle = CreateWindow(
			"OnLooker Engine",							//Class NAme
			m_Title.c_str(),							//Title Name
			m_Style,									//Style
			m_X,										//X Coordinate
			m_Y,										//Y Coordinate
			m_Width,									//Width
			m_Height,									//Height
			NULL,										//Handle to parent
			NULL,										//Handle to menu
			Main::getInstance()->getInstanceHandle(),	//Instance
			this);										//Creation Params
		
		if(!m_WindowHandle)
		{
			//Give Error
			return;
		}
	
	}

	LRESULT CALLBACK Window::WindowProc(HWND aWindowHandle, UINT aMsg, WPARAM aWParam, LPARAM aLParam)
	{


		return 0;
	}
	

}