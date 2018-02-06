//
// Created by Don Isaac on 1/30/18.
//

#ifndef RAYTRACER_C_TRANSFORMABLE_H
#define RAYTRACER_C_TRANSFORMABLE_H

#include "vec3.h"
#include "mat4.h"

using namespace std;
namespace vecmath{
    /**
     * Represents any object that can be transformed in 3D space.
     * This class is meant to be used with any object that has a
     * <code>Matrix4</code> field, allowing for external code to
     * modify said <code>Matrix4</code> in a controlled manner.
     */
    class Transformable{
    public:
        virtual Matrix4 *translate(double x, double y, double z) = 0;
        virtual Matrix4 *translate(Vector3 v) = 0;
        virtual Matrix4 *rotX(double theta, bool aroundOrigin) = 0;
        virtual Matrix4 *rotY(double theta, bool aroundOrigin) = 0;
        virtual Matrix4 *rotZ(double theta, bool aroundOrigin) = 0;
        virtual Matrix4 *transform(Matrix4 M) =0;
    };
}
#endif //RAYTRACER_C_TRANSFORMABLE_H
