#include <stdio.h>
#define SIZE 8

void insertionSort(int *);
void printArray(int *);

int main(){
	int data[SIZE]={16,25,39,27,12,8,45,63};
	insertionSort(data);
	printArray(data);
	return 0;
}

void insertionSort(int *array){
	int i,j,insertion_num;
	for(i=1;i<SIZE;i++){
		//the number to insert
		insertion_num=array[i];
		j=i-1;
		
		//shift the number right if the sorted array is bigger than the insertion number
		while(j>=0&&insertion_num<array[j]){
			array[j+1]=array[j];
			j-=1;
		}
		
		//insert the number
		array[j+1]=insertion_num;
	}
}

void printArray(int *array){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d ",array[i]);
	}
}
