#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
		//fuck OS
	//pthread_mutex_lock(&q->lock);
	//if (empty(q))  // if queue is empty, just put to queue
	//{
	//	q->proc[0] = proc;
	//	q->size++;
	//}
	//else // if queue is not empty, add to the queue with appropriate position due to priority itself
	//{
	//	for (int i = q->size - 1 ; i >= 0; i--)
	//	{
	//		if (proc->priority >= q->proc[i]->priority)  // find the position to add
	//		{
	//			for (int j = q->size-1; j >= i ; j--)
	//			{
	//				q->proc[j] = q->proc[j + 1];         // move the rest queue by 1 position on the right
	//			}
	//			q->proc[i] = proc;                       // add process to proper position
	//			q->size++;
	//			//pthread_mutex_unlock(&q->lock);
	//			return;
	//		}
	//	}
	//}
	//pthread_mutex_unlock(&q->lock);
	if (empty(q))  // if queue is empty, just put to queue
	{
		q->proc[0] = proc;
		q->size++;
	}
	else // if queue is not empty, add to the queue with appropriate position due to priority itself
	{
		for (int i = 0; i < q->size; i++)
		{
			if (proc->priority >= q->proc[i]->priority)  // find the position to add
			{
				for (int j = q->size - 1; j >= i; j--)
				{
					q->proc[j] = q->proc[j + 1];         // move the rest queue by 1 position on the right
				}
				q->proc[i] = proc;                       // add process to proper position
				q->size++;
				//pthread_mutex_unlock(&q->lock);
				return;
			}
		}
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
	//pthread_mutex_lock(&q->lock);
	struct pcb_t* proc = NULL;
	if (empty(q)) // q is empty
	{
		//pthread_mutex_unlock(&q->lock);
		return NULL;
	}
	else // q is not empty
	{
		proc = q->proc[0]; // take the head of the queue out
		for (int i = 0; i <= q->size -1; i++)
		{
			q->proc[i] = q->proc[i + 1];        // move the rest queue by 1 position on the left
		}
		q->size--;
	}
	//pthread_mutex_unlock(&q->lock);
	return proc;
}

