#ifndef BTREE_H
#define BTREE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct BTNODE_STRUCT {
				int val;
				struct BTNODE_STRUCT * left;
				struct BTNODE_STRUCT* right;
}BTNode;

typedef struct BTREE_STRUCT {
				BTNode* root;
				int tmp;
				int length;
}BTree;

void bnAddN(BTree* p_t, BTNode* p_this, BTNode* p_n){
				if(p_n->val < p_this->val) {
								if(p_this->left == NULL){
												p_t->length++;
												p_this->left = p_n;
								} else {
												bnAddN(p_t, p_this->left, p_n);
								}
				} else if(p_n->val > p_this->val){
								if(p_this->right == NULL){
												p_t->length++;
												p_this->right = p_n;
								} else {
												bnAddN(p_t, p_this->right, p_n);
								}
				}
}

BTNode* cBTNode(int p_v) {
				BTNode* n = malloc(sizeof(struct BTNODE_STRUCT));
				n->left = NULL;
				n->right = NULL;
				n->val = p_v;
				return n;
}

BTree* cBTree() {
				BTree* t = malloc(sizeof(struct BTREE_STRUCT));
				t->root = NULL;
				t->tmp = 0;
				t->length = 0;
				return t;
}

void btAddN(BTree* p_t, int p_v){
				BTNode* n = cBTNode(p_v);
				if(p_t->root == NULL){
								p_t->length++;
								p_t->root = n;
				} else {
								bnAddN(p_t, p_t->root, n);
				}
}

void bTNVisit(BTNode* p_n, BTree* p_t){
				if(p_n->left != NULL)
								bTNVisit(p_n->left, p_t);
				printf("%d \n", p_n->val);
				if(p_n->right != NULL)
								bTNVisit(p_n->right, p_t);
}

BTNode* bTNSearch(BTNode* p_n, int p_val){
				if(p_n->val == p_val){
								return p_n;
				} else if(p_val < p_n->val && p_n->left != NULL){
								bTNSearch(p_n->left, p_val);
				} else if(p_val > p_n->val && p_n->right != NULL){
								bTNSearch(p_n->right, p_val);
				}
}

void bTSort(BTree* p_t){
				bTNVisit(p_t->root, p_t);
}

BTNode* bTSearch(BTree* p_t, int p_val){
				BTNode* n = bTNSearch(p_t->root, p_val);
				return n;
}

void bTNFree(BTNode* p_n){
				if(p_n->left != NULL){
								bTNFree(p_n->left);
				} else if(p_n-> right != NULL){
								bTNFree(p_n->right);
				} else {
								free(p_n);
				}
}

void bTFree(BTree* p_t){
	if(p_t->root != NULL){
		bTNFree(p_t->root);
	} else {
		free(p_t);
	}
}

#endif
