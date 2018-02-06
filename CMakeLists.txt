cmake_minimum_required(VERSION 3.9)
project(Raytracer_C__)

set(CMAKE_CXX_STANDARD 98)

add_executable(Raytracer_C__ main.cpp infrastructure/math/vec3.h infrastructure/math/mat4.h infrastructure/math/ray.h infrastructure/math/transformable.h infrastructure/math/sphere.h)