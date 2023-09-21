def findDup(nums, N):
    possible_tar = list(range(1,N+1))
    nums = sorted(nums)
    for target in possible_tar:
        L=0
        R = N
        while L<=R:
            mid = L+(R-L)//2
            if nums[mid]>target:
                R = mid-1
            elif nums[mid]<target:
                L = mid+1
            else:
                if(nums[(mid+1)%len(nums)] == target or
                   nums[(mid-1)%len(nums)] == target):
                    return target
                else:
                    break
        
print(findDup([1,3,2,2],3))