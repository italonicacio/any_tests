// C++ Program to Demonstrate the correct size
// of various data types on your computer.
#include <iostream>
using namespace std;
 
int main()
{
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
 
    cout << "Size of long : " << sizeof(long) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of long long int: " << sizeof(long long int) << endl;

    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of long double : " << sizeof(long double) << endl;

 
    return 0;
}