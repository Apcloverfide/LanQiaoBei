//回溯法
//着色图
#include<iostream>
using namespace std;
int r[105][105]; //关系数组
int arr[105][105]; //行代表的是房间编号，每一列存放该房间的所有人下标
int m,n;
int ans = 105;
void Solution(int index,int number){
	if(index >= ans) return ;
	if(number > n ){
		if(index < ans)
			ans = index;
		return ;
	}
	int i;
	for(i = 1;i <= n ;i++){ //遍历房间
		
		if(arr[i][0] == 0)
			break;
		int j = 0;
		while( r[arr[i][j]][number] == 0 && arr[i][j] != 0 ) j++;
		if(arr[i][j] == 0){ //可以加入
			arr[i][j] = number; 
			Solution(index,number+1);
			arr[i][j] = 0;
		}
	}
	arr[i][0] = number;
	Solution(index+1,number+1);
	arr[i][0] = 0;
}

int main(){
	cin >> n >> m;
	int a,b;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		r[a][b] = 1;
		r[b][a] = 1;
	}
	Solution(0,1);
	cout << ans << endl;
}
