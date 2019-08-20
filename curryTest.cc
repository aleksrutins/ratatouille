#include <ratatouille/curry.h>
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}
void printFmt1Arg(const char *fmt, const void *arg) {
    printf(fmt, arg);
}
int main() {
    cout << "---- CURRY TEST ----";
    auto add5 = Ratatouille::Curry::curry(&add, 5);
    auto sayHello = Ratatouille::Curry::curry(&printFmt1Arg, "Hello, %s!\n");
    cout << "Result: " << add5(5) << "\n";
    sayHello("world");
    return 0;
}