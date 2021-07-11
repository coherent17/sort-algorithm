#include <stdio.h>

void swap(int *, int *);
void heapify(int *, int, int);
void insert(int *, int);
void delete(int *, int);
void printArray(int *, int);

//global variable
int size=0;

int main(){
    int array[10];
    insert(array,3);
    insert(array,4);
    insert(array,9);
    insert(array,5);
    insert(array,2);
    printArray(array,size);
    delete(array,9);
    printArray(array,size);
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *array, int size, int i){
    if(size==1) printf("Single element in the heap\n");
    else{
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
}

void insert(int *array, int newNumber){
    array[size]=newNumber;
    size+=1;
    //loop to heapify
    int i;
    for(i=size/2-1;i>=0;i--){
        heapify(array, size, i);
    }
}

void delete(int *array, int delNumber){
    //find the index of the number to delete
    int i;
    for(i=0;i<size;i++){
        if(array[i]==delNumber) break;
    }
    //swap to the end of the binary tree
    swap(&array[i],&array[size-1]);
    size-=1;
    //loop to heapify
    for(i=size/2-1;i>=0;i--){
        heapify(array, size, i);
    }
}

void printArray(int *array,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",array[i]);
	}
}