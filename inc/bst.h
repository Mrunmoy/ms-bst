#ifndef MS_BST_BST_H
#define MS_BST_BST_H

/**
 *  @file bst.h
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
typedef struct treeNode_t {
  int val;
  struct treeNode_t *leftChild;
  struct treeNode_t *rightChild;
}treeNode_t, *treeNodePtr_t;

typedef struct bst_t {
  treeNodePtr_t root;
  int count;
}bst_t;

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

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/

extern bst_t *createNewBST(void);
extern void destroyBST(bst_t *bst);
extern bool insertTreeNode(bst_t *bst, int val);
extern bool hasItem(bst_t *bst, int val);
extern bool removeItem(bst_t *bst, int val);

// max, min
extern int findMin(bst_t *bst);
extern int findMax(bst_t *bst);

// traversals
extern int *preOrder(bst_t *bst);
extern int *postOrder(bst_t *bst);
extern int *inOrder(bst_t *bst);
extern int *breadthFirst(bst_t *bst);


#ifdef __cplusplus
}
#endif

#endif //MS_BST_BST_H

