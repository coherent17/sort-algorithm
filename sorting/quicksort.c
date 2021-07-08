#include <stdio.h>
#define SIZE 8

void swap(int *, int *);
int partition(int *, int, int);
void quickSort(int *, int, int);
void printArray(int *);

int main(){
	int data[SIZE]={22,11,88,66,55,77,33,44};
	quickSort(data,0,SIZE-1);
	printArray(data);
	return 0;
}

void quickSort(int *array, int left, int right){
	if(left<right){
		int partition_pos;
		partition_pos=partition(array,left,right);
		quickSort(array,left,partition_pos-1);
		quickSort(array,partition_pos+1,right);
	}
} 

int partition(int *array, int left, int right){
	int i,j,pivot;
	i=left;
	j=right;
	pivot=array[right];
	
	while(i<j){
		//i move to right
		while(i<right&&array[i]<pivot){
			i++;
		}
		//j move to left
		while(j>left&&array[j]>pivot){
			j--;
		}
		//swap the element of the index i and j
		if(i<j){
			swap(&array[i],&array[j]);
		}
	}
	//swap the element of the index i and p
	if(array[i]>pivot){
		swap(&array[i],&array[right]);
	}
	return i;
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
