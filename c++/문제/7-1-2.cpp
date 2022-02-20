#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(const char * myname, int myage) : age(myage)
    {
        cout<<"MyFriendInfo(const char * myname, int myage) : age(myage)"<<endl;
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~MyFriendInfo()
    {   
        cout<<"~MyFriendInfo()"<<endl;
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(const char * myname, int myage, const char * myaddr, const char * myphone) : MyFriendInfo(myname, myage)
    {
        cout<<"MyFriendDetailInfo(const char * myname, int myage, const char * myaddr, const char * myphone) : MyFriendInfo(myname, myage)"<<endl;
        addr = new char[strlen(myaddr)+1];
        strcpy(addr, myaddr);
        phone = new char[strlen(myphone)+1];
        strcpy(phone, myphone);
    }
    void ShowFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl<<endl;
    }
    ~MyFriendDetailInfo()
    {
        cout<<"~MyFriendDetailInfo()"<<endl;
        delete []addr;
        delete []phone;
    }
};
int main()
{
    MyFriendDetailInfo MJ("M.J", 18, "13.street", "010-1111-2222");
    MJ.ShowFriendDetailInfo();
    return 0;
}
