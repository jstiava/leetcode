// Example program
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int START = 0;
int END = 1;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    // Insertion sort by start time ascending
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> curr = intervals[i];
        int j = i - 1;
        // Go to the start of the array
        while (j >= 0) {
            if (intervals[j][START] > curr[START]) {
                break;
            }
            // Move the greater value up and move down the array
            intervals[j+1] = intervals[j];
            j--;
        }
        intervals[j + 1] = curr;
    }
    
    vector<vector<int>> result = {intervals[0]}; 

    int i = 1;
    vector<int> last_meeting = intervals[0];

    while (i < intervals.size()) { 
        vector<int> curr_meeting = intervals[i]; 

        // Is overlapping
        if (last_meeting[END] >= curr_meeting[START]) {
            result.pop_back();
            vector<int> new_meeting = {last_meeting[START], curr_meeting[END]};
            result.push_back(new_meeting);
            last_meeting = new_meeting;
        }
        else {
            result.push_back(curr_meeting); 
            last_meeting = curr_meeting;
        }
        i++;
    }
    
    
    return result;
}
    
int main()
{   
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = merge(intervals);

    for (vector<int> interval : result) {
        cout << "[";

        for (int x : interval) {
            cout << x << " ";
        }

        cout << "] ";
    }

    cout << endl;
}