/**
* A class representing a 3D Vector, along with methods
* allowing for calculations on them plus some utility methods.
*
* @author Donald Isaac
*/
#ifndef RAYTRACER_C_VEC3_H
#define RAYTRACER_C_VEC3_H

#include <cmath>
#include <string>

using namespace std;
namespace bla {
    /**
     * Represents a vector or a point in 3D space. This class simply represents:
     * </b>
     * <pre>(x, y, z)</pre>
     * </b>
     * Along with some methods for basic utilities and vector math. Whether you
     * use it as a point or a vector is up to you. You should also be careful to
     * keep track of whether an instance of a <code>Vector3</code> is being used
     * as a point or a vector to prevent unwanted modifications and/or solutions.
     *
     * @author Donald Isaac
     */
    class Vector3 {
    public:
        /**The X value*/
        double x;
        /**The Y value*/
        double y;
        /**The Z value*/
        double z;



        /**
         * Creates a Vector3 object with specified values.
         * @param nx the x value of the vector. Default value is 0.0
         * @param ny the y value of the vector. Default value is 0.0
         * @param nz the z value of the vector. Default value is 0.0
         */
        Vector3(double _x = 0.0, double _y = 0.0, double _z=0.0);

        Vector3 operator+(Vector3 &v);

        Vector3& operator+=(Vector3 &v);

        Vector3 operator-(Vector3 &v);

        Vector3& operator-=(Vector3 &v);

        /**
         * Scalar multiplication.
         * @param scalar the scalar
         * @return the vector scaled by <b>s</b>
         */
        Vector3 operator*(double scalar);

        Vector3& operator*=(double scalar);

        /**
        * Scalar multiplication.
        * @param scalar the scalar
        * @return the vector scaled by <b>s</b>
        */
        Vector3 operator*(int scalar);

        Vector3& operator*=(int scalar);

        /**
        * Scalar multiplication.
        * @param scalar the scalar
        * @return the vector scaled by <b>s</b>
        */
        Vector3 operator*(float scalar);

        Vector3 operator*=(float scalar);

        /**
         * Dot (inner) product.
         * @param u the other vector to use in the calculation
         * @return the dot product between this vector and u
         */
        double operator*(const Vector3 v);

        bool operator==(const Vector3 v);

        /**
         * Takes the dot product of this vector with itself (i.e: squaring the vector). Shorthand for v * v.
         * @return the result from the operation
         */
        inline double sqr();

        /**
         * Takes the cross product of this vector and <b>v</b>.
         * @param v the other vector used in the calculation
         * @return the cross product of this vector and <b>v</b>
         */
        inline Vector3 cross(const Vector3 v);

        /*
         * Computes the distance between two vectors.
         */
        inline float dist(const Vector3 v);

        /**
         * @return the length of the vector
         */
        inline double len();

        /**
         * Normalizes the vector, turning it into a unit vector.
         */
        inline void norm();

        /**
         * @return the vector as a string
         */
        inline string toString();

      // static singletons

      /**Zero vector.*/
      static const Vector3 zeroVec;

      /**Unit vector I.*/
      static const Vector3 iVec;

      /**Unit vector J.*/
      static const Vector3 jVec;

      /**Unit vector K.*/
      static const Vector3 kVec;

    };

}
#endif //RAYTRACER_C_VEC3_H
