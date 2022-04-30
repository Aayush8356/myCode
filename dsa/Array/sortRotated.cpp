// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    // 3 2 1 4 ~ 4 3 2 1
    // 4 1 2 3 ~ 1 2 3 4
    // 3 4 1 2 ~ 1 2 3 4
    void swap(int& a , int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void reverse(int arr[],int num , int L, int R)
    {
        while(L<R)
        {
            swap(arr[L],arr[R]);
            ++L;
            --R;
        }
    }
    bool checkRotatedAndSorted(int arr[], int num){
        // Your code here
        int d = 0;
        int s1=1;
        int s2 = 1;
        for(int i = 0 ; i < num ; ++i)
        {
            if( (arr[i]>arr[i+1] and arr[i+1]>arr[i+2]) or (arr[i]<arr[i+1] and arr[i+1]>arr[i+2])  )
            {
                d = i;
                break;
            }
        }
        reverse(arr,num,0,d);
        reverse(arr,num,d+1,num-1);
        for(int i = num-1 ; i >= 0 ; --i)
        {
            if(arr[i]<arr[i-1])
            {
                ++s1;
            }
            else
            ++s2;
        }
        if(s1==num or s2==num)
        return true;
        return false;

    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        Solution ob;
        
        //function call
        flag = ob.checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends