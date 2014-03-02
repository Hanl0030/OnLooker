#ifndef OL_TEXTURE_H
#define OL_TEXTURE_H

#include <string>
#include "../../Libraries/OL_OpenGL.h"
#include "OL_Color.h"



namespace OnLooker
{

    class Color;

    class Texture
    {
    public:
        Texture();
        Texture(unsigned int aID, unsigned int aFileWidth, unsigned int aFileHeight, std::string aFilename, std::string aTextureName);
        Texture(unsigned int aID, unsigned int aFileWidth, unsigned int aFileHeight, std::string aFilename, std::string aTextureName, std::string aTextureCoordinateName,
            unsigned int aSourceWidth, unsigned int aSourceHeight, unsigned int aSourceX, unsigned int aSourceY);


        unsigned int getID();
        unsigned int getFileWidth();
        unsigned int getFileHeight();

        std::string getFilename();
        std::string getTextureName();

        std::string getTextureCoordinateName();
        unsigned int getSourceWidth();
        unsigned int getSourceHeight();
        unsigned int getSourceX();
        unsigned int getSourceY();
        float getMinU();
        float getMinV();
        float getMaxU();
        float getMaxV();


        float getAnchorPointX();
        float getAnchorPointY();

        GLenum getFormat();

        float getAlpha();
        float getRed();
        float getGreen();
        float getBlue();
        Color getColor();

        void setColor(Color aColor);

    private:
        unsigned int m_ID;
        unsigned int m_FileWidth;
        unsigned int m_FileHeight;
        std::string m_Filename;
        std::string m_TextureName;

        std::string m_TextureCoordinateName;
        unsigned int m_SourceWidth;
        unsigned int m_SourceHeight;
        unsigned int m_SourceX;
        unsigned int m_SourceY;


        float m_MinU;
        float m_MinV;
        float m_MaxU;
        float m_MaxV;

        Color m_TextureColor;

    };
}

#endif