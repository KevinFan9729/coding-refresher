class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        #sort the our array based on the start time
        #start time of the second meeting must not be smaller than the end time of the previous
        #if so we have an overlap
        intervals.sort()
        for i in range(len(intervals)-1):
            prev_end = intervals[i][1]
            next_start = intervals[i+1][0]
            if (next_start<prev_end):
                return False
        return True