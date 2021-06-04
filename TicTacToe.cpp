#include<iostream>
#include<unistd.h>//for using sleep function in Unix-Based OS(in windows use windows.h)
using namespace std;

class TicTacToe
{
    char board[4][4];

    string user1;
    string user2;

    bool turn;

    public:
      TicTacToe()//creates empty board
      {
         for (int i = 0; i < 4; ++i)
         {
            for (int j = 0; j < 4; ++j)
            {
               board[i][j]='_';
            }
         }
      }

      ~TicTacToe(){}

      bool inputer(int position, const bool& userTurn)//insert X or O in a position of the board
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

      int checker()//Check for winner!
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

      bool full()//is the board full?
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

      void names(const string& name1, const string& name2)//usernames setter
      {
         user1 = name1;
         user2 = name2;
      }

      void print()//print table
      {
         cout << endl;

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
            cout << endl;
         }
         cout << endl;
      }
};

int main()
{
   TicTacToe t1;

   string name1,name2;

   cout << "NAMES: ";

   getline(cin, name1);
   getline(cin, name2);

   t1.names(name1,name2);

   int pos=0;

   int winner;

   bool isValid;

   while(1)
   {
      if(t1.full())
      {
         cout<<"\nTie\n";
         break;
      }

      while(!isValid)//while will break if a valid position enter by user
      {
         cout<<"X: ";
         
         cin>>pos;

         isValid=t1.inputer(pos,true);
      }

      isValid=false;

      winner=t1.checker();//check if X wins

      t1.print();

      if(winner==0)
      {
          cout<<"\n"<<name1<<"WINS\n";

         break;
      }

      while(!isValid)
      {
         cout<<"O: ";

         cin>>pos;

         isValid=t1.inputer(pos,false);
      }

      isValid=false;

      winner=t1.checker();//check if O wins

       t1.print();

      if(winner==1)
      {
         cout<<"\n"<<name2<<"WINS\n";
         break;
      }
   }
   return 0;
}