#include "OL_Math.h"
#include "../Utilities/OL_Utilities.h"

namespace OnLooker
{
    Vector2::Vector2()
    {
        x = 0.0f;
        y = 0.0f;
    }
    Vector2::Vector2(float aX, float aY)
    {
        x = aX;
        y = aY;
    }
    Vector2::~Vector2()
    {
    
    }

    const float Vector2::getLength() const
    {
        return sqrt((x * x) + (y * y));
    }
    const float Vector2::getLengthSquared() const
    {
        return (x*x) + (y*y);
    }
    void Vector2::normalize()
    {
        float length = getLength();
        x /= length;
        y /= length;
    }
    const Vector2 Vector2::getNegative() const
    {
        return Vector2(-x,-y);
    }
        
    float Vector2::dotProduct(const Vector2 & aVec) const
    {
        return (x * aVec.x) + (y * aVec.y);
    }
    float Vector2::dotProduct(const Vector2 & aVecA, const Vector2 & aVecB)
    {
        return aVecA.dotProduct(aVecB);
    }

    Vector2 & Vector2::add(const Vector2 & aVecA, const Vector2 & aVecB,  Vector2 & aResult)
    {
        aResult.x = aVecA.x + aVecB.x;
        aResult.y = aVecA.y + aVecB.y;
        return aResult;
    }
    Vector2 & Vector2::subtract(const Vector2 & aVecA, const Vector2 & aVecB,  Vector2 & aResult)
    {
        aResult.x = aVecA.x - aVecB.x;
        aResult.y = aVecA.y - aVecB.y;
        return aResult;
    }
    Vector2 & Vector2::scale(const Vector2 & aVec, const float & aScale,  Vector2 & aResult)
    {
        aResult.x = aVec.x * aScale;
        aResult.y = aVec.y * aScale;
        return aResult;
    }
    bool Vector2::equal(const Vector2 & aVecA, const Vector2 & aVecB)
    {
        if(fabs(aVecA.x - aVecB.x) > 1.0e-7f)
        {
            return false;
        }
        if(fabs(aVecA.y - aVecB.y) > 1.0e-7)
        {
            return false;
        }
        return true;
    }


    

    Vector2 Vector2::operator+  (const Vector2 & aVec) const
    {
        Vector2 result;
        return add(*this,aVec,result);
    }
    Vector2 Vector2::operator+= (const Vector2 & aVec)
    {
        add(*this,aVec,*this);
        return *this;
    }
    Vector2 Vector2::operator-  (const Vector2 & aVec) const
    {
        Vector2 result;
        return subtract(*this,aVec,result);
    }
    Vector2 Vector2::operator-= (const Vector2 & aVec) 
    {
        return subtract(*this,aVec,*this);
    }
    Vector2 Vector2::operator*  (const float & aScale) const
    {
        Vector2 result;
        return scale(*this,aScale,result);
    }
    Vector2 Vector2::operator*= (const float & aScale) 
    {
        return scale(*this,aScale,*this);
    }
    Vector2 Vector2::operator/  (const float & aScale) const
    {
        Vector2 result;
        return scale(*this,1.0f/aScale,result);
    }
    Vector2 Vector2::operator/= (const float & aScale) 
    {
        return scale(*this,1.0f/aScale,*this);
    }
    float   Vector2::operator*  (const Vector2 & aVec) const
    {
        return dotProduct(*this,aVec);
    }
    Vector2 Vector2::operator-  () const                
    {
        return getNegative();
    }
    bool    Vector2::operator== (const Vector2 & aVec) const
    {
        return equal(*this,aVec);
    }
    bool    Vector2::operator!= (const Vector2 & aVec) const
    {
        return !equal(*this,aVec);
    }

    void Vector2::set(float aX, float aY)
    {
        x = aX;
        y = aY;
    }
    void Vector2::set(const Vector2 & aVec)
    {
        x = aVec.x;
        y = aVec.y;
    }

    std::string Vector2::toString()
    {
        return "X:" + convertFloatToString(x) + " Y:" + convertFloatToString(y);
    }
    const char * Vector2::getType()
    {
        return "Vector2";
    }

    Vector2 & Vector2::up()
    {
        return Vector2(0.0f,1.0f);
    }
    Vector2 & Vector2::down()  
    {
        return Vector2(0.0f,-1.0f);
    }
    Vector2 & Vector2::left() 
    {
        return Vector2(-1.0f,0.0f);
    }
    Vector2 & Vector2::right() 
    {
        return Vector2(1.0f,0.0f);
    }
    Vector2 & Vector2::zero()  
    {
        return Vector2(0.0f,0.0f);
    }
    Vector2 & Vector2::one()  
    {
        return Vector2(1.0f,1.0f);
    }

}