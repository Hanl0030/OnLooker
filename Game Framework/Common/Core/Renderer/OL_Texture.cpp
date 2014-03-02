#include "OL_Texture.h"

using namespace std;

namespace OnLooker
{
    Texture::Texture()
    {
        m_ID = 0;
        m_FileWidth = 0;
        m_FileHeight = 0;
    }
    Texture::Texture(unsigned int aID, unsigned int aFileWidth, unsigned int aFileHeight, string aFilename, string aTextureName)
    {
        m_ID = aID;
        m_FileWidth = aFileWidth;
        m_FileHeight = aFileHeight;
        m_Filename = aFilename;
        m_TextureName = aTextureName;
    }
    Texture::Texture(unsigned int aID, unsigned int aFileWidth, unsigned int aFileHeight, std::string aFilename, std::string aTextureName, std::string aTextureCoordinateName,
            unsigned int aSourceWidth, unsigned int aSourceHeight, unsigned int aSourceX, unsigned int aSourceY)
    {
        m_ID = aID;
        m_FileWidth = aFileWidth;
        m_FileHeight = aFileHeight;
        m_Filename = aFilename;
        m_TextureName = aTextureName;
        m_TextureCoordinateName = aTextureCoordinateName;
        m_SourceWidth = aSourceWidth;
        m_SourceHeight = aSourceHeight;
        m_SourceX = aSourceX;
        m_SourceY = aSourceY;

        float width = (float)m_FileWidth;
        float height = (float)m_FileHeight;

        float sourceX = (float)m_SourceX;
        float sourceY = (float)m_SourceY;
        float sourceWidth = (float)m_SourceWidth;
        float sourceHeight = (float)m_SourceHeight;

        m_MinU = sourceX / width;
        m_MaxU = sourceY / width;
        m_MinV = sourceWidth / height;
        m_MaxV = sourceHeight / height;

    }


    unsigned int Texture::getID()
    {
        return m_ID;
    }
    unsigned int Texture::getFileWidth()
    {
        return m_FileWidth;
    }
    unsigned int Texture::getFileHeight()
    {
        return m_FileHeight;
    }

    string Texture::getFilename()
    {
        return m_Filename;
    }
    string Texture::getTextureName()
    {
        return m_TextureName;
    }
    string Texture::getTextureCoordinateName()
    {
        return m_TextureCoordinateName;
    }
    unsigned int Texture::getSourceWidth()
    {
        return m_SourceWidth;
    }
    unsigned int Texture::getSourceHeight()
    {
        return m_SourceHeight;
    }
    unsigned int Texture::getSourceX()
    {
        return m_SourceX;
    }
    unsigned int Texture::getSourceY()
    {
        return m_SourceY;
    }
    float Texture::getMinU()
    {
        return m_MinU;
    }
    float Texture::getMinV()
    {
        return m_MinV;
    }
    float Texture::getMaxU()
    {
        return m_MaxU;
    }
    float Texture::getMaxV()
    {
        return m_MaxV;
    }

    float Texture::getAnchorPointX()
    {
        return 0.0f;
    }
    float Texture::getAnchorPointY()
    {
        return 0.0f;
    }

    GLenum Texture::getFormat()
    {
        return GL_RGBA;
    }

    float Texture::getAlpha()
    {
        return m_TextureColor.alpha;
    }
    float Texture::getRed()
    {
        return m_TextureColor.red;
    }
    float Texture::getGreen()
    {
        return m_TextureColor.green;
    }
    float Texture::getBlue()
    {
        return m_TextureColor.blue;
    }
    Color Texture::getColor()
    {
        return m_TextureColor;
    }

    void Texture::setColor(Color aColor)
    {
        m_TextureColor = aColor;
    }
}