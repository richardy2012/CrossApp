

#ifndef __CCGEMETRY_H__
#define __CCGEMETRY_H__

#include "platform/CCPlatformMacros.h"
#include "CAObject.h"
#include <math.h>

NS_CC_BEGIN

class CC_DLL CCSize;

class CC_DLL CCPoint
{
public:
    float x;
    float y;

public:
    
    CCPoint();
    
    CCPoint(float x, float y);
    /**
     * @lua NA
     */
    CCPoint(const CCPoint& other);
    /**
     * @lua NA
     */
    CCPoint(const CCSize& size);
    /**
     * @lua NA
     */
    CCPoint& operator= (const CCPoint& other);
    /**
     * @lua NA
     */
    CCPoint& operator= (const CCSize& size);
    /**
     * @lua NA
     */
    CCPoint operator+(const CCPoint& right) const;
    /**
     * @lua NA
     */
    CCPoint operator-(const CCPoint& right) const;
    /**
     * @lua NA
     */
    CCPoint operator-() const;
    /**
     * @lua NA
     */
    CCPoint operator*(float a) const;
    /**
     * @lua NA
     */
    CCPoint operator/(float a) const;
    /**
     * @lua NA
     */
    void setPoint(float x, float y);
    bool equals(const CCPoint& target) const;
    
    /** @returns if points have fuzzy equality which means equal with some degree of variance.
     * @since v2.1.4
     * @lua NA
     */
    bool fuzzyEquals(const CCPoint& target, float variance) const;

    /** Calculates distance between point an origin
     * @return float
     * @since v2.1.4
     * @lua NA
     */
    inline float getLength() const {
        return sqrtf(x*x + y*y);
    };

    /** Calculates the square length of a CCPoint (not calling sqrt() )
     * @return float
     * @since v2.1.4
     * @lua NA
     */
    inline float getLengthSq() const {
        return dot(*this); //x*x + y*y;
    };

    /** Calculates the square distance between two points (not calling sqrt() )
     @return float
     @since v2.1.4
    */
    inline float getDistanceSq(const CCPoint& other) const {
        return (*this - other).getLengthSq();
    };

    /** Calculates the distance between two points
     @return float
     @since v2.1.4
     */
    inline float getDistance(const CCPoint& other) const {
        return (*this - other).getLength();
    };

    /** @returns the angle in radians between this vector and the x axis
     @since v2.1.4
    */
    inline float getAngle() const {
        return atan2f(y, x);
    };

    /** @returns the angle in radians between two vector directions
     @since v2.1.4
    */
    float getAngle(const CCPoint& other) const;

    /** Calculates dot product of two points.
     @return float
     @since v2.1.4
     */
    inline float dot(const CCPoint& other) const {
        return x*other.x + y*other.y;
    };

    /** Calculates cross product of two points.
     @return float
     @since v2.1.4
     */
    inline float cross(const CCPoint& other) const {
        return x*other.y - y*other.x;
    };

    /** Calculates perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0
     @return CCPoint
     @since v2.1.4
     */
    inline CCPoint getPerp() const {
        return CCPoint(-y, x);
    };

    /** Calculates perpendicular of v, rotated 90 degrees clockwise -- cross(v, rperp(v)) <= 0
     @return CCPoint
     @since v2.1.4
     */
    inline CCPoint getRPerp() const {
        return CCPoint(y, -x);
    };

    /** Calculates the projection of this over other.
     @return CCPoint
     @since v2.1.4
     */
    inline CCPoint project(const CCPoint& other) const {
        return other * (dot(other)/other.dot(other));
    };

    /** Complex multiplication of two points ("rotates" two points).
     @return CCPoint vector with an angle of this.getAngle() + other.getAngle(),
     and a length of this.getLength() * other.getLength().
     @since v2.1.4
     */
    inline CCPoint rotate(const CCPoint& other) const {
        return CCPoint(x*other.x - y*other.y, x*other.y + y*other.x);
    };

    /** Unrotates two points.
     @return CCPoint vector with an angle of this.getAngle() - other.getAngle(),
     and a length of this.getLength() * other.getLength().
     @since v2.1.4
     */
    inline CCPoint unrotate(const CCPoint& other) const {
        return CCPoint(x*other.x + y*other.y, y*other.x - x*other.y);
    };

    /** Returns point multiplied to a length of 1.
     * If the point is 0, it returns (1, 0)
     @return CCPoint
     @since v2.1.4
     */
    inline CCPoint normalize() const {
        float length = getLength();
        if(length == 0.) return CCPoint(1.f, 0);
        return *this / getLength();
    };

    /** Linear Interpolation between two points a and b
     @returns
        alpha == 0 ? a
        alpha == 1 ? b
        otherwise a value between a..b
     @since v2.1.4
     */
    inline CCPoint lerp(const CCPoint& other, float alpha) const {
        return *this * (1.f - alpha) + other * alpha;
    };

    /** Rotates a point counter clockwise by the angle around a pivot
     @param pivot is the pivot, naturally
     @param angle is the angle of rotation ccw in radians
     @returns the rotated point
     @since v2.1.4
     */
    CCPoint rotateByAngle(const CCPoint& pivot, float angle) const;

    static inline CCPoint forAngle(const float a)
    {
    	return CCPoint(cosf(a), sinf(a));
    }
};

/**
 * @js NA
 */
class CC_DLL CCSize
{
public:
    
    float width;
    float height;

public:
    
    CCSize();
    
    CCSize(float width, float height);
    /**
     * @lua NA
     */
    CCSize(const CCSize& other);
    /**
     * @lua NA
     */
    CCSize(const CCPoint& point);
    /**
     * @lua NA
     */
    CCSize& operator= (const CCSize& other);
    /**
     * @lua NA
     */
    CCSize& operator= (const CCPoint& point);
    /**
     * @lua NA
     */
    CCSize operator+(const CCSize& right) const;
    /**
     * @lua NA
     */
    CCSize operator-(const CCSize& right) const;
    /**
     * @lua NA
     */
    CCSize operator*(float a) const;
    /**
     * @lua NA
     */
    CCSize operator/(float a) const;
    /**
     * @lua NA
     */
    void setSize(float width, float height);
    /**
     * @lua NA
     */
    bool equals(const CCSize& target) const;
};

/**
 * @js NA
 */
class CC_DLL CCRect
{
public:
    
    CCPoint origin;
    
    CCSize  size;

public:
    
    CCRect();
    
    CCRect(float x, float y, float width, float height);

    CCRect(const CCRect& other);
    
    void setRect(float x, float y, float width, float height);
    
    CCRect& operator= (const CCRect& other);
    
    CCRect operator*(float a) const;

    CCRect operator/(float a) const;
    
    float getMinX() const; /// return the leftmost x-value of current rect
    float getMidX() const; /// return the midpoint x-value of current rect
    float getMaxX() const; /// return the rightmost x-value of current rect
    float getMinY() const; /// return the bottommost y-value of current rect
    float getMidY() const; /// return the midpoint y-value of current rect
    float getMaxY() const; /// return the topmost y-value of current rect
    bool equals(const CCRect& rect) const;   
    bool containsPoint(const CCPoint& point) const;
    bool intersectsRect(const CCRect& rect) const;
    void InflateRect(float v);
    
    CC_SYNTHESIZE_IS(bool, m_bCenter, Center);
};


const CCPoint CCPointZero = CCPoint();
const CCSize CCSizeZero = CCSize();
const CCRect CCRectZero = CCRect();
const CCPoint CADipPointZero = CCPoint();
const CCSize CADipSizeZero = CCSize();
const CCRect CADipRectZero = CCRect();

#define CCPointMake(x, y) CCPoint((float)(x), (float)(y))
#define CCSizeMake(width, height) CCSize((float)(width), (float)(height))
#define CCRectMake(x, y, width, height) CCRect((float)(x), (float)(y), (float)(width), (float)(height))


NS_CC_END

#endif // __CCGEMETRY_H__
