#ifndef OL_WINDOW_H
#define OL_WINDOW_H


#include <Windows.h>
#include <string>



namespace OnLooker
{
	/*
	//WINDOWS WINDOW
    class Window
    {
		//Methods
    public:
        Window();
        ~Window();

		void Create();
		//Methods
	private:
		static LRESULT CALLBACK WindowProc(HWND aWindowHandle, UINT aMsg, WPARAM aWParam, LPARAM aLParam);
		//Member Variables
    private:
		HWND m_WindowHandle;
		ATOM m_WindowClass;
		//Member Variables
	protected:
		//Window Dimensions
		int m_X;
		int m_Y;
		int m_Width;
		int m_Height;

		//Window Bits
		int m_Bits;


		//Mouse Positions
		int m_MouseX;
		int m_MouseY;
		int m_BoundedMouseX;
		int m_BoundedMouseY;

		//Window title
		std::string m_Title;
		

		//Window Style
		DWORD m_Style;
		DWORD m_FullscreenModeStyle;
		DWORD m_WindowedModeStyle;

		//Dimensions just before full screen enable
		int m_RestoreX;
		int m_RestoreY;
		int m_RestoreWidth;
		int m_RestoreHeight;
		

		//Dimensions of the whole screen
		int m_ScreenWidth;
		int m_ScreenHeight;
		int m_ScreenRefreshRate;

		//
		bool m_IsFullScreen;

		HDC m_DeviceContext;
		HGLRC m_OpenGLContext;


    };*/


	class Window
	{
	public:
		Window();
		Window(int aWidth, int aHeight, int aBits, bool aFullScreen = false);
		~Window();

		void swapBuffers();

	private:
		void registerWindowClass();
		void createContext();
		void initGL();
		void resizeGLScene();
		static LRESULT CALLBACK eventHandle(HWND aHandle, UINT aMessage, WPARAM aWParam, LPARAM aLParam);
		void processEvent(UINT aMessage, WPARAM aWParam, LPARAM aLParam);

		HWND m_Window;
		HDC m_DeviceContext;
		HGLRC m_OpenGLContext;

		int m_WindowWidth;
		int m_WindowHeight;
		std::string m_ClassName;
		bool m_FullScreen;

	};

}

#endif