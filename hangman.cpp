#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int word_count(char arr[]);
int randomizer(char org[], char random[], int limit);
bool checker(char guess, char user_guess[], char guess_word[], int& correct_guess);
char hint_finder(char user_guess[], char guess_word[]);
void level_display(int level);
void level_1();
void level_2();
void level_3();
void level_4();
void level_5();
void level_6();
void level_7();
int main()
{
  char word_list[100]={};   //array to store the input list of words
  char guess_word[100]={};  //array to store the word that is to be guessed
  char user_guess[100]={};  //array to store the correct letters guessed by the user
  char guess;               //char to input the guess letter from the user
  // int correct_guess[1]={};  //array to store the correct guess from the user
  int correct_guess = 0;
  int incorrect_guess=1;
  //for(int i=0; i<100; ++i)
  //{
    //user_guess[i]='_';
  //}
  int no_word;   //stores the number of words in the input list
  int word_length;  //stores the length of the randomly selected word
  cout<<"\t\tPF Presents\n\t\tHangman in C++";
  int choice;
  do{
    no_word=0, word_length=0;  //initializes to zero, for every new round
    cout<<"\nPress 1 to Play";
    cout<<"\nPress 2 to Quit\n";
    cin>>choice;
    switch(choice)
    {
      case 1:
      cout<<"\n\tYou Selected to Play";
      cout<<"\nEnter the list of words. Maximum 100 characters are allowed.\n";
      cout<<"All characters are to be in lowercase and are separated by a comma:\n";
      cin.ignore();
      cin.getline(word_list,100);       //input the word list 
      no_word=word_count(word_list);    //func returns the number of words in the input word list
      word_length=randomizer(word_list, guess_word, no_word);  //func selects a random word from the list
                                                               //func returns int, which is the length of 
                                                               //the selected word starting from index zero
      // correct_guess[0]=word_length;  //stores the length of the selected word in array
      correct_guess = word_length;
      for(int i=0; i<=word_length; ++i)
        user_guess[i]='_';
      cout<<"\nA random word has been selected. The game has started.\n";
      int hint=0;
      int hint_choice;
      do{
        bool flag=false;
        level_display(incorrect_guess);   //calling function to display the game level
        if(incorrect_guess==6)    //check if the user has made 6 incorrect guess
        {
          if(hint==0)          //check if the user has already used the hint or not
          {
            cout<<"Only One Chance Left. Would You Like a Hint?\nPress 1 for Yes\nPress 2 for No\n";
            cin>>hint_choice;
            if(hint_choice==1)   //checks users response
            {
              ++hint;
              guess = hint_finder(user_guess, guess_word);  //func returns one of the correct characters of the guess word
              checker(guess, user_guess, guess_word, correct_guess);  //func updates the guess array
              cout<<"Hint has been revealed.\n";
            }
          }
        }
        cout<<"Guess Word: ";
        for(int i=0; i<=word_length; ++i)
          cout<<user_guess[i];
        cout<<"\nEnter your Guess letter: ";
        cin>>guess;
        flag = checker(guess, user_guess, guess_word, correct_guess);
        if(flag==true)
          cout<<"Correct Guess\n";
        else
        {
         ++incorrect_guess;
         cout<<"WRONG GUESS. ONE LIVE LOST.\n";
         switch(incorrect_guess)
          {
            case 7:
              level_7();
              cout<<"\nYOU LOST THIS ROUND";
              ++incorrect_guess;
            break;
          }
        }
      }while(incorrect_guess<8 && correct_guess>=0); //correct_guess[0] >= 0
      if(correct_guess<0)  //correct_guess[0] < 0
      {
        cout<<"Guess Word: ";
        for(int i=0; i<=word_length; ++i)
          cout<<user_guess[i];
        cout<<"\nYOU WON THIS ROUND";
      }
      else
      {
        cout<<"The correct word was: ";
        for(int i=0; i<=word_length; ++i)
          cout<<guess_word[i]; 
      }
      break;
    }
  }while(choice!=2);
  cout<<"\n\t\tGAME FINISHED.\n\t\tTHANK YOU FOR PLAYING";
return 0;
}
//need to create a function, which finds the number of words of in the input list
int word_count(char arr[])
{ 
  int number=1;
  for(int x=0; x<100 && arr[x] != '\0'; ++x)
    if(arr[x]==',')
      ++number;
  return number;
}
//need to create a function which extracts a certain word. First in non-randomized order
int randomizer(char org[], char random[], int limit)
{
  srand(time(0));
  int n=0, length=-1;
  int index = (rand()%limit)+1;
  // cout<<"The index of the random word is: "<<index;
  // if(index==1)
  // {
  //   for(int x=0; x<100 && org[x]!=',' && org[x]!='\0'; ++x)
  //   {
  //     random[x]=org[x];
  //     ++length;
  //   }
  //   cout<<length;
  //   return length;  //returns the length of the random word. Starting from zero
  // }
  // for(int x=0; x<100; ++x)
  // {
  //   if(org[x]==',')
  //   {
  //     ++n;
  //     if(index==n+1)
  //     {
  //       int start=x+1;
  //       for(int y=0; y<100 && org[start]!=',' && org[start]!= '\0'; ++y)
  //       {
  //         random[y]=org[start++];
  //         // ++start;
  //         ++length;   
  //       }
  //       return length;  //returns the length of the random word. Starting from zero
  //     }
  //   }
  // }
  for(int x=0; x<100 && org[x] != '\0'; ++x)
  {
    if( index == n+1) 
    {
      // int start = x;
      for( int y=0; y<100 && org[x] != ',' && org[x] != '\0'; ++y)
      {
        random[y] = org[x++];
        ++length;
      }
      return length;
    }
    else
    {
      if( org[x] == ',')
        ++n;
    }
  }
  return 1;
}
//levels 
void level_1()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl; 
}
void level_2()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"  O   |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl;
}
void level_3()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"  O   |"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl; 
}
void level_4()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"  O   |"<<endl;
  cout<<" /|   |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl; 
}
void level_5()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"  O   |"<<endl;
  cout<<" /|\\  |"<<endl;
  cout<<"      |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl; 
}
void level_6()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"  O   |"<<endl;
  cout<<" /|\\  |"<<endl;
  cout<<" /    |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl; 
}
void level_7()
{
  cout<<"  +---+"<<endl;
  cout<<"  |   |"<<endl;
  cout<<"  O   |"<<endl;
  cout<<" /|\\  |"<<endl;
  cout<<" / \\  |"<<endl;
  cout<<"      |"<<endl;
  cout<<"---------"<<endl;
  cout<<"---------"<<endl; 
}
bool checker(char guess, char user_guess[], char guess_word[], int& correct_guess) //int correct_guess[]
{
  bool flag=false;
  for(int x=0; x<100 && guess_word[x]!='\0'; ++x)
  {
    if(guess==guess_word[x])
    {
      user_guess[x]=guess_word[x];
      flag= true;
      correct_guess--;
    }
  }
  return flag;
}
void level_display(int level)
{
  switch (level)
  {
  case 1:
    level_1();
  break;
  case 2:
    level_2();
  break;
  case 3:
    level_3();
  break;
  case 4:
    level_4();
  break;
  case 5:
    level_5();
  break;
  case 6:
    level_6();
  break;
  }
}
char hint_finder(char user_guess[], char guess_word[])
{
  char hint='a';
  for(int x=0; x<100; ++x)
  {
    if(user_guess[x]=='_')
    {
      hint=guess_word[x];
      return hint;
    }
  }
  return hint;
}
