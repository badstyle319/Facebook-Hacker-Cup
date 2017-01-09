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

double C(int m, int n){
	if(n<=0)
		return 1;
	
	double rv = 1;
	for(int i=m;i>(m-n);i--)
		rv*=i;
	for(int i=n;i>1;i--)
		rv/=i;
	return rv;
}

double H(int n, int r){
	double rv = C(n+r-1, r);
	// cout<<"H("<<n<<","<<r<<") = "<<rv<<endl;
	return C(n+r-1, r);
}

double cal(string s, int h){
	size_t pos = s.find('+', 0);
	if(pos!=string::npos)
		h-=atoi(s.substr(pos+1).c_str());
	pos = s.find('-', 0);
	if(pos!=string::npos)
		h+=atoi(s.substr(pos+1).c_str());
	
	stringstream ss(s);
	int X, Y;
	char ch;
	ss>>X>>ch>>Y;
	
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
		h-=X;
		double sum = H(X+1, h-1);
		for(int i=0;i<h;i++){
			int temp = i/Y;
			int idx = 1;
			while(temp>0){
				if(idx%2)
					sum-=C(X, idx)*H(X, i-idx*Y);
				else
					sum+=C(X, idx)*H(X, i-idx*Y);
				temp--;
				idx++;
			}
			// if(i/Y==1)
				// sum-=C(X, 1)*H(X, i-Y);
			// if(i/Y==2)
				// sum+=C(X, 2)*H(X, i-2*Y);
			// if(i/Y==3)
				// sum-=C(X, 3)*H(X, i-3*Y);
		}

		return 1-sum/pow((double)Y, (double)X);
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
