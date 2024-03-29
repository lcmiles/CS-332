/* Driver program to test the queue implementation */
/* Use the Makefile provided or compile using: gcc -Wall queue.c qdriver.c */

#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv) {
	queue *q;
	int i;

	/* create a queue data structure */
	q = queue_init(10);

	/* insert 5 items to the queue */
	for (i = 0; i < 5; i++) {
	    queue_insert(q, 100+i);
	    queue_display(q);
	}
	/* delete 5 items from the queue */
	for (i = 0; i < 5; i++) {
	    queue_delete(q);
	    queue_display(q);
	}
	/* insert 11 items to the queue */
	for (i = 0; i < 11; i++) {
	    if (queue_insert(q, 200+i) != -1)
	        queue_display(q);
	    else
		printf("queue full, insertion failed!\n");
	}
	/* delete 11 items from the queue */
	for (i = 0; i < 11; i++) {
	    if (queue_delete(q) != -1) 
	        queue_display(q);
	    else
		printf("queue empty, deletion failed!\n");
	}
	/* delete the queue */
	queue_destroy(q);

	return 0;
}

