#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int  main()
{ 
   int guess=0; 
   string ch;
   srand((unsigned int ) time (0));
   int number=(rand()%50)+1;
   cout<<"welcome to number guessing game!!!!!"<<endl;
   while(ch!="no")
   {
   do
   {  
      cout<<"Enter the number between [1-50]:";
      cin>>guess;

      if(guess<number)
      {
        cout<<"Your guess is low !!"<<endl;
      }
      else if(guess>number)
      {
        cout<<"Your guess is high !!"<<endl;
      }
      else
      {
        cout<<"FInally!!\nYour guess is right\nYou won :)"<<endl;
      }
   } while(guess!=number);
   cout<<"Do you want to play again[yes/no]:";
   cin>>ch;
   }

}
