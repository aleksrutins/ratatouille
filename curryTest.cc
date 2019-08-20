#include "curry.h"
#include <stdio.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}
void printFmt1Arg(const char *fmt, const void *arg) {
    printf(fmt, arg);
}
int main() {
    auto add5 = Ratatouille::Curry::curry(&add, 5);
    auto sayHello = Ratatouille::Curry::curry(&printFmt1Arg, "Hello, %s!\n");
    printf("Result: %d\n", add5(5));
    sayHello("world");
    return 0;
}