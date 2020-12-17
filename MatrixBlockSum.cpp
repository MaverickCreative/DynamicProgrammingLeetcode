#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> prefixSum(mat.size()+1, vector<int>(mat[0].size()+1, 0));
        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), 0));
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i=1;i<=mat.size();i++)
        {
            for(int j=1;j<=mat[0].size();j++)
            {
                prefixSum[i][j] = mat[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                int r1 = (i - K) < 0 ? 0 : i-K;
                int r2 = (i + K )>= rows ? rows-1: i+K;
                int c1 = (j - K) < 0 ? 0 : j-K;
                int c2 = (j + K )>= cols ? cols-1: j+K;
                r1 += 1;
                c1 += 1;
                r2 += 1;
                c2 += 1;
                answer[i][j] = prefixSum[r2][c2] - prefixSum[r1-1][c2] - prefixSum[r2][c1-1] + prefixSum[r1-1][c1-1];
            }
        }
        return answer;
    }
};