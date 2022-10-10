#include <iostream>
#include <vector>
using namespace std;
typedef struct Point {
  double x, y;
  Point() {}
} Point;
double polygonarea(vector<Point>& polygon, int N) {
  int i, j;
  double area = 0;
  for (i = 0; i < N; i++) {
    j = (i + 1) % N;
    area += polygon[i].x * polygon[j].y;
    area -= polygon[i].y * polygon[j].x;
  }
  area /= 2;
  return (area < 0 ? -area : area);
}

//测试函数
int main() {
  vector<Point> polygon;
  int n;
  cin >> n;
  polygon.resize(n);
  int i = 0;
  while (n--) {
    double x, y;
    cin >> x >> y;
    polygon[i].x = x;
    polygon[i].y = y;
    ++i;
  }
  cout << "此多边形的面积为" << polygonarea(polygon, polygon.size()) << endl;

  return 0;
}
