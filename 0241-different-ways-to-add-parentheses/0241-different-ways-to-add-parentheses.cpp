class Solution {
public:
    int calculator(int x,int y,char op){
        if(op=='+') return x+y;
        if(op=='-') return x-y;
        if(op=='*') return x*y;
        return 0;
    }
    vector<int>res(int i,int j,string exp,vector<vector<vector<int>>>&dp){
        if(i>j) return {};
        if(dp[i][j].size()>0) return dp[i][j];
        bool isvalid=true;
        vector<int>results;
        for(int ind=i;ind<=j;ind++){
            if(!isnumber(exp[ind])){
                isvalid=false;
            
            vector<int>left=res(i,ind-1,exp,dp);
            vector<int>right=res(ind+1,j,exp,dp);
            for(int x:left){
                for(int y:right){
                    results.push_back(calculator(x,y,exp[ind]));
                }
            }
            }
        }
        if(isvalid){
            int num = 0;
            for (int ind = i; ind <= j; ind++) {
                num = num * 10 + (exp[ind] - '0');
            }
            results.push_back(num);
        }
        return dp[i][j]=results;

    }
    vector<int> diffWaysToCompute(string expression) {
        int m=expression.length();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(m+1,vector<int>()));
        return res(0,expression.length()-1,expression,dp);
        
    }
    bool isnumber(char c){
        return (c>='0'&&c<='9');
    }
};