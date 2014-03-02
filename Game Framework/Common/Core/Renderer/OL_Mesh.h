#ifndef OL_MESH_H
#define OL_MESH_H

namespace OnLooker
{
    struct VertexAttribute;

    class Mesh
    {
    public:
        Mesh();
        ~Mesh();

        void setVertices(VertexAttribute * aVertices, int aCount);
        VertexAttribute * getVertices();
        int getVerticesCount();
    private:
        void cleanUpVertices();

        VertexAttribute * m_Vertices;
        int m_VerticesCount;
    };

};

#endif