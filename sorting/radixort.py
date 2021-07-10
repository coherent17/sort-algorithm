data=[170,45,75,90,802,24,2,66]

def getMax(array):
    max=array[0]
    for i in range(1,len(data)):
        if array[i]>max:
            max=array[i]
    return max

def radixSort(array):
    temp_array=[0]*len(array)
    significantDigit=1
    largestNum=getMax(array)

    while largestNum/significantDigit>0:
        bucket=[0]*10

        # count how many number put into each bucket
        for i in range(len(array)):
            bucket[int(array[i]/significantDigit)%10]+=1

        # use prefix sum to determine where to put the number 
        for i in range(1,9+1):
            bucket[i]+=bucket[i-1]

        
        for i in range(len(array)-1,-1,-1):
            digitNumber=int(array[i]/significantDigit)%10
            # need to -1 because the prefix sum include itself
            bucket[digitNumber]-=1
            temp_array[bucket[digitNumber]]=array[i]

        # copy the array
        for i in range(len(array)):
            array[i]=temp_array[i]

        significantDigit*=10
    return array

print(radixSort(data))