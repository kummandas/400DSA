/*int minimumCoins(int v) {
    vector<int> coins = {1, 2 , 5, 10, 20, 50, 100 , 500 , 1000};
    
    int count =0;
    
    for(int i = coins.size()-1; i>=0; i--)
{
      while (v >= coins[i]) {
        count++;
        v -= coins[i];
      }
    }
    return count;
}*/

/*
    Time complexity: O(V)
    Space complexity: O(1)

    Where 'V' is the given input integer.
*/

int minimumCoins(int v) {
    // Initializing the vector 'coins'.
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    // Sorting 'coins'.
    sort(coins.begin(), coins.end());
    int count = 0;
    // Iterating over the 'coins'.
    for (int i = coins.size() - 1; i >= 0; i--) {
        // While loop till current 'v' is greater than 'coins[i]'.
        while (v >= coins[i]) {
            count++;
            v -= coins[i];
        }
    }
    return count;
}