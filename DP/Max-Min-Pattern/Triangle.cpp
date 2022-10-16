class Solution
{
public:
 int f(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
 {
  if (i == n)
   return 0;
  if (dp[i][j] != -1)
   return dp[i][j];
  int step1 = triangle[i][j] + f(i + 1, j, n, triangle, dp);
  int step2 = triangle[i][j] + f(i + 1, j + 1, n, triangle, dp);
  return dp[i][j] = min(step1, step2);
 }

 int minimumTotal(vector<vector<int>> &triangle)
 {
  vector<vector<int>> dp(triangle.size(), vector<int>(100000, -1));
  return f(0, 0, triangle.size(), triangle, dp);
 }
};