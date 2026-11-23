class ProductOfNumbers {
public:
vector<int> nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n=nums.size();
        int ans=1;
        int count=0;
        int i=n-1;
        while(count!=k) {
            ans*=nums[i];
            i--;
            count++;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */