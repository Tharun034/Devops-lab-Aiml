#include <stdio.h> 
#include <math.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsackBruteForce(int n, int weight[], int profit[], int capacity) {
    int maxProfit = 0;
    int totalSubsets = pow(2, n);

    for(int i = 0; i < totalSubsets; i++) {
        int totalWeight = 0;
        int totalProfitSubset = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                totalWeight += weight[j];
                totalProfitSubset += profit[j];
            }
        }
        if(totalWeight <= capacity) {
            maxProfit = max(maxProfit, totalProfitSubset);
        }
    }
    return maxProfit;
}
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int weight[n], profit[n];
    printf("Enter weights:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    printf("Enter profits:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    int result = knapsackBruteForce(n, weight, profit, capacity);
    printf("Maximum Profit = %d\n", result);
    return 0;
}

