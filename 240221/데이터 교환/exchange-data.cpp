#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 6;
    int c = 7;

    int a_ = a;
    int b_ = b;
    int c_ = c;

    b = a_;
    c = b_;
    a = c_;

    cout << a << '\n' << b << '\n' << c;
}