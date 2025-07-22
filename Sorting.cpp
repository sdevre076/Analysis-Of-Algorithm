#include<iostream>
using namespace std;
void insertionSort(int arr[], int size){
    for(int curr = 1; curr < size; curr++){
        int prev = curr - 1;
        int key = arr[curr];
        while (prev >= 0 && arr[prev] > key)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;

    }



}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int min_idx = i;
        int min_Val = arr[i];
        for (int j = i + 1; j < size; j++)
        {

            if(arr[j] < min_Val){
                min_idx = j;
                min_Val = arr[j];
            }
        }
        arr[min_idx] = arr[i];
        arr[i] = min_Val;



    }

}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main(){
    int choice;
    int size;
    int arr[100];
    do
    {
        cout<<"\n--------- Array Sorting --------"<<endl;
        cout<<"1. Insertion Sort\n2. Selection Sort\n3. Exit"<<endl;

        cout<<"Enter your choice: \n";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"\nEnter size of Array: ";
                cin>>size;

                cout<<"\nEnter array Elements: \n";
                for (int i = 0; i < size; i++)
                {
                    cin>>arr[i];
                }

                cout<<"\nBefore Sorting: ";
                printArray(arr, size);

                insertionSort(arr, size);

                cout<<"\nAfter Selection Sort: ";
                printArray(arr, size);



            break;

            case 2:

                cout<<"\nEnter size of Array: ";
                cin>>size;

                cout<<"\nEnter array Elements: \n";
                for (int i = 0; i < size; i++)
                {
                    cin>>arr[i];
                }

                cout<<"\nBefore Sorting: \n";
                printArray(arr, size);

                selectionSort(arr, size);

                cout<<"\nAfter Insertion Sort: \n";
                printArray(arr, size);
                break;




            case 3:
                cout<<"\nExiting....";
                break;

        default:
            cout<<"\nInvalid choice, Try Again!";

        }


    } while (choice != 3);




    return 0;

}