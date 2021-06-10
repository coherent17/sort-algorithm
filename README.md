# Algorithm 演算法筆記
---
## 時間複雜度(Time complexity) $O(f(n))$  
定義$T(n)$表示程式執行所要花費的時間，$n$代表資料輸入量。  
$O(f(n))$可被視為某演算法在電腦執行所需時間不會超過某一常數倍的$f(n)$，也就是說當某演算法所需的執行時間為$T(n)$，那其時間複雜度為$O(f(n))$。  
以數學式表示:  
${\exists}c,n_0{\in}constant$,  
if $n{\geq}n_0$, then $T(n){\leq}cf(n)$  
所估出來的函數式真正所需執行的上限。  
*    ex:假如執行時間為$T(n)=3n^3+2n^2+5n$，求其時間複雜度為何?  
        * sol:find constant $c$ and $n_0$: $(n_0,c)=(0,10)$  
when $n{\geq}n_0$, $3n^3+2n^2+5n{\leq}10n^3$, therefore the time complexity is $O(n^3)$  

常見的Big-O有下列幾種:






