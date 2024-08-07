//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){\
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(auto it: arr){
        minheap.push(it);
    }
    int curr = 1;
    unordered_map<int,int> mapping;
   while(!minheap.empty()){
       int top = minheap.top();
       minheap.pop();
       while(!minheap.empty() && minheap.top()==top) {
           minheap.pop();
       }
       mapping[top]= curr++;
   }
for(int i=0;i<N;i++){
    
    arr[i] = mapping[arr[i]];
}
return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends