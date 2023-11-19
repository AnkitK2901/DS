#include <stdio.h>
#include <stdlib.h>
void findTheMissing()
{
    int arr1[] = {7, 2, 5, 3, 5};
    int arr2[] = {7, 2, 5, 4, 3, 6, 5};
    int cnt = 0;
    int size_arr1 = sizeof(arr1) / sizeof(int);
    int size_arr2 = sizeof(arr2) / sizeof(int);
    for (int i = 0; i < size_arr2; i++)
    {
        cnt = 0;
        for (int j = 0; j < size_arr1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                cnt++;
            }
        }
        if (cnt == 0)
        {
            printf("Missing : %d\n", arr2[i]);
        }
    }
    if (cnt != 0)
    {
        printf("\nAll Available.\n");
    }
}
int main()
{
    findTheMissing();
    return 0;
}