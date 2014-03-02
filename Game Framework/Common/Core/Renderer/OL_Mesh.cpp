#include "OL_Mesh.h"
#include "OL_VertexAttribute.h"

namespace OnLooker
{
    Mesh::Mesh()
    {
    }
    Mesh::~Mesh()
    {
        cleanUpVertices();
    }

    void Mesh::setVertices(VertexAttribute * aVertices, int aCount)
    {
        if(m_Vertices != 0)
        {
            cleanUpVertices();
        }
        m_Vertices = aVertices;
        m_VerticesCount = aCount;
    }
    VertexAttribute * Mesh::getVertices()
    {
        return m_Vertices;
    }
    int Mesh::getVerticesCount()
    {
        return m_VerticesCount;
    }
    void Mesh::cleanUpVertices()
    {
        if(m_Vertices != 0)
        {
            delete m_Vertices;
            m_Vertices = 0;
        }
        m_VerticesCount = 0;
    }
}