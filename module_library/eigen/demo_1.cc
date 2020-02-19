#include <Eigen/Core>
#include <iostream>

void PrintMatrix(
    const Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic> matrix) {
  std::cout << matrix << std::endl;
  std::cout << std::endl;
}

int main(int argc, const char** argv) {
  Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic> matrix;

  Eigen::Matrix<int, 4, 4> temp;
  temp << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
  matrix = temp;
  PrintMatrix(matrix);

  matrix.resize(3, 4);
  // 零矩阵
  matrix.setZero();
  PrintMatrix(matrix);
  // 单位矩阵
  matrix.resize(3, 3);
  matrix.setIdentity();
  PrintMatrix(matrix);

  // matrix.setRandom();
  // PrintMatrix(matrix);

  // // 线性填充
  // Eigen::Matrix<int, 3, 1> vector;
  // vector.setLinSpaced(3, 1, 3);
  // PrintMatrix(vector);

  matrix = temp;
  // 伴随阵
  PrintMatrix(matrix.adjoint());
  // 转置
  PrintMatrix(matrix.transpose());
  // 对角向量
  PrintMatrix(matrix.diagonal());
  // 矩阵的逆
  // PrintMatrix(matrix.inverse());
}