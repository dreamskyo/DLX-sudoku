# DLX-SUDOKU
此次實作環境如下
---
>* Windos 11  
>* g++ 13.2.0 (Built by MinGW-Builds project)  
>* Visual Studio Code April 2025 (version 1.100)  
  
## 參考資料
>* [The Dancing Links Algorithm - An explanation that is less explanatory but more on implementation?](https://stackoverflow.com/questions/1518335/the-dancing-links-algorithm-an-explanation-that-is-less-explanatory-but-more-o)  
>* [Donald E. Knuth Dancing links](https://arxiv.org/abs/cs/0011047)  
>* [Solving Sudoku efficiently with Dancing Links](https://www.kth.se/social/files/58861771f276547fe1dbf8d1/HLaestanderMHarrysson_dkand14.pdf)
## 演算法介紹
### Dancing links  
>Dancing links由Algorithm X的作者Knuth所命名，據他所說此技術最早由Hiroshi Hitotsumatsu和Kōhei Noshita在1971年所發明。此技術著重在雙向鏈結串列(Doubly linked list)中增刪節點的實作，在每一列的最前端加入「head」節點，以便在回朔演算法中快速還原先前被刪除的節點。在實作過程中，節點在迭代時互相鏈結、斷開然後又復原，其動態變化如同「共舞」一般，因此得名。

### Algorithm X  
>由Donald Knuth所發明的Algorithm X是針對精確覆蓋問題的一種非確定性演算法，採用DFS加上回朔的方式快速求解。以下我們舉例說明。  
>精確覆蓋問題：對於全集S與若干子集(這裡舉例ABCDEF)能否找到一種組合，使組合內的子集兩兩不相交且其聯集剛好覆蓋整個S(這裡的解為BDF)
![image](./matrix/(6).png)  
>a.	矩陣非空，找出1最少的列，此列有A與B兩行。  
b.	依序先選擇A行加入解中，將與A有交集的行刪除。  
![image](./matrix/(2).png)  
c.	矩陣非空，找出1最少的列，此列全部為0，失敗，將A移出解並回朔。  
![image](./matrix/(3).png)  
d.	選擇B行加入解中，將與B有交集的行刪除。  
![image](./matrix/(1).png)   
e.	矩陣非空，找出1最少的列，此列只有D。  
f.	選擇D行加入解中，將與D有交集的行刪除。  
![image](./matrix/(4).png)  
g.	矩陣非空，找出1最少的列，此列只有F。  
h.	選擇F行加入解中並刪除。  
![image](./matrix/(5).png)  
i.	矩陣為空，求解成功。  
 
### 透過DLX解決數獨問題

>要將針對精確覆蓋的演算法套用到數獨上，勢必得經過問題的轉換，在這裡我們先基於陣列做解釋，暫時不理會 linked list 。對於一個空白數獨面板，不理會規則的情況下有 9\*9\*9 = 729 種可能，在這些可能中要找出符合4種規則的可能：    
>* 每個格子只能有一個數字  
>* 每一行 (column) 中數字不能重複  
>* 每一列 (row) 中數字不能重複  
>* 將數獨切分成 9 個 3\*3 的區塊，每個區塊中數字不能重複  

>將規則轉化為四個數獨面板， 9\*9\*4 = 324 個格子。每次我們在答案中填上某個數字，就會覆蓋這四個規則的一部份。綜上所述，只要開一個 324 格的 bool 陣列，紀錄面板的覆蓋情形，便能實作精確覆蓋。  
729 種可能 \* 324 格 = 236,196，是一個不容小覷的數字，但其中許多格並沒有記錄東西，直接開二維陣列會造成搜尋和儲存上的浪費，因此實作上會結合 Dancing links ，使整個回朔演算法擁有極高的效率。

### 後續
>就算完整看完上面既學術又冗長的理論，要實作出來也得經過一番努力。在Chat GPT的幫助下我生成出大部分程式碼，然後獨自將其包裝成Class結構並修改原本仰賴全域變數的地方。  
