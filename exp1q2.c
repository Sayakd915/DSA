#include <stdio.h>

#define MAX_STUDENTS 5
#define MAX_SUBJECTS 3

typedef struct {
    char name[20];
    int roll_no;
    struct {
        int maths;
        int science;
        int english;
    } marks;
} Student;

void calculate_total_and_grade(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        int total = students[i].marks.maths + students[i].marks.science + students[i].marks.english;
        char grade;

        if (total >= 270) {
            grade = 'A';
        } else if (total >= 240) {
            grade = 'B';
        } else if (total >= 210) {
            grade = 'C';
        } else {
            grade = 'F';
        }

        printf("Student %d: %s\n", i + 1, students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Marks: Maths - %d, Science - %d, English - %d\n", students[i].marks.maths, students[i].marks.science, students[i].marks.english);
        printf("Total: %d\n", total);
        printf("Grade: %c\n\n", grade);
    }
}

int main() {
    Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter student %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks: Maths - ");
        scanf("%d", &students[i].marks.maths);
        printf("Science - ");
        scanf("%d", &students[i].marks.science);
        printf("English - ");
        scanf("%d", &students[i].marks.english);
        printf("\n");
    }

    calculate_total_and_grade(students, MAX_STUDENTS);

    return 0;
}2