#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "stdlib.h"

typedef struct LNODE_STRUCT {
    int  element;
    struct LNODE_STRUCT* next;
}LNode;

typedef struct LLIST_STRUCT {
    int length;
    LNode* head;
}LList;

LNode* cLN(int element){
    LNode* n = malloc(sizeof(struct LNODE_STRUCT));
    n->element = element;
    n->next = NULL;
    return n;
}

LList* cLL(){
    LList* l = malloc(sizeof(struct LLIST_STRUCT));
    
    l->head = NULL;
    l->length = 0;

    return l;
}

void lAddN(LList* list, int element){
    LNode* n = cLN(element);
    if(list->head == NULL) list->head = n;
    else {
      LNode* cN = list->head;

      while(cN->next){
          cN = cN->next;
      }  

      cN->next = n;
    }

    list->length++;
}

void lRemoveN(LList* list, int element){
    LNode* cN = list->head;
    LNode* pN;

    if(cN->element == element) list->head = cN->next;
    else {
        while(cN->element != element){
            pN = cN;
            cN = cN->next;
        }

        pN->next = cN->next;
    }

    list->length--;
}

int lIndexOfN(LList* list, int element){
    LNode* cN = list->head;
    int index = -1;

    while(cN){
        index++;
        if(cN->element == element) return index;
    }

    return -1;
}

int lElementAt(LList* list, int index){
    LNode* cN = list->head;
    int count = 0;
    while(count < index){
        count++;
        cN = cN->next;
    }
    return cN->element;
}

void lAddAt(LList* list, int index, int element){
    LNode* n = cLN(element);
    LNode* cN = list->head;
    LNode* pN;
    int cI = 0;

    if(index == 0){
        n->next = cN;
        list->head = n;
    } else {
        while (cI < index){
            cI++;
            pN = cN;
            cN = cN->next;
        }
        n->next = cN;
        pN->next = n;
    }
    list->length++;
}

int lRemoveAt(LList* list, int index){
    LNode* cN = list->head;
    LNode* pN;
    int cI = 0;

    if(index == 0) list->head = cN->next;
    else {
        while(cI < index){
            cI++;
            pN = cN;
            cN = cN->next;
        }
        pN->next = cN->next;
    }
    list->length--;
    return cN->element;
}

void lNFree(LNode* n){
    LNode* cN;
    if(n->next){
        cN = n->next;
        lNFree(cN);
    } else free(n);
}

void lFree(LList* list){
    while(list->head){
        lNFree(list->head);
    }
    free(list);
}

#endif
