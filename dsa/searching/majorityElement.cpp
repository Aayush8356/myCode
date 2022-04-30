// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
    // int sum = 0;
    // sort(a, a + size);
    // int N = size / 2;
    // int x,y;
    // for(int i = 0 ; N<size ; ++i)
    // {
    //     x = a[i]; y = a[N];
    //     if(x==y)
    //     return x;
    //     ++N;
    // }
    // return 0;
        
    // 
    int count = 1;
        int maj = a[0];
        for(int i = 1 ; i<size ; ++i)
        {
            
             if(a[i]==a[i-1])
            {
                count++ ;
                maj = a[i];
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                count = 1;
                maj = a[i];
            }
        }
        if(count <= 0)
        return -1;
        count = 0;
        for(int i = 0 ; i<size ; ++i)
        {
            if(a[i]==maj)
            count++;
        }
        if(count > (size/2))
        return maj;
        return -1;
    }

};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends