/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head != NULL && K > 0){
		struct node* temp = head;
		int count = 1;
		//insertAtEveryKthNode(createList(12345), 2), 1223425
		//insertAtEveryKthNode(createList(289), 1), 218191
		while (temp != NULL){
			if (count == K){
				struct node* nn = (struct node*)malloc(sizeof(struct node*));
				nn->num = K;
				if (temp->next == NULL){
					temp->next = nn;
					nn->next = NULL;
				}
				else{
					nn->next = temp->next;
					temp->next = nn;
				}
				temp = nn;
				count = 0;
			}
			count++;
			temp = temp->next;
		}
		return head;
	}
	return NULL;
}
