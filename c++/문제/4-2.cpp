#include <iostream>
using namespace std;

class Point
{
private:
  int xpos, ypos;
public:
  void Init(int x, int y)
  {
    xpos=x;
    ypos=y;
  }
  void ShowPointInfo() const
  {
    cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
  }
};

class Circle
{
private:
  int radius;
  Point point;
public:
  void InitPointInfo(int x, int y, int r)
  { 
    point.Init(x, y);
    radius=r;
  }
  void ShowCircleInfo() const
  {
    cout<<"Inner Circle Info..."<<endl;
    cout<<"radius: "<<radius<<endl;
    point.ShowPointInfo();
  }
};

class Ring
{
private:
  Circle circle1;
  Circle circle2;
public:
  void Init(int x, int y, int z, int a, int b, int c)
  {
    circle1.InitPointInfo(x, y, z);
    circle2.InitPointInfo(a, b, c);
  }
  void ShowRingInfo() const
  {
    circle1.ShowCircleInfo();
    circle2.ShowCircleInfo();
  }
};

int main(void)
{
  Ring ring;
  ring.Init(1, 1, 4, 2, 2, 9);
  ring.ShowRingInfo();
  return 0;
}
