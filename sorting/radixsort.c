#include <stdio.h>
#define SIZE 8

int getMax(int *);
void radixSort(int *);
void printArray(int *);

int main(){
	int data[SIZE]={170,45,75,90,802,24,2,66};
	radixSort(data);
	printArray(data);
	return 0;
}

int getMax(int *array){
	int max,i;
	max=array[0];
	for(i=1;i<SIZE;i++){
		if(array[i]>max){
			max=array[i];
		}
	}
	return max;
}

void radixSort(int *array){
	int i;
	int temp_array[SIZE];
	int significantDigit=1;
	int largestNum=getMax(array);
	
	while(largestNum/significantDigit>0){
		int bucket[10]={0};
		
		//count how many number put into each bucket
		for(i=0;i<SIZE;i++){
			bucket[(array[i]/significantDigit)%10]++;
		}
		
		for(i=1;i<10;i++){
			bucket[i]+=bucket[i-1];
		}
		
		for(i=SIZE-1;i>=0;i--){
			temp_array[--bucket[(array[i]/significantDigit)%10]]=array[i];
		}
		
		//copy the array
		for(i=0;i<SIZE;i++){
			array[i]=temp_array[i];
		}
		//move to the next significantDigit number
		significantDigit*=10;
	}
}

void printArray(int *array){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d ",array[i]);
	}
} 
