#include<iostream>
#include<cstdlib>
#include<cctype>
#include<time.h>
using namespace std;
struct minions{
  bool scout;
  bool jailer;
  bool player;
  bool empty;
};
struct point{
  int x;
  int previous_x;
  int y;
  int previous_y;
};
void initialize(minions map[15][15], point minion_list[], short& minions_no){
  for (int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      map[i][j].empty=true;
      map[i][j].player=false;
      map[i][j].jailer=false;
      map[i][j].scout=false;
    }
  };
  for(int i=0;i<225;i++){
    minion_list[i].x=16;
    minion_list[i].previous_x=minion_list[i].x;
    minion_list[i].y=16;
    minion_list[i].previous_y=minion_list[i].y;
  }
  map[0][0].player=true;
  map[0][0].empty=false;
  srand(time(NULL));
  int x=rand()%15;
  int y=rand()%15;
  map[x][y].empty=false;
  map[x][y].jailer=true;
  minion_list[0].x=x;
  minion_list[0].previous_x=x;
  minion_list[0].y=y;
  minion_list[0].previous_y=y;
  minions_no+=1;
  for(int i=0; i<15;i++){
    for(int j=0;j<15;j++){
      if(map[i][j].jailer)
      cout<<'j';
      else if(map[i][j].empty)
      cout<<'-';
      else if(map[i][j].player)
      cout<<'P';
    }
    cout<<endl;
  }
}
void move(short mode, int& x, int& y){
  switch (mode){
    case 1:
      x+=1;
      break;
    case 2:
      y+=1;
      break;
    case 3:
      x-=1;
      break;
    case 4:
      y-=1;
      break;
    case 5:
      x+=1;
      y+=1;
      break;
    case 6:
      x+=1;
      y-=1;
      break;
    case 7:
      x-=1;
      y+=1;
      break;
    case 8:
      x-=1;
      y-=1;
      break;
  }
}
void air_strike(minions map[15][15], point minion_list[],short& minions_no){
  for(int i=0;i<minions_no;i++){
    map[minion_list[i].x][minion_list[i].y].empty=true;
    map[minion_list[i].x][minion_list[i].y].jailer=false;
    minion_list[i].x=16;
    minion_list[i].y=26;
  }
  minions_no=0;
}
void update(minions map[15][15], point minion_list[],point& player_position, short& minions_no){
  short direction,skill;
  cin>>direction;
  move(direction,player_position.x,player_position.y);
  if(player_position.x>14){
    player_position.x=14;
  }else if(player_position.y>14){
    player_position.y=14;
  }
  map[player_position.previous_x][player_position.previous_y].empty=true;
  map[player_position.previous_x][player_position.previous_y].player=false;
  map[player_position.x][player_position.y].empty=false;
  map[player_position.x][player_position.y].player=true;
  player_position.previous_x=player_position.x;
  player_position.previous_y=player_position.y;
  cout<<"Call air strike? 1 to call"<<endl;
  cin>>skill;
  if(skill==1){
    air_strike(map,minion_list,minions_no);
  }
  cout<<"Player's turn end"<<endl;
  while (true){
    minion_list[minions_no].x=rand()%13;
    minion_list[minions_no].y=rand()%13;
    minion_list[minions_no].previous_x=minion_list[minions_no].x;
    minion_list[minions_no].previous_y=minion_list[minions_no].y;
    if(map[minion_list[minions_no].x][minion_list[minions_no].y].empty==true){
      map[minion_list[minions_no].x][minion_list[minions_no].y].empty=false;
      map[minion_list[minions_no].x][minion_list[minions_no].y].jailer=true;
      break;
    }
  }
  minions_no+=1;
  cout<<"enermy's reinforcement is arrived!"<<endl;
  cout<<"there is "<<minions_no<<" of them"<<endl;
  bool movable=false;
  for(int i=0;i<minions_no;i++){
    while (movable==false){
      move(rand()%8+1,minion_list[i].x,minion_list[i].y);
      for(int j=0;j<minions_no;j++){
        if(minion_list[i].x==minion_list[j].x and minion_list[i].y==minion_list[j].y and j!=i){
          minion_list[i].x=minion_list[i].previous_x;
          minion_list[i].y=minion_list[i].previous_y;
          cout<<"dest not empty"<<endl;
        }else if(j==(minions_no-1)){
          movable=true;
        }
      }
    }
    while (true){
      if (minion_list[i].x>14 or minion_list[i].x<0){
        minion_list[i].x=minion_list[i].previous_x;
        minion_list[i].y=minion_list[i].previous_y;
        move(rand()%8+1,minion_list[i].x,minion_list[i].y);
      }else if(minion_list[i].y>14 or minion_list[i].y<0){
        minion_list[i].x=minion_list[i].previous_x;
        minion_list[i].y=minion_list[i].previous_y;
        move(rand()%8+1,minion_list[i].x,minion_list[i].y);
      }else{
        break;
      }
    }
    cout<<minion_list[i].x<<"\t"<<minion_list[i].y<<endl;
    map[minion_list[i].previous_x][minion_list[i].previous_y].empty=true;
    map[minion_list[i].previous_x][minion_list[i].previous_y].jailer=false;
    map[minion_list[i].x][minion_list[i].y].empty=false;
    map[minion_list[i].x][minion_list[i].y].jailer=true;
    minion_list[i].previous_x=minion_list[i].x;
    minion_list[i].previous_y=minion_list[i].y;
    if(minion_list[i].x==player_position.x and minion_list[i].y==player_position.y){
      map[player_position.x][player_position.y].empty=true;
      map[player_position.x][player_position.y].player=false;
      break;
    }
    movable=false;
  }

  for(int i=0; i<15;i++){
    for(int j=0;j<15;j++){
      if(map[i][j].jailer)
      cout<<'j';
      else if(map[i][j].empty)
      cout<<'-';
      else if(map[i][j].player)
      cout<<'P';
    }
    cout<<endl;
  }
}

int main(){
  minions map[15][15];
  point minion_list[225];
  point player_position={0,0,0,0};
  short minions_no=0;
  initialize(map, minion_list, minions_no);
  for(;;){
    update(map,minion_list,player_position, minions_no);
    if(map[player_position.x][player_position.y].player==false){
      cout<<"catched"<<endl;
      cout<<"You lose!"<<endl;
      return 0;
    }
    if(map[14][14].player==true){
      cout<<"you win"<<endl;
      return 0;
    }
  }
}
