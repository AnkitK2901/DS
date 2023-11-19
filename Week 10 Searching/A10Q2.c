#include <stdio.h>
int linearSearch(int arr[], int n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return 1; 
        }
    }
    return 0; 
}
int main()
{
    int n, m;
    printf("Enter the size of the first list (n): ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter %d space-separated integers for arr1:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second list (m): ");
    scanf("%d", &m);
    int arr2[m];
    printf("Enter %d space-separated integers for arr2:\n", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    printf("The numbers missing are: ");
    for (int i = 0; i < m; i++)
    {
        if (!linearSearch(arr1, n, arr2[i]))
        {
            printf("%d ", arr2[i]);
        }
    }
    return 0;
}
