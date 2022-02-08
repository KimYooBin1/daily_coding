#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };
    
    void ShowComp_Pos(int rank)
    {
        switch(rank)
        {
                case CLERK:
                    cout<<"사원"<<endl;
                    break;
                case SENIOR:
                    cout<<"주임"<<endl;
                    break;
                case ASSIST:
                    cout<<"대리"<<endl;
                    break;
                case MANAGER:
                    cout<<"과장"<<endl;
        }
    }
}

class NameCard
{
private:
    char * myname;
    char * myComName;
    char * mynumber;
    int myrank;
public:
    NameCard(const char * name,const char * ComName,const char * number, int rank) : myrank(rank)
    {
        int len1=strlen(name)+1;
        myname = new char[len1];
        strcpy(myname, name);
        
        int len2=strlen(ComName)+1;
        myComName = new char[len2];
        strcpy(myComName, ComName);
        
        int len3=strlen(number)+1;
        myComName = new char[len3];
        strcpy(mynumber, number);
        
        
    }
    void ShowNameCardInfo()
    {
        cout<<"이름: "<<myname<<endl;
        cout<<"회사: "<<myComName<<endl;
        cout<<"전화번호: "<<mynumber<<endl;
        cout<<"사원: "; COMP_POS::ShowComp_Pos(myrank);
        cout<<endl;
        
    }
    ~NameCard()
    {
        delete []myname;
        delete []myComName;
        delete []mynumber;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCRng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}
