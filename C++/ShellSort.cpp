#include <iostream>
using namespace std;
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i] < arr[i + gap])
                {
                    break;
                }
                else
                {
                    swap(arr[i], arr[i + gap]);
                }
            }
        }
    }
}
int main()
{
    int arr[] = {27, 10, 30, 2, 13, 23, 26, 9, 18};
    shellSort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
}