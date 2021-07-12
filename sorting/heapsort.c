#include <stdio.h>
#define SIZE 8

void swap(int *, int *);
void heapify(int *, int, int);
void heapSort(int *, int);
void printArray(int *);

int main(){
    int data[SIZE]={16,25,39,27,12,8,45,63};
    heapSort(data,SIZE);
    printArray(data);
    return 0;
}
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *array, int size, int i){
    int largest=i;
    int left_children=2*i+1;
    int right_children=2*i+2;

    if(left_children<size && array[left_children]>array[largest]) largest=left_children;
    if(right_children<size && array[right_children]>array[largest]) largest=right_children;
    //check need to swap or not?
    if(largest!=i){
        swap(&array[i],&array[largest]);
        heapify(array,size,largest);
    }
}

void heapSort(int *array, int size){
    //construct max heap:
    int i;
    for(i=size/2-1;i>=0;i--){
        heapify(array, size, i);
    }

    //swap the root(index=0) to the end of the array and delete it
    for(i=size-1;i>=0;i--){
        swap(&array[0],&array[i]);
        //heapify again to get the maxheap
        heapify(array,i,0);
    }
}

void printArray(int *array){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d ",array[i]);
	}
    printf("\n");
}