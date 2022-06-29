#include <cmath>
#include <iostream>
#include "/opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3/Eigen/Eigen"
 
// wrap the angle within [-PI, PI)
double WrapToPI(double ang_in_rad) {
  int c = ang_in_rad / (2.0 * M_PI);
  ang_in_rad -= c * (2.0 * M_PI);
  if (ang_in_rad < -M_PI) {
    ang_in_rad += 2.0 * M_PI;
  }
  if (ang_in_rad >= M_PI) {
    ang_in_rad -= 2.0 * M_PI;
  }
  return ang_in_rad;
}
 
int main(int argc, char *argv[]) {
  double roll = 30;
  double pitch = 45;
  double yaw = 90;
  std::cout << "\n指定欧拉角(roll pitch yaw): " << roll << " " << pitch << " " << yaw << std::endl;
 
  Eigen::Vector3d p1(0, 1, 0); // 点p在o1参考系下的坐标为(0, 1, 0)
  std::cout << "\n点p在o1参考系下的坐标p1: " << p1.transpose() << std::endl;
 
  Eigen::AngleAxisd v_21(yaw * M_PI / 180, Eigen::Vector3d::UnitZ()); // o1参考系绕其z轴(转yaw)顺时针旋转90度得到o2参考系
  Eigen::Matrix3d R_21 = v_21.matrix();
  Eigen::Vector3d p2 = R_21 * p1; // 点p在o2参考系下的坐标为(-1, 0, 0)
  std::cout << "\n点p在o2参考系下的坐标p2: " << p2.transpose() << std::endl;
 
  Eigen::AngleAxisd v_32(pitch * M_PI / 180, Eigen::Vector3d::UnitY()); // o2参考系绕其y轴(pitch)顺时针旋转45度得到o3参考系
  Eigen::Matrix3d R_32 = v_32.matrix();
  Eigen::Vector3d p3 = R_32 * p2; // 点p在o3参考系下的坐标为(-0.707, 0, 0.707)
  std::cout << "\n点p在o3参考系下的坐标p3: " << p3.transpose() << std::endl;
 
  Eigen::AngleAxisd v_43(roll * M_PI / 180, Eigen::Vector3d::UnitX()); // o3参考系绕其x轴(roll)顺时针旋转30度得到o4参考系
  Eigen::Matrix3d R_43 = v_43.matrix();
  Eigen::Vector3d p4 = R_43 * p3; // 点p在o4参考系下的坐标为(-0.707, -0.35, 0.61)
  std::cout << "\n点p在o4参考系下的坐标p4: " << p4.transpose() << std::endl;
 
  Eigen::Matrix3d R_41 = R_43 * R_32 * R_21; // 先绕z轴顺时针旋转90度，再绕y轴顺时针旋转45度，最后绕x轴顺时针旋转30度
  // Eigen::Matrix3d R_41 = v_43 * v_32 * v_21;
  p4 = R_41 * p1; // 点p在o4参考系下的坐标为(-0.707, -0.353, 0.612)
  std::cout << "\n点p在o4参考系下的坐标p4: " << p4.transpose() << std::endl;
 
  // 旋转矩阵->欧拉角
  Eigen::Vector3d euler_angles = R_41.eulerAngles(0, 1, 2); // (0,1,2) 表示分别绕XYZ轴顺序（与上面旋转顺序相反），即按roll,pitch,yaw顺序，顺时针为正
  // Euler's angles are not unique.
  // eigen has two sets of euler angles: (a, b, c) or (pi+a, pi-b, pi+c)
  // In your XYZ convention, both (0, pi, pi) and (pi, 0, 0) represents the same rotation, and both are correct.
  // The Eigen::eulerAngles method consistently chooses to minimize first angles.
  if (std::fabs(euler_angles(1)) > M_PI / 2) {
    euler_angles(0) = WrapToPI(M_PI + euler_angles(0));
    euler_angles(1) = WrapToPI(M_PI - euler_angles(1));
    euler_angles(2) = WrapToPI(M_PI + euler_angles(2));
  }
  std::cout << "\n旋转矩阵->欧拉角(roll pitch yaw): " << euler_angles.transpose() * 180 / M_PI << std::endl; // 30 45 90
 
  return 0;
}