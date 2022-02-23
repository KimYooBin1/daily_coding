#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
    char name[100];
public:
    Employee(const char * name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const{
        cout<<"name: "<<name<<endl;
    }
    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const
    {
        
    }
};

class PermanentWorker : public Employee
{
private:
    int salary;
public:
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char * name, int pay)
        :Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)
    {
        workTime+=time;
    }
    int GetPay() const
    {
        return workTime*payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(const char * name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult+=value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(Employee* emp)
    {
        empList[empNum++]=emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i=0; i<empNum; i++)
        {
            empList[i]->ShowSalaryInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int sum=0;
        for(int i=0; i<empNum; i++)
            sum+=empList[i]->GetPay();
        
        cout<<"salary sum: "<<sum<<endl;
    }
    ~EmployeeHandler()
    {
        for(int i=0; i<empNum; i++)
        delete empList[i];
    }
};

namespace RISK_LEVEL
{
    enum
    {
        RISK_A=30, RISK_B=20, RISK_C=10
    };
}

class ForeignSalesWorker : public SalesWorker
{
private:
    const int risklevel;
public:
    ForeignSalesWorker(const char * name, int money, double ratio, int risk) : SalesWorker(name, money, ratio), risklevel(risk)
    {

    }
    int GetRiskPay() const
    {
        return (int)(SalesWorker::GetPay() * (risklevel / 100.0));
    }
    int GetPay() const
    {
        return SalesWorker::GetPay() + GetRiskPay();
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<SalesWorker::GetPay()<<endl;
        cout<<"risk pay: "<<GetRiskPay()<<endl;
        cout<<"sum: "<<GetPay()<<endl;
    }
};


int main()
{
    /*
    EmployeeHandler handler;
    
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    
    TemporaryWorker * alba=new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);
    
    SalesWorker * seller=new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);
    
    handler.ShowAllSalaryInfo();
    
    handler.ShowTotalSalary();
    return 0;
    */

    EmployeeHandler handler;
    
    ForeignSalesWorker * fseller1=new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);
    
    ForeignSalesWorker * fseller2=new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);
    
    ForeignSalesWorker * fseller3=new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);
    
    handler.ShowAllSalaryInfo();
    return 0;
}
