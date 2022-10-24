#include <stdio.h>
#include <string.h>
#define N 100010

// struct Node{
//     char c;
//     struct Node* next; struct Node* prev;
// }; 

struct Node{
    char current;
    struct Node* prev;
    struct Node* next;
};

Node* insertNode(Node* n, char current){
    Node* temp = new Node();
    temp->current = current;
    temp->next = n->next;
    n->next->prev = temp;
    n->next = temp;
    temp->prev = n;
    return temp;
}
 
void print(Node* dummy) {
    Node* tmp = dummy->next;
    while(tmp->current) {
        putchar(tmp->current);
        tmp = tmp->next;
    }
    printf ("\n");
}
 
//  void process() {
//     Node* dummy = new Node();
//     Node* tail = new Node();
//     tail->prev = dummy;
//     dummy->next = tail;
//     tail->next = NULL;
//     dummy->prev = NULL;
//     Node* cur = dummy;
//     tail->c = 0;
//  }

int main() {
    char arr[N];
    while(scanf("%s", arr) != EOF) {
        Node* dummy = new Node();
        Node* tail = new Node();
        tail->prev = dummy;
        dummy->next = tail;
        tail->next = NULL;
        dummy->prev = NULL;
        Node* cur = dummy;
        tail->current = 0;
        
        for (int i = 0 ; arr[i] ; i++ ) {
            if (arr[i] == '['){
                cur = dummy;
                continue;
            }
            if ( arr[i] == ']' ) {
                cur = tail->prev;
                continue;
            }
            cur = insertNode(cur, arr[i]);
        }
        print(dummy);
    }
    return 0;
}