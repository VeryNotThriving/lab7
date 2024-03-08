for (i=0; i < n; i++){
        while(swapStuff[o].value != arr[i]){
        o++;
        }
        printf("%d: %d ", arr[i], swapStuff[o].swaps);
        printf("\n");
    }