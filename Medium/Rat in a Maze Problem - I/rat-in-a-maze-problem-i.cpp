//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve (vector<vector<int>> &m, int n,string &curr, vector<string> &ans,int row, int col   )
    {
        if(row==col && row== n-1) {ans.push_back(curr); return;}
        if(row<0 || row>=n || col<0 || col>=n || m[row][col]== 0) return;
        m[row][col]= 0;
        //up
        curr+= 'U';
        
        solve(m,n,curr,ans,row-1,col);
        curr.pop_back();
        
        //down
        curr+='D';
            solve(m,n,curr,ans,row+1,col);
        curr.pop_back();
        
        //left
         curr+= 'L';
        solve(m,n,curr,ans,row,col-1);
        curr.pop_back();
        
        //right
         curr+= 'R';
        solve(m,n,curr,ans,row,col+1);
        curr.pop_back();
         m[row][col]= 1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string curr;
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
      
        solve(m,n,curr, ans, 0,0);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends