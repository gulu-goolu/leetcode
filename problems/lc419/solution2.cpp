#include <vector>
#include <cstdio>

using namespace std;


class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {
    int num = 0;
    for (int i = 0; i < board.size(); ++i) {
      for (int j  = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'X') {
         if ((i == 0 || (i > 0 && board[i - 1][j] == '.')) &&
             (j == 0 || (j > 0 && board[i][j - 1] == '.'))) {
	   num++;
	 }
        }
      }
    }
    return num;
  }
};

int main() {
  Solution solution;
  vector<vector<char>> board = {
    {'.', 'X'},
    {'.', 'X'}
  };

  printf("num = %d\n", solution.countBattleships(board));
}
