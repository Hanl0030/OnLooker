#include "OL_Renderer.h"

namespace OnLooker
{
    Renderer * Renderer::s_Instance = 0;
    Renderer * Renderer::getInstance()
    {
        if(s_Instance == 0)
        {
            s_Instance = new Renderer();
        }
        return s_Instance;
    }
    void Renderer::destroy()
    {
        if(s_Instance != 0)
        {
            delete s_Instance;
            s_Instance = 0;
        }
    }
    Renderer::Renderer()
    {

    }
    Renderer::~Renderer()
    {

    }
    
}