

#include <stdio.h>
#include <stdlib.h>


/*
A ROCK 1
B PAPER 2
C SCISSORS 3

X ROCK 1 
Y PAPER 2
Z SCISSORS 3
*/

int main(void){

    FILE* file;
    char buff[4];
    int i;
    int sum;
    sum = 0;
    
    file = fopen("input.txt", "r");

    if (NULL == file) {
        printf("Cant open file...");
    };

    while (fgets(buff, 4, file) != NULL) {
        i++;
        //printf("%s", buff);
        char opp = buff[0];
        char you = buff[2];

        switch(opp){

            case 'A':
                if (you == 'Y'){
                    sum += 8;
                }
                else if( you == 'X'){
                    sum += 4;
                }else if(you == 'Z'){
                    sum += 3;
                };
                break;

            case 'B':
                if (you == 'Z'){
                    sum += 9;
                }
                else if( you == 'Y'){
                    sum += 5;
                }else if(you == 'X'){
                    sum += 1;
                };
                break;

            case 'C':
                if (you == 'X'){
                    sum += 7;
                }
                else if( you == 'Z'){
                    sum += 6;
                }else if(you == 'Y'){
                    sum += 2;
                };
                break;
        }
    }
    
    printf("%d\n",sum);

    return 0;
}