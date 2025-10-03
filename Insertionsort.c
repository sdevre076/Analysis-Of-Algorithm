// #include<stdio.h>
// void insertionSort(int arr[], int size);


// int main(){
    
//     int arr[] = {30,10,50,20,40};
//     int size = sizeof(arr)/sizeof(arr[0]);

//     printf("\nBefore Sorting: \n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//         }

//     insertionSort(arr, size);

//     printf("\n\nAfter Sorting: \n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//         }


//     return 0;
// }


// void insertionSort(int arr[], int size){
//     for(int curr = 1; curr < size; curr++){
//         int prev = curr - 1;
//         int key = arr[curr];
//         while (prev >= 0 && arr[prev] > key)
//         {
//             arr[prev + 1] = arr[prev];
//             prev--;
//         }
//         arr[prev + 1] = key;
        
//     }

    

// }




// #include<stdio.h>

// void insertionSort(int arr[], int size){
//     for (int j = 1; j < size - 1; j++)
//     {
//         int i = j - 1;
//         int key = arr[j];
//         while (key <= arr[i] && i >= 0 )
//         {
//             arr[i + 1] = arr[i];
//             i--;
//         }
//         arr[i + 1] = key;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
    
    
    
// }

// int main(){

//     int arr[] = {6, 3, 1, 2, 9};
//     insertionSort(arr, 5);

// }


#include <stdio.h>

void insertionSort(int arr[], int size) {
    for (int j = 1; j < size; j++) {
        int key = arr[j];
        int i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];  // Variable Length Array (VLA)

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, size);

    return 0;
}

