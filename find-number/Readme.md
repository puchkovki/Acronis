# **Find number**

You have the integer sequence from 0 to `M` (not inclusive): [0;M). We'll call it `sequence`.

**Input** — unordered array of integer numbers of size `M-n`.

**Output** — array of missing numbers in the `sequence`.
> Example:
```
M = 5, arraySize = 3, array = {4, 1, 3}
Output = {0, 2}
```
## **Solution**
Let's allocate auxiliary array (size `M`) and marking all input `M-n` numbers by one-time array traverse. Then go through the array and output all unmarked elements.

It takes `O(M)` memory and time.

## **Build**

 - Run `build.sh` file.
 - Or run in any UNIX shell:
```
g++ -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align \
-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
-fstack-protector -o test solution.cpp & ./test
```