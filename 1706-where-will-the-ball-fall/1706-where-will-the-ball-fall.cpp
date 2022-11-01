class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        // vector<int> ans(grid[0].size(),0);
//         for(int j=0;j<grid[0].size();j++) {
//             for(int i=0;i<grid.size();i++) {
//                 if(j==0 and grid[i][j]==-1) {
//                     ans[i] = -1;
//                     continue;
//                 }
//                 else if(j==grid[0].size()-1 and grid[i][j]==1) {
//                     ans[i] = -1;
//                     continue;
//                 }
//                 else if(grid[i][j]==1 and grid[i][j+1]==-1) {
//                     ans[i] = -1;
//                     continue;
//                 }
//                 else if(grid[i][j]==-1 and grid[i][j-1]==1) {
//                     ans[i] = -1;
//                     continue;
//                 }
                
//             }
//         }
        
        int pos=0,m=grid.size(),n=grid[0].size();
        vector<int> ans(n,0);
        for(int j=0;j<n;j++) {
            pos = j;
            for(int i=0;i<m;i++) {
                if(pos==0 and grid[i][pos]==-1) {
                    ans[j]=-1;
                    break;
                }
                else if(pos==n-1 and grid[i][pos]==1) {
                    ans[j]=-1;
                    break;
                }
                else if(grid[i][pos]==1 and grid[i][pos+1]==-1) {
                    ans[j]=-1;
                    break;
                } 
                else if(grid[i][pos]==-1 and grid[i][pos-1]==1) {
                    ans[j]=-1;
                    break;
                }
                else if(grid[i][pos]==1 and grid[i][pos+1]==1) 
                    pos++;
                else if(grid[i][pos]==-1 and grid[i][pos-1]==-1) 
                    pos--;
                    
            }
            if(ans[j]==0)
                ans[j] = pos;
        }
        
        
        return ans;
    }
};