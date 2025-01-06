#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
void set_list(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void print(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
// string isSame(Node*head,Node*head1)
// {

 
      

// }

int size(Node*head)
{
    int sz=0;
    Node*temp=head;
    while(temp!=nullptr)
    {
        sz++;
        temp=temp->next;
    }
    return sz;
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *head1 = nullptr;
    Node *tail1 = nullptr;

    int x;
    while (cin >> x && x != -1)
    {
        set_list(head, tail, x);
    }
    int len1=size(head);
     

    int y;
    while (cin >> y && y != -1)
    {
        set_list(head1, tail1, y);
    }
    int len2=size(head1);
    return 0;
}