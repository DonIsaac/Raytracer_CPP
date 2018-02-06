#include <iostream>
#include "./infrastructure/math/vec3.h"
#include "./infrastructure/math/mat4.h"

using namespace std;
using namespace bla;

int main() {
    // Matrix4* A = Matrix4::getTranslationInstance(1, 2, 3);
    //A->rotY(1.5, true);
    //A->translate(Vector3(2.0, 2.0, 2.0));
    //cout << A->toString() << endl;
    //cout << Matrix4::getRotYInstance(3.0).toString() << endl;
    double l[] = {1, 2, 3};
    Vector3 v = Vector3();
    cout << v.toString() << endl;

    return 0;
}