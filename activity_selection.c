//activyityselction 
#include <stdio.h>
#include <stdlib.h>

struct Activity
{
    int start, finish;
};

// This function is used for sorting all activities according to finish time
int activityCompare(const void *a, const void *b)
{
   struct Activity *a1 = (struct Activity *)a;
   struct Activity *b1 = (struct Activity *)b;
   return a1->finish - b1->finish;
}

// Returns minimum number of platforms required
void activitySelection(struct Activity arr[], int n)
{
   // Sort all activities according to finish time
    qsort(arr, n, sizeof(arr[0]), activityCompare);

   // Initialize result (number of platforms in minimum number of platforms)
    int result = 1;

   // Initialize last time (finish time of last activity)
    int last = arr[0].finish;

   // Iterate through all given activities
    for (int i = 1; i < n; i++)
    {
       // If start time of current activity is greater than last time
        if (arr[i].start >= last)
        {
           // Increment result and update last
            result++;
            last = arr[i].finish;
        }
    }

   // Print the result
    printf("Minimum Number of Platforms Required = %d\n", result);
}

int main()
{
    struct Activity arr[] = { {1, 2}, {3, 4}, {0, 6}, {5, 7},
                            {8, 9}, {5, 9} };
    int n = sizeof(arr)/sizeof(arr[0]);
    activitySelection(arr, n);
    return 0;
}
