#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int id;
    double value;
    double weight;
} Item;

typedef struct Knapsack {
    int capacity;
    int item_count;
    Item* items;
} Knapsack;

double get_value_per_weight(Item item) {
    return item.value / item.weight;
}

int compare_items(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;

    double value_per_weight1 = get_value_per_weight(*item1);
    double value_per_weight2 = get_value_per_weight(*item2);

    if (value_per_weight1 > value_per_weight2) {
        return -1;
    } else if (value_per_weight1 < value_per_weight2) {
        return 1;
    } else {
        return 0;
    }
}

void sort_items(Knapsack* knapsack) {
    qsort(knapsack->items, knapsack->item_count, sizeof(Item), compare_items);
}

double solve_fractional_knapsack(Knapsack* knapsack) {
    double total_value = 0;
    double remaining_capacity = knapsack->capacity;

    for (int i = 0; i < knapsack->item_count; i++) {
        Item* item = &knapsack->items[i];

        if (item->weight <= remaining_capacity) {
            total_value += item->value;
        } else {
            double fraction = (double)remaining_capacity / item->weight;
            total_value += item->value * fraction;
            break;
        }

        remaining_capacity -= item->weight;
    }

    return total_value;
}

int main() {
    Knapsack knapsack;
    knapsack.capacity = 20;
    knapsack.item_count = 3;
    knapsack.items = (Item[]){
        {1, 25, 18},
        {2, 24, 15},
        {3, 15, 10}
    };

    sort_items(&knapsack);
    double max_value = solve_fractional_knapsack(&knapsack);

    printf("Maximum value: %.2f\n", max_value);

    return 0;
}