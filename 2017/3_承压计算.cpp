
#include<cstdio>
#include<iostream>
using namespace std;
int arr[100][100];
double height[100][100];
int main(){
    for(int i = 1;i <= 29;i++){
        for(int j = 1; j <= i;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i <= 30;i++){
        for(int j = 1;j <= i;j++){
            if(j == 1){
                height[i][j] = arr[i][j] + height[i-1][j]/2.0;
            }else if(i == j){
                height[i][j] = arr[i][j] + height[i-1][j-1]/2.0;
            }else{
                height[i][j] = arr[i][j] + height[i-1][j-1]/2.0 + height[i-1][j]/2.0;
            }
        }
    }
    double min = 208645823100;
    cout << min << endl;
    double max = 0;
    for(int i = 1;i <= 30;i++){
        if(min > height[30][i]){
            min = height[30][i];
        }
        if(max < height[30][i]){
            max = height[30][i];
        }
    }
    for(int i = 1;i <= 30;i++){
        cout << height[30][i] << " ";
    }
    cout << endl;
    double t = 2086458231 / min;
    long long res = t * max;
    cout << res << endl;
    return 0;
}
