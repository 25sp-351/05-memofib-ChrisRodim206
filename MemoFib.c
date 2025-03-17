#include <stdio.h>
#include "fibonacci.h"

int main(){
    fibonacci_provider = init_cache(fibonacci);

    printf("Enter integers then space for the next integer ");

    char input[200];
    
    if(!fgets(input, sizeof(input), stdin)){
        printf("Error input");
        return 0;
    }

    char *ptr = input;
    int number;
    while(sscanf(ptr, "%d", &number) == 1) {
        if(number < 0) {
            printf("fib(%d) not accepted\n", number);
        }
        else{
            printf("fib(%d) = %lld\n", number, (*fibonacci_provider)(number));
        }
         //move from one pointer to next pointer 
         for(; *ptr != ' ' && *ptr != '\0'; ++ptr);
         for(; *ptr == ' '; ++ptr);
    }

}