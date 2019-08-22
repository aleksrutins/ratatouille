#include <ratatouille/pipe.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>
using namespace std;
using namespace Ratatouille::Pipe;

int main() {
    cout << "---- Threading & Pipes Test ----";
    thread thrd([]() {
        new Piper<function<string()>>([]() {
            this_thread::sleep_for(chrono::seconds(5));
            return "Hello from other thread!";
        })->pipe([](func) {
            cout << func();
        })->ret();
    });
    this_thread::sleep_for(chrono::milliseconds(2500));
    cout << "Hello from main thread";
    thrd.join();
}