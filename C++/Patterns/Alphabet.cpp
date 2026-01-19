#include <iostream>
using namespace std;

// int n=5;

// A A A A A
// B B B B B
// C C C C C
// D D D D D
// E E E E E
void printAlphabet1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char(65 + i) << " ";
        }
        cout << endl;
    }
}

// A B C D E
// A B C D E
// A B C D E
// A B C D E
// A B C D E
void printAlphabet2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char(65 + j) << " ";
        }
        cout << endl;
    }
}

// A B C D E
// F G H I J
// K L M N O
// P Q R S T
// U V W X Y
void printAlphabet3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char((i * n) + j + 65) << " ";
        }
        cout << endl;
    }
}

// A B C D E
// B C D E F
// C D E F G
// D E F G H
// E F G H I
void printAlphabet4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char(i + j + 65) << " ";
        }
        cout << endl;
    }
}

// A
// B B
// C C C
// D D D D
// E E E E E
void printAlphabet5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(i + 65) << " ";
        }
        cout << endl;
    }
}

// A
// B C
// D E F
// G H I J
// K L M N O
void printAlphabet6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char((i * (i + 1)) / 2 + j + 65) << " ";
        }
        cout << endl;
    }
}

// A
// B C
// C D E
// D E F G
// E F G H I
void printAlphabet7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(i + j + 65) << " ";
        }
        cout << endl;
    }
}

// E
// D D
// C C C
// B B B B
// A A A A A
void printAlphabet8(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = n - i + 1; j > 0; j--)
        {
            cout << char(65 + i - 1) << " ";
        }
        cout << endl;
    }
}

// E
// D E
// C D E
// B C D E
// A B C D E
void printAlphabet8(int n)
{
    // Approach 1:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(65 + n - 1 - i + j) << " ";
        }
        cout << endl;
    }

    // Approach 1:
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            cout << char(65 + j) << " ";
        }
        cout << endl;
    }
}