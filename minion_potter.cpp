#include<iostream>
#include<stdlib.h>
using namespace std;
struct minion{
  bool empty;
  bool bomb;
  bool banana;
  bool player;
};
struct point{
  short x;
  short y;
  bool banana;
};
struct play{
  short x;
  short y;
  int score;
};
void initialize(minion map[][10], point item[],play Plist[]){
  srand(time(NULL));
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      map[i][j].empty=true;
      map[i][j].bomb=false;
      map[i][j].banana=false;
      map[i][j].player=false;
    }
  }
  for(int i=0;i<100;i++){
    if(rand()%2){
      item[i].banana=true;
    }
    item[i].x=rand()%10;
    item[i].y=0-i;
    if (item[i].y>=0){
      map[item[i].x][item[i].y].empty=false;
      if(item[i].banana){
        map[item[i].x][item[i].y].banana=true;
      }else if(item[i].banana==false){
        map[item[i].x][item[i].y].bomb=true;
      }
    }
  }
  for(int i=0;i<2;i++){
    while (true){
      Plist[i].x=rand()%10;
      Plist[i].y=9;
      if(map[Plist[i].x][Plist[i].y].empty==true){
        map[Plist[i].x][Plist[i].y].player=true;
        map[Plist[i].x][Plist[i].y].empty=false;
        Plist[i].score=0;
        break;
      }else{
        Plist[i].x=rand()%10;
      }
    }
  }
}
void Imove(minion map[][10], point item[],play Plist[]){
  for(int j=0;j<100;j++){
    item[j].y+=1;
    if(item[j].y>=0){
      if(item[j].banana==false){
        if(item[j].y==0){
          map[item[j].x][0].bomb=true;
          map[item[j].x][0].empty=false;
        }
        if (item[j].y<9 and item[j].y>0){
          map[item[j].x][item[j].y-1].bomb=false;
          map[item[j].x][item[j].y-1].empty=true;
          map[item[j].x][item[j].y].bomb=true;
          map[item[j].x][item[j].y].empty=false;
        }else if(item[j].y==9){
          for(int i=0;i<2;i++){
            if (item[j].x==Plist[i].x and item[j].y==Plist[i].y){
              Plist[i].score-=1;
            }else{
              map[item[j].x][item[j].y-1].empty=true;
            }
          }
          map[item[j].x][item[j].y-1].bomb=false;
          item[j].x=rand()%9;
          item[j].y=rand()%9-10;
        }
      }else if(item[j].banana==true){
        if(item[j].y==0){
          map[item[j].x][item[j].y].banana=true;
          map[item[j].x][item[j].y].empty=false;
        }
        if (item[j].y<9 and item[j].y>0){
          map[item[j].x][item[j].y-1].banana=false;
          map[item[j].x][item[j].y-1].empty=true;
          map[item[j].x][item[j].y].banana=true;
          map[item[j].x][item[j].y].empty=false;
        }else if(item[j].y==9){
          for(int i=0;i<2;i++){
            if (item[j].x==Plist[i].x and item[j].y==Plist[i].y){
              Plist[i].score+=1;
            }else{
              map[item[j].x][item[j].y-1].empty=true;
            }
          }
          map[item[j].x][item[j].y-1].banana=false;
          item[j].x=rand()%9;
          item[j].y=rand()%9-10;
        }
      }
    }
  }
}
void Pmove(minion map[][10], short& Player,play Plist[]){
  char direction;
  cout<<"Left or right (1 is right, 2 is left)"<<endl;
  cin>>direction;
  map[Player][9].empty=true;
  map[Player][9].player=false;
  if(direction=='a'){
    Player+=1;
  }else if(direction=='d'){
    Player-=1;
  };
  if(Player<0){
    Player=0;
  }else if(Player>9){
    Player=9;
  };
  map[Player][9].empty=false;
  map[Player][9].player=true;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if (Plist[i].x==Plist[j].x and i!=j){
        Plist[i].score=-1;
      }
    }
  }
  map[Player][9].empty=false;
  map[Player][9].player=true;
}
void printmap(minion map[10][10]){
  for(int j=0;j<10;j++){
    for(int i=0;i<10;i++){
      if (map[i][j].empty==true){
        cout<<'_';
      }else if(map[i][j].bomb==true){
        cout<<'b';
      }else if(map[i][j].banana==true){
        cout<<'|';
      }else if(map[i][j].player==true){
        cout<<'P';
      }
    }
    cout<<endl;
  }
}
int main(){
  minion map[10][10];
  short no_of_player;
  cout<<"How many players? maximun 2"<<endl;
  cin>>no_of_player;
  play Plist[no_of_player];
  point item[100];
  initialize(map,item,Plist);
  for(;;){
    Imove(map,item,Plist);
    printmap(map);
    for(int i=0;i<2;i++){
      Pmove(map,Plist[i].x,Plist);
      printmap(map);
      cout<<"Player"<<i<<"'s score:'"<<Plist[i].score<<endl;
      if(Plist[i].score<0){
        cout<<"Player"<<i<<" lose"<<endl;
        return 0;
      }
    }
  }
  return 0;
}
