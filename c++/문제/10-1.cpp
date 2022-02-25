#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    void ShowInfo()
    {
        cout<<"x: "<<x<<" "<<"y: "<<y<<endl;
    }
    friend Point operator-(Point &a, Point &b);
};

Point operator-(Point &a, Point &b)
{
    Point c(a.x-b.x, a.y-b.y);
    return c;
}
int main()
{
    Point point1(10, 20);
    Point point2(5, 8);
    //Point point3 = operator-(point1,point2);
    Point point3 = point1-point2;
    point1.ShowInfo();
    point2.ShowInfo();
    point3.ShowInfo();
    
    return 0;
}
