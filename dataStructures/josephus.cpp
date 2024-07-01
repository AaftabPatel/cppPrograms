//program for josephus problem
#include<iostream>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
Node *newNode(int data) 
{ 
   Node *temp = new Node; 
   temp->next = temp; 
   temp->data = data; 
} 
  
void getJosephusPosition(int m, int n) 
{ 
    Node *head = newNode(1); 
    Node *prev = head; 
    for (int i = 2; i <= n; i++) 
    { 
        prev->next = newNode(i); 
        prev = prev->next; 
    } 
    prev->next = head; 

    Node *ptr1 = head, *ptr2 = head; 
    while (ptr1->next != ptr1) 
    {  
        int count = 1; 
        while (count != m) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->next; 
            count++; 
        } 
  
        ptr2->next = ptr1->next; 
        ptr1 = ptr2->next; 
    } 
  
    cout<<"Last process is(Josephus Position) is"<< ptr1->data; 
} 
  
int main() 
{ 
    int k = 14, n = 2; 
    getJosephusPosition(n,k); 
    return 0; 
} 