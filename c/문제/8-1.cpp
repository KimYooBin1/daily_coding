#include <stdio.h>

int main(void)
{
    int A, Z, number1, number2;
    for(int A = 0; A<10; A++)
    {
        for(int Z = 0; Z<10; Z++)
        {
            number1 = A*10 + Z;
            number2 = Z*10 + A;
            if(number1 + number2 == 99)
            {
                printf("%d %d \n", A, Z);
            }
        }
    }
}
