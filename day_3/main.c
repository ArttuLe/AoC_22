
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int calculate_part_one(char* buff);
int calculate_part_two(char* buff);

int main(void) {

#define LINESIZE 50

    FILE* file;
    char *buff, *line;
    int num_lines = 300;

    file = fopen("input.txt", "r");

    if (NULL == file) {
        printf("Cant open file...");
        
        return -1;
    }

    //Allocate memory for the input.txt TODO: Dynamic LINESIZE?
    buff = (char*)malloc(num_lines * LINESIZE * sizeof(char));

    line = buff;

    // Read lines from input.txt into a buffer
    while (fgets(line, LINESIZE, file) != NULL) {
        if (!(strlen(line) == LINESIZE-1 && line[LINESIZE-2] != '\n'))
            line += LINESIZE;
    }

    fclose(file);

    //printf("%s\n", &buff[LINESIZE*row]);

    int sum = 0;

    for(int j = 0; j < 300;j++){
        //Calculate priority of one line
        sum += calculate_part_one(&buff[LINESIZE*j]);
    }

    printf("%d\n",sum);

    return 0;
}


int calculate_part_one(char* buff){

    size_t sum = 0;
    size_t len = 0;
    int half;

    //printf("%s", buff);

    //Get num of characters
    for (int l = 0; l < 50;l++){
        if(buff[l] != '\0' && buff[l] != '\n')
            len += 1;
    }

    half = (len / 2);

    printf("Length: %ld\n", len);

    for (size_t i = 0;i < half;i++){
        for (size_t j = half;j < len;j++){
            if (buff[i] == buff[j]){

                int ascii = buff[i];
                if (ascii <= 90){
                    sum += ascii-38;
                    return sum;
                }else
                    sum += ascii-96;
                    return sum;
            }
        }
    }
}
//Upper case 65-90 ASCII -> priorities: ASCII-38 -> 27-52
// Lower case 97-122 -> priorities: ASCII-96 -> 1-26

