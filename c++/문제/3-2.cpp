#include <iostream>
#include <cstring>
using namespace std;

class Calculator
{
private:
  int numofadd;
  int numofdiv;
  int numofmul;
  int numofmin;
public:
  void Init(){
      numofadd = 0;
      numofmin = 0;
      numofmul = 0;
      numofdiv = 0;
  }
  double Add(double x, double y)  #double 말고 void로 했을 떄는 왜 오류가 나는지;;
  {
    numofadd++;
    return x+y;
  }
  double Div(double x, double y)
  {
    numofdiv++;
    return x/y;
  }
  double Min(double x, double y)
  {
    numofmin++;
    return x-y;
  }
  double Mul(double x, double y)
  {
    numofmul++;
    return x*y;
  }
  void ShowOpCount()
  {
    cout<<"덧셈: "<<numofadd<<"뺄셈: "<<numofmin<<"곱셈: "<<numofmul<<"나눗셈: "<<numofdiv<<endl;
  }
};
  
int main(void)
{
  Calculator cal;
  cal.Init();
  cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
  cout<<"3.5 / 1.7 = "<<cal.Div(3.2, 2.4)<<endl;
  cout<<"2.2 - 1.5 = "<<cal.Min(3.2, 2.4)<<endl;
  cout<<"4.9 / 1.2 = "<<cal.Div(3.2, 2.4)<<endl;
  cal.ShowOpCount();
  return 0;
}
