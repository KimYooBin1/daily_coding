#include <iostream>
#include <cstring>

using namespace std;

class Rectangle
{
public:
    int width;
    int height;
    double area;
    Rectangle(int x, int y) : width(x), height(y)
    {
        area = width * height;
    }
    void ShowAreaInfo()
    {
        cout<<"면적: "<<area<<endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int x) : Rectangle(x, x)
    {
        area = width * height;
    }
};

int main()
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();
    
    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}
