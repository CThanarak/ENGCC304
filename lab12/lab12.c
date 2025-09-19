#include <stdio.h>
#include <string.h>

struct Student {
    char Name[20] ;
    char ID[5] ;
    float ScoreSub1 ;
    float ScoreSub2 ;
    float ScoreSub3 ;
    float ScoreSub4 ;
    float ScoreSub5 ;
} typedef S ;

void gradeFromScore(float s, char out[]) {
    if (s >= 80) strcpy(out, "A");
    else if (s >= 75) strcpy(out, "B+");
    else if (s >= 70) strcpy(out, "B");
    else if (s >= 65) strcpy(out, "C+");
    else if (s >= 60) strcpy(out, "C");
    else if (s >= 55) strcpy(out, "D+");
    else if (s >= 50) strcpy(out, "D");
    else strcpy(out, "F");
}

void inputStudent(S students[], int n) {
    printf("Student %d:\n", n + 1);
    printf("Name:\n");
    scanf(" %[^\n]", students[n].Name);
    printf("ID:\n");
    scanf("%s", students[n].ID);

    printf("Scores in Subject 1:\n");
    scanf("%f", &students[n].ScoreSub1);
    printf("Scores in Subject 2:\n");
    scanf("%f", &students[n].ScoreSub2);
    printf("Scores in Subject 3:\n");
    scanf("%f", &students[n].ScoreSub3);
    printf("Scores in Subject 4:\n");
    scanf("%f", &students[n].ScoreSub4);
    printf("Scores in Subject 5:\n");
    scanf("%f", &students[n].ScoreSub5);
    printf("\n");
}

void printStudent(S students[], int n) {

    char g1[3], g2[3], g3[3], g4[3], g5[3];
    gradeFromScore(students[n].ScoreSub1, g1);
    gradeFromScore(students[n].ScoreSub2, g2);
    gradeFromScore(students[n].ScoreSub3, g3);
    gradeFromScore(students[n].ScoreSub4, g4);
    gradeFromScore(students[n].ScoreSub5, g5);

    printf("Student %d:\n", n + 1);
    printf("Name: %s\n", students[n].Name);
    printf("ID: %s\n", students[n].ID);
    printf("Scores: %.0f %.0f %.0f %.0f %.0f\n",
           students[n].ScoreSub1, students[n].ScoreSub2,
           students[n].ScoreSub3, students[n].ScoreSub4,
           students[n].ScoreSub5);
    printf("Grades: %s %s %s %s %s\n", g1, g2, g3, g4, g5);
    printf("\n");
}

int main() {
    S students[3];

    printf("Enter the details of 3 students :\n");
    for (int i = 0; i < 3; i++) {
        inputStudent(students, i);
    }

    for (int i = 0; i < 3; i++) {
        printStudent(students, i);
    }

    return 0;
}