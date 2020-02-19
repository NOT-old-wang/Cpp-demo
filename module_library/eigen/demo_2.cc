
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;

int main() {
  MatrixXd random_matrix =
      MatrixXd::Random(3, 2);  // 初始化一个3*2的随机(-1,1)矩阵
  cout << "random_matrix = " << endl << random_matrix << endl;

  // MatrixXd::Constant(3, 2, 1.2) 表示一个3*2的矩阵,其内元素皆为1.2
  auto m = (random_matrix + MatrixXd::Constant(3, 2, 1.2)) * 50;
  cout << "m =" << endl << m << endl;

  cout << "sum = " << endl << m.sum() << endl;  // 输出所有元素的和

  cout << "colwise_sum =" << endl << m.colwise().sum() << endl;  // 输出每列的和

  auto diagonal_vetor = m.diagonal();
  cout << "diagonal_vetor =" << endl
       << diagonal_vetor << endl;  // 输出m矩阵的对角向量

  auto diagonal_martix = MatrixXd(diagonal_vetor.asDiagonal());  // 构建对角矩阵
  cout << "diagonal_martix =" << endl << diagonal_martix << endl;

  VectorXd v(2);
  v << 1, 2;
  cout << "m * v =" << endl << m * v << endl;  // 矩阵和向量相乘

  VectorXd vector_line_random = VectorXd::LinSpaced(5, 0, 5);
  cout << "vector_line_random =" << endl
       << vector_line_random << endl;  // 向量线性分布

  auto m_block = m.block(0, 0, 1, 1);  // 按块选取
  cout << "m_block =" << endl << m_block << endl;
  cout << "m(1)=" << endl << m.row(1) << endl;  // 按行选取

  auto m_identity = MatrixXd::Identity(3, 4);  // 测试非n阶的单位矩阵
  cout << "m_identity = " << endl << m_identity << endl;

  cout << "m_reverse = " << endl << m.reverse() << endl;  // 翻转矩阵
}