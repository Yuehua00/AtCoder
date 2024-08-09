/*
題意是要求創建一個二維陣列，內部填入0/1，滿足輸入字串P及Q的排序。
我將順序(行和列)的質相加觀察，發現質大於n的為1及會滿足。
3*3
3	2	4
4	3	5
5	4	6
這題還有看到很多其他解法，但幾乎都是觀察結果為主。
*/  
#include <iostream>
#include <string.h>
#define MAXN 500+5

using namespace std;

int n = 0, a = 0;
int arr[MAXN][MAXN];
int p[MAXN], q[MAXN];

int main()
{
    while(scanf("%d", &n) != EOF){
        memset(arr, 0, sizeof(arr));
        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));

        for(int i = 1; i <= n; i++){
            scanf("%d", &a);
            p[a] = i;
            //cout << "P[" << a << "] = " << i << endl;
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &a);
            q[a] = i;
            //cout << "Q[" << a << "] = " << i << endl;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                //if(p[i] + q[j] > n) arr[i][j] = 1;
                printf("%d ", p[i] + q[j]);
            }
            printf("\n");
        }
    }
    return 0;
}

