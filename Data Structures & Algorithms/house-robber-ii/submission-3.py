class Solution:
    def rob(self, nums: List[int]) -> int:
        #dp[0] = nums[0]
        #dp[1] = max(nums[0],nums[1])
        #dp[2] = max(nums[0],nums[1],nums[2])
        #dp[n] = max(dp[n-1],nums[n]+dp[n-2])

        n = len(nums)
        if(n == 1):
            return nums[0]
        elif(n == 2):
            return max(nums[0],nums[1])
        elif(n == 3):
            return max(nums[0],nums[1],nums[2])
        dp1 = [0 for _ in range(n-1)]
        dp1[0] = nums[0]
        dp1[1] = max(nums[0],nums[1])
        for i in range(2,n-1):
            dp1[i] = max(dp1[i-1], nums[i]+dp1[i-2])

        dp2 = [0 for _ in range(n-1)]
        dp2[0] = nums[1]
        dp2[1] = max(nums[1],nums[2])
        for i in range(2,n-1):
            dp2[i] = max([dp2[i-1],nums[i+1]+dp2[i-2]])

        return max(dp1[n-2],dp2[n-2])