#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char * name;
    int age;
public:
    Person(char * myname, int myage)
    {
        int len=strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age=myage;
    }
    Person()
    {
        name = NULL;
        age=0;
        cout<<"called Person()"<<endl;
    }
    void setPersonInfo(char * myname, int myage)
    {
        name=myname;
        age=myage;
    }
    void ShowPersinInfo() const
    {
        cout<<"이름: "<<name<<", ";
        cout<<"나이: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor"<<endl;
    }
};

int main(void)
{
    Person parr[3];
    char namestr[100];
    char * strptr;
    int age;
    int len;
    
    for(int i=0;i<3;i++)
    {
        cout<<"이름: ";
        cin>>namestr;
        cout<<"나이: ";
        cin>>age;
        len=strlen(namestr)+1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].setPersonInfo(strptr, age);   //strptr 값이 delete를 통해 계속 초기화되어야된다
    }
    parr[0].ShowPersinInfo();
    parr[1].ShowPersinInfo();
    parr[2].ShowPersinInfo();
    return 0;
}
