#include <stdio.h>
#define SIZE 8

void selectionSort(int *);
void printArray(int *);

int main(){
	int data[SIZE]={16,25,39,27,12,8,45,63};
	selectionSort(data);
	printArray(data);
	return 0;
}

void selectionSort(int *array){
	void swap(int *,int *);
	int i,j,min_index;
	for(i=0;i<SIZE-1;i++){
		//initiaize the index of the unsorted array
		min_index=i;
		
		//find the smallest nuber in the unsorted array
		for(j=i+1;j<SIZE;j++){
			if(array[min_index]>array[j]){
				min_index=j;
			}
		}
		
		//put the smallest number into the last of the sorted array
		swap(&array[min_index],&array[i]);
	}
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printArray(int *array){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d ",array[i]);
	}
}
