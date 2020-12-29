#include "btree.h"
#include <stdio.h>

int main(){
				BTree* tree = cBTree();
				for(int i = 0; i < 10001; i++){
								btAddN(tree, rand());
				}
				bTSort(tree);
				BTNode* foundn = bTSearch(tree, 2144316428);
				if(foundn != NULL)
								printf("found %d", foundn->val);
				bTFree(tree);
}
