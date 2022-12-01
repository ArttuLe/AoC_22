

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE* file;
    char ch;
    char buff[16];
    int i;
    int max, sum;
    int second, third;

    file = fopen("input.txt", "r");

    if (NULL == file) {
        printf("Cant open file...");
    };

    max = 0;
    sum = 0;
    third = 0;
    second = 0;

    while (fgets(buff, 16, file) != NULL) {
        i++;
        if(buff[0] != '\n') {
            int num = atoi(buff); //Should probably use strtol instead?
            sum += num;

        }else{
            if (sum > third && sum < second){
                third = sum;
                sum = 0;

            }else if(sum > second && sum < max){
                second = sum;
                sum = 0;

            }else if(sum > max){
                max = sum;
                sum = 0;
                
            };
            sum = 0;
        };
    };

    printf("Return Value is: %d\n",(max+second+third));

    return 0;
}

