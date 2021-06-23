#include <stdio.h>
#include <stdlib.h>
#include <D:\Embedded-Course\BinarySearch\types.h>
#define MAXSIZE 255


// Check if an array is sorted or not
uint32_t arraySortedCheck(uint32_t* arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;
    if(arr[n-1] < arr[n-2])
        return 0;
    return arraySortedCheck(arr, n-1);
}



// Sort array and do searching
uint8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t number)
{
    int temp = 0, first, last, middle;
    if(arraySortedCheck(arr, size))
    {
        //Binary Search
        first = 0;
        last = size - 1;
        middle = (first+last)/2;
        while (first <= last)
        {
            if (arr[middle] < number)
                first = middle + 1;
            else if (arr[middle] == number)
            {
                return middle;
                break;
            }
            else
                last = middle - 1;
            middle = (first + last)/2;
        }
        if (first > last)
        {
            return 0;
        }
    }
    else
    {
        // Sort Array
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if(arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printf("Array after Sorting:  ");
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

        // Binary Search
        first = 0;
        last = size - 1;
        middle = (first+last)/2;
        while (first <= last)
        {
            if (arr[middle] < number)
                first = middle + 1;
            else if (arr[middle] == number)
            {
                return middle;
                break;
            }
            else
                last = middle - 1;
            middle = (first + last)/2;
        }
        if (first > last)
        {
            return 0;
        }


    }

}




int main()
{
    int size,arr[MAXSIZE],number;

    printf("Enter number of Elements:\n");
    scanf("%d",&size);



    //Check Size of array
    if(size <= MAXSIZE)
    {
        printf("Enter %d number:\n", size);
        for (int c = 0; c < size; c++)
            scanf("%d",&arr[c]);


        printf("Enter the value to find:\n");
        scanf("%d", &number);

        int result = binarySearch(arr,size,number);

        if(result == 0)
        {
            printf("\nNot found %d isn't present in the array.\n", number);
        }
        else
        {
            printf("\n%d is present at index %d.\n", number, result);
        }
    }
    else
    {
        printf("\n Size must be less than 255");
    }


}
