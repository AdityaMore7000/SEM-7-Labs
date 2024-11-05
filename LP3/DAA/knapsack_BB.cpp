#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    double weight;
    double ratio; // Value-to-weight ratio

    Item(int v, double w) : value(v), weight(w), ratio((double)v / w) {}
};

struct Node
{
    double bound; // Upper bound of profit
    int level;    // Current level in the decision tree
    int profit;   // Profit accumulated so far
    int weight;   // Total weight accumulated so far

    Node(int lvl = -1, int p = 0, int w = 0) : level(lvl), profit(p), weight(w), bound(0) {}
};

struct CompareNode
{
    bool operator()(Node &a, Node &b)
    {
        return a.profit < b.profit;
    }
};

// Comparator to sort items by value-to-weight ratio
bool cmp(const Item &a, const Item &b)
{
    return a.ratio > b.ratio;
}

// Function to calculate the upper bound on maximum profit for a given node
double calculateBound(Node &u, int W, vector<Item> &items)
{
    if (u.weight >= W)
        return 0; // If over weight, bound is zero

    double profitBound = u.profit; // Start with the current profit
    int totalWeight = u.weight;    // Start with the current weight
    int j = u.level + 1;           // Start from the next item

    // Include whole items until we exceed the capacity
    while (j < items.size() && totalWeight + items[j].weight <= W)
    {
        profitBound += items[j].value;  // Add the value of the item
        totalWeight += items[j].weight; // Update total weight
        j++;
    }

    // If there are still items left, add the fraction of the last item
    if (j < items.size())
    {
        profitBound += (W - totalWeight) * items[j].ratio; // Add the fraction of the next item
    }

    return profitBound; // Return the calculated upper bound
}

// Function to solve the knapsack problem using Branch and Bound
int knapsack(int W, vector<Item> &items)
{
    int maxProfit = 0;                     // Initialize maximum profit to 0
    sort(items.begin(), items.end(), cmp); // Sort items by value-to-weight ratio

    priority_queue<Node, vector<Node>, CompareNode> pq; // Priority queue to store nodes
    Node u(-1, 0, 0);                                   // Starting node
    pq.push(u);                                         // Push the starting node into the priority queue

    // Main loop to process nodes in the priority queue
    while (!pq.empty())
    {
        Node current = pq.top();   // Get the node with the highest bound
        pq.pop();                  // Remove the node from the queue
        int j = current.level + 1; // Next item index

        // If we haven't considered all items yet
        if (j < items.size())
        {
            // Case 1: Take the current item
            Node nextTake(j, current.profit + items[j].value, current.weight + items[j].weight);

            // If the weight is within capacity
            if (nextTake.weight <= W)
            {
                maxProfit = max(nextTake.profit, maxProfit);         // Update maximum profit
                nextTake.bound = calculateBound(nextTake, W, items); // Calculate bound for taking the item
                if (nextTake.bound > maxProfit)
                    pq.push(nextTake); // Push to queue if bound is promising
            }

            // Case 2: Don't take the current item
            Node nextSkip(j, current.profit, current.weight);
            nextSkip.bound = calculateBound(nextSkip, W, items); // Calculate bound for skipping the item

            if (nextSkip.bound > maxProfit)
                pq.push(nextSkip); // Push to queue if bound is promising
        }
    }

    return maxProfit; // Return the maximum profit found
}

int main()
{
    int W = 15;                                                // Maximum weight of knapsack
    vector<Item> items = {{10, 2}, {10, 4}, {12, 6}, {18, 9}}; // Items (value, weight)

    cout << "Maximum profit: " << knapsack(W, items) << '\n'; // Output the maximum profit
    return 0;
}
