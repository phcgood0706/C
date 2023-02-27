#include <stdio.h>
main ()
{
    printf("\n");
    printf("Hello, World~1\n");
    printf("Hello, World~%d",2);

    //함수의 서식 변경
    printf("\n");

    int a = 365;
    float b = 3.14;
    printf("%5d \t",a);
    printf("%3.1f \n",b);

    printf("\n");

    printf("\"Hello, World~5\'");

    //함수의 활용
    printf("\n");
    int good =1;
    printf("    1번만 출력하라\n");
    printf("%9d번만 출력하라",good); printf("\n");
    printf("\v\t%.0f번만 출력하라\n",1.23);
}