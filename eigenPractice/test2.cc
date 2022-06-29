#include <cmath>
#include <iostream>
#include "/opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3/Eigen/Eigen"

int main(int argc, char *argv[]) {
  // 单位四元素
  Eigen::Quaterniond q = Eigen::Quaterniond(1, 0, 0, 0); // (w,x,y,z)
  // Eigen::Quaterniond q(1, 0, 0, 0); // (w,x,y,z)
  // Eigen::Quaterniond q(Eigen::Vector4d(0, 0, 0, 1)); // (x,y,z,w)
  std::cout << "\n单位四元素:\n" << q.coeffs() << std::endl; // (x,y,z,w)

  // 单位旋转矩阵
  Eigen::Matrix3d rotation_matrix3d = Eigen::Matrix3d::Identity();
  std::cout << "\n单位旋转矩阵:\n" << rotation_matrix3d << std::endl;

  // 旋转向量（轴角）
  Eigen::AngleAxisd angle_axis(M_PI / 4, Eigen::Vector3d(0, 0, 1)); // 绕z轴顺时针旋转45°(yaw)
  std::cout << "\n旋转向量:\naxi: " << angle_axis.axis().transpose() << ", angle: " << angle_axis.angle() * 180 / M_PI << std::endl;

  // 欧拉角
  Eigen::Vector3d euler_angles(0, 0, 45); // roll pitch yaw（自定义）
  std::cout << "\n欧拉角:\n(roll pitch yaw) = " << euler_angles.transpose() << std::endl;

  // 旋转向量->旋转矩阵
  rotation_matrix3d = angle_axis.matrix();
  // rotation_matrix3d = angle_axis.toRotationMatrix();
  std::cout << "\n旋转向量->旋转矩阵:\n" << rotation_matrix3d << std::endl;

  // 旋转矩阵->旋转向量（轴角）
  angle_axis.fromRotationMatrix(rotation_matrix3d);
  // angle_axis = rotation_matrix3d;
  std::cout << "\n旋转矩阵->旋转向量(轴角):\naxi: " << angle_axis.axis().transpose() << ", angle: " << angle_axis.angle() * 180 / M_PI << std::endl;

  // 旋转向量（轴角）->四元素
  q = Eigen::Quaterniond(angle_axis);
  std::cout << "\n旋转向量(轴角)->四元素:\n(w x y z) = " << q.w() << " " << q.x() << " " << q.y() << " " << q.z() << std::endl;

  // 四元素->旋转向量（轴角）
  angle_axis = q;
  std::cout << "\n四元素->旋转向量(轴角):\naxi: " << angle_axis.axis().transpose() << ", angle: " << angle_axis.angle() * 180 / M_PI << std::endl;

  // 旋转矩阵->四元素
  q = Eigen::Quaterniond(rotation_matrix3d);
  // q = rotation_matrix3d;
  std::cout << "\n旋转矩阵->四元素:\n(w x y z) = " << q.w() << " " << q.x() << " " << q.y() << " " << q.z() << std::endl;

  // 四元素->旋转矩阵
  rotation_matrix3d = q.matrix();
  // rotation_matrix3d = q.toRotationMatrix();
  std::cout << "\n四元素->旋转矩阵:\n" << rotation_matrix3d << std::endl;

  // 旋转矩阵->欧拉角
  euler_angles = rotation_matrix3d.eulerAngles(0, 1, 2);
  std::cout << "\n旋转矩阵->欧拉角:\n(roll pitch yaw) = " << euler_angles.transpose() * 180 / M_PI << std::endl;

  return 0;
}
