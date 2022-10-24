#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ctr=0;

struct node {
    char data;
    struct node *next;
};

struct node *head = NULL;

void pop() {
    struct node *temp = head;
    if(!temp) {
        return ;
    }
    else {
        temp = head;
        head = head->next;
        ctr--;
        free(temp);
    }
}

void push(char x) {
    ctr++;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
    if(head->next!=NULL) {
        if(x==')' && (head->next)->data=='(') {
            pop();
            pop();
        }
        else if(x==']' && (head->next)->data=='[') {
            pop();
            pop();
        }
    }
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        char s[128];
        scanf("%s",s);
        int n = strlen(s),i;
        for(i=0;i<n;i++) {
            push(s[i]);
        }
        if(!ctr) {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}

#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node *next;    
}*top=NULL;

void push(char x) {
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack is Full\n");
    else {
        t->data=x;
        t->next=top;
        top=t;
    }
}

void pop() {
    char x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else {
        struct Node *t;
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
}

int balance(char *exp) {
    int i;
    for(i=0;exp[i]!='\0';i++) {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')') {
            if(top==NULL)
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main() {
    char exp[130];
    int tc;
    scanf("%d",&tc);
    for(int i=0 ; i<tc ; i++){
        scanf("%s",exp);
        if(balance(exp))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

int main() {
    int test; char str[130]; 
    scanf ("%d", &test);
    getchar();

    for (int i = 1 ; i <= test; i++){
        stack<int> nodez;   
        bool pair = true;
        gets(str);
        for (int j =0; j <= strlen(str); j++){
            if (str[j]== '(' || str[j] == '[') {
                nodez.push(str[j]);
                continue;
            }
            if (!nodez.empty() && (str[j] == ')' && nodez.top()=='(' || str[j]==']' && nodez.top() == '[')) {
                nodez.pop();
            } else {
                pair = false;
                break;
            }
        }
        if (pair && nodez.empty()) {
            printf ("Yes\n");
        }else{
            printf ("No\n");
        }
    }
 return 0;
}