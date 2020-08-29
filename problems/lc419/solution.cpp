// https://leetcode-cn.com/problems/battleships-in-a-board/
// 甲板上有多少战列舰

#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

// 标记法
int countBattleships(vector<vector<char>>& board) {
  if (board.empty() || board[0].empty()) return 0;
  int num = 0;
  const int N = board.size(), M = board[0].size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (board[i][j] == 'X') {
        board[i][j] = '*';
        // horizontal
        int k = j + 1;
	while (k < M && board[i][k] == 'X') {
	  board[i][k++] = '*';
	}
	// verrical
	k = i + 1;
	while (k < N && board[k][j] == 'X') {
	  board[k++][j] = '*';
	}

	num++;
      }
    }
  }
  return num;
}

int main() {
  vector<vector<char>> board = {
    {'X', '.', '.', 'X'},
    {'.', '.', '.', 'X'},
    {'.', '.', '.', 'X'},
    {'.', '.', '.', 'X'},
  };
  int num = countBattleships(board);
  printf("num = %d\n", num);
}

