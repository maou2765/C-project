#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <time.h>

using namespace std;
enum minions{
  Kevin,
  Bob,
  Stuart,
  Dave,
  Phil,
  Tim,
  Carl,
  Jerry,
  Mark,
  Larry,
  UMA
};
void guessing(int& fully_right, int& halfly_right,minions minion_list[],int level,char mode){
  int Pchoice;
  for(int i=0;i<level;i++){
  cin>>Pchoice;
  Pchoice-=1;
  if(Pchoice==minion_list[i]){
    fully_right+=1;
    if (mode=='y'){
      cout<<"fully right"<<endl;
    }
  }else{
    for(int j=0;j<level;j++){
      if(Pchoice==minion_list[j]){
        halfly_right+=1;
        if (mode=='y'){
          cout<<"halfly right"<<endl;
          }
          break;
        }
      }
    }
  }
}
void computer_guess(minions minion_list[],int level,char mode,int& res,int i,minions& wrong,minions& half_ans,minions& guess,minions& memory)
{
  if(guess==minion_list[i]){
    res=2;
    memory=guess;
    wrong=UMA;
    half_ans=UMA;
  }else{
    for(int j=0;j<level;j++){
      if(guess==minion_list[j]){
        res=1;
        half_ans=guess;
        wrong=UMA;
      }
    };
    if(res==0){
      cout<<"+1"<<endl;
      wrong=guess;
      half_ans=UMA;
    }
  };
  cout<<"computer's choice: "<<guess<<endl;
}




