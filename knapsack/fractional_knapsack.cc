#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using std::sort;
using std::cout;
using std::cin;
using std::ios_base;
using std::endl;

// Stucture for Item which store weight and corresponding
// value of Item
struct Item {
  int value;
  int weight;

  // Constructor
  Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
  //    sorting Item on basis of ration
  sort(arr, arr + n, cmp);

  // Uncomment to see new order of Items with their ratio
  /*
    for (int i = 0; i < n; i++) {
    cout << arr[i].value << "  " << arr[i].weight << " : "
    << ((double)arr[i].value / arr[i].weight) << endl;
    }
  */

  int curWeight = 0;  // Current weight in knapsack
  double finalvalue = 0.0;  // Result (value in Knapsack)

  // Looping through all Items
  for (int i = 0; i < n; i++) {
    // If adding Item won't overflow, add it completely
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    } else {  // If we can't add current Item, add fractional part of it
      int remain = W - curWeight;
      finalvalue += arr[i].value * ((double) remain / arr[i].weight);
      break;
    }
  }

  // Returning final value
  return finalvalue;
}

// driver program to test above function
int main() {
  int W = 50;   //    Weight of knapsack
  Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Maximum value we can obtain = "
       << fractionalKnapsack(W, arr, n) << endl;
  return 0;
}
