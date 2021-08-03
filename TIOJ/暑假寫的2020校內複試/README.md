計畫是跟著[題解](https://hackmd.io/ftPOYtCBTbeh7YtB1ZhlSA)寫一次，盡可能AC多一點題目  
[pA](https://tioj.ck.tp.edu.tw/problems/2155)我用題解subtask4說的枚舉每個字串的所有子字串的hash，因為我不知道要怎麼存我就用map<ll,int>代表一個字串的某個hash出現了幾次。然後我現在寫README才發現我hash寫爛了，處理一次前綴就好，剩下的用數學算出來。  
[pB](https://tioj.ck.tp.edu.tw/problems/2151)暫時還沒空看題解的dp優化是什麼意思，但有把dp寫完，對環的判斷和處理也沒問題。要記得這裡dp要用max更新，不是直接覆蓋掉，因為可能會有很多個點連到同一個點。還沒寫滾動，不過影響不大。
