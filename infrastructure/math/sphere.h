//
// Created by Don Isaac on 2/6/18.
//

#ifndef RAYTRACER_C_SPHERE_H
#define RAYTRACER_C_SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "transformable.h"

using namespace std;
namespace bla {
    /**
     * A class representing a sphere in 3D space.
     *
     * @author Donald Isaac
     */
    class Sphere : public Transformable {
    public:
        /**The center of the Sphere*/
        Vector3 c;
        /**The radius of the Sphere*/
        double r;

        /**
         * Constructs a Sphere.
         * @param center the center of the Sphere
         * @param radius the radius of the Sphere
         */
        Sphere(Vector3 center = bla::VEC_ZERO, double radius = 1) {
            c = center;
            r = radius;
        }

        /**
         * Checks to see if a ray intersects this sphere.
         * @param ray the ray to check
         * @return an array with two elements containing the intersection results, <code>{t1, t2}</code>.
         * When checking a ray-sphere intersection, there can be 0, 1, or 2 intersections. If there are <b>0</b>
         * intersections, <code>{-1.0, -1.0}</code> is returned. If there is <b>1</b> intersection,
         * <code>{t1, -1.0}</code> is returned. If there are <b>2</b> intersections, <code>{t1, t2}</code> is returned.
         */
        double *intersects(Ray3 ray) {
            double ret[] = {-1.0, -1.0};
            // To understand what's going on here, check the wiki.
            Vector3 p = ray.o - c;
            double b = ray.d * p;
            double discrim = b * b - ray.d.sqr() * (p.sqr() - r * r);
            if (discrim < 0.0)
                return ret;
            else {
                double t1 = -b + sqrt(discrim);
                double t2 = -b - sqrt(discrim);

                ret[0] = t1 < 0 ? -1.0 : t1;
                ret[1] = t2 < 0 ? -1.0 : t2;
                return ret;
            }

        }

        void translate(double x, double y, double z) {
            c.x += x;
            c.y += y;
            c.z += z;
        }

        void translate(Vector3 v) {
            c += v;
        }

        void rotX(double theta, bool aroundOrigin) {
            // Rotating a sphere does nothing.
        }

        void rotY(double theta, bool aroundOrigin) {
            // Rotating a sphere does nothing.
        }

        void rotZ(double theta, bool aroundOrigin) {
            // Rotating a sphere does nothing.
        }

        void transform(Matrix4 M) {
            array<double, 16> m = M.getMatrix();

            c.x += m[12];
            c.y += m[13];
            c.z += m[14];
        }
    };
}
#endif //RAYTRACER_C_SPHERE_H
