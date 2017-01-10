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

int solution[21] = {0};
void backtrack(int n, int X, int Y, int h, int &sum){
	if(n==X){
		return;
	}
	
	for(int i=1;i<=Y;i++){
		solution[n] = i;
		if(n>0)
			solution[n]+=solution[n-1];
		if(solution[n]>=h){
			// for(int j=0;j<=n;j++)
				// cout<<solution[j]<<" ";
			int restNum = pow((double)Y, (double)(X-n-1));
			// cout<<" -> "<<restNum<<endl;
			sum+=restNum;
		}else
			backtrack(n+1, X, Y, h, sum);
	}
}

double cal(string s, int h){	
	stringstream ss(s);
	int X, Y, Z = 0;
	char ch;
	
	ss>>X>>ch>>Y;
	if(s.find('+', 0)!=string::npos || s.find('-', 0)!=string::npos)
		ss>>Z;
	h-=Z;

	if(X*Y<h)
		return 0;
	else if(X>=h)
		return 1;
	
	if(X==1){
		int count = 0;
		for(int i=1;i<=Y;i++)
			if(i>=h)
				count++;
		return (double)count/Y;
	}else{
		// cout<<X<<" "<<Y<<" "<<h<<endl;
		int sum = 0;
		backtrack(0, X, Y, h, sum);
		return sum/pow((double)Y, (double)X);
		// backtrack(0, X, Y, h);
	}
	
	return 0;
}

int main()
{
	#ifndef online_judge
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	cout.setf(ios::fixed, ios::floatfield);

	int casenum, i=1;
	cin>>casenum;
	while(casenum-->0){
		///////////////
		int H, S;
		cin>>H>>S;
		vector<string> vec;
		while(S-->0){
			string tmp;
			cin>>tmp;
			vec.push_back(tmp);
		}
		
		double ans = 0;
		
		for(vector<string>::iterator it=vec.begin();it!=vec.end();it++)
			ans = max(ans, cal(*it, H));
		
		cout.setf(ios::fixed, ios::floatfield);
		cout<<"Case #"<<i<<": "<<ans<<endl;
		i++;
		///////////////
	}
	
	#ifndef online_judge
	fclose(stdin);
	fclose(stdout);
	#endif 

	return 0;
}
