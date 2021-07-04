#include <stdio.h>
#define SIZE 8

void bubbleSort(int *);
void Modified_bubbleSort(int *);
void printArray(int *);

int main(){
	int data[SIZE]={16,25,39,27,12,8,45,63};
	bubbleSort(data);
	Modified_bubbleSort(data);
	printArray(data);
	return 0;
}

void bubbleSort(int *array){
	void swap(int *, int *);
	int i,j;
	for(i=0;i<SIZE-1;i++){
		for(j=0;j<SIZE-1-i;j++){
			if (array[j]>array[j+1]){
				swap(&array[j],&array[j+1]);
			}
		}
	}
} 

void Modified_bubbleSort(int *array){
	void swap(int *, int *);
	int i,j,flag;
	for(i=0;i<SIZE-1;i++){
		flag=1;
		for(j=0;j<SIZE-1-i;j++){
			if(array[j]>array[j+1]){
				swap(&array[j],&array[j+1]);
				flag=0;
				if(flag) break;
			}
		}
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
