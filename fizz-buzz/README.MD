# **FizzBuzz**
1. Input - sequence of numbers.
2. If number is divizible by 3, replace it with fizz.
3. If number is divizible by 5, replace it with buzz.
4. If both, then fizzbuzz.
5. Output to the console.<br/>
*Division operation and modulo operation are prohibited*
## **Solution**
At first we should test an input value whether it is number and not overflowing long long type. Then we are moving to the checking number's divisibility by 3 and 5.

Function `divisible_by_5` checks the number whether it is divisible by 5 or not: if it ends with 5 or 0, then it is divisible by 5.

Function `divisible_by_3` checks the number whether it is divisible by 3 or not: if the sum of number's numerals is divisible by 3, then the whole number too. I made an iterative algorithm which continues until the number after "summation" won't become a numeral. 0, 3, 6, 9 are the only numerals which are divisible by 3.

## **How to build**

1. Run ```build.sh``` file.
2. Or you may do it in any UNIX shell:

```
g++ -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align \
-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
-fstack-protector -o test solution.cpp
./test
```