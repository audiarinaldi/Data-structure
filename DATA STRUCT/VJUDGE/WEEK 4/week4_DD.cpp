// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// // int counter;

// struct Node {
//     char data;
//     struct Node *next;
// };

// // struct Node *head = NULL;

// void push (char str) {
//     struct Node *temp;
//     temp = (Struct *Node)malloc(sizeof(struct Node));
//     temp->data = str;
//     temp->next = head;
// }

// void pop() {
//     char str = -1;
//     struct Node *temp;
//     temp = head;
//     head = head->next;
//     str = temp->data
//     free(temp);
// }

// int isBalancechar *exp) {
//     int c;
//     for(i=0; exp[c]!='\0'; i++) {
//         if(exp[c] == '(')
//             push(exp[c]);
//         else if(exp[c] == ')') {
//             if(head == NULL)
//                 return 0;
//             pop();
//         }
//     }
//     if(top==NULL) return 1;
//     else return 0;
// }

// int main {
//     int tc, char setring[130];
//     scanf("%d", &tc);

//     for(int i = 0; i < tc; i++) {
//         scanf("%s", setring);
//         if(isBalance(exp))printf("Yes\n");
//         else printf("No\n")ß;

//     }
//     return 0;
// }

//============================================

// #include<string.h>
// #include<iostream>
// #include<stack>

// using namespace std;

// string line;
// stack< char > pilha;

// int main() {
//     int count, i;
//     scanf("%d\n", &count);

//     while (count--) {

//         while (pilha.size() > 0) {
//             pilha.pop();
//         }

//         getline(cin, line);

//         for (i = 0; i < line.size(); i++) {

//             if (line[i] == '(' || line[i] == '[') {
//                 pilha.push(line[i]);
//             } else if (pilha.empty()) {
//                 pilha.push('E');
//                 break;
//             } else if (line[i] == ')' && pilha.top() == '(') {
//                 pilha.pop();
//             } else if (line[i] == ']' && pilha.top() == '[') {
//                 pilha.pop();
//             } else {
//                 pilha.push('E');
//                 break;
//             }
//         }

//         if (pilha.size() == 0) {
//             printf("Yes\n");
//         } else {
//             printf("No\n");
//         }
//     }

//     return 0;
// };

//===============================================================

// #include<stdio.h>
// #include<stdlib.h>

// struct Node {
//     char data;
//     struct Node *next;    
// }*top=NULL;

// void push(char x) {
//     struct Node *t;
//     t=(struct Node*)malloc(sizeof(struct Node));
//     if(t==NULL)
//         printf("Stack is Full\n");
//     else {
//         t->data=x;
//         t->next=top;
//         top=t;
//     }
// }

// void pop() {
//     char x=-1;
//     if(top==NULL)
//         printf("Stack is Empty\n");
//     else {
//         struct Node *t;
//         t=top;
//         top=top->next;
//         x=t->data;
//         free(t);
//     }
// }

// int balance(char *exp) {
//     int i;
//     for(i=0;exp[i]!='\0';i++) {
//         if(exp[i]=='(')
//             push(exp[i]);
//         else if(exp[i]==')') {
//             if(top==NULL)
//                 return 0;
//             pop();
//         }
//     }
//     if(top==NULL)
//         return 1;
//     else
//         return 0;
// }

// int main() {
//     char exp[130];
//     int tc;
//     scanf("%d",&tc);
//     for(int i=0 ; i<tc ; i++){
//         scanf("%s",exp);
//         if(balance(exp))
//             printf("Yes\n");
//         else
//             printf("No\n");
//     }
// }

//======================================

#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

int main() {

    int test;
    char str[255];
    scanf("%d", &test);
    getchar();
    for(int i = 1; i <= test; i++) {
        stack<int>node;
        bool isPair = true;
        gets(str);

        for(int j = 1; j <= strlen(str); j++) {
            if(str[j] == '(' || str[j] == '[') {
                node.push(isPair[j]);
            }
            if (!node.empty() && (str[j] == ')' &&node.top()=='(' || str[j]==']' && node.top() == '[')) {
                node.pop();
            } 
            else {
                isPair = false;
                break;
            }
        }
        if (isPair && node.empty()) {
            printf ("Yes\n");
        }else{
            printf ("No\n");
        }
    }
    return 0;
}