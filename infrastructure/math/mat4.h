//
// Created by Don Isaac on 1/30/18.
//

#ifndef RAYTRACER_C_MAT4_H
#define RAYTRACER_C_MAT4_H
#define SIZE 16

#include "vec3.h"
#include <array>

using namespace std;
namespace vecmath {
    static const array<double, SIZE> idMtx = {
            1.0, 0.0, 0.0, 0.0,
            0.0, 1.0, 0.0, 0.0,
            0.0, 0.0, 1.0, 0.0,
            0.0, 0.0, 0.0, 1.0
    };

    /**
     * Represents a 4 dimensional square matrix. This class also contains methods
     * used for 3D transformations.
     *
     * @see <a href="https://en.wikipedia.org/wiki/Transformation_matrix">Transform Matricies</a>
     * @author Donald Isaac
     */
    class Matrix4 {

    protected:
        array<double, SIZE> mat;

        /**
         * Creates a <code>Matrix4</code> with specified values. If the passed
         * array is invalid, this <code>Matrix4</code> is set to the identity matrix.
         *
         * @param matrix the array containing the values to set the <code>Matrix4</code> to
         */
        Matrix4(array<double, SIZE> matrix) {
            if (matrix.size() != SIZE) {
                //for (int i = 0; i < SIZE; i++) { mat[i] = idMtx[i]; }
                //mat = new array()
            } else {
                mat = matrix;
            }
        }

    public:
        //==========================================
        //=======FACTORY METHODS/CONSTRUCTORS=======
        //==========================================

        /**
         * Creates an identity matrix.
         */
        Matrix4() {
            mat = idMtx;
        }


        /**
         * Creates a new <code>Matrix4</code> instance that has been modified to apply
         * a translation transformation.
         * <p>
         * The resulting matrix looks like:
         * </p>
         *
         * <pre>
         * |1 0 0 x|
         * |0 1 0 y|
         * |0 0 1 z|
         * |0 0 0 1|
         * </pre>
         *
         * @param x
         *            how far to translate along the X axis
         * @param y
         *            how far to translate along the Y axis
         * @param z
         *            how far to translate along the Z axis
         * @return a <code>Matrix4</code> matrix that applies a translation
         */
        static Matrix4 *getTranslationInstance(double x, double y, double z) {
            array<double, SIZE> matrix = idMtx;
            matrix[12] = x;
            matrix[13] = y;
            matrix[14] = z;

            return new Matrix4(matrix);
        }


        /**
         * Creates a new <code>Matrix4</code> instance that has been modified to apply
         * a translation transformation.
         * <p>
         * The resulting matrix looks like:
         * </p>
         *
         * <pre>
         * |1 0 0 x|
         * |0 1 0 y|
         * |0 0 1 z|
         * |0 0 0 1|
         * </pre>
         *
         * @param v
         *            the <code>Vector3</code> that defines how far to translate the
         *            matrix in each direction
         * @return a translated <code>Matrix4</code> instance
         */
        static Matrix4 *getTranslationInstance(Vector3 v) {
            return getTranslationInstance(v.x, v.y, v.z);
        }

        static Matrix4 getRotXInstance(double theta) {
            array<double, SIZE> matrix = idMtx;
            double s = sin(theta);
            double c = cos(theta);

            matrix[5] = c;
            matrix[6] = s;
            matrix[9] = -s;
            matrix[10] = c;

            return Matrix4(matrix);
        }


        /**
         * Creates a new <code>Matrix4</code> instance that has been modified to apply
         * a rotation transformation around the Y axis.
         * <p>
         * The resulting matrix looks like:
         * </p>
         *
         * <pre>
         * | c  0  s  0|
         * | 0  1  0  0|
         * |-s  s  c  0|
         * | 0  0  0  1|
         * </pre>
         *
         * @param theta
         *            the angle of the rotation in radians
         * @return a <code>Matrix4</code> that applies a rotation around the Y
         *         axis
         */
        static Matrix4 getRotYInstance(double theta) {
            array<double, SIZE> matrix = idMtx;
            double s = sin(theta);
            double c = cos(theta);

            matrix[0] = c;
            matrix[2] = -s;
            matrix[8] = s;
            matrix[10] = c;

            return Matrix4(matrix);
        }


