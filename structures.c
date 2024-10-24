#include<stdio.h>
typedef  struct
{
    int regno;
    char name[50];
    float marks;
}student;

int main(){
    student s1;
    s1.regno=183;
    sprintf(s1.name, "Harry");
    s1.marks=92.0;
    printf("Student details\n");
    printf("Registration Number : %d\n", s1.regno);
    printf("Name : %s\n", s1.name);
    printf("Marks : %.2f", s1.marks);
    return 0;
}
