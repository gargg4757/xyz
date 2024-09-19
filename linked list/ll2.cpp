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
    
};
int findLength(node* head)
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

// inser at head
void inserthead(node*&head,int data)
{
    if(head==NULL)
    {
        node* newnode=new node(data);
        head=newnode;
    }
    else{
        // create new node
        node*newnode=new node(data);
        // newnod eto head se attach kardo
        newnode->next=head;
        // update head
        head=newnode;
    }
}
    // inser at tail
    void inserttail(node*&head,node*&tail,int data)
    {
        if(head==NULL)
    {
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
        
        else{
            node*newnode= new node(data);
        //     tail to connect kar do newnode se
        tail->next=newnode;
        tail=newnode;
        }
    }
//     void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
//         int len = findLength(head);
        
//         if(position == 1) {
//                 inserthead(head,  data);
//                 return;
//         }
//         else if(position > len) {
//                 inserttail(head, tail, data);
//                 return;
//         }
//         else {
//             Node* newNode = new Node(data);
            
//             Node* prev = NULL;
//             Node* curr = head;
//             while(position != 1) {
//                 position--;
//                 prev = curr;
//                 curr = curr->next;
//             }
            
//             //step3:
//             newNode -> next = curr;

//             //step4:
//             prev -> next = newNode;
            
//         }
        
// }
void insertAtPosition(node*& head, node*& tail, int data, int position) {
    int len = findLength(head);
    
    if (position < 1) {
        cout << "Position should be greater than or equal to 1" << endl;
        return;
    }

    if (position == 1) {
        inserthead(head, data);
        return;
    } else if (position > len + 1) {
        inserttail(head, tail, data);
        return;
    } else {
        node* newNode = new node(data);
        node* prev = NULL;
        node* curr = head;
        while (position != 1) {
            position--;
            prev = curr;
            curr = curr->next;
        }
        newNode->next = curr;
        prev->next = newNode;
    }
}
// void deletenode(node*&head,node*&tail, int position)
// {
//     if(head==NULL)
//     return;
//     int len =findLength(head);
//     if(position==1)
//     {
//         node*temp=head;
//         head=head->next;
//         temp->next=NULL;
//         delete temp;
//     }
//     else if(position==len)
//     {
//         node* prev=head;
//         while(prev->next !=tail)
//         {
//             prev=prev->next;
//         }
//         prev->next=NULL;
//     }
// }
// void deleteNode(Node* &head, Node* &tail, int position)
void deletenode(node*&head,node*&tail, int position) {
  //empty list
  if(head == NULL) {
    cout << "Cannot delete, coz LL is empty" << endl;
    return;
  }

  if(head == tail) {
    //single element
    node* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
    return;
  }

  int len = findLength(head);

  //delete from head
  if(position == 1) {
    //first node ko delete kardo
    node* temp = head;
    head = head->next;
    //head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else if(position == len) {
    //last node ko delete krdo

    //find prev
    node* prev = head;
    while(prev -> next != tail ){
      prev = prev -> next;
    }

    //prev node ka link null karo
    prev -> next = NULL;

    //node delete kro
    delete tail;

    //update tail
    tail = prev;

  }

  else {
    //middle me koi node ko delete krna h 

    //step1: set prev/curr pointers
    node* prev = NULL;
    node* curr = head;
    while(position != 1) {
      position--;
      prev = curr;
      curr = curr->next;
    }

    //step2: prev -> next me curr ka next node add kro
    prev->next = curr->next;

    //step3: node isolate krdo
    curr->next = NULL;
    //step4: delte node
    delete curr;

  }

}



// int main()
// {
    
//         node* first=new node(10);
//         node* second=new node(20);
//          node* third=new node(30);
//          node* head=first;
//         first->next=second;
//         second->next=third;
//         node*tail=third;
        
        
//          cout << "Original linked list: ";
//     printll(head);

//     // Insert a new node at the head
//     // inserthead(head, 5);
//     inserttail(head,tail, 500);

//     // Print the updated list
//     cout << "Updated linked list after insertion at head: ";
//     printll(head);

        
//         return 0;
//     }

int main() {
    node* head = NULL;  // Initialize head to nullptr
    node* tail = NULL;
    
    // Insert elements
    inserthead(head, 10);
    inserthead(head, 20);
    inserthead(head, 30);
    inserthead(head, 40);
    inserthead(head, 60);
    //  insertAtPosition(11,2, head, tail) ;
     printll(head);
    //  insertAtPosition(head, tail, 15, 2);  // Insert 15 at position 2
    // insertAtPosition(head, tail, 5, 1);   // Insert 5 at position 1
    // insertAtPosition(head, tail, 25, 5);  // Insert 25 at position 5 (end)

    // // Print the updated linked list
    // cout << "Updated linked list: ";
    // printll(head);
    // deletenode(head,tail,1);
    deletenode(head,tail,5);
    // deletenode(head,tail,3);
    printll(head);


    // Print the linked list
    

    return 0;
}