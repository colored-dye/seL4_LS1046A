/*
Test type-aliased array type pointer dereference behavior.

Output:
0x3A2ABAC0, 0x3A2ABAC0
233
*/

typedef int array[10];
typedef struct array_cont {
        array arr;
} array_cont;

#include <stdio.h>

void f(array_cont *a) {
        printf("%d\n", a->arr[0]);
}

int main() {
        array_cont a1;
        a1.arr[0] = 233;

        printf("0x%08X, 0x%08X\n", &a1, a1.arr);

        array_cont *r2 = &a1;

        f(r2);

        return 0;
}
