#include <iostream>

using namespace std;

unsigned float_abs(unsigned uf) {
    int clear;
    int mask = 1;
    mask = mask << 31;
    clear = ~mask;
    mask = mask & uf;
    mask = mask >> 31;
    mask = ~mask;
    mask = mask << 31;
    uf = clear & uf;
    uf = uf | mask;
    return uf;
}

int main()
{
    cout << float_abs(0) << endl;
}