#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char fileName[100];
char query[1000];
char line[255];
int uppers = 0;
int lowers = 0;

int main(int argc, char *argv[]) {
        if (argc != 4) {
            printf("Not Provided with enough files! only provided with %d", (argc -1));
        }
    FILE *file = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "w");
    FILE *file3 = fopen(argv[3], "w");
    while (fgets(line, 255, file)){
    if (strlen(line) < 20){
        //get line
        // check if under 20 chars
        for (int i = 0; i< strlen(line); i++){
        line[i] = toupper(line[i]);
        }
        uppers++;
        fputs(line, file2);
    } else {
        // check if over 20 chars
        for (int i = 0; i< strlen(line); i++){
         line[i] = tolower(line[i]);   
        }
        lowers++;
        fputs(line, file3);
    }
    }
    printf("%d Lines had less than 20 characters\n", uppers);
    printf("%d Lines had more than 20 characters\n", lowers);
    
    fclose(file);
    fclose(file2);
    fclose(file3);
}