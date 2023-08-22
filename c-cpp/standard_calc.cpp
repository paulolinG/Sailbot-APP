#include "stdbool.h"
#include "standard_calc.h"

/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    int truncatedAngle = (int) angle;
    // shifts the angle from the lowerbound if angle >= 180
    if (angle >= 180) 
    {
        return -180 + ((truncatedAngle + 180) % 360) + (angle - truncatedAngle);
    } 
    // shifts the angle from the upperbound if angle < -180
    else if (angle < -180) 
    {
        return 180 - (-angle + truncatedAngle) - ((-truncatedAngle + 180) % 360);
    }
    // angle is already between boundaries
    else 
    {
        return angle;
    }
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    // bounds the angles to make it easier to compare
    float boundedFirstAngle = bound_to_180(first_angle);
    float boundedMiddleAngle = bound_to_180(middle_angle);
    float boundedSecondAngle = bound_to_180(second_angle);
    float maxAngle;
    float minAngle;

    // determines the greater angle between the first and second angle
    if (boundedSecondAngle > boundedFirstAngle) {
        maxAngle = boundedSecondAngle;
        minAngle = boundedFirstAngle;
    } else {
        maxAngle = boundedFirstAngle;
        minAngle = boundedSecondAngle;
    }

    // checks if the angle between second and first angle is the reflex angle
    if ((maxAngle - minAngle) < (360 - (maxAngle - minAngle))) {
        return (boundedMiddleAngle <= maxAngle && boundedMiddleAngle >= minAngle);
    } else {
        return ((boundedMiddleAngle >= maxAngle && boundedMiddleAngle < 180) || (boundedMiddleAngle >= -180 && boundedMiddleAngle <= minAngle));
    }   
}
