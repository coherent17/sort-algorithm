# **Algorithm 演算法筆記**
---
## 時間複雜度(Time complexity) $O(f(n))$  
定義$T(n)$表示程式執行所要花費的時間，$n$代表資料輸入量。  
$O(f(n))$可被視為某演算法在電腦執行所需時間不會超過某一常數倍的$f(n)$，也就是說當某演算法所需的執行時間為$T(n)$，那其時間複雜度為$O(f(n))$。  
以數學式表示:  
${\exists}c,n_0{\in}constant$,  
if $n{\geq}n_0$, then $T(n){\leq}c\cdot f(n)$  
所估出來的函數式真正所需執行的上限。  
*    >Example:假如執行時間為$T(n)=3n^3+2n^2+5n$，求其時間複雜度為何?  
  Sol:  
Find constant $c$ and $n_0$: $(n_0,c)=(0,10)$  
        when $n{\geq}n_0$,$3n^3+2n^2+5n{\leq}10n^3$, therefore the time complexity is $O(n^3)$  

### 常見的Big-O有下列幾種:
|    Big O     | feature and explanation                        |
|:------------:|:---------------------------------------------- |
|    $O(1)$    | constant time，執行時間為一個常數倍            |
|    $O(n)$    | linear time，執行時間會隨資料大小而線性成長    |
| $O(log_2n)$  | sub-linear time，成長速度較線性慢              |
|   $O(n^2)$   | quadratic-time，執行時間會成二次方增長         |
|   $O(n^3)$   | cubic-time，執行時間會成三次方增長             |
|   $O(2^n)$   | exponential time，執行時間會成2的n次方增長     |
| $O(nlog_2n)$ | 線性乘對數時間，介於線性及二次方成長之間的行為 |

