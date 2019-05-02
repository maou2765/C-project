#include<iostream>
#include<stdlib.h>
using namespace std;
class Competitors{
  private:
    short x;
    short y;
    short score;
    bool out;i(x,y)
  public:
    Competitors(short init_x, short init_y){
      set_position(init_x,init_y);
      set_score(0);
      out=false;
    };
    int get_score() const{
      return score;
    };
    short get_x() const{
      return x;
    };
    short get_y() const{
      return y;
    };
    bool get_out() const{
      return out;
    }
    void set_score(int new_score){
      score=new_score;
    };
    void set_position(short init_x, short init_y){
      if(init_x<=14 and init_x>=0 and init_y<=14 and init_y>=0){
        x=init_x;
        y=init_y;
      };
    };
    void kaccha(){
      short prob=rand()%6+1;
      if (prob==6){
        set_score(score+2);
      }else if(prob<6 and prob>3){
        cout<<"Nothing"<<endl;
      }else if(prob<4){
        set_score(score+1);
      }
    }
    void move(char direction){
      if(direction=='a'){
        set_position(x-1,y);
        kaccha();
      }else if(direction=='d'){
        set_position(x+1,y);
        kaccha();
      }else if(direction=='w'){
        set_position(x,y+1);
        kaccha();
      }else if(direction=='s'){
        set_position(x,y-1);
        kaccha();
      }else{
        cout<<"Where do you want to go?"<<endl;
      };
    };
    void move(int direction){
      if(direction==0){
        set_position(x-1,y);
        kaccha();
      }else if(direction==1){
        set_position(x+1,y);
        kaccha();
      }else if(direction==2){
        set_position(x,y+1);
        kaccha();
      }else if(direction==3){
        set_position(x,y-1);
        kaccha();
      }
    }
};
class Obstacles{
  private:
    short x;
    short y;
    char name;
  public:
    Obstacles(){
      x=rand()%15;
      y=rand()%15;
      if (rand()%2){
        name='O';
      }else{
        name='t';
      }
    };
    short get_x() const{
      return x;
    };
    short get_y() const{
      return y;
    };
    char get_name() const{
      return name;
    }
};
struct grid{
  char content;
};
void initializer(grid map[15][15],Obstacles* list[10]){
  srand(time(NULL));
  for (int i=0;i<10;i++){
    map[list[i]->get_x()][list[i]->get_y()].content=list[i]->get_name();
  }
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      if(map[i][j].content!='O'or map[i][j].content!='t'){
        map[i][j].content='_';
      }
    }
  }
}
void map_viewer(grid map[15][15],short player_position[],short El_position[]){
  for(int j=0;j<15;j++){
    for(int i=0;i<15;i++){
      if (player_position[0]==i and player_position[1]==j){
        cout<<'P';
      }else if(El_position[0]==i and El_position[1]==j){
        cout<<'E';
      }else{
        cout<<map[i][j].content;
      }
    }
    cout<<endl;
  }
}
int main(){
  grid map[15][15];
  Obstacles* list[10];
  for(int j=0;j<10;j++){
    list[j]=new Obstacles;
  }
  initializer(map,list);
  Competitors player(0,0);
  Competitors El_macho(14,14);
  short player_position[]={player.get_x(),player.get_y()};
  short El_position[]={El_macho.get_x(),El_macho.get_y()};
  char direction;
  map_viewer(map,player_position,El_position);
  cin>>direction;
  player.move(direction);
  player_position[0]=player.get_x();
  player_position[1]=player.get_y();
  El_macho.move(rand()%4);
  El_position[0]=player.get_x();
  El_position[1]=player.get_y();
  for(int i=0;i<14;i++){
    map_viewer(map,player_position,El_position);
    cin>>direction;
    player.move(direction);
    player_position[0]=player.get_x();
    player_position[1]=player.get_y();
    cout<<player.get_score()<<endl;
    El_macho.move(rand()%4);
    El_position[0]=El_macho.get_x();
    El_position[1]=El_macho.get_y();
    cout<<El_macho.get_score()<<endl;
    if(player_position[0]==El_position[0] and player_position[1]==El_position[1]){
      cout<<"Crashed! You lose"<<endl;
      return 0;
    }else if(player.get_out()){
      cout<<"You lose"<<endl;
      return 0;
    }else if(El_macho.get_out()){
      cout<<"You win"<<endl;
      return 0;
    }
  };
  if(player.get_score()>El_macho.get_score()){
    cout<<"You win"<<endl;

    return 0;
  }else{
    cout<<"You lose";
    return 0;
  }
}
