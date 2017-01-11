#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

typedef struct{
	int X;
	int Y;
}point;

int main()
{
	#ifndef online_judge
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	cout.setf(ios::fixed, ios::floatfield);

	int casenum, no=1;
	cin>>casenum;
	while(casenum-->0){
		///////////////
		int ans=0, N, X, Y, d;
		vector<point> vec;
		vector< vector<int> > distance(2001, vector<int>(2001));
		// int distance[2001][2001];
		
		cin>>N;
		while(N-->0){
			point p;
			cin>>p.X>>p.Y;
			vec.push_back(p);
		}
		
		for(int i=0;i<vec.size();i++){
			for(int j=0;j<vec.size();j++){
				if(i!=j && i>j){
					int difx = vec[i].X-vec[j].X;
					int dify = vec[i].Y-vec[j].Y;
					d = difx*difx+dify*dify;
					distance[i][j] = d;
					distance[j][i] = d;
				}
			}
		}
		
		
		for(int i=0;i<vec.size();i++){
			map<int,int> mp;
			for(int j=0;j<vec.size();j++){
				mp[distance[i][j]]+=1;
			}
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
				int val = it->second;
				if(val>1)
					ans+=val*(val-1)/2;
			}
		}
		
		
		cout<<"Case #"<<no<<": "<<ans<<endl;
		no++;
		///////////////
	}
	
	#ifndef online_judge
	fclose(stdin);
	fclose(stdout);
	#endif 

	return 0;
}
