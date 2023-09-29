//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(arr[i]>arr[prev] && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
        }
        
        int last_index=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                last_index=i;
            }
        }
        // cout<<last_index;
        vector<int>temp;
        temp.push_back(arr[last_index]);
        while(hash[last_index]!=last_index)
        {
            last_index=hash[last_index];
            temp.push_back(arr[last_index]);
            
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends