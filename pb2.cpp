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

void Revrsre(Node*&head,Node*&tail)
{
     for(Node* i=head,*j=tail;i!=j&& i->prev!=j;i=i->next,j=j->prev)
     swap(i->val,j->val);
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

int size(Node *head)
{
    int sz = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        sz++;
        temp = temp->next;
    }
    return sz;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int x;
    while (cin >> x && x != -1)
    {
        set_list(head, tail, x);
    }
    Revrsre(head,tail);
    print(head);
    return 0;
}