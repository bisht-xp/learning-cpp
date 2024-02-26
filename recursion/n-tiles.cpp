#include<iostream>

using namespace std;

int tillingProblem(int n, int m){
    if(n<m) {
        return 1;
    }   
    int opt = tillingProblem(n-1,m);
    int opt1 = tillingProblem(n-m,m);
    return (opt+opt1);
}

int main() {
    int n,m;
    cin >> n>>m;
    cout << tillingProblem(n,m) << endl;
    return 0;   
}