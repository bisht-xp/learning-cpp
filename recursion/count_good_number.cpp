#include <iostream>
#include <climits>

using namespace std;

int const mod = 1e9 + 7;

// long fastPower(int n, int digit)
// {
//     if (n <= 0) {
//         return 1;
//     }
//     long long num = fastPower(n / 2, digit);
//     long long powerSq = (num * num) % mod;
//     if (n & 1)
//     {
//         powerSq = (digit * powerSq) % mod;
//     }
//     return powerSq;
// }

// int countGoodNumbers(long long n)
// {
//     if(n == 1) {
//         return 5;
//     }
//     long long oddPower = n / 2;
//     long long evenPower = n - oddPower;
//     long long evenPosibility = fastPower(evenPower, 5)%mod;
//     long long oddPosibility = fastPower(oddPower, 4)%mod;

//     return ((evenPosibility) * (oddPosibility)) % mod;
// }

//Recursive function have some issues doesn't provide correct answer.
int const mod = 1e9 + 7;

long long fastPower(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int countGoodNumbers(long long n)
{
     if(n == 1) {
        return 5;
    }
    long long oddPower = n / 2;
    long long evenPower = n - oddPower;
    long long evenPosibility = fastPower(5, evenPower);
    long long oddPosibility = fastPower(4, oddPower);

    return ((evenPosibility) * (oddPosibility)) % mod;
}

int main() {
    cout << countGoodNumbers(806166225460393) << endl;
    // cout << countGoodNumbers(50) << endl;
    return 0;
}