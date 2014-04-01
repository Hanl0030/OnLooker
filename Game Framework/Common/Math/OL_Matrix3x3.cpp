#include "OL_Math.h"
#include "../Utilities/OL_Utilities.h"

namespace OnLooker
{

	const int m11 = 0;
	const int m12 = 1;
	const int m13 = 2;
	const int m21 = 3;
	const int m22 = 4;
	const int m23 = 5;
	const int m31 = 6;
	const int m32 = 7;
	const int m33 = 8;

    Matrix3x3::Matrix3x3()
    {

    }
    Matrix3x3::Matrix3x3(float aCols[], float aRows[] )
    {

    }
    Matrix3x3::Matrix3x3(Vector3 aCols[])          
    {

    }
    Matrix3x3::~Matrix3x3()                         
    {

    }
    void Matrix3x3::set(int aIndex, float aValue)
    {
        m_Matrix[aIndex] = aValue;
    }
    void Matrix3x3::set(int aCol, int aRow, float aValue)
    {
        m_Matrix[getIndexOf(aCol,aRow,3)] = aValue;
    }
    float Matrix3x3::get(int aIndex)
    {
        return m_Matrix[aIndex];
    }
    float Matrix3x3::get(int aCol, int aRow)
    {
        return m_Matrix[getIndexOf(aCol,aRow,3)];
    }
    void Matrix3x3::getMatrix(float * aMatrix) const
    {
        //aMatrix = m_Matrix;
    }
    const float Matrix3x3::getDeterminant() const   
    {
        float value;

	    value = 
		    m_Matrix[3] * m_Matrix[6] * m_Matrix[9]  * m_Matrix[12]-m_Matrix[2] * m_Matrix[7] * m_Matrix[9]  * m_Matrix[12]-m_Matrix[3] * m_Matrix[5] * m_Matrix[10] * m_Matrix[12]+m_Matrix[1] * m_Matrix[7] * m_Matrix[10] * m_Matrix[12]+
		    m_Matrix[2] * m_Matrix[5] * m_Matrix[11] * m_Matrix[12]-m_Matrix[1] * m_Matrix[6] * m_Matrix[11] * m_Matrix[12]-m_Matrix[3] * m_Matrix[6] * m_Matrix[8]  * m_Matrix[13]+m_Matrix[2] * m_Matrix[7] * m_Matrix[8]  * m_Matrix[13]+
		    m_Matrix[3] * m_Matrix[4] * m_Matrix[10] * m_Matrix[13]-m_Matrix[0] * m_Matrix[7] * m_Matrix[10] * m_Matrix[13]-m_Matrix[2] * m_Matrix[4] * m_Matrix[11] * m_Matrix[13]+m_Matrix[0] * m_Matrix[6] * m_Matrix[11] * m_Matrix[13]+
		    m_Matrix[3] * m_Matrix[5] * m_Matrix[8]  * m_Matrix[14]-m_Matrix[1] * m_Matrix[7] * m_Matrix[8]  * m_Matrix[14]-m_Matrix[3] * m_Matrix[4] * m_Matrix[9]  * m_Matrix[14]+m_Matrix[0] * m_Matrix[7] * m_Matrix[9]  * m_Matrix[14]+
		    m_Matrix[1] * m_Matrix[4] * m_Matrix[11] * m_Matrix[14]-m_Matrix[0] * m_Matrix[5] * m_Matrix[11] * m_Matrix[14]-m_Matrix[2] * m_Matrix[5] * m_Matrix[8]  * m_Matrix[15]+m_Matrix[1] * m_Matrix[6] * m_Matrix[8]  * m_Matrix[15]+
		    m_Matrix[2] * m_Matrix[4] * m_Matrix[9]  * m_Matrix[15]-m_Matrix[0] * m_Matrix[6] * m_Matrix[9]  * m_Matrix[15]-m_Matrix[1] * m_Matrix[4] * m_Matrix[10] * m_Matrix[15]+m_Matrix[0] * m_Matrix[5] * m_Matrix[10] * m_Matrix[15];

	    return value;
    }
    const Matrix3x3 Matrix3x3::getNegative() const  
    {
        Matrix3x3 negative = (*this);

        //negative.getNegative();
        return negative;
    }
    const Matrix3x3 Matrix3x3::getTranspose() const
    {
        Matrix3x3 transpose = (*this);

        transpose.transpose();
        return transpose;
    }
    const Matrix3x3 Matrix3x3::getInverse() const   
    {
        Matrix3x3 inverse = (*this);

        inverse.inverse();
        return inverse;
    }

    void Matrix3x3::setIdentity()
    {
        memset(m_Matrix, 0, 9 * sizeof(float));

        m_Matrix[0] = m_Matrix[4] = m_Matrix[8] = 1.0f;

    }
    void Matrix3x3::transpose() 
    {
        //
    }
    void Matrix3x3::inverse()  
    {
        //cry
    }

