#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int n, int ele, int findFirst)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == ele)
        {
            result = mid;
            if (findFirst)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);
    if (N <= 0 || N > 1000000)
    {
        printf("Invalid size of the array.\n");
        return 0;
    }
    int arr[N];
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ele;
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    qsort(arr, N, sizeof(int), compare);
    int firstOccurrence = binarySearch(arr, N, ele, 1);
    int lastOccurrence = binarySearch(arr, N, ele, 0);
    if (firstOccurrence == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d %d\n", firstOccurrence, lastOccurrence, lastOccurrence - firstOccurrence + 1);
    }
    return 0;
}

/*
Time Complexity Analysis:
- Binary Search has a time complexity of O(log N).
- The findElementCount function calls findFirstOccurrence and findLastOccurrence, each with O(log N) complexity.
- Thus, the overall time complexity is O(log N).
*/