#include<iostream>
#include "TicTacToe.h"
using namespace std;


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