#include <iostream>

using namespace std;

unsigned float_half(unsigned uf) {
    int E, M, bias;
    uf = uf >> 1;
    int V = 1;
    int sign = 0x80000000 & uf;
    int exp = ((0x7f800000)& uf)>>23;
    int frac = (0x7fffff & uf);
    if(frac < 0x400000)
    {
        frac = 0x0;
    }
    else
    {
        frac = 0x1000000;
    }
    bias = 127;
    if(exp == 0xff)
    {
        return 0x80000000u;
    }
    else if(exp == 0)
    {
        cout << "denorm " << endl;
        E = 1 - bias;
        cout << "E" << E << endl;
        M = frac;
        cout << "M " << M << endl;

    }
    else
    {
        cout << "norm " << endl;
        E = (exp - bias);
        cout << "E" << E << endl;
        M = (frac + 0x1000000);
        cout << "M" << M << endl;
    }
    if(E < 0)
    {
        return sign;
    }
    V = (V << (E))*(M);
    if(sign == 0x80000000)
    {
        V = ~V + 1;
    }
    return V;
}


int main()
{
    cout << float_half(0x800000) << endl; 
}