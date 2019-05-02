template<typename T>
class LLnode{
    private:
        LLnode* next;
        LLnode* prev;
        T data;
    public:
        LLnode():next(NULL),prev(NULL),data(){};
        LLnode(data):next(NULL),data(data){};
        void setNode(data){
            this->data=data;
        }
        LLnode& getNode(){
            return *this;
        }
        LLnode* getNext() const {
            return next;
        }
        void Next(LLNode* next) {
            this->next=next;
        }
};
template <typename T>
class LL{
    private:
        LLnode* head;
        LLnode* tail;
        int size;
    public:
        LL():head(new LLnode),tail(head),size(1){}
        LL(T data):head(new LLNode(data)),tail(head),size(1){}
        void addNode(T data,int pos){
            if(pos<size){
                LLNode* temp=head;
                for(int i=0;i<pos;i++){
                    temp=temp->next;
                }
                LLNode* temp2=temp;
                temp2->prev=temp;
                temp2->next=temp->next;
                temp2->data=data;
                size++;
            }
        }
}
