/*
 * File:	deque.h
 *
 * Description:	This file contains the public function declarations for a
 *		deque abstract data type for integers.  A deque is a
 *		doubly-ended queue, in which items can only be added to or
 *		removed from the front or rear of the list.
 */

# ifndef DEQUE_H
# define DEQUE_H

typedef struct deque DEQUE;

extern DEQUE *createDeque(void);

extern void destroyDeque(DEQUE *dp);

extern int numItems(DEQUE *dp);

extern void addFirst(DEQUE *dp, int x);

extern void addLast(DEQUE *dp, int x);

extern int removeFirst(DEQUE *dp);

extern int removeLast(DEQUE *dp);

extern int getFirst(DEQUE *dp);

extern int getLast(DEQUE *dp);

extern void makeLastUnreferenced(DEQUE *dp);

extern int search(DEQUE *dp, int x);

extern void printDeque(DEQUE *dp);

extern void moveToFirst(DEQUE *dp, int position);

extern void UpdateData(DEQUE *dp, int position, int data);

# endif /* DEQUE_H */
