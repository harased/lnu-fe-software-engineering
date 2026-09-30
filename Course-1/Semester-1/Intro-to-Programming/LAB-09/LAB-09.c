#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PEOPLE 20

void reverse_string(char* str) {
    int start = 0;
    int end = (int)strlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}


int is_valid_ascii(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = str[i];
        if (!isalnum(c) && c != '.' && c != '-' && c != '_' && c != '@') {
            return 0; 
        }
    }
    return 1;
}

typedef struct {
    int id;
    char surname[50];
    char name[50];
} Person;

int main() {
    Person team[MAX_PEOPLE];
    char buff1[128];
    int count1 = 0;

    printf("=== Input list (Format : Number Surname Name) ===\n");
    printf("Enter at least 10 participants. Enter '0' or an empty line to finish :\n\n");

    while (count1 < MAX_PEOPLE) {
        printf("[%d] ", count1 + 1);
        if (!fgets(buff1, sizeof(buff1), stdin)) break;

        buff1[strcspn(buff1, "\r\n")] = '\0';

        if (strlen(buff1) == 0 || strcmp(buff1, "0") == 0) {
            if (count1 < 10) {
                printf("Warning : You entered fewer than 10 participants (%d). Please continue:\n", count1);
                continue;
            }
            break;
        }

        if (sscanf(buff1, "%d %s %s", &team[count1].id, team[count1].surname, team[count1].name) == 3) {
            count1++;
        }
        else {
            printf("Format error! Enter using pattern: Number Surname Name (e.g. 10 Shevchenko Andriy)\n");
        }
    }

    if (count1 == 0) {
        printf("List is empty.\n");
        return 0;
    }

    int unique_names_count = 0;
    int total_surname_length = 0;

    for (int i = 0; i < count1; i++) {
        total_surname_length += (int)strlen(team[i].surname);

        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(team[i].name, team[j].name) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_names_count++;
        }
    }

    double avg_surname_len = (double)total_surname_length / count1;

    printf("\n=== Analysis Results ===\n");
    printf("1) Number of unique names: %d\n", unique_names_count);
    printf("2) Average surname length: %.2f characters\n", avg_surname_len);

    for (int i = 0; i < count1 - 1; i++) {
        for (int j = 0; j < count1 - i - 1; j++) {
            int cmp = strcmp(team[j].name, team[j + 1].name);

            if (cmp == 0) {
                cmp = strcmp(team[j].surname, team[j + 1].surname);
            }

            if (cmp > 0) {
                Person temp = team[j];
                team[j] = team[j + 1];
                team[j + 1] = temp;
            }
        }
    }

    printf("\n=== Sorted List (Number Name Surname) ===\n");
    for (int i = 0; i < count1; i++) {
        printf("%d %s %s\n", team[i].id, team[i].name, team[i].surname);
    }


    char email[111];
    char temp[111];

    printf("Enter a email : ");
    fgets(email, sizeof(email), stdin);

    email[strcspn(email, "\r\n")] = '\0';

    if (!is_valid_ascii(email)) {
        printf("Invalid email : contains invalid characters or cyrylycya\n");
        return 0;
    }

    strcpy(temp, email);

    int at_count = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_count++;
        } 
        
    }

    if (at_count != 1) {
        printf("Invalid email : must contain exactly one '@'.\n");
        return 0;
    }

    char* prefix = strtok(temp, "@");
    char* domain = strtok(NULL, "@");

    if (prefix == NULL || domain == NULL) {
        printf("Invalid email: missing prefix or domain.\n");
        return 0;
    }

    int dot_count = 0;
    int domain_len = (int)strlen(domain);

    for (int i = 0; i < domain_len; i++) {
        if (domain[i] == '.') {
            dot_count++;
        }
    }

    if (domain[0] == '.' || domain[domain_len - 1] == '.') {
        printf("Invalid email : dot cannot be at the start or end of domain.\n");
        return 0;
    }

    if (dot_count >= 1) {
        printf("Valid email! User : %s | Domain : %s\n", prefix, domain);
    }
    else {
        printf("Invalid email : domain must contain at least one dot.\n");
    }

    char buff[111];
    char* words[67];
    const char* delim = " \n\t,.-!?";

    printf("Enter a string : ");
    fgets(buff, sizeof(buff), stdin);

    char* token = strtok(buff, delim);

    int word_count = 0;

    while (token != NULL) {
        words[word_count] = token;
        word_count++;
        token = strtok(NULL, delim);
    }
   
    for (int i = 0; i < word_count; i++) {
        reverse_string(words[i]);
        printf("Word [%d]: %s\n", i, words[i]);
    }

	return 0;
}