#include <iostream>

using namespace std;

	
int isAsciiDigit(int x)
{
	int lowerBound = 0x30;
    int upperBound = 0x39;
    int mask = 0x1;
    upperBound = ((~x) + 1) + upperBound;
    lowerBound = x + ((~lowerBound) + 1);
    upperBound = upperBound >> 31;
    lowerBound = lowerBound >> 31;
    upperBound = upperBound & mask;
    lowerBound = lowerBound & mask;
    cout << "lowerBound" << lowerBound  << endl;
    cout << "upperBound" << upperBound << endl;
    return((!lowerBound) & (!upperBound));
}

int main()
{
	cout << isAsciiDigit(0x31) << endl;
}