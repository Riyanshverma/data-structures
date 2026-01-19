#include <iostream>
using namespace std;

// int n=5;

// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5
void printNumberSquare1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
void printNumberSquare2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

// 5 5 5 5 5
// 4 4 4 4 4
// 3 3 3 3 3
// 2 2 2 2 2
// 1 1 1 1 1
void printNumberSquare3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << n - i << " ";
        }
        cout << endl;
    }
}

// 5 4 3 2 1
// 5 4 3 2 1
// 5 4 3 2 1
// 5 4 3 2 1
// 5 4 3 2 1
void printNumberSquare4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << n - j << " ";
        }
        cout << endl;
    }
}

// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printNumberSquare5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (i * n) + j + 1 << " ";
        }
        cout << endl;
    }
}

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5
void printNumberTriangle6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
void printNumberTriangle7(int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (++temp) << " "; // cout << (i * (i + 1) / 2 + j + 1) << " ";
        }
        cout << endl;
    }
}

// 1
// 2 3
// 3 4 5
// 4 5 6 7
// 5 6 7 8 9
void printNumberTriangle8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + j + 1 << " ";
        }
        cout << endl;
    }
}

// 1
// 2 1
// 3 2 1
// 4 3 2 1
// 5 4 3 2 1
void printNumberTriangle9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

// 1 1 1 1 1
//   2 2 2 2
//     3 3 3
//       4 4
//         5
void printNumberTriangle10(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                cout << "  ";
            }
            else
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

//         1
//       2 2
//     3 3 3
//   4 4 4 4
// 5 5 5 5 5
void printNumberTriangle11(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < (n - i - 1))
            {
                cout << "  ";
            }
            else
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

// 1 2 3 4 5
//   2 3 4 5
//     3 4 5
//       4 5
//         5
void printNumberTriangle12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                cout << "  ";
            }
            else
            {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}

//       1
//     2 3
//   4 5 6
// 7 8 9 10
void printNumberTriangle13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < (n - i - 1))
            {
                cout << "  ";
            }
            else
            {
                cout << (i * (i + 1) / 2 + j + 1 - (n - i - 1)) << " ";
            }
        }
        cout << endl;
    }
}

//         1
//       1 2
//     1 2 3
//   1 2 3 4
// 1 2 3 4 5
void printNumberTriangle14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
            {
                cout << "  ";
            }
            else
            {
                cout << i + j + 2 - n << " ";
            }
        }
        cout << endl;
    }
}

//         1
//       1 2 1
//     1 2 3 2 1
//   1 2 3 4 3 2 1
// 1 2 3 4 5 4 3 2 1
void printNumberTriangle15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
            {
                cout << "  ";
            }
            else
            {
                cout << i + j + 2 - n << " ";
            }
        }
        for (int k = i; k > 0; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}

// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
void printNumberTriangle16(int n)
{
    // Approach 1:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((j + i) < n)
            {
                cout << j + 1 << " ";
            }
        }

        cout << endl;
    }

    // Approach 2:
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4     4 3 2 1
// 1 2 3         3 2 1
// 1 2             2 1
// 1                 1
void printNumberTriangle17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((j + i) < n)
            {
                cout << j + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (k < i)
            {
                cout << "  ";
            }
            else
            {
                cout << n - k << " ";
            }
        }
        cout << endl;
    }
}

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
void printNumberTriangle17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1
void printNumberTriangle17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ((i + j) % 2 == 0) << " ";
        }
        cout << endl;
    }
}

// 5 5 5 5 5
// 4 4 4 4
// 3 3 3
// 2 2
// 1
void printNumberTriangle17(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// 1                 1
// 1 2             2 1
// 1 2 3         3 2 1
// 1 2 3 4     4 3 2 1
// 1 2 3 4 5 5 4 3 2 1
void printNumberTriangle17(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = i + 1, end = (2 * n) - (i + 1);
        for (int j = 0; j < 2 * n; j++)
        {
            if ((start < end) && (j == start))
            {
                cout << "  ";
                start++;
            }
            else
            {
                if (i >= j)
                {
                    cout << j + 1 << " ";
                    continue;
                }
                else if (start == end)
                {
                    cout << 2 * n - j << " ";
                }
            }
        }
        cout << endl;
    }
}

//         1
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5
void printNumberTriangle17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (i + j + 1 > n - 1)
            {
                cout << abs(n - j - 1) + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

//     1 
//    2 2 
//   3 3 3 
//  4 4 4 4 
// 5 5 5 5 5
void printNumberTriangle17(int n)
{
    for(int i=0;i<n;i++) {
        for(int j=0;j<n+i;j++) {
            if(i+j+1>n-1) {
                if((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
                    cout<<i+1<<" ";
                }
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}