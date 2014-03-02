#ifndef OL_RENDERER_H
#define OL_RENDERER_H
/*
*   Filename: OL_Renderer
*   Date Modified: 02/03/2014 by Nathan Hanlan
*   Comments: v1.0.0 Added Renderer Class
*/

#include "../../Libraries/OL_OpenGL.h"
#include "OL_Color.h"

namespace OnLooker
{
    class Texture;
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

        bool isReadyInitalized();

        void initialize(double aWindowWidth, double aWindowHeight);
        //OpenGL States
        void clear();

        Color getBackgroundColor();
        void setBackgroundColor(Color aBackgroundColor);

        Color getForegroundColor();
        void setForegroundColor(Color aForegroundColor);

        void enableClip(float x, float y, float width, float height);
        void disableClip();

        void enableBlending(GLenum aSourceBlending = GL_SRC_ALPHA, GLenum aDestinationBlending = GL_ONE_MINUS_SRC_ALPHA);
        void disableBlending();

        float getPointSize();
        void setPointSize(float pointSize);
        void resetPointSize();
    
        float getLineWidth();
        void setLineWidth(float lineWidth);
        void resetLineWidth();

        //Vertex Array
        void drawPoint(float x, float y);
        void drawLine(float x1, float y1, float x2, float y2);
        void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
        void drawCircle(float x, float y, float aRadius, bool aIsFilled = true, int aLineSegments = 36);
        void drawRectangle(float x, float y, float aWidth, float aHeight, bool aIsFilled = true);

        void drawPolygon(GLenum aRenderMode, float * aVertices, int aVertexSize, int aVertexCount);
        void drawPolygon(GLenum aRenderMode, float * aVertices, int aVertexSize, int aVertexCount, float * aColors, int aColorSize);

        void drawTexture(Texture * aTexture, float x, float y, float aAngle = 0.0f);
        void drawTexture(Texture * aTexture, float x, float y, float aWidth, float aHeight, float aAngle = 0.0f);
        void drawTexture(Texture * aTexture, float * aTexCoordinates, float * aVertices);

        


        //Vertex Buffer


        void checkForErrors();
    private:
        Renderer();
        ~Renderer();
        static Renderer * s_Instance;

        bool m_Initialized;
        Color m_BackgroundColor;
        Color m_ForegroundColor;


    };
}

#endif