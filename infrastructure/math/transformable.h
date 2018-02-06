//
// Created by Don Isaac on 1/30/18.
//

#ifndef RAYTRACER_C_TRANSFORMABLE_H
#define RAYTRACER_C_TRANSFORMABLE_H

#include "vec3.h"
#include "mat4.h"

using namespace std;
namespace bla{
    /**
     * Represents any object that can be transformed in 3D space.
     * This class is meant to be used with any object that has a
     * <code>Matrix4</code> field, allowing for external code to
     * modify said <code>Matrix4</code> in a controlled manner.
     */
    class Transformable{
    public:
        virtual void translate(double x, double y, double z) = 0;
        virtual void translate(Vector3 v) = 0;
        virtual void rotX(double theta, bool aroundOrigin) = 0;
        virtual void rotY(double theta, bool aroundOrigin) = 0;
        virtual void rotZ(double theta, bool aroundOrigin) = 0;
        virtual void transform(Matrix4 M) =0;
    };
}
#endif //RAYTRACER_C_TRANSFORMABLE_H
