#include <ratatouille/pipe.h>
#include <string>
#include <thread>
#include <iostream>
#include <functional>
using namespace std;
using namespace Ratatouille::Pipe;

int main() {
    cout << "---- Threading & Pipes Test ----"
    thread thrd([]() {
        new Piper<function<string()>>([]() {
            thread::sleep(5000);
            return "Hello from other thread!";
        }).pipe([](func) {
            cout << func();
        }).ret();
    });
    thread::sleep(2500);
    cout << "Hello from main thread";
    thrd.join();
}