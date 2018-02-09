/**
* Vector3 class implementation
*
* @author Donald Isaac
*/

#include "vec3.h"
#include <cmath>
#include <string>

using namespace std;

namespace bla {

    const Vector3 Vector3::zeroVec = Vector3(0.0, 0.0, 0.0);

    const Vector3 Vector3::iVec = Vector3(1.0, 0.0, 0.0);

    const Vector3 Vector3::jVec = Vector3(0.0, 1.0, 0.0);

    const Vector3 Vector3::kVec = Vector3(0.0, 0.0, 1.0);


    Vector3::Vector3(double _x, double _y, double _z) 
        : x(_x)
        , y(_y)
        , z(_z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3 Vector3::operator+(Vector3 &v) {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3& Vector3::operator+=(Vector3 &v) {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;

        return *this;
    }

    Vector3 Vector3::operator-(Vector3 &v) {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3& Vector3::operator-=(Vector3 &v) {
        this->x -= v.x;
        this->y -= v.y;
        this->z -= v.z;

        return *this;
    }

    /**
     * Scalar multiplication.
     * @param scalar the scalar
     * @return the vector scaled by <b>s</b>
     */
    Vector3 Vector3::operator*(double scalar) {
        return Vector3(scalar * x, scalar * y, scalar * z);
    }

    Vector3& Vector3::operator*=(double scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;

        return *this;
    }

    /**
    * Scalar multiplication.
    * @param scalar the scalar
    * @return the vector scaled by <b>s</b>
    */
    Vector3 Vector3::operator*(int scalar) {
        double s = (double) scalar;//the scalar as a double
        return Vector3(s * x, s * y, s * z);
    }

    Vector3& Vector3::operator*=(int scalar) {
        double s = (double) scalar;//the scalar as a double
        this->x *= s;
        this->y *= s;
        this->z *= s;

        return *this;
    }

    /**
    * Scalar multiplication.
    * @param scalar the scalar
    * @return the vector scaled by <b>s</b>
    */
    Vector3 Vector3::operator*(float scalar) {
        double s = (double) scalar;//the scalar as a double
        return Vector3(s * x, s * y, s * z);
    }

    Vector3 Vector3::operator*=(float scalar) {
        double s = (double) scalar;//the scalar as a double
        x *= s;
        y *= s;
        z *= s;
    }

    /**
     * Dot (inner) product.
     * @param u the other vector to use in the calculation
     * @return the dot product between this vector and u
     */
    double Vector3::operator*(const Vector3 v) {
        return v.x * x + v.y * y + v.z * z;
    }

    bool Vector3::operator==(const Vector3 v){
        return x==v.x && y==v.y && z==v.z;
    }

    /**
     * Takes the dot product of this vector with itself (i.e: squaring the vector). Shorthand for v * v.
     * @return the result from the operation
     */
    inline double Vector3::sqr() {
        return x * x + y * y + z * z;
    }

    /**
     * Takes the cross product of this vector and <b>v</b>.
     * @param v the other vector used in the calculation
     * @return the cross product of this vector and <b>v</b>
     */
    inline Vector3 Vector3::cross(const Vector3 v) {
        return Vector3(
                y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x
        );
    }

    /*
     * Computes the distance between two vectors.
     */
    inline float Vector3::dist(const Vector3 v) {
        float dx = x - v.x;
        float dy = y - v.y;
        float dz = z - v.z;

        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    /**
     * @return the length of the vector
     */
    inline double Vector3::len() {
        return sqrt(x * x + y * y + z * z);
    }

    /**
     * Normalizes the vector, turning it into a unit vector.
     */
    inline void Vector3::norm() {
        double l = len();
        x /= l;
        y /= l;
        z /= l;
    }

    /**
     * @return the vector as a string
     */
    inline string Vector3::toString() {
        return "<" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ">";
    }

}
