#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

void addSolution(vvi &ans, vvi &board, int n) {
    vi temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vvi &board, int n) {
    // Check row on the left
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    // Check upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check lower diagonal on the left
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void solve(vvi &ans, vvi &board, int n, int col) {
    if (col == n) {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(ans, board, n, col + 1);
            board[row][col] = 0;  // Backtrack
        }
    }
}

void display(vvi &ans, int n) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
            if ((j + 1) % n == 0) {
                cout << '\n';
            }
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cout << "Enter the value of n:\n";
    cin >> n;
    vvi board(n, vi(n, 0));
    vvi ans;
    solve(ans, board, n, 0);
    display(ans, n);
    cout<<"Total number of solutions : "<<ans.size()<<'\n';
    return 0;
}
