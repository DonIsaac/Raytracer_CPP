//
// Created by Don Isaac on 2/6/18.
//

#ifndef RAYTRACER_C_SPHERE_H
#define RAYTRACER_C_SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "transformable.h"

using namespace std;
namespace bla{
    class Sphere: public Transformable{
    public:
        Vector3 o;
        double r;

        Sphere(Vector3 origin, double radius){
            o = origin;
            r = radius;
        }

        Matrix4 *translate(double x, double y, double z){
            o.x += x;
            o.y += y;
            o.z += z;
        }
        Matrix4 *translate(Vector3 v){
            o += v;
        }
        Matrix4 *rotX(double theta, bool aroundOrigin){

        }
        Matrix4 *rotY(double theta, bool aroundOrigin) = 0;
        Matrix4 *rotZ(double theta, bool aroundOrigin) = 0;
        Matrix4 *transform(Matrix4 M) =0;
    };
}
#endif //RAYTRACER_C_SPHERE_H
