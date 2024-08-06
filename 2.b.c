#include <stdio.h>

struct info {
    int roll_no;
    char name[50];
    float CGPA;
};

int main() {
    struct info student[50];
    int n;

    printf("Enter the number of students (max 50): ");
    scanf("%d", &n);

    if (n > 50) {
        printf("Error: Maximum number of students is 50.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        student[i].roll_no = i + 1;

        printf("Enter name for Student %d: ", i + 1);
        scanf("%49s", student[i].name);

        printf("Enter CGPA for Student %d: ", i + 1);
        scanf("%f", &student[i].CGPA);
    }

    printf("\nStudent Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, CGPA: %f\n", 
               student[i].roll_no, student[i].name, student[i].CGPA);
    }

    return 0;
}