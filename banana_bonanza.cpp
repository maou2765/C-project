#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <time.h>

using namespace std;
string number2word(int choice){
  string Banana("BANANA");
  string Blade("BLADE");
  string Bomb("BOMB");
  if (choice==1){
    return Banana;
  }
  else if (choice==2){
    return Blade;
  }
  else {
    return Bomb;
  }
}
int main(){
  int result,ComputerChoice,YourChoice;
  string CYourChoice;
  string PlayAgain;
  string UPlayAgain = boost::to_upper_copy<std::string>("YES");
  string YES=boost::to_upper_copy<std::string>("YES");
  string Y=boost::to_upper_copy<std::string>("Y");
  string NO=boost::to_upper_copy<std::string>("NO");
  string N=boost::to_upper_copy<std::string>("N");
  cout<<"BANANA!Larry, Let's play a game! "<<endl;
  cout<<"You may choice Banana, Blade or Bomb as your weapon.";
  cout<<"While Blade eat the Banana, Banana buy the Bomb, Bomb lies to the Blade";
  do{
    srand(time(NULL));
    ComputerChoice=rand()%3+1;
    string Cchoice;
    Cchoice=number2word(ComputerChoice);
    string one=boost::to_upper_copy<std::string>("1");
    string two=boost::to_upper_copy<std::string>("2");
    string three=boost::to_upper_copy<std::string>("3");
    for(;;){
        cout<<"Larry, now you could type 1 for banana, 2 for blade, 3 for bomb\n";
        cin>>CYourChoice;
        if (CYourChoice==one){
          YourChoice=1;
          break;
        }else if(CYourChoice==two){
          YourChoice=2;
          break;
        }else if(CYourChoice==three){
          YourChoice=3;
          break;
        }else{
          cout<<"Stupid Larry! Now I will choice Banana for you"<<endl;
          YourChoice=1;
          break;
        };
    }
    if(ComputerChoice-YourChoice==1 or ComputerChoice-YourChoice==-2){
      cout<<"Buddy Darwin choice ";
      cout<<Cchoice<<endl;
      result=0;
    }
    else if(ComputerChoice==YourChoice){
      cout<<"Buddy Darwin choice "<<endl;
      cout<<Cchoice<<endl;
      result=2;
    }
    else{
      cout<<"Buddy Darwin choice "<<endl;
      cout<<Cchoice<<endl;
      result=1;
    }
    if (result==1){
      cout<<"Smart Larry, you win! Don't forget my name and Eat My BANANA!"<<endl;
    }
    else if (result==0){
      cout<<"I win! HA!HA! I will eat this smart BANANA and become the king of the BOMB!"<<endl;
    }
    else{
      cout<<"Play one more time! There must be one champion between US!"<<endl;
    }
    cout<<"Play again?(y for yes or n for no"<<endl;
    cin>>PlayAgain;
    UPlayAgain = boost::to_upper_copy<std::string>(PlayAgain);
    while (UPlayAgain !=YES && UPlayAgain !=Y && UPlayAgain !=N && UPlayAgain !=NO){
      cout<<"yes or no only! Don't type in strange thing!";
      cin>>PlayAgain;
      UPlayAgain = boost::to_upper_copy<std::string>(PlayAgain);
    };
  }while(UPlayAgain==YES or UPlayAgain==Y);
  return 0;
}
