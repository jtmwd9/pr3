#ifndef LIST_H
#define LIST_H

typedef struct node {
	struct node * next;
	struct node * prev;
	int val;
} Node;

Node * primaryHead (Node * head, Node * tail);

Node * primaryTail (Node * head, Node * tail);

Node * List_insert_last (Node * head, int val);

Node * List_insert_head (Node * tail, int val);

Node * List_delete (Node * head, int val);

void List_destroy (Node * head);

void List_display (Node * head);

#endif
