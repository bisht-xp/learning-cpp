#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
    int value;
    int listIndex;
    int elementIndex;
};

struct Compare
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.value > b.value;
    }
};

vector<int> kSmallestRange(vector<vector<int>> nums)
{
    priority_queue<Node, vector<Node>, Compare> pq;
    vector<int> ans;
    int currentMax = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i][0], i, 0});
        currentMax = max(nums[i][0], currentMax);
    }

    int rangeStart = INT_MAX;
    int rangeEnd = INT_MIN;
    int currentRange = INT_MAX;

    while (true)
    {
        Node current = pq.top();
        pq.pop();

        int currentMin = current.value;

        if (currentMax-currentMin < currentRange);
        {
            rangeStart = current.value;
            rangeEnd = currentMax;
            currentRange = currentMax-currentMin;
        }

        int nextIndex = current.elementIndex + 1;

        if (nextIndex >= nums[current.listIndex].size())
        {
            break;
        }

        currentMax = max(nums[current.listIndex][nextIndex], currentMax);
        pq.push({nums[current.listIndex][nextIndex], current.listIndex, nextIndex});
    }

    return {rangeStart, rangeEnd};
}

int main()
{
    std::vector<std::vector<int>> lists = {{1,2,3},{1,2,3},{1,2,3}};

    vector<int> ans = kSmallestRange(lists);
    cout << ans[0] << " " << ans[1] << endl;    
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<queue>
// #include<climits>

// using namespace std;

// struct Node
// {
//     int value;
//     int listIndex;
//     int elementIndex;
// };

// struct Compare
// {
//     bool operator()(const Node& a, const Node& b) {
//         return a.value > b.value;
//     }
// };

// vector<int> kSmallestRange(vector<vector<int>> nums) {
//     priority_queue<Node, vector<Node>, Compare> pq;
//     vector<int> ans;
//     int currentMax = INT_MIN;
//     for(int i=0; i<nums.size(); i++) {
//         pq.push({nums[i][0], i, 0});
//         currentMax = max(nums[i][0], currentMax);
//     }

//     int rangeStart = INT_MAX;
//     int rangeEnd = INT_MIN;

//     while(true) {
//         Node current = pq.top();
//         pq.pop();

//         int currentRange = currentMax - rangeStart;

//         if(currentRange < rangeEnd - rangeStart || (currentRange == rangeEnd - rangeStart && current.value < rangeStart)) {
//             rangeStart = current.value;
//             rangeEnd = currentMax;
//         }

//         int nextIndex = current.elementIndex + 1;

//         if(nextIndex >= nums[current.listIndex].size()) {
//             break;
//         }

//         currentMax = max(nums[current.listIndex][nextIndex], currentMax);
//         pq.push({nums[current.listIndex][nextIndex], current.listIndex, nextIndex});
//     }

//     ans.push_back(rangeStart);
//     ans.push_back(rangeEnd);

//     return ans;
// }

// int main() {
//     std::vector<std::vector<int>> lists = {
//         {4, 10, 15, 24},
//         {0, 9, 12, 20},
//         {5, 18, 22, 30}
//     };

//     vector<int> ans = kSmallestRange(lists);
//     cout << ans[0] << " " << ans[1] << endl;
//     return 0;
// }

// struct node
// {
//     int data, row, column;
//     node(int value, int i, int j) : data(value), row(i), column(j) {}
// };
// struct comparator
// {
//     bool operator()(node a, node b)
//     {
//         return a.data > b.data;
//     }
// };
// vector<int> smallestRange(vector<vector<int>> &nums)
// {
//     int k = nums.size();
//     // this approach will use a min heap of size k
//     priority_queue<node, vector<node>, comparator> minHeap;
//     int currMin = INT_MAX, currMax = INT_MIN, currRange = INT_MAX;
//     // run a loop for k times and build the min heap
//     for (int i = 0; i < k; ++i)
//     {
//         currMax = max(currMax, nums[i][0]);
//         node temp(nums[i][0], i, 0);
//         minHeap.push(temp);
//     }
//     // the start and end range of our answer
//     int start = currMin, end = currMax;
//     while (true)
//     {
//         node min = minHeap.top();
//         minHeap.pop();
//         currMin = min.data;
//         // if we got a smaller range
//         if (currMax - currMin < currRange)
//         {
//             start = currMin;
//             end = currMax;
//             currRange = currMax - currMin;
//         }

//         // if we don't have any more elements in the row of the min element, we're done
//         if (min.column + 1 == nums[min.row].size())
//             break;

//         // if we still have at least one element, push it inside the min heap
//         node next(nums[min.row][min.column + 1], min.row, min.column + 1);
//         minHeap.push(next);

//         // update the currMin and currMax
//         if (next.data < currMin)
//             currMin = next.data;
//         if (next.data > currMax)
//             currMax = next.data;
//     }
//     return {start, end};
// }