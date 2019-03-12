#include <iostream>

using namespace std;
class node
{
   public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next = NULL;
    }

};
//for doubly linked list we can keep two pointers.
/*class LinkedList{
node* head;
node *tail;
public:
    void add()
};
*/

// by functions
void insertAtHead(node*&head,int data)
{
    if(head==NULL)
    {
        head = new node(data);
        return;
    }
    node *n=new node(data);
    n->next=head;
    head=n;
}
void print(node*head)
{
    while(head!=NULL)
    {
     cout<<head->data<<"->";
     head=head->next;
    }
    cout<<endl;
}
void insertAtMiddle(node *head,int data,int pos)
{
    if(pos==0)
        insertAtHead(head,data);
    else
    {
        node *temp=head;
      for(int i=1;i<=pos-1;i++)
      temp=temp->next;
      node *n=new node(data);
      n->next=temp->next;
      temp->next=n;


    }

}
ostream& operator<<(ostream&a,node *head)
{
    print(head);
    return a;
}
bool search_list(node *head,int key)
{
    if(head==NULL)
        return false;
    if(head->data==key)
        return true;
    search_list(head->next,key);
}
void reverse_list(node *&head)
{
    node *temp=head->next;
    node *temp2=NULL;
    while(temp->next!=NULL)
    {temp2=temp->next;
    temp->next=head;
    head=temp;
    temp=temp2;
    }
    head=temp;
}

int main()
{
    node *head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,7);
    insertAtMiddle(head,3,1);
    cout<<head;
    cout<<"\n";
    reverse_list(head);
    cout<<head;

    return 0;
}
