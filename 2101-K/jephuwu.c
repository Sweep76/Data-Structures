#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int *getNumbers()
{
    int *numbers = calloc(MAX, sizeof(int));
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("give me your number daddy: ");
        scanf("%d", numbers+i);
    }
    return numbers;
}

int selectAlgorithm()
{
    int algo = -1;
    while (algo < 0 || algo > 5)
    {
        printf("Choose your sorting algorithm daddy:\n");
        printf("0 - bubble\n");
        printf("1 - insertion\n");
        printf("2 - merge\n");
        printf("3 - shell\n");
        printf("4 - quick\n");
        printf("5 - selection\n");
        scanf("%d", &algo);
    }
    return algo;
}

void printNums(int *nums, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}

void bubbleSort(int *nums, int size)
{
    // boolean to check if all items are sorted
    int isUnordered = 1;
    int i;
    while (isUnordered == 1)
    {
        isUnordered = 0;
        for (i = 0; i < size - 1; i++)
        {
            // reset isUnordered if a pair is not in order, then swap
            if (nums[i] > nums[i + 1])
            {
                int spare;
                spare = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = spare;
                isUnordered = 1;
            }
            printNums(nums, size);
        }
    }
}

void insertionSort(int *nums, int size)
{
    int step;
    for (step = 1; step < size; step++)
    {
        int key = nums[step];
        int j = step - 1;
        while (key < nums[j] && j >= 0)
        {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
        printNums(nums, size);
    }
}

void mergeSort(int *nums, int size)
{

}

void shellSort(int *nums, int size)
{
    
}

void quickSort(int *nums, int size)
{
    
}

void selectionSort(int *nums, int size)
{
    int step;
    for (step = 0; step < size; step++)
    {
        // find the least element
        int i, minIdx = step;
        for (i = step + 1; i < size; i++)
        {
            if (nums[i] < nums[step])
                minIdx = i;
        }

        int temp = nums[minIdx];
        nums[minIdx] = nums[step];
        nums[step] = temp;
        printNums(nums, size);
    }
}

int main()
{
    int *numArray = getNumbers();
    printNums(numArray, MAX);
    int algo = selectAlgorithm();
    switch(algo)
    {
        case 0:
            bubbleSort(numArray, MAX);
            break;
        case 1:
            insertionSort(numArray, MAX);
            break;
        case 2:
            mergeSort(numArray, MAX);
            break;
        case 3:
            shellSort(numArray, MAX);
            break;
        case 4:
            quickSort(numArray, MAX);
            break;
        case 5:
            selectionSort(numArray, MAX);
            break;
    }
    return 0;
}
