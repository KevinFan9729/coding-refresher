#sliding window O(n*m*log(m))
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1 = sorted(s1)
        L,R = 0, 0 
        while R<len(s2):
            window = s2[L:R+1]
            if len(window)<len(s1):
                R+=1
            elif len(window)>len(s1):
                L+=1
            else:
                if(sorted(window)==s1):
                    return True
                R+=1
        return False