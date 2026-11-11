class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return 1LL*min(costBoth,cost1+cost2)*min(need1,need2)+1LL*max(0,need1-need2)*min(costBoth,cost1)+1LL*max(0,need2-need1)*min(costBoth,cost2);
    }
};