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
bool sameornot(Node *head, Node *head1)
{
    Node *temp1 = head;
    Node *temp2 = head1;
    int len1 = size(head);
    int len2 = size(head1);
    if (len1 != len2)
    {
        return false;
    }
    for (int i = 0; i < len1; i++)
    {
        if (temp1->val != temp2->val)
        {
            return false;  
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
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

    int y;
    while (cin >> y && y != -1)
    {
        set_list(head1, tail1, y);
    }

    if (sameornot(head, head1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}