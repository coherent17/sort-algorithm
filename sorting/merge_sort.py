data=[6,5,3,1,8,7,2,4]

def merge_sort(array):
    if len(array)>1:
        #find the division point
        mid=len(array)//2
        left_array=array[:mid]
        right_array=array[mid:]

        print(left_array,right_array)
        #use recursion to keep dividing
        merge_sort(left_array)
        merge_sort(right_array)

        #initialize the comparison index
        right_index=0
        left_index=0
        merge_index=0

        print(left_array)
        #start comparing
        #case 1: right array compare with left array
        while right_index<len(right_array) and left_index<len(left_array):
            if right_array[right_index]<left_array[left_index]:
                array[merge_index]=right_array[right_index]
                right_index+=1
            else:
                array[merge_index]=left_array[left_index]
                left_index+=1
            merge_index+=1
        
        #case 2: right array compare with itself
        while right_index<len(right_array):
            array[merge_index]=right_array[right_index]
            right_index+=1
            merge_index+=1
        
        #case 3: left array compare with itself
        while left_index<len(left_array):
            array[merge_index]=left_array[left_index]
            left_index+=1
            merge_index+=1
    return array

d=merge_sort(data)