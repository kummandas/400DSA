/*/*
    Time Complexity: O(Q) 
    Space Complexity: O(capacity)
    
    where Q is the number of the given queries and 
    capacity is the maximum number of keys LRU Cache can store.


#include <map>

class Node
{
public:
    Node *left, *right;
    int key, val;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->left = this->right = NULL;
    }
};

class LRUCache
{
public:
    map<int, Node *> nodemap;
    Node *head, *tail;
    int capacity, size;

    // Initialize LRUCache
    LRUCache(int capacity)
    {
        head = tail = NULL;
        this->capacity = capacity;
        this->size = 0;
    }
    
    // Add node at rear of linked list,
    void addToRear(Node *nd)
    {
        if (head == NULL)
        {
            head = tail = nd;
            return;
        }

        tail->right = nd;
        nd->left = tail;

        tail = nd;

        return;
    }
    
    void deleteNode(Node *nd)
    {
        if (nd->left != NULL)
        {
            nd->left->right = nd->right;
        }
        else
        {
            head = nd->right;
        }

        if (nd->right != NULL)
        {
            nd->right->left = nd->left;
        }
        else
        {
            tail = nd->left;
        }

        nd->left = nd->right = NULL;
    }

    // Return the value of the given key
    int get(int key)
    {
        if (nodemap.find(key) == nodemap.end())
        {
            return -1;
        }

        deleteNode(nodemap[key]);
        addToRear(nodemap[key]);

        return nodemap[key]->val;
    }

    // Inserts a key and it's value into the LRUCache
    void put(int key, int value)
    {
        if (nodemap.find(key) != nodemap.end())
        {
            nodemap[key]->val = value;

            deleteNode(nodemap[key]);
            addToRear(nodemap[key]);
        }
        else
        {
            Node *nd = new Node(key, value);
            nodemap[key] = nd;

            if (size == capacity)
            {
                nodemap.erase(head->key);
                deleteNode(head);
                addToRear(nd);
            }
            else
            {
                size++;
                addToRear(nd);
            }
        }
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    
    public:
    class node 
    {
        public: 
        int key;
        int value;
        node * prev;
        node * next;
        
        node(int _key,int _value)
        {
            key = _key;
            value = _value;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node *> m;
    
    // Constructor for initializing the
    // cache capacity with the given value.
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node * temp)
    {
        node * dummy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dummy;
        dummy->prev = temp;
    }
    
    void deletenode(node * temp)
    {
        node * delnext = temp->next;
        node * delprev = temp->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    // This method works in O(1)
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node * res =  m[key];
            m.erase(key);
            int ans = res->value;
            deletenode(res);
            addnode(res);
            m[key] = head->next;
           cout << "Got the value : " << ans 
                << " for the key: " << key << "\n";
            return ans;
        }
        cout << "Did not get any value for the key: " 
             << key << "\n";
        return -1;
    }
    
    // This method works in O(1)
    void set(int key, int value)
    {
        
        cout << "Going to set the (key, value) : (" 
             << key << ", " << value << ")" << "\n";
        if (m.find(key) != m.end())
        {
            node * exist = m[key];
            m.erase(key);
            deletenode(exist);
        }
        
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

// Driver code
int main()
{
    cout << "Going to test the LRU  " 
         << "Cache Implementation\n";
         
    LRUCache * cache = new LRUCache(2);

    // It will store a key (1) with value
    // 10 in the cache.
    cache->set(1, 10);

    // It will store a key (1) with value 10 in the
    // cache.
    cache->set(2, 20);
    cout << "Value for the key: 1 is "
         << cache->get(1) << "\n"; // returns 10

    // Evicts key 2 and store a key (3) with
    // value 30 in the cache.
    cache->set(3, 30);

    cout << "Value for the key: 2 is " 
         << cache->get(2) << "\n"; // returns -1 (not found)

    // Evicts key 1 and store a key (4) with
    // value 40 in the cache.
    cache->set(4, 40);
    cout << "Value for the key: 1 is "
         << cache->get(1) << "\n"; // returns -1 (not found)
    cout << "Value for the key: 3 is "
         << cache->get(3) << "\n"; // returns 30
    cout << "Value for the key: 4 is "
         << cache->get(4) << "\n"; // return 40

    return 0;
}

// This code is contributed by CoderSaty