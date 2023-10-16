#include <stdio.h>

void main()
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nShifted\n");
    for(int i = 9; i > 5; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[5] = 9;
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}
