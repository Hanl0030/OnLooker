#ifndef OL_WINDOW_H
#define OL_WINDOW_H


#include <Windows.h>
#include <string>



namespace OnLooker
{
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


		//Mouse Positions
		int m_MouseX;
		int m_MouseY;
		int m_BoundedMouseX;
		int m_BoundedMouseY;

		//Window title
		std::string m_Title;
		

		//Window Style
		DWORD m_Style;

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


    };

}

#endif