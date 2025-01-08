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

void at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    
 
}
void at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void any_pos(Node *&head, Node *&tail, int idx, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void froword_print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void backword_print(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
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

    int test;
    cin >> test;
    while (test--)
    {
        int idx, val;
        cin >> idx >> val;
        int len = size(head);

        if (idx == 0)
        {
            at_head(head, tail, val);
            froword_print(head);
            backword_print(tail);
        }
        
        else if (idx == len)
        {
            at_tail(head, tail, val);
            froword_print(head);
            backword_print(tail);
        }

        else if (len < idx)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            any_pos(head, tail, idx, val);
            froword_print(head);
            backword_print(tail);
        }
    }
    return 0;
}