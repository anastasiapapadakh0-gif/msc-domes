#include <stdio.h>
#include <string.h>

#define N 50 // αριθμός φοιτητών

// ερώτημα 1
struct Student {
    int id;
    char surname[50];
    char name[50];
    char father_name[50];
    char mother_name[50];
    char address[100];
    char landline_phone[15];
    char mobile_phone[15];
    char course[100];
};

int main() {
    // ερώτημα 2
    struct Student students[N];

    for (int i = 0; i < N; i++) {
        printf("--- Enter data for student %d ---\n", i + 1);
        
        printf("Student ID: ");
        scanf("%d", &students[i].id);
        
        printf("Last Name: ");
        scanf("%s", students[i].surname);
        
        printf("First Name: ");
        scanf("%s", students[i].name);
        
        printf("Father's Name: ");
        scanf("%s", students[i].father_name);
        
        printf("Mother's Name: ");
        scanf("%s", students[i].mother_name);
        
        printf("Address: ");
        scanf("%s", students[i].address);
        
        printf("Landline Phone: ");
        scanf("%s", students[i].landline_phone);
        
        printf("Mobile Phone: ");
        scanf("%s", students[i].mobile_phone);
        
        printf("Course: ");
        scanf("%s", students[i].course);
        printf("\n");
    }

    // ερώτημα 3
    struct Student *index_ptr[N]; // πίνακας από δείκτες
    int count = 0;
    char search_course[100];

    printf("Enter course for search: ");
    scanf("%s", search_course);
    
    for (int i = 0; i < N; i++) {
        if (strcmp(students[i].course, search_course) == 0) {
            index_ptr[count] = &students[i]; // δείκτης δείχνει στη διεύθυνση του φοιτητή
            count++;
        }
    }
    
    printf("\nSearch Results for course '%s':\n", search_course);
    if (count == 0) {
        printf("No students found in this course.\n");
    } else {
        for (int i = 0; i < count; i++) {
            // χρησιμοποιώ τον τελεστή -> γιατί έχουμε δείκτη
            printf("ID: %d | Name: %s %s\n", 
                    index_ptr[i]->id, 
                    index_ptr[i]->name, 
                    index_ptr[i]->surname);
        }
    }

    return 0;
}