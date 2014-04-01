#ifndef OL_VECTOR_3_H
#define OL_VECTOR_3_H


#include "../Core/Base Objects/OL_Object.h"

namespace OnLooker
{
    class Vector2;

    class Vector3 : public Object
    {
    public:
        Vector3();
        Vector3(float aX, float aY, float aZ);
        Vector3(float aX, Vector2 aVec);
        Vector3(Vector2 aVec, float aZ);
        ~Vector3();

        const float getLength() const;
        const float getLengthSquared() const;
        const Vector3 getNegative() const;

        void normalize();
        float dotProduct(const Vector3 & aVec) const;
        static float dotProduct(const Vector3 & aVecA, const Vector3 & aVecB);
        Vector3 crossProduct(const Vector3 & aVec) const;
        static Vector3 crossProduct(const Vector3 & aVecA, const Vector3 & aVecB);

        //arithmetic
        static Vector3 & add(const Vector3 & aVecA, const Vector3 & aVecB,  Vector3 & aResult);
        static Vector3 & subtract(const Vector3 & aVecA, const Vector3 & aVecB,  Vector3 & aResult);
        static Vector3 & scale(const Vector3 & aVec, const float & aScale,  Vector3 & aResult);
        static bool equal(const Vector3 & aVecA, const Vector3 & aVecB);
    
        //Operators
        Vector3 operator +  (const Vector3 & aVec) const;
        Vector3 operator += (const Vector3 & aVec);
        Vector3 operator -  (const Vector3 & aVec) const;
        Vector3 operator -= (const Vector3 & aVec);
        Vector3 operator *  (const float & aScale) const;
        Vector3 operator *= (const float & aScale);
        Vector3 operator /  (const float & aScale) const;
        Vector3 operator /= (const float & aScale);
        Vector3 operator ^  (const Vector3 & aVec) const;
        float   operator *  (const Vector3 & aVec) const;
        Vector3 operator -  () const;
        bool    operator == (const Vector3 & aVec) const;
        bool    operator != (const Vector3 & aVec) const;
        float & operator []  (const int & aRow);

        //Variables
        void set(float aX, float aY, float aZ);
        void set(float aX, const Vector2 & aVec);
        void set(const Vector2 & aVec, float aZ);
        void set(const Vector3 & aVec);
        float x;
        float y;
        float z;

        //Overrides
        std::string toString();
        const char * getType();

        static Vector3 & up();
        static Vector3 & down();
        static Vector3 & forward();
        static Vector3 & back();
        static Vector3 & left();
        static Vector3 & right();
        static Vector3 & zero();
        static Vector3 & one();

    };

}

#endif