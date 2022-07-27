//
// Created by Ste7an on 2022/7/27.
//

#ifndef ALGORITHM_L79_EXIST_H
#define ALGORITHM_L79_EXIST_H
//单词搜索
//
#include "vector"
#include "string"
using namespace std;


vector<int> directions{-1,0,1,0,-1};
bool dfs(int pos, vector<vector<char>>& board, string word, int row, int col)
{
   if(pos == word.size())
   {
       return true;
   }
   char ch = board[row][col];
   board[row][col] = '0';
   bool res = false;

   int x, y;
   for(int i = 0; i < 4; i++)
   {
       x = row + directions[i];
       y = col + directions[i + 1];
       if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == word[pos])
       {
           if(dfs(pos + 1, board, word, x, y))
           {
                res = true;
                break;
           }
       }
   }
   board[row][col] = ch;
   return res;
}

bool exist(vector<vector<char>> board, string word)
{
    int m = board.size();
    int n = board[0].size();
    int pos = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == word[pos])
            {
                if(dfs(pos + 1, board, word, i, j))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

#endif //ALGORITHM_L79_EXIST_H
