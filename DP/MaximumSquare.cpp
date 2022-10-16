class Solution
{
public:
 int f(vector<vector<char>> &v, int i, int j, vector<vector<int>> &dp)
 {
  int n = v.size(), m = v[0].size();
  if (i >= n || j >= m || v[i][j] == '0')
   return 0;
  if (dp[i][j] != -1)
   return dp[i][j];
  // check down, right, diagonally-down
  return dp[i][j] = 1 + min(f(v, i + 1, j, dp), min(f(v, i + 1, j + 1, dp), f(v, i, j + 1, dp)));
 }
 int maximalSquare(vector<vector<char>> &matrix)
 {
  int n = matrix.size(), m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int res = 0;
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < m; j++)
   {
    if (matrix[i][j] == '1')
     res = max(res, f(matrix, i, j, dp));
   }
  }
  return res * res; // res*res because we have to return area
 }
};