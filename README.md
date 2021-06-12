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
*    謝耳排序法
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