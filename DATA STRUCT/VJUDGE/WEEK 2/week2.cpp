//B
int sum(ListNode *head) {
    ListNode *iter = head;
    int result = 0;
    while (iter != NULL) { 
        result = result + iter -> val;
        iter = iter -> next; 
    }
    return temp;
}

//================================

//D
void PrintReverse(ListNode *head) {
    if(head != NULL) {
    PrintReverse(head->next);
    printf("%d ", head->val);
    }
}

//=================================

F

int hasCycle(ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
  
    while(slow && fast && fast->next )
    {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast)
        {
           return 1;
        }
    }
    return 0;
}

//=================================

C 

ListNode* merge(ListNode *l1, ListNode *l2)
{ 
    if (!l1) 
        return l2; 
    if (!l2) 
        return l1; 

    if (l1->val < l2->val) { 
        l1->next = merge(l1->next, l2); 
        return l1; 
    } 
    else { 
        l2->next = merge(l1, l2->next); 
        return l2; 
    } 
} 

//=======================================

include<stdio.h>

int main() {
    int radius;
    float phi = 3.14159;
    scanf("%d", &a);
    
    printf("%d\n", 2*r);
    printf("%.2f\n", phi*2*r);
    printf("%.2f\n", phi*r*r);
    return 0;
}



