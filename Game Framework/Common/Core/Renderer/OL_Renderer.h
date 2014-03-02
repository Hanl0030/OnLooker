#ifndef OL_RENDERER_H
#define OL_RENDERER_H
/*
*   Filename: OL_Renderer
*   Date Modified: 02/03/2014 by Nathan Hanlan
*   Comments: v1.0.0 Added Renderer Class
*/


namespace OnLooker
{
    /*
    *   Class: Renderer
    *   Base Class: N/A
    *   Description: The purpose of this class is to provide easy functions
    *   to use for rendering on screen
    *   Follows the singleton design pattern
    *   Date Modified: 02/03/2014 by Nathan Hanlan
    */
    class Renderer
    {
    public:
        static Renderer * getInstance();
        static void destroy();
    private:
        Renderer();
        ~Renderer();
        static Renderer * s_Instance;
    };
}

#endif