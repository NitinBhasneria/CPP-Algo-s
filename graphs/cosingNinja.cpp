#include <bits/stdc++.h>
using namespace std;

bool hasCoding(vector<vector<char>> &board, int n, int m, char* arr, bool** visited, int i, int j) {
    if(i<0||j<0||i==n||j==m){
        return false;
    }
    if(arr[0] == '\0')
        return true;
    // cout<<i<<" "<<j<<" /"<<arr<<" "<<(arr[0] == board[i][j])<<endl;
    if(arr[0] == board[i][j] && !visited[i][j]){
        visited[i][j] = true;
        if(hasCoding(board, n, m, arr+1, visited, i, j+1)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i+1, j+1)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i+1, j)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i+1, j-1)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i, j-1)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i-1, j-1)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i-1, j)) return true;
        if(hasCoding(board, n, m, arr+1, visited, i-1, j+1)) return true;
    }
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    char arr[] = "CODINGNINJA";
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    bool ans = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'C'){
                if(hasCoding(board, n, m, arr, visited, i, j)){
                    ans = true;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}