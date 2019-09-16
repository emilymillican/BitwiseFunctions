#include <iostream>

using namespace std;

int float_f2i(unsigned uf) {
    int E, M, mask;
    int V = 1;
    int two = 1;
    int sign = 0x80000000 & uf;
    cout << sign << endl;
    int exp = ((0x7f800000)& uf)>>23;
    int frac = (0x7fffff & uf) >>23;
    int bias = 127;
    if(exp == 0xff)
    {
        return 0x80000000u;
    }
    else if(exp == 0)
    {
        cout << "denorm" << endl;
        E = 1 - bias;
        M = frac;
    }
    else
    {
        cout << "norm" << endl;
        E = (exp - bias);
        cout << "exp " << exp << endl;
        cout << "E" << E << endl;
        M = (frac + 1);
        cout << "frac " << frac << endl;
        cout << "M " << M << endl;
    }
    for(int i = 0; i < E && two > 0; i++)
    {
        two = two * 2;
    }
    for(int i = E; i < 0; i++)
    {
        two = two/2;
    }
    cout << "two " <<  (two) << endl;
    V = two * (M);
    if(sign == 0x80000000)
    {
        V = ~V + 1;
    }
    cout << V << endl;
    mask = 0x1;
    mask = mask & V;
    if(mask == 1)
    {
        V = V & (~mask);
    }
    return V;
}

int main()
{
    cout << float_f2i(0x7effffff) << endl;
}