#include <stdio.h>

typedef union
{
    int i;
    float f;
} U;

int main(void)
{
    U u;

    u.f = 10.0;

    printf("%g = %#x\n", u.f, u.i);

    return 0;
}

