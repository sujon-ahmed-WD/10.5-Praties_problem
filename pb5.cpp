#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node*prev;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

void at_tail(Node*&head,Node*&tail,int val)
{
        Node*newnode=new Node(val);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            return;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
}
void sort(Node*&head)
{
    for(Node *i=head;i->next!=NULL;i=i->next)
    {
        for(Node *j=i->next;j!=NULL;j=j->next)
        {
            if(i->val>j->val)
            swap(i->val,j->val);
        }
    }
}
 void print(Node*head)
 {
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
 }
int main()
{
    Node*head=NULL;
    Node*tail=NULL;
    int val;
    while(cin>>val&& val!=-1)
    {
        at_tail(head,tail,val);
    }
    sort(head);
    print(head);
    return 0;
}