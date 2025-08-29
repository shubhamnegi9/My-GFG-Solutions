class LRUCache {
  public:
    class Node {
        public:
        int key, val;
        Node* prev;
        Node* next;
        
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;
    
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
        mpp.clear();
    }
    
    void deleteNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        
        if(prevNode != NULL)
            prevNode->next = nextNode;
        
        if(nextNode != NULL)
            nextNode->prev = prevNode;
    }
    
    void insertAfterHead(Node* newNode) {
        Node* nodeAfterHead = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nodeAfterHead;
        nodeAfterHead->prev = newNode;
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end()) 
            return -1;
        
        Node* temp = mpp[key];
        deleteNode(temp);
        insertAfterHead(temp);
        
        return temp->val;
    }

        
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            
            temp->val = value;
            mpp[key] = temp;
            deleteNode(temp);
            insertAfterHead(temp);
        }
        else {
            if(mpp.size() == capacity) {
                Node* temp = tail->prev;
                deleteNode(temp);
                mpp.erase(temp->key);
            }
            
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;
        }
    }
};