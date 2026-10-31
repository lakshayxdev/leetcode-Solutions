class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children) return -1;
        money=money-children;
        int count=0;
        while(money>=7 && count<children) {
            money=money-7;
            count++;
        }
        if(count==children && money>0) count--;
        else if(money==3 && children-count==1) {
            count--;
        }
        return max(0,count);
    }
};