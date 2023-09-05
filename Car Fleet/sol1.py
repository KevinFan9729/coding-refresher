class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        if len(position)==1:
            return 1
        combined = list(zip(position, speed))
        combined.sort()
        ans = 0
        memory = set()
        R = len(combined)-1
        L = R-1
        while R>=0 and L >=0: 
            right_time = (target - combined[R][0])/combined[R][1]
            left_time = (target - combined[L][0])/combined[L][1]
            if right_time >= left_time:#right car is slower
                if combined[R] not in memory:
                    ans+=1
                memory.add(combined[R])
                L-=1
            else: #right car is faster, no combined fleet
                if combined[R] not in memory: # the right car itself form a fleet
                    ans+=1
                memory.add(combined[R])
                R = L
                if L!=0:
                    L-=1
        return ans