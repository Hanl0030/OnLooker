#ifndef OL_MATRIX_3_X_3_H
#define OL_MATRIX_3_X_3_H

#include "../Core/Base Objects/OL_Object.h"

namespace OnLooker
{
    class Vector3;

    class Matrix3x3 : public Object
    {
    public:
        Matrix3x3();
        Matrix3x3(float aCols[], float aRows[] );
        Matrix3x3(Vector3 aCols[]);
        ~Matrix3x3();

        void set(int aIndex, float aValue);
        void set(int aCol, int aRow, float aValue);
        float get(int aIndex);
        float get(int aCol, int aRow);
        void getMatrix(float * aMatrix) const;
        const float getDeterminant() const;
        const Matrix3x3 getNegative() const;
        const Matrix3x3 getTranspose() const;
        const Matrix3x3 getInverse() const;

        void setIdentity();
        void transpose();
        void inverse();

        //Arithmetic
        static Matrix3x3 & add( const Matrix3x3 & aMatrixA, const  Matrix3x3 & aMatrixB, Matrix3x3 & aResult);
        static Matrix3x3 & subtract(const Matrix3x3 & aMatrixA, const Matrix3x3 & aMatrixB, Matrix3x3 & aResult);
        static Matrix3x3 & scale(const Matrix3x3 & aMatrix, const float & aScale, Matrix3x3 & aResult);
        static Matrix3x3 & multiply(const Matrix3x3 & aMatrixA, const Matrix3x3 & aMatrixB, Matrix3x3 & aResult);
        static Vector2   & multiply(const Matrix3x3 & aMatrix, const Vector2 & aVec, Vector2 & aResult);
        static bool equal(const Matrix3x3 & aMatrixA, const Matrix3x3 & aMatrixB);

        // Operators
	    Matrix3x3   operator+(const Matrix3x3 & aMatrix) const;        // { Matrix3x3 result; return Add(*this, m, result); }
	    Matrix3x3 & operator+=(const Matrix3x3 &aMatrix);             //{ Add(*this, m, *this); return *this; }
	    Matrix3x3   operator-(const Matrix3x3 &aMatrix) const;        // { Matrix3x3 result; return Subtract(*this, m, result); }
	    Matrix3x3 & operator-=(const Matrix3x3 &aMatrix);             // { Subtract(*this, m, *this); return *this; }
	    Matrix3x3   operator*(const float & aScale) const;            // { Matrix3x3 result; return Scale(*this, sca, result); }
	    Matrix3x3 & operator*=(const float & aScale);                 // { Scale(*this, sca, *this); return *this; }
	    Matrix3x3   operator/(const float & aScale) const;            // { Matrix3x3 result; return Scale(*this, (1/sca), result); }
	    Matrix3x3 & operator/=(const float & aScale);                 // { Scale(*this, (1/sca), *this); return *this; }
	    Matrix3x3   operator*(const Matrix3x3 & aMatrix);             // { Matrix3x3 result; return Multiply(*this, m, result); }
	    Vector2     operator*(const Vector2 & aVec);                  // { Vector3d result; return Multiply(*this, v, result); }
	    bool        operator==(const Matrix3x3 & aMatrix);            // const { return equal(*this, m); };
	    bool        operator!=(const Matrix3x3 & aMatrix) ;           // const { return !equal(*this, m); };
        float &     operator() (const int aCol, const int aRow);
       
        //Overrides
        const char * getType();
        std::string toString();

        float m_Matrix[9];
    private:
        
       
    };

}

#endif