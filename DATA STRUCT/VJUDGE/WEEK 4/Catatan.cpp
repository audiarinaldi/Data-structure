#include<bits/stdc++.h>
using namespace std;

struct Node {
	int x;
	Node *next;
};

struct LinkedList {
	Node *head;
	int size;
	LinkedList() {
		head=NULL; size=0;
	}
	~LinkedList() {
		clear();
	}
	void insert(int x) {
		Node *newNode=(Node*)malloc(sizeof(Node));
		//Node *newNode=new Node();
		newNode->x=x;
		newNode->next=head;
		head=newNode;
		size++;
	}
	void pop() {
		if (empty()) return;
		Node *temp=head;
		head=head->next;
		free(temp);
		size--;
		//delete temp;
	}
	bool search(int x) {
		Node *iter; iter=head;
		while (iter!=NULL) {
			if (iter->x==x) return true;
			iter=iter->next;
		}
		return false;
	}
	void deleteOneX(int x) {
		if (empty()) return;
		if (!search(x)) return;
		if (head->x==x) {
			pop(); return;
		}
		Node *iter; iter=head;
		while (iter->next->x!=x) iter=iter->next;
		Node *temp; temp=iter->next;
		iter->next=temp->next;
		free(temp); size--;
		//delete temp;
	}
	void deleteAllX(int x) {
		if (empty()) return;
		if (!search(x)) return;
		while (!empty() && head->x==x) pop();
		Node *iter; iter=head;
		while (iter!=NULL && iter->next!=NULL) {
			while (iter->next!=NULL && iter->next->x==x) {
				Node *temp; temp=iter->next;
				iter->next=temp->next;
				free(temp); size--;
			}
			iter=iter->next;
		}
	}
	void clear() {
		while (!empty()) pop();
	}
	bool empty() {
		return (head==NULL);
	}
	void sort() {
		if (empty()) return;
		if (size==1) return;
		for (int i=0;i<size;i++) {
			Node *iter; iter=head;
			while (iter->next!=NULL) {
				if ((iter->x)>(iter->next->x)) {
					int temp=iter->x;
					iter->x=iter->next->x;
					iter->next->x=temp;
				}
				iter=iter->next;
			}
		}
	}
	void debug() {
		Node *iter; iter=head;
		while (iter!=NULL) {
			if (iter!=head) printf(" ");
			printf("%d",iter->x);
			iter=iter->next;
		}
		printf("\n");
	}
};

int main() {
	return 0;
}