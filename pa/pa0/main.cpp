#include <cmath>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>

using namespace std;
using std::acos;
using std::cos;
using std::sin;
using std::sqrt;

Eigen::Vector3f coordinate_transform(Eigen::Vector3f input_vec)
{
    Eigen::Matrix3f rotation_matrix, translate_matrix;
    float theta = 45.0 / 180.0 * acos(-1);
    rotation_matrix << cos(theta), -sin(theta), 0.0, sin(theta), cos(theta), 0.0, 0.0, 0.0, 1.0;
    translate_matrix << 1.0, 0.0, 1.0, 0.0, 1.0, 2.0, 0.0, 0.0, 1.0;

    Eigen::Vector3f result_vec;
    result_vec = translate_matrix * rotation_matrix * input_vec;
    return result_vec;
}

int main2()
{
    // Basic Example of cpp
    cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    cout << a << endl;
    cout << a / b << endl;
    cout << sqrt(a) << endl;
    cout << acos(-1) << endl;
    cout << sin(30.0 / 180.0 * acos(-1)) << endl;

    // Example of vector
    cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f, 2.0f, 3.0f);
    Eigen::Vector3f w(1.0f, 1.0f, 1.0f);
    // vector output
    cout << "Example of output \n";
    cout << v << endl;
    // vector add
    cout << "Example of add \n";
    cout << v + w << endl;
    // vector scalar multiply
    cout << "Example of scalar multiply \n";
    cout << v * 3.0f << endl;
    cout << 2.0f * v << endl;

    // Example of matrix
    cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i, j, e;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    e << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0;
    // matrix output
    cout << "Example of output \n";
    cout << "Matrix i \n";
    cout << i << endl;
    cout << "Matrix j \n";
    cout << j << endl;
    // matrix add i + j
    cout << "Example of matrix add \n";
    cout << i + j << endl;
    // matrix scalar multiply i * 2.0
    cout << "Example of matrix scalar multiply \n";
    cout << i * 2.0 << endl;
    // matrix multiply i * j
    cout << "Example of matrix multiply \n";
    cout << i * e << endl;
    // matrix multiply vector i * v
    cout << "Example of matrix multiply vector \n";
    cout << i * v << endl;

    return 0;
}

int main()
{
    Eigen::Vector3f p(2.0f, 1.0f, 1.0f), result;
    cout << "The input coordinate is ";
    cout << "[" << p[0] << ", " << p[1] << "]" << endl;
    result = coordinate_transform(p);
    cout << "The result of coordinate transform is ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
