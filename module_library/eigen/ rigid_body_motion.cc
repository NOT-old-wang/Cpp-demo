
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  cout << "hello-----" << endl;
  cout.precision(3);
  //旋转矩阵
  Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
  cout << "rotation_matrix = \n" << rotation_matrix << endl;
  //旋转向量（轴向量）
  Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));

  //轴向量 --> 旋转矩阵
  cout << "rotation_matrix = \n" << rotation_vector.matrix() << endl;
  rotation_matrix = rotation_vector.toRotationMatrix();
  cout << "rotation_matrix = \n" << rotation_matrix << endl;

  Eigen::Vector3d v(1, 0, 0);
  //用angleAxis进行坐标变换
  Eigen::Vector3d v_rotated = rotation_vector * v;
  cout << "(1,0,0) after rotation = \n" << v_rotated.transpose() << endl;
  //用旋转矩阵进行坐标变换
  v_rotated = rotation_matrix * v;
  cout << "(1,0,0) after rotation = \n" << v_rotated << endl;

  //旋转矩阵 --> 欧拉角
  Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
  cout << "yaw pitch roll = \n" << euler_angles.transpose();

  //变换矩阵 (轴向量 --> 变换矩阵)
  Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
  T.rotate(rotation_vector);
  T.pretranslate(Eigen::Vector3d(1, 3, 4));

  cout << "Transform matrix = \n" << T.matrix() << endl;
  // cout << T.rotation() << "\n" << T.translation() << endl;

  //用变换矩阵进行坐标变换
  Eigen::Vector3d v_transformed = T * v;
  cout << "v_transformed = \n" << v_transformed << endl;

  //四元数 (轴向量 --> 四元数)
  Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
  cout << "quaternion = \n" << q.coeffs() << endl;

  q = Eigen::Quaterniond(rotation_matrix);
  cout << "quaternion = \n" << q.coeffs() << endl;

  //使用四元数旋转一个向量
  v_rotated = q * v;
  cout << v_rotated << endl;

  //欧拉角 --> 旋转矩阵
  cout << "eulerAngles = \n" << euler_angles << endl;
  cout << euler_angles[0] << "," << euler_angles[1] << "," << euler_angles[2]
       << endl;

  /*
  Eigen::Matrix3d test =
  Eigen::AngleAxisd(euler_angles[0], Eigen::Vector3d::UnitZ()) *\
  Eigen::AngleAxisd(euler_angles[1], Eigen::Vector3d::UnitY()) *\
  Eigen::AngleAxisd(euler_angles[2], Eigen::Vector3d::UnitX());
  */

  //欧拉角->旋转矩阵
  Eigen::AngleAxisd angleAxis2 =
      Eigen::AngleAxisd(euler_angles[0], Eigen::Vector3d::UnitZ());
  Eigen::AngleAxisd angleAxis1 =
      Eigen::AngleAxisd(euler_angles[1], Eigen::Vector3d::UnitY());
  Eigen::AngleAxisd angleAxis0 =
      Eigen::AngleAxisd(euler_angles[2], Eigen::Vector3d::UnitX());

  Eigen::Matrix3d test =
      angleAxis2.matrix() * angleAxis1.matrix() * angleAxis0.matrix();

  cout << "test = \n" << test << endl;

  cout << "test -> eulerAngle = \n" << test.eulerAngles(2, 1, 0) << endl;
  // cout << Eigen::Vector3d::UnitZ() << endl;
  return 0;
}
