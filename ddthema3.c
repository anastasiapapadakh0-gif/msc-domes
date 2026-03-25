#include <stdio.h>
#include <string.h>

#define N 50 // αριθμός φοιτητών

// ερώτημα 1
struct Student {
    int am;
    char epwnumo[50];
    char onoma[50];
    char patrwnumo[50];
    char mhtrwnumo[50];
    char dieuthinsh[100];
    char stathero[15];
    char kinhto[15];
    char mathima[100];
};

int main() {
    // ερώτημα 2
    struct Student students[N];

    for (int i = 0; i < N; i++) {
        printf("--- Eisagwgh Stoixeiwn Foithth %d ---\n", i + 1);
        
        printf("Arithmos Mhtrwou: ");
        scanf("%d", &students[i].am);
        
        printf("Epwnumo: ");
        scanf("%s", students[i].epwnumo);
        
        printf("Onoma: ");
        scanf("%s", students[i].onoma);
        
        printf("Patrwnumo: ");
        scanf("%s", students[i].patrwnumo);
        
        printf("Mhtrwnumo: ");
        scanf("%s", students[i].mhtrwnumo);
        
        printf("Dieuthinsh: ");
        scanf("%s", students[i].dieuthinsh);
        
        printf("Stathero Thlefwno: ");
        scanf("%s", students[i].stathero);
        
        printf("Kinhto Thlefwno: ");
        scanf("%s", students[i].kinhto);
        
        printf("Mathima: ");
        scanf("%s", students[i].mathima);
        printf("\n");
    }

    // ερώτημα
    struct Student *index_ptr[N]; // πίνακας από δείκτες
    int count = 0;
    char search_course[100];

    printf("Dwste mathima gia anazhthsh: ");
    scanf("%s", search_course);

    
    for (int i = 0; i < N; i++) {
        if (strcmp(students[i].mathima, search_course) == 0) {
            index_ptr[count] = &students[i]; // δείκτης δείχνει στη διεύθυνση του φοιτητή
            count++;
        }
    }

    
    printf("\nApotelemata anazhthshs gia '%s':\n", search_course);
    if (count == 0) {
        printf("Den vrethikan foithtes se auto to mathima.\n");
    } else {
        for (int i = 0; i < count; i++) {
            // χρησιμοποιώ τον τελεστή -> γιατί έχουμε δείκτη
            printf("AM: %d | Onoma: %s %s\n", 
                    index_ptr[i]->am, 
                    index_ptr[i]->onoma, 
                    index_ptr[i]->epwnumo);
        }
    }

    return 0;
}