#include <iostream>
using namespace std;

//Function to sort array in descending order using the radix algorithm
void countSort(int arr[], int len, int exp){
    int output[len];
    int i, count[10] = { 0 };

    for (i = 0; i < len; i++)
		count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = len - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < len; i++)
		arr[i] = output[i];
}
void radixSort(int arr[], int len){
    int maximum = arr[0];
    for (int i = 0; i < len; i++){ if (arr[i] > maximum) maximum = arr[i];}

    for (int exp = 1; maximum/ exp > 0; exp *= 10)
		countSort(arr, len, exp);

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "After Descending radix sort:\t";  
    for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);

}

//Function to sort array in ascending order using the bubble sort algorithm
void bubbleSort(int arr[], int x){
    int n = x;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"\nAfter ascending bubble sort:\t";
    for (int i = 0; i < 20; i++){
        cout<< arr[i] << " ";
    }
}

//Function to search for user input in array using binary search algorithm
void binarySearch(int arr[], int x, int target){
    int start = 0;
    int end = x-1;
    
    while (start <= end) {
        int m = start + (end - start) / 2;
        if (arr[m] == target)
            cout<<"\nAfter binary searching, the number " << target << " is INCLUDED in the array."; 
        if (arr[m] < target)
            start = m + 1;
        else
            end = m - 1;
    }
    cout<<"\nAfter binary searching, the number " << target << " is NOT in the array."; 
}

//Test
int main(){
    //code to generate random array of 20 elements
    int test_array[] = {50, 98, 79, 89, 83, 95, 41, 61, 18, 1, 10, 81, 76, 44, 49, 41, 8, 2, 62, 75};
    int len = sizeof(test_array)/sizeof(test_array[0]);
    
    //radixSort(test_array, len);
    //bubbleSort(test_array, len); 
    binarySearch(test_array, len, 95);
}
