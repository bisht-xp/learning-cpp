#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const char arr[100] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int helper(string s, int i, int sign, long long result)
{
    if (i >= s.length() || !isdigit(s[i]))
    {
        return result * sign;
    }

    result = result * 10 + (s[i] - '0');

    if (result * sign < INT_MIN)
    {
        return INT_MIN;
    }
    else if (result * sign > INT_MAX)
    {
        return INT_MAX;
    }

    return helper(s, i + 1, sign, result);
}

int createAtoi(string s)
{
    // cout << '45' - '0' << endl;
    int i = 0;
    int sign = 1;
    long long result = 0;
    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (i < s.length() && (s[i] == '-' || s[i] == '+'))
    {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    int val = helper(s, i, sign, result);
    return val;
}

int main()
{
    cout << createAtoi("45rohit34") << endl;
    return 0;
}