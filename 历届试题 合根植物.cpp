/*
如果我们告诉你哪些小格子间出现了连根现象，你能说出这个园中一共有多少株合根植物吗？
输入格式
　　第一行，两个整数m，n，用空格分开，表示格子的行数、列数（1<m,n<1000）。
　　接下来一行，一个整数k，表示下面还有k行数据(0<k<100000)
　　接下来k行，第行两个整数a，b，表示编号为a的小格子和编号为b的小格子合根了。


　　格子的编号一行一行，从上到下，从左到右编号
*/


#include<algorithm>
#include<iostream>
using namespace std;
int v[1000000][4]; //上下左右 一共四维 如果没有相连就为0
int m,n,k; //m行n列
bool vis[1000000]; //标志节点是否被访问过
void dfs(int x){ //递归
	if(x <= 0 || x > m*n || vis[x] == true)
		return;
	vis[x] = true;
	for(int i = 0;i < 4;i++){
		if(v[x][i]){
			dfs(v[x][i]);
		}
	}
}
int main(){
	
	cin >> m >> n;
	cin >> k;
	int a,b;
	//输入定义的存储数据结构数组
	for(int i = 0;i < k;i++){
		cin >> a >> b;
		//上下
		if(a > b) swap(a,b);
		if(b - n == a){
			v[b][0] = a;
			v[a][1] = b;
		}
		else{ //左右
			v[a][3] = b;
			v[b][2] = a;
		}
	}
	//遍历
	int sum = 0;
	for(int i = 1;i <= m*n;i++){
		if(vis[i] == false){
			dfs(i);
			sum ++;
		}
	}
	cout << sum << endl;
	return 0;
}
