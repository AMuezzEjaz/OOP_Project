#ifndef __vector2D_H__
#define __vector2D_H__

#include <cmath>

template <class T>
class vector2D
{
public:
    T x, y;

    vector2D() : x(0), y(0) {}
    vector2D(T x, T y) : x(x), y(y) {}
    vector2D(const vector2D &v) : x(v.x), y(v.y) {}

    vector2D &operator=(const vector2D &v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    vector2D operator+(vector2D &v)
    {
        return vector2D(x + v.x, y + v.y);
    }
    vector2D operator-(vector2D &v)
    {
        return vector2D(x - v.x, y - v.y);
    }

    vector2D &operator+=(vector2D &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    vector2D &operator-=(vector2D &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    vector2D operator+(double s)
    {
        return vector2D(x + s, y + s);
    }
    vector2D operator-(double s)
    {
        return vector2D(x - s, y - s);
    }
    vector2D operator*(double s)
    {
        return vector2D(x * s, y * s);
    }
    vector2D operator/(double s)
    {
        return vector2D(x / s, y / s);
    }

    vector2D &operator+=(double s)
    {
        x += s;
        y += s;
        return *this;
    }
    vector2D &operator-=(double s)
    {
        x -= s;
        y -= s;
        return *this;
    }
    vector2D &operator*=(double s)
    {
        x *= s;
        y *= s;
        return *this;
    }
    vector2D &operator/=(double s)
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

    vector2D &normalize()
    {
        if (length() == 0)
            return *this;
        *this *= (1.0 / length());
        return *this;
    }

    float dist(vector2D v) const
    {
        vector2D d(v.x - x, v.y - y);
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

    vector2D ortho() const
    {
        return vector2D(y, -x);
    }

    static float dot(vector2D v1, vector2D v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }
    static float cross(vector2D v1, vector2D v2)
    {
        return (v1.x * v2.y) - (v1.y * v2.x);
    }
};

typedef vector2D<float> vector2Df;
typedef vector2D<double> vector2Dd;

#endif