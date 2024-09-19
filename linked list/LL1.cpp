#include<iostream>
using namespace std;
class node
{
    public:
    int data ;
    node* next;
   

    node()
    {
        this->next=NULL;

    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void printll(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl; 
    
}
int lengthh(node* head)
{
    node* temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;

    }
    return len;
}
    
    int main()
    {
        node* first=new node(10);
        node* second=new node(20);
         node* third=new node(30);
         node* head=first;
        first->next=second;
        second->next=third;
        printll(head);
        int a=lengthh(head);
        cout<<a;
        return 0;
    }
    void deletenode(node* &head,node* &tail,int position)
    {
        int len=lengthh(head); 
        if(head==NULL)
        {
            return;
        }
        if(position==1)
        {
            node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp; 

        }
        else if(position==len)
        {

        }
        else{

        }
    }
     //  void inserthead(node*&head,int data)
    //  {
    //     if(head==NULL)
    //     {
    //         node*newnode=newnode(data);
    //         head=newnode;

    //     }
    //     else
    //     {
    //         node*newnode = newnode(data);
    //         newnode->next=head;
    //         head=newnode;
    //     }
    //  }
