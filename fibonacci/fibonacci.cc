// Program for Fibonacci numbers

// The Fibonacci numbers are the numbers in the following integer sequence.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ......
// In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation
//         Fn = Fn-1 + Fn-2
//     with seed values
//        F0 = 0 and F1 = 1.

// Write a function int fib(int n) that returns Fn. For example, if n = 0, then fib() should return 0. If n = 1, then it should return 1. For n > 1, it should return Fn-1 + Fn-2

//     For n = 9
//     Output:34

#include <sys/time.h>
#include <iostream>
using std::cout;
using std::endl;

// Fibonacci Series using Recursion
// Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential. O(2^n).
// Extra Space: O(n) if we consider the function call stack size, otherwise O(1).
// Method 1 (Use recursion)
// int fib(int n) {
//   if (n <= 1)
//     return n;

//   return fib(n-1) + fib(n-2);
// }

// Method 2 (Dynamic Programming)
// Time Complexity: O(n)
// Extra Space: O(n)
// int fib(int n) {
//   int f[n + 1];

//   f[0] = 0;
//   f[1] = 1;
//   for (int i = 2; i <= n; ++i) {
//     f[i] = f[i - 1] + f[i - 2];
//   }

//   return f[n];
// }

// Method 3 (Space Optimized Method 2)
// We can optimize the space used in method 2 by storing the previous two numbers only because that is all we need to get the next Fibonacci number in series.
// Time Complexity: O(n)
// Extra Space: O(1)
// int fib(int n) {
//   int a = 0;
//   int b = 1;
//   int c;

//   if(n <= 1) return n;

//   for (int i = 2; i <= n; ++i) {
//     c = a + b;
//     a = b;
//     b = c;
//   }

//   return b;
// }

// Method 4 (Using power of the matrix {{1,1},{1,0}})
// This another O(n) which relies on the fact that if we n times multiply the matrix M = {{1,1},{1,0}} to itself (in other words calculate power(M, n )), then we get the (n+1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix.
// omplexity: O(n)
// Extra Space: O(1)

/* Helper function that multiplies 2 matrices F and M of size 2*2, and
  puts the multiplication result back to F[][] */
void multiply(int F[2][2], int M[2][2]);

/* Helper function that calculates F[][] raise to the power n and puts the
  result in F[][]
  Note that this function is designed only for fib() and won't work as general
  power function */
void power(int F[2][2], int n);

// int fib(int n) {
//   int F[2][2] = {{1, 1}, {1, 0}};
//   if (n == 0)
//       return 0;
//   power(F, n-1);

//   return F[0][0];
// }

void multiply(int F[2][2], int M[2][2]) {
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

// void power(int F[2][2], int n) {
//   int i;
//   int M[2][2] = {{1, 1}, {1, 0}};

//   // n - 1 times multiply the matrix to {{1,0},{0,1}}
//   for (i = 2; i <= n; i++)
//       multiply(F, M);
// }

/* Optimized version of power() in method 4 */
void power(int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}


const int MAX = 1000;

// Create an array for memoization
int f[MAX] = {0};

// Returns n'th fuibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n])
        return f[n];

    int k = (n & 1)? (n+1)/2 : n/2;

    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
           : (2*fib(k-1) + fib(k))*fib(k);

    return f[n];
}
int main() {
  int n = 9;
  // Starting timing here
  timeval start, end;
  gettimeofday(&start, NULL);

  cout << fib(n) << endl;

  // Stop  timing here
  gettimeofday(&end, NULL);
  cout << (end.tv_sec - start.tv_sec) * 1000. + (end.tv_usec - start.tv_usec) / 1000. << " ms to compute fib." << endl;

  return 0;
}
