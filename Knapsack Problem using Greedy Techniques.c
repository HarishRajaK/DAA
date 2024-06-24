#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void knapsack(struct Item arr[], int n, int W) {
    int curWeight = 0;
    float finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((float)remain / arr[i].weight);
            break;
        }
    }
    printf("Maximum value in Knapsack = %.2f", finalValue);
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);
    knapsack(arr, n, W);
    return 0;
}
