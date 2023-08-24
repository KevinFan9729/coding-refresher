def funWithAnagrams(text):
    # Write your code here
    #anagram if sorted(s) == sorted(t)
    seen = set()
    ans = []
    for s in text:
        sorted_s = str(sorted(s))
        if sorted_s not in seen:
            seen.add(sorted_s)
            ans.append(s)
    
    ans.sort()
        
    return ans