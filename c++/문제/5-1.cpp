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
    NameCard(const char * name,const char * ComName,const char * number, int rank) : myrank(rank)           //c++ 버전문제로 char *은 상수취급으로 const를 붙혀야된다
    {
        int len1=strlen(name)+1;
        myname = new char[len1];
        strcpy(myname, name);
        
        int len2=strlen(ComName)+1;
        myComName = new char[len2];
        strcpy(myComName, ComName);
        
        int len3=strlen(number)+1;
        mynumber = new char[len3];
        strcpy(mynumber, number);
        
        
    }
    NameCard(const NameCard &copy)
    {
        myname = new char [strlen(copy.myname) + 1];
        strcpy(myname, copy.myname);
        myComName = new char [strlen(copy.myComName) + 1];
        strcpy(myComName, copy.myComName);
        mynumber = new char [strlen(copy.mynumber) + 1];
        strcpy(mynumber, copy.mynumber);
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
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1=manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2=manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}
