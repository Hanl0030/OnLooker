#include "OL_Renderer.h"
#include "../../Utilities/OL_Utilities.h"

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
        m_Initialized = false;
    }
    Renderer::~Renderer()
    {

    }
    bool Renderer::isReadyInitalized()
    {
        return m_Initialized;
    }
    void Renderer::initialize(double aWindowWidth, double aWindowHeight)
    {
        
        Debug::console->output("SetupContext-Begin-\n");
        glViewport(0,0,aWindowWidth,aWindowHeight);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0,aWindowWidth,aWindowHeight,0.0,-1.0,1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        setBackgroundColor(Colors::cornflowerBlue());
        setForegroundColor(Colors::turquoise());
        enableBlending();
        //Check Errors
        checkForErrors();
        m_Initialized = true;

        
        Debug::console->output("SetupContext-End-\n");
    }

    void Renderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    Color Renderer::getBackgroundColor()
    {
        return m_BackgroundColor;
    }
    void Renderer::setBackgroundColor(Color aBackgroundColor)
    {
        m_BackgroundColor = aBackgroundColor;
        glClearColor(m_BackgroundColor.red,m_BackgroundColor.green,m_BackgroundColor.blue,m_BackgroundColor.alpha);
    }

    Color Renderer::getForegroundColor()
    {
        return m_ForegroundColor;
    }
    void Renderer::setForegroundColor(Color aForegroundColor)
    {
        m_ForegroundColor = aForegroundColor;
    }

    void Renderer::enableClip(float x, float y, float width, float height)
    {
        glEnable(GL_SCISSOR_TEST);
        glScissor(x, y, width, height);
    }
    void Renderer::disableClip()
    {
        glDisable(GL_SCISSOR_TEST);
    }


    void Renderer::enableBlending(GLenum aSourceBlending, GLenum aDestinationBlending )
    {
        glEnable(GL_BLEND);
        glBlendFunc(aSourceBlending, aDestinationBlending);
    }
    void Renderer::disableBlending()
    {
        glDisable(GL_BLEND);
    }

    float Renderer::getPointSize()
    {
        float pointSize;
        glGetFloatv(GL_POINT_SIZE, &pointSize);
        return pointSize;
    }
    void Renderer::setPointSize(float aPointSize)
    {
        glPointSize(aPointSize);
    }
    void Renderer::resetPointSize()
    {
        setPointSize(1.0f);
    }
    
    float Renderer::getLineWidth()
    {
        float lineWidth;
        glGetFloatv(GL_LINE_WIDTH, &lineWidth);
        return lineWidth;
    }
    void Renderer::setLineWidth(float aLineWidth)
    {
        glLineWidth(aLineWidth);
    }
    void Renderer::resetLineWidth()
    {
        setLineWidth(1.0f);
    }


    void Renderer::drawPoint(float x, float y)
    {
        float vertices[] = { x, y };
	    int vertexSize = 2;
	    int vertexCount = 1;
	    drawPolygon(GL_POINTS, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawLine(float x1, float y1, float x2, float y2)
    {
        float vertices[] = { x1, y1, x2, y2 };
	    int vertexSize = 2;
	    int vertexCount = 2;
	    drawPolygon(GL_LINES, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
    {
        float vertices[] = { x1, y1, x2, y2, x3, y3 };
	    int vertexSize = 2;
	    int vertexCount = 3;
        drawPolygon(GL_TRIANGLES, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawCircle(float x, float y, float aRadius, bool aIsFilled, int aLineSegments )
    {
        int vertexSize = 2;
	    int vertexCount = aLineSegments;
	    float *  vertices = new float[vertexCount * vertexSize];
    
	    float rotationAmount = (360.0f / aLineSegments);
    
	    int count = 0;
	    for (float i = 0; i < 359.99f; i+= rotationAmount)
	    {
		    vertices[count++] = x + (cosf((M_PI * i / 180.0)) * aRadius);
            vertices[count++] = y + (sinf((M_PI * i / 180.0)) * aRadius);
	    }
    
	    drawPolygon(aIsFilled ? GL_TRIANGLE_FAN : GL_LINE_LOOP, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawRectangle(float x, float y, float aWidth, float aHeight, bool aIsFilled )
    {
        const int vertexSize = 2;
	    const int vertexCount = 4;
	    float vertices[vertexSize * vertexCount];
    
	    vertices[0] = x;          vertices[1] = y;
	    vertices[2] = x + aWidth; vertices[3] = y;
	    vertices[4] = x + aWidth; vertices[5] = y + aHeight;
	    vertices[6] = x;          vertices[7] = y + aHeight;

    
	drawPolygon(aIsFilled ? GL_TRIANGLE_FAN : GL_LINE_LOOP, vertices, vertexSize, vertexCount);
    }

    void Renderer::drawPolygon(GLenum aRenderMode, float * aVertices, int aVertexSize, int aVertexCount)
    {
        //Setup the colors array based on the foreground color
	    int colorSize = 4;
	    float * colors = new float[colorSize * aVertexCount];
	    int count = 0;
	    for (int i = 0; i < aVertexCount; ++i)
	    {
		    colors[count++] = m_ForegroundColor.red;
            colors[count++] = m_ForegroundColor.green;
            colors[count++] = m_ForegroundColor.blue;
            colors[count++] = m_ForegroundColor.alpha;
	    }
    
	    //If the foreground alpha isn't full, enable blending
	    if(m_ForegroundColor.alpha != 1.0f)
	    {
		    enableBlending();
	    }
	    //Draw the polygon
	    drawPolygon(aRenderMode, aVertices, aVertexSize, aVertexCount, colors, colorSize);
    
	    //If the foreground alpha isn't full, blending is enabled, disable it
	    if(m_ForegroundColor.alpha != 1.0f)
	    {
		    disableBlending();
	    }
    }
    void Renderer::drawPolygon(GLenum aRenderMode, float * aVertices, int aVertexSize, int aVertexCount, float * aColors, int aColorSize)
    {
        //Enable the vertex array
	    glEnableClientState(GL_VERTEX_ARRAY);
	    glVertexPointer(aVertexSize, GL_FLOAT, 0, aVertices);
	    //Enable the color array
	    glEnableClientState(GL_COLOR_ARRAY);
	    glColorPointer(aColorSize, GL_FLOAT, 0, aColors);
    
	    //Render the polygon.
	    glDrawArrays(aRenderMode, 0, aVertexCount);
    
	    //Disable the vertex array client state.
	    glDisableClientState(GL_VERTEX_ARRAY);
	    glDisableClientState(GL_COLOR_ARRAY);
    }

    void Renderer::drawTexture(Texture * aTexture, float x, float y, float aAngle )
    {
        /*if(aTexture != NULL)
        {
            drawTexture(aTexture, x, y, aTexture->getSourceWidth(), aTexture->getSourceHeight(), aAngle);
        }*/
    }
    void Renderer::drawTexture(Texture * aTexture, float x, float y, float aWidth, float aHeight, float aAngle)
    {
        /*//Safety check the texture
	    if(aTexture != NULL)
	    {
            float uvCoordinates[8];
		    float vertices[8];
        
		
		    uvCoordinates[0] = aTexture->getMinU(); uvCoordinates[1] = aTexture->getMinV();
		    uvCoordinates[2] = aTexture->getMaxU(); uvCoordinates[3] = aTexture->getMinV();
		    uvCoordinates[4] = aTexture->getMaxU(); uvCoordinates[5] = aTexture->getMaxV();
		    uvCoordinates[6] = aTexture->getMaxU(); uvCoordinates[7] = aTexture->getMaxV();
        
		    //Set the vertices
		    vertices[0] = 0.0f;           vertices[1] = 0.0f + aHeight;
		    vertices[2] = 0.0f + aWidth;  vertices[3] = 0.0f + aHeight;
		    vertices[4] = 0.0f;           vertices[5] = 0.0f;
		    vertices[6] = 0.0f + aWidth; 	vertices[7] = 0.0f;
        
            //Push the Matrix
            glPushMatrix();
        
            //Translate the texture
            glTranslatef(x - (aTexture->getSourceWidth() * aTexture->getAnchorPointX()), y - (aTexture->getSourceHeight() * aTexture->getAnchorPointY()), 0.0f);
        
            //Rotate the texture
            if(aAngle != 0.0f)
            {
                //Rotate around the center of the texture.
                glTranslatef(aWidth/2, aHeight/2, 0.0f);
                glRotatef(aAngle, 0.0f, 0.0f, 1.0f);
                glTranslatef(-aWidth/2, -aHeight/2, 0.0f);
            }
        
		    //Draw the texture
		    drawTexture(aTexture, uvCoordinates, vertices);
        
            //Pop the Matrix
            glPopMatrix();
        }*/
    }

    void Renderer::drawTexture(Texture * aTexture, float * aTexCoordinates, float * aVertices)
    {
        /*if(aTexture != NULL)
	    {
		    int vertexCount = 4;
		    int vertexSize = 2;
        
		    //Setup the colors array based on the foreground color
		    bool hasTransparency = aTexture->getFormat() == GL_RGBA || aTexture->getAlpha() != 1.0f;
		    int colorSize = hasTransparency ? 4 : 3;
		    float * colors = new float[colorSize * vertexCount];
		    int count = 0;
		    for (int i = 0; i < vertexCount; ++i)
		    {
			    colors[count++] = aTexture->getColor().red;
			    colors[count++] = aTexture->getColor().green;
			    colors[count++] = aTexture->getColor().blue;
			    if(colorSize == 4)
			    {
				    colors[count++] = aTexture->getAlpha();
			    }
		    }
        
		    //If the foreground alpha isn't full, enable blending
		    if(hasTransparency == true)
		    {
			    enableBlending();
		    }
        
            //Set the uvCoordinates of the texture.
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, aTexCoordinates);
        
		    //Enable the texture and bind it
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, aTexture->getID());
        
		    //Draw the texture
		    drawPolygon(GL_TRIANGLE_STRIP, aVertices, vertexSize, vertexCount, colors, colorSize);
        
            //Disable the client states
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glDisable(GL_TEXTURE_2D);
        
		    //If the foreground alpha isn't full, blending is enabled, disable it
		    if(hasTransparency == true)
		    {
			    disableBlending();
		    }
	    }*/
    }

    void Renderer::checkForErrors()
    {
        int error = glGetError();

        while(error != GL_NO_ERROR)
        {
            switch(error)
            {
            case GL_INVALID_ENUM:
                    Debug::console->output("GL_INVALID_ENUM");
                break;
            case GL_INVALID_VALUE:
                    Debug::console->output("GL_INVALID_VALUE");
                break;
            case GL_INVALID_OPERATION:
                    Debug::console->output("GL_INVALID_OPERATION");
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                    Debug::console->output("GL_INVALID_FRAMEBUFFER_OPERATION");
                break;

                
            }

            error = glGetError();
        }
    }

    
}