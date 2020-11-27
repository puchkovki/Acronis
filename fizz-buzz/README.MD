# **FizzBuzz**

**Input** - sequence of numbers.

Task:
 - If number is divizible by 3, replace it with fizz.
 - If number is divizible by 5, replace it with buzz.
 - If both, then fizzbuzz.
 - Output to the console.

**Division operation and modulo operation are prohibited.**
## **Solution**

1. Test an input value whether it is number and not overflowing long long type. 
2. Check number's divisibility by 3 and 5.

Function `divisible_by_5` checks whether the number is divisible by 5: if it ends with 5 or 0, then it is true.

Function `divisible_by_3` checks whether the number is divisible by 3: the sum of number's numerals should be divisible by 3. Program uses an iterative algorithm which continues until the number after "summation" won't become a numeral. `{0, 3, 6, 9}` are the only numerals divisible by 3.

## **Build**

 - Run `build.sh` file.
 - Run in any UNIX shell:

```
g++ -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align \
-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
-fstack-protector -o test solution.cpp & ./test
```