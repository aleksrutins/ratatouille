#include <ratatouille/pipe.h>
#include <iostream>
using namespace std;

class PipeableClass {
    string val;
    public:
    PipeableClass() {
        val = "Hi";
    }
    void addWorld() {
        cout << "adding world";
        val += " world";
    }
    string get() {
        return val;
    }
};

int main() {
    cout << "---- PIPE TEST  ----" << endl;
    Ratatouille::Pipe::Piper<string> *piper = new Ratatouille::Pipe::Piper<string>("hi");
    cout << piper->pipe([](string str){
        return str.append(" there");
    })->pipe([](string str){
        return str.append("\n");
    })->ret();
    Ratatouille::Pipe::Piper<PipeableClass> *otherPiper = new Ratatouille::Pipe::Piper<PipeableClass>(PipeableClass());
    otherPiper->pipe([](PipeableClass p) {
        cout << "first";
        cout << p.get();
        return p;
    })->callMemberFn(&PipeableClass::addWorld)->pipe([](PipeableClass p) {
        cout << "second";
        cout << p.get();
        return p;
    })->ret();
    return 0;
}