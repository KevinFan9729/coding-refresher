class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        L,R = 0, 0 
        if len(s2)<len(s1):
            return False
        count_s1 = defaultdict(int)
        count_s2 = defaultdict(int)
        for c in s1:
            count_s1[c]+=1
        count_s2[s2[0]]+=1
        while R<len(s2):
            window = s2[L:R+1]
            if len(window)<len(s1):
                R+=1
                count_s2[s2[R]]+=1
            elif len(window)>len(s1):
                count_s2[s2[L]]-=1
                if count_s2[s2[L]]==0:
                    count_s2.pop(s2[L])
                L+=1
            else:
                if(count_s1==count_s2):
                    return True
                R+=1
                if R<len(s2):#prevent index error
                    count_s2[s2[R]]+=1    
        return False