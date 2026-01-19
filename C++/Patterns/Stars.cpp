#include <iostream>
using namespace std;

// int n=5;

// * * * * *
// * * * * *
// * * * * *
// * * * * *
// * * * * *
void printSolidSquare(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// *
// * *
// * * *
// * * * *
// * * * * *
void printSolidTriangle1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

//         *
//       * *
//     * * *
//   * * * *
// * * * * *
void printSolidTriangle2(int n)
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
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// * * * * *
// * * * *
// * * *
// * *
// *
void printSolidTriangle3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// * * * * *
//   * * * *
//     * * *
//       * *
//         *
void printSolidTriangle4(int n)
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
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// *
// * *
// * * *
// * * * *
// * * * * *
// * * * *
// * * *
// * *
// *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

//         *
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *
void printSolidTriangle4(int n)
{
    // Approach 1:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j + 1 < n)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        for (int k = i; k > 0; k--)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Approach 2:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n + i); j++)
        {
            if (j + i + 1 < n)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// * * * * * * * * *
//   * * * * * * *
//     * * * * *
//       * * *
//         *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2 * n - i - 1); j++)
        {
            if (j < i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

//         *
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *
//   * * * * * * *
//     * * * * *
//       * * *
//         *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n + i); j++)
        {
            if (j + i + 1 < n)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (2 * n - i - 1); j++)
        {
            if (j < i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// * * * * *
//  * * * *
//   * * *
//    * *
//     *
//     *
//    * *
//   * * *
//  * * * *
// * * * * *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2 * n) - i - 1; j++)
        {
            if (j < i)
            {
                cout << " ";
            }
            else
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    cout << "*";
                }
                else if (i % 2 == 1 && j % 2 == 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (i + j + 1 < n)
            {
                cout << " ";
            }
            else
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    cout << "*";
                }
                else if (i % 2 == 1 && j % 2 == 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

// * * * * *
// *       *
// *       *
// *       *
// * * * * *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i + 1 == n || j + 1 == n)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

//         *
//       *   *
//     *       *
//   *           *
// * * * * * * * * *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (i == n - 1)
            {
                cout << "* ";
                continue;
            }
            else if ((i + j == n - 1) || (j - i == n - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// * * * * * * * * *
//   *           *
//     *       *
//       *   *
//         *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = (2 * n) - 1; j > 0; j--)
        {
            if (i == 0)
            {
                cout << "* ";
                continue;
            }
            else if ((j - i == (2 * n) - (2 * i) - 1) || j - i == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

//         *
//       *   *
//     *       *
//   *           *
// *               *
//   *           *
//     *       *
//       *   *
//         *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if ((i + j == n - 1) || (j - i == n - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 2 * n - 1; j > 0; j--)
        {
            if ((j - i == n - 1) || (i + j == n + 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *
// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
void printSolidTriangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = n - i, end = n + i;
        for (int j = 0; j < 2 * n; j++)
        {
            if ((start < end) && (j == start))
            {
                cout << "  ";
                start++;
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
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
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *
void printSolidTriangle4(int n)
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
                cout << "* ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        int start = n - i, end = n + i;
        for (int j = 0; j < 2 * n; j++)
        {
            if ((start < end) && (j == start))
            {
                cout << "  ";
                start++;
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}