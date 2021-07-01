data=[45,84,77,83,55,49,91,64,91,5,37,31,70,38,51]
#define the gap by yourself
gap=[5,2,1]

def shell_sort(array,gap):
    n=len(array)
    #start gapped insertion sort
    for current_gap in gap:
        for i in range(current_gap,n):
            #temp: the insertion number
            temp=array[i]
            j=i
            #if the unsorted array is bigger than insertion number, then shift right 
            while j>=0 and j-current_gap>=0 and array[j-current_gap]>temp:
                array[j]=array[j-current_gap]
                j-=current_gap
            #insert the insertion number
            array[j]=temp
    return array

print(shell_sort(data,gap))