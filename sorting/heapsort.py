def heapify(array,size,i):
    largest=i
    left_children=2*i+1
    right_children=2*i+2

    if left_children<size and array[left_children]>array[largest]:
        largest=left_children
    if right_children<size and array[right_children]>array[largest]:
        largest=right_children
    
    # //check need to swap or not?
    if largest!=i:
        array[i],array[largest]=array[largest],array[i]
        heapify(array,size,largest)

def heapSort(array):
    # construct max heap:
    n=len(array)
    for i in range(n//2,-1,-1):
        heapify(array,n,i)
    
    # swap the root(index=0) to the end of the array and delete it
    for i in range(n-1,0,-1):
        array[i],array[0]=array[0],array[i]
        #heapify root element:
        heapify(array,i,0)

data=[16,25,39,27,12,8,45,63]
heapSort(data)
print(data)