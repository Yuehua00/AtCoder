/*
題目 : https://atcoder.jp/contests/arc181/tasks/arc181_a
問幾次  k 後能讓數列完整排序。

(by fish)
排序次數分四類 :
1. 已經排好，輸出0
2. 有一數字已經排在位置上，且的左邊通通比他小，例如(21354)，3符合此條件，或是1在第一個或n在第n個，輸出1
3. 1在第n個且n在第一個，輸出3
4. 其他，輸出2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 200000+10

using namespace std;

int ans = 0;
int kase = 0;
int n = 0, a = 0;
vector<int> v, v2;

int main() {

    scanf("%d", &kase);
    while(kase--){
        v.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            v.emplace_back(a);
        }
        v2 = v;
        sort(v2.begin(), v2.end());
        if(v == v2){                           // 已經排好，輸出0
            printf("0\n");
            continue;
        }else if(v[0] == 1 || v[n-1] == n){    // 1在第一個或n在第n個
            printf("1\n");
            continue;
        }else if(v[0] == n && v[n-1] == 1){    // 1在第n個且n在第一個
            printf("3\n");
            continue;
        }

        int max_tmp = v[0];
        bool ans = false;
        for(int i = 1; i <= n; i++){
            if(v[i-1] == i && v[i-1] > max_tmp){     // 有一數字已經排在位置上，且的左邊通通比他小
                printf("1\n");
                ans = true;
                break;
            }
            max_tmp = max(v[i-1], max_tmp);
        }
        if(ans) continue;
        else printf("2\n");
    }

    return 0;
}
