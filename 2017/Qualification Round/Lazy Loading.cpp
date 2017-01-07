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
		vector<int> nums;
		int icnt, num;
		cin>>icnt;
		while(icnt-->0){
			cin>>num;
			nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		
		// for(int I=0;I<nums.size();I++){
			// cout<<setw(3)<<nums[I]<<" ";
			// if((I+1)%10==0)
				// cout<<endl;
		// }
		// cout<<endl;
		
		int ans = 0;
		if(nums.size()==1){
			ans = 1;
		}else{
			int i, j, k;
			for(i=0,j=nums.size()-1;i<j;){
				k=1;
				while(nums[j]*k<50)
					k++;
				ans+=1;
				j--;
				i+=(k-1);
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
