#include<iostream>
#include<string>
using namespace std;
void initialize(int board[][6],int player){
  for (int i=0;i<6;i++){
    for (int j=0;j<6;j++){
      board[i][j]=0;
    }
  }
};
int check_winner(int board[][6],int player, int score[]){
  cout<<"checking player:"<<player<<endl;
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      if(board[i][j]==board[i+1][j]&&board[i+1][j]==board[i+2][j]&&board[i+2][j]==player){
        cout<<"horizontal"<<endl;
        score[player-1]+=4;
        break;
      }else if(board[i][j]==board[i][j+1]&&board[i][j+1]==board[i][j+2]&&board[i][j+2]==player){
        cout<<"vertical"<<endl;
        score[player-1]+=4;
        break;
      }else if(board[i][j]==board[i+1][j+1]&&board[i+1][j+1]==board[i+2][j+2]&&board[i+2][j+2]==player){
        cout<<"skew"<<endl;
        score[player-1]+=4;
        break;
      }
    }
  }

}
void input_choice(int board[][6],int player){
  string choice;
  cin>>choice;
  choice[0]-='a';
  choice[1]-=48;
  int x=(int)choice[0],y=(int)choice[1];
  if (board[x][y]==0){
    board[x][y]=player;
  }else if (board[x][y]!=player){
    cout<<"you cannot modify your friend's choose!"<<endl;
  }else if(board[x][y]==player){
    cout<<"World is irereversable!"<<endl;
  }
}
int main(){
  int board[6][6];
  int player;
  cout<<"How many player?"<<endl;
  cin>>player;
  player+=1;
  int score[player];
  for(int i=0;i<player;i++){
    score[i]=0;
  }
  int turn=1;
  initialize(board,player);
  char x_axis='a';
  while(true){
    for(int j=0;j<7;j++){
      for(int i=0;i<7;i++){
        if(i==0&&j==0){
          cout<<'\t';
        }else if(i==0){
          cout<<j-1<<'\t';
        }else if(j==0){
          cout<<x_axis<<'\t';
          x_axis+=1;
        }else{
          cout<<board[i-1][j-1]<<"\t";
        }
      }
      cout<<endl;
      x_axis='a';
    }
    cout<<"Now player:"<<turn<<endl;
    input_choice(board,turn);
    check_winner(board,turn,score);
    for(int i=0;i<player;i++){
      if(score[i]==4){
        cout<<"Player "<<i+1<<" win!"<<endl;
        return 0;
      }
    };
    if(turn==player){
      turn-=(player-1);
    }else if (turn<=player){
      turn+=1;
    }
  }
  return 0;
}
