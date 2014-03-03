#ifndef OL_VERTEX_ATTRIBUTE_H
#define OL_VERTEX_ATTRIBUTE_H

namespace OnLooker
{
    
    struct VertexAttribute
    {
        struct Color
        {
            float red;
            float green;
            float blue;
            float alpha;
        };
        struct Position
        {
            float x;
            float y;
        };
        struct TexCoord
        {
            float u;
            float v;
        };
        Position m_Position;
        Color m_Color;
        TexCoord m_TexCoords;
        
    };

}

#endif