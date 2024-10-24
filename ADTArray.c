#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray*a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize*sizeof(int));
}

void show(struct myArray a){
    int i;
    printf("The array is : ");
    for (i = 0; i < a.used_size; i++) {
        printf("%d ",(a.ptr)[i]);
    }
}

void setval(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i]=n;
    }
}

int main()
{
    struct myArray marks; 
    createArray(&marks, 10, 5);
    setval(&marks);
    show(marks);
    return 0;
}