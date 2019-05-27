#ifndef MS_BST_QUEUE_H
#define MS_BST_QUEUE_H

/**
 *  @file queue.h
 *  @author championsurfer3044
 *  @date 27 May 2019 
 *  @brief 
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2019 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Data Types
*----------------------------------------------------------------------
*/
typedef struct mcq_t {
  treeNodePtr_t *data;
  int head;
  int tail;
  int size;
}mcq_t;

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Public Function Prototypes
*----------------------------------------------------------------------
*/
/** Initialize your data structure here. Set the size of the queue to be k. */
mcq_t * CreateQueue(int k);

void DestroyQueue(mcq_t *q);

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool EnQueue(mcq_t *q, treeNode_t *value);

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool DeQueue(mcq_t *q);

/** Get the front item from the queue. */
treeNode_t *Front(mcq_t *q);

/** Get the last item from the queue. */
treeNode_t *Rear(mcq_t *q);

/** Checks whether the circular queue is empty or not. */
bool IsEmpty(mcq_t *q);

/** Checks whether the circular queue is full or not. */
bool IsFull(mcq_t *q);
/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/
#ifdef __cplusplus
}
#endif

#endif //MS_BST_QUEUE_H

