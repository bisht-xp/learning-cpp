#include <iostream>
#include <string.h>
#include <algorithm>
#include <limits.h>

using namespace std;

string LongestWord(string sen)
{

    // code goes here
    int i = 0;
    int maxSize = -1;
    int stIndex = 0;
    int endIndex = 0;
    if(sen.size() < 1) {
        return "";
    }
    cout << sen.size() << endl;
    while (i < sen.length())
    {
        int longestString = 0;
        stIndex = i;
        while (sen[i] != ' ' && (sen[i] >= 'A' && sen[i] <= 'Z') ||
               (sen[i] >= 'a' && sen[i] <= 'z') )
        {
            longestString++;
            i++;
        }
        if (longestString> maxSize) {
            maxSize = longestString;
            endIndex = i;
        }
        i++;
    }
    return sen.substr(endIndex-maxSize, maxSize);
}

int main(void)
{

    // keep this function call here
    string sen = "fun&!! time";
    // string sen = "I love dogs";
    cout << LongestWord(sen);
    return 0;
}