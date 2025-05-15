//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Using Extra Space
    // T.C. = O(m+n) + O(m+n) = 2*O(m+n)
    // S.C. = O(m+n) for temp array
    void mergeArrays1(vector<int>& a, vector<int>& b, int m, int n) {
        vector<int> temp;
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(a[i] <= b[j]) {
                temp.push_back(a[i]);
                i++;
            } else {
                temp.push_back(b[j]);
                j++;
            }
        }
        
        while(i < m) {
            temp.push_back(a[i]);
            i++;
        }
        
        while(j < n) {
            temp.push_back(b[j]);
            j++;
        }
        
        for(int i = 0; i < m+n; i++) {
            if(i < m)
                a[i] = temp[i];
            else
                b[i-m] = temp[i];
        }
    }
    
    // Optimal Approach 1
    // T.C. = O(min(m,n)) + O(mlogm) + O(nlogn)
    // S.C. = O(1)
    void mergeArrays2(vector<int>& a, vector<int>& b, int m, int n) {
        int i = m-1, j = 0;
        
        while(i >= 0 && j < n && a[i] > b[j]) {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
    
    void swapIfGreater(vector<int>& a, vector<int>& b, int i, int j) {
        if(a[i] > b[j])
            swap(a[i], b[j]);
    }
    
    // Optimal Approach 2 (Using Gap Method)
    // T.C. = O(log(m+n)) * O(m+n)
    // S.C. = O(1)
    void mergeArrays3(vector<int>& a, vector<int>& b, int m, int n) {
        int len = m+n;
        int gap = len/2 + len%2;
        
        while(gap > 0) {        // O(log(m+n))
                
            // Reset left and right pointers everytime for new gap value
            int left = 0, right = left+gap;
                    
            while(right < len) {    // O(m+n)
            
                // left pointer is in first array and right pointer is in second array
                // Pass 'a' as first array and 'b' as second array
                if(left < m && right >= m) {
                    swapIfGreater(a, b, left, right-m);
                }
                // left and right pointers are in second array
                // Pass 'b' as first array and 'b' as second array
                else if(left >= m) {
                    swapIfGreater(b, b, left-m, right-m);
                } 
                // left and right pointers are in first array
                // Pass 'a' as first array and 'a' as second array
                else {
                    swapIfGreater(a, a, left, right);
                }
                       
                left++;
                right++;
            }
            
            // If gap == 1, break from further iteration
            if(gap == 1) {
                break; 
            }
            
            gap = gap/2 + gap%2;
        }
    }
    
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        
        // Brute Force Using Extra Space
        // mergeArrays1(a, b, m, n);
        
        // Optimal Approach 1
        mergeArrays2(a, b, m, n);
        
        // Optimal Approach 2 (Using Gap Method)
        // mergeArrays3(a, b, m, n);
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends