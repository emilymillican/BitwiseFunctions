#include <iostream>
 
using namespace std;

int byteSwap(int x, int n, int m) {
    int y= 0xff;
    int mask1 = (y << (n << 3));
    int mask2 = (y << (m << 3));
    cout << "Mask1:" << mask1 << " Mask2:" << mask2 << endl;
    int clear = ~(mask1 | mask2);
    cout << "clear " << clear << endl;
    mask1 = mask1 & x;
    cout << "mask1 " << mask1 << endl;
    mask1 = mask1 >> (n << 3); 
    mask2 = mask2 & x;
    cout << "mask2 " << mask2 << endl;

    mask2 = mask2 >> (m << 3);
    cout << "shifted mask1 " << mask1 << endl;
    cout << "shifted mask2 " << mask2 << endl;
    mask1 = mask1 & y;
    mask2 = mask2 & y;
    cout << "mask1&y " << mask1 << endl;
    cout << "mask2&y " << mask2 << endl;
    x = x & clear;
    cout << "x" << x << endl;
    mask1 = (mask1 << (m << 3));
    mask2 = (mask2 << (n << 3));
    cout << "shifted mask1 " << mask1 << endl;
    cout << "shifted mask2 " << mask2 << endl;
    int swap = mask1 | mask2;
    cout << "swap " << swap << endl;
    swap = swap | x;
    return swap;
}

int main()
{
    cout << byteSwap(0x80000000, 0, 3) << endl;
}