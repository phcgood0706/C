#include <stdio.h>
main ()
{
    printf("\n");
    printf("Hello, World~1\n");
    printf("Hello, World~%d",2);

    //�Լ��� ���� ����
    printf("\n");

    int a = 365;
    float b = 3.14;
    printf("%5d \t",a);
    printf("%3.1f \n",b);

    printf("\n");

    printf("\"Hello, World~5\'");

    //�Լ��� Ȱ��
    printf("\n");
    int good =1;
    printf("    1���� ����϶�\n");
    printf("%9d���� ����϶�",good); printf("\n");
    printf("\v\t%.0f���� ����϶�\n",1.23);
}