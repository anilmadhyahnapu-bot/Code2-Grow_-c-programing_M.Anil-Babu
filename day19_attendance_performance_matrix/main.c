#include <stdio.h>
int main() {
int attendance[5][5];
int marks[5][5];
char names[5][20];
int i, j, choice;
printf("Enter names of 5 students:");
for (i = 0; i < 5; i++) {
 printf("Student %d name: ", i + 1);
 scanf("%s", names[i]);
}
printf("Enter attendance for 5 students (1 for Present, 0 for Absent) for 5 subjects:");
for (i = 0; i < 5; i++) {
printf("Attendance for %s:", names[i]);
for (j = 0; j < 5; j++) {
printf(" Subject %d: ", j + 1);
scanf("%d", &attendance[i][j]);
while (attendance[i][j] != 0 && attendance[i][j] != 1) {
printf("Invalid input. Enter 1 or 0: ");
scanf("%d", &attendance[i][j]);
}}}
printf("Enter marks for 5 students for 5 subjects (0-100):");
for (i = 0; i < 5; i++) {
printf("Marks for %s:", names[i]);
for (j = 0; j < 5; j++) {
scanf("%d", &marks[i][j]);
while (marks[i][j] < 0 || marks[i][j] > 100) {
printf("Invalid input. Enter marks between 0 and 100: ");
scanf("%d", &marks[i][j]);
}}}
do {
printf("========= MENU =========");
printf("1. Display Attendance Matrix");
printf("2. Display Marks Matrix");
printf("3. Attendance Report");
printf("4. Performance Report");
printf("5. Grade Report");
printf("6. Exit");
printf("========================");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Attendance Matrix:");
printf("Student  Sub1 Sub2 Sub3 Sub4 Sub5");
for (i = 0; i < 5; i++) {
printf("%-13s", names[i]);
for (j = 0; j < 5; j++) {
printf(" %4d", attendance[i][j]);
}
printf("");
}
break;
case 2:
printf("Marks Matrix:");
printf("Student       Sub1 Sub2 Sub3 Sub4 Sub5");
for (i = 0; i < 5; i++) {
printf("%-13s", names[i]);
for (j = 0; j < 5; j++) {
printf(" %4d", marks[i][j]);
}
printf("");
}
break;
case 3: {
int totalAttendance[5], totalAbsences[5];
int maxAttendance = -1, minAttendance = 6, maxIndex = -1, minIndex = -1;
for (i = 0; i < 5; i++) {
totalAttendance[i] = 0;
for (j = 0; j < 5; j++) {
totalAttendance[i] += attendance[i][j];
}
totalAbsences[i] = 5 - totalAttendance[i];
if (totalAttendance[i] > maxAttendance) {
maxAttendance = totalAttendance[i];
maxIndex = i;
}
if (totalAttendance[i] < minAttendance) {
minAttendance = totalAttendance[i];
minIndex = i;
}}
printf("Attendance Report:");
for (i = 0; i < 5; i++) {
printf("%s -> Classes Attended: %d, Absences: %d", names[i], totalAttendance[i], totalAbsences[i]);
}
printf("Highest Attendance: %s (%d classes)", names[maxIndex], maxAttendance);
printf("Lowest Attendance: %s (%d classes)", names[minIndex], minAttendance);
break;
}
case 4: {
int totalMarks[5];
float avgMarks[5];
int maxMarks = -1, minMarks = 501, maxIndex = -1, minIndex = -1;
for (i = 0; i < 5; i++) {
totalMarks[i] = 0;
for (j = 0; j < 5; j++) {
totalMarks[i] += marks[i][j];
}
avgMarks[i] = totalMarks[i] / 5.0;
if (totalMarks[i] > maxMarks) {
maxMarks = totalMarks[i];
maxIndex = i;
}
if (totalMarks[i] < minMarks) {
minMarks = totalMarks[i];
minIndex = i;
}}
printf("Performance Report:");
for (i = 0; i < 5; i++) {
printf("%s -> Total Marks: %d, Average Marks: %.2f", names[i], totalMarks[i], avgMarks[i]);
}
printf("Class Topper: %s (Total Marks: %d)", names[maxIndex], maxMarks);
printf("Lowest Performer: %s (Total Marks: %d)", names[minIndex], minMarks);
break;
}
case 5: {
int totalMarks[5];
float avgMarks[5];
char grades[5];
for (i = 0; i < 5; i++) {
totalMarks[i] = 0;
for (j = 0; j < 5; j++) {
totalMarks[i] += marks[i][j];
}
avgMarks[i] = totalMarks[i] / 5.0;
if (avgMarks[i] >= 90)
grades[i] = '+';
else if (avgMarks[i] >= 80)
grades[i] = 'A';
else if (avgMarks[i] >= 70)
grades[i] = 'B';
else if (avgMarks[i] >= 60)
grades[i] = 'C';
else if (avgMarks[i] >= 50)
grades[i] = 'D';
else
grades[i] = 'F';
}
printf("Grade Report:");
for (i = 0; i < 5; i++) {
printf("%s -> Average Marks: %.2f, Grade: ", names[i], avgMarks[i]);
if (avgMarks[i] >= 90) {
printf("A+");
} else if (avgMarks[i] >= 80) {
printf("A");
} else if (avgMarks[i] >= 70) {
printf("B");
} else if (avgMarks[i] >= 60) {
printf("C");
} else if (avgMarks[i] >= 50) {
printf("D");
} else {
printf("F");
}}}
break;
case 6:
printf("Exiting program. Goodbye.");
break;
default:
printf("Invalid choice. Please try again.");
break;
}} while (choice != 6);
return 0;
}
