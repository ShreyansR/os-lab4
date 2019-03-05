/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Group 1
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Define your FIFO queue functions here, these will most likely be the
// push and pop functions that you declared in your header file

/*this function removes the job from the list*/
proc * pop(node_q * queue){
    proc tempProcess;

	if(queue -> next == NULL){
		return NULL;
	}
	node_q * nextNode = NULL;
	nextNode = queue -> next -> next; //second node
	node_q * currentNode = NULL;
    currentNode = queue -> next; //first node
 	tempProcess = currentNode -> process;
	queue -> next = nextNode;
    free(currentNode); //free the current node(free the already done node)

	return &tempProcess;
}

/*push the process into the queue*/
void push (proc process, node_q  * queue){
	node_q *current = queue;

	while(current -> next != NULL){
		current = current -> next;
	}
  /*expand the memory needed*/
	current -> next =  (node_q *) malloc(sizeof(node_q));
	current -> next -> process = process;
    current->next->next = NULL;

}
