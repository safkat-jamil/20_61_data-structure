#include<stdio.h>

int main()
{
int age;

    printf("Enter age : ");

    scanf("%d", &age);

    age >= 18 ? printf("Adult \n") : printf("Not adult \n");

    int number = 19;

    int luckyNumber = 19;

    printf("Enter number : ");

    scanf("%d", &luckyNumber);

    number == luckyNumber ? printf("You are lucky \n") : printf("you are not lucky \n");

return 0;
}
