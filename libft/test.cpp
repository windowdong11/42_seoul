#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {0,}; // 0xf0
    for(int i = 0; i < 10; ++i)
        arr[i] = i; // 0 1 2 ,,, 9
    int *ptr = arr;
    cout << (*ptr++) << ' ';
    /*
    ptr = 0xf0
    ptr++ <-
    ptr = 0xf0
    *ptr -> 0 <- arr[0]
    ptr = 0xf1
    */ 
    cout << (*ptr++) << ' '; // arr[1] // -> &arr[2]
    cout << (*ptr++) << ' ';    
    cout << "\n\n";
    for(int i = 0; i < 10; ++i)
        cout << arr[i] << ' ';
    return (0);
}