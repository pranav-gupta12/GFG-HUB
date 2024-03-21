//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
vector<int> nexts(int* heights,  int n)
    {
      
        // int n = heights.size();
          vector<int> ans(n);
        stack<int> s;
        for(int i = n-1;i>=0;i--)
        {
            int curr = heights[i];
            while(!s.empty() && heights[s.top()] >= curr ) s.pop();
            if(!s.empty())  ans[i] = s.top();
            else ans[i] = n;
            s.push(i);
            
        }
        return ans;
    }
    vector<int> previous(int* heights,  int n){
  
        // int n = heights.size();
              vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int curr=  heights[i];
            while(s.top()!= -1 && curr<= heights[s.top()]) s.pop();
            ans[i]= s.top();
            s.push(i);
            
            
        } return ans;
        
        
    }
    int largestRectangleArea(int* heights,  int n) {
    //  int n = heights.size();
        vector<int> next(n); next = nexts(heights,n);
           vector<int> prev(n); prev = previous(heights,n);
        int area = 0;
        for(int i=0;i<n;i++){
            int l = heights[i];
            // if(next[i]== )
            int b = next[i]- prev[i]-1;
            int curr = l*b;
            area = max(area, curr);
            
        }
        return area;
    }
class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = largestRectangleArea(M[0],m);
      
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
               //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] += M[i-1][j];
                else
                    M[i][j] = 0;
            }
            area = max(area,largestRectangleArea(M[i], m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends