#ifndef __vector2d_H__
#define __vector2d_H__

#include <cmath>

template <class T>
class vector2d
{
public:
    T x, y;

    vector2d() : x(0), y(0) {}
    vector2d(T x, T y) : x(x), y(y) {}
    vector2d(const vector2d &v) : x(v.x), y(v.y) {}

    vector2d &operator=(const vector2d &v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    vector2d operator+(vector2d &v)
    {
        return vector2d(x + v.x, y + v.y);
    }
    vector2d operator-(vector2d &v)
    {
        return vector2d(x - v.x, y - v.y);
    }

    vector2d &operator+=(vector2d &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    vector2d &operator-=(vector2d &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    vector2d operator+(double s)
    {
        return vector2d(x + s, y + s);
    }
    vector2d operator-(double s)
    {
        return vector2d(x - s, y - s);
    }
    vector2d operator*(double s)
    {
        return vector2d(x * s, y * s);
    }
    vector2d operator/(double s)
    {
        return vector2d(x / s, y / s);
    }

    vector2d &operator+=(double s)
    {
        x += s;
        y += s;
        return *this;
    }
    vector2d &operator-=(double s)
    {
        x -= s;
        y -= s;
        return *this;
    }
    vector2d &operator*=(double s)
    {
        x *= s;
        y *= s;
        return *this;
    }
    vector2d &operator/=(double s)
    {
        x /= s;
        y /= s;
        return *this;
    }

    void set(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    void rotate(double deg)
    {
        double theta = deg / 180.0 * M_PI;
        double c = cos(theta);
        double s = sin(theta);
        double tx = x * c - y * s;
        double ty = x * s + y * c;
        x = tx;
        y = ty;
    }

    vector2d &normalize()
    {
        if (length() == 0)
            return *this;
        *this *= (1.0 / length());
        return *this;
    }

    float dist(vector2d v) const
    {
        vector2d d(v.x - x, v.y - y);
        return d.length();
    }
    float length() const
    {
        return std::sqrt(x * x + y * y);
    }
    void truncate(double length)
    {
        double angle = atan2f(y, x);
        x = length * cos(angle);
        y = length * sin(angle);
    }

    vector2d ortho() const
    {
        return vector2d(y, -x);
    }

    static float dot(vector2d v1, vector2d v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }
    static float cross(vector2d v1, vector2d v2)
    {
        return (v1.x * v2.y) - (v1.y * v2.x);
    }
};

typedef vector2d<float> vector2df;
typedef vector2d<double> vector2dd;

#endif