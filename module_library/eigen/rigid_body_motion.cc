
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>
#include <iostream>
/*
 旋转表示方法: 欧拉角(表示沿哪个轴旋转)，旋转向量(旋转轴+旋转角)，旋转矩阵，
 四元数(增加一纬度，避免万向锁)
 */

int main(int argc, char** argv) {
  // 输出精度为小数点后1位
  std::cout.precision(1);
  // 旋转矩阵 Identity就是设置为单位矩阵
  Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
  std::cout << "rotation_matrix = \n" << rotation_matrix << std::endl;
  // 旋转向量（轴向量）沿z轴45度, 逆时针为正
  Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));
  std::cout << "rotation_vector axis: " << rotation_vector.axis().transpose()
            << std::endl;
  std::cout << "rotation_vector angle: " << rotation_vector.angle()
            << std::endl;

  /**** 旋转向量 <--> 四元数|欧拉角 <--> 旋转矩阵 互相转化相关 *****/

  // [旋转向量] <--> [旋转矩阵]
  std::cout << "rotation_matrix = \n" << rotation_vector.matrix() << std::endl;
  rotation_matrix = rotation_vector.toRotationMatrix();
  std::cout << "rotation_matrix = \n" << rotation_matrix << std::endl;

  // [旋转向量] <--> [四元数]
  //  Eigen::Quaterniond q = Eigen::Quaterniond(1, 0, 0, 0);  //(w,x,y,z)
  Eigen::Quaterniond quaterniond = Eigen::Quaterniond(rotation_vector);
  std::cout << "quaternion = " << quaterniond.coeffs().transpose() << std::endl;
  // quaterniond.x() quaterniond.y() quaterniond.z() quaterniond.w()
  // rotation_vector = quaterniond;

  // [旋转矩阵] <--> [四元数]
  quaterniond = Eigen::Quaterniond(rotation_matrix);
  std::cout << "quaternion = " << quaterniond.coeffs().transpose() << std::endl;
  //   quaterniond.toRotationMatrix();

  // [旋转矩阵] <--> [欧拉角]
  // ZYX顺序，即yaw pitch roll顺序, (0,1,2)表示分别绕XYZ轴顺序，即pitch yaw
  // roll顺序，逆时针为正
  Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
  std::cout << "eulerAngles = \n" << euler_angles.transpose() << std::endl;
  std::cout << "yaw pitch roll = \n" << euler_angles.transpose() << std::endl;
  ;
  //   std::cout << euler_angles[0] << "," << euler_angles[1] << ","
  //             << euler_angles[2] << std::endl;

  // yaw
  Eigen::AngleAxisd angleAxis2 =
      Eigen::AngleAxisd(euler_angles[0], Eigen::Vector3d::UnitZ());
  // pitch
  Eigen::AngleAxisd angleAxis1 =
      Eigen::AngleAxisd(euler_angles[1], Eigen::Vector3d::UnitY());
  // roll
  Eigen::AngleAxisd angleAxis0 =
      Eigen::AngleAxisd(euler_angles[2], Eigen::Vector3d::UnitX());
  Eigen::Matrix3d test =
      angleAxis2.matrix() * angleAxis1.matrix() * angleAxis0.matrix();
  std::cout << "test = \n" << test << std::endl;
  std::cout << "test -> eulerAngle = \n"
            << test.eulerAngles(2, 1, 0) << std::endl;

  /*********** 坐标变换相关 ***********/
  Eigen::Vector3d v(1, 0, 0);

  // 用angleAxis进行坐标变换
  Eigen::Vector3d v_rotated = rotation_vector * v;
  std::cout << "(1,0,0) after rotation = \n"
            << v_rotated.transpose() << std::endl;

  // 使用四元数旋转一个向量
  v_rotated = quaterniond * v;
  // std::cout << v_rotated << std::endl;

  // 用旋转矩阵进行坐标变换
  v_rotated = rotation_matrix * v;
  std::cout << "(1,0,0) after rotation = \n" << v_rotated.transpose() << std::endl;

  // 用欧式变换矩阵(旋转+平移)进行坐标变化
  // rotation 可以是旋转矩阵，可以是四元数，可以是旋转向量
  auto rotation = rotation_matrix;
  // Eigen:Isometry3d T(rotation);
  // 如果没有直接初始化，先设为单位阵，欧氏变换矩阵（4 x 4
  // ）虽然称为3d，实质上是4＊4的矩阵
  Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
  // 然后添加旋转矩阵，或者向量，或者四元数，// T.rotate(rotation_vector);
  T.prerotate(rotation);
  // 添加平移向量
  T.pretranslate(Eigen::Vector3d(1, 3, 4));
  std::cout << "Transform matrix = \n" << T.matrix() << std::endl;
  /*
  T.rotation(); // 返回旋转矩阵
  T.translation(); // 返回旋转矩阵
  */
  Eigen::Vector3d v_transformed = T * v;
  std::cout << "v_transformed = \n" << v_transformed.transpose() << std::endl;

  return 0;
}
