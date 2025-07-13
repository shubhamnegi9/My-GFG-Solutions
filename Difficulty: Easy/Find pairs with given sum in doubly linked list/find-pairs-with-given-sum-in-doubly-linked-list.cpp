// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(no. of pairs) only for returning answer
    vector<pair<int, int>> findPairsWithGivenSum1(Node *head, int target) {
        Node* temp1 = head;
        vector<pair<int, int>> result;
        
        while(temp1 != NULL) {
            Node* temp2 = temp1->next;
            while(temp2 != NULL && temp1->data + temp2->data <= target) {
                if(temp1->data + temp2->data == target) {
                    result.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        
        return result;
    }
    
    Node* findTail(Node* head) {
        Node* tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        
        return tail;
    }
    
    // Optimal Approach
    // T.C. = O(n) for finding tail + O(n) for finding pairs
    //      = O(2n)
    // S.C. = O(no. of pairs) only for returning answer
    vector<pair<int, int>> findPairsWithGivenSum2(Node *head, int target) {
        Node* temp1 = head;
        Node* temp2 = findTail(head);
        vector<pair<int, int>>  result;
        
        while(temp1->data < temp2->data) {      // Loop until temp1 and temp2 have not crossed each other
            if(temp1->data + temp2->data == target) {
                result.push_back({temp1->data, temp2->data});
                temp1 = temp1->next;
                temp2 = temp2->prev;
            }
            else if(temp1->data + temp2->data < target) {
                temp1 = temp1->next;
            }
            else {
                temp2 = temp2->prev;
            }
        }
        
        return result;
    }
    
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // Brute Force Approach
        // return findPairsWithGivenSum1(head, target);
        
        // Optimal Approach
        return findPairsWithGivenSum2(head, target);
        
    }
};