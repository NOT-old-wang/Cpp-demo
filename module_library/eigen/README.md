# eigen
## 概要
- Eigen是有关线性代数计算的C++模板库，里面还包含了基本的矩阵、数组的定义和使用，以及矩阵的各种分解、特征值、特征向量、行列式的计算,基本涵盖了各种需要对矩阵的操作.

## 安装
```bash
$ sudo apt-get install libeigen3-dev 
```
Eigen用源码的方式提供给用户使用，在使用时只需要包含Eigen的头文件即可进行使用.Eigen头文件的默认位置为/usr/include/eigen3/.

## 矩阵Martix
- 定义

矩阵模板函数中一共包含六个模板参数，前三个是比较常用的，分别表示矩阵元素的类型、行数、列数。在矩阵定义的时候可以使用 Dynamic 来表示行或者列数未知。
- ex:
```cpp
template<typename _Scalar, int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols>
class Eigen::Matrix< _Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols >

Eigen::Matrix<int, 3, 4> mat1;              //  3x4 的 int 类型的矩阵 mat1
Eigen::Matrix<double, 3, Dynamic> mat2;     //  3x? 的 double 类型的矩阵 mat2
Eigen::Matrix<float, Dynamic, 4> mat3;      //  ?x4 的 float 类型的矩阵 mat3
Eigen::Matrix<long, Dynamic, Dynamic> mat4; //  ?x? 的 long 类型的矩阵 mat4

```

- 类型
在 Eigen中typedef了很多矩阵的类型，通常命名为Matrix前缀加一个长度为1∼4的字符串S的命名——Matrix。其中S可以用来判断该矩阵类型，数字n表示n ∗ n,n的范围是2∼4，字母 d、f、i、cd表示 double、float、int、complex，另外X表示行或者列数未知的矩阵。

- ex:
```cpp
// 挑选几个常用的矩阵类型
typedef Matrix<double, 2, 2> Eigen::Matrix2d;                           //  2x2 的 double 类型的矩阵
typedef Matrix<double, 2, Dynamic> Eigen::Matrix2Xd;                   //  2x? 的 double 类型的矩阵
typedef Matrix<double, Dynamic, Dynamic> Eigen::MatrixXd;              //  ?x? 的 double 类型的矩阵
typedef Matrix<int, Dynamic, Dynamic> Eigen::MatrixXi;                 //  ?x? 的 i 类型的矩阵
typedef Matrix<float, 3, 3> Eigen::Matrix3f;                           //  ?x? 的 i 类型的矩阵


// 向量Vector是一种特殊的矩阵,默认为列向量
typedef Matrix<int, 2, 1> Eigen::Vector2i;                  //  int 类型的 2*1 向量
typedef Matrix<double, 4, 1> Eigen::Vector4d;               //  double 类型的 4*1 向量
typedef Matrix<float, Dynamic, 1> Eigen::VectorXf;          //  float 类型的 ?*1 向量

```

- 访问与赋值
与C++数组的操作不同的是，Eigen::Matrix不能通过[]来访问赋值数据的，而是需要通过()。矩阵之间也可以通过=来进行赋值（拷贝）。

- ex 
```cpp

x = mat(a, b);  //  获取到矩阵 mat 的 a+1 行 b+1 列的元素并赋值给 x
mat(b, a) = x;  //  将 x 赋值给矩阵 mat 的 b+1 行 a+1 列
mat1 = mat2;    //  将矩阵 mat2 赋值（拷贝）给矩阵 mat1

// Eigen中重载了<<可以用来赋值矩阵，也可以用cout输出矩阵。
MatrixXf m(4, 4);          //定义一个4x4的float类型的动态矩阵
m << 1, 2, 3, 4,
     5, 6, 7, 8,
     9, 10, 11, 12,
     13, 14, 15, 16;       //  赋值
std::cout << m;            //  输出m

// Eigen 矩阵还可以进行分块操作，通过成员函数block()获取某一部分矩阵。
mat = mat1.block(i, j, p, q);   //  从矩阵 mat1 的 i+1 行 j+1 列开始获取一个 p 行 q 列的子矩阵
mat = mat1.block<p, q>(i, j);   //  从矩阵 mat1 的 i+1 行 j+1 列开始获取一个 p 行 q 列的子矩阵（动态矩阵）

// Eigen 矩阵可以使用成员函数 row()、col() 来获取某一行或者某一列。
mat = mat1.row(i);  //  获取 mat1 的第 i+1 行
mat = mat1.col(j);  //  获取 mat1 的第 j+1 列  


// Vector向量可以使用[]来访问
x = vector(n);     //  获取向量 vector 的第 n 个元素并赋值给 x
x = vector[n];
vector(n) = x;     //  将 x 赋值给 vector 的第 n 个元素

// Vertor向量分块操作
vector.head(n);        // 获取向量的前n个元素
vector.tail(n);        // 获取向量的后n个元素
vector.segment(i,n);   // 获取从向量的第i个元素开始的n个元素
```
注: 通常Martix的赋值通过<<实现

## 常用的运算API

- 基础使用
```cpp
A.size()              // 获取矩阵中元素个数
A.rows()              // 获取矩阵中行数
A.cols()              // 获取矩阵中列数
A.resize(3,3)         // 重新分配矩阵行列数为3*3 (通常动态矩阵使用,静态矩阵原本不是3*3使用会报错)
A.fill(10)            // A矩阵内部元素全赋值为10
```

