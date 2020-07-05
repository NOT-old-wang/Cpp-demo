#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  cout << "##-------------------常用数学运算-------------------##" << endl;
  Eigen::Vector3d v4(1, 1, 0);
  cout << "(1, 1, 0)模长：" << v4.norm() << endl;
  cout << "(1, 1, 0)单位向量：" << v4.normalized().transpose() << endl;

  Eigen::Vector3d v5(1, 0, 0), v6(0, 1, 0);
  cout << "(1, 0, 0)点乘(0, 1, 0):" << v5.dot(v6) << endl;
  cout << "(1, 0, 0)叉乘(0, 1, 0):" << v5.cross(v6).transpose() << endl;

  cout << "##----------------------使用块----------------------##" << endl;
  Eigen::Matrix<double, 4, 4> T12;
  T12.Identity();  //设为单位阵

  Eigen::AngleAxisd angle_axis(M_PI / 4, Eigen::Vector3d(0, 0, 1));
  Eigen::Matrix3d R12(angle_axis);  //用角轴初始化旋转矩阵

  Eigen::Vector3d t12;
  t12.setOnes();  //各分量设为1
  // t.setZero();//各分量设为0

  T12.block<3, 3>(0, 0) = R12;
  T12.block<3, 1>(0, 3) = t12;
  cout << "旋转R12：" << endl << T12.topLeftCorner(3, 3) << endl;
  cout << "平移t12：" << T12.topRightCorner(3, 1).transpose()
       << endl;  // 2系原点在1系下的坐标

  cout << "##---------------欧式变换矩阵(Isometry)-------------##" << endl;
  Eigen::Isometry3d T = Eigen::Isometry3d::
      Identity();  //虽然称为3d，实质上是4x4的矩阵(旋转R+平移t)
  T.linear() = Eigen::Matrix3d::Identity();  //旋转部分赋值
  // T.linear() << 1, 0, 0, 0, 1, 0, 0, 0, 1;//cv::Mat赋值
  // T.rotate(Eigen::Matrix3d::Identity());
  // T.rotate(angle_axis);
  T.translation() = Eigen::Vector3d(1, 1, 1);  //平移部分赋值
  // Eigen::Isometry3d T(quaterniond);
  // T(0,3) = 1; T(1,3) = 1; T(2,3) = 1;
  cout << "R_12: " << endl << T.linear().matrix() << endl;  //输出旋转部分
  cout << "t_12:" << T.translation().transpose() << endl;   //输出平移部分
  cout << "T_12: " << endl << T.matrix() << endl;  //输出4x4变换矩阵
  cout << "T_12*(1, 2, 3): " << endl
       << (T * Eigen::Vector3d(1, 2, 3)).transpose()
       << endl;  //相当于R21*v+t21,隐含齐次坐标(1，2，3，1)

  // Eigen::Quaterniond q = T.rotation();
  // Eigen::Quaterniond q(T.linear());
  // cout << "q: " << q.w() << " " << q.x() << " " << q.y() << " " << q.z() <<
  // endl;

  cout << "##------------------解线性方程------------------##" << endl;
  // AX = 0
  //(AX)`(AX)
  // X`(A`A)X
  // Eigen::SelfAdjointEigenSolver<Eigen::Matrix4d> self_adjoint_solver;
  // self_adjoint_solver.compute(ATA);
  // cout << "eigenvalues:\n" << self_adjoint_solver.eigenvalues();
  // cout << "eigenvectors:\n" << self_adjoint_solver.eigenvectors();
  // Eigen::Vector4d wxyz = self_adjoint_solver.eigenvectors().col(0);

  // Eigen::EigenSolver<Eigen::Matrix4d> general_solver;
  // general_solver.compute(ATA);
  // cout << "eigenvalues:\n" << general_solver.eigenvalues();
  // cout << "eigenvectors:\n" << general_solver.eigenvectors();
  // // wxyz = general_solver.eigenvectors().col(0);

  // // AX=B
  // Eigen::Vector3d t =
  //     A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(B);

  // getchar();

  //   std::cout << Eigen::Vector2d::Ones() << std::endl;
  return 0;
}