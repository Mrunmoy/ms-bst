/**
 *  @file bst.c
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


/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "bst.h"
#include "queue.h"
#include "debug.h"

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

static treeNode_t *createTreeNode(int value) {
  treeNode_t *result = (treeNode_t *) malloc(sizeof(treeNode_t));
  assert(result);
  result->val = value;
  result->leftChild = result->rightChild = NULL;
  return result;
}

static void destroyTreeHelper(treeNode_t *current) {
  if (current) {
    if (!current->leftChild && !current->rightChild) {
      // case 1: leaf node
    }
  }
}

static void freeTreeNode(treeNode_t *node) {
  free(node);
}

static bool insertNode(treeNode_t *current, int val) {
  if (val < current->val) {
    if (!current->leftChild) {
      current->leftChild = createTreeNode(val);
      return true;
    }
    else {
      return insertNode(current->leftChild, val);
    }
  }
  else {
    if (!current->rightChild) {
      current->rightChild = createTreeNode(val);
      return true;
    }
    else {
      return insertNode(current->rightChild, val);
    }
  }
}

static treeNode_t *findNode(treeNode_t *root, int val) {
  if (!root) return NULL;

  if ( root->val == val )
    return root;
  else if (val < root->val)
    return findNode(root->leftChild, val);
  else
    return findNode(root->rightChild, val);
}

static treeNode_t *findParent(treeNode_t *root, int val) {
  if ( root->val == val )
    return NULL;
  else if ( val < root->val ) {
    if (!root->leftChild)
      return NULL;
    else if ( root->leftChild->val == val )
      return root;
    else
      return findParent(root->leftChild, val);
  }
  else {
    if (!root->rightChild)
      return NULL;
    else if ( root->rightChild->val == val )
      return root;
    else
      return findParent(root->rightChild, val);
  }
}

static bool hasItemHelper(treeNode_t *current, int val) {
  if ( !current ) return false;

  if ( current->val == val)
    return true;
  else if ( val < current->val )
    return hasItemHelper(current->leftChild, val);
  else
    return hasItemHelper(current->rightChild, val);
}

static int findMinHelper(treeNode_t *current) {
  if (!current->leftChild)
    return current->val;

  return findMinHelper(current->leftChild);
}

static int findMaxHelper(treeNode_t *current) {
  if (!current->rightChild)
    return current->val;

  return findMinHelper(current->rightChild);
}


static bool preOrderHelper(treeNode_t *current, int *result, int *index) {
  if (current) {
    result[(*index)++] = current->val;
    if (preOrderHelper(current->leftChild, result, index) ) (*index)++;
    preOrderHelper(current->rightChild, result, index);
    return true;
  }
  return false;
}

static bool postOrderHelper(treeNode_t *current, int *result, int *index) {
  if (current) {
    if (postOrderHelper(current->leftChild, result, index)) (*index)++;
    if (postOrderHelper(current->rightChild, result, index)) (*index)++;
    result[*index] = current->val;
    return true;
  }
  return false;
}

static bool inOrderHelper(treeNode_t *current, int *result, int *index) {
  if (current) {
    if (inOrderHelper(current->leftChild, result, index) ) (*index)++;
    result[(*index)++] = current->val;
    inOrderHelper(current->rightChild, result, index);
    return true;
  }
  return false;
}

/*
*----------------------------------------------------------------------
*   Exported Functions Definitions
*----------------------------------------------------------------------
*/

bst_t *createNewBST(void) {
  Trace();
  bst_t *result = (bst_t *) malloc(sizeof(bst_t));
  assert(result);
  result->count = 0;
  result->root = NULL;
  return result;
}

void destroyBST(bst_t *bst) {
  if ( !bst || !bst->root) return;

  Trace();
  mcq_t *q = CreateQueue(bst->count);
  treeNode_t *cur = bst->root;
  while ( cur ) {
    if ( cur->leftChild )
      EnQueue(q, cur->leftChild);

    if ( cur->rightChild )
      EnQueue(q, cur->rightChild);

    freeTreeNode(cur);

    if ( !IsEmpty(q) ) {
      cur = Front(q);
      DeQueue(q);
    }
    else
      cur = NULL;
  }

  DestroyQueue(q);
  free(bst);
}

bool insertTreeNode(bst_t *bst, int val) {
  if ( !bst ) return false;

  Trace();
  if ( !bst->root ) {
    bst->root = createTreeNode(val);
    bst->count += (NULL != bst->root)? 1: 0;
    return (NULL != bst->root);
  }

  if (insertNode( bst->root, val )){
    bst->count++;
    return true;
  }

  return false;
}

