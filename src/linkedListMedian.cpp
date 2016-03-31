/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node* temp = head;
	int len = 0;
	if (head != NULL){
		while (temp != NULL)
		{
			len++;
			temp = temp->next;
		}
		temp = head;
		if (len % 2 != 0){
			len = len / 2;
			for (int i = 0; i < len; i++)
				temp = temp->next;
			return temp->num;
		}
		else{
			len = len / 2;
			for (int i = 0; i < len-1; i++){
				temp = temp->next;
			}
			temp->num = ((temp->num) + (temp->next->num)) / 2;
			return temp->num;
		}
	}
	return -1;
}
