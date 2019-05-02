#include<iostream>
#include<stdlib.h>
using namespace std;
struct Minion{
  string name;
  short bombs;
  short total_firepower;
  short firepower[21];
};
void initialize(Minion& minion,string name){
  srand(time(NULL));
  minion.bombs=1;
  minion.name.resize(name.size());
  for(int i=0;i<name.size();i++){
    minion.name[i]=name[i];
  }
  if(rand()%11==0){
    minion.firepower[minion.bombs-1]=12;
  }else{
    minion.firepower[minion.bombs-1]=rand()%10+1;
  }
  for(int i=1;i<=21;i++){
    minion.firepower[i]=0;
  }
}
void total_firepower(Minion& minion){
  minion.total_firepower=0;
  for(int i=0;i<minion.bombs;i++){
    if(minion.firepower[i]!=12){
      minion.total_firepower+=minion.firepower[i];
    }else{
      short* choice=new short;
      cout<<"You want the super bomb to be strong or weak? 1 for strong, 0 be weak"<<endl;
      cin>>*choice;
      if(*choice==1){
        minion.total_firepower+=11;
      }else{
        minion.total_firepower+=1;
      }
      delete choice;
      choice=nullptr;
    }
  }
};
void draw(Minion& minion){
  if(rand()%11==0){
    minion.firepower[minion.bombs]=12;
  }else{
    minion.firepower[minion.bombs]=rand()%10+1;
  };
  minion.bombs+=1;
}
int main(){
  Minion player[7];
  short no_of_player;
  cout<<"How many player?"<<endl;
  cin>>no_of_player;
  string name;
  for(int i=0;i<no_of_player;i++){
    cout<<"what is your name?"<<endl;
    cin>>name;
    initialize(player[i],name);
  };
  for(int i=no_of_player;i<7;i++){
    initialize(player[i],string("UMA"));
  };
  short passed=0;
  while (true){
    passed=0;
    for(int i=0;i<no_of_player;i++){
      total_firepower(player[i]);
      cout<<"Total firepower of "<<player[i].name<<" is "<<player[i].total_firepower<<endl;
      char* choice=new char;
      cout<<"draw again?"<<endl;
      cin>>*choice;
      if (*choice=='y'){
        draw(player[i]);
        total_firepower(player[i]);
        cout<<no_of_player<<endl;
        for(int j=0;j<player[i].bombs;j++){
          if(player[i].firepower[j]==12){
            cout<<j+1<<"\'s bombs of player "<<player[i].name<<" is "<<'A'<<endl;
          }else{
            cout<<j+1<<"\'s bombs of player "<<player[i].name<<" is "<<player[i].firepower[j]<<endl;
          }
        }
      }else{
        passed+=1;
        cout<<passed<<endl;
      }
      cout<<"Total firepower of "<<player[i].name<<" is "<<player[i].total_firepower<<endl;
      if(player[i].total_firepower==21){
        cout<<player[i].name<<" win"<<endl;
        return 0;
      }
      if(player[i].total_firepower>21){
        cout<<player[i].name<<" lose"<<endl;
        short tmp=player[0].total_firepower;
        short winner=0;
        for(int k=0;k<no_of_player;k++){
          if((21-tmp)>0 and (21-tmp)>(21-player[k].total_firepower)){
            tmp=player[k].total_firepower;
            winner=k;
          }
        }
        cout<<player[winner].name<<" win"<<endl;
        return 0;
      }
      delete choice;
      choice=nullptr;
    }
    if(passed==no_of_player){
      short tmp=player[0].total_firepower;
      short winner=0;
      for(int k=0;k<no_of_player;k++){
        if((21-tmp)>0 and (21-tmp)>(21-player[k].total_firepower)){
          tmp=player[k].total_firepower;
          winner=k;
        }
      }
      cout<<player[winner].name<<" win"<<endl;
      return 0;
    }
  }
}
