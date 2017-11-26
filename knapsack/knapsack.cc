#include <utility>
#include <iostream>

using std::cout;
using std::cin;
using std::max;
using std::ios_base;
using std::endl;

/* A Naive recursive implementation of 0-1 Knapsack problem */
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
// Time complexity: O(2^n).
// Space complexity: O(1).
// int knapSack(int W, int wt[], int val[], int n)
// {
//    // Base Case
//    if (n == 0 || W == 0)
//        return 0;

//    // If weight of the nth item is more than Knapsack capacity W, then
//    // this item cannot be included in the optimal solution
//    if (wt[n-1] > W)
//        return knapSack(W, wt, val, n-1);

//    // Return the maximum of two cases:
//    // (1) nth item included
//    // (2) not included
//    else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
//                     knapSack(W, wt, val, n-1)
//                   );
// }

// A Dynamic Programming based solution for 0-1 Knapsack problem
// A utility function that returns maximum of two integers

// Returns the maximum value that can be put in a knapsack of capacity W
// Time Complexity: O(nW) where n is the number of items and W is the capacity of knapsack.
// int knapSack(int W, int wt[], int val[], int n)
// {
//    int i, w;
//    int K[n+1][W+1];

//    // Build table K[][] in bottom up manner
//    for (i = 0; i <= n; i++)
//    {
//        for (w = 0; w <= W; w++)
//        {
//            if (i==0 || w==0)
//                K[i][w] = 0;
//            else if (wt[i-1] <= w)
//                  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
//            else
//                  K[i][w] = K[i-1][w];
//        }
//    }

//    return K[n][W];
// }

int knapsack(int value[], int weight[], int n_items, int maixumWeight) {
  int dp[n_items+1][maixumWeight+1];

  for (int w = 0; w <= maixumWeight; w++)
    dp[0][w] = 0;

  for (int i = 0; i <= n_items; i++)
    dp[i][0] = 0;

  for (int i = 1; i <= n_items; i++) {
    for (int w = 1; w <= maixumWeight; w++) {
      if (weight[i-1] <= w)
        dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],  dp[i-1][w]);
      else
        dp[i][w] = dp[i-1][w];
    }
  }

  return dp[n_items][maixumWeight];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int value[] = {12, 1000, 30, 10, 1000};
  int weight[] = {19, 120, 20, 1, 120};
  int n_tems = 5;
  int  maixumWeight = 40;

  // int value[] = {5, 3, 5, 3, 2};
  // int weight[] = {1, 2, 4, 2, 5};
  // int n_tems = 5;
  // int  maixumWeight = 10;

  cout << knapsack(value, weight, n_tems, maixumWeight) << endl;  // values of the items, weights, number of items and the maximum weight
  return 0;
}
