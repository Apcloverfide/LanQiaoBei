// 收获一：注意for循环中的条件如果不满足的话循环就根本不会执行
// 收获二：高效的筛选法求素数表
#include<iostream>
using namespace std;
const long long n = 1000010;
bool p[n];
//
void selectp(){
    for(long long i = 2; i*i < n;i++){
        if(p[i] == false){
            long long j = i*i;
            while(j < n){
                p[j] = true;
                j += i;
            }
        }
    }
}

/*int dp[n] = {1,1,0};
int prim[n],tot = 0;
void init()
{
    for(long long i = 2 ; i < n ; i ++)
    {
        if(dp[i])continue;
        prim[tot++]=i;
        for(long long  j = i ; j * i < n ; j ++){
            dp[i*j] = 1;
        }
    }
}
*/
int main(){
    //init();
    selectp();
    //int f;
    int sum = 0;
    for(int i = 2;i < n;i++){
        if(dp[i] == 1 && dp[i] == false){
            sum ++;
        }
    }
    cout << sum <<endl;
    for(int i = 2;i < 20;i++){
        if(p[i] == false)
            cout << i <<" ";
    }
    cout << endl;
    long long i ; //起点
    int f;
    for(int d = 2; d*10 < n;d++){
        for(i = 2 ; i + 9*d < n; i++){ //起点
            f = 0;
            for(int k = 0;k <= 9;k++)
            {
                if(p[d*k + i] == true){
                    f = 1;break;
                }
            }
            if(f == 0){
                cout << d <<endl;
                return 0;
            }
        }
    }
    cout << "##############"<<endl;
    return 0;
}
