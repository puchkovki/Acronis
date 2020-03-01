# **FizzBuzz**
1. Input - sequence of numbers.
2. If number is divizible by 3, replace it with fizz.
3. If number is divizible by 5, replace it with buzz.
4. If both, then fizzbuzz.
5. Output to the console.<br/>
*Division operation and modulo operation are prohibited*
## **Solution**
I'm allocating auxiliary array (size M) and marking all input M-n numbers by one-time array traverse. Then you go through the array and output all unmarked elements.

It takes O(M) memory and time.

## **How to build**

1. Run ```build.sh``` file.
2. Or you may do it in any UNIX shell:

```
g++ -Wall -Wextra -pedantic -std=c++17 -O3 -o test solution.cpp
 ./test
```