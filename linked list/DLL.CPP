#include<iostream>
using namespace std;
 class node
 {public:
    int data;
    node*next;
    node *prev;

    node()
    {
        this->prev=NULL;
        this->next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

 };
 void print(node* head)
 {
    node* temp=head;
    while(temp!= NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
 }
 int length(node* head)
 {
    node* temp=head;
    int len=0;
    while(temp!= NULL)
    {
      len++;
        temp=temp->next;
    }
    return len;
 }
 void insertathead(node*&head,node*&tail,int data)
 {
    if(head==NULL)
    {
        node*newnode=new node(data);
        head=newnode;  
        tail=newnode;
    }
    else
    {
    node*newnode=new node(data);
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    }
 }
 void insertattail(node*&head,node*&tail,int data)
 {
    if(head==NULL)
    {
        node*newnode=new node(data);
        head=newnode;  
        tail=newnode;
    }
    else
    {
    node*newnode=new node(data);
    tail->next=newnode;
    newnode->prev=tail;
    newnode=tail;
    }
 }
 void insertatmiddle(node*&head,node*&tail,int data, int position)
 {int len=length( head);
    if(head==NULL)
    {node*newnode=new node(data);
        head=newnode;  
        tail=newnode;

    }
    else if(position==1)
    {
        
        insertathead(head,tail,data);
    }
    else if(position==len+1)
    {
        insertattail(head,tail,data);
    }
    else{
        // insert at middle
        // create new node
        node*newnode=new node(data);
        // setr currand prev
        node*prev=NULL;
        node*curr=head;
        while(position!=1)
        {
            position--;
            prev=curr;
            curr=curr->next;
        }
        // step3

        prev->next=newnode;
        newnode->prev=prev;
        
        newnode->next=curr;
        curr->prev=newnode;


    }
 }
 void deletenode(node*&head,node*&tail, int position) 
 {
  //empty list
  if(head == NULL)
   {
    cout << "Cannot delete, coz LL is empty" << endl;
    return;
  }

  if(head == tail)
   {
    //single element
    node* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
    return;
  }

  int len = length(head);

  //delete from head
  if(position == 1) 
  {
    //first node ko delete kardo
    node* temp = head;
    head = head->next;
    //head = temp->next;
    temp->next = NULL;
    head->prev=NULL;
    delete temp;
  }
  else if(position == len) 
  {
    //last node ko delete krdo

    //find prev
    node* prev = tail->prev;
    

    //prev node ka link null karo
    prev -> next = NULL;
    tail->prev=NULL;

    //node delete kro
    delete tail;

    //update tail
    tail = prev;

  }
  else
  {
    node* prev = NULL;
    node* curr = head;
    while(position != 1) {
      position--;
      prev = curr;
      curr = curr->next;
    }
    node*nextnode=curr->next;
    prev->next=nextnode;
    curr->prev=NULL;
    curr->next=NULL;
    nextnode->prev=prev;
    delete curr;


  }
 }

 int main()
 {
    node*head=NULL;
    node*tail=NULL;
    insertathead(head,tail,40);
    insertathead(head,tail,30);
    insertathead(head,tail,20);
    insertathead(head,tail,10);
    print(head);
    cout<<endl;
    // insertattail(head ,tail,99);
    // insertatmiddle(head,tail,1000,3);
    //  print(head);
    deletenode(head,tail,3);
    print(head);


    return 0;  
 }