int main(){
  minions minion_list[10]={Kevin,Bob,Stuart,Dave,Phil,Tim,Carl,Jerry,Mark,Larry};
  const minions minions_ref[10]={Kevin,Bob,Stuart,Dave,Phil,Tim,Carl,Jerry,Mark,Larry};
  minions memory[10]={UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA};
  minions incorrect_answer_set[10]={UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA};
  minions answer_set[10]={UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA};
  minions now_guess[10]={UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA};
  minions past_guess[10]={UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA,UMA};
  int Cresult[12]={0,0,0,0,0,0,0,0,0,0,0,0};//result corr. to each answer, Cresult[10]is the number of half correct, Cresult[11] is the number of full correct
  minions tmp,tmp_wrong_ans,tmp_half_ans,tmp_guess;
  bool change;
  int which_1,which_2,rand_key,level=1;
  int Pchoice;
  char next,retry,mode;
  next='n';
  int Pfully_right=0,Phalfly_right=0,Cfully_right=0,Chalfly_right=0;
  cout<<"Easy mode?"<<endl;
  cin>>mode;
  int Pscore=0,Cscore=0;
  while(true){

    for(int i=0;i<30;i++){//generation of the minion's position
      if(i>9){
        srand(time(NULL));
        change=rand()%2;
      }else{
        change=true;
      };
      srand(time(NULL)+rand_key);
      rand_key=rand();
      srand(time(NULL)+change+which_1+rand_key);
      which_1=rand()%10;
      srand(time(NULL)+change+which_1+which_2);
      which_2=rand()%10;
      if(change){
        tmp=minion_list[which_1];
        minion_list[which_1]=minion_list[which_2];
        minion_list[which_2]=tmp;
      }
    };
    for(int i=0;i<10;i++){
      memory[i]=UMA;
      answer_set[i]=UMA;
      incorrect_answer_set[i]=UMA;

    };
    for(int i=0;i<sizeof(Cresult)/sizeof(int);i++){Cresult[i]=0;};
    next='n';
    Pfully_right=0,Phalfly_right=0;
    while(true){
      Pfully_right=0;Phalfly_right=0;
      cout<<"1 for Kevin,2 for Bob,3 for Stuart,4 for Dave,5 for Phil,6 for Tim,7 for Carl,8 for Jerry,9 for Mark,10 for Larry"<<endl;
      guessing(Pfully_right,Phalfly_right,minion_list,level,mode);
      for(int j=0;j<10;j++){
        now_guess[j]=UMA;
      };
      for(int i=0;i<level;i++){
        for(int j=0;j<10;j++){
          for(int k=0;k<10;k++){
            if (minions_ref[j]==incorrect_answer_set[k]){
              tmp_guess=UMA;
              break;
            };
            if(k==9){
              tmp_guess=minions_ref[j];
              cout<<tmp_guess<<"not in incorrect set"<<endl;
            };
          };
          for(int k=0;k<level;k++){
            if(memory[k]!=UMA&&k==i){
              tmp_guess=memory[k];
            }
          };
          for(int k=0;k<level;k++){
            if(tmp_guess==answer_set[k]&&tmp_guess!=UMA&&tmp_guess==past_guess[i]){
              cout<<tmp_guess<<"in half correct set"<<endl;
              tmp_guess=UMA;
            }
          };
          for(int k=0;k<level;k++){
            if(tmp_guess!=UMA && tmp_guess==now_guess[k]){
              tmp_guess=UMA;
            }
          };
          if(tmp_guess!=UMA){
            cout<<"Computer's guest: "<<tmp_guess<<endl;
            break;
          }
        };

        now_guess[i]=tmp_guess;
        past_guess[i]=tmp_guess;
        computer_guess(minion_list,level,mode,Cresult[i],i,tmp_wrong_ans,tmp_half_ans,tmp_guess,memory[i]);
        for(int k=0;k<level;k++){
          if(tmp_wrong_ans==UMA){
            break;
          };
          if(tmp_wrong_ans==incorrect_answer_set[k]){
            tmp_wrong_ans=UMA;
            break;
          };
        };
        if(tmp_wrong_ans!=UMA){
              for(int k=0;k<10;k++){
                if(incorrect_answer_set[k]==UMA){
                  incorrect_answer_set[k]=tmp_wrong_ans;
                  tmp_wrong_ans=UMA;
                  break;
                }
              }
            };
        for(int j=0;j<level;j++){
          if(tmp_half_ans!=UMA){
            for(int k=0;k<level;k++){
                if(tmp_half_ans==answer_set[k]){tmp_half_ans=UMA;break;}
              };
            };
            if(tmp_half_ans!=UMA){
              for(int k=0;k<level;k++){
                if(answer_set[k]==UMA){
                  answer_set[k]=tmp_half_ans;
                  break;
              }
            }
          }
        };
      };
      Cfully_right=0;
      Chalfly_right=0;
      for(int i=0;i<level;i++){
        if(memory[i]==minion_list[i]){
            Cfully_right+=1;
          }else{
            for(int j=0;j<level;j++){
              if(memory[i]==minion_list[j]){
                Chalfly_right+=1;
                break;
              }
            }
          }
        }
      cout<<"Cfully_right"<<Cfully_right<<endl;
      cout<<"Chalfly_right"<<Chalfly_right<<endl;
      if(Cfully_right==level){
        if(level==10){
          cout<<"You are so smart! You have clear all level"<<endl;
          cout<<"Play again?"<<endl;
          cin>>retry;
          if(retry=='y'){
            level=1;
            break;
          }else{
            return 0;
          }
        }else{
          Cscore+=1;
          cout<<"Player's score: "<<Pscore<<endl;
          cout<<"Computer's score: "<<Cscore<<endl;
          cout<<"Next level?";
          cin>>next;
          if(next=='y'){
            level+=1;
            break;}
            else if(next=='n'){
              return 0;
            };
          };
        };
      if(Pfully_right==level){
        if(level==10){
          cout<<"You are so smart! You have clear all level"<<endl;
          cout<<"Play again?"<<endl;
          cin>>retry;
          if(retry=='y'){
            level=1;
            break;
          }else{
            return 0;
          }
        };
        Pscore+=1;
        cout<<"Player's score: "<<Pscore<<endl;
        cout<<"Computer's score: "<<Cscore<<endl;
        cout<<"Next level?";
        cin>>next;
        if(next=='y'){
          level+=1;
          break;}
        else if(next=='n'){
          return 0;
        };
      }else if(Pfully_right<level && (Phalfly_right+Pfully_right)>0){
        cout<<Phalfly_right<<" halfly right while "<<Pfully_right<<" fully right"<<endl;
        cout<<"Play Again?"<<endl;
        cin>>retry;
        if(retry=='y'){
          continue;
        }else{
          return 0;
        };
      }else if(Pfully_right<level && (Pfully_right+Phalfly_right)==0){
        cout<<"all wrong"<<endl;
        cout<<"Play Again?"<<endl;
        cin>>retry;
        if(retry=='y'){
          continue;
        }else{
          return 0;
        };
      }
    return 0;
  }}}
