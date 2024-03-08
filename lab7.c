#include <stdio.h>
#include <stdlib.h>
struct switches{
    int swaps;
    int value;
};


// A function to implement bubble sort
struct switches*  bubbleSort(int arr[], int n)
{
    struct switches* swapStuff = (struct switches*)malloc(sizeof(struct switches)*n);
    
    int i, j,temp;
    int o=0;
    int total =0;

    for(int i = 0; i < n; i++){
        swapStuff[i].value = arr[i];
        swapStuff[i].swaps = 0;
    }

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {//then swap
                temp=arr[j];
                arr[j]=arr[j+1];
                
                while(swapStuff[o].value != arr[j]){
                    o++;
                }
                swapStuff[o].swaps++;
                arr[j+1]=temp;
                o=0;

                while(swapStuff[o].value != temp){
                    o++;
                }
                swapStuff[o].swaps++;
                o=0;
                total++;
            }
        }
    }//prints number of swaps
    for (i=0; i < n; i++){
        o=0;
        while(swapStuff[o].value != arr[i]){
            o++;
        }
        printf("%d: %d \n", arr[i], swapStuff[o].swaps);
    }
    printf("%d\n",total);
    free(swapStuff);
}
struct switches * selectionSort(int arr[], int n)
{
    struct switches* swapStuff = (struct switches*)malloc(sizeof(struct switches)*n);
    int i, j, min_idx, temp;
    int total=0;
    int o=0;
    
    for(i = 0; i < n; i++){
        swapStuff[i].value = arr[i];
        swapStuff[i].swaps = 0;
    }
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        
        // Find the minimum element in unsorted array
        min_idx = i;
        
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            min_idx = j;
            
        }
        // Swap the found minimum element with the first element
        if(i != min_idx){
            temp = arr[i];
            arr[i] = arr[min_idx];
            while(swapStuff[o].value != arr[i]){
                        o++;
                    }
            swapStuff[o].swaps++;
            o=0;
            while(swapStuff[o].value != temp){
                        o++;
                    }
            swapStuff[o].swaps++;
            o=0;
            arr[min_idx] = temp;
            total++;
        }
    }//prints number swaps
    for (i=0; i < n; i++){
        o=0;
        while(swapStuff[o].value != arr[i]){
            o++;
        }
        printf("%d: %d \n", arr[i], swapStuff[o].swaps);
    }
    printf("%d\n",total);
    free(swapStuff);
}

// Driver program to test above functions
int main()
{
    int array1[] = {97,16,45,63,13,22,7,58,72};
    int array2[] = {90,80,70,60,50,40,30,20,10};
    
    int array3[] = {97,16,45,63,13,22,7,58,72};
    int array4[] = {90,80,70,60,50,40,30,20,10};
    int n = 9; //size of the array

    printf("Bubble sort: \n");
    printf("array1: \n");
    bubbleSort(array1, n);
    printf("array2: \n");
    bubbleSort(array2, n);

    printf("Selection sort: \n");
    printf("array1: \n");
    selectionSort(array3, n);
    printf("array2: \n");
    selectionSort(array4, n);

    return 0;
}
