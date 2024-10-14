
#include <stdio.h> 
#include <time.h>

 
void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 


int partition(int arr[], int low, int high) 
{ 

	 
	int pivot = arr[low]; 
	int i = low; 
	int j = high; 

	while (i < j) { 

		 
		while (arr[i] <= pivot && i <= high - 1) { 
			i++; 
		} 

		
		while (arr[j] > pivot && j >= low + 1) { 
			j--; 
		} 
		if (i < j) { 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[low], &arr[j]); 
	return j; 
} 

void unique(int arr[],int n){
for(int i = 0;i<=n-2;i++){
		if (arr[i] == arr[i + 1]){
			printf("Not unique\n");
			break;
		}
		else if(i==n-2 && arr[i] != arr[i + 1]){
			printf("Unique\n");
		}
	}
}

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 


		int partitionIndex = partition(arr, low, high); 


		quickSort(arr, low, partitionIndex - 1); 
		quickSort(arr, partitionIndex + 1, high); 
	} 
} 


int main() 
{ 
    clock_t start, end;
    double t;
	int n,i;
	printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


	printf("Original array: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	} 

    start = clock();
	quickSort(arr, 0, n - 1); 
    end = clock();


	printf("\nSorted array: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	} 
	
	unique(arr,n);
    t = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to sort: %f seconds\n", t);

	return 0; 
}