![time complexity chart](https://i.imgur.com/7lT5DLp.png)

### 常見的演算法簡介
*    分治法(Divide and conquer)
*    遞迴法(Recursion)
*    貪心法(Greed method)
*    動態規劃法(Dynamic Programming Algorithm, DPA)
*    疊代法(Iterative method)
*    枚舉法
*    回溯法

## 排序演算法
*    氣泡排序法(bubble sort)
*    選擇排序法(selection sort)
*    插入排序法(insertion sort)
*    希爾排序法(shell sort)
*    合併排序法
*    快速排序法
*    基數排序法
### **氣泡排序法(Bubble Sort)**
#### 從第一個元素開始，比較相鄰元素大小，如果順序有誤，則對調再進行下一個元素的比較。掃描過一次後就可以確保最後一個元素是位於正確的位置。接著再進行第二次掃描，直到所有元素完成排序為止。
![image alt](https://miro.medium.com/max/901/1*PlGu04ObXCSpTvJOZTOYIw.png)
![image alt](https://blog.kakaocdn.net/dn/nzo1o/btqY5NitVF7/ys6DkVyHWeKGkPYbMaKXNK/img.gif)
#### 時間複雜度:
*    Best Case: $O(n)$  
    當資料的順序恰好由小到大時，第一次掃描後，沒有進行任何swap $\Rightarrow$ 提前結束
*    Worst Case: $O(n^2)$  
    當資料的順序恰好為由大到小時，每回合分別執行:$n-1、n-2、...、1$次
    因此$(n-1)+(n-2)+...+1=n\cdot\frac{(n-1)}{2}$ $\Rightarrow$ $O(n^2)$
*    Average Case: $O(n^2)$  
    每個數字要執行的次數為$0、1、2、3、...、n-1$，因此每個數字平均的執行次數是$\frac{0+1+2+3+...+(n-1)}{n}=\frac{(n-1)}{2}$，有$n$個數字，所以所需平均時間為$n\cdot\frac{(n-1)}{2}=\frac{(n^2-n)}{2}$ $\Rightarrow$ $O(n^2)$
    
#### 空間複雜度:
*   不需要額外的陣列去存資料，因此為$\theta(1)$ 
#### python code:
```python=1
def bubbleSort(array):
    for i in range(len(array)-1):
        for j in range(0,len(array)-i-1):
            if array[j]>array[j+1]:
                #swap the element
                array[j],array[j+1]=array[j+1],array[j]
    return array
```
code:https://github.com/coherent17/algorithm/blob/main/sorting/bubblesort.py
#### 改良Bubble Sort (Modified Bubble Sort)
Bubble Sort的時間複雜度只有在給定的陣列為從小到大排序好的情形才會是$O(n)$，其餘情況階是維持$O(n^2)$。因此我們使用一個flag變數去停止bubble sort當陣列已經被排序好了。 初始化flag為True，當有元素進行交換時，flag改為False，當進行完整個迴圈後，若flag還是維持True，則表示該陣列已經被排序好了，便可以停止bubble sort了。
#### python code:
```python=
def Modified_bubbleSort(array):
    for i in range(len(array)-1):
        flag=True
        for j in range(0,len(array)-i-1):
            if array[j]>array[j+1]:
                #swap the element and let flag become false
                array[j],array[j+1]=array[j+1],array[j]
                flag=False

                if flag==True:
                    break
    return array
```
code:https://github.com/coherent17/algorithm/blob/main/sorting/bubblesort.py
  
  
### **選擇排序法(Selection Sort)**
#### 將資料分成已排序及未排序兩部分，依序在未排序中找最小值，加入到已排序部分的末端。按照這個方式，可以在第一輪中找到最小的，第二輪找到第二小的。那要如何從未排序的數列中找到最小值呢?可以先設未排序陣列的第一個數字是目前的最小值，然後再往後一個一個比大小，如果後面的數字比目前的最小值小，那就將目前的最小值換為這個數。
![image alt](https://miro.medium.com/max/700/1*MUEvL8qTjbRtz22PlTSXPA.jpeg)
![image alt](http://www.codingconnect.net/wp-content/uploads/2016/09/Selection-Sort.gif)
#### 時間複雜度:
分成兩個步驟討論:
*    從未排序陣列中取得最小值:  
        ##### 在n個未排序數列中找到最小值需要$n$個步驟，因此對於selection sort而言，第一回合要從$n$個未排序數列中找到最小值需要$n$個步驟，第二回合要從$n-1$個未排序數列中找到最小值需要$n-1$個步驟，一直到最後一個回合需要一個步驟為止。因此總步驟數為$(n+(n-1)+(n-2)+...+1)=\frac{n\cdot(n+1)}{2}$。
*    移到已排序陣列末端:  
        ##### 每次找到最小的數值，將其與未排序好的第一個數字交換位置，每一個回合需要一個步驟，總共執行$n$個回合，需要$n$個步驟。

因此selection sort共需要$\frac{n\cdot(n+1)}{2}+n=\frac{n\cdot(n+3)}{2}$ $\Rightarrow$ $O(n^2)$

#### 空間複雜度:
*    不需要額外的陣列去存資料，因此為$\theta(1)$ 
#### python code:
```python=
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
```
code:https://github.com/coherent17/algorithm/blob/main/sorting/selection_sort.py
### **插入排序法(Insertion Sort)**
#### 想像手上又一副撲克牌，想要將其由小到大排序。可以將第$i$張牌加入前$i-1$張以排序過的牌，那就可以獲得$i$張排序過的牌組了。
![image alt](https://www.w3resource.com/w3r_images/insertion-sort.png)
![image alt](https://i.pinimg.com/originals/92/b0/34/92b034385c440e08bc8551c97df0a2e3.gif)
#### 時間複雜度:
*    Best Case: $O(n)$  
    當處理的資料為$1、2、3、4、...、N$時，僅需比較$N$次便可以完成排序。另一方面也表示，當給定的數列已經接近排序的狀態時，用insertion sort效率會很高。
*    Worst Case: $O(n^2)$  
    當處理的資料為顛倒的順序:$N、N-1、N-2、...、2、1$時，那麼位在第$i$個的數字將會需要比較$i-1$次，因此總步驟數為$0+1+2+...+(N-1)=\frac{n\cdot(n-1)}{2}$ $\Rightarrow O(n^2)$
*    Average Case: $O(n^2)$  
    這個好難，之後再來搞懂他，如[連結](http://home.cse.ust.hk/faculty/golin/COMP271Sp03/Notes/Ins_Sort_Average_Case.pdf)
#### 空間複雜度:
*    不需要額外的陣列去存資料，因此為$\theta(1)$ 
#### python code:
```python=
def insertionSort(array):
    for i in range(1,len(array)):
        insert_num=array[i]  #要插入的數字
        j=i-1

        while(j>=0 and insert_num<array[j]):
            array[j+1]=array[j]  #往右移
            j-=1  

        array[j+1]=insert_num  #插入新值
    return array
```
code:https://github.com/coherent17/algorithm/blob/main/sorting/insertion_sort.py  
說明:以$array=[5,2,4,6,1,3]$為例。  
*    當$i=1\cap j=0$時，我們將$2$這張牌抽出並決定要插在哪裡。此時因為$array[i]<array[j]$，因此將$5$往右挪一格$(array[j+1]=array[j])$，再將比較的值$(array[i])$插入挪出來的位置。此時數列會變成$array=[2,5,4,6,1,3]$
*    當$i=2\cap j=1$時，我們將$4$這張牌抽出並決定要插在哪裡。此時因為$array[i]<array[j]$，因此我們再把$5$往右移一格，將$4$插入挪出來的空格，此時數列會變成$array=[2,4,5,6,1,3]$
*    當$i=3\cap j=2、1、0$時，將$6$這張牌抽出，發現前面的人都比他小，因此不會進入到$while$的迴圈中，維持在原位。此時數列仍然維持$array=[2,4,5,6,1,3]$不變。
*    當$i=4\cap j=3、2、1、0$時，可以發現$1$都比前面的數字還要小，因此將前面的數字依序往後挪一格，再將$1$插入空位，此時數列會變成$array=[1,2,4,5,6,3]$
*    當$i=5\cap j=4、3、2$時，將$3$這張牌抽出，按照前面的規則可以知道將其插入在數字$2$及數字$4$之間，那做到這邊我們就完成我們的排序了，此時數列會變成$array=[1,2,3,4,5,6]$
### **希爾排序法(Shell Sort)**
#### 為進化版的插入排序法，改良insertion sort中每次只能將資料移動一位的缺點，因此能夠使原本距離較遠的數字快速歸位。添加了間距(gap)的觀念，往左邊間距gap的數字比大小，可讓在陣列後端數值較小的數字較快回到陣列前端。

#### 舉例說明:有$15$筆資料，取$gap$分別為$5、2、1$
| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  |
| --- | --- |:--- | --- | --- |:--- | --- | --- |:--- |:--- | --- | --- | --- | --- |:--- |
| 45  | 84  | 77  | 83  | 55  | 49  | 91  | 64  | 91  | 5   | 37  | 31  | 70  | 38  | 51  |
*    第一回合: $gap=5$
        *    對$index$為$0、5、10$做insertion sort  
                Example:
                | 0                  | 1   | 2   | 3   | 4   | 5                 | 6   | 7   | 8   | 9   | 10                | 11  | 12  | 13  | 14  |
                | ------------------ |:--- |:--- | --- | --- |:----------------- | --- | --- |:--- |:--- | ----------------- | --- | --- | --- |:--- |
                | $\color{red} {45}$ | 84  | 77  | 83  | 55  | $\color{red}{49}$ | 91  | 64  | 91  | 5   | $\color{red}{37}$ | 31  | 70  | 38  | 51  |
                排序後:  
                | 0                  | 1   | 2   | 3   | 4   | 5                 | 6   | 7   | 8   | 9   | 10                | 11  | 12  | 13  | 14  |
                | ------------------ |:--- |:--- | --- | --- |:----------------- | --- | --- |:--- |:--- | ----------------- | --- | --- | --- |:--- |
                | $\color{red} {37}$ | 84  | 77  | 83  | 55  | $\color{red}{45}$ | 91  | 64  | 91  | 5   | $\color{red}{49}$ | 31  | 70  | 38  | 51  |
                
        *    對$index$為$1、6、11$做insertion sort
        *    對$index$為$2、7、12$做insertion sort
        *    對$index$為$3、8、13$做insertion sort
        *    對$index$為$4、9、14$做insertion sort  
        
        經過上面$gap=5$的insertion sort後可以發現顏色相同的數組已經按照順序排好了。
        | 0                 | 1                  |          2          | 3                     |         4          |         5         | 6                  |          7          |           8           | 9                   |        10         | 11                 | 12                  | 13                    | 14                  |
        | ----------------- |:------------------ |:-------------------:| --------------------- |:------------------:|:-----------------:| ------------------ |:-------------------:|:---------------------:|:------------------- |:-----------------:| ------------------ | ------------------- | --------------------- |:------------------- |
        | $\color{red}{37}$ | $\color{blue}{31}$ | $\color{green}{64}$ | $\color{magenta}{38}$ | $\color{Brown}{5}$ | $\color{red}{45}$ | $\color{blue}{84}$ | $\color{green}{70}$ | $\color{magenta}{83}$ | $\color{Brown}{51}$ | $\color{red}{49}$ | $\color{blue}{91}$ | $\color{green}{77}$ | $\color{magenta}{91}$ | $\color{Brown}{55}$ |
        
*    第二回合: $gap=2$
        *    將$gap$減至$2$，分成兩組進行insertion sort:  
                | 0                 | 1                  | 2                 | 3                  | 4                | 5                  | 6                 | 7                  | 8                 | 9                  | 10                | 11                 | 12                | 13                 |        14         |
                | ----------------- | ------------------ |:----------------- | ------------------ | ---------------- |:------------------ | ----------------- | ------------------ |:----------------- |:------------------ | ----------------- | ------------------ | ----------------- | ------------------ |:-----------------:|
                | $\color{red}{37}$ | $\color{blue}{31}$ | $\color{red}{64}$ | $\color{blue}{38}$ | $\color{red}{5}$ | $\color{blue}{45}$ | $\color{red}{84}$ | $\color{blue}{70}$ | $\color{red}{83}$ | $\color{blue}{51}$ | $\color{red}{49}$ | $\color{blue}{91}$ | $\color{red}{77}$ | $\color{blue}{91}$ | $\color{red}{55}$ |
                排序後:  
                | 0                 | 1                  | 2                 | 3                  | 4                | 5                  | 6                 | 7                  | 8                 | 9                  | 10                | 11                 | 12                | 13                 |        14         |
                | ----------------- | ------------------ |:----------------- | ------------------ | ---------------- |:------------------ | ----------------- | ------------------ |:----------------- |:------------------ | ----------------- | ------------------ | ----------------- | ------------------ |:-----------------:|
                | $\color{red}{5}$ | $\color{blue}{31}$ | $\color{red}{37}$ | $\color{blue}{38}$ | $\color{red}{49}$ | $\color{blue}{45}$ | $\color{red}{55}$ | $\color{blue}{51}$ | $\color{red}{64}$ | $\color{blue}{70}$ | $\color{red}{77}$ | $\color{blue}{91}$ | $\color{red}{83}$ | $\color{blue}{91}$ | $\color{red}{84}$ |  
                可以看出顏色相同的數組已經被由小到大排序好了，此外，也可以看到較小的數字已經都在左側，而較大的數字也都已經移到右側了，已經變成一個快要完全排序完成的數列了，此時我們可以進行$gap=1$的排序，其實也就是前面所介紹的insertion sort，在這種快要排序好的數列中，insertion sort的效能會是很高的。
                       
*    第三回合: $gap=1$，其實就是前面所說的insertion sort，只不過這邊不分組，是將所有數列一起做一次insertion sort，便可以得到最終排序好的數列。  
        *    排序後:
                | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  |
                | --- | --- |:--- | --- | --- |:--- | --- | --- |:--- |:--- | --- | --- |:---:| --- |:--- |
                | 5   | 31  | 37  | 38  | 45  | 49  | 51  | 55  | 64  | 70  | 77  | 83  | 84  | 91  | 91  |

![image alt](https://img-blog.csdnimg.cn/2021011217372654.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzUxMjgzODU2,size_16,color_FFFFFF,t_70)

**好懂的示意影片**:{%youtube CmPA7zE8mx0 %}
#### 時間複雜度:
*    Best Case: $O(n)$  
