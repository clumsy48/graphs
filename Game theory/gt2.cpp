/*****************************************************************************
 * 
 * https://practice.geeksforgeeks.org/problems/cycle-race/0
 * Solution
 * 
 *************************************************************************************/


#include <iostream>
using namespace std;

static long long int a[10000001];

int main() {
	long long int t,n;
	cin >> t;
	
	
	a[0]=0,a[1]=1,a[2]=1,a[3]=0,a[4]=1;
	for(long long int i=5;i<10000001;i++){
	    if(a[i-1]==0 || a[i-2]==0 || a[i-4]==0){
	        a[i] = 1;
	    }else a[i] = 0;
        //cout << i << " " << a[i] << endl;
	}
	
	while(t--){
	    cin >> n;
	    if(a[n]==1){
	        cout << "JELLY\n";
	    }else cout << "JACK\n";
	}
    return 1;
}

	
	
