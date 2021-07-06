#include <stdio.h>
#define SIZE 15

void shellSort(int *, int *);
void printArray(int *);

int main(){
	int data[SIZE]={45,84,77,83,55,49,91,64,91,5,37,31,70,38,51};
	//define gap by yourself
	int gap[3]={5,2,1};
	shellSort(data,gap);
	printArray(data);
	return 0;
}

void shellSort(int *array, int *gap){
	int i,j,k,current_gap,temp;
	for(i=0;i<3;i++){
		current_gap=gap[i];
		for(j=current_gap;j<SIZE;j++){
			temp=array[j];
			k=j;
			while(k>=0&&k-current_gap>=0&&array[k-current_gap]>temp){
				array[k]=array[k-current_gap];
				k-=current_gap;
			}
			array[k]=temp;
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
