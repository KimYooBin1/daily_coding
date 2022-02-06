#include <iostream>
using namespace std;

class NameCard
{
private:
    char name[];
    char ComName[];
    char number[];
    int rank;
    enum {CLERK, SENIOR, ASSIST, MANAGER};
public:
    NameCard(name, ComName, number, rank)
    {
        cout<<"생성자 실행"<<endl;
    }
    void ShowNameCardInfo();
    {
        cout<<"hello world"<<endl;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCRng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::Assist);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}
