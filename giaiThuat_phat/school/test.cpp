#include <iostream>
using namespace std;
void display(int a[])
{
    for (const auto &i : a)
         cout<< i<< " ";
}
int main()
{
    int arr[] = {1, 2, 3};
    display(arr);
    return 0;
 }