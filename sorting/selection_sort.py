data=[16,25,39,27,12,8,45,63]

def selectionSort(array):
    for i in range(len(array)-1):
        #設未排序陣列中的第一個元素為最小的
        min_index=i
        for j in range(i+1,len(array)):
            #找到未排序中最小元素的index
            if array[min_index]>array[j]:
                min_index=j
        #將最小的數字放到已排序數列中的最後面
        array[i],array[min_index]=array[min_index],array[i]
    return array

print(selectionSort(data))