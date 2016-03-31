/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 != NULL && head2 != NULL){
		struct node* res = NULL;
		struct node* temp1 = head1;
		struct node* temp2 = head2;
		struct node* res1 = NULL;
		while (temp1 != NULL && temp2 != NULL){
			struct node* nn = (struct node*)malloc(sizeof(struct node*));
			if (temp1->num < temp2->num){
				nn->num = temp1->num;
				nn->next = NULL;
				if (res == NULL){
					res = nn;
					res1 = res;
				}
				else{
					res->next = nn;
					res = nn;
				}
				temp1 = temp1->next;
			}
			else{
				nn->num = temp2->num;
				nn->next = NULL;
				if (res == NULL){
					res = nn;
					res1 = res;
				}
				else{
					res->next = nn;
					res = nn;
				}
				temp2 = temp2->next;
			}
			if (temp1 == NULL){
				res->next = temp2;
			}
			if (temp2 == NULL){
				res->next = temp1;
			}
		}
		return res1;
	}
	else if (head1 == NULL){
		return head2;
	}
	else if (head2 == NULL){
		return head1;
	}
	return NULL;
}
