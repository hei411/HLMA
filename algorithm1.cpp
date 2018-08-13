#include<bits/stdc++.h>
using namespace std;
int N,M;//N number of vertice, M number of edges
int a[1001][1001];//maximum size of graph is 1000 for this program
int visited[1001];
int cnt[1001];
int main (){
	ios::sync_with_stdio(false);
	srand(time(NULL));
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			a[i][j]=0;
		}
		visited[i]=0;
		cnt[i]=0;
	}
	if(N==1){
		cout<<"Prime"<<endl;
		return 0;
	}
	for(int i=0;i<M;i++){
		int q,w;
		cin>>q>>w;
		a[q][w]=1;
		a[w][q]=1;
	}
	int start1,start2;
	start1=rand()%N+1;
	start2=start1;
	while(start2==start1){
		start2=rand()%N+1;
	}
	cout<<start1<<" and "<<start2<<" are chosen"<<endl;
	vector<int> now;
	queue<int> q;
	q.push(start1);
	q.push(start2);
	visited[start1]=1;
	visited[start2]=1;
	while(q.size()!=0){
		int u=q.front();
		q.pop();
		for(int i=1;i<=N;i++){
			if(visited[i]==0&&a[u][i]==1){
				cnt[i]++;
			}
		}
		now.push_back(u);
		if(q.size()==0){
			for(int i=1;i<=N;i++){
				if(visited[i]==0&&cnt[i]>0&&cnt[i]<now.size()){
					visited[i]=1;
					q.push(i);
				}
			}
		}
	}
	if(now.size()==N){
		cout<<"Prime"<<endl;
		return 0;
	}else{
		cout<<"Not prime"<<endl;
		sort(now.begin(),now.end());
		for(int i=0;i<now.size();i++){
			cout<<now[i]<<" ";
		}cout<<endl;
		return 0;
	}
}
