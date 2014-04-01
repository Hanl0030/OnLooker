#ifndef OL_VECTOR_2_H
#define OL_VECTOR_2_H

#include "../Core/Base Objects/OL_Object.h"

namespace OnLooker
{

    class Vector2 : public Object
    {
    public:
        //Initializers
        Vector2();
        Vector2(float x, float y);
        ~Vector2();

        //Helpers
        const float getLength() const;
        const float getLengthSquared() const;
        void normalize();
        const Vector2 getNegative() const;
        float dotProduct(const Vector2 & aVec) const;
        static float dotProduct(const Vector2 & aVecA, const Vector2 & aVecB);

        //Arithmetic
        static Vector2 & add(const Vector2 & aVecA, const Vector2 & aVecB,  Vector2 & aResult);
        static Vector2 & subtract(const Vector2 & aVecA, const Vector2 & aVecB,  Vector2 & aResult);
        static Vector2 & scale(const Vector2 & aVec, const float & aScale,  Vector2 & aResult);
        static bool equal(const Vector2 & aVecA, const Vector2 & aVecB);

        //Operators
        Vector2 operator +  (const Vector2 & aVec) const;
        Vector2 operator += (const Vector2 & aVec);
        Vector2 operator -  (const Vector2 & aVec) const;
        Vector2 operator -= (const Vector2 & aVec);
        Vector2 operator *  (const float & aScale) const;
        Vector2 operator *= (const float & aScale);
        Vector2 operator /  (const float & aScale) const;
        Vector2 operator /= (const float & aScale);
        float   operator *  (const Vector2 & aVec) const;
        Vector2 operator -  () const;
        bool    operator == (const Vector2 & aVec) const;
        bool    operator != (const Vector2 & aVec) const;


        //Variables
        void set(float aX, float aY);
        void set(const Vector2 & aVec);
        float x;
        float y;

        //Overrides
        std::string toString();
        const char * getType();

        static Vector2 & up();
        static Vector2 & down();
        static Vector2 & left();
        static Vector2 & right();
        static Vector2 & zero();
        static Vector2 & one();
    };
}

#endif