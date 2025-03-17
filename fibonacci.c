#include "fibonacci.h"
#define Max_Memoized 100
#define Array_size (Max_Memoized +1)
#define Not_Present -1

long_function_pointer _original_provider;
long_function_pointer fibonacci_provider;
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