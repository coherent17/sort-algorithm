data=[22,11,88,66,55,77,33,44]

def quicksort(array,left,right):
    if left<right:
        partition_pos=partition(array,left,right)
        quicksort(array,left,partition_pos-1)
        quicksort(array,partition_pos+1,right)


def partition(array,left,right):
    i=left
    j=right-1
    pivot=array[right]

    while i<j:
        #i move to right:
        while i<right and array[i]<pivot:
            i+=1
        
        #j move to left:
        while j>left and array[j]>pivot:
            j-=1

        #swap the element of index i and j
        if i<j:
            array[i],array[j]=array[j],array[i]

    #swap the element of index i and p
    if array[i]>pivot:
        array[i],array[right]=array[right],array[i]

    return i    

quicksort(data,0,len(data)-1)
print(data)