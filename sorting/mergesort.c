#include <stdio.h>
#define SIZE 8 

void mergeSort(int *, int *, int, int);
void printArray(int *);

int main(){
	int data[SIZE]={5,3,8,6,2,7,1,4};
	int reg[SIZE]={0};
	mergeSort(data,reg,0,SIZE-1);
	printArray(data);
	return 0;
}

void mergeSort(int *array, int *reg, int front, int end){
	int mid;	
	if(front<end){
		mid=(front+end)/2;
		//left sub-array:array[front,...,mid]
		//right sub-array:array[mid+1,...,end]
		mergeSort(array,reg,front,mid);
		mergeSort(array,reg,mid+1,end);
		
		//initialize the comparison pointer
		int left_pointer=front;
		int right_pointer=mid+1;
		
		//loop counter
		int i;
		
		for(i=front;i<=end;i++){
			//limit of the left pointer
			if(left_pointer==mid+1){
				reg[i]=array[right_pointer];
				right_pointer+=1;
			}
			
			//limit of the right pointer
			else if(right_pointer==end+1){
				reg[i]=array[left_pointer];
				left_pointer+=1;
			}
			
			//the element of the left sub-array is smaller than right sub-array
			else if(array[left_pointer]<array[right_pointer]){
				reg[i]=array[left_pointer];
				left_pointer+=1;
			}
			
			//the element of the right sub-array is smaller than left sub-array
			else{
				reg[i]=array[right_pointer];
				right_pointer+=1;
			}
		}
		
		//copy the element from register to array
		for(i=front;i<=end;i++){
			array[i]=reg[i];
		}
	}
}

void printArray(int *array){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d ",array[i]);
	}
}
