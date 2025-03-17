#include <stdio.h>

typedef long long(*long_function_pointer)(int parameter);

long long fibonacci(int numbers);

long_function_pointer fibonacci_provider;

//Cache
#define Max_Memoized 100
#define Array_size (Max_Memoized +1)
#define Not_Present -1

long_function_pointer _original_provider;
long long _memoization_data[Array_size];

long long cache_function(int numbers){
    if(numbers > Max_Memoized){
        return (*_original_provider)(numbers);
    }

    if(_memoization_data[numbers] == Not_Present){
        _memoization_data[numbers] = (*_original_provider)(numbers);
    }

    return _memoization_data[numbers];
}

long_function_pointer init_cache(long_function_pointer real_provider){
    for(int i = 0; i < Array_size; i++){
        _memoization_data[i] = Not_Present;
    }
    _original_provider = real_provider;
    return cache_function;
}

//Fibonacci process
long long fibonacci(int numbers){
    if (numbers < 2){
        return numbers;
    }

    return (*fibonacci_provider)(numbers - 1) + (*fibonacci_provider)(numbers - 2);
}

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