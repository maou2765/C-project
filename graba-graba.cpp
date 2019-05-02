#include<iostream>
#include<stdlib.h>
using namespace std;
struct Weapon{
  short id;
  short firepower;
  Weapon* next;
};
struct Minion{
  string name;
  short x;
  short y;
  Weapon* weapon_box;
};
struct Grid{
  Weapon* weapon;
};
void initializer(Grid grid[15][15], Minion minions[]){
  srand(time(NULL));
  short prob=0;
  for(short i=0;i<15;i++){
    for(short j=0;j<15;j++){
      prob=rand()%55+1;
      grid[i][j].weapon=new Weapon;
      if (prob==55){
          grid[i][j].weapon->id=10;
          grid[i][j].weapon->firepower=10;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=54 and prob>=53){
          grid[i][j].weapon->id=9;
          grid[i][j].weapon->firepower=9;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=52 and prob>=50){
          grid[i][j].weapon->id=8;
          grid[i][j].weapon->firepower=8;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=49 and prob>=46){
          grid[i][j].weapon->id=7;
          grid[i][j].weapon->firepower=7;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=45 and prob>=41){
          grid[i][j].weapon->id=6;
          grid[i][j].weapon->firepower=6;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=40 and prob>=35){
          grid[i][j].weapon->id=5;
          grid[i][j].weapon->firepower=5;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=34 and prob>=28){
          grid[i][j].weapon->id=4;
          grid[i][j].weapon->firepower=4;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=27 and prob>=20){
          grid[i][j].weapon->id=3;
          grid[i][j].weapon->firepower=3;
          grid[i][j].weapon->next=nullptr;
        }else if(prob<=19 and prob>=11){
          grid[i][j].weapon->id=2;
          grid[i][j].weapon->firepower=2;
          grid[i][j].weapon->next=nullptr;
        }else{
          grid[i][j].weapon->id=1;
          grid[i][j].weapon->firepower=1;
          grid[i][j].weapon->next=nullptr;
        };
    }
  }
  minions[0].x=0;
  minions[0].y=0;
  cout<<"What is your name?"<<endl;
  cin>>minions[0].name;
  minions[1].x=0;
  minions[1].y=14;
  minions[1].name="Kevin";
  minions[2].x=14;
  minions[2].y=0;
  minions[2].name="Carl";
}
void Pmove(short mode, short& x, short& y){
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
short smart_move(Grid grid[15][15],short ori_x,short ori_y){
  short x=ori_x;
  short tmp_x=ori_x;
  short y=ori_y;
  short tmp_y=ori_y;
  short tmp_direction=1;
  for(short i=1;i<=8;i++){
    x=ori_x;
    y=ori_y;
    switch(i){
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
   cout<<"smart"<<i<<endl;
   if(x<0){
     x=0;
   }else if(x>14){
    x=14;
   }
   if(y<0){
     y=0;
   }else if(y>14){
     y=14;
   }
   if(grid[x][y].weapon->firepower>=grid[tmp_x][tmp_y].weapon->firepower){
     tmp_direction=i;
     tmp_x=x;
     tmp_y=y;
   }
   if(tmp_x==ori_x and tmp_y==ori_y){
     tmp_direction=rand()%8+1;
   }
  }
  return tmp_direction;
}
/*
void show(Grid grid[15][15],short ori_x,short ori_y){
  short x=ori_x;
  short tmp_x=ori_x;
  short y=ori_y;
  short tmp_y=ori_y;
  short tmp_direction=1;
  for(short i=1;i<=8;i++){
    x=ori_x;
    y=ori_y;
    switch(i){
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
  if(x<0){
     x=0;
   }else if(x>14){
    x=14;
   }
   if(y<0){
     y=0;
   }else if(y>14){
     y=14;
   }
   cout<<i<<' '<<grid[x][y].weapon->firepower<<endl;
 }
}*/
Weapon* last_node(Weapon* init){
  Weapon* pW;
  for(Weapon* p=init;p;p=p->next){pW=p;};
  return pW;
}
int main(){
  Grid map[15][15];
  Minion minions[3];
  initializer(map,minions);
  short direction=0;
  minions[0].weapon_box=map[minions[0].x][minions[0].y].weapon;
  minions[0].weapon_box->next=nullptr;
  minions[1].weapon_box=map[minions[1].x][minions[1].y].weapon;
  minions[1].weapon_box->next=nullptr;
  minions[2].weapon_box=map[minions[2].x][minions[2].y].weapon;
  minions[2].weapon_box->next=nullptr;
  for(int i=0;i<15;i++){
    for(int j=0;j<3;j++){
      cout<<i<<j<<endl;
        cout<<"x: "<<minions[j].x<<" y: "<<minions[j].y;
        cout<<" id: "<<map[minions[j].x][minions[j].y].weapon->id;
        cout<<" with firepower "<<map[minions[j].x][minions[j].y].weapon->firepower<<endl;
        if(j==0){
          //show(map,minions[j].x,minions[j].y);
          cin>>direction;
        }else if(j==2){
          direction=rand()%8+1;
        }else{
          direction=smart_move(map,minions[j].x,minions[j].y);
        }
        cout<<minions[j].name<<" moving"<<endl;
        Pmove(direction,minions[j].x,minions[j].y);
        if(minions[j].x<0){
          minions[j].x=0;
        }else if(minions[j].x>14){
          minions[j].x=14;
        }
        if(minions[j].y<0){
          minions[j].y=0;
        }else if(minions[j].y>14){
          minions[j].y=14;
        }
        Weapon* last=last_node(minions[j].weapon_box);
        if(last!=map[minions[j].x][minions[j].y].weapon){
          last->next=map[minions[j].x][minions[j].y].weapon;
          cout<<"x: "<<minions[j].x<<" y: "<<minions[j].y<<' '<<last->next->id<<" with firepower "<<last->next->firepower<<endl;
          last->next->next=nullptr;
        }else{
          last->next=nullptr;
          cout<<"x: "<<minions[j].x<<" y: "<<minions[j].y<<' '<<last->id<<" with firepower "<<last->firepower<<endl;
        }
        }
      }
      int score=0;
      for(short j=0;j<3;j++){
        for(Weapon* p=minions[j].weapon_box;p;p=p->next){
          cout<<"id: "<<p->id<<" firepower: "<<p->firepower<<endl;
          score+=p->firepower;
        };
        cout<<minions[j].name<<"'s score is "<<score<<endl;
      }
    return 0;
}
