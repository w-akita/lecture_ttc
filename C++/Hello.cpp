#include <iostream>
using namespace std;
// int main(void)
// {
//   cout << "Hello, World!\n";
//   return 0;
// }
int main(void){
    int a[] = {1, 2, 3, 4};
    int *b = a;
    cout << *b;
    cout << *b+1; // *(b+1)
    cout << *++b; // *(++b)
    return 0;
}