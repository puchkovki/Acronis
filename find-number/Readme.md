# **Find number**
1. You have sequence from 0 to M: [0;M).
2. Input — unordered array of integer numbers of size M-n.
3. Output — array of missing numbers in input array.
> Example:<br/>
```
M = 5, arraySize = 3, array = {4, 1, 3}
Output = {0, 2}
```
## **Solution**
I'm allocating auxiliary array (size M) and marking all input M-n numbers by one-time array traverse. Then you go through the array and output all unmarked elements.

It takes O(M) memory and time.

## **How to build**

1. Run ```build.sh``` file.
2. Or you may do it in any UNIX shell:

```
g++ -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align \
-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
-fstack-protector -o test solution.cpp
./test
```