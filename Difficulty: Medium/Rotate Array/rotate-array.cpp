//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force 
    // T.C. = O(d*n)
    // S.C. = O(1)
    void rotateArr1(vector<int>& arr, int d, int n) {
        d = d % n;
        while(d--) {
            int temp = arr[0];
            for(int i = 1; i < n; i++) {
                arr[i-1] = arr[i];
            }
            arr[n-1] = temp;
        }
    }
    
    // Better Approach
    void rotateArr2(vector<int>& arr, int d, int n) {
        d = d % n;
        vector<int> temp;
        
        for(int i = 0; i < d; i++) {
            temp.push_back(arr[i]);
        }
        
        for(int i = d; i < n; i++) {
            arr[i-d] = arr[i];
        }
        
        for(int i = n-d; i < n; i++) {
            arr[i] = temp[i-(n-d)];
        }
    }
    
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        // Brute Force 
        // rotateArr1(arr, d, n);
        
        // Better Approach
        rotateArr2(arr, d, n);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends