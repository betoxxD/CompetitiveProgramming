#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int seen[20];

  Solution() { clearSeen(); }

  void clearSeen() {
    int i;
    for (i = 0; i < 10; i++) {
      seen[i] = 0;
    }
  }

  bool isValidSquare(int x, int y, vector<vector<char>> &board) {
    int i, j;
    int digit;
    for (i = x; i < x + 3; i++) {
      for (j = y; j < y + 3; j++) {
        digit = (board[i][j] != '.' ? board[i][j] : '0') - '0';
        if (digit != 0 && seen[digit]) {
          return false;
        }
        seen[digit]++;
      }
    }
    clearSeen();
    return true;
  }

  bool isValidRow(int x, vector<vector<char>> &board) {
    int i;
    int digit;
    for (i = 0; i < 9; i++) {
      digit = (board[x][i] != '.' ? board[x][i] : '0') - '0';
      if (digit != 0 && seen[digit]) {
        return false;
      }
      seen[digit]++;
    }
    clearSeen();
    return true;
  }

  bool isValidColumn(int y, vector<vector<char>> &board) {
    int i;
    int digit;
    for (i = 0; i < 9; i++) {
      digit = (board[i][y] != '.' ? board[i][y] : '0') - '0';
      if (digit != 0 && seen[digit]) {
        return false;
      }
      seen[digit]++;
    }
    clearSeen();
    return true;
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    int i, j;
    for (i = 0; i < 9; i += 3) {
      for (j = 0; j < 9; j += 3) {
        if (!isValidSquare(i, j, board)) {
          return false;
        }
      }
    }

    for (i = 0; i < 9; i++) {
      if (!isValidRow(i, board)) {
        return false;
      }
      if (!isValidColumn(i, board)) {
        return false;
      }
    }

    return true;
  }
};

int main() {

  vector<vector<char>> boardValido = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  vector<vector<char>> boardInvalido = {
      {'8', '3', '.', '.', '7', '8', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '5', '.', '.', '.', '.', '6', '.'},
      {'9', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution s;
  printf("Board valido:\n");
  if (s.isValidSudoku(boardValido)) {
    cout << "El Sudoku es válido ✅" << endl;
  } else {
    cout << "El Sudoku es inválido ❌" << endl;
  }

  printf("Board invalido:\n");
  if (s.isValidSudoku(boardInvalido)) {
    cout << "El Sudoku es válido ✅" << endl;
  } else {
    cout << "El Sudoku es inválido ❌" << endl;
  }

  return 0;
}
