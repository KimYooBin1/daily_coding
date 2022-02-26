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
    /*
    String operator+ (String &string1, String &string2)
    {
        String string(string1+string2);
        return string;
    }
    */
    String& operator+= (const String& string1)
    {
        len+=string1.len-1;
        
        return *this;
    }
    /*String operator==()
    {
        
    }
    String operator<<()
    {
        
    }
    String operator>>()
    {
        
    }*/
    ~String()
    {
        if(str!=NULL)
        {
            delete []str;
        }
    }
};
int main()
{
    String str1("Hello world");
    return 0;
}
