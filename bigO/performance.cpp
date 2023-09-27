#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

void findingNemo(vector<string> arr)
{
    // cout << arr[0] << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == "Nemo")
        {
            cout<<"found Nemo \n";
        }
    }
}

int main()
{
    auto t0 = high_resolution_clock::now();
    // string fish[2] = {"Nemo"};
    vector<string> vec(10000, "Nemo");
    // int fishSize = sizeof(fish)/sizeof(fish[0]);
    findingNemo(vec);
    auto t1 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t1 - t0);
    duration<double, std::milli> ms_double = t1 - t0;
    // cout << "time in millescondis: " << ms_int.count() << endl; 
    cout << "time in millescondis: " << ms_double.count() << endl; 
    return 0;
}
