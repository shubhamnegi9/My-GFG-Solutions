//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(nlogn)
    // S.C. = O(1)
    void sort1(vector<int>& arr, int n) {
        sort(arr.begin(), arr.end());
    }
    
    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(1)
    void sort2(vector<int>& arr, int n) {
        int count0 = 0, count1 = 0, count2 = 0;
        
        for(int& ele: arr) {
            if(ele == 0) {
                count0++;
            } else if(ele == 1) {
                count1++;
            } else {
                count2++;
            }
        }
        
        for(int i = 0; i < count0; i++) {
            arr[i] = 0;
        }
        
        for(int i = count0; i < count0+count1; i++) {
            arr[i] = 1;
        }
        
        for(int i = count0+count1; i < n; i++) {
            arr[i] = 2;
        }
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    void sort3(vector<int>& arr, int n) {
        int left = 0, mid = 0, right = n-1;
        
        while(mid <= right) {
            if(arr[mid] == 0) {
                swap(arr[left], arr[mid]);
                left++;
                mid++;
            } else if(arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[mid], arr[right]);
                right--;
            }
        }
    }
    
    void sort012(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force
        // sort1(arr, n);
        
        // Better Approach
        // sort2(arr, n);
        
        // Optimal Approach
        sort3(arr, n);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends