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
		vector<int> nums;
		int icnt, num;
		cin>>icnt;
		while(icnt-->0){
			cin>>num;
			nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		
		
		int ans = 0;
		if(nums.size()==1){
			ans = 1;
		}else{
			for(int L=0,R=nums.size()-1;L<=R;){
				int needs = 0;
				while(nums[R]*(needs+1)<50)
					needs++;
				if(L+needs<=R)
					ans++;
				L+=needs;
				R--;
			}
		}
		
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
