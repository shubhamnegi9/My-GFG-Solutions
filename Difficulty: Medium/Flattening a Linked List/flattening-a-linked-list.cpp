/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    
    Node* convertArrToLinkedList(vector<int>& arr) {
        // Edge Case
        if(arr.size() == 0)
            return NULL;
            
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            temp->bottom = newNode;
            temp = newNode;     // OR temp = temp->bottom;
        }
        
        return head;
    }
  
    // Brute Force Approach
    // T.C. = 2*O(n*m) + O((n*m)log(n*m)) 
    // S.C. = 2*O(n*m)
    Node *flatten1(Node *root) {
        
        // Edge Case
        if(root == NULL)
            return NULL;
        
        Node* temp = root;
        vector<int> arr;
        
        while(temp != NULL) {
            Node* t = temp;
            while(t != NULL) {
                arr.push_back(t->data);
                t = t->bottom;
            }
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        return convertArrToLinkedList(arr);
    }
    
    
    Node* merge2SortedLL(Node* list1, Node* list2) {
        Node* t1 = list1;
        Node* t2 = list2;
        
        Node* dNode = new Node(-1);
        Node* temp = dNode;
        
        while(t1 != NULL && t2 != NULL) {
            if(t1->data < t2->data) {
                temp->bottom = t1;
                temp = t1;
                t1 = t1->bottom;
            } else {
                temp->bottom = t2;
                temp = t2;
                t2 = t2->bottom;
            }
            
            temp->next = nullptr;   // Make next pointer of each node in merged linked list as NULL
        }
        
        if(t1!=NULL)
            temp->bottom = t1;
        
        if(t2!=NULL)
            temp->bottom = t2;
        
        if(dNode->bottom != NULL)
            dNode->bottom->next = nullptr;
            
        return dNode->bottom;
    }
    
    // Optimal Approach
    // T.C. = O(n*2*m) = O(2*n*m)
    // S.C. = O(n) for recursive stack space
    Node *flatten2(Node *root) {
        Node* head = root;
        // Base case
        if(head == NULL || head->next == NULL)
            return head;
        
        // Recursive call for next node 
        Node* mergedHead = flatten2(head->next);
        
        // On backtracking, merge the 2 sorted linked lists
        return merge2SortedLL(head, mergedHead);
    }
    
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Brute Force Approach
        // return flatten1(root);
        
        // Optimal Approach
        return flatten2(root);
    }
};