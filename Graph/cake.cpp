#include<bits/stdc++.h>
using namespace std;

int cycle(vector<vector<int>> &board, int n, bool** visited, int i, int j) {
    if(i<0||j<0||i==n||j==n){
        return 0;
    }
    if(1 == board[i][j] && !visited[i][j]){
        visited[i][j] = true;
        int ans;
       	int ans1 = cycle(board, n, visited, i, j+1);
        int ans2 = cycle(board, n, visited, i+1, j);
        int ans3 = cycle(board, n, visited, i, j-1);
        int ans4 = cycle(board, n, visited, i-1, j);
        ans = 1 + ans1 + ans2 + ans3 + ans4;
    	return ans;    
	}
    return 0;
}

int getBiggestPieceSize(vector<vector<int>> &board, int n) {
    // Write your code here.
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j])
            {
                int max = cycle(board, n, visited, i, j);
                if(max > ans)
                    ans = max;
        	}
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}