/*
    Time Complexity: O(N1+N2)
    Space Complexity: O(N2)
    where N1 is the number of nodes in the first BST and
    N2 is the number of nodes in the second BST.
*/

#include <unordered_set>
void trav(Node *node, unordered_set<int> &st)
{
    if (!node)
        return;

    // Insert data in set
    st.insert(node->data);

    // Traverse left subtree
    trav(node->left, st);
    // Traverse right subtree
    trav(node->right, st);
}

void count(Node *node, int &ans, unordered_set<int> &st, int x)
{
    if (!node)
        return;

    // If complement found in subtree
    if (st.find(x - (node->data)) != st.end())
        ans++;

    // Count in left subtree
    count(node->left, ans, st, x);
    // Count in right subtree
    count(node->right, ans, st, x);
}

int countCouples(Node *root1, Node *root2, int x)
{
    unordered_set<int> st;
    int ans = 0;

    // Traverse second BST and insert all values in set
    trav(root2, st);

    // Count nodes in first BST which have complement
    count(root1, ans, st, x);

    return ans;
}