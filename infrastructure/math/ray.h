//
// Created by Don Isaac on 1/30/18.
//

#ifndef RAYTRACER_C_RAY_H
#define RAYTRACER_C_RAY_H

#include "vec3.h"

using namespace std;
namespace vecmath {
    /**
     * Represents a ray in 3D space. A ray is defined as:
     * </br>
     * <pre>
     * R = o + <i>t</i>d
     * </pre>
     * where:
     * <ul>
     *     <li><b>o</b> is the origin vector</li>
     *     <li><b><i>t</i></b> is a scalar</li>
     *     <li><b>d</b> is the direction <a href="https://en.wikipedia.org/wiki/Unit_vector">unit vector</a></li>
     * </ul>
     * </br>
     * By changing the value of <b><i>t</i></b>, you can solve for points on the ray.
     *
     * @see <a href="http://tutorial.math.lamar.edu/Classes/CalcIII/EqnsOfLines.aspx">Equations of Lines</a>
     * @author Donald Isaac
     */
    class Ray3 {
    public:
        /**Origin vector.*/
        Vector3 o;
        /**Direction vector. This vector must be a <a href="https://en.wikipedia.org/wiki/Unit_vector">unit vector</a>.*/
        Vector3 d;

        /**
         * Default constructor. Origin initializes to the zero vector, and the direction
         * initializes to the I unit vector.
         */
        Ray3() {
            o = VEC_ZERO;
            d = VEC_I;
        }

        /**
         * Creates a new <code>Ray3</code>.
         *
         * @param origin the origin vector
         * @param direction the direction vector
         */
        Ray3(Vector3 origin, Vector3 direction) {
            o = origin;
            d = direction;
            d.nor();
        }

        /**
         * Gets a point on the <code>Ray3</code>.
         * @param t the scalar to plug into the <a href="http://tutorial.math.lamar.edu/Classes/CalcIII/EqnsOfLines.aspx">ray equation</a>.
         * @return the point on the <code>Ray3</code> as a <code>Vector3</code>
         */
        Vector3 getPoint(double t){
            return o + d * t;
        }
    };
}
#endif //RAYTRACER_C_RAY_H
