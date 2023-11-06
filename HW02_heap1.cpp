#include <iostream>
using namespace std;

void buildMaxHeap(int arr[], int n); //build a max heap
template <typename T>
void SWAP(T& a, T& b);
void heapification(int arr[], int n, int i);
void heapification2(int arr[], int n, int i);


void buildMaxHeap(int arr[], int n){
    //begin from the last parent node
    for(int i=n/2-1; i>=0; i--){
        heapification(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n){
    //begin from the last parent node
    for(int i=n/2-1; i>=0; i--){
        heapification2(arr, n, i);
    }
}

//the name of swap function needs to be in uppercase
template <typename T>
void SWAP(T& a, T& b){
    T temp= a; 
    a=b;
    b=temp;
}

void heapification(int arr[], int n, int i){
    //declare variables going to be used
    int largest = i;
    int leftChild = i*2+1;
    int rightChild = i*2+2;

    if(arr[leftChild] > arr[largest] && leftChild < n){
        largest = leftChild;
    }

    if(arr[rightChild] > arr[largest] && rightChild < n){
        largest = rightChild;
    }

    if(largest != i){
        SWAP(arr[largest],arr[i]);
        //use the recursion function to heapify the subtrees if it needs
        heapification(arr, n, largest);
    }
}

void heapification2(int arr[], int n, int i){
    //declare variables going to be used
    int largest = i;
    int leftChild = i*2+1;
    int rightChild = i*2+2;

    if(arr[leftChild] < arr[largest] && leftChild < n){
        largest = leftChild;
    }

    if(arr[rightChild] < arr[largest] && rightChild < n){
        largest = rightChild;
    }

    if(largest != i){
        SWAP(arr[largest],arr[i]);
        //use the recursion function to heapify the subtrees if it needs
        heapification2(arr, n, largest);
    }
}

int main(){
    //the original array
    int arr1[] = {1,3,5,4,6,13,10,9,8,15,17};
    int arr2[] = {17,15,8,9,10,13,6,4,5,3,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    //build the max heap
    buildMaxHeap(arr1, size1);

    //build the min heap
    buildMinHeap(arr2, size2);

    //print it out
    cout<<"max heap: ";
    for(int i=0; i<size1; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl<<"min heap: ";

    for(int i=0; i<size2; i++){
        cout<<arr2[i]<<" ";
    }
}