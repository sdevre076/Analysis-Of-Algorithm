#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    char name;
    int profit;
    int weight;
    float ratio;
} Item;

// Compare function for qsort (descending order by ratio)
int compare(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;

    if (i2->ratio > i1->ratio) return 1;
    else if (i2->ratio < i1->ratio) return -1;
    else return 0;
}

int main() {
    int n, capacity, wt = 0;
    float totalProfit = 0;

    printf("Enter number of items (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    Item items[MAX];

    // Take input of items
    for (int i = 0; i < n; i++) {
        printf("Enter name, profit, weight of item %d: ", i + 1);
        scanf(" %c %d %d", &items[i].name, &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    // Sort by ratio
    qsort(items, n, sizeof(Item), compare);

    printf("\nItems taken in Knapsack:\n");
    for (int i = 0; i < n && wt < capacity; i++) {
        if (wt + items[i].weight <= capacity) {
            // Take full item
            wt += items[i].weight;
            totalProfit += items[i].profit;
            printf("Item %c -> FULL (Profit = %d)\n", items[i].name, items[i].profit);
        } else {
            // Take fraction
            int remaining = capacity - wt;
            float fraction = (float)remaining / items[i].weight;
            totalProfit += fraction * items[i].profit;
            wt = capacity;
            printf("Item %c -> %.2f fraction (Profit = %.2f)\n",
                   items[i].name, fraction, fraction * items[i].profit);
            break; // bag is full
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
