#include <iostream>

using namespace std;


int satAdd(int x, int y) {
    int overflow, same, ssign, overflowv, mask2;
    int min = 1;
    min = min << 31;
    int max = ~min;
    int s = x + y;
    int mask = 1;
    x = x >> 31;
    y = y >> 31;
    x = x & mask;
    y = y & mask;
    ssign = s >> 31;
    ssign = ssign & mask;
    same = !(x ^ y);
    overflow = (same & (x ^ ssign));
    mask = overflow << 1;
    overflow = overflow | mask;
    mask = overflow << 2;
    overflow = overflow | mask;
    mask = overflow << 4;
    overflow = overflow | mask;
    mask = overflow << 8;
    overflow = overflow | mask;
    mask = overflow << 16;
    overflow = overflow | mask;
    mask2 = ssign << 1;
    ssign = ssign | mask2;
    mask2 = ssign << 2;
    ssign = ssign | mask2;
    mask = overflow << 4;
    ssign = ssign | mask;
    mask2 = ssign << 8;
    ssign = ssign | mask2;
    mask2 = ssign << 16;
    ssign = ssign | mask2;
    overflowv = (overflow & ((ssign & max) | (~ssign & min))) | ((~overflow) & s);
    cout << "overflow " << overflow << endl;
    cout << "max or min  " << ((ssign & max)) << endl;
    return overflowv;
}

int main()
{
    cout << satAdd(0x80000000, 0x80000000 ) << endl;
}