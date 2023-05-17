#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<char *> vs = {
  "aa",
  "ccc",
  "eeeee",
  "gggggg",
  "zzzz",
};

// Q1
// 完成用 binary serach 搜尋vector vs, 回傳字串str在vs中的位置, 若未發現則回傳 -1
// 不限使用 C或C++的function 
// 但請注意c++ string 與 c char*轉換的消耗, 盡可能以最有效率的方式完成工作, 

int bin_search(const string &str) {
    int n = vs.size(), ret=-1;

    /* 若vs還沒排列好可以用sort的技術 根據資料大小跟分布選擇 用哪種sorting, TC:O(NlogN)，
    給的vector<char*> vs 看起來是已排序過的，所以只需對insert進來的放到對的位置，用char* comparison 比較ASCLL大小,
    insert(val): vs.push_back(val) 往前比較然後swap到對的位置，因為儲存的資料結構為array，
    若用binary search的方式去找到位置後，swap完，也是需要將指標一格一格指到正確的地方，所以insert還是TC:O(N) */
    
    int l=0, r=n-1;
    // binary search from sorted array : TC: O(logN)
    while(l<=r){
        int mid=l+(r-l)/2;
        string tar = vs[mid];
        if(tar==str){
            ret = mid;
            break;
        }
        else if(tar>str){
            r=mid-1;
        }
        else if(tar<str){
            l=mid+1;
        }
    }
    return ret;
}

int main(){
    string key;
    while(true){
        cout<<"please enter the key:"<<endl;
        cin >> key;
        int pos = bin_search(key);
        if(pos==-1){
            cout<<"cannot find!!"<<endl;
        }
        else{
            cout<< "the idx is:"<<pos<<endl;
        }
    }
    return 0;
}
// Q2
// 若要insert "111"到vs內, 應該放在哪最為合適.
/*  push_back()後再swap到正確位置 若是直接找位置，也是需要將array中比"111"大的copy到後面一格 insert:O(N) : (這是我一開始用string的方式去思考的答案)
    後來發現他是char* 所以不是copy，是拿對的char address assign給他 但還是O(N).
    "111" 會放在 vs[0].
    我對char*的操作比較少，比較常對string做操作，所以有google一下char* to string有什麼要注意的
*/