bool hasItem(bst_t *bst, int val) {
  if ( !bst || !bst->root) return false;

  Trace();
  return hasItemHelper(bst->root, val);
}

bool removeItem(bst_t *bst, int val) {
  if ( !bst || !(bst->root) ) return false;

  Trace();
  treeNode_t *nodeToRemove = findNode(bst->root, val);
  if ( !nodeToRemove ) return false;

  treeNode_t *parent = findParent(bst->root, val);
  // special case: only one item, delete root
  if ( 1 == bst->count ) {
    freeTreeNode(bst->root);
    bst->root = NULL;
  }
  else if (bst->root == nodeToRemove) {
    // removing root
    treeNode_t *largestValue = nodeToRemove->leftChild;
    while ( largestValue->rightChild ) {
      largestValue = largestValue->rightChild;
    }
    // copy the value to the position that was supposed to be removed
    nodeToRemove->val = largestValue->val;
    // free the node
    freeTreeNode(largestValue->rightChild);
  }
  else if ( !nodeToRemove->leftChild && !nodeToRemove->rightChild ) {
    // case 1: both right child and left child are NULL
    if (nodeToRemove->val < parent->val)
      parent->leftChild = NULL;
    else
      parent->rightChild = NULL;
    freeTreeNode(nodeToRemove);
  }
  else if ( !nodeToRemove->leftChild && nodeToRemove->rightChild ) {
    // case 2: leftChild = NULL, rightChild = valid
    if ( nodeToRemove->val < parent->val )
      parent->leftChild = nodeToRemove->rightChild;
    else
      parent->rightChild = nodeToRemove->rightChild;
    freeTreeNode(nodeToRemove);
  }
  else if ( nodeToRemove->leftChild && !nodeToRemove->rightChild) {
    // case 3: leftChild = valid, rightChild = NULL
    if ( nodeToRemove->val < parent->val )
      parent->leftChild = nodeToRemove->leftChild;
    else
      parent->rightChild = nodeToRemove->leftChild;
    freeTreeNode(nodeToRemove);
  }
  else { // case 4: rearrange sub-tree
    treeNode_t *largestValue = nodeToRemove->leftChild;
    while ( largestValue->rightChild ) {
      largestValue = largestValue->rightChild;
    }
    if (parent = findParent(bst->root, largestValue->val) ) {
      // copy the value to the position that was supposed to be removed
      nodeToRemove->val = largestValue->val;
      // free the node
      freeTreeNode(parent->rightChild);
      parent->rightChild = NULL;
    }
  }
  bst->count--;

  return true;
}

int findMin(bst_t *bst) {
  if (!bst) return INT_MIN;

  Trace();
  return findMinHelper(bst->root);
}

int findMax(bst_t *bst) {
  if (!bst) return INT_MAX;

  Trace();
  return findMaxHelper(bst->root);
}

int *preOrder(bst_t *bst) {
  if (!bst) return NULL;

  Trace();
  int *result = (int * )malloc(bst->count*sizeof(int));
  assert(result);
  int index = 0;
  preOrderHelper(bst->root, result, &index);

  return result;
}

int *postOrder(bst_t *bst) {
  if (!bst) return NULL;

  Trace();
  int *result = (int * )malloc(bst->count*sizeof(int));
  assert(result);
  int index = 0;
  postOrderHelper(bst->root, result, &index);

  return result;
}

int *inOrder(bst_t *bst) {
  if (!bst) return NULL;

  Trace();
  int *result = (int * )malloc(bst->count*sizeof(int));
  assert(result);
  int index = 0;
  inOrderHelper(bst->root, result, &index);

  return result;
}

int *breadthFirst(bst_t *bst) {
  if (!bst) return NULL;

  Trace();
  int *result = (int * )malloc(bst->count*sizeof(int));
  assert(result);

  mcq_t *q = CreateQueue(bst->count);
  int index = 0;
  treeNode_t *cur = bst->root;
  while ( cur ) {
    result[index++] = cur->val;

    if ( cur->leftChild )
      EnQueue(q, cur->leftChild);

    if ( cur->rightChild )
      EnQueue(q, cur->rightChild);

    if ( !IsEmpty(q) ) {
      cur = Front(q);
      DeQueue(q);
    }
    else
      cur = NULL;
  }

  DestroyQueue(q);

  return result;
}

