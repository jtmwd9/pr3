#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char *argv[]) {
	int s, val;
	bool hCheck = false;	
	bool tCheck = false;
	Node * head = NULL;
	head = primaryNode_constructor();
	Node * tail = NULL;
	tail = primaryNode_constructor();
	head = primaryHead (head, tail);
	tail = primaryTail (head, tail);
	do {
		printf("Enter number:\n");
		printf("\t1: Insert head\n");
		printf("\t2: Instert tail\n");
		printf("\t3: Delete a node\n");
		printf("\t4: Delete all\n");
		printf("\t5: Display all\n");
		printf("\t6: Exit\n");

		scanf("%d", &s);
		while (s < 1 || s > 6) {
			printf("Not a valid option\n");
			scanf("%d", &s);
		}
		switch (s) {
			case 1:
				printf("Enter an integer:\n");
				scanf("%d", &val);
				if (hCheck == false) {
					head->val = val;
					hCheck = true;
				} else {
					head = List_insert_head (head, val);
				}
				break;
			case 2:
				printf("Enter an integer:\n");
		                scanf("%d", &val);
				if (tCheck == false) {
					tail->val = val;
					tCheck = true;
				} else {
					tail = List_insert_last (tail, val);
				}
				break;
			case 3:
				printf("Enter an integer:\n");
				scanf("%d", &val);
				List_delete (head, val);
				break;
			case 4:
				printf("Deleting all:\n");
				List_destroy (head);
				break;
			case 5:
				List_display (head);
				break;
			case 6:
				break;
		}		
	} while (s != 6);

	return 0;
}
