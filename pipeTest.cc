#include <ratatouille/pipe.h>
#include <iostream>
using namespace std;

int main() {
    cout << "---- PIPE TEST  ----" << endl;
    Ratatouille::Pipe::Piper<string> *piper = new Ratatouille::Pipe::Piper<string>("hi");
    cout << piper->pipe([](string str){
        return str.append(" there");
    })->pipe([](string str){
        return str.append("\n");
    })->callMemberFn(&string::shrink_to_fit)->ret();
    return 0;
}