        /**
         * Creates a new <code>Matrix4</code> instance that has been modified to apply
         * a rotation transformation around the Z axis.
         * <p>
         * The resulting matrix looks like:
         * </p>
         *
         * <pre>
         * |c -s  s  0|
         * |s  c  0  0|
         * |0  s  1  0|
         * |0  0  0  1|
         * </pre>
         *
         * @param theta
         *            the angle of the rotation in radians
         * @return a <code>Matrix4</code> instance that applies a rotation around the Z
         *         axis
         */
        static Matrix4 getRotZInstance(double theta) {
            array<double, SIZE> matrix = idMtx;
            double s = sin(theta);
            double c = cos(theta);

            matrix[0] = c;
            matrix[1] = s;
            matrix[4] = -s;
            matrix[5] = c;

            return Matrix4(matrix);
        }

        //==================================
        //=======MATH/UTILITY METHODS=======
        //==================================

        /**
         * Multiplies this <code>Matrix4</code> with another <code>Matrix4</code>
         * and stores it in the <code>Matrix4</code> which called this method.
         * </br>
         * Essentially a code representation for the equation:
         *
         * <pre>
         * T = T * M
         * </pre>
         *
         * where <code>T</code> is this <code>Matrix4</code> and <code>M</code> is the passed <code>Matrix4</code>.
         *
         * @param M
         *            the matrix to multiply by.
         * @return a reference to this <code>Matrix4</code> for method chaining
         */
        Matrix4 *mult(Matrix4 M) {
            //array<double, SIZE> newmat;
            array<double, SIZE> m1 = mat;
            array<double, SIZE> m2 = M.mat;

            // I'm way more proud of this than I should be
            for (int i = 0, m = 0, n = 0; i < SIZE; i++) {
                n = i % 4;
                m = n == 0 && i > 0 ? m + 1 : m;
                mat[i] = m1[n] * m2[4 * m] + m1[n + 4] * m2[4 * m + 1] +
                         m1[n + 8] * m2[4 * m + 2] + m1[n + 12] * m2[4 * m + 3];
            }

            return this;
        }

        /**
         * Multiplies this <code>Matrix4</code> with another <code>Matrix4</code>.
         * </br>
         * Essentially a code representation of the equation:
         *
         * <pre>
         * T' = T * M
         * </pre>
         *
         * where <code>T'</code> is the new <code>Matrix4</code> <code>T</code> is this
         * <code>Matrix4</code> and <code>M</code> is the passed <code>Matrix4</code>.
         *
         * @param M
         *            the <code>Matrix4</code> to multiply by.
         * @return a new <code>Matrix4</code> that is the result of T * M
         */
        Matrix4 getMult(Matrix4 M) {
            array<double, SIZE> newmat;
            array<double, SIZE> m1 = mat;
            array<double, SIZE> m2 = M.mat;

            // I'm way more proud of this than I should be
            for (int i = 0, m = 0, n = 0; i < SIZE; i++) {
                n = i % 4;
                m = n == 0 && i > 0 ? m + 1 : m;
                newmat[i] = m1[n] * m2[4 * m] + m1[n + 4] * m2[4 * m + 1] +
                            m1[n + 8] * m2[4 * m + 2] + m1[n + 12] * m2[4 * m + 3];
            }

            return Matrix4(newmat);
        }

        Matrix4 operator+(Matrix4 &M) {
            array<double, SIZE> matrix;

            for (int i = 0; i < SIZE; i++) {
                matrix[i] = mat[i] + M.mat[i];
            }

            return Matrix4(matrix);
        }

        Matrix4 operator-(Matrix4 &M) {
            array<double, SIZE> matrix;

            for (int i = 0; i < SIZE; i++) {
                matrix[i] = mat[i] - M.mat[i];
            }

            return Matrix4(matrix);
        }


        /**
         * Transforms a <code>Vector3</code> using this matrix, modifying the original <code>Vector3</code>.
         *
         * @param v
         *            the <code>Vector3</code> to transform
         * @return a <code>Vector3</code> with the applied transformations
         */
        Vector3 transformVec(Vector3 *v) {
            double vec[] = {0.0, 0.0, 0.0};

            for (int i = 0; i < 3; i++) {
                vec[i] = mat[i] * v->x + mat[i + 4] * v->y + mat[i + 8] * v->z + mat[i + 12];
            }
            v->x = vec[0];
            v->y = vec[1];
            v->z = vec[2];
        }


        /**
         * Transforms a <code>Vector3</code> using this matrix. Note that this method
         * does not modify the original <code>Vector3</code>.
         *
         * @param v
         *            the <code>Vector3</code> to transform
         * @return a <code>Vector3</code> with the applied transformations
         */
        Vector3 getTransformedVec(Vector3 v) {
            double vec[] = {0.0, 0.0, 0.0};

            for (int i = 0; i < 3; i++) {
                vec[i] = mat[i] * v.x + mat[i + 4] * v.y + mat[i + 8] * v.z + mat[i + 12];
            }

            return Vector3(vec[0], vec[1], vec[2]);
        }

