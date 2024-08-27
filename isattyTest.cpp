#include <stdio.h>
#include <io.h>
int main()
{
    FILE* fp = fopen("test.txt", "r");
    printf("%d", isatty(fp));
}
