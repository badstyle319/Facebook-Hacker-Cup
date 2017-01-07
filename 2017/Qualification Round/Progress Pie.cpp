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

typedef struct {
	int a:4;
	int b:2;
	int c:2;
	int d:6;
} myStruct;

int main()
{
	#ifndef online_judge
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int casenum, i=1;
	cin>>casenum;
	while(casenum-->0){
		///////////////
		string color = "white";
		int p, x, y;
		cin>>p>>x>>y;
		
		int dx = x-50;
		int dy = y-50;
		double r = sqrt(dx*dx+dy*dy);
		double theta = atan2(dy, dx)*180/PI;
		theta = dy>0?(dx>0?90-theta:450-theta):-theta+90;
		theta = theta/360*100;
		if(r<=50 && p && p>=theta)
			color = "black";
		
		cout<<"Case #"<<i<<": "<<color<<endl;
		i++;
		///////////////
	}
	
	#ifndef online_judge
	fclose(stdin);
	fclose(stdout);
	#endif 

	return 0;
}
