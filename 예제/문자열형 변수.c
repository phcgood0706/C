#include <stdio.h>
main ()
{
    char a[6] = {'K','O','R','E','A','\0'};
    printf ("%c\n", a[1]);
    printf ("%s\n", a);
    char b[6] = {'K','O','R','E','A','\0'};
    printf ("%s\n",b);
    char c[6] = "KOREA";
    printf ("%s\n",c);
}