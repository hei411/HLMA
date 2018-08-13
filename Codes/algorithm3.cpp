#include<bits/stdc++.h>
using namespace std;
int N,M;//N number of vertice, M number of edges
int a[1001][1001];//maximum size of graph is 1000 for this program
int visited[1001];
int cnt[1001];
int check=0;
vector<int> module;
void func(vector<vector<int> >l1,vector<vector<int> >l2){
	if(check==1){
		return;
	}if(l1.size()==0){
		l1.push_back(l2[0]);
		l2.erase(l2.begin()+0);
		func(l1,l2);
		return;
	}
	if(l2.size()==0&&l1[0].size()>1){
		check=1;
		module=l1[0];
		return ;
	}if(l2.size()==0&&l1[0].size()==1){
		return ;
	}
	for(int i=0;i<l1[0].size();i++){
		for(int j=0;j<l2.size();j++){
			vector<int> one,two;
			for(int k=0;k<l2[j].size();k++){
				if(a[l1[0][i]][l2[j][k]]==0){
					one.push_back(l2[j][k]);
				}else{
					two.push_back(l2[j][k]);
				}
			}if(one.size()!=0&&two.size()!=0){
				l2[j]=one;
				l2.push_back(two);
			}	
		}
	}
	for(int c=0;c<l2.size();c++){
		for(int i=0;i<l2[c].size();i++){
			for(int j=0;j<l1.size();j++){
				vector<int> one,two;
				for(int k=0;k<l1[j].size();k++){
					if(a[l2[c][i]][l1[j][k]]==0){
						one.push_back(l1[j][k]);
					}else{
						two.push_back(l1[j][k]);
					}
				}if(one.size()!=0&&two.size()!=0){
					l1[j]=one;
					l1.push_back(two);
				}	
			}
		}
	}
	vector<vector<int> >temp1,temp2;
	temp1.push_back(l1[0]);
	temp2=l1;
	temp2.erase(temp2.begin()+0);
	func(temp1,temp2);
	temp1.erase(temp1.begin()+0);
	temp1.push_back(l2[0]);
	temp2=l2;
	temp2.erase(temp2.begin()+0);
	func(temp1,temp2);
	return;
}
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
	if(now.size()<N){
		cout<<"Not prime"<<endl;
		sort(now.begin(),now.end());
		for(int i=0;i<now.size();i++){
			cout<<now[i]<<" ";
		}cout<<endl;
		return 0;
	}
	int start=rand()%N+1;
	cout<<start<<" is chosen"<<endl;
	vector<vector<int> > list1, list2;
	vector<int> group1, group2;
	for(int i=1;i<=N;i++){
		if(i!=start){
			if(a[i][start]==0){
				group1.push_back(i);
			}else{
				group2.push_back(i);
			}
		}
	}
	list1.push_back(group1);
	list2.push_back(group2);
	func(list1,list2);
	if(check==0){
		cout<<"Prime"<<endl;
		return 0;
	}
	cout<<"Not prime"<<endl;;
	for(int i=0;i<module.size();i++){
		cout<<module[i]<<" ";
	}
}
