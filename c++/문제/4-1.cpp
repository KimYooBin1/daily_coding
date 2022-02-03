#include <iostream>
#include <cstring>
using namespace std;

class FruitSeller
{
private:
  int APPLE_PRICE;
  int numOfApples;
  int myMoney;
  
public:
  void InitMembers(int price, int num, int money)
  {
    APPLE_PRICE=price;
    numOfApples=num;
    myMoney=money;
  }
  int SaleApples(int money)
  {
    int num=money/APPLE_PRICE;
    numOfApples-=num;
    myMoney+=money;
    return num;
  }
  void ShowSalesResult()
  {
    cout<<"남은 사과: "<<numOfApples<<endl;
    cout<<"판매 수익: "<<myMoney<<endl;
  }
};

class FruitBuyer
{
  int myMoney;
  int numOfApples;
  
public:
  bool InitMembers(int money)
  { 
    if(money < 0)
    {
      cout<<"돈이 잘못 입력되었습니다."<<endl;
      return false;
    }
    myMoney=money;
    numOfApples=0;
    return true;
  }
  void BuyApples(FruitSeller &seller, int money)
  {
    numOfApples=seller.SaleApples(money);
    myMoney-=money;
  }
  void ShowBuyResult()
  {
    cout<<"현재 잔액: "<<myMoney<<endl;
    cout<<"사과 개수: "<<numOfApples<<endl;
  }
};

int main(void)
{
  FruitSeller seller;
  seller.InitMembers(1000, 20, 0);
  FruitBuyer buyer;
  if(!buyer.InitMembers(-1))
  {
    cout<<"구매 실패"<<endl;
  }
  if(!buyer.InitMembers(5000))
  {
    cout<<"구매 실패"<<endl;
  }
  buyer.BuyApples(seller, 2000);
  
  cout<<"과일 판매자의 현황"<<endl;
  seller.ShowSalesResult();
  cout<<"과일 구매자의 현황"<<endl;
  buyer.ShowBuyResult();
  return 0;
}
