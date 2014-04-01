#include "OL_Math.h"
#include "../Utilities/OL_Utilities.h"

namespace OnLooker
{
        Vector3::Vector3()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
        Vector3::Vector3(float aX, float aY, float aZ)
        {
            x = aX;
            y = aY;
            z = aZ;
        }
        Vector3::Vector3(float aX, Vector2 aVec)    
        {
            x = aX;
            y = aVec.x;
            z = aVec.y;
        }
        Vector3::Vector3(Vector2 aVec, float aZ)     
        {
            x = aVec.x;
            y = aVec.y;
            z = aZ;
        }
        Vector3::~Vector3()                         
        {
        }

        const float Vector3::getLength() const
        {
            return sqrt((x*x) + (y*y) + (z*z));
        }
        const float Vector3::getLengthSquared() const
        {
            return (x*x) + (y*y) + (z*z); 
        }
        const Vector3 Vector3::getNegative() const
        {
            return Vector3(-x,-y,-z);
        }

        void Vector3::normalize()
        {
            float length = getLength();

            x /= length;
            y /= length;
            z /= length;
        }
        float Vector3::dotProduct(const Vector3 & aVec) const
        {
            return (x * aVec.x) + ( y * aVec.y ) + (z * aVec.z);
        }
        float Vector3::dotProduct(const Vector3 & aVecA, const Vector3 & aVecB)
        {
            return (aVecA.dotProduct(aVecB));
        }
        Vector3 Vector3::crossProduct(const Vector3 & aVec) const
        {
            return Vector3::crossProduct(*this,aVec);
        }
        Vector3 Vector3::crossProduct(const Vector3 & aVecA, const Vector3 & aVecB)
        {
            Vector3 result;
            result.x = aVecA.y * aVecB.z - aVecA.z * aVecB.y;
            result.y = aVecA.z * aVecB.x - aVecA.x * aVecB.z;
            result.z = aVecA.x * aVecB.y - aVecA.y * aVecB.x;

            return result;
        }

        //arithmetic
        Vector3 & Vector3::add(const Vector3 & aVecA, const Vector3 & aVecB,  Vector3 & aResult)
        {
            aResult.x = aVecA.x + aVecB.x;
            aResult.y = aVecA.y + aVecB.y;
            aResult.z = aVecA.z + aVecB.z;

            return aResult;
        }
        Vector3 & Vector3::subtract(const Vector3 & aVecA, const Vector3 & aVecB,  Vector3 & aResult)
        {

            aResult.x = aVecA.x - aVecB.x;
            aResult.y = aVecA.y - aVecB.y;
            aResult.z = aVecA.z - aVecB.z;

            return aResult;
        }
        Vector3 & Vector3::scale(const Vector3 & aVec, const float & aScale,  Vector3 & aResult)
        {
            aResult.x = aVec.x * aScale;
            aResult.y = aVec.y * aScale;
            aResult.z = aVec.z * aScale;

            return aResult;
        }
        bool Vector3::equal(const Vector3 & aVecA, const Vector3 & aVecB)
        {
            if(fabs(aVecA.x - aVecB.x) > 1.0e-7f)
            {
		        return false;
            }

	        if(fabs(aVecA.y - aVecB.y) > 1.0e-7f)
		    {
		        return false;
            }

	        if(fabs(aVecA.z - aVecB.z) > 1.0e-7f)
		    {
		        return false;
            }

	        return true;
        }
    
        //Operators
        Vector3 Vector3::operator+  (const Vector3 & aVec) const
        {
            Vector3 result;
            return add(*this, aVec, result);
        }
        Vector3 Vector3::operator+= (const Vector3 & aVec)     
        {
            return add(*this,aVec,*this);
        }
        Vector3 Vector3::operator-  (const Vector3 & aVec) const
        {
            Vector3 result;
            return subtract(*this,aVec,result);
        }
        Vector3 Vector3::operator-= (const Vector3 & aVec)      
        {
            return subtract(*this,aVec,*this);
        }
        Vector3 Vector3::operator*  (const float & aScale) const
        {
            Vector3 result;
            return scale(*this, aScale, result);
        }
        Vector3 Vector3::operator*= (const float & aScale)     
        {
            return scale(*this,aScale,*this);
        }
        Vector3 Vector3::operator/  (const float & aScale) const
        {
            Vector3 result;
            return scale(*this,1.0f/aScale,result);
        }
        Vector3 Vector3::operator/= (const float & aScale)      
        {
            return scale(*this,1.0f/aScale,*this);
        }
        Vector3 Vector3::operator^  (const Vector3 & aVec) const
        {
            return crossProduct(*this,aVec);
        }
        float   Vector3::operator*  (const Vector3 & aVec) const
        {
            return dotProduct(*this,aVec);
        }
        Vector3 Vector3::operator-  () const                    
        {
            return getNegative();
        }
        bool    Vector3::operator== (const Vector3 & aVec) const
        {
            return equal(*this,aVec);
        }
        bool    Vector3::operator!= (const Vector3 & aVec) const
        {
            return -equal(*this,aVec);
        }
        float & Vector3::operator[]  (const int & aRow)
        {
            if(aRow == 0)
            {
                return x;
            }
            if(aRow == 1)
            {
                return y;
            }
            if(aRow == 2)
            {
                return z;
            }
            return x;
        }


        //Variables
        void Vector3::set(float aX, float aY, float aZ)
        {
            x = aX;
            y = aY;
            z = aZ;
        }
        void Vector3::set(float aX, const Vector2 & aVec)
        {
            x = aX;
            y = aVec.x;
            z = aVec.y;
        }
        void Vector3::set(const Vector2 & aVec, float aZ)
        {
            x = aVec.x;
            y = aVec.y;
            z = aZ;
        }
        void Vector3::set(const Vector3 & aVec)
        {
            x = aVec.x;
            y = aVec.y;
            z = aVec.z;
        }
        float x;
        float y;
        float z;

        //Overrides
        std::string Vector3::toString()
        {
            return "X:" + convertFloatToString(x) + " Y:" + convertFloatToString(y) + " Z:" + convertFloatToString(z);
        }
        const char * Vector3::getType()
        {
            return "Vector3";
        }

        Vector3 & Vector3::up()      
        {
            return Vector3(0.0f,1.0f,0.0f);
        }
        Vector3 & Vector3::down()   
        {
            return Vector3(0.0f,-1.0f,0.0f);
        }
        Vector3 & Vector3::forward()
        {
            return Vector3(0.0f,0.0f,1.0f);
        }
        Vector3 & Vector3::back()   
        {
            return Vector3(0.0f,0.0f,-1.0f);
        }
        Vector3 & Vector3::left()  
        {
            return Vector3(-1.0f,0.0f,0.0f);
        }
        Vector3 & Vector3::right()  
        {
            return Vector3(1.0f,0.0f,0.0f);
        }
        Vector3 & Vector3::zero()
        {
            return Vector3(0.0f,0.0f,0.0f);
        }
        Vector3 & Vector3::one()
        {
            return Vector3(1.0f,1.0f,1.0f);
        }
}