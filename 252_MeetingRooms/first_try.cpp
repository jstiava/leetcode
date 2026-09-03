// Example program
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int START = 0;
int END = 1;

bool isScheduleWithoutConflict(vector<vector<int>>& intervals) {
    
    sort(intervals.begin(), intervals.end());
    
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> curr_meeting = intervals[i];
        vector<int> last_meeting = intervals[i-1];
        if (last_meeting[END] > curr_meeting[START]) {
            return false;
        }
    }
    
    return true;
}
    
int main()
{   
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    bool result = isScheduleWithoutConflict(intervals);
    cout << result << endl;
}