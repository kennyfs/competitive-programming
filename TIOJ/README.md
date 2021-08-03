[網站連結](https://tioj.ck.tp.edu.tw/)，[我](https://tioj.ck.tp.edu.tw/users/kennyfs)  
  
暑假Day12，[1452](https://tioj.ck.tp.edu.tw/problems/1452)：  
輪廓線dp花了好久才理解，基本上我就是把google搜尋輪廓線dp的第一頁都點開來看完了。最後是看[這篇](https://blog.csdn.net/lvmaooi/article/details/79702273)。  
其實我卡住或許只是因為看不懂[OI Wiki](https://oi-wiki.org/dp/plug/)的轉移條件，我想了好久還是不懂，他的橫放應該是往右放，但是跟上面的圖示一起看我又被混淆了。  
雖然說今天只寫一題，但也夠燒腦了，明天大概是把昨天說的[開窗戶問題](https://tioj.ck.tp.edu.tw/contests/74/problems/2153)寫完，盡量快點寫完，畢竟比賽時間沒有很長。
  
暑假Day13，[1080](https://tioj.ck.tp.edu.tw/problems/1080)：  
這天有點混XD，我把逆序數對真正解一次，因為上次是寫的程式bug一堆所以抄別人的解，這次自己刻BIT，練習一下基礎，改天應該要再寫一次merge sort。  
  
暑假Day14，[2153](https://tioj.ck.tp.edu.tw/problems/2153)：  
遲了一天，後來想了很久才懂，我是看[蛋餅的解](https://hackmd.io/-eNf09F8QNePaIoGVsEbHw#pC-%E9%96%8B%E7%AA%97%E6%88%B6)，後來才懂他的transform是每行結束後轉移到下一行的動作，就是我在36行開始寫的註解。  
有件很好笑的事：我一開始看到他寫的!!我就直接關掉題解，因為根本看不懂是什麼奇怪的語法，後來用驚嘆號的英文查了一下，查到[這個](https://stackoverflow.com/questions/14751973/what-is-in-c)，原來就是直接兩層驚嘆號的意思。  
我還發現不需要把初始值寫得跟蛋餅的解一樣麻煩，直接全設為1就好，因為不合法的時候自然不會轉移，所以不會有問題。這個dp的初始狀態卡了我一下，因為第一行不太能套用dp狀態，有點反直覺。我後來覺得應該要把dp初始條件當作「能夠轉移的方法數」，雖然他不一定會轉移，但如果轉移了就應該把他當作1，其實也可以暴力把前兩行算出來，只是會TLE（2^32>10^9）。好像這種可能方法數的dp初始狀態幾乎都是無腦設為1就好。dp的初始狀態滿有意思的。
  
暑假Day17，[1211](https://tioj.ck.tp.edu.tw/problems/1211)：  
複習一下Prim，用最普通的heap(priority queue)寫  
[1711](https://tioj.ck.tp.edu.tw/problems/1711)，[EEK](https://slides.com/fhvirus/eek#/1)  
樹dp，[參考](https://oi.ototot.tw/2018/11/tioj-1711-apple-tree.html)  
  
暑假Day22，[1306](https://tioj.ck.tp.edu.tw/problems/1306)：  
為了寫[複賽pA](https://tioj.ck.tp.edu.tw/problems/2155)，早上讀了[字串匹配](http://slides.com/justinlai2003/deck-56d971)，複習了hash Z KMP，然後下午看複賽題解的時候發現Suffix array，於是研究了一下，參考[山姆的這篇](https://sam571128.codes/2020/10/02/Suffix-Array/)，使用prefix doubling algorithm，把原字串先做一次，然後用非嚴格遞增的l和非嚴格遞減的r夾出一樣的範圍。原本是要先二分搜，然後調整lr的位置，但後來發現因為是非嚴格遞增/減，所以均攤O(字串長)沒問題，而且比較簡潔，又不會出問題。  
加上以前資讀時寫的hash。
