#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
long long dice(short dice_1,short dice_2, short dice_3,short dice_4,short dice_5, long long score, long long& draw){
  cout<<"-------------------------------"<<endl<<"You have throw "<<draw<<"times of dice"<<endl;
  if (dice_1==6){
    cout<<"first dices: "<<dice_1<<endl<<"second dices: "<<dice_2<<endl<<"third dices: "<<dice_3<<endl<<"fourth dices: "<<dice_4<<endl<<"firth dices: "<<dice_5<<endl;
    cout<<score<<endl;
    dice_1=rand()%6+1;
    draw+=1;
    return dice(dice_1,dice_2,dice_3,dice_4,dice_5,score+dice_1,draw);
  }else if(dice_2==6){
    cout<<"first dices: "<<dice_1<<endl<<"second dices: "<<dice_2<<endl<<"third dices: "<<dice_3<<endl<<"fourth dices: "<<dice_4<<endl<<"firth dices: "<<dice_5<<endl;
    cout<<score<<endl;

    draw+=1;
    return dice(dice_1,dice_2,dice_3,dice_4,dice_5,score+dice_2,draw);
  }else if(dice_3==6){
    cout<<"first dices: "<<dice_1<<endl<<"second dices: "<<dice_2<<endl<<"third dices: "<<dice_3<<endl<<"fourth dices: "<<dice_4<<endl<<"firth dices: "<<dice_5<<endl;
    cout<<score<<endl;
    dice_3=rand()%6+1;
    draw+=1;
    return dice(dice_1,dice_2,dice_3,dice_4,dice_5,score+dice_3,draw);
  }else if(dice_4==6){
    cout<<"first dices: "<<dice_1<<endl<<"second dices: "<<dice_2<<endl<<"third dices: "<<dice_3<<endl<<"fourth dices: "<<dice_4<<endl<<"firth dices: "<<dice_5<<endl;
    cout<<score<<endl;

    draw+=1;
    return dice(dice_1,dice_2,dice_3,dice_4,dice_5,score+dice_4,draw);
  }else if(dice_5==6){
    cout<<"first dices: "<<dice_1<<endl<<"second dices: "<<dice_2<<endl<<"third dices: "<<dice_3<<endl<<"fourth dices: "<<dice_4<<endl<<"firth dices: "<<dice_5<<endl;
    cout<<score<<endl;
    dice_5=rand()%6+1;
    draw+=1;
    return dice(dice_1,dice_2,dice_3,dice_4,dice_5,score+dice_5,draw);
  }else{
    return score;
  }
}
long long tungfaaseon(short dice_1,short dice_2, short dice_3,short dice_4,short dice_5, long long score,long long& draw){
  short Adice[]={dice_1,dice_2,dice_3,dice_4,dice_5};
  cout<<"-------------------------------"<<endl<<"You have throw "<<draw<<"times of dice"<<endl;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(Adice[i]==Adice[j] and j!=i){
        for(int k=0;k<5;k++){
          if(Adice[i]==Adice[k] and i!=k and j!=k){
            cout<<"Three pairs!"<<endl;
            Adice[i]=rand()%6+1;
            Adice[j]=rand()%6+1;
            Adice[k]=rand()%6+1;
            cout<<"first dices: "<<Adice[0]<<endl<<"second dices: "<<Adice[1]<<endl<<"third dices: "<<Adice[2]<<endl<<"fourth dices: "<<Adice[3]<<endl<<"firth dices: "<<Adice[4]<<endl;
            draw+=1;
            return tungfaaseon(Adice[0],Adice[1],Adice[2],Adice[3],Adice[4],score+Adice[i]+Adice[j]+Adice[k],draw);
          }
        }
        cout<<"Two pairs!"<<endl;
        Adice[i]=rand()%6+1;
        Adice[j]=rand()%6+1;
        draw+=1;
        cout<<"first dices: "<<Adice[0]<<endl<<"second dices: "<<Adice[1]<<endl<<"third dices: "<<Adice[2]<<endl<<"fourth dices: "<<Adice[3]<<endl<<"firth dices: "<<Adice[4]<<endl;
        return tungfaaseon(Adice[0],Adice[1],Adice[2],Adice[3],Adice[4],score+Adice[i]+Adice[j],draw);
      }
    }
  }
  if((Adice[0]<Adice[1] and Adice[1]<Adice[2] and Adice[2]<Adice[3] and Adice[3]<Adice[4] and Adice[4]<Adice[5])or (Adice[0]>Adice[1] and Adice[1]>Adice[2] and Adice[2]>Adice[3] and Adice[3]>Adice[4] and Adice[4]>Adice[5])){
    cout<<"Seon!"<<endl;
    cout<<"You are really lucky! What is your next lucky secret?"<<endl;
    char lucky;
    cin>>lucky;
    (int)lucky;
    Adice[0]=rand()%6+1;
    Adice[1]=rand()%6+1;
    Adice[2]=rand()%6+1;
    Adice[3]=rand()%6+1;
    Adice[4]=rand()%6+1;
    draw+=1;
    return tungfaaseon(Adice[0],Adice[1],Adice[2],Adice[3],Adice[4],score+Adice[0]+Adice[1]+Adice[2]+Adice[3]+Adice[4],draw);
  }
  return score;
}
void initial(short dices[], long long& score, char lucky, long long& draw){
  (int)lucky;
  dices[0]=rand()%6+1;
  dices[1]=rand()%6+1;
  dices[2]=rand()%6+1;
  dices[3]=rand()%6+1;
  dices[4]=rand()%6+1;
  score+=(dices[0]+dices[1]+dices[2]+dices[3]+dices[4]);
  draw+=1;
  cout<<"first dices: "<<dices[0]<<endl<<"second dices: "<<dices[1]<<endl<<"third dices: "<<dices[2]<<endl<<"fourth dices: "<<dices[3]<<endl<<"firth dices: "<<dices[4]<<endl;
  cout<<score<<endl;
};
int main(){
  int no_of_player;
  cout<<"How many Player?"<<endl;
  cin>>no_of_player;
  while(no_of_player>10){
    cout<<"Too many players! Jailer will catch you!"<<endl;
    cout<<"How many Player?"<<endl;
    cin>>no_of_player;
  }
  srand(time(NULL));
  cout<<"Rule:"<<endl;
  cout<<"If you draw 6, you can draw one more times"<<endl;
  cout<<"If you have two dice equal, you can draw one more"<<endl;
  cout<<"If you have three dice equal, you can draw one more"<<endl;
  cout<<"If you have accending order or decending order of terms, you can draw one more"<<endl;
  short P1_dices[5];
  long long P1_score[10]={0,0,0,0,0,0,0,0,0,0};
  long long P_draw_time[10]={0,0,0,0,0,0,0,0,0,0};
  char lucky;
  for(int i=0;i<no_of_player;i++){
      cout<<"What is your lucky character?"<<endl;
      cin>>lucky;
      initial(P1_dices,P1_score[i],lucky,P_draw_time[i]);
      P1_score[i]=dice(P1_dices[0],P1_dices[1],P1_dices[2],P1_dices[3],P1_dices[4],P1_score[i],P_draw_time[i]);
      P1_score[i]=tungfaaseon(P1_dices[0],P1_dices[1],P1_dices[2],P1_dices[3],P1_dices[4],P1_score[i],P_draw_time[i]);
      P1_score[i]=dice(P1_dices[0],P1_dices[1],P1_dices[2],P1_dices[3],P1_dices[4],P1_score[i],P_draw_time[i]);
      cout<<"P"<<i+1<<"'s score"<<P1_score[i]<<endl;
  }
  long long winner_score=P1_score[0];
  short winner=0;
  for(short j=0;j<no_of_player;j++){
    if(winner_score<P1_score[j]){
      winner_score=P1_score[j];
      winner=j;
    }
  }
  for (short j=0; j<no_of_player;j++){
    if(P1_score[j]<10){
      winner_score=P1_score[j];
      winner=j;
      for(short k=0; k<no_of_player;k++){
        if (P1_score[k]<P1_score[j]){
          winner_score=P1_score[k];
          winner=k;
        }
      }
    }
  }
  for(short j=0;j<no_of_player;j++){
    cout<<'P'<<j+1<<"'s score is"<<P1_score[j]<<endl;
  }
  cout<<"P"<<winner+1<<" won! so another player need to give him banana for prize!"<<endl;

  return 0;
}
