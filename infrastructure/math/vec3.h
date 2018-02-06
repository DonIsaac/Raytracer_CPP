/**
* A class representing a 3D Vector, along with methods
* allowing for calculations on them plus some utility methods.
*
* @author Donald Isaac
*/
#ifndef RAYTRACER_C_VEC3_H
#define RAYTRACER_C_VEC3_H

#import <cmath>
#import <string>

using namespace std;
namespace vecmath {
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
         * Creates a Vector3 object at (0, 0, 0).
         */
        Vector3() {
            x = 0.0;
            y = 0.0;
            z = 0.0;
        }

        /**
         * Creates a Vector3 object with specified values.
         * @param nx the x value of the vector
         * @param ny the y value of the vector
         * @param nz the z value of the vector
         */
        Vector3(double nx, double ny, double nz) {
            x = nx;
            y = ny;
            z = nz;
        }

        inline Vector3 operator+(Vector3 &v) {
            return Vector3(x + v.x, y + v.y, z + v.z);
        }

        inline Vector3 operator-(Vector3 &v) {
            return Vector3(x - v.x, y - v.y, z - v.z);
        }

        /**
         * Scalar multiplication.
         * @param scalar the scalar
         * @return the vector scaled by <b>s</b>
         */
        inline Vector3 operator*(double scalar) {
            return Vector3(scalar * x, scalar * y, scalar * z);
        }

        /**
        * Scalar multiplication.
        * @param scalar the scalar
        * @return the vector scaled by <b>s</b>
        */
        inline Vector3 operator*(int scalar) {
            double s = (double) scalar;//the scalar as a double
            return Vector3(s * x, s * y, s * z);
        }

        /**
        * Scalar multiplication.
        * @param scalar the scalar
        * @return the vector scaled by <b>s</b>
        */
        inline Vector3 operator*(float scalar) {
            double s = (double) scalar;//the scalar as a double
            return Vector3(s * x, s * y, s * z);
        }

        /**
    * Dot (inner) product.
    * @param u the other vector to use in the calculation
    * @return the dot product between this vector and u
    */
        inline double operator*(Vector3 u) {
            return u.x * x + u.y * y + u.z * z;
        }

        /**
         * Takes the dot product of this vector with itself (i.e: squaring the vector). Shorthand for v * v.
         * @return the result from the operation
         */
        inline double sqr() {
            return x * x + y * y + z * z;
        }

        /**
         * Takes the cross product of this vector and <b>v</b>.
         * @param v the other vector used in the calculation
         * @return the cross product of this vector and <b>v</b>
         */
        inline Vector3 cross(Vector3 v) {
            return Vector3(
                    y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x
            );
        }

        /*
    * Computes the distance between two vectors.
    */
        inline float dist(Vector3 v) {
            float dx = x - v.x;
            float dy = y - v.y;
            float dz = z - v.z;

            return sqrt(dx * dx + dy * dy + dz * dz);
        }

        /**
         * @return the length of the vector
         */
        inline double len() {
            return sqrt(x * x + y * y + z * z);
        }

        /**
         * Normalizes the vector.
         */
        inline void nor() {
            double l = len();
            x /= l;
            y /= l;
            z /= l;
        }

        /**
         * @return the vector as a string
         */
        inline string toString() {
            return "<" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ">";
        }

    };
    /**Zero vector.*/
    static const Vector3 VEC_ZERO = Vector3(0.0, 0.0, 0.0);
    /**Unit vector I.*/
    static const Vector3 VEC_I = Vector3(1.0, 0.0, 0.0);
    /**Unit vector J.*/
    static const Vector3 VEC_J = Vector3(0.0, 1.0, 0.0);
    /**Unit vector K.*/
    static const Vector3 VEC_K = Vector3(0.0, 0.0, 1.0);
}
#endif //RAYTRACER_C_VEC3_H
