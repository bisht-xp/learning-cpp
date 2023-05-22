#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
    stack<string> name;
    
    name.push("Batman");
    name.push("Ironman");
    name.push("Shaktimaan");
    name.push("Groot");

    cout << "All favourite superHero ";

    while (!name.empty())
    {
        cout << ">> " << name.top() << endl;
        name.pop();
    }
    

    return 0;
}