#include "TicTacToe.h"
#include<unistd.h>//for using sleep function in Unix-Based OS(in windows use windows.h)
using std::cout;
TicTacToe::TicTacToe()//creates empty board
{
      for (int i = 0; i < 4; ++i)
      {
         for (int j = 0; j < 4; ++j)
         {
               board[i][j]='_';
         }
      }
}

TicTacToe::~TicTacToe(){}
      
bool TicTacToe::inputer(int position, const bool& userTurn)//insert X or O in a position of the board
{
   if(position>16 || position<1)
   {
      cout<<"\nSelected position is out of range: Valid range is 1-16\n";
      return false;
   }

   turn = userTurn;

   for(int i=0;i<4;++i)
   {
      for(int j=0;j<4;++j)
      {
         --position;

         if(position==0 && board[i][j]=='_')
         {
            if(turn)
               board[i][j]='x';
            else{
               board[i][j]='o';
            }
               return true;
         }
         else if(position==0 && board[i][j]!='_')
         {
            cout<<"\nALREADY TAKEN!\n";
         }
      }
   }
   return false;
}

int TicTacToe::checker()//Check for winner!
{
   int Xrow=0,Xcol=0,Xhex=0,Xlhex=0,Orow=0,Ocol=0,Ohex=0,Olhex=0;

   for (int i = 0; i < 4; ++i)
   {
      for (int j = 0; j < 4; ++j)
      {
         if(board[i][j]=='x')
         {
            ++Xrow;

            if(Xrow==4)
               return 0;//X WINS
         }

         if(board[j][i]=='x')
         {
            ++Xcol;

            if(Xcol==4)
               return 0;
         }

         if(board[i][j]=='o')
         {
            ++Orow;

            if(Orow==4)
               return 1;//O WINS
         }

         if(board[j][i]=='o')
         {
            ++Ocol;

            if(Ocol==4)
               return 1;
         }
      }

      Xrow=0;
      Xcol=0;
      Orow=0;
      Ocol=0;

      if(board[i][i]=='x')
      {
         ++Xhex;

         if(Xhex==4)
            return 0;//nobody wins YET
      }

      if(board[i][i]=='o')
      {
         ++Ohex;

         if(Ohex==4)
            return 1;
      }

      if(board[i][3-i]=='x')
      {
         ++Xlhex;

         if(Xlhex==4)
            return 0;
      }

      if(board[i][3-i]=='o')
      {
         ++Olhex;

         if(Olhex==4)
            return 1;
      }
            
   }
   return -1;
}

bool TicTacToe::full()//is the board full?
{
   for (int i = 0; i < 4; ++i)
   {
      for (int j = 0; j < 4; ++j)
      {
         if(board[i][j]=='_')
            return false;
      }
   }
   return true;
}

void TicTacToe::names(const std::string& name1, const std::string& name2)//usernames setter
{
   user1 = name1;
   user2 = name2;
}

void TicTacToe::print()//print table
{
   cout << std::endl;

   unsigned int microsec=100000;

   for (int i = 0; i < 4; ++i)
   {
      for (int j = 0; j < 4; ++j)
      {
         cout<<board[i][j];

         cout.flush();//required to flush buffer

         usleep(1*microsec);

         cout<<" ";
      }
      cout << std::endl;
   }
   cout << std::endl;
}