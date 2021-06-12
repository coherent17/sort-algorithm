data=[16,25,39,27,12,8,45,63]

def insertionSort(array):
    for i in range(1,len(array)):
        insert_num=array[i]  #要插入的數字
        j=i-1

        while(j>=0 and insert_num<array[j]):
            array[j+1]=array[j]  #往右移
            j-=1  

        array[j+1]=insert_num  #插入新值
    return array

print(insertionSort(data))