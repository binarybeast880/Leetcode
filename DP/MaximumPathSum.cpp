class Solution
{
public:
 int getMinPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
 {
  if (i == 0 && j == 0)
   return grid[i][j];
  if (dp[i][j] != -1)
   return dp[i][j];
  int m = INT_MAX;
  if (j > 0)
   m = grid[i][j] + getMinPath(grid, i, j - 1, dp);
  if (i > 0)
  {
   int s = grid[i][j] + getMinPath(grid, i - 1, j, dp);
   m = min(m, s);
  }
  return dp[i][j] = m;
 }
 int minPathSum(vector<vector<int>> &grid)
 {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return getMinPath(grid, n - 1, m - 1, dp);
 }
};