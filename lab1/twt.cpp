#include <stdio.h>
#include <string.h>
//int sum(int a,int b){
//    return a + b;
//}
//
//int (*p)(int, int);



//void *sum(void *a, void *b) {
//    return a + b;
//}

int stringCompare(void* str1, void* str2){
    return (int) strcmp((char*)str1, (char*)str2);
}

void* min(void* el1, void* el2, int(*comp)(void*, void*)){
    int a = comp(el1, el2);
    printf("%d", comp(el1, el2));
    switch (a) {
        case 0: return el1;
        case 1: return el2;
        case 2: return 0;
    }
    return NULL;
}

int main() {
//    p = &sum;
//    printf("%d", p(1,3));
    char str1[] = "Hello";
    char str2[] = "wd!";
    printf("%d", strcmp(str1, str2));
    printf("%s", (char *) min(str1, str2, stringCompare));
    return 0;
}
