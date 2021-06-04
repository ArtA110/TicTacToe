#ifndef TicTacToe_H
#define TicTacToe_H
#include<iostream>
class TicTacToe
{
    char board[4][4];

    std::string user1;
    std::string user2;

    bool turn;

    public:
      TicTacToe();//creates empty board
    
      ~TicTacToe();

      bool inputer(int position, const bool& userTurn);//insert X or O in a position of the board
      

      int checker();//Check for winner!
      

      bool full();//is the board full?
      

      void names(const std::string& name1, const std::string& name2);//usernames setter
      

      void print();//print table    
};

#endif