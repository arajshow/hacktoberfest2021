#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class par{

    public:
    node *head;
    node *tail;
};

par reverseSupport(node*head){
    if(head==NULL || head->next ==NULL){
        par ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    else{
        par temp = reverseSupport(head->next);
        temp.tail->next = head;
        head->next =NULL;
        temp.tail= head;
        return temp;
    }
}

node *reverse(node *head){
    return reverseSupport(head).head;
}


void print( node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;

}

int main(){

    node *n1 = new node(10);
   node *head = n1;

   node *n2 = new node(20);
   node *n3 = new node(30);
   node *n4 = new node(40);
   node *n5 = new node(50);
   node *n6 = new node(60);
   node *n7 = new node(70);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    print(head);

    head = reverse(head);
    print(head);

    

    return 0;

}
