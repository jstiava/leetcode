// Example program
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int START = 0;
int END = 1;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
    sort(intervals.begin(), intervals.end());
    
    int result = 0;
    vector<int> last_meeting = intervals[0];
    
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> curr_meeting = intervals[i]; 
        
        // Is overlapping
        if (last_meeting[END] > curr_meeting[START]) { 
            /**
             * Key step: keep the event with the earliest end time to maximize space for other events.
             */
            last_meeting = last_meeting[END] < curr_meeting[END] ? last_meeting : curr_meeting;
            result++;
        }
        else {
            last_meeting = curr_meeting;
        }
    }
    
    return result;
}
    
int main()
{   
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = eraseOverlapIntervals(intervals);
    cout << result << endl;
}