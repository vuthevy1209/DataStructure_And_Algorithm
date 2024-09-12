#include <stdio.h>
#include <algorithm>
using namespace std;

struct node{
    int data;
    struct node* next;
};

int size(node* head){
    int cnt = 0;
    while(head != nullptr){
        cnt++;
        head = head->next;
    }
    return cnt;
}

node* makeNode(int x){
    node* newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    return newnode;
}

void pushFront(node** head, int x){
    node* newnode = makeNode(x);
    if(*head == nullptr){
        *head = newnode;
    }
    else{
        newnode->next = *head;
        *head = newnode;
    }
}

void pushBack(node** head, int x){
    node* newnode = makeNode(x);
    if(*head == nullptr){
        *head = newnode;
    }
    else{
        node* temp = *head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp->next = newnode;
    }
}

void insert(node** head, int x, int k){
    int n = size(*head);
    if(k < 1 || k > n+1){
        return;
    }
    if(k==1){
        pushFront(head, x);
        return;
    }
    node* newnode = makeNode(x);
    node* temp = *head;
    for (int i = 1; i <= k-2; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void popFront(node** head){
    if(head == nullptr){
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void popBack(node** head){
    if(*head == nullptr || (*head)->next ==  nullptr){
        popFront(head);
        return;
    }
    node* temp = *head;
    while((temp->next)->next != nullptr){
        temp = temp->next;
    }
    node* k = temp->next;
    temp->next = nullptr;
    delete k;
}

void erase(node** head, int k){
    if(*head == nullptr){
        return;
    }
    int n = size(*head);
    if(k<1 || k>n){
        return;
    }
    else if(k == 1){
        popFront(head);
    }
    else{
        node* temp = *head;
        for(int i = 1; i <= k-2; i++)
        {
            temp = temp->next;
        }
        node* k = temp->next;
        temp->next = k->next;
        delete k;
    }
}

void pop(node** head, int x){
    if(*head == nullptr){
        return;
    }
    node* temp = *head;
    node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == x){
            if(prev == nullptr){
                *head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            node* to_delete = temp;
            temp = temp->next;
            delete to_delete;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}


void removeAll(node** head){
    node* temp = nullptr;
    while(*head != nullptr){
        temp =*head;
        *head = (*head)->next;
        delete temp;
    }
    head = nullptr;
}

void Selection_Sort(node** head){
    for(node* i = *head; i!=nullptr; i = i->next){
        node* nodeMin = i;
        for(node* j =i->next; j!=nullptr; j = j->next){
            if(j->data < nodeMin->data){
                nodeMin = j;
            }
        }
        int temp = i->data;
        i->data = nodeMin->data;
        nodeMin->data = temp;
    }
}

void Insert_Sort(node** head)
{
    if(*head == nullptr || (*head)->next == nullptr)
    {
        return;
    }
    node* key = (*head)->next;
    (*head)->next = nullptr;
    while(key != nullptr)
    {
        node* nextNode = key->next;
        if(key->data < (*head)->data)
        {
            key->next = *head;
            *head = key;
        }
        else
        {
            node* k = *head;
            node* p = k->next;
            while(p!=nullptr && key->data > p->data)
            {
                k = k->next;
                p = p->next;
            }
            k->next = key;
            key->next = p;
        }
        key = nextNode;
    }
}

void Bubble_Sort(node** head)
{
    if (*head == nullptr || (*head)->next == nullptr)
    {
        return;
    }
    node* last = nullptr;
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        node* curr = *head;
        node* prev = nullptr;
        while(curr -> next != last)
        {
            if(curr->data > (curr->next)->data)
            {
                node* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                if(prev != nullptr)
                {
                    prev->next = temp;
                }
                else
                {
                    *head = temp;
                }
                prev = temp;
                swapped = true;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        last = curr;
    }
}
node* Merge(node* left, node* right){
    node* result = nullptr;
    if(left == nullptr){
        return right;
    }
    else if (right == nullptr){
        return left;
    }
    if(left->data <= right->data){
        result = left;
        result->next = Merge(left->next, right);
    }
    else{
        result = right;
        result->next = Merge(left, right->next);
    }
    return result;
}
void Merge_Sort(node*& head){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    node* left = head;
    node* right = head->next;
    left->next = nullptr;
    Merge_Sort(left);
    Merge_Sort(right);
    head = Merge(left, right);
}

void print_list(node* head)
{
    while(head != nullptr)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void reversee(node* &head){
    if(head == nullptr || head->next == nullptr) return;
    node* last = head;
    node* temp = head->next;
    reversee(temp);
    last->next->next = last;
    last->next = nullptr;
    head = temp;
}


int main()
{
    int n = 0;
    scanf("%d", &n);
    node* head = nullptr;
    for(int i = 1; i<=n; i++)
    {
        int x = 0;
        scanf("%d", &x);
        pushBack(&head, x);
    }
    print_list(head);
    printf("\n");
    //Selection_Sort(&head);
    //Insert_Sort(&head);
    //Bubble_Sort(&head);
    Merge_Sort(head);
    //erase(&head, 4);
    //reversee(head);
    print_list(head);
    removeAll(&head);
    return 0;
}
