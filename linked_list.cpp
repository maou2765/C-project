#include<iostream>
using namespace std;
struct Node{
  char data;
  Node* next;
};
Node* node_create(char data){
  Node* p= new Node;
  p->data=data;
  p->next=nullptr;
  return p;
};
Node* node_search(char data,Node* init_node){
  for(Node* p=init_node;p;p=p->next){
    if(p->data==data){
      return p;
    };
  }
  return nullptr;
};
void node_insert(char data,Node*& init_node,Node*& end_node){
  Node* p=node_create(data);
  if(init_node==nullptr){
    p->next=end_node;
  }else{
    init_node->next=p;
    p->next=end_node;
  }
}
void node_remove(Node*& start_node,Node*& end_node){
  Node* tmp=start_node->next;
  tmp=tmp->next;
  while(start_node->next!=end_node and tmp!=nullptr){
    delete start_node->next;
    start_node->next=tmp;
    tmp=tmp->next;
  }
}
void node_remove_data(char data,Node* start_node){
  Node* node_2del=node_search(data,start_node);
  Node* tmp=node_2del->next;
  for(Node* p=start_node;p;p=p->next){
    if(p->next==node_2del){
      node_remove(p,tmp);
      /*
      delete p->next;
      p->next=tmp;
      break;*/
    };
  }
};
int list_length(Node* init_node){
  int length=0;
  for(Node* p=init_node;p;p=p->next){
    length++;
  }
  return length;
}
void list_print(Node* init_node){
  for(Node* p=init_node;p;p=p->next){
    cout<<p->data;
  }
  cout<<endl;
}
int main(){
  Node* start=node_create('f');
  start->next=node_create('u');Node* pu=start->next;
  pu->next=node_create('c');Node* cu=pu->next;
  cu->next=node_create('k');
  list_print(start);
  cout<<list_length(start)<<endl;
  node_insert('!',start,pu); Node* paa =start->next;
  list_print(start);
  cout<<"Length "<<list_length(start)<<endl;
  cout<<paa<<endl;
  cout<<node_search('!',start)<<endl;
  node_remove_data('!',start);
  list_print(start);
  node_insert('!',start,pu);paa =start->next;
  list_print(start);
  node_remove(start,pu);
  list_print(start);
  cout<<list_length(start)<<endl;
  node_remove(start,cu->next);
  list_print(start);
  cout<<list_length(start)<<endl;
  return 0;
}
