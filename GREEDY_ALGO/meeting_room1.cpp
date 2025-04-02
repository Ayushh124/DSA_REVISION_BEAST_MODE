SIMILAR QUESTION:-
(MUST DO):-
1->   MEETING ROOM -1 && MEETING ROOM -2(VIP)
   TEST CASE -:
 startTime = [1, 2, 3, 4];
 endTime   = [5, 6, 7, 8];
We have four meetings:
Meeting 1: (1 to 5)
Meeting 2: (2 to 6)
Meeting 3: (3 to 7)
Meeting 4: (4 to 8)
Understanding the while Loop
Loop Condition
while (i < len && j < len)
Runs until either the i pointer (start times) or j pointer (end times) reaches the end of the arrays.
Step-by-Step Iteration
i	j	startTime[i]	endTime[j]	activate	maxRooms	Action
0	0	1	5	1	1	Start Meeting 1 (activate++)
1	0	2	5	2	2	Start Meeting 2 (activate++)
2	0	3	5	3	3	Start Meeting 3 (activate++)
3	0	4	5	4	4	Start Meeting 4 (activate++)
4	0	-	5	3	4	End Meeting 1 (activate--)
4	1	-	6	2	4	End Meeting 2 (activate--)
4	2	-	7	1	4	End Meeting 3 (activate--)
4	3	-	8	0	4	End Meeting 4 (activate--)
Key Observations
We increment activate when a meeting starts (startTime[i] < endTime[j]).
We decrement activate when a meeting ends (startTime[i] >= endTime[j]).
The maximum value of activate at any point is 4, meaning we need 4 rooms.
Breaking Down the Loop Logic
if (startTime[i] < endTime[j]) {
    activate++;  // A new meeting starts
    i++;         // Move to the next start time
} else {
    activate--;  // A meeting ends
    j++;         // Move to the next end time
}
maxRooms = max(maxRooms, activate); // Track max rooms required
Why does j move only when startTime[i] >= endTime[j]?
Because this means a meeting is ending, so we should free a room before checking the next meeting.


   class Solution {
     public:
       int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<int> startTime(len), endTime(len);
        
        for (int i = 0; i < len; ++i) {
            startTime[i] = intervals[i][0];
            endTime[i] = intervals[i][1];
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        
        int i = 0, j = 0;
        int activate = 0, maxRooms = 0;
        
        while (i < len && j < len) {
            if (startTime[i] < endTime[j]) {
                activate++;
                i++;
            } else {
                activate--;
                j++;
            }
            maxRooms = max(maxRooms, activate);
        }
        
        return maxRooms;
    }
    };

#######################################
