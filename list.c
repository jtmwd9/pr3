#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static Node * Node_constructor (int val) {
	Node * node = malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
}

Node * primaryNode_constructor () {
	Node * new = Node_constructor (0);
	return new;
}

Node * primaryHead (Node * head, Node * tail) {
	head->prev = tail;
	return head;
}

Node * primaryTail (Node * head, Node * tail) {
	tail->next = head;
	return tail;
}

Node * List_insert_head (Node * head, int val) {
	if (head == NULL) {
		Node * new = Node_constructor (val);
		new->prev = head;
		return new;
	} else if (head->next == NULL) {
		Node * new = Node_constructor (val);
		head->next = new;
		new->prev = head;
		return new;
	} else {
		List_insert_head (head->next, val);
	}
}

Node * List_insert_last (Node * tail, int val) {
	if (tail == NULL) {
		Node * new = Node_constructor (val);
		new->next = tail;
		return new;
	} else if (tail->prev == NULL) {
		Node * new = Node_constructor (val);
		tail->prev = new;
		new->next = tail;
		return new;
	} else {
		List_insert_last (tail->prev, val);
	}
}

Node * List_delete (Node * head, int val) {
	Node * temp;
	if (head == NULL) {
	} else if (head->val == val) {
		temp = head->prev;
		temp->next = head->next;
		free (head);
		return temp;
	} else {
		temp = List_delete (head->prev, val);
		if (temp->next == NULL)
			return temp;
		else
			return temp->next;
	}
}

void List_destroy (Node * head) {
	Node * temp;
	if (head == NULL) {
	} else {
		temp = head->prev;
		temp->next = NULL;
		free (head);
		List_destroy (temp);
	}
}

void List_display (Node * head) {
	Node * temp;
	if (head == NULL) {
	} else {
		temp = head->prev;
		printf("%d ", head->val);
		printf("\n");
		List_display (temp);
	}
}
