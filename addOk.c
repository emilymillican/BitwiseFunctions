#include <iostream>

using namespace std;


int addOk(int x, int y)
{
	int s = x + y;
	cout << "x " << x << endl;
	cout << "y " << y << endl;
	cout << "s " << s << endl;
    int mask = 1;
    x = x >> 31;
    y = y >> 31;
    cout << "x1 " << x << endl;
    cout << "y1 " << y << endl;
    x = x & mask;
    y = y & mask;
    cout << "xm " << x << endl;
    cout << "ym " << y << endl;
    s = s >> 31;
    cout << "s1 " << s << endl;
    s = s & mask;
    cout << "sm " << s << endl;
    int same = !(x ^ y);
    cout << same << endl;
    return (!(same & (x ^ s)));

}

int main()
{
	cout << addOk(0x80000000, 0x7fffffff) << endl;
}