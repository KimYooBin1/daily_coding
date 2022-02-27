#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    int len = 0;
    char *str;
public:
    String()
    {
        len=0;
        str=NULL;
    }
    
    String(const char *str)
    {
        this->str = new char[strlen(str)+1];
        strcpy(this->str, str);
    }
    
    String(const String& string)
    {
        str = new char[strlen(string.str)+1];
        strcpy(str, string.str);
    }
    
    ~String()
    {
        if(str!=NULL)
        {
            delete []str;
        }
    }
    
    String operator= (const char * str)
    {
        if(this->str!=NULL)
        {
            this->str = NULL;
        }
        String string(str);
        return string;
    }
    
    String& operator= (const String& string)
    {
        if(this->str!=NULL)
        {
            delete []str;
        }
        len = string.len;
        str = new char[len];
        strcpy(str, string.str);
        return *this;
    }
    
    String& operator+= (const String& string1)
    {
        len+=string1.len-1;
        char *tmpstr = new char[len];
        strcpy(tmpstr, str);
        strcat(tmpstr, string1.str);
        
        if(str!=NULL)
        {
            delete []str;
        }
        str = tmpstr;
        return *this;
    }
    
    bool operator==(const String& string1)
    {
        return strcmp(str, string1.str)?false:true;
    }
    
    String operator+ (const String& string1)
    {
        len = len + strlen(string1.str) - 1;
        char *tempstr = new char[len];
        strcpy(tempstr, str);
        strcat(tempstr, string1.str);
        String temp(tempstr);
        delete []tempstr;
        return temp;
    }
    
    friend ostream& operator<<(ostream& os, const String& string1);
    friend istream& operator>>(istream& os, String& string1);
};

ostream& operator<<(ostream& os, const String& string1)
{
    os<<string1.str;
    return os;
}
istream& operator>>(istream& is, String& string1)
{
    char str[100];
    is>>str;
    string1=String(str);
    return is;
}

int main()
{
    String str1="I like ";
    String str2="string class";
    String str3=str1+str2;
    
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    
    str1+=str2;
    if(str1==str2)
    {
        cout<<"동일 문자열"<<endl;
    }
    else
    {
        cout<<"동일하지 않은 문자열"<<endl;
    }
    
    String str4;
    cout<<"문자열 입력: ";
    cin>>str4;
    cout<<"입력한 문자열: "<<str4<<endl;
    return 0;
}
