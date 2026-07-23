class Solution:
    def climbStairs(self, n: int) -> int:
        #n = 1 dp[0] = 1
        #n = 2 dp[1] = 1 + 1
        #n = 3 dp[2] = 2 + 1
        #n = 4 dp[3] = 3 + 2

        #dp[n] = dp[n-1] + dp[n-2]
        dp = [0 for _ in range(n)]
        if(n == 1):
            return 1
        if(n == 2):
            return 2
        dp[0] = 1
        dp[1] = 2
        for i in range(2,n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n-1]
