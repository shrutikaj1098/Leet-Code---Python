//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int n,int m,int row, int col,vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            for(int nr=-1;nr<=1;nr++)
            {
                for(int nc=-1;nc<=1;nc++)
                {
                    int newr=r+nr;
                    int newc=c+nc;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1' && !vis[newr][newc])
                    {
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    // vis[row][col]=1;
                    bfs(n,m,row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends