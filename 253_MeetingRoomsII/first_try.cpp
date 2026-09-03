// Example program
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int START = 0;
int END = 1;

int minMeetingRooms(vector<vector<int>>& intervals) {
    
    if (intervals.empty()) {
        return 0;
    }
    
    sort(intervals.begin(), intervals.end());
    
    priority_queue<int, vector<int>, greater<int>> endTimesMinHeap;
    endTimesMinHeap.push(intervals[0][END]);
    
    int result = 1; 
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> curr_meeting     = intervals[i];
        
        // Is most avaliable room overlapping
        if (endTimesMinHeap.top() > curr_meeting[START]) {
            result++;
            endTimesMinHeap.push(curr_meeting[END]);
        }
        else {
            endTimesMinHeap.pop();
            endTimesMinHeap.push(curr_meeting[END]);
        }
    }
    
    return result;
}
    
int main()
{   
    vector<vector<int>> intervals = {{0, 40}, {5, 10}, {15, 20}};
    int result = minMeetingRooms(intervals);
    cout << result << endl;
}