- 矩阵加减乘除
```cpp
// 这部分跟常规的运算基本一致,很好理解
// 需要强调的是,eigen不做自动类型转换,需要手动进行转换
mat = mat1 + mat2;  //  +
mat = mat1 - mat2;  //  -（减）
mat = mat1 * mat2;  //  *
mat = mat1 * n;     //  *
mat = mat1 / n;     //  /
mat = -mat1;        //  -（负）
mat += mat1;        //  +=
mat -= mat1;        //  -=
mat *= mat1;        //  *=
mat *= n;           //  *=
mat /= n;           //  /=
```

- 特殊矩阵 
```cpp
MatrixXd::Identity(rows,cols)       // rows*cols的单位矩阵 
A.setIdentity(rows,cols)            
MatrixXd::Zero(rows,cols)           // rows*cols的零矩阵
A.setZero(rows,cols)                
MatrixXd::Ones(rows,cols)           // rows*cols的矩阵 元素全为1
A.setOnes(rows,cols)                
MatrixXd::Random(rows,cols)         // rows*cols的矩阵 元素随机在-1->1
A.setRandom(rows,cols)  
VectorXd::LinSpaced(size,low,high)  // 线性分布的数组
A.setLinSpaced(size,low,high)      
```

- 矩阵转置

```cpp
A.adjoint()                        // 返回A矩阵的伴随矩阵
A.transpose()                      // 返回A矩阵的转置矩阵
A.diagonal()                       // 返回A矩阵的对角向量
x.asDiagonal()                     // 对角矩阵化
A.conjugate()                      // 返回A矩阵的共轭矩阵
A.inverse()                        // 返回A矩阵的逆
A.reverse()                        // 返回A矩阵翻转后的矩阵(原点对称变换)
A.determinant()                    // 返回A矩阵的行列式
```

```cpp
x.head(n)                          // 获取向量的前n个元素
x.head<n>()                        
x.tail(n)                          // 获取向量的后n个元素
x.tail<n>()                        
x.segment(i, n)                    // 获取从向量的第i个元素开始的n个元素
x.segment<n>(i)                    
A.block(i, j, rows, cols)          //  从矩阵 A 的 i+1 行 j+1 列开始获取一个 rows 行 cols 列的子矩阵
A.block<rows, cols>(i, j)          
A.row(i)                           //  获取 A 的第 i+1 行
A.col(j)                           //  获取 A 的第 j+1 列
```

- 矩阵化简
```cpp
A.minCoeff()              // A矩阵中最小的元素值
A.maxCoeff()              // A矩阵中最大的元素值
s = A.minCoeff(&r, &c)    // 计算最小值和它的位置
s = A.maxCoeff(&r, &c)    // 计算最大值和它的位置
A.sum()                   // 求和（所有元素）
A.colwise().sum()         // 按列求和  (最后会返回每列求和后的一组数据)
A.rowwise().sum()         // 按行求和  (最后会返回每行求和后的一组数据)
A.prod()                  // 所有乘积
A.colwise().prod()        // 按列求积  (最后会返回每列求积后的一组数据)
A.rowwise().prod()        // 按行求积  (最后会返回每行求积后的一组数据)
A.trace()                 // 求矩阵的迹
A.all()                   // 是否所有元素都非零 
A.colwise().all()         // 按列判断，是否该列所有元素都非零  
A.rowwise().all()         // 按行判断，是否该行所有元素都非零 
A.any()                   // 是否有元素非零
A.colwise().any()         // 按列判断，是否该列有元素都非零
A.rowwise().any()         // 按行判断，是否该行有元素都非零
```
- 点积
```cpp
x.norm()                  //模,也叫范数（注意：Eigen中没有norm(R)）  
x.squaredNorm()           //平方和（注意：对于复数而言，不等价）  
x.dot(y)                  //点积  
x.cross(y)                //交叉积，需要头文件 #include <Eigen/Geometry>  
```

- 类型转换
```cpp
A.cast<double>();         //变成双精度类型  
A.cast<float>();          //变成单精度类型  
A.cast<int>();            //整型  
A.real();                 //实部  
A.imag();                 //虚部 
```
- 矩阵特征值
```cpp
A.eigenvalues();                  // eig(A);特征值
EigenSolver<Matrix3d> eig(A);     // [vec val] = eig(A)
eig.eigenvalues();                // diag(val)与前边的是一样的结果
eig.eigenvectors();               // vec 特征值对应的特征向量
```

- 求解线性方程组 Ax = b
```cpp
x = A.ldlt().solve(b));  // #include <Eigen/Cholesky>LDLT分解法实际上是Cholesky分解法的改进
x = A.llt() .solve(b));  // A sym. p.d.      #include <Eigen/Cholesky>
x = A.lu()  .solve(b));  // Stable and fast. #include <Eigen/LU>
x = A.qr()  .solve(b));  // No pivoting.     #include <Eigen/QR>
x = A.svd() .solve(b));  // Stable, slowest. #include <Eigen/SVD>
```

## 后续扩展
- [分解问题](https://blog.csdn.net/u012936940/article/details/79871941)



## 参考教程
- [官方文档](http://eigen.tuxfamily.org/dox/index.html)
- [简书文档](https://www.jianshu.com/p/c40f36e85eaf)
- [blog参考](https://blog.csdn.net/u012541187/article/details/53420432)