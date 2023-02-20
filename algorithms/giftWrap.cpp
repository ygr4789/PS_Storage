#include <bits/stdc++.h>
using namespace std;

const double PI = 2.0 * acos(0.0);

struct vector2 {
  double x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

  bool operator==(const vector2 &rhs) const { return x == rhs.x && y == rhs.y; }
  bool operator<(const vector2 &rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; }
  vector2 operator+(const vector2 &rhs) const { return vector2(x + rhs.x, y + rhs.y); }
  vector2 operator-(const vector2 &rhs) const { return vector2(x - rhs.x, y - rhs.y); }
  vector2 operator-() const { return vector2(-x, -y); }
  vector2 operator*(double rhs) const { return vector2(x * rhs, y * rhs); }

  double norm() const { return hypot(x, y); }
  vector2 normalize() const { return vector2(x / norm(), y / norm()); }

  double polor() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
  double dot(const vector2 &rhs) const { return x * rhs.x + y * rhs.y; }
  double cross(const vector2 &rhs) const { return x * rhs.y - y * rhs.x; }

  vector2 project(const vector2 &rhs) const {
    vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }

  double ccw(const vector2 &a, const vector2 &b) {
    return (a - *this).cross(b - *this);
  }
};

vector<vector2> giftWrap(const vector<vector2> &points) {
  int n = points.size();
  vector<vector2> hull;
  vector2 pivot = *min_element(points.begin(), points.end());
  hull.push_back(pivot);
  while (true) {
    vector2 ph = hull.back(), next = points[0];
    for (int i = 0; i < n; i++) {
      double cross = ph.ccw(next, points[i]);
      double dist = (next - ph).norm() - (points[i] - ph).norm();
      if (cross < 0 || (cross == 0 && dist < 0)) {
        next = points[i];
      }
    }
    if (next == pivot) break;
    hull.push_back(next);
  }
  return hull;
}