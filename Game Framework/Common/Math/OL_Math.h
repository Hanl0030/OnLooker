#ifndef OL_MATH_H
#define OL_MATH_H

#include <math.h>
#include "OL_Vector2.h"
#include "OL_Vector3.h"
#include "OL_Matrix3x3.h"

namespace OnLooker
{
    const int PI = 3.14159265358979;

    inline float degreesToRad(float aDegrees)
    {
        return (aDegrees * (PI / 180));
    }
    inline float radToDegrees(float aRadians)
    {
        return (aRadians * (180/PI));
    }
    inline float clamp(float aValue, float aMin, float aMax)
    {
        if(aValue > aMax)
        {
            return aMax;
        }
        if(aValue < aMin)
        {
            return aMin;
        }
        return aValue;
    }
}


#endif