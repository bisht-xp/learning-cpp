#include<iostream>

using namespace std;

int gridWays(int i, int j, int m, int n) {
    if(i == m-1 && j == n-1) {
        return 1;
    }
    if(i>=m || j>=n) {
        return 0;
    }

    int ways = 0;
    ways += gridWays(i+1, j, m,n) + gridWays(i,j+1,m,n);
    return ways;

}

int main() {

    cout << "number of ways grid solved is: " << gridWays(0,0,3,3) << endl;
    return 0;
}