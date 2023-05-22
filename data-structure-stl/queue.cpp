#include<iostream>
#include<queue>

using namespace std;

int main() {

    queue<string> animal;
    
    animal.push("cat");
    animal.push("tiger");
    animal.push("elephant");
    animal.push("fox");

    cout << "last animal: " << animal.back() << endl;

    while(!animal.empty()) {
        cout << animal.front() << ",";
        animal.pop();
    }

    return 0;
}