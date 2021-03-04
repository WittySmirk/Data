#include "linkedList.h"
#include "stdio.h"

int main(){
    LList* list = cLL();
    for(int i = 0; i < 100; i++){
        lAddN(list, i);
    }
    
    printf("%d\n", list->length);
    printf("Removed %d\n", lRemoveAt(list, 50));
    printf("%d\n", list->length);
}