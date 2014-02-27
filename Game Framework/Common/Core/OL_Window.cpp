#include "OL_Window.h"
#include "../../Windows/OnLooker/OnLooker/Source/OL_Main.h"

namespace OnLooker
{
	/*Window::Window()
	{
		m_X = 0;
		m_Y = 0;
		m_Width = 1024;
		m_Height = 768;

		m_Title = "OnLooker Engine";
		m_WindowedModeStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX;  //default style
		m_FullscreenModeStyle = WS_POPUP;
		m_IsFullScreen = false;

		m_ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		m_ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	}
    Window::~Window()
	{
	}

	void Window::Create()
	{
		//Create the window class
		//Register Window Class
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

		//Setup Dev Mode
		if(m_IsFullScreen == true)
		{
			//Setup DEVMODE settings
			DEVMODE dmScreenSettings;
			memset(&dmScreenSettings, 0 , sizeof(dmScreenSettings));
			dmScreenSettings.dmSize = sizeof(dmScreenSettings);		
			dmScreenSettings.dmPelsWidth	= m_Width;									//Horizontal Screen Resolution
			dmScreenSettings.dmPelsHeight	= m_Height;									//Vertical Screen Resolution
			dmScreenSettings.dmBitsPerPel	= m_Bits;									//Color depth
			dmScreenSettings.dmDriverExtra	= 0;										//The device drigver does not use specific information
			dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;	//Tell DEVMODE what fields we wish to override

			if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
			{
				//Throw an error 
				//And return
			}
			//Get Refresh Rate
			EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS, &dmScreenSettings);
			m_ScreenRefreshRate = dmScreenSettings.dmDisplayFrequency;

		}

		if(m_IsFullScreen)
		{
			m_Style = m_FullscreenModeStyle;
		}
		else
		{
			m_Style = m_WindowedModeStyle;
		}

		RECT windowRect;
		windowRect.top = m_Y;
		windowRect.left = m_X;
		windowRect.right = m_X + m_Width;
		windowRect.bottom = m_Y + m_Height;

		//Set the window position and size
		AdjustWindowRect(&windowRect, m_Style, FALSE);

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
		
		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = m_Bits;


		m_DeviceContext = GetDC(m_WindowHandle);
		//error check

		int pixelFormat = 0;

		pixelFormat = ChoosePixelFormat(m_DeviceContext, &pfd);
		//error check

		//error check
		SetPixelFormat(m_DeviceContext,pixelFormat,&pfd);
		

		m_OpenGLContext = wglCreateContext(m_DeviceContext);
		//error check

		wglMakeCurrent(m_DeviceContext,m_OpenGLContext);

		ShowWindow(m_WindowHandle,SW_SHOW);

		if(!m_WindowHandle)
		{
			//Give Error
			return;
		}
	
	}

	LRESULT CALLBACK Window::WindowProc(HWND aWindowHandle, UINT aMsg, WPARAM aWParam, LPARAM aLParam)
	{


		return 0;
	}*/
	Window::Window()
	{
	}
	Window::Window(int aWidth, int aHeight, int aBits, bool aFullScreen)
	{
	}
	Window::~Window()
	{
	}

	void Window::swapBuffers()
	{
	}
	void Window::registerWindowClass()
	{
	}
	void Window::createContext()
	{
	}
	void Window::initGL()
	{
	}
	void Window::resizeGLScene()
	{
	}
	LRESULT CALLBACK Window::eventHandle(HWND aHandle, UINT aMessage, WPARAM aWParam, LPARAM aLParam)
	{

		return 0;
	}
	void Window::processEvent(UINT aMessage, WPARAM aWParam, LPARAM aLParam)
	{
	}


}