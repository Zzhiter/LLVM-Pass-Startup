#include <stdio.h>

#define MAX 100

void print(int num)
{
    printf("hello, %d\n", num);
}

int cal() {
    return 10;
}

int main()
{
    int i;

    if (i < cal()) {
        print(111);
    }

    i > 5 ? print(5) : print(-5);

    return 0;
}