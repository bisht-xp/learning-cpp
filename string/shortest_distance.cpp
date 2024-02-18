#include <iostream>

using namespace std;

void shortest_path(string s)
{
    int x = 0, y = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'S')
        {
            y--;
        }
        else if (s[i] == 'N')
        {
            y++;
        }
        else if (s[i] == 'E')
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    if (x >= 0 and y >= 0)
    {
        while (y--)
        {
            cout << 'N';
        }
        while (x--)
        {
            cout << 'E';
        }
    }
    else if (x <= 0 and y >= 0)
    {
        while (y--)
        {
            cout << 'N';
        }
        while (x++)
        {
            cout << 'W';
        }
    }
    else if (x >= 0 and y <= 0)
    {
        while (y++)
        {
            cout << 'S';
        }
        while (x--)
        {
            cout << 'E';
        }
    }
    else if (x <= 0 and y <= 0)
    {
        while (y++)
        {
            cout << 'S';
        }
        while (x++)
        {
            cout << 'W';
        }
    }
    // return s;
}

int main()
{
    string ch;
    cin >> ch;
    shortest_path(ch);
    return 0;
}