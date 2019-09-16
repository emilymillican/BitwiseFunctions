#include <iostream>

using namespace std;

int conditional(int x, int y, int z) {
    x = !!x;
    cout << "x " << x << endl;
    int nx = x << 1;
    x = x | nx;
    cout << x << endl;
    nx = x << 2;
    x = x | nx;
    nx = x << 4;
    x = x | nx;
    nx = x << 8;
    x = x | nx;
    cout << x << endl;
    nx = x << 16;
    x = x | nx;
    cout << "x" << x << endl;
    int mask1 = x & y;
    cout << "mask1 " << mask1 << endl;
    int mask2 = (~x) & z;
    cout << "mask2 "<< mask2 << endl;
    return(mask1 | mask2);
}

int main()
{
	cout << conditional(0, 0x80000000, 0x80000000) << endl;
}