    //Arithmetic
    Matrix3x3 & Matrix3x3::add(const Matrix3x3 & aMatrixA,  const Matrix3x3 & aMatrixB, Matrix3x3 & aResult)
    {
        for(int i = 0; i < 9; i++)
        {
            aResult.m_Matrix[i] = aMatrixA.m_Matrix[i] + aMatrixB.m_Matrix[i];
        }
        return aResult;
    }
    Matrix3x3 & Matrix3x3::subtract(const Matrix3x3 & aMatrixA, const Matrix3x3 & aMatrixB, Matrix3x3 & aResult)
    {
        for(int i = 0; i < 9; i++)
        {
            aResult.m_Matrix[i] = aMatrixA.m_Matrix[i] - aMatrixB.m_Matrix[i];
        }
        return aResult;
    }
    Matrix3x3 & Matrix3x3::scale(const Matrix3x3 & aMatrix, const float & aScale, Matrix3x3 & aResult)
    {
        for(int i = 0; i < 9; i++)
        {
            aResult.m_Matrix[i] = aMatrix.m_Matrix[i] * aScale;
        }
        return aResult;
    }
    Matrix3x3 & Matrix3x3::multiply(const Matrix3x3 & aMatrixA, const Matrix3x3 & aMatrixB, Matrix3x3 & aResult)
    {
        float * matA = 0;
        float * matB = 0;
        float * matResult = 0;
        aMatrixA.getMatrix(matA);
        aMatrixB.getMatrix(matB);
        aResult.getMatrix(matResult);

		matResult[0] = matA[m11] * matB[m11] + matA[m12] * matB[m21] + matA[m13] * matB[m31];		matResult[1] = matA[m11] * matB[m12] + matA[m12] * matB[m22] + matA[m13] * matB[m32];	matResult[2] = matA[m11] * matB[m13] + matA[m12] * matB[m23] + matA[m13] * matB[m33];
        matResult[0] = matA[m21] * matB[m11] + matA[m22] * matB[m21] + matA[m23] * matB[m31];		matResult[1] = matA[m21] * matB[m12] + matA[m22] * matB[m22] + matA[m23] * matB[m32];	matResult[2] = matA[m21] * matB[m13] + matA[m22] * matB[m23] + matA[m23] * matB[m33];
		matResult[0] = matA[m31] * matB[m11] + matA[m32] * matB[m21] + matA[m33] * matB[m31];		matResult[1] = matA[m31] * matB[m12] + matA[m32] * matB[m22] + matA[m33] * matB[m32];	matResult[2] = matA[m31] * matB[m13] + matA[m32] * matB[m23] + matA[m33] * matB[m33];

        for(int i = 0; i < 9; i++)
        {
            aResult.set(i,matResult[i]);
        }
        return aResult;
    }
    Vector2   & Matrix3x3::multiply(const Matrix3x3 & aMatrix, const Vector2 & aVec, Vector2 & aResult)
    {
        int index, alpha;

        float vect[3], r[3];

        double sum;

        vect[0] = aVec.x;
        vect[1] = aVec.y;
        vect[2] = 1;


        for(index = 0; index < 3; index++)
        {
            sum = 0.0;
            for(alpha = 0; alpha < 3; alpha++)
            {
                sum+= aMatrix.m_Matrix[index + alpha * 3] * vect[alpha];
            }
            r[index] = (float)sum;
        }

        aResult = Vector2(r[0],r[1]);
        return aResult;
    }
    bool Matrix3x3::equal(const Matrix3x3 & aMatrixA, const Matrix3x3 & aMatrixB)
    {
        for(int i = 0; i < 16; i++) 
        {
            if(fabs(aMatrixA.m_Matrix[i] - aMatrixB.m_Matrix[i]) > 1.0e-7f)
            {
			    return false;
            }
	    }

	    return true;
    }


	Matrix3x3  Matrix3x3::operator+(const Matrix3x3 & aMatrix) const
    {
        Matrix3x3 result;
        return add(*this,aMatrix,result);
    }
	Matrix3x3 & Matrix3x3::operator+=(const Matrix3x3 &aMatrix)    
    {
        add(*this,aMatrix,*this);
        return *this;
    }
	Matrix3x3   Matrix3x3::operator-(const Matrix3x3 &aMatrix) const
    {
        Matrix3x3 result;
        return subtract(*this,aMatrix,result);
    }
	Matrix3x3 & Matrix3x3::operator-=(const Matrix3x3 &aMatrix)   
    {
        subtract(*this,aMatrix,*this);
        return *this;
    }
	Matrix3x3   Matrix3x3::operator*(const float & aScale) const   
    {
        Matrix3x3 result;
        return scale(*this,aScale,result);
    } 
	Matrix3x3 & Matrix3x3::operator*=(const float & aScale)         
    {
        scale(*this,aScale,*this);
        return *this;
    } 
	Matrix3x3   Matrix3x3::operator/(const float & aScale) const   
    {
        Matrix3x3 result;
        return scale(*this,(1/aScale),result);
    }
	Matrix3x3 & Matrix3x3::operator/=(const float & aScale)        
    {
        return scale(*this,(1/aScale),*this);
    }    
	Matrix3x3   Matrix3x3::operator*(const Matrix3x3 & aMatrix)     
    {
        Matrix3x3 result;
        return multiply(*this,aMatrix,result);
    }     
	Vector2     Matrix3x3::operator*(const Vector2 & aVec)         
    {
        Vector2 result;
        return multiply(*this, aVec, result);
    }  
	bool        Matrix3x3::operator==(const Matrix3x3 & aMatrix)   
    {
        return equal(*this,aMatrix);
    }  
	bool        Matrix3x3::operator!=(const Matrix3x3 & aMatrix)   
    {
        return -equal(*this,aMatrix);
    }

    float & Matrix3x3::operator() (const int aCol, const int aRow)
    {
        int index = getIndexOf(aCol,aRow,3);
        if(index < 0 || index > 8)
        {
            return m_Matrix[0];
        }
        return m_Matrix[index];
    }

    const char * Matrix3x3::getType()
    {
        return "Matrix3x3";
    }
    std::string Matrix3x3::toString()
    {
        return "Nothing";
    }
}