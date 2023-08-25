#include <stdio.h>


struct thing {
    int this;
};

int main()
{
    struct thing ok;
    ok.this = 10;
    printf("%d", ok.this);
    return 0;
}