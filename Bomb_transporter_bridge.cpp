#include<iostream>
#include<string>
#include <boost/algorithm/string.hpp>
using namespace std;
const int move_mode[]={1,2,3,4,5,6,7,8,9,10};
void one_expert_left(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie,bool inverse){
  left_expert+=1;
  right_expert-=1;
  if (inverse==1){
    left_expert-=1;
    right_expert+=1;
  }
}

void two_expert_left(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie,bool inverse){
  left_expert+=2;
  right_expert-=2;
  if (inverse==1){
    left_expert-=2;
    right_expert+=2;
  }
}

void one_newbie_left(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie, bool inverse){
  left_newbie+=1;
  right_newbie-=1;
  if (inverse==1){
    left_newbie-=1;
    right_newbie+=1;
  }
}

void two_newbie_left(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie,bool inverse){
  left_newbie+=2;
  right_newbie-=2;
  if (inverse==1){
    left_newbie-=2;
    right_newbie+=2;
  }
}

void one_newbie_one_expert_left(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie,bool inverse){
  left_expert+=1;
  right_expert-=1;
  left_newbie+=1;
  right_newbie-=1;
  if (inverse==1){
    left_expert-=1;
    right_expert+=1;
    left_newbie-=1;
    right_newbie+=1;
  }
}

void one_newbie_back(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie,bool inverse){
  left_newbie-=1;
  right_newbie+=1;
  if(inverse==1){
    left_newbie+=1;
    right_newbie-=1;
  }
}

void one_expert_back(int& left_expert,int& right_expert, int& left_newbie, int& right_newbie,bool inverse){
  left_expert-=1;
  right_expert+=1;
  if(inverse==1){
    left_expert+=1;
    right_expert-=1;
  }
}

int main(){
  int level=6,playagain=0;
  string mode;
  int status[]={0,3,0,3};
  int banana=0;
  int previous_move,move;
  string next;
  cout<<"Boss: hey! Here are chances for you to higher your performance!"<<endl;
  cout<<"I need to transport some bomb to another side of this building"<<endl;
  cout<<"But I have restructure the company and let some of the expert resigned themselve."<<endl;
  cout<<"So I don't have enough expert."<<endl;
  cout<<"If you can transport all bombs to the right side of the building, I will give you two banana and those banana can keep the newbies calm."<<endl;
  cout<<"Of course, I will not give you banana now,since I don't like pay to someone that has not finished their work"<<endl;
  cout<<"For the reminder, When there are more newbie than expert in one side, they will fight and the bomb will booms!"<<endl;
  cout<<"Let me ask you a question, Who you are? Son of the Emperor? or just a small potato?(SE for son of the emperor, SP for small potato)"<<endl;
  cin>>mode;
  boost::to_upper(mode);
  while(true){
      cout<<"Latest situation:"<<endl;
      cout<<"Experts in left side: "<<status[0]<<" while expert in right side: "<<status[1]<<endl;
      cout<<"Newbies in left side: "<<status[2]<<" while newbies in right side: "<<status[3]<<endl;
      if (mode=="SE"){
        string tmp_banana;
        cout<<"How many banana you want?"<<endl;
        cin>>tmp_banana;
        if (tmp_banana.empty()!=true){
          int x=atoi(tmp_banana.c_str());
          banana+=x;
        };
      };
      if((status[0]+status[2])==level){
        cout<<"All Bombs is transported!"<<endl;
        if(mode=="SE"){
          cout<<"How many bombs transported?"<<endl;
          cin>>level;
        };
        if (level>=10000){
          cout<<"Boss: Good jobs! However, You work too slow so my sister is married with a clever and handsome man!"<<endl;
        };
        cout<<"Your boss has give you two banana for prize and he give you two more minions and bomb for the transport mission.";
        cout<<"One of the minions is a expert while another one is a newbies."<<endl;
        cout<<"Work again?";
        cin>>next;
        boost::to_upper(next);
        if(next=="Y"){
          cout<<"Boss: Good boy! After you have transport 10000 bombs to the right side, I will marry mu cute sister Umaru to you!";
          level+=2;
          status[1]=status[0]+1;
          status[0]=0;
          status[3]=status[2]+1;
          status[2]=0;
          banana+=2;
          continue;
        }else{
          string things;
          cout<<"Things you want to said to the boss:";
          cin>>things;
          cout<<"You:"<<things;
          break;
        }
      };

      cout<<"How do you move?"<<endl;
      cout<<"1 for move one expert to left, 2 for move two expert to left, 3 for move one newbie to left, 4 for move two newbies to left, 5 for move one newbie one expert to the left side"<<endl;
      cin>>move;
      if(move==1){
        one_expert_left(status[0],status[1],status[2],status[3],0);
      }else if(move==2){
        two_expert_left(status[0],status[1],status[2],status[3],0);
      }else if(move==3){
        one_newbie_left(status[0],status[1],status[2],status[3],0);
      }else if(move==4){
        two_newbie_left(status[0],status[1],status[2],status[3],0);
      }else if(move==5){
        one_newbie_one_expert_left(status[0],status[1],status[2],status[3],0);
      }else{
        cout<<"1 for move one expert to left, 2 for move two expert to left, 3 for move one newbie to left, 4 for move two newbies to left, 5 for move one newbie one expert to the left side"<<endl;
      }
      if((status[0]+status[2])==level){
        cout<<"All Bombs is transported!"<<endl;
        if (level>=10000){
          cout<<"Boss: Good jobs! However, You work too slow so my sister is married with a clever and handsome man!"<<endl;
        };
        cout<<"Your boss has give you two banana for prize and he give you two more minions and bomb for the transport mission.";
        cout<<"One of the minions is a expert while another one is a newbies."<<endl;
        cout<<"Work again?";
        cin>>next;
        boost::to_upper(next);
        if(next=="Y"){
          cout<<"Boss: Good boy! After you have transport 100000000 bombs to the right side, I will marry mu cute sister Umaru to you!";
          level+=2;
          status[1]=status[0]+1;
          status[0]=0;
          status[3]=status[2]+1;
          status[2]=0;
          banana+=2;
          continue;
        }else{
          string things;
          cout<<"Things you want to said to the boss:";
          cin>>things;
          cout<<"You:"<<things;
          break;
        }
      };
      cout<<"Who should take back the torch to right side? 1 for a expert, 2 for a newbie"<<endl;
      cin>>move;
      if(move==1){
        if(status[0]>0){
          one_expert_back(status[0],status[1],status[2],status[3],0);
        }
      }else{
        if(status[2]>0){
          one_newbie_back(status[0],status[1],status[2],status[3],0);
        }
      }
      if((status[2]>status[0] and status[0]!=0) or (status[3]>status[1] and status[1]!=0)) {
        banana-=1;
        cout<<"You now have "<<banana<<" banana"<<endl;
        if(banana<0){
          cout<<"Booms! Game over"<<endl;
          break;
        };
      };
    }
}
