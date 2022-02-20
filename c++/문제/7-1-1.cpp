#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int gasolineGauge)
    {
        this->gasolineGauge=gasolineGauge; 
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int gasolineGauge, int electricGauge) : Car(gasolineGauge)
    {
        this->electricGauge=electricGauge;
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int gasolineGauge=0, int electricGauge=0, int waterGauge=0) : HybridCar(gasolineGauge, electricGauge)
    {
        this->waterGauge=waterGauge;
    }
    void ShowcurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};
int main()
{
    HybridWaterCar HWC(1,2,3);
    HWC.ShowcurrentGauge();
    return 0;
}
