#!/bin/bash

# Compile the C code
gcc -o MemoFib MemoFib.c -Wall -Wextra

# Check if compilation was successful
if [[ ! -f "MemoFib" ]]; then
    echo "Compilation failed."
    exit 1
fi

# Test case function
test_case() {
    input=$1           
    expected=$2                    
    output=$(echo "$input" | ./MemoFib)  

    # Print the actual program 
    echo "Input: $input"
    echo "Program Output:"
    echo "$output"
    echo "Expected Output: $expected"

    # Check if expected output is in the actual output
    if echo "$output" | grep -q "$expected"; then
        echo " Test Passed"
    else
        echo " Test Failed"
    fi
    echo "----------------------"
}

# Test cases 
test_case "0" "fib(0) = 0"
test_case "1" "fib(1) = 1"
test_case "2" "fib(2) = 1"
test_case "3" "fib(3) = 2"
test_case "4" "fib(4) = 3"
test_case "5" "fib(5) = 5"
test_case "6" "fib(6) = 8"
test_case "25" "fib(25) = 75025"
test_case "50" "fib(50) = 12586269025"
test_case "70" "fib(70) = 190392490709135"
test_case "99" "fib(99) = 218922995834555169026"

# Negative case (input is not accepted for negative numbers)
test_case "-1" "fib(-1) not accepted"

# Clean up 
rm -f MemoFib