        string toString() {
            string s = "";

            for (int i = 0; i < 4; i++) {
                s.append("|" + to_string(mat[i]) + " " + to_string(mat[i + 4]) + " " + to_string(mat[i + 8]) + " " +
                         to_string(mat[i + 12]) + "|\n");
            }

            return s;
        }
        //====================================
        //=======TRANSFORMATION METHODS=======
        //====================================

        /**
         * Applies a translation transformation to the <code>Transform</code> matrix.
         *
         * @param x
         *            how much to translate along the X-axis
         * @param y
         *            how much to translate along the Y-axis
         * @param z
         *            how much to translate along the Z-axis
         * @return a reference to this matrix for method chaining
         */
        Matrix4 *translate(double x, double y, double z) {
            mat[12] += x;
            mat[13] += y;
            mat[14] += z;

            return this;
        }

        /**
         * Applies a translation transformation to the <code>Transform</code> matrix.
         *
         * @param v
         *            how much to translate the matrix in each direction
         *
         * @return a reference to this matrix for method chaining
         *
         * @see infrastructure.math.Vector3
         */
        Matrix4 *translate(Vector3 v) {
            return translate(v.x, v.y, v.z);
        }

        /**
         * Adds a rotation transformation on this <code>Matrix4</code> around the X-axis.
         * Because the rotation occurs around the axis, if the matrix is not centered on
         * the axis, it will rotate in a circular path around it, not on it's local axis.
         * To make the rotation occur around the local axis, set <b>aroundOrigin</b> to false.
         *
         * @param theta
         *            the angle to rotate by in radians
         * @param aroundOrigin
         *            <b>true</b> if the rotation should occur around the global axis,
         *            <b>false</b> otherwise
         * @return a pointer to this matrix for chaining purposes
         */
        Matrix4 *rotX(double theta, bool aroundOrigin) {
            Vector3 t = VEC_ZERO;

            if (!aroundOrigin) {
                t = Vector3(mat[12], mat[13], mat[14]);
                translate(-t.x, -t.y, -t.z);
            }

            this->mult(getRotXInstance(theta));//TODO: Does this work?
            if (!aroundOrigin)
                translate(t);

            return this;
        }

        /**
         * Adds a rotation transformation on this <code>Matrix4</code> around the Y-axis.
         * Because the rotation occurs around the axis, if the matrix is not centered on
         * the axis, it will rotate in a circular path around it, not on it's local axis.
         * To make the rotation occur around the local axis, set <b>aroundOrigin</b> to false.
         *
         * @param theta
         *            the angle to rotate by in radians
         * @param aroundOrigin
         *            <b>true</b> if the rotation should occur around the global axis,
         *            <b>false</b> otherwise
         * @return a pointer to this matrix for chaining purposes
         */
        Matrix4 *rotY(double theta, bool aroundOrigin) {
            Vector3 t = VEC_ZERO;

            if (!aroundOrigin) {
                t = Vector3(mat[12], mat[13], mat[14]);
                translate(-t.x, -t.y, -t.z);
            }

            this->mult(getRotYInstance(theta));//TODO: Does this work?
            if (!aroundOrigin)
                translate(t);

            return this;
        }

        /**
         * Adds a rotation transformation on this <code>Matrix4</code> around the Z-axis.
         * Because the rotation occurs around the axis, if the matrix is not centered on
         * the axis, it will rotate in a circular path around it, not on it's local axis.
         * To make the rotation occur around the local axis, set <b>aroundOrigin</b> to false.
         *
         * @param theta
         *            the angle to rotate by in radians
         * @param aroundOrigin
         *            <b>true</b> if the rotation should occur around the global axis,
         *            <b>false</b> otherwise
         * @return a pointer to this matrix for chaining purposes
         */
        Matrix4 *rotZ(double theta, bool aroundOrigin) {
            Vector3 t = VEC_ZERO;
            if (!aroundOrigin) {
                t = Vector3(mat[12], mat[13], mat[14]);
                translate(-t.x, -t.y, -t.z);
            }
            //multiply(Transform.getRotationXInstance(theta));
            this->mult(getRotZInstance(theta));//TODO: Does this work?
            if (!aroundOrigin)
                translate(t);

            return this;
        }

    };
}

#endif //RAYTRACER_C_MAT4_H
