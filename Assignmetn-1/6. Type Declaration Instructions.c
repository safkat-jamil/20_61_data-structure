#include <stdio.h>

int main()
{
    int age = 26;
    int oldAge = age;
    int newAge = oldAge + 1;
    printf("New age is: %d\n", newAge);

    int BDT = 1, USD = 108;

    /*
    order of declaration is important - Wrong Declaration Order
    float pi = 3.1416;
    float area = pi * rad * rad;
    float rad = 3;
    */

    //valid declaration
    int age1, age2, age3;
    age1 = age2 = age3 = 26;

    /*invalid
    int a1 = a2 = a3 = 26;
    */

    return 0;
}
