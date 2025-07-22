#include<stdio.h>
void binary_search(int arr[], int size, int key){
    int low = 1, high = size, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            printf("Element detected at index %d\n", mid + 1);
            return;
        
        }else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        if(low > high){
            printf("Element not detected\n");
            return;
        }
    }
}
int main(){
    int arr[] = {4,8,12,16,20,24,28};
    int size = sizeof(arr)/sizeof(arr[0]); //size = 7
    int key = 12;
    binary_search(arr, size, key);
    return 0;
}
